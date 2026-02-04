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


void* __aux_thread_safe_static_val_get__(void* static_list, size_t type_size) {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return static_list + (i * type_size);
}


void* __raise_exception__(exception_t* exception) {
  errexc = *exception;
  if (exception->context) {
    errctx = *(exception->context);
    errexc.context = &errctx;
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
    const static unsigned int buffer_size = 256 + FILENAME_MAX;
    char buffer[buffer_size];
    if (!errexc.context) {
      errexc.context = &errctx;
    }
    sprintf(buffer,
            "Terminating program with exit status %d.\n" \
            "Exception(%d)! In \'%s\' %s:%d (tracked scope depth %d):\n",
            exception->exception_number,
            exception->exception_number,
            exception->context->function_name,
            exception->context->filename,
            exception->context->line,
            exception->context->tracked_context_depth);
    write(2, buffer, strlen(buffer) + 1);
    if (errexc.exception_description) {
      perror(errexc.exception_description);
    } else {
      perror("");
    }
    if (errexc.context->data && errexc.context->data[0]) {
      const char exc_ctx_str[] = "The following section is first " \
                                 __EXCEPTION_CONSTEXPR_AS_STR(__DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__) \
                                 " byte(s) of exception context:\n";
      write(2, exc_ctx_str, sizeof(exc_ctx_str));
      write(2, errexc.context->data, __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__);
      write(2, "\n", 2);
    }
    (__EXCEPTION_EXIT_CALLBACK__)(exception->exception_number);
  }
  return NULL;
}

BOOL __exception_check_any() {
  return errno || errexc.exception_number;
}

void* __check_uncaught_exception__(exception_t* exception) {
  if (errchk) {
    __exit_on_exception__(exception, 0);
  }
  return NULL;
}

void* __exc_assert_fail__(exception_t* exception,
                          char* description,
                          const char* function_name,
                          const char* file_name,
                          unsigned int line,
                          void(*callback)()) {
  size_t sz = strlen(description);
  exception->context = 0;
  size_t fn_sz = strlen(function_name);
  for (size_t i = 0; i < fn_sz; ++i) {
    errctx.data[i] = function_name[i];
  }
  exception->exception_description = description;
  exception->exception_number = EASSERTEXC;
  errctx = (exception_context_t){.filename=file_name,
                                 .function_name=function_name,
                                 .line=line,
                                 .tracked_context_depth=__EXCEPTION_SCOPE_INDENTATION_VAR};
  exception->context = &errctx;
  errno = EASSERTEXC;
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) {
    const char* exc_str = exception_str(exception);
    static const char trm_str[] = "Terminating program with exit status " __EXCEPTION_CONSTEXPR_AS_STR(EASSERTEXC) ".\n";
    write(2, trm_str, sizeof(trm_str));
    write(2, exc_str, strlen(exc_str) + 1);
    free((char*)exc_str);
    (__EXCEPTION_EXIT_CALLBACK__)(exception->exception_number);
  }
  exception->status = 0;
  return NULL;
}

const char* exception_str(exception_t* exception) {
  const char exc_hdr_str[] = "Exception(0)! In \'(null)\' (null):0 (tracked scope depth 0):\n";
  const char exc_ctx_str[] = "\nThe following section is first " \
                             __EXCEPTION_CONSTEXPR_AS_STR(__DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__) \
                             " byte(s) of exception context:\n";
  char* description = exception->exception_description;
  exception_context_t* context = &(exception_context_t){};
  size_t context_size = 0;
  if (!description) {
    description = strerror(exception->exception_number);
  }
  if (exception->context) {
    context = exception->context;
    if (context->filename) {
      context_size += strlen(context->filename) + 1;
    }
    if (context->function_name) {
      context_size += strlen(context->function_name) + 1;
    }
    if (context->line) {
      context_size += (sizeof(int) * __CHAR_BIT__ * 2 / 5);
    }
    if (context->tracked_context_depth) {
      context_size += (sizeof(int) * __CHAR_BIT__ * 2 / 5);
    }
  }
  char* ctx = calloc(sizeof(exc_ctx_str) + \
                     sizeof(exc_hdr_str) + \
                     strlen(description) + \
                     context_size + \
                     (sizeof(int) * __CHAR_BIT__ * 2 / 5) + \
                     __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__ + \
                     32,
                     1);
  sprintf(ctx,
          "Exception(%d)! In \'%s\' %s:%d (tracked scope depth %d):\n%s",
          exception->exception_number,
          context->function_name,
          context->filename,
          context->line,
          context->tracked_context_depth,
          description);
  if (context && \
      context->data && \
      context->data[0]) {
    memcpy(ctx + strlen(ctx),
           exc_ctx_str,
           sizeof(exc_ctx_str));
    size_t offset = strlen(ctx);
    memcpy(ctx + offset,
           exception->context->data,
           __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__);
    memcpy(ctx + offset + __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__,
           "\n",
           2);
  }
  return ctx;
}

