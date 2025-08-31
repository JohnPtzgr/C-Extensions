#include "../../src/oop/exception.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

exception_t _EXCEPTION = (exception_t){};

exception_context_t _EXCEPTION_CONTEXT = (exception_context_t){};

exception_t CAUGHT_EXCEPTION = (exception_t){};

exception_context_t CAUGHT_EXCEPTION_CONTEXT = (exception_context_t){};

unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR = 0;

BOOL _ERRORB = FALSE;

void* __raise_exception__(exception_t* exception) {
  _EXCEPTION = *exception;
  if (_EXCEPTION.context) {
    _EXCEPTION_CONTEXT = *(exception->context);
  }
  _ERRORB = TRUE;
  errno = exception->exception_number;
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) {
    __exit_on_exception__(&_EXCEPTION, 0);
  }
  return INVALID;
}

void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...) {
  if (exception->exception_number == _EXCEPTION.exception_number && _EXCEPTION.exception_number) {
    if (clean_up) {
      clean_up();
    }
    perror(_EXCEPTION.exception_description);
    const static unsigned int buffer_size = 128;
    char buffer[buffer_size];
    if (!_EXCEPTION.context) {
      _EXCEPTION.context = &_EXCEPTION_CONTEXT;
    }
    sprintf(buffer, "Terminating program with exit status %d.\n", exception->exception_number);
    write(2, buffer, strlen(buffer) + 1);
    if (_EXCEPTION.context->data[0]) {
      const char exc_ctx_str[] = "The following section is first " \
                                 __EXCEPTION_CONSTEXPR_AS_STR(__DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__) \
                                 " byte(s) of exception context:\n";
      write(2, exc_ctx_str, sizeof(exc_ctx_str));
      write(2, _EXCEPTION.context->data, __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__);
    }
    (__EXCEPTION_EXIT_CALLBACK__)(exception->exception_number);
  }
  return NULL;
}

void* __check_uncaught_exception__(exception_t* exception) {
  if (errno || _EXCEPTION.exception_number) {
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
    _EXCEPTION_CONTEXT.data[i] = function_name[i];
  }
  exception->exception_description = description;
  exception->exception_number = EASSERTEXC;
  errno = EASSERTEXC;
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) {
    __exit_on_exception__(&_EXCEPTION, 0);
  }
  exception->status = 0;
  return NULL;
}

