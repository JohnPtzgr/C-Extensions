#include <setjmp.h>
#include <sys/time.h>
#include "../oop/class.h"
// #include "pthread.h"

#pragma once

jmp_buf* __cr_jmp_buff_location__();

typedef enum {
  PRM_STOPPED=-2,
  PRM_INVALID=-1,
  PRM_WAITING,
  PRM_ASSIGNED,
  PRM_INITIALIZED,
  PRM_RUNNING,
  PRM_YIELDED,
  PRM_BLOCKED,
  PRM_DONE,
  PRM_CLAIMED
} promise_state_enum;


typedef signed short promise_handler_status_t;
typedef unsigned short promise_handler_mask_t;
typedef unsigned int promise_handler_signal_t;
typedef generic_function_t promise_target_t;
typedef generic_function_t promise_callback_t;
typedef generic_predicate_t promise_predicate_t;
typedef struct promise_handler_t promise_handler_t;
typedef struct promise_dependency_handler_t promise_dependency_handler_t;

typedef struct promise_handler_t {
  promise_target_t target;
  void* args;
  void* state;
  void* result;
  promise_predicate_t predicate;
  promise_callback_t callback;
  promise_dependency_handler_t* dependencies;
  promise_handler_mask_t mask;
  promise_handler_status_t status;
  promise_handler_signal_t signal;
  struct timeval timer;
} promise_handler_t;


typedef unsigned short promise_mask_t;
typedef signed short promise_status_t;

typedef struct promise_t {
  promise_mask_t mask;
  promise_status_t status;
  promise_handler_t* handler;
  void* result;
} promise_t;

typedef void*(*promise_handler_function_t)(promise_handler_t*);

#define __AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__ 64

extern promise_handler_function_t __aux_promise_handler_call_functions__[__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__];
extern promise_handler_function_t __aux_promise_handler_claim_functions__[__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__];
extern promise_handler_function_t __aux_promise_handler_destroy_functions__[__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__];

int __aux_promise_mask_get_type__(promise_t* promise);

int __aux_promise_mask_set_type__(promise_t* promise, int type);

void* __aux_promise_await__(promise_t* promise);

void* __aux_promise_claim__(promise_t* promise);

void __aux_promise_destroy__();

#define pr_await(PROMISE) \
  __aux_promise_await__(&(PROMISE))

#define pr_claim(PROMISE) \
  __aux_promise_claim__(&(PROMISE))

#define pr_destroy(PROMISE) \
  __aux_promise_destroy__(&(PROMISE))
