#include <errno.h>
#include <stdint.h>
#include <stddef.h>

#pragma once
#ifndef INVALID
#define INVALID ((void*)-1)
#endif // !INVALID

#ifndef MIN
#define MIN(A, B) (A < B ? A : B)
#endif // !MAX


#ifndef MAX
#define MAX(A, B) (A > B ? A : B)
#endif // !MAX

#define __AUX_EXPAND_MACRO_VA_ARGS__(MACRO, ARGS...) \
  MACRO##(ARGS)

#define EXPAND_MACRO(MACRO, ARGS...) \
  __AUX_EXPAND_MACRO_VA_ARGS__(MACRO, ARGS)

#ifndef ARG1_VA_ARGS
#define __AUX_EXP_MACRO_ARG__(MACRO_TO_EXP, ARG) MACRO_TO_EXP(ARG)
#define ARG0_VA(ARG0...) ARG0
#define ARG1_VA_ARGS( ARG1, ... ) ARG1
#define ARG1_VA_ARGS_VA( ARG1, ... ) __VA_ARGS__
#define ARG2_VA_ARGS( ARG1, ARG2, ... ) ARG2
#define ARG2_VA_ARGS_VA( ARG1, ARG2, ... ) __VA_ARGS__
#define ARG3_VA_ARGS( ARG1, ARG2, ARG3, ... ) ARG3
#define ARG3_VA_ARGS_VA( ARG1, ARG2, ARG3, ... ) __VA_ARGS__
#define ARG4_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ... ) ARG4
#define ARG4_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ... ) __VA_ARGS__
#define ARG5_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ... ) ARG5
#define ARG5_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ... ) __VA_ARGS__
#define ARG6_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ... ) ARG6
#define ARG6_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ... ) __VA_ARGS__
#define ARG7_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ... ) ARG7
#define ARG7_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ... ) __VA_ARGS__
#define ARG8_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ... ) ARG8
#define ARG8_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ... ) __VA_ARGS__

#endif // CHOOSE __VA_ARGS__ ARGUMENT (Up to 8-th)

#ifndef TO_STR_LITERAL
#define TO_STR_LITERAL(ARG) #ARG
#endif // !TO_STR_LITERAL

#ifndef __glibc_unlikely
    #ifdef __GNUC__
        #define __glibc_unlikely(x) __builtin_expect(x, 0)
    #else
        #define __glibc_unlikely(x) (x)
    #endif
#endif // !__glibc_unlikely

typedef void*(*generic_function_t)(void*, ... );
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;
typedef BOOL*(*generic_predicate_t)(void*, ... );

#define MAX_THREAD_COUNT 256

#define EXCEPTION_RETURNS INVALID


#define __DEFAULT_EXCEPTION_CONTEXT_SIZE__ 256
#define __DEFAULT_EXCEPTION_CONTEXT_PREVIEW_SIZE__ 32

#define __EXCEPTION_STACK_FRAME_STATIC_SIZE__ 32


// The function never causes the program to terminate or exit early
#define _NoThrow

// The function never raises an exception
#define _NoExcept


void* __aux_thread_safe_static_val_get__(void* static_list, size_t type_size);


typedef struct exception_context_t {
  const char* filename;
  const char* function_name;
  unsigned int line;
  unsigned int tracked_context_depth;
  char data[__DEFAULT_EXCEPTION_CONTEXT_SIZE__];
} exception_context_t;

typedef struct exception_stack_frame_t {
  const char* filename;
  const char* function_name;
  const char* exception_data;
  uint16_t line;
  uint16_t tracked_context_depth;
  unsigned int exception_number;
} exception_stack_frame_t;

typedef struct exception_stack_t {
  exception_stack_frame_t static_frames[__EXCEPTION_STACK_FRAME_STATIC_SIZE__];
  exception_stack_frame_t* dynamic_frames;
  size_t dynamic_stack_size;
  size_t dynamic_stack_head_index;
  size_t static_stack_head_index;
} exception_stack_t;

