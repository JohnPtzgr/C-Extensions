#include "promise.h"
#include "co_promise.h"
#include "th_promise.h"
#include "thp_promise.h"
#include "cothp_promise.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

jmp_buf __AUX_CR_JUMP_BUFF_ENVS__[2 * MAX_THREAD_COUNT] = {};

jmp_buf* __cr_jmp_buff_location__() {
  return __aux_thread_safe_static_val_get__(__AUX_CR_JUMP_BUFF_ENVS__, sizeof(jmp_buf));
}

promise_handler_function_t __aux_promise_handler_call_functions__[
          __AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__
        ] = \
      {
        (promise_handler_function_t)__aux_co_promise_handler_await__
      };

promise_handler_function_t __aux_promise_handler_claim_functions__[
          __AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__
        ] = \
      {
        (promise_handler_function_t)__aux_co_promise_handler_claim__
      };

promise_handler_function_t __aux_promise_handler_destroy_functions__[
          __AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__
        ] = \
      {
        (promise_handler_function_t)__aux_co_promise_handler_destroy__
      };

int __aux_promise_mask_get_type__(promise_t* promise) {
  return promise->mask & (__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__ - 1);
}

int __aux_promise_mask_set_type__(promise_t* promise, int type) {
  promise->mask = type | (promise->mask & (__UINT32_MAX__ - (__AUX_PROMISE_HANDLER_FUNCTIONS_VTABLE_SIZE__ - 1)));
  return promise->mask;
}

void* __aux_promise_await__(promise_t* promise) {
  promise->result = __aux_promise_handler_call_functions__[__aux_promise_mask_get_type__(promise)](promise->handler);
  promise->status = promise->handler->status;
  if (promise->status >= PRM_DONE) {
    promise->status = PRM_CLAIMED;
    promise->result = promise->handler->result;
    return promise->result;
  } else {
    promise->result = NULL;
    return NULL;
  }
}

void* __aux_promise_claim__(promise_t* promise) {
  void* result = promise->handler->result;
  __aux_promise_handler_claim_functions__[__aux_promise_mask_get_type__(promise)](promise->handler);
  promise->status = PRM_CLAIMED;
  return result;
}

void __aux_promise_destroy__(promise_t* promise) {
  __aux_promise_handler_destroy_functions__[__aux_promise_mask_get_type__(promise)](NULL);
  promise->status = PRM_INVALID;
  promise->handler = NULL;
}
