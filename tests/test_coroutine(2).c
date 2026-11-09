#include "../src/async/promise.h"

typedef struct coroutine_manager_t coroutine_manager_t;

typedef unsigned int coroutine_signal_t;

#define INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY 8

typedef struct coroutine_t {
  promise_target_t target;
  void* args;
  void* state;
  void* result;
  promise_predicate_t predicate;
  promise_callback_t callback;
  struct promise_handler_t** dependencies;
  unsigned int ref_count;
  unsigned int arg_size;
  promise_handler_mask_t mask;
  promise_handler_status_t status;
  coroutine_signal_t signal;
  struct timeval timer;
  coroutine_manager_t* manager;
  struct coroutine_t* sync_call_prev;
  jmp_buf env;
  jmp_buf temp_env;
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
  coroutine_t** queue;
  size_t* queue_vacant_indexes;
  coroutine_t* entry_point;
  unsigned int queue_size;
  unsigned int queue_capacity;
  coroutine_manager_status_t state;
  coroutine_manager_mask_t mask;
  coroutine_signal_t signal;
  coroutine_signal_handler_t signal_handler;
  jmp_buf manager_env;
  jmp_buf return_env;
  size_t current_cor_index;
} coroutine_manager_t;

typedef enum {
  COR_STOPPED=-2,
  COR_INVALID=-1,
  COR_WAITING,
  COR_ASSIGNED,
  COR_INITIALIZED,
  COR_RUNNING,
  COR_YIELDED,
  COR_BLOCKED,
  COR_DONE,
  COR_CLAIMED,
  COR_REMOVED
} coroutine_state_enum;

coroutine_manager_t* __aux_coroutine_manager_location__();

coroutine_t** __aux_coroutine_location__();

coroutine_manager_t* coroutine_manager_queue_reserve(coroutine_manager_t* manager);

coroutine_manager_t* coroutine_manager_t_init(coroutine_manager_t* manager);

void coroutine_manager_t_destroy(coroutine_manager_t* manager);

coroutine_t* coroutine_manager_t_add(coroutine_manager_t* manager,
                                     coroutine_t* coroutine);

coroutine_manager_t* coroutine_manager_t_remove(coroutine_manager_t* manager,
                                                size_t idx);

coroutine_manager_t* coroutine_manager_add_signal_handler(coroutine_manager_t* manager,
                                                          coroutine_signal_handler_t signal_handler);

promise_t __aux_co_promise_add__(coroutine_t arg_cor);

int __aux_coroutine_yield_handler__(void* resultA, void* resultB, coroutine_t* coroutine);



coroutine_manager_t __AUX_COR_MANAGERS__[2 * MAX_THREAD_COUNT] = {};
coroutine_t* __AUX_COR_COROUTINES_PTR__[2 * MAX_THREAD_COUNT] = {};

coroutine_manager_t* __aux_coroutine_manager_location__() {
  return __aux_thread_safe_static_val_get__(__AUX_COR_MANAGERS__, sizeof(coroutine_manager_t));
}

coroutine_t** __aux_coroutine_location__() {
  return __aux_thread_safe_static_val_get__(__AUX_COR_COROUTINES_PTR__, sizeof(void*));
}

coroutine_t* coroutine_manager_get_at(coroutine_manager_t* manager, size_t index) {
  if (index >= manager->queue_size) {
    return NULL;
  }
  size_t high_bucket_id = sizeof(size_t) * __CHAR_BIT__;
  size_t low_bucket_id = 0;
  size_t low_bound_index = INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY;
  size_t bucket_id_delta = 1;
  while (bucket_id_delta) {
    bucket_id_delta = (high_bucket_id - low_bucket_id) / 2;
    if ((low_bound_index << bucket_id_delta) < (index + 1)) {
      low_bound_index <<= bucket_id_delta;
      low_bucket_id += bucket_id_delta;
    } else if ((low_bound_index << bucket_id_delta) > (index + 1)) {
      high_bucket_id -= bucket_id_delta;
    } else {
      low_bound_index <<= bucket_id_delta;
      low_bucket_id += bucket_id_delta;
      break;
    }
  }
  size_t cor_index = index - low_bound_index + INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY;
  if (cor_index >= (INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY << low_bucket_id)) {
    cor_index ^= (INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY << low_bucket_id);
    low_bucket_id++;
  }
  // printf("B(%d): %d; %d; %d\n", index, low_bound_index, low_bucket_id, cor_index);
  return &manager->queue[low_bucket_id][cor_index];
}

