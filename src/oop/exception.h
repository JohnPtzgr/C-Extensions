#include <errno.h>

#pragma once

#ifndef INVALID
#define INVALID ((void*)-1)
#endif // !INVALID


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

extern exception_context_t _EXCEPTION_CONTEXT;
extern unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR;

typedef int exception_status_t;

typedef struct exception_t
{
  unsigned int exception_number;
  exception_status_t status;
  exception_context_t* context;
  char* exception_description;
} exception_t;

extern exception_t _EXCEPTION;

extern exception_t CAUGHT_EXCEPTION;
extern exception_context_t CAUGHT_EXCEPTION_CONTEXT;


#define EASSERTEXC 256

#define __EXCEPTION_EXIT_CALLBACK__ exit


#ifndef BOOL
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;
#endif

extern BOOL _ERRORB;
extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);

#define CHECK_UNCAUGHT __check_uncaught_exception__(&_EXCEPTION);

#define TRY __EXCEPTION_SCOPE_INDENTATION_VAR++; \
  _ERRORB = FALSE; \
  errno = 0; \
  CAUGHT_EXCEPTION = (exception_t){}; \
  CAUGHT_EXCEPTION_CONTEXT = (exception_context_t){}; \
  do

#define BREAKPOINT if (errno || _EXCEPTION.exception_number) { _ERRORB = TRUE; break; }

#define CATCH while (0); \
  __EXCEPTION_SCOPE_INDENTATION_VAR--; \
  CAUGHT_EXCEPTION = _EXCEPTION; \
  CAUGHT_EXCEPTION_CONTEXT = _EXCEPTION_CONTEXT; \
  _EXCEPTION = (exception_t){}; \
  _EXCEPTION_CONTEXT = (exception_context_t){}; \
  _ERRORB = _ERRORB || errno || _EXCEPTION.exception_number; \
  if (!CAUGHT_EXCEPTION.exception_number) { \
    CAUGHT_EXCEPTION.exception_number = errno; \
  } \
  errno = 0; \
  if (_ERRORB)

void* __raise_exception__(exception_t* exception);

#define RAISE(EXCEPTION) __raise_exception__(&(EXCEPTION));

#define THROW(RETURN_TYPE, EXCEPTION) void* __EXCEPTION_RESULT__ = RAISE(EXCEPTION); \
  return *((RETURN_TYPE*)&(__EXCEPTION_RESULT__));

#define THROW_ON(RETURN_TYPE, EXCEPTION_NUMBER) \
  if (EXCEPTION_NUMBER == _EXCEPTION.exception_number) { \
    void* __EXCEPTION_RESULT__ = EXCEPTION_RETURNS; \
    return *((RETURN_TYPE*)&(__EXCEPTION_RESULT__)); \
  }

void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...);

#define EXIT_ON(EXCEPTION...) __exit_on_exception__(EXCEPTION, 0);

#define CLEAR_EXCEPTION errno = 0; \
  _EXCEPTION = (exception_t){}; \
  _EXCEPTION_CONTEXT = (exception_context_t){}; \
  CAUGHT_EXCEPTION = (exception_t){}; \
  CAUGHT_EXCEPTION_CONTEXT = (exception_context_t){}; \
  _ERRORB = FALSE; \
  errno = 0;

#define __EXCEPTION_EXPR_TO_STR(expr) #expr

#define __EXCEPTION_CONSTEXPR_AS_STR(expr) __EXCEPTION_EXPR_TO_STR(expr)

#define FINALLY errno = 0; \
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) { \
    __exit_on_exception__(&_EXCEPTION, 0); \
  } \
  for (int _EXCIZERO = 0; _EXCIZERO == 0; _EXCIZERO = 1)

void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, void(*callback)());

#define EXC_ASSERT_CALLBACK ((void*)0)

#define PUSH_EXCEPTION(RETURN_TYPE) \
  if (CAUGHT_EXCEPTION.exception_number) { \
      THROW(RETURN_TYPE, CAUGHT_EXCEPTION); \
  } else { \
    if (_ERRORB = (_EXCEPTION.exception_number || errno)) { \
      if (!_EXCEPTION.exception_number) { \
        _EXCEPTION.exception_number = errno; \
      } \
      THROW(RETURN_TYPE, _EXCEPTION); \
    } \
  }

#define EXC_ASSERT(EXPR...) ((EXPR) ? ((void*)0) : \
  __exc_assert_fail__(&_EXCEPTION, \
    "Assertion failed! '" #EXPR "' in file " __FILE__ ":" __EXCEPTION_CONSTEXPR_AS_STR(__LINE__), \
    __func__, \
    EXC_ASSERT_CALLBACK) \
  )

#define EXCTH_ASSERT(RETURN_TYPE, EXPR...) \
  EXC_ASSERT(EXPR); \
  THROW_ON(RETURN_TYPE, EASSERTEXC);

