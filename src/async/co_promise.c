#include "co_promise.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


coroutine_manager_t __AUX_COR_MANAGERS__[2 * MAX_THREAD_COUNT] = {};
coroutine_t* __AUX_COR_COROUTINES_PTR__[2 * MAX_THREAD_COUNT] = {};

coroutine_manager_t* __aux_coroutine_manager_location__() {
  return __aux_thread_safe_static_val_get__(__AUX_COR_MANAGERS__, sizeof(coroutine_manager_t));
}

coroutine_t** __aux_coroutines_location__() {
  return __aux_thread_safe_static_val_get__(__AUX_COR_COROUTINES_PTR__, sizeof(void*));
}

coroutine_t* coroutine_manager_get_cor(coroutine_manager_t* manager, size_t index) {
  size_t bucket_id = (index / INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY) ? 1 : 0;
  size_t offset_index = (1 + bucket_id) * INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY;
  if (bucket_id) {
    printf("GC0 - BID: %d - OID: %d - IID: %d\n", bucket_id, offset_index, index);
    while (offset_index <= (index + 1)) {
      bucket_id++;
      offset_index *= 2;
    }
    long cor_index = index - offset_index + INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY;
    if (cor_index < 0) {
      offset_index /= 2;
      bucket_id--;
      cor_index += offset_index;
    }
    // printf("GC1 - BID: %d - OID: %d - IID: %d\n", bucket_id, offset_index, index);
    // bucket_id--;
    // offset_index /= 2;
  }
  printf("GC2 - BID: %d - OID: %d - IID: %d - LID: %d\n", bucket_id, offset_index, index, index - offset_index + INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY);
  return &manager->queue[bucket_id][index - offset_index + INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY];
}

size_t coroutine_manager_queue_capacity(coroutine_manager_t* manager) {
  size_t i = INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY - 1;
  while (manager->queue[i++]);
  return --i;
}

size_t coroutine_manager_queue_size(coroutine_manager_t* manager) {
  size_t i = 0;
  while (manager->queue[i++] != INVALID) {printf("I: %d; Q: %d\n", i - 1, manager->queue[i - 1]);};
  printf("I: %d; Q: %d\n", i - 1, manager->queue[i - 1]);
  return --i;
}

coroutine_manager_t* coroutine_manager_t_reserve(coroutine_manager_t* manager) {
  size_t queue_size = coroutine_manager_queue_size(manager);
  size_t queue_capacity = coroutine_manager_queue_capacity(manager);
  printf("Reserve - %d - %d - %d - %d\n", manager->queue_size, manager->queue_capacity, queue_size, queue_capacity);
  if ((queue_size + 1) == queue_capacity) {
    coroutine_t** old_queue = manager->queue;
    manager->queue = (coroutine_t**)malloc((queue_capacity *= 2) * sizeof(coroutine_t*));
    memcpy(manager->queue, old_queue, sizeof(void*) * queue_size);
    for (size_t i = queue_size; i < queue_capacity - 1; ++i) {
      manager->queue[i] = INVALID;
    }
    manager->queue[queue_capacity - 1] = NULL;
  }
  size_t* old_vacant_queue = manager->queue_vacant_indexes;
  size_t new_capacity = manager->queue_capacity;
  size_t new_bucket_capacity = manager->queue_capacity + INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY;
  manager->queue[queue_size] = (coroutine_t*)calloc(new_bucket_capacity, sizeof(coroutine_t));
  manager->queue_vacant_indexes = (size_t*)calloc(new_capacity, sizeof(size_t));
  memcpy(manager->queue_vacant_indexes, old_vacant_queue, sizeof(size_t) * manager->queue_size);
  free(old_vacant_queue);
  manager->queue_capacity = new_capacity + new_bucket_capacity;
  return manager;
}

