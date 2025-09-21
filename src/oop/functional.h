#include "class.h"

#pragma once

#undef FUNCTION


DEF_CLASS(callable_t, generic_function_t func_ptr)

#define __AUX_FUNCTIONAL_ARG_MERGE__(ARG) ARG##_f

#define __AUX_FUNCTIONAL_ARG__(ARG) __AUX_FUNCTIONAL_ARG_MERGE__(ARG)

#define __AUX_DEF_FUNC__(RETURNS, FUNCTION_NAME...) \
  RETURNS ARG1_VA_ARGS(FUNCTION_NAME)(ARG1_VA_ARGS_VA(FUNCTION_NAME, ...)); \
  extern callable_t __AUX_FUNCTIONAL_ARG__(ARG1_VA_ARGS(FUNCTION_NAME));

#define __AUX_FUNC_END__(RETURNS, FUNCTION_NAME...) \
  callable_t __AUX_FUNCTIONAL_ARG__(ARG1_VA_ARGS(FUNCTION_NAME)) = \
    (callable_t){.__meta__=&__callable_t_Default_MetaData__, \
                 .func_ptr=(generic_function_t)ARG1_VA_ARGS(FUNCTION_NAME)}; \
  RETURNS ARG1_VA_ARGS(FUNCTION_NAME)(ARG1_VA_ARGS_VA(FUNCTION_NAME, ...))


typedef struct lambda_capture_t lambda_capture_t;


DEF_CLASS(lambda_t, generic_function_t func_ptr; lambda_capture_t* capture)

#define __AUX_LAMBDA_FUNC_NAME__(NAME) NAME##_aux_lambda_function__

#define __AUX_LAMBDA_CAPTURE_NAME__(NAME) NAME##_aux_capture_struct__

#define __AUX_LAMBDA_FUNC__(CAPTURE, RETURNS, NAME, ARGS...) \
  typedef struct __AUX_LAMBDA_CAPTURE_NAME__(NAME) { \
    CAPTURE; \
  } __AUX_LAMBDA_CAPTURE_NAME__(NAME); \
  RETURNS __AUX_LAMBDA_FUNC_NAME__(NAME)(__AUX_LAMBDA_CAPTURE_NAME__(NAME)* ctx, \
    ARG1_VA_ARGS_VA(ARGS, ...)); \
  callable_t NAME = \
    (callable_t){.__meta__=&__callable_t_Default_MetaData__, \
                 .func_ptr=(generic_function_t)__AUX_LAMBDA_FUNC_NAME__(NAME)}; \
  RETURNS __AUX_LAMBDA_FUNC_NAME__(NAME)(__AUX_LAMBDA_CAPTURE_NAME__(NAME)* ctx, \
    ARG1_VA_ARGS_VA(ARGS, ...))

#define DEF_FUNC(RETURNS, FUNCTION_NAME...) \
  __AUX_DEF_FUNC__(RETURNS, FUNCTION_NAME)

#define FUNC(RETURNS, FUNCTION_NAME...) \
  __AUX_FUNC_END__(RETURNS, FUNCTION_NAME)

#define LAMBDA(CAPTURE, RETURNS, NAME...) \
  __AUX_LAMBDA_FUNC__(CAPTURE, RETURNS, ARG1_VA_ARGS(NAME), NAME)

#define LAMBDA_CALL(CALLABLE, CAPTURE...) (((__ClassInstance__*)&(CALLABLE))->__meta__->vcls->__call__(&(CALLABLE), &((__AUX_LAMBDA_CAPTURE_NAME__(CALLABLE))ARG1_VA_ARGS(CAPTURE)), ARG1_VA_ARGS_VA(CAPTURE, NULL)))

#define LAMBDA_LOAD(CALLABLE, CAPTURE) (callable_t*)CLS(lambda_t, (CALLABLE).func_ptr, &((__AUX_LAMBDA_CAPTURE_NAME__(CALLABLE))ARG1_VA_ARGS(CAPTURE)))

#define __F_VA_ARG__( LAST_ARG, ARGS_COUNT, DEFAULT_ARGS... ) \
  va_list __RAW_METHOD_ARGS__; \
  void* __ARG_LIST__[ARGS_COUNT] = {DEFAULT_ARGS}; \
  size_t __ARG_CNT__ = 0; \
  do { \
    va_start(__RAW_METHOD_ARGS__, LAST_ARG); \
    for (size_t i = 0; \
      (i < ARGS_COUNT) && \
      (__ARG_LIST__[i] = va_arg(__RAW_METHOD_ARGS__, void*)); \
      ++i) { \
        __ARG_CNT__++; \
      }; \
    va_end(__RAW_METHOD_ARGS__); \
  } while (0);

#if __STDC__ != 1 || __STDC_VERSION < 201112L
#define CALL(ARGS...) ((__ClassInstance__*)ARG1_VA_ARGS(ARGS))->__meta__->vcls->__call__(ARG1_VA_ARGS(ARGS), ARG1_VA_ARGS_VA(ARGS, NULL));
#else
#define CALL(ARGS...) _Generic((ARG1_VA_ARGS(ARGS)), void*(*)(void*, ...): ARG1_VA_ARGS(ARGS)(ARG1_VA_ARGS_VA(ARGS)), default: ((__ClassInstance__*)&(ARG1_VA_ARGS(ARGS)))->__meta__->vcls->__call__(&(ARG1_VA_ARGS(ARGS)), ARG1_VA_ARGS_VA(ARGS, NULL)));
#endif