#include <errno.h>

#ifndef INVALID
#define INVALID ((void*)-1);
#endif // !INVALID


#define __DEFAULT_EXCEPTION_CONTEXT_SIZE__ 4096
#define __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__ 32


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


#ifndef BOOL
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;
#endif

#define EASSERTEXC 256

#define __EXCEPTION_EXIT_CALLBACK__ exit

extern BOOL _ERRORB;
extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);

#define CHECH_UNCAUGHT __check_uncaught_exception__(&_EXCEPTION);

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
  if (errno || CAUGHT_EXCEPTION.exception_number)

void* __raise_exception__(exception_t* exception);

#define RAISE(EXCEPTION) __raise_exception__(&(EXCEPTION));

#define THROW(EXCEPTION, RETURN_TYPE) void* __EXCEPTION_RESULT__ = RAISE(EXCEPTION); \
  return *((RETURN_TYPE*)&(__EXCEPTION_RESULT__));

void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...);

#define EXIT_ON(EXCEPTION...) __exit_on_exception__(EXCEPTION, 0);

#define CLEAR_EXCEPTION errno = 0; \
  _EXCEPTION = (exception_t){}; \
  _EXCEPTION_CONTEXT = (exception_context_t){}; \
  CAUGHT_EXCEPTION = (exception_t){}; \
  CAUGHT_EXCEPTION_CONTEXT = (exception_context_t){}; \
  _ERRORB = FALSE;

#define __EXCEPTION_EXPR_TO_STR(expr) #expr

#define __EXCEPTION_CONSTEXPR_AS_STR(expr) __EXCEPTION_EXPR_TO_STR(expr)

#define FINALLY errno = 0; \
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) { \
    __exit_on_exception__(&_EXCEPTION, 0); \
  } \
  for (int _EXCIZERO = 0; _EXCIZERO == 0; _EXCIZERO = 1)

void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, void(*callback)());

#define EXC_ASSERT_CALLBACK ((void*)0)

#define PUSH_EXCEPTION(RETURN_TYPE) if (_ERRORB) { THROW(CAUGHT_EXCEPTION, RETURN_TYPE); }

#define EXC_ASSERT(EXPR) ((EXPR) ? ((void*)0) : \
  __exc_assert_fail__(&_EXCEPTION, \
    "Assertion failed! '" #EXPR "' in file " __FILE__ ":" __EXCEPTION_CONSTEXPR_AS_STR(__LINE__), \
    __func__, \
    EXC_ASSERT_CALLBACK) \
  )
