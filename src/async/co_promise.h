#include "promise.h"
#pragma once

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
  size_t ref_count;
  promise_handler_mask_t mask;
  promise_handler_status_t status;
  coroutine_signal_t signal;
  struct timeval timer;
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
  coroutine_t** queue;
  size_t* queue_vacant_indexes;
  unsigned int queue_size;
  unsigned int queue_capacity;
  coroutine_manager_status_t state;
  coroutine_manager_mask_t mask;
  coroutine_signal_t signal;
  coroutine_signal_handler_t signal_handler;
  jmp_buf env;
} coroutine_manager_t;

typedef enum {
  COR_STOPPED=-2,
  COR_INVALID=-1,
  COR_WAITING,
  COR_ASSIGNED,
  COR_INITIALIZED,
  COR_RUNNING,
  COR_YIELDED,
  COR_DONE,
  COR_CLAIMED,
  COR_REMOVED
} coroutine_state_enum;

coroutine_manager_t* __aux_coroutine_manager_location__();

coroutine_t** __aux_coroutines_location__();

coroutine_manager_t* coroutine_manager_t_reserve(coroutine_manager_t* manager);

coroutine_manager_t* coroutine_manager_t_init(coroutine_manager_t* manager);

void coroutine_manager_t_destroy(coroutine_manager_t* manager);

coroutine_t* coroutine_manager_t_add(coroutine_manager_t* manager,
                                     coroutine_t* coroutine);

coroutine_manager_t* coroutine_manager_t_remove(coroutine_manager_t* manager,
                                                size_t idx);

coroutine_manager_t* coroutine_manager_add_signal_handler(coroutine_manager_t* manager,
                                                          coroutine_signal_handler_t signal_handler);

coroutine_manager_t* __aux_coroutine_manager_t_run__();

promise_t __aux_co_promise_call__(promise_target_t target,
                                  size_t target_state_size,
                                  size_t target_args_size,
                                  void* target_args,
                                  promise_t** dependencies);

void* __aux_co_promise_handler_await__(coroutine_t* coroutine);

void __aux_co_promise_handler_claim__(coroutine_t* coroutine);

void __aux_co_promise_handler_destroy__();

coroutine_signal_t __aux_coroutine_yield_handler__(void* result, long signal, coroutine_t* coroutine);

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
  NAME##_cor_args* args = (NAME##_cor_args*)self->args; \
  NAME##_cor_state* state = (NAME##_cor_state*)self->state; \
  if (!setjmp(self->env)) { \
    longjmp(self->manager->env, 0); \
  } \
  self = *__aux_coroutines_location__(); \
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
    longjmp(self->manager->env, \
      __aux_coroutine_yield_handler__(ARG1_VA_ARGS(RESULT, 0), \
                                      ARG2_VA_ARGS(RESULT, 0), \
                                      self)); \
  } \
  self = *__aux_coroutines_location__(); \
  self = *__aux_coroutines_location__(); \
  args = self->args; \
  state = self->state; \
  

#define cor_return(RESULT) \
  longjmp(self->manager->env, \
    2 + 0 * __aux_coroutine_yield_handler__(ARG1_VA_ARGS(RESULT, 0), \
                                            ARG2_VA_ARGS(RESULT, 0), \
                                            self))

#define COR_SYNC_CALL(TARGET, ARGS...) \
  

#define COR_ASYNC_CALL(TARGET, ARGS...) \
  
#define cor_promise(NAME, ARGS...) \
  __aux_co_promise_call__((promise_target_t)NAME##_coroutine, sizeof(NAME##_cor_state), sizeof(NAME##_cor_args), ARG1_VA_ARGS(ARGS, NULL), ARG2_VA_ARGS(ARGS, NULL))