coroutine_manager_t* coroutine_manager_t_init(coroutine_manager_t* manager) {
  manager->queue = malloc(sizeof(void*) * INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY);
  for (size_t i = 0; i < INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY; ++i) {
    manager->queue[i] = INVALID;
  }
  manager->queue[INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY - 1] = NULL;
  manager->queue[0] = calloc(INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY,
                             sizeof(coroutine_t));
  manager->queue_capacity = INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY;
  manager->queue_size = 0;
  manager->queue_vacant_indexes = (size_t*)calloc(INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY,
                                                  sizeof(size_t));
  memcpy(&manager->env, &(jmp_buf){}, sizeof(jmp_buf));
  return manager;
}

void coroutine_manager_t_destroy(coroutine_manager_t* manager) {
  if (manager->queue) {
    coroutine_t* coroutine_i = NULL;
    for (size_t i = 0; i < manager->queue_size; ++i) {
      coroutine_i = coroutine_manager_get_cor(manager, i);
      if (coroutine_i->args) {
        free(coroutine_i->args);
        coroutine_i->args = NULL;
      }
      if (coroutine_i->state) {
        free(coroutine_i->state);
        coroutine_i->state = NULL;
      }
      if (coroutine_i->dependencies) {
        free(coroutine_i->dependencies);
        coroutine_i->dependencies = NULL;
      }
    }
    free(manager->queue);
    free(manager->queue_vacant_indexes);
  }
  *manager = (coroutine_manager_t){};
}

size_t coroutine_manager_find_vacant_slot(coroutine_manager_t* manager) {
  if (!manager->queue_vacant_indexes[0]) {
    return -1llu;
  }
  size_t i = 0;
  size_t l = 0;
  size_t r = manager->queue_size - 1;
  while ((r - l) > 3) {
    i = (r + 2 * l) / 3;
    if (manager->queue_vacant_indexes[i] > 0) {
      l = i;
    } else {
      r = i;
    }
  }
  i = r;
  while (manager->queue_vacant_indexes[i] == 0) { i--; };
  return i;
}

size_t coroutine_manager_add_vacant_slot(coroutine_manager_t* manager, size_t index) {
  size_t idx = coroutine_manager_find_vacant_slot(manager);
  if (!(idx + 1)) {
    return -1llu;
  }
  manager->queue_vacant_indexes[idx] = 1 + index;
  return idx + 1;
}

size_t coroutine_manager_take_vacant_slot(coroutine_manager_t* manager) {
  size_t idx = coroutine_manager_find_vacant_slot(manager);
  if (!(idx + 1)) {
    return -1llu;
  }
  size_t slot_idx = manager->queue_vacant_indexes[idx] - 1;
  manager->queue_vacant_indexes[idx] = 0;
  return slot_idx;
}


coroutine_t* coroutine_manager_t_add(coroutine_manager_t* manager, coroutine_t* coroutine) {
  if (manager->queue_size + 1 >= manager->queue_capacity) {
    coroutine_manager_t_reserve(manager);
  }
  size_t idx = coroutine_manager_take_vacant_slot(manager);
  // printf("ADD%d\n", idx + 1);
  if (!(idx + 1)) {
    idx = manager->queue_size++;
  }
  printf("ID: %d\n", idx);
  coroutine_t* coroutine_idx = coroutine_manager_get_cor(manager, idx);
  *coroutine_idx = *coroutine;
  if (coroutine->dependencies) {
    size_t i = 0;
    while (coroutine->dependencies[i]) {
      coroutine->dependencies[i++]->ref_count++;
    }
  }
  coroutine_idx->manager = manager;
  coroutine_idx->status = COR_ASSIGNED;
  return coroutine_idx;
}

