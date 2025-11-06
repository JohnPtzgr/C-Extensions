#include <errno.h>
#include <stddef.h>

#pragma once

#ifndef INVALID
#define INVALID ((void*)-1)
#endif // !INVALID

#define MAX_THREAD_COUNT 256

#define EXCEPTION_RETURNS INVALID


#define __DEFAULT_EXCEPTION_CONTEXT_SIZE__ 4096
#define __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__ 32


// The function never causes the program to terminate or exit early
#define _NoThrow

// The function never raises an exception
#define _NoExcept


typedef struct exception_context_t
{
  char data[__DEFAULT_EXCEPTION_CONTEXT_SIZE__];
} exception_context_t;

typedef int exception_status_t;

typedef struct exception_t
{
  unsigned int exception_number;
  exception_status_t status;
  exception_context_t* context;
  char* exception_description;
} exception_t;


#define EASSERTEXC 256

#define __EXCEPTION_EXIT_CALLBACK__ exit

extern exception_t caught_exception;

extern void* __aux_mt_thread_ids_ptr__;
extern void* __aux_default_thread_0_init_ptr__;

#ifndef BOOL
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;
#endif

exception_t* __errexc_location();
exception_context_t* __errctx_location();
size_t* __exception_scope_indent_location();

#define errexc (*__errexc_location())

#define errctx (*__errctx_location())

#define __EXCEPTION_SCOPE_INDENTATION_VAR (*__exception_scope_indent_location())

#define __AUX_KL(X, Y...) (X, Y)

#define KL(X...) __AUX_KL(int, X)


extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);

#define CHECK_UNCAUGHT __check_uncaught_exception__(&errexc);

#define TRY __EXCEPTION_SCOPE_INDENTATION_VAR++; \
  errno = 0; \
  do

#define BREAKPOINT if (errno || errexc.exception_number) { break; }

#define CATCH(EXC...) while (0); \
  __EXCEPTION_SCOPE_INDENTATION_VAR--; \
  exception_t caught_exception = errexc; \
  exception_context_t __CAUGHT_EXCEPTION_CONTEXT = errctx; \
  if (!caught_exception.context || caught_exception.context == &errctx) { \
    caught_exception.context = &__CAUGHT_EXCEPTION_CONTEXT; \
  } \
  if (!caught_exception.exception_number) { \
    caught_exception.exception_number = errno; \
  } \
  BOOL __aux_err_bool = (caught_exception.exception_number > 0) && \
    (EXC.exception_number == caught_exception.exception_number); \
  errexc = (exception_t){}; \
  errctx = (exception_context_t){}; \
  errno = 0; \
  BOOL exception_was_caught = __aux_err_bool; \
  if (__aux_err_bool)

void* __raise_exception__(exception_t* exception);

#define RAISE(EXCEPTION...) __raise_exception__(&(EXCEPTION));

#define THROW(RETURN_TYPE, EXCEPTION...) void* __EXCEPTION_RESULT__ = RAISE(EXCEPTION); \
  return *((RETURN_TYPE*)&(__EXCEPTION_RESULT__));

#define THROW_ON(RETURN_TYPE, EXCEPTION_NUMBER...) \
  if (EXCEPTION_NUMBER == errexc.exception_number) { \
    void* __EXCEPTION_RESULT__ = EXCEPTION_RETURNS; \
    return *((RETURN_TYPE*)&(__EXCEPTION_RESULT__)); \
  }

void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...);

#define EXIT_ON(EXCEPTION...) __exit_on_exception__(EXCEPTION, 0);

#define CLEAR_EXCEPTION errno = 0; \
  errexc = (exception_t){}; \
  errctx = (exception_context_t){};

#define __EXCEPTION_EXPR_TO_STR(expr) #expr

#define __EXCEPTION_CONSTEXPR_AS_STR(expr) __EXCEPTION_EXPR_TO_STR(expr)

#define FINALLY errno = 0; \
  for (int _EXCIZERO = 0; _EXCIZERO == 0; _EXCIZERO = 1)

void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, void(*callback)());

#define EXC_ASSERT_CALLBACK ((void*)0)

#define PUSH_EXCEPTION(RETURN_TYPE) \
  if (caught_exception.exception_number) { \
      THROW(RETURN_TYPE, caught_exception); \
  } else { \
    if (errexc.exception_number || errno) { \
      if (!errexc.exception_number) { \
        errexc.exception_number = errno; \
      } \
      THROW(RETURN_TYPE, errexc); \
    } \
  }

#define EXC_ASSERT(EXPR...) ((EXPR) ? ((void*)0) : \
  __exc_assert_fail__(&errexc, \
    "Assertion failed! '" #EXPR "' in file " __FILE__ ":" __EXCEPTION_CONSTEXPR_AS_STR(__LINE__), \
    __func__, \
    EXC_ASSERT_CALLBACK) \
  )

#define EXCTH_ASSERT(RETURN_TYPE, EXPR...) \
  EXC_ASSERT(EXPR); \
  THROW_ON(RETURN_TYPE, EASSERTEXC);