size_t coroutine_manager_bucket_queue_capacity(coroutine_manager_t* manager) {
  size_t i = INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY - 2;
  while (manager->queue[++i]);
  return i;
}

size_t coroutine_manager_bucket_queue_size(coroutine_manager_t* manager) {
  size_t i = 0;
  while (manager->queue[i++] != INVALID) {
    // printf("I: %d; Q: %d\n", i - 1, manager->queue[i - 1]);
  };
  // printf("I: %d; Q: %d\n", i - 1, manager->queue[i - 1]);
  return --i;
}

coroutine_manager_t* coroutine_manager_queue_reserve(coroutine_manager_t* manager) {
  size_t bucket_queue_size = coroutine_manager_bucket_queue_size(manager);
  size_t bucket_queue_capacity = coroutine_manager_bucket_queue_capacity(manager);
  // printf("Reserve - %d - %d - %d - %d\n", manager->queue_size, manager->queue_capacity, bucket_queue_size, bucket_queue_capacity);
  if ((bucket_queue_size + 1) == bucket_queue_capacity) {
    coroutine_t** old_queue = manager->queue;
    manager->queue = (coroutine_t**)malloc((bucket_queue_capacity *= 2) * sizeof(coroutine_t*));
    memcpy(manager->queue, old_queue, sizeof(coroutine_t*) * bucket_queue_size);
    for (size_t i = bucket_queue_size; i < bucket_queue_capacity - 1; ++i) {
      manager->queue[i] = INVALID;
    }
    manager->queue[bucket_queue_capacity - 1] = NULL;
    free(old_queue);
  }
  size_t* old_vacant_indexes = manager->queue_vacant_indexes;
  size_t new_capacity = manager->queue_capacity;
  size_t new_bucket_capacity = manager->queue_capacity + INITIAL_COROUTINE_MANAGER_QUEUE_CAPACITY;
  manager->queue[bucket_queue_size] = (coroutine_t*)calloc(new_bucket_capacity, sizeof(coroutine_t));
  manager->queue_capacity = new_capacity + new_bucket_capacity;
  manager->queue_vacant_indexes = (size_t*)calloc(manager->queue_capacity, sizeof(size_t));
  memcpy(manager->queue_vacant_indexes, old_vacant_indexes, sizeof(size_t) * manager->queue_size);
  free(old_vacant_indexes);
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
  manager->current_cor_index = 0;
  return manager;
}

