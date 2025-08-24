#include "class.h"

DEF_CLASS(callable_t,, generic_function_t func_ptr;)

#define __AUX_FUNCTIONAL_ARG_MERGE__(ARG) ARG##_f

#define __AUX_FUNCTIONAL_ARG__(ARG) __AUX_FUNCTIONAL_ARG_MERGE__(ARG)

#undef FUNCTION
#define DEF_FUNC(RETURNS, FUNCTION_...) \
  RETURNS ARG1_VA_ARGS(FUNCTION_)(ARG1_VA_ARGS_VA(FUNCTION_, ...)); \
  extern callable_t __AUX_FUNCTIONAL_ARG__(ARG1_VA_ARGS(FUNCTION_)); \

#define FUNC(RETURNS, FUNCTION_...) \
  callable_t __AUX_FUNCTIONAL_ARG__(ARG1_VA_ARGS(FUNCTION_)) = \
    (callable_t){.__base__=(__BaseClass__){.__meta__=&__callable_t_Default_MetaData__}, \
      .func_ptr=(generic_function_t)ARG1_VA_ARGS(FUNCTION_)}; \
  RETURNS ARG1_VA_ARGS(FUNCTION_)(ARG1_VA_ARGS_VA(FUNCTION_, ...))

#if __STDC__!=1 || __STDC_VERSION < 201112L
#define CALL(ARGS...) ((__ClassInstance__*)&(ARG1_VA_ARGS(ARGS)))->__meta__->vcls->__call__(&(ARG1_VA_ARGS(ARGS)), ARG1_VA_ARGS_VA(ARGS, NULL));
#else
#define CALL(ARGS...) _Generic((ARG1_VA_ARGS(ARGS)), void*(*)(void*, ...): ARG1_VA_ARGS(ARGS)(ARG1_VA_ARGS_VA(ARGS)), default: ((__ClassInstance__*)&(ARG1_VA_ARGS(ARGS)))->__meta__->vcls->__call__(&(ARG1_VA_ARGS(ARGS)), ARG1_VA_ARGS_VA(ARGS, NULL)));
#endif