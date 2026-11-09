#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "../src/oop/class.h"

#define INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY 8


jmp_buf __AUX_CR_JUMP_BUFF_ENVS__[2 * MAX_THREAD_COUNT] = {};
pthread_t __aux_mt_thread_ids__[2 * MAX_THREAD_COUNT] = {};
pthread_t __aux_default_thread_0_init__;

void* __aux_mt_thread_ids_ptr__ = &__aux_mt_thread_ids__;
void* __aux_default_thread_0_init_ptr__ = &__aux_default_thread_0_init__;

static inline size_t __aux_mt_get_thread_idx__(pthread_t thread_id) {
  size_t seed = *(int*)&thread_id;
  size_t step = 0;
  size_t i = seed;
  pthread_t i_thread = __aux_default_thread_0_init__;
  do {
    i = (i + step) % (2 * MAX_THREAD_COUNT);
    i_thread = __aux_mt_thread_ids__[i];
    step = step * 2 + 1;
  } while (!pthread_equal(i_thread, thread_id) && \
           !pthread_equal(i_thread, __aux_default_thread_0_init__));
  if (pthread_equal(i_thread, __aux_default_thread_0_init__)) {
    __aux_mt_thread_ids__[i] = thread_id;
  }
  return i;
}

jmp_buf* __cr_jmp_buff_location__() {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return &(__AUX_CR_JUMP_BUFF_ENVS__[i]);
}

typedef enum {
  PRM_INVALID=-1,
  PRM_WAITING,
  PRM_ASSIGNED,
  PRM_INITIALIZED,
  PRM_RUNNING,
  PRM_YIELDED,
  PRM_DONE,
  PRM_STOPPED=24
} promise_state_enum;


typedef signed short promise_handler_status_t;
typedef unsigned short promise_handler_mask_t;
typedef unsigned int promise_handler_signal_t;
typedef generic_function_t promise_target_t;
typedef generic_function_t promise_callback_t;
typedef generic_predicate_t promise_predicate_t;

typedef struct promise_handler_t {
  promise_target_t target;
  void* args;
  void* state;
  void* result;
  promise_predicate_t predicate;
  promise_callback_t callback;
  struct promise_handler_t** dependencies;
  size_t ref_count;
  promise_handler_mask_t mask;
  promise_handler_status_t status;
  promise_handler_signal_t signal;
} promise_handler_t;


typedef unsigned short promise_mask_t;
typedef signed short promise_status_t;

typedef struct promise_t {
  promise_mask_t mask;
  promise_status_t status;
  promise_handler_t* handler;
  void* result;
} promise_t;


typedef struct coroutine_manager_t coroutine_manager_t;

typedef unsigned int coroutine_signal_t;

typedef struct coroutine_t {
  promise_target_t target;
  void* args;
  void* state;
  void* result;
  promise_predicate_t predicate;
  promise_callback_t callback;
  struct promise_handler_t** dependencies;
  size_t ref_count;
  promise_handler_mask_t mask;
  promise_handler_status_t status;
  coroutine_signal_t signal;
  coroutine_manager_t* manager;
  struct coroutine_t* next;
  struct coroutine_t* prev;
  jmp_buf env;
} coroutine_t;

typedef signed short coroutine_manager_status_t;
typedef unsigned short coroutine_manager_mask_t;
typedef unsigned int coroutine_manager_signal_t;
typedef coroutine_manager_signal_t(*coroutine_signal_handler_t)(
                                    promise_handler_signal_t coroutine_signal,
                                    coroutine_manager_signal_t manager_signal,
                                    coroutine_t* coroutine,
                                    coroutine_manager_t* manager
                                  );

typedef struct coroutine_manager_t {
  coroutine_t* queue;
  unsigned int queue_size;
  unsigned int queue_capacity;
  coroutine_manager_status_t state;
  coroutine_manager_mask_t mask;
  coroutine_signal_t signal;
  coroutine_signal_handler_t signal_handler;
  jmp_buf env;
} coroutine_manager_t;