coroutine_manager_t* coroutine_manager_t_remove(coroutine_manager_t* manager, size_t idx) {
  // printf("REM%d\n", idx + 1);
  coroutine_t* coroutine_idx = coroutine_manager_get_cor(manager, idx);
  if (coroutine_idx->args) {
    free(coroutine_idx->args);
    coroutine_idx->args = NULL;
  }
  if (coroutine_idx->state) {
    free(coroutine_idx->state);
    coroutine_idx->state = NULL;
  }
  if (coroutine_idx->dependencies) {
    free(coroutine_idx->dependencies);
    coroutine_idx->dependencies = NULL;
  }
  coroutine_manager_add_vacant_slot(manager, idx);
  *coroutine_idx = (coroutine_t){};
  coroutine_idx->status = COR_REMOVED;
  return manager;
}

coroutine_manager_t* coroutine_manager_add_signal_handler(coroutine_manager_t* manager, coroutine_signal_handler_t signal_handler) {
  manager->signal_handler = signal_handler;
  return manager;
}

coroutine_manager_t* __aux_coroutine_manager_t_run__() {
  coroutine_manager_t* manager = __aux_coroutine_manager_location__();
  coroutine_t* coroutine_i = NULL;
  for (size_t i = 0; i < manager->queue_size; ++i) {
    coroutine_i = coroutine_manager_get_cor(manager, i);
    if (coroutine_i->status == COR_ASSIGNED) {
      if (!setjmp(manager->env)) {
        coroutine_i->status = COR_INITIALIZED;
        coroutine_i->target(coroutine_i);
      }
      manager = __aux_coroutine_manager_location__();
    }
  }
  manager->state = 1;
  while (manager->state && !(manager->state & 2)) {
    if (!manager->queue_size) {
      manager->state = 0;
      break;
    }
    if (manager->signal_handler) {
      manager->signal = manager->signal_handler(0, manager->signal, NULL, manager);
    }
    manager->state |= 2;
    for (size_t i = 0; i < manager->queue_size; ++i) {
      printf("%d - AA DEP\n", i);
      coroutine_i = coroutine_manager_get_cor(manager, i);
      if (coroutine_i->status == COR_REMOVED) {
        continue;
      }
      if (coroutine_i->dependencies && coroutine_i->dependencies[0]) {
        size_t j = 0;
        BOOL ready = coroutine_i->dependencies[0]->status >= PRM_DONE;
        while (coroutine_i->dependencies[++j] && ready) {
          ready = coroutine_i->dependencies[j - 1]->status >= PRM_DONE;
        }
        if (!ready) {
          continue;
        }
      }
      // printf("%d - BB REM\n", i);
      if (coroutine_i->status >= COR_DONE || coroutine_i->status == COR_INVALID) {
        printf("%d - BC REM\n", i);
        if (coroutine_i->status == COR_CLAIMED && !coroutine_i->ref_count) {
          // printf("%d - BD REM\n", i);
          coroutine_manager_t_remove(manager, i);
        }
        continue;
      }
      // printf("%d - CC INIT\n", i);
      manager->state |= 2;
      manager->state ^= 2;
      if (coroutine_i->status == COR_ASSIGNED) {
        if (!setjmp(manager->env)) {
          coroutine_i->status = COR_INITIALIZED;
          coroutine_i->target(coroutine_i);
        }
        manager = __aux_coroutine_manager_location__();
        continue;
      }
      // printf("%d - DD SETJMP\n", i);
      switch (setjmp(manager->env)) {
        case -1:
          // printf("%d - EE-1 DEP\n", i);
          manager = __aux_coroutine_manager_location__();
          coroutine_i = coroutine_manager_get_cor(manager, i);
          coroutine_i->status = COR_INVALID;
          if (manager->signal_handler) {
            coroutine_signal_t man_signal = manager->signal_handler(0, -1, coroutine_i, manager);
            coroutine_i->signal = manager->signal_handler(-1, 0, coroutine_i, manager);
            manager->signal = man_signal;
          }
          break;
        
        case 0:
          // printf("%d - EE0 DEP\n", i);
          manager = __aux_coroutine_manager_location__();
          coroutine_i->status = COR_RUNNING;
          *__aux_coroutines_location__() = coroutine_i;
          if (manager->signal_handler) {
            coroutine_i->signal = manager->signal_handler(0, manager->signal, coroutine_i, manager);
          }
          // printf("%d - FF LJMP\n", coroutine_i->env);
          longjmp(coroutine_i->env, 1);
          break;

        case 1:
          // printf("%d - EE1 DEP\n", i);
          manager = __aux_coroutine_manager_location__();
          coroutine_i = coroutine_manager_get_cor(manager, i);
          coroutine_i->status = COR_YIELDED;
          coroutine_i->signal = 0;
          break;

        case 2:
          // printf("%d - EE2 DEP\n", i);
          manager = __aux_coroutine_manager_location__();
          coroutine_i = coroutine_manager_get_cor(manager, i);
          coroutine_i->status = COR_DONE;
          break;
        
        default:
          // printf("%d - EEDEF DEP\n", i);
          manager = __aux_coroutine_manager_location__();
          coroutine_i = coroutine_manager_get_cor(manager, i);
          coroutine_i->status = COR_YIELDED;
          if (manager->signal_handler) {
            manager->signal = manager->signal_handler(coroutine_i->signal, 0, coroutine_i, manager);
          }
          break;
      }
      manager = __aux_coroutine_manager_location__();
      if (!manager->queue_size) {
        break;
      }
    }
  }
  return __aux_coroutine_manager_location__();
}


