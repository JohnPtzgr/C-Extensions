#include "../memory/dyn_alloc.h"
#pragma once

#ifndef __GET_CLASS_MASK_IS_DYNAMIC
BOOL __GET_CLASS_MASK_IS_DYNAMIC(size_t* mask) {
  return (BOOL)((*mask & 1) && 1);
}

BOOL __GET_CLASS_MASK_IS_HYBRID(size_t* mask) {
  return (BOOL)((*mask & 2) && 1);
}

BOOL __GET_CLASS_MASK_INHERITS(size_t* mask) {
  return (BOOL)((*mask & 4) && 1);
}

BOOL __GET_CLASS_MASK_IS_ABSTRACT(size_t* mask) {
  return (BOOL)((*mask & 8) && 1);
}

BOOL __GET_CLASS_MASK_IS_CONST(size_t* mask) {
  return (BOOL)((*mask & 16) && 1);
}

BOOL __GET_CLASS_MASK_WAS_INIT(size_t* mask) {
  return (BOOL)((*mask & 32) && 1);
}

BOOL __GET_CLASS_MASK_IS_INNER(size_t* mask) {
  return (BOOL)((*mask & 64) && 1);
}

BOOL __GET_CLASS_MASK_IS_SUPER(size_t* mask) {
  return (BOOL)((*mask & 128) && 1);
}

BOOL __GET_CLASS_MASK_IS_TEMPLATE(size_t* mask) {
  return (BOOL)((*mask & 256) && 1);
}

BOOL __GET_CLASS_MASK_IS_BARE(size_t* mask) {
  return (BOOL)((*mask & 512) && 1);
}

unsigned int __GET_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  return (*mask) >> (__CHAR_BIT__ * sizeof(int));
}

void __SET_CLASS_MASK_DYNAMIC(size_t* mask, BOOL new_type) {
  *mask |= 1;
  *mask ^= !new_type;
}

BOOL __SET_CLASS_MASK_HYBRID(size_t* mask, BOOL new_type) {
  *mask |= 2;
  *mask ^= !new_type;
}

