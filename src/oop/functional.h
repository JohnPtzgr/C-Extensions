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

#define CALL(ARGS...) ((__ClassInstance__*)&(ARG1_VA_ARGS(ARGS)))->__meta__->vcls->__call__(&(ARG1_VA_ARGS(ARGS)), ARG1_VA_ARGS_VA(ARGS, NULL));