promise_t __aux_co_promise_call__(promise_target_t target,
                                  size_t target_state_size,
                                  size_t target_args_size,
                                  void* target_args,
                                  promise_t** dependencies) {
  coroutine_t coroutine = (coroutine_t){.target=target,
                                        .args=target_args};
  coroutine.state = calloc(target_state_size, 1);
  coroutine.args = calloc(target_args_size, 1);
  coroutine.ref_count = 1;
  if (dependencies && dependencies[0]) {
    size_t i = 0;
    while (dependencies[++i]) {}
    if (i) {
      coroutine.dependencies = (promise_handler_t**)malloc(
                                 (i + 1) * sizeof(void*)
                               );
      for (size_t j = 0; j < i; ++j) {
        coroutine.dependencies[j] = dependencies[j]->handler;
      }
      coroutine.dependencies[i] = NULL;
    }
  }
  if (target_args) {
    memcpy(coroutine.args, target_args, target_args_size);
  }
  coroutine_manager_t* manager = __aux_coroutine_manager_location__();
  if (!manager->queue) {
    printf("MAN-INIT\n");
    coroutine_manager_t_init(manager);
  }
  return (promise_t){0, 0, (promise_handler_t*)coroutine_manager_t_add(manager, &coroutine), NULL};
}

void* __aux_co_promise_handler_await__(coroutine_t* coroutine) {
  __aux_coroutine_manager_t_run__();
  void* result = coroutine->result;
  return result;
}

void __aux_co_promise_handler_claim__(coroutine_t* coroutine) {
  // printf("CLAIM\n");
  if (coroutine->ref_count > 0) {
    coroutine->ref_count--;
  }
  if (!coroutine->ref_count) {
    if (coroutine->args) {
      free(coroutine->args);
      coroutine->args = NULL;
    }
    if (coroutine->state) {
      free(coroutine->state);
      coroutine->state = NULL;
    }
    if (coroutine->dependencies) {
      free(coroutine->dependencies);
      coroutine->dependencies = NULL;
    }
    *coroutine = (coroutine_t){};
  }
  coroutine->status = COR_CLAIMED;
}

void __aux_co_promise_handler_destroy__() {
  coroutine_manager_t_destroy(__aux_coroutine_manager_location__());
}

coroutine_signal_t __aux_coroutine_yield_handler__(void* result, long signal, coroutine_t* coroutine) {
  if (result) {
    coroutine->result = result;
  }
  if (signal < 0) {
    coroutine->signal = -signal;
    return -1;
  }
  coroutine->signal = signal;
  return (signal == 0) ? 0 : 3;
}