BOOL __SET_CLASS_MASK_INHERITS(size_t* mask, BOOL new_type) {
  *mask |= 4;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_ABSTRACT(size_t* mask, BOOL new_type) {
  *mask |= 8;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_CONST(size_t* mask, BOOL new_type) {
  *mask |= 16;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_WAS_INIT(size_t* mask, BOOL new_type) {
  *mask |= 32;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_INNER(size_t* mask, BOOL new_type) {
  *mask |= 64;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_SUPER(size_t* mask, BOOL new_type) {
  *mask |= 128;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_TEMPLATE(size_t* mask, BOOL new_type) {
  *mask |= 256;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_BARE(size_t* mask, BOOL new_type) {
  *mask |= 512;
  *mask ^= !new_type;
}

void __ADD_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  unsigned int cnt = (*mask) >> (__CHAR_BIT__ * sizeof(int));
  if (cnt + 1 != 0) {
    cnt++;
  }
  *mask &= (1ull << (__CHAR_BIT__ * sizeof(int))) - 1;
  *mask += ((size_t)cnt) << (__CHAR_BIT__ * sizeof(int));
}

void __SUB_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  unsigned int cnt = (*mask) >> (__CHAR_BIT__ * sizeof(int));
  if (cnt != 0) {
    cnt--;
  }
  *mask &= (1ull << (__CHAR_BIT__ * sizeof(int))) - 1;
  *mask += ((size_t)cnt) << (__CHAR_BIT__ * sizeof(int));
}

#endif // CLASS MASK RELATED DEFINITIONS


#ifndef __BUILT_IN_METHOD_TABLE__
#define __BUILT_IN_METHOD_TABLE_SIZE__ 32
static method_function_t __default_method__;
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
};
static char* __BUILT_IN_METHOD_TABLE__[__BUILT_IN_METHOD_TABLE_SIZE__] = {
  "INIT",
  "DESTROY",
  "TO_STR",
  "DATA",
  "ITER",
  "NEXT",
  "CALL",
  "GETITEM",
  "LEN",
  "NEG",
  "ADD",
  "IADD",
  "SUB",
  "ISUB",
  "MUL",
  "IMUL",
  "DIV",
  "IDIV",
  "MOD",
  "IMOD",
  "AND",
  "IAND",
  "OR",
  "IOR",
  "XOR",
  "IXOR",
  "NOT",
  "INOT",
  "CONTAINS",
  "CMP",
  "SET",
  "GET"
};

#endif // BUILT-IN METHOD TABLE DEFINITION


#ifndef CLASS

#define __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, FIELD_DEFINITIONS, DYNAMIC_METHOD_COUNT, STATIC_METHOD_COUNT, MASK, ...  ) \
typedef struct CLASS_NAME { \
  FIELD_DEFINITIONS; \
  method_function_t __meta[DYNAMIC_METHOD_COUNT]; \
} CLASS_NAME; \
void* CLASS_NAME##_init(CLASS_NAME*, ...); \
void* CLASS_NAME##_destroy(CLASS_NAME*); \
size_t __##CLASS_NAME##_MASK = (MASK) | \
  (66 * (STATIC_METHOD_COUNT == 0)) | \
  (578 * (STATIC_METHOD_COUNT + 1 == 0)); \
method_function_t __meta_##CLASS_NAME[2 + ((STATIC_METHOD_COUNT + 1 == 0) ? 0, STATIC_METHOD_COUNT)] = \
  {(method_function_t) CLASS_NAME##_init, (method_function_t) CLASS_NAME##_destroy, __VA_ARGS__}; \
size_t __##CLASS_NAME##_BUILT_IN_METHOD_CURRENT_INDEX__ = (STATIC_METHOD_COUNT + 1 == 0) ? 0 : 3; \
size_t __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[(STATIC_METHOD_COUNT + 1 == 0) ? \
  2 : __BUILT_IN_METHOD_TABLE_SIZE__] = {1, 2, 0, 0, 0, 0, 0, 0, \
                                         0, 0, 0, 0, 0, 0, 0, 0, \
                                         0, 0, 0, 0, 0, 0, 0, 0, \
                                         0, 0, 0, 0, 0, 0, 0, 0};

#define CLASS( CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT, ...  ) \
  __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT, METHOD_COUNT, 3, __VA_ARGS__ )

#define STATIC_CLASS( CLASS_NAME, FIELD_DEFINITIONS, METHOD_COUNT, ... ) \
  __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, FIELD_DEFINITIONS, 0, METHOD_COUNT, 0, __VA_ARGS__ )

#define CLASS_END( CLASS_NAME, ... ) void* CLASS_NAME##_init(CLASS_NAME* self, ...) { \
  __VA_ARGS__; \
  __SET_CLASS_MASK_WAS_INIT(&__##CLASS_NAME##_MASK, TRUE); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=self, \
                     .function=__meta_##CLASS_NAME[1]}); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=&__##CLASS_NAME##_MASK, \
                     .function=(method_function_t)__SUB_CLASS_MASK_COUNT_INSTANCES}); \
  return self; \
} \
  void* CLASS_NAME##_destroy(CLASS_NAME* self)

#define MAKE_STATIC( CLASS_NAME ) __SET_CLASS_MASK_DYNAMIC(&__##CLASS_NAME##_MASK, FALSE);

#define MAKE_DYNAMIC( CLASS_NAME ) __SET_CLASS_MASK_DYNAMIC(&__##CLASS_NAME##_MASK, TRUE);

#define MAKE_CONST( CLASS_NAME ) __SET_CLASS_MASK_CONST(&__##CLASS_NAME##_MASK, TRUE);

#define REMOVE_CONST( CLASS_NAME ) __SET_CLASS_MASK_CONST(&__##CLASS_NAME##_MASK, FALSE);

#define MAKE_ABSTRACT( CLASS_NAME ) __SET_CLASS_MASK_ABSTRACT(&__##CLASS_NAME##_MASK, TRUE);

#define MAKE_TEMPLATE( CLASS_NAME ) __SET_CLASS_MASK_TEMPLATE(&__##CLASS_NAME##_MASK, TRUE);

#define MAKE_INNER( CLASS_NAME ) __SET_CLASS_MASK_INNER(&__##CLASS_NAME##_MASK, TRUE);

#define __IS_EMPTY(...) ( sizeof( (char[]){#__VA_ARGS__} ) == 1 )

#define INIT( CLASS_NAME, OBJ, ... ) CLASS_NAME OBJ __VA_ARGS__; \
  if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) { \
    for (size_t i = 0; i < sizeof((OBJ).__meta) / sizeof(method_function_t); ++i) { \
      (OBJ).__meta[i] = __meta_##CLASS_NAME[2 + i]; \
    } \
  } \
  if ( (!__GET_CLASS_MASK_IS_ABSTRACT(&__##CLASS_NAME##_MASK)) \
    && (__GET_CLASS_MASK_IS_TEMPLATE(&__##CLASS_NAME##_MASK) <= \
    (__GET_CLASS_MASK_IS_SUPER(&__##CLASS_NAME##_MASK) && \
    (!__IS_EMPTY(__VA_ARGS__)))) ) {\
    __meta_##CLASS_NAME[0](&(OBJ)); \
    __ADD_CLASS_MASK_COUNT_INSTANCES(&__##CLASS_NAME##_MASK); \
  }

#define INIT_WITH( CLASS_NAME, OBJ, ... ) CLASS_NAME OBJ; \
  if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) { \
    for (size_t i = 0; i < sizeof((OBJ).__meta) / sizeof(method_function_t); ++i) { \
      (OBJ).__meta[i] = __meta_##CLASS_NAME[2 + i]; \
    } \
  } \
  if ( (!__GET_CLASS_MASK_IS_ABSTRACT(&__##CLASS_NAME##_MASK)) \
    && (__GET_CLASS_MASK_IS_TEMPLATE(&__##CLASS_NAME##_MASK) <= \
    __GET_CLASS_MASK_IS_SUPER(&__##CLASS_NAME##_MASK)) ) {\
    __meta_##CLASS_NAME[0](&(OBJ), __VA_ARGS__); \
    __ADD_CLASS_MASK_COUNT_INSTANCES(&__##CLASS_NAME##_MASK); \
  }

#define INIT_CLASS( CLASS_NAME, ... ) \
  if (__GET_CLASS_MASK_WAS_INIT(&__##CLASS_NAME##_MASK) == 0) { __VA_ARGS__; };

#define METHOD( CLASS_NAME, METHOD_ID, ... ) { \
  method_function_t __METHOD_PTR = 0; \
  void* __METHOD_RESULT = 0; \
  size_t __METHOD_INDEX__ = 1 + METHOD_ID - __BUILT_IN_METHOD_TABLE_SIZE__; \
  if (METHOD_ID < __BUILT_IN_METHOD_TABLE_SIZE__) { \
    __METHOD_INDEX__ = __##CLASS_NAME##_BUILT_IN_METHOD_TABLE__[METHOD_ID]; \
    if (__METHOD_INDEX__ == 0) { \
      printf("Error! Method '%s' is undefined.\n", __BUILT_IN_METHOD_TABLE__[METHOD_ID]); \
      __default_method__(__VA_ARGS__); \
    } \
  } \
  if (__METHOD_INDEX__ < 3) { \
    __METHOD_PTR = (__meta_##CLASS_NAME[__METHOD_INDEX__ - 1]); \
  } else { \
    if (__GET_CLASS_MASK_IS_INNER(&__##CLASS_NAME##_MASK)) { \
      __METHOD_PTR = *((method_function_t*)(ARG1_VA_ARGS(__VA_ARGS__)) + (__METHOD_INDEX__ - 3)); \
    } else { \
      if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) { \
        __METHOD_PTR = (((CLASS_NAME*)(ARG1_VA_ARGS(__VA_ARGS__)))->__meta[__METHOD_INDEX__ - 3]); \
      } else { \
        __METHOD_PTR = (__meta_##CLASS_NAME[__METHOD_INDEX__ - 1]); \
      }; \
    }; \
  } \
  if (__METHOD_PTR != 0) { \
    __METHOD_RESULT = (__METHOD_PTR)(__VA_ARGS__); \
  }; \
  __METHOD_RESULT; \
}

#define SET_METHOD( CLASS_NAME, METHOD_ID, OBJ, FUNCTION) { \
  size_t __METHOD_INDEX__ = 1 + METHOD_ID - __BUILT_IN_METHOD_TABLE_SIZE__; \
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
          __meta_##CLASS_NAME[__METHOD_INDEX__ - 1] = (method_function_t)FUNCTION; \
        }; \
      }; \
    }; \
  }; \
}

#define HAS_INSTANCE( CLASS_NAME ) (__GET_CLASS_MASK_COUNT_INSTANCES(&__##CLASS_NAME##_MASK) > 0)

#define COUNT_INSTANCES( CLASS_NAME ) __GET_CLASS_MASK_COUNT_INSTANCES(&__##CLASS_NAME##_MASK)

#define CLASS_META( CLASS_NAME ) __meta_##CLASS_NAME

#define INHERIT( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT, ... ) \
  __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, BASE_CLASS __base; FIELD_DEFINITIONS, METHOD_COUNT, METHOD_COUNT, 7, __VA_ARGS__ )

#define STATIC_INHERIT( CLASS_NAME, BASE_CLASS, FIELD_DEFINITIONS, METHOD_COUNT, ... ) \
  __GENERIC_CLASS_DEFINITION_MACRO__( CLASS_NAME, BASE_CLASS __base; FIELD_DEFINITIONS, 0, METHOD_COUNT, 4, __VA_ARGS__ )

#define INHERIT_END( CLASS_NAME, BASE_CLASS, ... ) void* CLASS_NAME##_init(CLASS_NAME* self, ...) { \
  __SET_CLASS_MASK_SUPER(&__##BASE_CLASS##_MASK, TRUE); \
  __meta_##BASE_CLASS[0](&(self->__base)); \
  for (size_t i = 2; i < MIN(sizeof(__meta_##CLASS_NAME) / sizeof(method_function_t), \
        sizeof(__meta_##BASE_CLASS) / sizeof(method_function_t)); ++i) { \
    __meta_##CLASS_NAME[i] = __meta_##BASE_CLASS[i]; \
  } \
  if (__GET_CLASS_MASK_IS_DYNAMIC(&__##CLASS_NAME##_MASK)) { \
    if (__GET_CLASS_MASK_IS_DYNAMIC(&__##BASE_CLASS##_MASK)) { \
      for (size_t i = 2; i < MIN(sizeof(__meta_##CLASS_NAME) / sizeof(method_function_t), \
           sizeof(__meta_##BASE_CLASS) / sizeof(method_function_t)); ++i) { \
        self->__meta[i - 2] = self->__base.__meta[i - 2]; \
      } \
    } else { \
      for (size_t i = 2; i < MIN(sizeof(__meta_##CLASS_NAME) / sizeof(method_function_t), \
           sizeof(__meta_##BASE_CLASS) / sizeof(method_function_t)); ++i) { \
        self->__meta[i - 2] = __meta_##BASE_CLASS[i]; \
      } \
    } \
  } else { \
    if (__GET_CLASS_MASK_IS_DYNAMIC(&__##BASE_CLASS##_MASK)) { \
      for (size_t i = 2; i < MIN(sizeof(__meta_##CLASS_NAME) / sizeof(method_function_t), \
           sizeof(__meta_##BASE_CLASS) / sizeof(method_function_t)); ++i) { \
        __meta_##CLASS_NAME[i] = self->__base.__meta[i]; \
      } \
    } \
  } \
  __VA_ARGS__; \
  __SET_CLASS_MASK_WAS_INIT(&__##CLASS_NAME##_MASK, TRUE); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=self, .function=__meta_##CLASS_NAME[1]}); \
  __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){.obj_instance=&__##CLASS_NAME##_MASK, \
                     .function=(method_function_t)__SUB_CLASS_MASK_COUNT_INSTANCES}); \
  return self; \
} \
  void* CLASS_NAME##_destroy(CLASS_NAME* self)

#define INHERIT_ADD(BASE_CLASS, BASE_OBJ) \
  __meta_##BASE_CLASS[0](BASE_OBJ);

#define DEFAULT_DESTROY { return self; }

#endif // CLASS RELATED DEFINITIONS