typedef int exception_status_t;

typedef struct exception_t {
  unsigned int exception_number;
  exception_status_t status;
  exception_context_t* context;
  char* exception_description;
  struct exception_t* cause;
} exception_t;


#define EASSERTEXC 256

#define __EXCEPTION_EXIT_CALLBACK__ exit

extern exception_t caught_exception;

extern void* __aux_mt_thread_ids_ptr__;
extern void* __aux_default_thread_0_init_ptr__;

exception_t* __errexc_location();
exception_stack_t* __errstack_location();
exception_t* __errexc_location();
exception_context_t* __errctx_location();
size_t* __exception_scope_indent_location();
// inline BOOL __exception_check_any();
const char* exception_str(exception_t* exception);

#define errexc (*__errexc_location())

#define errctx (*__errctx_location())

#define errchk __exception_check_any()

#define __EXCEPTION_SCOPE_INDENTATION_VAR (*__exception_scope_indent_location())

#define __exception_check_any() ( errno || errexc.exception_number )

extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);

#define CHECK_UNCAUGHT __check_uncaught_exception__(&errexc);

#define TRY __EXCEPTION_SCOPE_INDENTATION_VAR++; \
  errno = 0; \
  do

#define BREAKPOINT if (errno || errexc.exception_number) { break; }

#define CATCH(EXC...) while (0); \
  __EXCEPTION_SCOPE_INDENTATION_VAR--; \
  exception_t caught_exception; \
  BOOL exception_was_caught = FALSE; \
  BOOL __aux_err_bool = FALSE; \
  if (__glibc_unlikely(errchk)) { \
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
  } \
  for (size_t _EXCIZERO = __aux_err_bool; _EXCIZERO != 0; _EXCIZERO = 0)

void* __raise_exception__(exception_t* exception, exception_t* cause);

#define RAISE(EXCEPTION...) __raise_exception__(&ARG1_VA_ARGS(EXCEPTION), ARG2_VA_ARGS(EXCEPTION, NULL));

#define THROW(RETURN_TYPE...) void* __EXCEPTION_RESULT__ = RAISE(ARG2_VA_ARGS(RETURN_TYPE, caught_exception), \
    ARG3_VA_ARGS(RETURN_TYPE, &caught_exception, NULL)); \
  return *((ARG1_VA_ARGS(RETURN_TYPE)*)&(__EXCEPTION_RESULT__));

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

#define FINALLY \
  for (int _EXCIZERO = 0; _EXCIZERO == 0; _EXCIZERO = 1)

void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, const char* file_name, unsigned int line, void(*callback)());

#define EXC_ASSERT_CALLBACK ((void*)0)

#define PUSH_EXCEPTION(RETURN_TYPE) \
  if (errexc.exception_number || errno) { \
    if (!errexc.exception_number) { \
      errexc.exception_number = errno; \
    } \
    THROW(RETURN_TYPE, errexc); \
  } else if (caught_exception.exception_number) { \
      THROW(RETURN_TYPE, caught_exception); \
  }

#define EXC_ASSERT(EXPR...) ((EXPR) ? ((void*)0) : \
  __exc_assert_fail__(&errexc, \
    "Assertion failed! '" #EXPR "' in file " __FILE__ ":" __EXCEPTION_CONSTEXPR_AS_STR(__LINE__), \
    __func__, \
    __FILE__, \
    __LINE__, \
    EXC_ASSERT_CALLBACK) \
  )

#define EXCEPTION_CTX_LTR ((exception_context_t){ \
  .filename=__FILE__, \
  .function_name=__func__, \
  .line=__LINE__, \
  .tracked_context_depth=__EXCEPTION_SCOPE_INDENTATION_VAR})

#define EXCTH_ASSERT(RETURN_TYPE, EXPR...) \
  EXC_ASSERT(EXPR); \
  THROW_ON(RETURN_TYPE, EASSERTEXC);