void coroutine_manager_t_destroy(coroutine_manager_t* manager) {
  if (manager->queue) {
    coroutine_t* coroutine_i = NULL;
    for (size_t i = 0; i < manager->queue_size; ++i) {
      coroutine_i = coroutine_manager_get_at(manager, i);
      do {
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
        coroutine_i = coroutine_i->sync_call_prev;
      } while (coroutine_i);
    }

    for (size_t i = 0; i < coroutine_manager_bucket_queue_size(manager); ++i) {
      if (manager->queue[i]) {
        free(manager->queue[i]);
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
    coroutine_manager_queue_reserve(manager);
  }
  size_t idx = coroutine_manager_take_vacant_slot(manager);
  // printf("ADD%d\n", idx + 1);
  if (!(idx + 1)) {
    idx = manager->queue_size++;
  }
  // printf("ID: %d\n", idx);
  coroutine_t* coroutine_new = coroutine_manager_get_at(manager, idx);
  *coroutine_new = *coroutine;
  if (coroutine->dependencies) {
    size_t i = 0;
    while (coroutine->dependencies[i]) {
      coroutine->dependencies[i++]->ref_count++;
    }
    if (i) {
      coroutine_new->dependencies = (promise_handler_t**)malloc(i * sizeof(promise_handler_t*));
      memcpy(coroutine_new->dependencies, coroutine->dependencies, i * sizeof(promise_handler_t*));
    }
  }
  if (coroutine->args) {
    coroutine_new->args = (void*)malloc(coroutine->arg_size * sizeof(promise_handler_t*));
    memcpy(coroutine_new->args, coroutine->args, coroutine->arg_size);
  }
  coroutine_new->state = NULL;
  coroutine_new->manager = manager;
  coroutine_new->status = COR_ASSIGNED;
  coroutine_new->sync_call_prev = NULL;
  return coroutine_new;
}

coroutine_t* coroutine_sync_call(coroutine_t* self, coroutine_t* coroutine) {
  coroutine_t* coroutine_new = (coroutine_t*)malloc(sizeof(coroutine_t));
  *coroutine_new = *coroutine;
  if (coroutine->dependencies) {
    size_t i = 0;
    while (coroutine->dependencies[i]) {
      coroutine->dependencies[i++]->ref_count++;
    }
    if (i) {
      coroutine_new->dependencies = (promise_handler_t**)malloc(i * sizeof(promise_handler_t*));
      memcpy(coroutine_new->dependencies, coroutine->dependencies, i * sizeof(promise_handler_t*));
    }
  }
  if (coroutine->args) {
    coroutine_new->args = (void*)malloc(coroutine->arg_size * sizeof(promise_handler_t*));
    memcpy(coroutine_new->dependencies, coroutine->dependencies, coroutine->arg_size * sizeof(promise_handler_t*));
  }
  coroutine_new->state = NULL;
  coroutine_new->manager = self->manager;
  coroutine_new->status = COR_ASSIGNED;
  coroutine_new->sync_call_prev = self;
  return coroutine_new;
}

coroutine_manager_t* coroutine_manager_t_remove(coroutine_manager_t* manager, size_t idx) {
  // printf("REM%d\n", idx + 1);
  coroutine_t* coroutine_idx = coroutine_manager_get_at(manager, idx);
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

coroutine_manager_t* coroutine_manager_add_signal_handler(coroutine_manager_t* manager,
                                                          coroutine_signal_handler_t signal_handler) {
  manager->signal_handler = signal_handler;
  return manager;
}

coroutine_manager_t* coroutine_manager_peak(coroutine_manager_t* manager, coroutine_t* coroutine) {
  if ((coroutine->status == COR_ASSIGNED) && !setjmp(coroutine->temp_env)) {
    *__aux_coroutine_location__() = coroutine;
    coroutine->target(coroutine, NULL);
  }
  return manager;
}

coroutine_t* coroutine_next_cor(coroutine_t* coroutine) {
  coroutine_t* next_coroutine = NULL;
  size_t index = coroutine->manager->current_cor_index;
  size_t cnt = 0;
  while ((next_coroutine = coroutine_manager_get_at(coroutine->manager, \
                                                    (index = (index + 1) % coroutine->manager->queue_size))) && \
         (next_coroutine->status < COR_INITIALIZED || \
          next_coroutine->status >= COR_DONE) &&
         (cnt < coroutine->manager->queue_size)) {
    cnt++;
    // printf("Index: %d\n", index);
    if (next_coroutine->status < COR_INITIALIZED) {
      coroutine_manager_peak(coroutine->manager, next_coroutine);
    }
  }
  coroutine->manager->current_cor_index = index;
  if (cnt >= coroutine->manager->queue_size) {
    return NULL;
  }
  return next_coroutine;
}


void __aux_co_promise_handler_await__(coroutine_t* coroutine) {
  coroutine->manager->entry_point = coroutine;
  // coroutine_t* entry_coroutine_var = coroutine;
  volatile char coroutine_stack_padding[2 * sizeof(void*)];
  for (size_t i = 0; i < 2 * sizeof(void*); ++i) {
    coroutine_stack_padding[i] = 0;
  }
  coroutine_t* current_coro = coroutine;
  do {
    // printf("CURCOR: %d\n", current_coro);
    coroutine_manager_t* manager;
    switch (setjmp(current_coro->temp_env)) {
      case 0:
        manager = __aux_coroutine_manager_location__();
        *__aux_coroutine_location__() = current_coro;
        if (manager->signal_handler) {
          current_coro->signal = manager->signal_handler(-1,
                                                        manager->signal,
                                                        current_coro,
                                                        manager);
        }
        longjmp(current_coro->env, 1);
        break;
      case 1:
        manager = __aux_coroutine_manager_location__();
        current_coro = *__aux_coroutine_location__();
        break;
      case 3:
        current_coro = *__aux_coroutine_location__();
        current_coro->status = COR_DONE;
        break;
      case 5:
        manager = __aux_coroutine_manager_location__();
        current_coro = *__aux_coroutine_location__();
        if (manager->signal_handler) {
          current_coro->signal = manager->signal_handler(current_coro->signal,
                                                        -1,
                                                        current_coro,
                                                        manager);
        }
        break;
      case 7:
        manager = __aux_coroutine_manager_location__();
        current_coro = *__aux_coroutine_location__();
        if (manager->signal_handler) {
          current_coro->signal = manager->signal_handler(current_coro->signal,
                                                        -1,
                                                        current_coro,
                                                        manager);
        }
        current_coro->status = COR_DONE;
        break;
    }
  } while (current_coro = coroutine_next_cor(current_coro));
  printf("Escaped AWAIT WRAPPER!\n");
  // longjmp(__aux_coroutine_manager_location__()->return_env, 1);
  // return coroutine->result;
  // return NULL;
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

promise_t __aux_co_promise_add__(coroutine_t arg_cor) {
  coroutine_t* new_coroutine = coroutine_manager_t_add(__aux_coroutine_manager_location__(), &arg_cor);
  coroutine_manager_peak(__aux_coroutine_manager_location__(), new_coroutine);
  return (promise_t){.handler = (promise_handler_t*)new_coroutine, .result = new_coroutine->result, .status = new_coroutine->status};
}

int __aux_coroutine_yield_handler__(void* resultA, void* resultB, coroutine_t* coroutine) {
  if (resultA || resultB) {
    return 4;
  }
  return 0;
}


#define CorDecl(NAME, ARG_STRUCT_DEF, STATE_STRUCT_DEF) \
  typedef struct NAME##_cr_args { \
    ARG_STRUCT_DEF; \
  } NAME##_cor_args; \
  typedef struct NAME##_cr_state { \
    STATE_STRUCT_DEF; \
  } NAME##_cor_state; \
  void NAME##_coroutine(coroutine_t* self)

typedef struct NULL_cor_args {
} NULL_cor_args;

typedef struct NULL_cor_state {
} NULL_cor_state;

#define cor_init(NAME) \
  self->state = calloc(1, sizeof(NAME##_cor_state)); \
  NAME##_cor_args* args = (NAME##_cor_args*)self->args; \
  NAME##_cor_state* state = (NAME##_cor_state*)self->state; \
  if (!setjmp(self->env)) { \
    self->status = COR_INITIALIZED; \
    longjmp(self->temp_env, 1); \
  } \
  self = *__aux_coroutine_location__(); \
  args = (NAME##_cor_args*)self->args; \
  state = (NAME##_cor_state*)self->state; \

#define __AUX_COROUTINE_DEF_EXP__(NAME) \
  void NAME##_coroutine(coroutine_t* self)

#define __AUX_COROUTINE_DEF__(NAME) \
  __AUX_COROUTINE_DEF_EXP__(NAME)

#define __AUX_CR_ARG1__(X, Y...) X
#define __AUX_CR_ARG2__(X, Y, Z...) Y

#define CorDef(NAME) \
  __AUX_COROUTINE_DEF__(__AUX_CR_ARG1__(NAME))

#define cor_yield(RESULT...) \
  if (!setjmp(self->env)) { \
    longjmp(self->temp_env, \
      __aux_coroutine_yield_handler__(ARG1_VA_ARGS(RESULT, 0), \
                                      ARG2_VA_ARGS(RESULT, 0), \
                                      self)); \
  } \
  self = *__aux_coroutine_location__(); \
  args = self->args; \
  state = self->state; \


#define cor_return(RESULT) \
  self->result = ((void*)(RESULT)); \
  longjmp(self->temp_env, 3 | __aux_coroutine_yield_handler__(ARG1_VA_ARGS(RESULT, 0), \
                                                              ARG2_VA_ARGS(RESULT, 0), \
                                                              self))


#define COR_SYNC_CALL(TARGET, ARGS...) \


#define COR_ASYNC_CALL(TARGET, ARGS...) \


#define cor_promise(NAME, ARGS...) \
  __aux_co_promise_call__((promise_target_t)NAME##_coroutine, sizeof(NAME##_cor_state), sizeof(NAME##_cor_args), ARG1_VA_ARGS(ARGS, NULL), ARG2_VA_ARGS(ARGS, NULL))


#define cor_add(NAME, ARGS...) \
  __aux_co_promise_add__((coroutine_t){.target = (promise_target_t)NAME##_coroutine, \
                                       .args = &(NAME##_cor_args){ARGS}, \
                                       .arg_size = sizeof(NAME##_cor_args)}) \


CorDecl(cort1, int a, int b);

int cntext = 0;

int _Atomic _Acntext = 0;

int addOne() {
  return _Acntext++;
}

CorDef(cort1) {
  printf("Init\n");
  cor_init(cort1);
  state->b = (cntext++);
  printf("Yield - 1! (%d)\n", state->b);
  cor_yield(0);
  printf("Yield - 2! (%d)\n", state->b);
  cor_yield(0);
  addOne();
  printf("Yield - 3! (%d)\n", state->b);
  cor_yield(0);
  printf("Ret\n");
  cor_return(0);
}


int sds(int index) {
  coroutine_manager_t_init(__aux_coroutine_manager_location__());
  promise_t cor0 = cor_add(cort1);
  promise_t cor1 = cor_add(cort1);
  promise_t cor2 = cor_add(cort1);
  promise_t cor3 = cor_add(cort1);
  promise_t cor4 = cor_add(cort1);
  promise_t cor5 = cor_add(cort1);
  promise_t cor6 = cor_add(cort1);
  promise_t cor7 = cor_add(cort1);
  promise_t cor8 = cor_add(cort1);
  promise_t cor9 = cor_add(cort1);
  promise_t cor10 = cor_add(cort1);
  promise_t cor11 = cor_add(cort1);
  promise_t cor12 = cor_add(cort1);
  promise_t cor13 = cor_add(cort1);
  promise_t cor14 = cor_add(cort1);
  promise_t cor15 = cor_add(cort1);
  promise_t cor16 = cor_add(cort1);
  promise_t cor17 = cor_add(cort1);
  promise_t cor18 = cor_add(cort1);
  promise_t cor19 = cor_add(cort1);
  promise_t cor20 = cor_add(cort1);
  promise_t cor21 = cor_add(cort1);
  promise_t cor22 = cor_add(cort1);
  promise_t cor23 = cor_add(cort1);
  promise_t cor24 = cor_add(cort1);
  promise_t cor25 = cor_add(cort1);
  // coroutine_t* cor1 = coroutine_manager_t_add(__aux_coroutine_manager_location__(), &(coroutine_t){.target = (promise_target_t)cort1_coroutine,
  //                                                                                                   .args = &(cort1_cor_args){},
  //                                                                                                   .arg_size = sizeof(cort1_cor_args)});
  // coroutine_t* cor2 = coroutine_manager_t_add(__aux_coroutine_manager_location__(), &(coroutine_t){.target = (promise_target_t)cort1_coroutine,
  //                                                                                                   .args = &(cort1_cor_args){},
  //                                                                                                   .arg_size = sizeof(cort1_cor_args)});
  // coroutine_t* cor3 = coroutine_manager_t_add(__aux_coroutine_manager_location__(), &(coroutine_t){.target = (promise_target_t)cort1_coroutine,
  //                                                                                                   .args = &(cort1_cor_args){},
  //                                                                                                   .arg_size = sizeof(cort1_cor_args)});
  // // coroutine_manager_peak(__aux_coroutine_manager_location__(), cor3);
  // coroutine_t* cor4 = coroutine_manager_t_add(__aux_coroutine_manager_location__(), &(coroutine_t){.target = (promise_target_t)cort1_coroutine,
  //                                                                                                   .args = &(cort1_cor_args){},
  //                                                                                                   .arg_size = sizeof(cort1_cor_args)});
  // coroutine_t* cor5 = coroutine_manager_t_add(__aux_coroutine_manager_location__(), &(coroutine_t){.target = (promise_target_t)cort1_coroutine,
  //                                                                                                   .args = &(cort1_cor_args){},
  //                                                                                                   .arg_size = sizeof(cort1_cor_args)});
  // if (!setjmp(__aux_coroutine_manager_location__()->ret_env)) {
  //   printf("ENV is %d\n", *(int*)&__aux_coroutine_manager_location__()->ret_env);
  __aux_co_promise_handler_await__((coroutine_t*)cor0.handler);
  // }
  coroutine_manager_t_destroy(__aux_coroutine_manager_location__());
  return 0;
}


int main() {
  sds(0);
  printf("HUI! - (%d)\n", _Acntext);
  return 0;
}