typedef enum {
  CR_INVALID=-1,
  CR_WAITING,
  CR_ASSIGNED,
  CR_INITIALIZED,
  CR_RUNNING,
  CR_YIELDED,
  CR_DONE,
  CR_CLAIMED,
  CR_STOPPED=24
} coroutine_state_enum;


coroutine_manager_t __AUX_CR_MANAGERS__[2 * MAX_THREAD_COUNT] = {};
coroutine_t* __AUX_CR_COROUTINES_PTR__[2 * MAX_THREAD_COUNT] = {};

coroutine_manager_t* __aux_coroutine_manager_location__() {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return &(__AUX_CR_MANAGERS__[i]);
}

coroutine_t** __aux_coroutines_location__() {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return &(__AUX_CR_COROUTINES_PTR__[i]);
}

coroutine_manager_t* coroutine_manager_t_reserve(coroutine_manager_t* manager, size_t new_capacity) {
  coroutine_t* old_coroutines = manager->queue;
  manager->queue = (coroutine_t*)calloc(new_capacity, sizeof(coroutine_t));
  if (old_coroutines) {
    memcpy(manager->queue, old_coroutines, sizeof(coroutine_t) * manager->queue_size);
    free(old_coroutines);
  }
  manager->queue_capacity = new_capacity;
  return manager;
}

coroutine_manager_t* coroutine_manager_t_init(coroutine_manager_t* manager) {
  coroutine_manager_t_reserve(manager, INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY);
  memcpy(&manager->env, &(jmp_buf){}, sizeof(jmp_buf));
  manager->queue_size = 0;
  return manager;
}

void coroutine_manager_t_destroy(coroutine_manager_t* manager) {
  if (manager->queue) {
    for (size_t i = 0; i < manager->queue_size; ++i) {
      if (manager->queue[i].args) {
        free(manager->queue[i].args);
      }
      if (manager->queue[i].state) {
        free(manager->queue[i].state);
      }
      if (manager->queue[i].dependencies) {
        free(manager->queue[i].dependencies);
      }
    }
    free(manager->queue);
  }
  *manager = (coroutine_manager_t){};
}

coroutine_t* coroutine_manager_t_add(coroutine_manager_t* manager, coroutine_t* coroutine) {
  if (manager->queue_size + 1 >= manager->queue_capacity) {
    coroutine_manager_t_reserve(manager, manager->queue_capacity * 2);
  }
  manager->queue[manager->queue_size++] = *coroutine;
  if (coroutine->dependencies) {
    size_t i = 0;
    while (coroutine->dependencies[i]) {
      coroutine->dependencies[i++]->ref_count++;
    }
  }
  manager->queue[manager->queue_size - 1].manager = manager;
  manager->queue[manager->queue_size - 1].status = CR_ASSIGNED;
  return &manager->queue[manager->queue_size - 1];
}

coroutine_manager_t* coroutine_manager_t_remove(coroutine_manager_t* manager, size_t idx) {
  if (manager->queue[idx].args) {
    free(manager->queue[idx].args);
  }
  if (manager->queue[idx].state) {
    free(manager->queue[idx].state);
  }
  if (manager->queue[idx].dependencies) {
    free(manager->queue[idx].dependencies);
  }
  manager->queue[idx] = manager->queue[manager->queue_size - 1];
  manager->queue[--manager->queue_size] = (coroutine_t){};
  return manager;
}

coroutine_manager_t* coroutine_manager_add_signal_handler(coroutine_manager_t* manager, coroutine_signal_handler_t signal_handler) {
  manager->signal_handler = signal_handler;
}

