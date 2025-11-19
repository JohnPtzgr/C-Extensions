#include "../oop/exception.h"
#include "setjmp.h"
#include "stdarg.h"

#define CR_LIST_INITIAL_CAPACITY 8

#define CR_ARG_LIST_MAX_SIZE 16

#define CR_DEFAULT_STACK_PADDING_SIZE 256

typedef struct generic_cr_state_t {
  size_t __size__;
} generic_cr_state_t;


typedef void (*coroutine_function_t)(void* crt, void* arg);

typedef struct async_handler_t async_handler_t;

typedef struct async_coroutine_t {
  int __signal__;
  int __state__;
  size_t __mask__;
  jmp_buf __jmp_buf__;
  size_t stack_size_ubnd;
  size_t index;
  size_t arg_size;
  coroutine_function_t function;
  void* arg;
  void* result;
  generic_cr_state_t* static_state_data;
  generic_cr_state_t* heap_state_data;
  async_handler_t* handler;
  struct async_coroutine_t* dependency;
} async_coroutine_t;


typedef int(*coroutine_signal_handler_t)(async_coroutine_t* coroutine,
                                         int jump_result,
                                         int manager_state);


typedef struct async_handler_t {
  jmp_buf __jmp_buf__;
  size_t __mask__;
  size_t stack_size;
  size_t cr_list_size;
  size_t cr_list_capacity;
  coroutine_signal_handler_t signal_handler;
  async_coroutine_t* cr_list_data;
} async_handler_t;

void __async_coroutine_sync_call__(async_coroutine_t* self,
                                   async_coroutine_t* target);
void* __async_coroutine_async_call__(async_coroutine_t** self,
                                     async_coroutine_t* target);
void* __aux_async_coroutine_init_calloc__(size_t size);

void* __async_handler_init__(async_handler_t* self, size_t stack_size);
void* __async_handler_destroy__(async_handler_t* self);
void* __async_handler_call__(async_handler_t* self);
size_t __async_handler_find__(async_handler_t* self, async_coroutine_t* crt);
void* __async_handler_remove__(async_handler_t* self, async_coroutine_t* crt);
void* __async_handler_add__(async_handler_t* self, async_coroutine_t* crt);
void __async_handler_save__(async_handler_t* self, async_coroutine_t* crt, ... );
void __async_handler_restore__(async_handler_t* self, async_coroutine_t* crt, ... );

async_handler_t* __aux_mt_async_handler_location__();

#define __async_handler__ (*__aux_mt_async_handler_location__())

#define COROUTINE_DECL(NAME, ARG_STRUCT_DEF, STATE_STRUCT_DEF) \
  typedef struct NAME##_cr_args { \
    ARG_STRUCT_DEF; \
  } NAME##_cr_args; \
  typedef struct NAME##_cr_state { \
    size_t __size__; \
    STATE_STRUCT_DEF; \
  } NAME##_cr_state; \
  async_coroutine_t* __##NAME##_aux_crt_get__(NAME##_cr_args args); \
  void NAME##_coroutine(async_coroutine_t* crt, NAME##_cr_args* args);

typedef struct NULL_cr_state {
  size_t __size__;
} NULL_cr_state;


#define COROUTINE_INIT(NAME) \
  unsigned int __aux_tmp_ascr__ = 0; \
  crt->static_state_data = (generic_cr_state_t*)__aux_async_coroutine_init_calloc__(sizeof(NAME##_cr_state)); \
  crt->static_state_data->__size__ = sizeof(NAME##_cr_state); \
  crt->__signal__ = 1; \

#define __AUX_COROUTINE_DEF_EXP__(NAME, STACK_SIZE) \
  async_coroutine_t* __##NAME##_aux_crt_get__(NAME##_cr_args args) { \
    async_coroutine_t* crt = __aux_async_coroutine_init_calloc__(sizeof(async_coroutine_t)); \
    crt->function = (coroutine_function_t)NAME##_coroutine; \
    crt->arg_size = sizeof(NAME##_cr_args); \
    crt->stack_size_ubnd = STACK_SIZE; \
    crt->arg = __aux_async_coroutine_init_calloc__(sizeof(NAME##_cr_args)); \
    *(NAME##_cr_args*)crt->arg = args; \
    return crt; \
  } \
  void NAME##_coroutine(async_coroutine_t* crt, NAME##_cr_args* args)

#define __AUX_COROUTINE_DEF__(NAME, STACK_SIZE) \
  __AUX_COROUTINE_DEF_EXP__(NAME, STACK_SIZE)

#define __AUX_CR_ARG1__(X, Y...) X
#define __AUX_CR_ARG2__(X, Y, Z...) Y

#define COROUTINE(NAME...) \
  __AUX_COROUTINE_DEF__(__AUX_CR_ARG1__(NAME), __AUX_CR_ARG2__(NAME, 0))

#define COROUTINE_SAVEPOINT \
  __async_handler_save__(&__async_handler__, crt, NULL); \
  if (!(__aux_tmp_ascr__ = setjmp(crt->__jmp_buf__))) { \
    longjmp(__async_handler__.__jmp_buf__, crt->__signal__); \
  } \
  crt = &__async_handler__.cr_list_data[__aux_tmp_ascr__ - 1]; \
  __async_handler_restore__(&__async_handler__, crt, NULL); \
  crt->__signal__ = 1; \

#define COROUTINE_SAVEPOINT_ARGS(ARGS...) \
  __async_handler_save__(&__async_handler__, crt, ARGS, NULL); \
  if (!(__aux_tmp_ascr__ = setjmp(crt->__jmp_buf__))) { \
    longjmp(__async_handler__.__jmp_buf__, crt->__signal__); \
  } \
  crt = &__async_handler__.cr_list_data[__aux_tmp_ascr__ - 1]; \
  __async_handler_restore__(&__async_handler__, crt, ARGS, NULL); \
  crt->__signal__ = 1; \

#define COROUTINE_EXIT \
  __async_handler_remove__(&__async_handler__, crt); \
  longjmp(__async_handler__.__jmp_buf__, 1);


#define COROUTINE_ADD(NAME, ARG...) \
  (async_coroutine_t*)__async_handler_add__(&__async_handler__, \
                                            __##NAME##_aux_crt_get__((NAME##_cr_args)ARG));

#define COROUTINE_RUN \
  __async_handler_call__(&__async_handler__);

#define COROUTINE_SET_PADDING_SIZE(SIZE...) \
  (__async_handler__.stack_size = SIZE)


#define COROUTINE_SYNC_CALL(TARGET, ARGS...) \
  __async_handler_save__(&__async_handler__, crt, NULL); \
  if (!(__aux_tmp_ascr__ = setjmp(crt->__jmp_buf__))) { \
    __async_coroutine_sync_call__(crt, \
                                  __##TARGET##_aux_crt_get__((TARGET##_cr_args)ARGS)); \
  } \
  crt = &__async_handler__.cr_list_data[__aux_tmp_ascr__ - 1]; \
  __async_handler_restore__(&__async_handler__, crt, NULL); \
  crt->__signal__ = 1; \

#define COROUTINE_ASYNC_CALL(TARGET, ARGS...) \
  __async_coroutine_async_call__(&crt, \
                                 __##TARGET##_aux_crt_get__((TARGET##_cr_args)ARGS)); \
  
#define AWAIT(CRT) \
  while (!CRT->result) { \
    COROUTINE_SAVEPOINT; \
  } \


