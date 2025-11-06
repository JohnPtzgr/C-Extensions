#include "../../src/oop/exception.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

// exception_t errexc = (exception_t){};

// exception_context_t _EXCEPTION_CONTEXT = (exception_context_t){};

exception_t caught_exception = (exception_t){};

// exception_context_t CAUGHT_EXCEPTION_CONTEXT = (exception_context_t){};

// unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR = 0;

exception_t __AUX_EXCEPTIONS__[2 * MAX_THREAD_COUNT] = {};
exception_context_t __AUX_EXCEPTION_CONTEXTS__[2 * MAX_THREAD_COUNT] = {};
size_t __AUX_EXCEPTION_SCOPE_INDENTS__[2 * MAX_THREAD_COUNT] = {};
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

exception_t* __errexc_location() {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return &(__AUX_EXCEPTIONS__[i]);
}

exception_context_t* __errctx_location() {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return &(__AUX_EXCEPTION_CONTEXTS__[i]);
}

size_t* __exception_scope_indent_location() {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return &(__AUX_EXCEPTION_SCOPE_INDENTS__[i]);
}



void* __raise_exception__(exception_t* exception) {
  errexc = *exception;
  if (errexc.context) {
    errctx = *(exception->context);
  }
  errno = exception->exception_number;
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) {
    __exit_on_exception__(&errexc, 0);
  }
  return INVALID;
}

void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...) {
  if (exception->exception_number == errexc.exception_number && errexc.exception_number) {
    if (clean_up) {
      clean_up();
    }
    perror(errexc.exception_description);
    const static unsigned int buffer_size = 128;
    char buffer[buffer_size];
    if (!errexc.context) {
      errexc.context = &errctx;
    }
    sprintf(buffer, "Terminating program with exit status %d.\n", exception->exception_number);
    write(2, buffer, strlen(buffer) + 1);
    if (errexc.context->data[0]) {
      const char exc_ctx_str[] = "The following section is first " \
                                 __EXCEPTION_CONSTEXPR_AS_STR(__DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__) \
                                 " byte(s) of exception context:\n";
      write(2, exc_ctx_str, sizeof(exc_ctx_str));
      write(2, errexc.context->data, __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__);
    }
    (__EXCEPTION_EXIT_CALLBACK__)(exception->exception_number);
  }
  return NULL;
}

void* __check_uncaught_exception__(exception_t* exception) {
  if (errno || errexc.exception_number) {
    __exit_on_exception__(exception, 0);
  }
  return NULL;
}

void* __exc_assert_fail__(exception_t* exception,
                          char* description,
                          const char* function_name,
                          void(*callback)()) {
  size_t sz = strlen(description);
  exception->context = 0;
  size_t fn_sz = strlen(function_name);
  for (size_t i = 0; i < fn_sz; ++i) {
    errctx.data[i] = function_name[i];
  }
  exception->exception_description = description;
  exception->exception_number = EASSERTEXC;
  errno = EASSERTEXC;
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) {
    __exit_on_exception__(&errexc, 0);
  }
  exception->status = 0;
  return NULL;
}

