#ifndef CLASSES_H
#define CLASSES_H

#include "../memory/dyn_alloc.h"
#include "stdarg.h"
#pragma once

#ifndef __GET_CLASS_MASK_IS_DYNAMIC
BOOL __GET_CLASS_MASK_IS_DYNAMIC(size_t* mask);

BOOL __GET_CLASS_MASK_IS_HYBRID(size_t* mask);

BOOL __GET_CLASS_MASK_INHERITS(size_t* mask);

BOOL __GET_CLASS_MASK_IS_ABSTRACT(size_t* mask);

BOOL __GET_CLASS_MASK_IS_CONST(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_INIT(size_t* mask);

BOOL __GET_CLASS_MASK_IS_INNER(size_t* mask);

BOOL __GET_CLASS_MASK_IS_SUPER(size_t* mask);

BOOL __GET_CLASS_MASK_IS_TEMPLATE(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BARE(size_t* mask);

unsigned int __GET_CLASS_MASK_COUNT_INSTANCES(size_t* mask);

void __SET_CLASS_MASK_DYNAMIC(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_HYBRID(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_INHERITS(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_ABSTRACT(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_CONST(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_INIT(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_INNER(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_SUPER(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_TEMPLATE(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BARE(size_t* mask, BOOL new_type);

size_t __ADD_CLASS_MASK_COUNT_INSTANCES(size_t* mask);

size_t __SUB_CLASS_MASK_COUNT_INSTANCES(size_t* mask);

#endif // CLASS MASK RELATED DEFINITIONS


// #ifndef __SUPPRESS_UNUSED_VARIABLE__
// #define __SUPPRESS_UNUSED_VARIABLE__( VAR ) {(void*)(&(VAR));}
// #endif // !__SUPPRESS_UNUSED_VARIABLE__


#ifndef __BUILT_IN_METHOD_TABLE__

#ifndef __BUILT_IN_METHOD_TABLE_SIZE__
#define __BUILT_IN_METHOD_TABLE_SIZE__ 58
#endif // !__BUILT_IN_METHOD_TABLE_SIZE__

static method_function_t __default_method__;
// __SUPPRESS_UNUSED_VARIABLE__(__default_method__);
enum {
  __m_init__ = 0,
  __m_destroy__ = 1,
  __m_to_str__ = 2,
  __m_data__ = 3,
  __m_iter__ = 4,
  __m_next__ = 5,
  __m_call__ = 6,
  __m_getitem__ = 7,
  __m_len__ = 8,
  __m_neg__ = 9,
  __m_add__ = 10,
  __m_iadd__ = 11,
  __m_sub__ = 12,
  __m_isub__ = 13,
  __m_mul__ = 14,
  __m_imul__ = 15,
  __m_div__ = 16,
  __m_idiv__ = 17,
  __m_mod__ = 18,
  __m_imod__ = 19,
  __m_and__ = 20,
  __m_iand__ = 21,
  __m_or__ = 22,
  __m_ior__ = 23,
  __m_xor__ = 24,
  __m_ixor__ = 25,
  __m_not__ = 26,
  __m_inot__ = 27,
  __m_contains__ = 28,
  __m_cmp__ = 29,
  __m_set__ = 30,
  __m_get__ = 31,
  __m_copy__ = 32,
  __m_assign__ = 33,
  __m_new__ = 34,
  __m_lt__ = 35,
  __m_gt__ = 36,
  __m_eq__ = 37,
  __m_le__ = 38,
  __m_ge__ = 39,
  __m_neq__ = 40,
  __m_pow__ = 41,
  __m_cast__ = 42,
  __m_bitand__ = 43,
  __m_bitiand__ = 44,
  __m_bitor__ = 45,
  __m_bitior__ = 46,
  __m_bitxor__ = 47,
  __m_bitixor__ = 48,
  __m_bitnot__ = 49,
  __m_bitinot__ = 50,
  __m_inc__ = 51,
  __m_dec__ = 52,
  __m_lsh__ = 53,
  __m_ilsh__ = 54,
  __m_rsh__ = 55,
  __m_irsh__ = 56,
  __m_ineg__ = 57,
};
extern char* __BUILT_IN_METHOD_TABLE__[__BUILT_IN_METHOD_TABLE_SIZE__];
#define __DEFAULT_BUILT_IN_METHOD_TABLE__ { \
  1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
}
// __SUPPRESS_UNUSED_VARIABLE__(__BUILT_IN_METHOD_TABLE__)

#endif // BUILT-IN METHOD TABLE DEFINITION


#ifndef CLASS

#define __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, FIELD_DEFINITIONS, DYNAMIC_METHOD_COUNT, STATIC_METHOD_COUNT) \
typedef struct CLASS_NAME { \
  FIELD_DEFINITIONS; \
  method_function_t __meta[DYNAMIC_METHOD_COUNT]; \
} CLASS_NAME; \
void* CLASS_NAME##_init(CLASS_NAME*, ...); \
void* CLASS_NAME##_destroy(CLASS_NAME*); \
extern size_t __##CLASS_NAME##_MASK; \
extern method_function_t __##CLASS_NAME##_META[2 + ((STATIC_METHOD_COUNT + 1 == 0) ? 0 : STATIC_METHOD_COUNT)]; \
extern size_t __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__; \
extern size_t __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[(STATIC_METHOD_COUNT + 1 == 0) ? \
  2 : __BUILT_IN_METHOD_TABLE_SIZE__];


#define __AUX_CLASS__( CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT) \
  __GENERIC_CLASS_DEFINITION_MACRO__(CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT, METHOD_COUNT)

#define CLASS( CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT) \
  __AUX_CLASS__(CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT)


#define __AUX_STATIC_CLASS__( CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT) \
  __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, FIELD_DEFINITIONS, 0, METHOD_COUNT)

#define STATIC_CLASS( CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT) \
  __AUX_STATIC_CLASS__(CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT)

#define __AUX_BRIDGE_CLASS__( CLASS_NAME, METHOD_COUNT) \
  void* CLASS_NAME##_init(CLASS_NAME*, ...); \
  void* CLASS_NAME##_destroy(CLASS_NAME*); \
  extern size_t __##CLASS_NAME##_MASK; \
  extern method_function_t __##CLASS_NAME##_META[2 + ((METHOD_COUNT + 1 == 0) ? 0 : METHOD_COUNT)]; \
  extern size_t __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__; \
  extern size_t __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[(METHOD_COUNT + 1 == 0) ? \
    2 : __BUILT_IN_METHOD_TABLE_SIZE__];

#define BRIDGE_CLASS( CLASS_NAME, METHOD_COUNT) \
__AUX_BRIDGE_CLASS__(CLASS_NAME, METHOD_COUNT)



#define __GENERIC_CLASS_END_MACRO__( CLASS_NAME, METHOD_COUNT, MASK, ... ) \
size_t __##CLASS_NAME##_MASK = MASK; \
method_function_t __##CLASS_NAME##_META[2 + ((METHOD_COUNT + 1 == 0) ? 0 : METHOD_COUNT)] = \
  {(method_function_t) CLASS_NAME##_init, (method_function_t) CLASS_NAME##_destroy}; \
size_t __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__ = (METHOD_COUNT + 1 == 0) ? 0 : 3; \
size_t __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[(METHOD_COUNT + 1 == 0) ? \
  2 : __BUILT_IN_METHOD_TABLE_SIZE__] = __DEFAULT_BUILT_IN_METHOD_TABLE__; \
void* CLASS_NAME##_init(CLASS_NAME* self, ...) { \
  if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) { \
    for (size_t i = 0; i < METHOD_COUNT; ++i) { \
      self->__meta[i] = __##CLASS_NAME##_META[2 + i]; \
    } \
  } \
  const size_t __METHOD_CNT__ = METHOD_COUNT; \
  __VA_ARGS__; \
  __SET_CLASS_MASK_WAS_INIT(&__##CLASS_NAME##_MASK, TRUE); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=self, \
                     .function=__##CLASS_NAME##_META[1]}); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=&__##CLASS_NAME##_MASK, \
                     .function=(method_function_t)__SUB_CLASS_MASK_COUNT_INSTANCES}); \
  return self; \
} \
void* CLASS_NAME##_destroy(CLASS_NAME* self)

#define __AUX_CLASS_END__( CLASS_NAME, METHOD_COUNT, MASK, ... ) \
  __GENERIC_CLASS_END_MACRO__(CLASS_NAME, METHOD_COUNT, \
  (MASK) | (66 * (METHOD_COUNT == 0)) | (578 * (METHOD_COUNT + 1 == 0)), __VA_ARGS__)

#define CLASS_END( CLASS_NAME, METHOD_COUNT, ... ) \
  __AUX_CLASS_END__(CLASS_NAME, METHOD_COUNT, 3, __VA_ARGS__)

#define STATIC_CLASS_END( CLASS_NAME, METHOD_COUNT, ... ) \
  __AUX_CLASS_END__(CLASS_NAME, METHOD_COUNT, 0, __VA_ARGS__)


#define __AUX_CLASS_MASK__( CLASS_NAME ) __##CLASS_NAME##_MASK

#define MAKE_STATIC( CLASS_NAME ) __SET_CLASS_MASK_DYNAMIC(&__AUX_CLASS_MASK__(CLASS_NAME), FALSE)

#define MAKE_DYNAMIC( CLASS_NAME ) __SET_CLASS_MASK_DYNAMIC(&__AUX_CLASS_MASK__(CLASS_NAME), TRUE)

#define MAKE_CONST( CLASS_NAME ) __SET_CLASS_MASK_CONST(&__AUX_CLASS_MASK__(CLASS_NAME), TRUE)

#define REMOVE_CONST( CLASS_NAME ) __SET_CLASS_MASK_CONST(&__AUX_CLASS_MASK__(CLASS_NAME), FALSE)

#define MAKE_ABSTRACT( CLASS_NAME ) __SET_CLASS_MASK_ABSTRACT(&__AUX_CLASS_MASK__(CLASS_NAME), TRUE)

#define MAKE_TEMPLATE( CLASS_NAME ) __SET_CLASS_MASK_TEMPLATE(&__AUX_CLASS_MASK__(CLASS_NAME), TRUE)

#define MAKE_INNER( CLASS_NAME ) __SET_CLASS_MASK_INNER(&__AUX_CLASS_MASK__(CLASS_NAME), TRUE)

#define __IS_EMPTY(...) ( sizeof( (char[]){#__VA_ARGS__} ) == 1 )


#define __AUX_INIT__( CLASS_NAME, ... ) ((CLASS_NAME*)( \
  ( \
    (!__GET_CLASS_MASK_IS_ABSTRACT(&__##CLASS_NAME##_MASK)) && \
    (!__GET_CLASS_MASK_IS_TEMPLATE(&__##CLASS_NAME##_MASK)) \
  ) ? ( \
    __CALL_FUNCTION__((generic_function_t)__ADD_CLASS_MASK_COUNT_INSTANCES, \
      &__##CLASS_NAME##_MASK) + \
    __##CLASS_NAME##_META[0](__VA_ARGS__) \
  ) : ( \
    0 \
  ) \
))

#define INIT( CLASS_NAME, OBJ... ) \
  __AUX_INIT__(CLASS_NAME, OBJ, NULL)


#define __AUX_ON_INIT_CLASS__( CLASS_NAME, ... ) \
  if (__GET_CLASS_MASK_WAS_INIT(&__##CLASS_NAME##_MASK) == 0) { __VA_ARGS__; }

#define ON_INIT_CLASS( CLASS_NAME, EXPR... ) \
  __AUX_ON_INIT_CLASS__(CLASS_NAME, EXPR)


#define __AUX_DESTROY__( CLASS_NAME, OBJ ) \
  ((CLASS_NAME*)(__##CLASS_NAME##_META[1](&(OBJ))))


#define DESTROY( CLASS_NAME, OBJ ) \
  __AUX_DESTROY__(CLASS_NAME, OBJ)


// #define __AUX_METHOD__( CLASS_NAME, METHOD_ID, ... ) { \
//   method_function_t __METHOD_PTR = 0; \
//   void* __METHOD_RESULT = 0; \
//   size_t __METHOD_INDEX__ = 1 + (METHOD_ID) - __BUILT_IN_METHOD_TABLE_SIZE__; \
//   if (METHOD_ID < __BUILT_IN_METHOD_TABLE_SIZE__) { \
//     __METHOD_INDEX__ = __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[METHOD_ID]; \
//     if (__METHOD_INDEX__ == 0) { \
//       printf("Error! Method '%s' is undefined.\n", __BUILT_IN_METHOD_TABLE__[METHOD_ID]); \
//       __default_method__(__VA_ARGS__); \
//     } \
//   } \
//   if (__METHOD_INDEX__ < 3) { \
//     __METHOD_PTR = (__##CLASS_NAME##_META[__METHOD_INDEX__ - 1]); \
//   } else { \
//     if (__GET_CLASS_MASK_IS_INNER(&__##CLASS_NAME##_MASK)) { \
//       __METHOD_PTR = *((method_function_t*)(ARG1_VA_ARGS(__VA_ARGS__)) + (__METHOD_INDEX__ - 3)); \
//     } else { \
//       if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) { \
//         __METHOD_PTR = (((CLASS_NAME*)(ARG1_VA_ARGS(__VA_ARGS__)))->__meta[__METHOD_INDEX__ - 3]); \
//       } else { \
//         __METHOD_PTR = (__##CLASS_NAME##_META[__METHOD_INDEX__ - 1]); \
//       }; \
//     }; \
//   } \
//   if (__METHOD_PTR != 0) { \
//     __METHOD_RESULT = (__METHOD_PTR)(__VA_ARGS__, 0); \
//   }; \
//   __METHOD_RESULT; \
// }

#define __AUX_METHOD_INDEX__(CLASS_NAME, METHOD_ID, ... ) ( \
  ( \
    1 + (METHOD_ID) - __BUILT_IN_METHOD_TABLE_SIZE__ < __BUILT_IN_METHOD_TABLE_SIZE__ \
  ) ? ( \
    (__##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[METHOD_ID]) ? ( \
      __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[METHOD_ID] \
    ) : ( \
      0 * printf("Error! Method '%s' is undefined.\n", __BUILT_IN_METHOD_TABLE__[METHOD_ID]) - 1 \
    ) \
  ) : ( \
    1 + (METHOD_ID) - __BUILT_IN_METHOD_TABLE_SIZE__ \
  ) \
)

#define __AUX_METHOD_PTR__(CLASS_NAME, __METHOD_INDEX__, ... ) ((generic_function_t)( \
  (__METHOD_INDEX__ < 3) ? ( \
    __##CLASS_NAME##_META[__METHOD_INDEX__ - 1] \
  ) : ( \
    ( \
      __GET_CLASS_MASK_IS_INNER(&__##CLASS_NAME##_MASK) \
    ) ? ( \
      *((method_function_t*)(ARG1_VA_ARGS(__VA_ARGS__)) + (__METHOD_INDEX__ - 3)) \
    ) : ( \
      (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) ? ( \
        ((CLASS_NAME*)(ARG1_VA_ARGS(__VA_ARGS__)))->__meta[__METHOD_INDEX__ - 3] \
      ) : ( \
        __##CLASS_NAME##_META[__METHOD_INDEX__ - 1] \
      ) \
    ) \
  ) \
))

#define __AUX_METHOD__( CLASS_NAME, METHOD_ID, ... ) ((void*)( \
  (__AUX_METHOD_PTR__(CLASS_NAME, \
    __AUX_METHOD_INDEX__(CLASS_NAME, METHOD_ID, __VA_ARGS__), \
    __VA_ARGS__))(__VA_ARGS__) \
))

#define METHOD( CLASS_NAME, METHOD_ID, OBJ... ) \
  __AUX_METHOD__(CLASS_NAME, METHOD_ID, OBJ, NULL)


#define __AUX_SET_METHOD__( CLASS_NAME, METHOD_ID, OBJ, FUNCTION) { \
  size_t __METHOD_INDEX__ = 1 + (METHOD_ID) - __BUILT_IN_METHOD_TABLE_SIZE__; \
  if (METHOD_ID < __BUILT_IN_METHOD_TABLE_SIZE__ && METHOD_ID > 0) { \
    __METHOD_INDEX__ = __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[METHOD_ID]; \
    if (__METHOD_INDEX__ == 0) { \
      __METHOD_INDEX__ = __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__; \
      __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[METHOD_ID] = \
                  __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__++; \
    } \
  } \
  if ((unsigned int)(METHOD_ID + __UINT8_MAX__) < (unsigned int)(METHOD_ID)) { \
    __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__ -= METHOD_ID; \
  } else { \
    if (!__GET_CLASS_MASK_IS_CONST(&__##CLASS_NAME##_MASK)) { \
      if (__GET_CLASS_MASK_IS_INNER(&__##CLASS_NAME##_MASK)) { \
        *((method_function_t*)(OBJ) + (__METHOD_INDEX__ - 3)) = \
          (method_function_t)FUNCTION; \
      } else { \
        if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK) && (__METHOD_INDEX__ >= 3)) { \
          ((CLASS_NAME*)(OBJ))->__meta[__METHOD_INDEX__ - 3] = (method_function_t)FUNCTION; \
        } else { \
          __##CLASS_NAME##_META[__METHOD_INDEX__ - 1] = (method_function_t)FUNCTION; \
        }; \
      }; \
    }; \
  }; \
}

#define SET_METHOD( CLASS_NAME, METHOD_ID, OBJ, FUNCTION) \
  __AUX_SET_METHOD__(CLASS_NAME, METHOD_ID, OBJ, FUNCTION)


#define METHOD_ARGS( ARGS_COUNT, ... ) \
  va_list __RAW_METHOD_ARGS__; \
  void* __ARG_LIST__[ARGS_COUNT] = {__VA_ARGS__}; \
  size_t __ARG_CNT__ = 0; \
  { \
    va_start(__RAW_METHOD_ARGS__, self); \
    for (size_t i = 0; (i < ARGS_COUNT) && (__ARG_LIST__[i] = va_arg(__RAW_METHOD_ARGS__, void*)); ++i) { __ARG_CNT__++; }; \
    va_end(__RAW_METHOD_ARGS__); \
  }


#define __AUX_HAS_INSTANCE__( CLASS_NAME ) (__GET_CLASS_MASK_COUNT_INSTANCES(&__##CLASS_NAME##_MASK) > 0)

#define HAS_INSTANCE( CLASS_NAME ) \
  __AUX_HAS_INSTANCE__(CLASS_NAME)


#define __AUX_COUNT_INSTANCES__( CLASS_NAME ) __GET_CLASS_MASK_COUNT_INSTANCES(&__##CLASS_NAME##_MASK)

#define COUNT_INSTANCES( CLASS_NAME ) \
  __AUX_COUNT_INSTANCES__(CLASS_NAME)


#define __AUX_CLASS_META__( CLASS_NAME ) __##CLASS_NAME##_META

#define CLASS_META( CLASS_NAME ) \
  __AUX_CLASS_META__(CLASS_NAME)


#define __AUX_CLASS_MASK__( CLASS_NAME ) __##CLASS_NAME##_MASK

#define CLASS_MASK( CLASS_NAME ) \
  __AUX_CLASS_MASK__(CLASS_NAME)


#define __AUX_INHERIT__( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT ) \
  __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, BASE_CLASS __base; FIELD_DEFINITIONS, \
    METHOD_COUNT, METHOD_COUNT)

#define INHERIT( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT ) \
  __AUX_INHERIT__( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT)


#define __AUX_STATIC_INHERIT__( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT ) \
  __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, BASE_CLASS __base; FIELD_DEFINITIONS, 0, METHOD_COUNT)

#define STATIC_INHERIT( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT ) \
  __AUX_STATIC_INHERIT__( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT)


#define __GENERIC_INHERIT_END_MACRO__( CLASS_NAME, BASE_CLASS, METHOD_COUNT, MASK, ... ) \
size_t __##CLASS_NAME##_MASK = MASK; \
method_function_t __##CLASS_NAME##_META[2 + ((METHOD_COUNT + 1 == 0) ? 0 : METHOD_COUNT)] = \
  {(method_function_t) CLASS_NAME##_init, (method_function_t) CLASS_NAME##_destroy}; \
size_t __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__ = (METHOD_COUNT + 1 == 0) ? 0 : 3; \
size_t __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[(METHOD_COUNT + 1 == 0) ? \
  2 : __BUILT_IN_METHOD_TABLE_SIZE__] = __DEFAULT_BUILT_IN_METHOD_TABLE__; \
void* CLASS_NAME##_init(CLASS_NAME* self, ...) { \
  const size_t __METHOD_CNT__ = METHOD_COUNT; \
  __SET_CLASS_MASK_SUPER(&__##BASE_CLASS##_MASK, TRUE); \
  __##BASE_CLASS##_META[0](&(self->__base), NULL); \
  for (size_t i = 2; i < MIN(sizeof(__##CLASS_NAME##_META) / sizeof(method_function_t), \
        sizeof(__##BASE_CLASS##_META) / sizeof(method_function_t)); ++i) { \
          __##CLASS_NAME##_META[i] = __##BASE_CLASS##_META[i]; \
  } \
  if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) { \
    if (__GET_CLASS_MASK_IS_DYNAMIC(&__##BASE_CLASS##_MASK)) { \
      for (size_t i = 2; i < MIN(sizeof(__##CLASS_NAME##_META) / sizeof(method_function_t), \
           sizeof(__##BASE_CLASS##_META) / sizeof(method_function_t)); ++i) { \
        self->__meta[i - 2] = self->__base.__meta[i - 2]; \
      } \
    } else { \
      for (size_t i = 2; i < MIN(sizeof(__##CLASS_NAME##_META) / sizeof(method_function_t), \
           sizeof(__##BASE_CLASS##_META) / sizeof(method_function_t)); ++i) { \
        self->__meta[i - 2] = __##BASE_CLASS##_META[i]; \
      } \
    } \
  } else { \
    if (__GET_CLASS_MASK_IS_DYNAMIC(&__##BASE_CLASS##_MASK)) { \
      for (size_t i = 2; i < MIN(sizeof(__##CLASS_NAME##_META) / sizeof(method_function_t), \
           sizeof(__##BASE_CLASS##_META) / sizeof(method_function_t)); ++i) { \
        __##CLASS_NAME##_META[i] = self->__base.__meta[i]; \
      } \
    } \
  } \
  __VA_ARGS__; \
  __SET_CLASS_MASK_WAS_INIT(&__##CLASS_NAME##_MASK, TRUE); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=self, \
                     .function=__##CLASS_NAME##_META[1]}); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=&__##CLASS_NAME##_MASK, \
                     .function=(method_function_t)__SUB_CLASS_MASK_COUNT_INSTANCES}); \
  return self; \
} \
void* CLASS_NAME##_destroy(CLASS_NAME* self)


#define __AUX_INHERIT_END__( CLASS_NAME, BASE_CLASS, METHOD_COUNT, ... ) \
  __GENERIC_INHERIT_END_MACRO__(CLASS_NAME, BASE_CLASS, METHOD_COUNT, 7, __VA_ARGS__)

#define INHERIT_END( CLASS_NAME, BASE_CLASS, METHOD_COUNT, ... ) \
  __AUX_INHERIT_END__(CLASS_NAME, BASE_CLASS, METHOD_COUNT, __VA_ARGS__)


#define __AUX_STATIC_INHERIT_END__( CLASS_NAME, BASE_CLASS, METHOD_COUNT, ... ) \
  __GENERIC_INHERIT_END_MACRO__(CLASS_NAME, BASE_CLASS, METHOD_COUNT, 4, __VA_ARGS__)

#define STATIC_INHERIT_END( CLASS_NAME, BASE_CLASS, METHOD_COUNT, ... ) \
  __AUX_INHERIT_END__(CLASS_NAME, BASE_CLASS, METHOD_COUNT, __VA_ARGS__)
  

#define __AUX_INHERIT_ADD__(BASE_CLASS, BASE_OBJ...) \
  __##BASE_CLASS##_META[0](BASE_OBJ);

#define INHERIT_ADD(BASE_CLASS, BASE_OBJ) \
  __AUX_INHERIT_ADD__(BASE_CLASS, BASE_OBJ, NULL);


#define DEFAULT_DESTROY { return self; }


CLASS(DefaultObject, void* data, 0)


#endif // CLASS RELATED DEFINITIONS

#endif