coroutine_manager_t* coroutine_manager_t_run() {
  coroutine_manager_t* manager = __aux_coroutine_manager_location__();
  for (size_t i = 0; i < manager->queue_size; ++i) {
    if (!setjmp(manager->env)) {
      manager->queue[i].status = CR_INITIALIZED;
      manager->queue[i].target(&manager->queue[i]);
    }
    manager = __aux_coroutine_manager_location__();
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
    sleep(1);
    manager->state |= 2;
    for (size_t i = 0; i < manager->queue_size; ++i) {
      if (manager->queue[i].dependencies && manager->queue[i].dependencies[0]) {
        size_t j = 0;
        BOOL ready = manager->queue[i].dependencies[0]->status >= PRM_DONE;
        while (manager->queue[i].dependencies[++j] && ready) {
          ready = manager->queue[i].dependencies[j - 1]->status >= PRM_DONE;
        }
        if (!ready) {
          continue;
        }
      }
      if (manager->queue[i].status >= CR_DONE || manager->queue[i].status == CR_INVALID) {
        if (manager->queue[i].status == CR_CLAIMED && !manager->queue[i].ref_count) {
          coroutine_manager_t_remove(manager, i);
        }
        continue;
      }
      manager->state |= 2;
      manager->state ^= 2;
      if (manager->queue[i].status == CR_ASSIGNED) {
        if (!setjmp(manager->env)) {
          manager->queue[i].status = CR_INITIALIZED;
          manager->queue[i].target(&manager->queue[i]);
        }
        manager = __aux_coroutine_manager_location__();
        continue;
      }
      switch (setjmp(manager->env)) {
        case -1:
          manager = __aux_coroutine_manager_location__();
          manager->queue[i].status = CR_INVALID;
          break;
        
        case 0:
          manager = __aux_coroutine_manager_location__();
          manager->queue[i].status = CR_RUNNING;
          *__aux_coroutines_location__() = &manager->queue[i];
          if (manager->signal_handler) {
            manager->queue[i].signal = manager->signal_handler(0, manager->signal, &manager->queue[i], manager);
          }
          longjmp(manager->queue[i].env, 1);
          break;

        case 1:
          manager = __aux_coroutine_manager_location__();
          manager->queue[i].status = CR_YIELDED;
          manager->queue[i].signal = 0;
          break;

        case 2:
          manager = __aux_coroutine_manager_location__();
          manager->queue[i].status = CR_DONE;
          break;
        
        default:
          manager = __aux_coroutine_manager_location__();
          manager->queue[i].status = CR_YIELDED;
          if (manager->signal_handler) {
            manager->signal = manager->signal_handler(manager->queue[i].signal, 0, &manager->queue[i], manager);
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


// void __aux_co_promise_init_handler__(coroutine_t* coroutine) {
//   switch (setjmp(coroutine->env)) {
//     case 0:
//       longjmp(*__cr_jmp_buff_location__(), 0);
//       break;
//     case -1:
//       longjmp(*__cr_jmp_buff_location__(), -1);
//     case 2:
//       0;
//     default:
//       coroutine->target(coroutine, coroutine->state, coroutine->args);
//       break;
//   }
// }


promise_t __aux_co_promise_call__(promise_target_t target,
                                  size_t target_state_size,
                                  size_t target_args_size,
                                  void* target_args,
                                  promise_t** dependencies) {
  coroutine_t coroutine = (coroutine_t){.target=target,
                                        .args=target_args};
  coroutine.state = calloc(target_state_size, 1);
  coroutine.args = calloc(target_args_size, 1);
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
    coroutine_manager_t_init(manager);
  }
  return (promise_t){0, 0, (promise_handler_t*)coroutine_manager_t_add(manager, &coroutine), NULL};
}

void __aux_co_promise_handler_await__(coroutine_t* coroutine) {
  coroutine_manager_t_run(__aux_coroutine_manager_location__());
  // if (coroutine->status == PRM_DONE) {
  //   return;
  // }
}


typedef struct coroutine_manager_t coroutine_manager_t;

typedef unsigned int coroutine_signal_t;

typedef struct coroutine_t {
  promise_target_t target;
  void* args;
  void* state;
  void* result;
  promise_predicate_t predicate;
  promise_callback_t callback;
  struct promise_handler_t** dependencies;
  size_t ref_count;
  promise_handler_mask_t mask;
  promise_handler_status_t status;
  coroutine_signal_t signal;
  coroutine_manager_t* manager;
  struct coroutine_t* next;
  struct coroutine_t* prev;
  jmp_buf env;
} coroutine_t;

typedef unsigned short coroutine_manager_status_t;
typedef unsigned short coroutine_manager_mask_t;
typedef unsigned int coroutine_manager_signal_t;
typedef coroutine_manager_signal_t(*coroutine_signal_handler_t)(
                                    promise_handler_signal_t coroutine_signal,
                                    coroutine_manager_signal_t manager_signal,
                                    coroutine_t* coroutine,
                                    coroutine_manager_t* manager
                                  );

typedef struct coroutine_manager_t {
  coroutine_t* queue;
  unsigned int queue_size;
  unsigned int queue_capacity;
  coroutine_manager_status_t state;
  coroutine_manager_mask_t mask;
  coroutine_signal_t signal;
  coroutine_signal_handler_t signal_handler;
  jmp_buf env;
} coroutine_manager_t;





typedef void(*promise_handler_function_t)(promise_handler_t*);

#define __AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__ 64

promise_handler_function_t __aux_promise_handler_functions__[__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__] = {
  (promise_handler_function_t)__aux_co_promise_handler_await__
};

int __aux_promise_mask_get_type__(promise_t* promise) {
  return promise->mask & (__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__ - 1);
}

int __aux_promise_mask_set_type__(promise_t* promise, int type) {
  promise->mask = type | (promise->mask & (__UINT32_MAX__ - (__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__ - 1)));
  return promise->mask;
}

void __aux_promise_await__(promise_t* promise) {
  __aux_promise_handler_functions__[__aux_promise_mask_get_type__(promise)](promise->handler);
  promise->status = promise->handler->status;
}

int timer = 0;

typedef struct coro_state { int a; } coro_state;
typedef struct coro_args { int a; } coro_args;
void coro(coroutine_t* coroutine) {
  // volatile coroutine_t* self = NULL;
  // memcpy(&self, &coroutine, sizeof(void*));
  timer++;
  printf("SIG: %d\n", coroutine->signal);
  printf("a(%d), %d, %d\n", timer, coroutine, coroutine->manager);
  if (!setjmp(coroutine->env)) {
    longjmp(coroutine->manager->env, 0);
  }
  coroutine = *__aux_coroutines_location__();
  sleep(1);
  // memcpy(&coroutine, &self, sizeof(void*));
  timer++;
  memcpy(&coroutine->signal, &coroutine, sizeof(coroutine_signal_t));
  printf("SIG: %d\n", coroutine->signal);
  printf("b(%d), %d, %d\n", timer, coroutine, coroutine->manager);
  if (!setjmp(coroutine->env)) {
    longjmp(coroutine->manager->env, 10);
  }
  coroutine = *__aux_coroutines_location__();
  sleep(1);
  // memcpy(&coroutine, &self, sizeof(void*));
  timer++;
  printf("SIG: %d\n", coroutine->signal);
  printf("c(%d), %d, %d\n", timer, coroutine, coroutine->manager);
  longjmp(coroutine->manager->env, 2);
}

coroutine_t* curcor = NULL;
coroutine_t* trgcor = NULL;
int icrc = 0;

coroutine_signal_t simple_sig_handler(coroutine_signal_t coroutine_signal, coroutine_manager_signal_t manager_signal, coroutine_t* coroutine, coroutine_manager_t* manager) {
  coroutine_signal_t result = 0;
  printf("(curcor)%d - (trgcor)%d - (icrc)%d\n", curcor, trgcor, icrc);
  if (coroutine_signal && !manager_signal) {
    if (curcor == coroutine) {
      if (icrc == 3) {
        icrc = 0;
        curcor = NULL;
        return 0;
      }
      if (icrc == 2 && coroutine_signal == -1) {
        icrc = 3;
      } else {
        icrc = 2;
      }
      result = coroutine_signal;
    } else {
      switch (icrc) {
        case 0:
          icrc = 1;
          curcor = coroutine;
          result = coroutine_signal;
          break;
        default:
          result = manager->signal;
          break;
      }
    }
    return result;
  }
  if (!coroutine_signal && manager_signal) {
    if (coroutine) {
      if (!memcmp(&coroutine, &manager_signal, sizeof(coroutine_manager_signal_t))) {
        trgcor = coroutine;
        return 1;
      }
      if (trgcor == coroutine) {
        return manager_signal;
      }
    } else {
      result = manager_signal;
    }
    return result;
  }
}



// void __async_handler_manager__(async_handler_t* self) {
//   for (size_t i = 0; i < self->cr_list_size; ++i) {
//     if (!setjmp(self->__jmp_buf__)) {
//       __async_handler_set_cr_mask_init__(&self->cr_list_data[i], TRUE);
//       self->cr_list_data[i].function(&self->cr_list_data[i], self->cr_list_data[i].arg);
//     }
//   }
//   int manager_state = 1;
//   int jump_result = 0;
//   while (manager_state)
//   {
//     if (!self->cr_list_size) {
//       manager_state = 0;
//       break;
//     }
//     for (size_t i = 0; i < self->cr_list_size; ++i) {
//       if (!__async_handler_get_cr_mask_init__(&self->cr_list_data[i])) {
//         if (!setjmp(self->__jmp_buf__)) {
//           __async_handler_set_cr_mask_init__(&self->cr_list_data[i], TRUE);
//           self->cr_list_data[i].function(&self->cr_list_data[i], self->cr_list_data[i].arg);
//         }
//         continue;
//       }
//       if (jump_result = setjmp(self->__jmp_buf__)) {
//         if (!self->cr_list_size) {
//           return;
//         }
//         switch (jump_result)
//         {
//           case -1:
//             if (self->signal_handler) {
//               manager_state = self->signal_handler(&self->cr_list_data[i],
//                                                    -1,
//                                                    manager_state);
//             } else {
//               __async_handler_remove__(self, &self->cr_list_data[i]);
//               manager_state = 0;
//             }
//             break;

//           case 1:
//             break;

//           default:
//             if (self->signal_handler) {
//               self->cr_list_data[i].__state__ = self->signal_handler(&self->cr_list_data[i],
//                                                                      jump_result,
//                                                                      manager_state);
//             }
//             break;
//         }
//       } else {
//         longjmp(self->cr_list_data[i].__jmp_buf__, 1 + i);
//         break;
//       }
//     }
//   }
//   return;
// }



int main() {
  promise_t promise1 = __aux_co_promise_call__((promise_target_t)coro, sizeof(coro_state), sizeof(coro_args), NULL, NULL);
  promise_t promise2 = __aux_co_promise_call__((promise_target_t)coro, sizeof(coro_state), sizeof(coro_args), NULL, NULL);
  promise_t promise3 = __aux_co_promise_call__((promise_target_t)coro, sizeof(coro_state), sizeof(coro_args), NULL, (promise_t*[]){&promise2, NULL});
  promise_t promise4 = __aux_co_promise_call__((promise_target_t)coro, sizeof(coro_state), sizeof(coro_args), NULL, (promise_t*[]){&promise3, NULL});
  promise_t promise5 = __aux_co_promise_call__((promise_target_t)coro, sizeof(coro_state), sizeof(coro_args), NULL, (promise_t*[]){&promise4, NULL});
  promise_t promise6 = __aux_co_promise_call__((promise_target_t)coro, sizeof(coro_state), sizeof(coro_args), NULL, (promise_t*[]){&promise5, NULL});
  promise_t promise7 = __aux_co_promise_call__((promise_target_t)coro, sizeof(coro_state), sizeof(coro_args), NULL, (promise_t*[]){&promise6, NULL});
  printf("ppp\n");
  coroutine_manager_add_signal_handler(__aux_coroutine_manager_location__(), (coroutine_signal_handler_t)simple_sig_handler);
  __aux_promise_await__(&promise1);
  coroutine_manager_t_destroy(__aux_coroutine_manager_location__());
  return 0;
}


