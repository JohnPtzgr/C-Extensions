#include "../memory/dyn_alloc.h"

#pragma once

#define __DEFAULT_VTABLE_SIZE__ 8
#define __DEFAULT_VTABLE_MLT_OFFSET__ 8
#define __VTABLE_SIZE_IS_POWER_OF_2__ TRUE

#define __DEFAULT_INHERITANCE_LIST_CAPACITY__ 8

#define __VCLASS_METHOD_COUNT__ 62

typedef struct __vTableHash__
{
  size_t hashX;
  size_t hashY;
} __vTableHash__;

typedef struct __vTableNode__
{
  void* data;
  size_t data_mask;
  size_t data_shift;
  size_t mask;
  __vTableHash__ hash;
} __vTableNode__;

typedef size_t (*__vTable_byte_hasher_t__)(const char* key, size_t k_hash);

typedef struct __vTable__
{
  __vTable_byte_hasher_t__ hasher;
  __vTableNode__* data;
  size_t size;
} __vTable__;

__vTableHash__ __class_vtable_hash__(const char* key);

typedef struct __ClassObject__ __ClassObject__;

typedef struct __vClassObject__ __vClassObject__;

typedef struct __ClassMetaData__ __ClassMetaData__;

typedef struct __BaseClass__
{
  __ClassMetaData__* __meta__;
} __BaseClass__;

typedef struct __ClassInstance__
{
  __ClassMetaData__* __meta__;
} __ClassInstance__;

typedef struct __InheritanceListNode__
{
  __ClassObject__* class;
  size_t adress_shift;
} __InheritanceListNode__;

typedef struct __InheritanceList__
{
  __InheritanceListNode__* list;
  size_t capacity;
  size_t size;
} __InheritanceList__;

void* __vTable_add__(__vTable__* table, __vTableHash__ hash, __vTableNode__ value);
void* __vTable_remove__(__vTable__* table, __vTableHash__ hash);
__vTableNode__* __vTable_get__(__vTable__* table, __vTableHash__ hash);
BOOL __vTable_check__(__vTable__* table, __vTableHash__ hash);
void* __vTable_join__(__vTable__* table, __vTable__* source);


typedef struct __ClassObject__
{

  size_t size;
  const char* name;

  __vTable__* static_vtable;
  
  size_t mask;

  size_t instance_count;
  __InheritanceList__* inherits_from;

  __vClassObject__* default_vcls;
  __vClassObject__* vcls;

  __ClassInstance__* default_instance;

  generic_function_t __static_init__;
  generic_function_t __static_destroy__;

} __ClassObject__;

typedef struct __vClassObject__
{
  unsigned int method_shift[__VCLASS_METHOD_COUNT__];
  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __to_str__;
  generic_function_t __data__;
  generic_function_t __iter__;
  generic_function_t __next__;
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __len__;
  generic_function_t __neg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __contains__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __cmp__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __pow__;
  generic_function_t __cast__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;
  generic_function_t __ineg__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __id__;

  __ClassObject__* cls;
  
  __vTable__* vtable;

} __vClassObject__;

typedef struct __ClassMetaData__ {
  __vClassObject__* vcls;
  __vTable__* vtable;
} __ClassMetaData__;


void* __class_init__(__vClassObject__* default_vclass);
void* __class_destroy__(__ClassObject__* class);
void* __class_init_instance__(__ClassInstance__* instance,
  __vClassObject__* default_vclass);
void* __class_destroy_instance__(__ClassInstance__* instance,
  generic_function_t destructor);
void __class_inherit_static__(__ClassObject__* class);
void __class_inherit__(__ClassObject__* class);
void __class_inherit_instance__(__ClassInstance__* instance);

typedef enum __m_enum__ {
  __m_init__,
  __m_destroy__,
  __m_to_str__,
  __m_data__,
  __m_iter__,
  __m_next__,
  __m_call__,
  __m_getitem__,
  __m_len__,
  __m_neg__,
  __m_add__,
  __m_iadd__,
  __m_sub__,
  __m_isub__,
  __m_mul__,
  __m_imul__,
  __m_div__,
  __m_idiv__,
  __m_mod__,
  __m_imod__,
  __m_and__,
  __m_iand__,
  __m_or__,
  __m_ior__,
  __m_xor__,
  __m_ixor__,
  __m_not__,
  __m_inot__,
  __m_contains__,
  __m_set__,
  __m_get__,
  __m_copy__,
  __m_assign__,
  __m_new__,
  __m_delete__,
  __m_cmp__,
  __m_lt__,
  __m_gt__,
  __m_eq__,
  __m_le__,
  __m_ge__,
  __m_neq__,
  __m_pow__,
  __m_cast__,
  __m_bitand__,
  __m_bitiand__,
  __m_bitor__,
  __m_bitior__,
  __m_bitxor__,
  __m_bitixor__,
  __m_bitnot__,
  __m_bitinot__,
  __m_inc__,
  __m_dec__,
  __m_lsh__,
  __m_ilsh__,
  __m_rsh__,
  __m_irsh__,
  __m_ineg__,
  __m_listen__,
  __m_shout__,
  __m_id__
} __m_enum__;

extern const char* __VCLASS_METHOD_UC_NAMES__[__VCLASS_METHOD_COUNT__];

typedef struct __PRIVATE__
{
  void* data;
} __PRIVATE__;

void* __InheritanceList_add__(__InheritanceList__* list, void* self,
  void* instance, __ClassObject__* class);
void* __InheritanceList_remove__(__InheritanceList__* list, __ClassInstance__* instance);
size_t __InheritanceList_find__(__InheritanceList__* list, __vTableHash__ hash);
size_t __InheritanceList_find_built_in__(__InheritanceList__* list, __m_enum__ built_in_no);
void* __InheritanceList_init__(__InheritanceList__* list);
void* __InheritanceList_destroy__(__InheritanceList__* list);

#ifndef __GET_CLASS_MASK_IS_DYNAMIC
BOOL __GET_CLASS_MASK_IS_STATIC__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_HYBRID__(size_t* mask);

BOOL __GET_CLASS_MASK_INHERITS__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_ABSTRACT__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_CONST__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_INNER__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_SUPER__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_TEMPLATE__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BARE__(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_INIT__(size_t* mask);

void __SET_CLASS_MASK_STATIC__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_HYBRID__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_INHERITS__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_ABSTRACT__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_CONST__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_INNER__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_SUPER__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_TEMPLATE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BARE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_INIT__(size_t* mask, BOOL new_type);

#define STATIC 1
#define HYBRID 2
#define INHERITS 4
#define ABSTRACT 8
#define CONST 16
#define INNER 32
#define SUPER 64
#define TEMPLATE 128
#define BARE 256

#endif // CLASS MASK RELATED DEFINITIONS

#define __ON_INIT__(NAME, EXPR...) \
    if (!__GET_CLASS_MASK_WAS_INIT__(&(__##NAME##_ClassObject__.mask))) { \
      EXPR; \
    }

#define __CLASS_MASK__(NAME) __##NAME##_ClassObject__.mask

#define __GENERIC_CLASS_DECLARE_MACRO__(NAME, \
    BASE, \
    STATIC_CLASS_FIELDS, \
    CLASS_FIELDS) \
  \
  typedef struct __##NAME##_vClassObject__ \
  { \
    unsigned int method_shift[__VCLASS_METHOD_COUNT__]; \
    generic_function_t __init__; \
    generic_function_t __destroy__; \
    generic_function_t __to_str__; \
    generic_function_t __data__; \
    generic_function_t __iter__; \
    generic_function_t __next__; \
    generic_function_t __call__; \
    generic_function_t __getitem__; \
    generic_function_t __len__; \
    generic_function_t __neg__; \
    generic_function_t __add__; \
    generic_function_t __iadd__; \
    generic_function_t __sub__; \
    generic_function_t __isub__; \
    generic_function_t __mul__; \
    generic_function_t __imul__; \
    generic_function_t __div__; \
    generic_function_t __idiv__; \
    generic_function_t __mod__; \
    generic_function_t __imod__; \
    generic_function_t __and__; \
    generic_function_t __iand__; \
    generic_function_t __or__; \
    generic_function_t __ior__; \
    generic_function_t __xor__; \
    generic_function_t __ixor__; \
    generic_function_t __not__; \
    generic_function_t __inot__; \
    generic_function_t __contains__; \
    generic_function_t __set__; \
    generic_function_t __get__; \
    generic_function_t __copy__; \
    generic_function_t __assign__; \
    generic_function_t __new__; \
    generic_function_t __delete__; \
    generic_function_t __cmp__; \
    generic_function_t __lt__; \
    generic_function_t __gt__; \
    generic_function_t __eq__; \
    generic_function_t __le__; \
    generic_function_t __ge__; \
    generic_function_t __neq__; \
    generic_function_t __pow__; \
    generic_function_t __cast__; \
    generic_function_t __bitand__; \
    generic_function_t __bitiand__; \
    generic_function_t __bitor__; \
    generic_function_t __bitior__; \
    generic_function_t __bitxor__; \
    generic_function_t __bitixor__; \
    generic_function_t __bitnot__; \
    generic_function_t __bitinot__; \
    generic_function_t __inc__; \
    generic_function_t __dec__; \
    generic_function_t __lsh__; \
    generic_function_t __ilsh__; \
    generic_function_t __rsh__; \
    generic_function_t __irsh__; \
    generic_function_t __ineg__; \
    generic_function_t __listen__; \
    generic_function_t __shout__; \
    generic_function_t __id__; \
    __ClassObject__* cls; \
    __vTable__* vtable; \
    STATIC_CLASS_FIELDS; \
  } __##NAME##_vClassObject__; \
  typedef struct NAME \
  { \
    BASE; \
    CLASS_FIELDS; \
  } NAME; \
  void* __##NAME##_static_init__(NAME* self); \
  void* __##NAME##_static_destroy__(NAME* self); \
  void* NAME##_init(NAME* self , ...); \
  void* NAME##_destroy(NAME* self, ...); \
  extern __ClassObject__ __##NAME##_ClassObject__; \
  extern __##NAME##_vClassObject__ __##NAME##_Default_vClassObject__; \
  extern NAME __##NAME##_Default_Instance__; \
  extern __ClassMetaData__ __##NAME##_Default_MetaData__;


#define __GENERIC_CLASS_DEFINE_MACRO__(NAME, MASK, EXPR...) \
  __ClassObject__ __##NAME##_ClassObject__ = \
    (__ClassObject__){.mask=MASK, \
                      .size=sizeof(NAME), \
                      .default_vcls=(__vClassObject__*)&__##NAME##_Default_vClassObject__, \
                      .default_instance=(__ClassInstance__*)&__##NAME##_Default_Instance__, \
                      .name=#NAME, \
                      .__static_init__=(generic_function_t)__##NAME##_static_init__, \
                      .__static_destroy__=(generic_function_t)__##NAME##_static_destroy__}; \
  __##NAME##_vClassObject__ __##NAME##_Default_vClassObject__ = \
    (__##NAME##_vClassObject__){.__init__=(generic_function_t)NAME##_init, \
                                .__destroy__=(generic_function_t)NAME##_destroy, \
                                .cls=&__##NAME##_ClassObject__}; \
  NAME __##NAME##_Default_Instance__ = (NAME){}; \
  __ClassMetaData__ __##NAME##_Default_MetaData__ = \
    (__ClassMetaData__){.vcls=(__vClassObject__*)&__##NAME##_Default_vClassObject__}; \
  void* __##NAME##_static_init__(NAME* self) { \
    __ON_INIT__(NAME, \
      *self = (NAME){}; \
      SCOPE_PUSH(&__##NAME##_ClassObject__, __class_destroy__); \
      SCOPE_DEFER(&__##NAME##_ClassObject__, __class_destroy__, __DEFAULT_PREDICATE__); \
    ); \
    if (!__GET_CLASS_MASK_IS_BARE__(&(__##NAME##_ClassObject__.mask))) { \
      ((__ClassInstance__*)self)->__meta__ = &__##NAME##_Default_MetaData__; \
    } \
    if (self != &__##NAME##_Default_Instance__) { \
      SCOPE_PUSH(self, __##NAME##_static_destroy__); \
    } \
    EXPR; \
    return self; \
  } \
  void* __##NAME##_static_destroy__(NAME* self)
  
#define __GENERIC_INHERENT_CLASS_DEFINE_MACRO__(NAME, BASE, MASK, EXPR...) \
  __ClassObject__ __##NAME##_ClassObject__ = \
    (__ClassObject__){.mask=MASK|INHERITS, \
                      .size=sizeof(NAME), \
                      .default_vcls=(__vClassObject__*)&__##NAME##_Default_vClassObject__, \
                      .default_instance=(__ClassInstance__*)&__##NAME##_Default_Instance__, \
                      .name=#NAME, \
                      .__static_init__=(generic_function_t)__##NAME##_static_init__, \
                      .__static_destroy__=(generic_function_t)__##NAME##_static_destroy__}; \
  __##NAME##_vClassObject__ __##NAME##_Default_vClassObject__ = \
    (__##NAME##_vClassObject__){.__init__=(generic_function_t)NAME##_init, \
                                .__destroy__=(generic_function_t)NAME##_destroy, \
                                .cls=&__##NAME##_ClassObject__}; \
  NAME __##NAME##_Default_Instance__ = (NAME){}; \
  __ClassMetaData__ __##NAME##_Default_MetaData__ = \
    (__ClassMetaData__){.vcls=(__vClassObject__*)&__##NAME##_Default_vClassObject__}; \
  void* __##NAME##_static_init__(NAME* self) { \
    __##BASE##_static_init__((BASE*)self); \
    __ON_INIT__(NAME, \
      *self = (NAME){}; \
      if (!__##NAME##_ClassObject__.inherits_from) { \
        __##NAME##_ClassObject__.inherits_from = (__InheritanceList__*)malloc(sizeof(__InheritanceList__)); \
        __InheritanceList_init__(__##NAME##_ClassObject__.inherits_from); \
        __InheritanceList_add__(__##NAME##_ClassObject__.inherits_from, \
                                (void*)self, \
                                (void*)self, \
                                &__##BASE##_ClassObject__); \
      } \
      SCOPE_PUSH(&__##NAME##_ClassObject__, __class_destroy__); \
      SCOPE_DEFER(&__##NAME##_ClassObject__, __class_destroy__, __DEFAULT_PREDICATE__); \
    ); \
    if (!__GET_CLASS_MASK_IS_BARE__(&(__##NAME##_ClassObject__.mask))) { \
      ((__ClassInstance__*)self)->__meta__ = &__##NAME##_Default_MetaData__; \
    } \
    if (self != &__##NAME##_Default_Instance__) { \
      SCOPE_PUSH(self, __##NAME##_static_destroy__); \
    } \
    EXPR; \
    __ON_INIT__(NAME, \
      if (__GET_CLASS_MASK_INHERITS__(&(__##NAME##_ClassObject__.mask))) { \
        __class_inherit_static__(&__##NAME##_ClassObject__); \
      } \
    ) \
    return self; \
  } \
  void* __##NAME##_static_destroy__(NAME* self)

#define __M_VA_ARG__( ARGS_COUNT, DEFAULT_ARGS... ) \
  va_list __RAW_METHOD_ARGS__; \
  void* __ARG_LIST__[ARGS_COUNT] = {DEFAULT_ARGS}; \
  size_t __ARG_CNT__ = 0; \
  do { \
    va_start(__RAW_METHOD_ARGS__, self); \
    for (size_t i = 0; \
      (i < ARGS_COUNT) && \
      (__ARG_LIST__[i] = va_arg(__RAW_METHOD_ARGS__, void*)); \
      ++i) { \
        __ARG_CNT__++; \
      }; \
    va_end(__RAW_METHOD_ARGS__); \
  } while (0);

#define __AUX_INIT_BEGIN__(NAME) \
  if (self != &__##NAME##_Default_Instance__ && \
      !__GET_CLASS_MASK_WAS_INIT__(&(__##NAME##_ClassObject__.mask))) { \
    NAME##_init(&__##NAME##_Default_Instance__); \
  } \
  __##NAME##_static_init__(self); \
  __ON_INIT__(NAME, \
    if (!__GET_CLASS_MASK_IS_STATIC__(&(__##NAME##_ClassObject__.mask))) { \
      __class_init__((__vClassObject__*)&__##NAME##_Default_vClassObject__); \
      if (__GET_CLASS_MASK_INHERITS__(&(__##NAME##_ClassObject__.mask))) { \
        __class_inherit__(&__##NAME##_ClassObject__); \
      } \
    } \
  ); \
  if (!__GET_CLASS_MASK_IS_STATIC__(&(__##NAME##_ClassObject__.mask)) && \
      !__GET_CLASS_MASK_IS_BARE__(&(__##NAME##_ClassObject__.mask))) { \
    __class_init_instance__((__ClassInstance__*)self, \
                            (__vClassObject__*)&__##NAME##_Default_vClassObject__); \
    if (__GET_CLASS_MASK_INHERITS__(&(__##NAME##_ClassObject__.mask))) { \
      __class_inherit_instance__((__ClassInstance__*)self); \
    } \
  } \

#define __AUX_ADD_INHERITS__(NAME, BASE, FIELD_NAME) { \
    __##BASE##_static_init__((BASE*)(&(self->FIELD_NAME))); \
    __ON_INIT__(NAME, \
      __InheritanceList_add__(__##NAME##_ClassObject__.inherits_from, \
                              (void*)self, \
                              (void*)&(self->FIELD_NAME), \
                              &__##BASE##_ClassObject__); \
    ); \
  } \
  

#define __AUX_INIT_END__(NAME) \
  __##NAME##_ClassObject__.instance_count++; \
  __ON_INIT__(NAME, \
    __SET_CLASS_MASK_WAS_INIT__(&(__##NAME##_ClassObject__.mask), TRUE); \
  ); \
  if (self != &__##NAME##_Default_Instance__) { \
    SCOPE_PUSH(self, __class_destroy_instance__, NAME##_destroy); \
  } \
  return self; \

#define DEF_INIT(NAME, EXPR...) \
  void* NAME##_init(NAME* self, ...) { \
    __AUX_INIT_BEGIN__(NAME); \
    EXPR; \
    __AUX_INIT_END__(NAME); \
  } \


#define __AUX_CLASS__(NAME, STATIC_FIELDS, INSTANCE_FIELDS) \
  __GENERIC_CLASS_DECLARE_MACRO__(NAME, __BaseClass__ __base__;, STATIC_FIELDS, INSTANCE_FIELDS)

#define DEF_CLASS(NAME, STATIC_FIELDS, INSTANCE_FIELDS) \
  __AUX_CLASS__(NAME, STATIC_FIELDS, INSTANCE_FIELDS)

#define __AUX_INHERIT__(NAME, BASE, STATIC_FIELDS, INSTANCE_FIELDS) \
  __GENERIC_CLASS_DECLARE_MACRO__(NAME, BASE __base__;, STATIC_FIELDS, INSTANCE_FIELDS)

#define DEF_INHERIT(NAME, BASE, STATIC_FIELDS, INSTANCE_FIELDS) \
  __AUX_INHERIT__(NAME, BASE, STATIC_FIELDS, INSTANCE_FIELDS)

#define __AUX_CLASS_END__(NAME, MASK, EXPR...) \
  __GENERIC_CLASS_DEFINE_MACRO__(NAME, MASK, EXPR)

#define CLASS_END(NAME, MASK, EXPR...) \
  __AUX_CLASS_END__(NAME, MASK, EXPR)

#define __AUX_INHERIT_END__(NAME, BASE, MASK, EXPR...) \
  __GENERIC_INHERENT_CLASS_DEFINE_MACRO__(NAME, BASE, MASK, EXPR)

#define INHERIT_END(NAME, BASE, MASK, EXPR...) \
  __AUX_INHERIT_END__(NAME, BASE, MASK, EXPR)

#define __AUX_SMETHOD__(CLASS, METHOD, INSTANCE...) (__##CLASS##_Default_vClassObject__.METHOD)

#define __AUX_IMETHOD__(CLASS, METHOD, INSTANCE...) (ARG1_VA_ARGS(INSTANCE)->METHOD)

#define SMETHOD(CLASS, METHOD, INSTANCE...) __AUX_SMETHOD__(CLASS, METHOD, INSTANCE)(INSTANCE, 0)

#define IMETHOD(CLASS, METHOD, INSTANCE...) __AUX_IMETHOD__(CLASS, METHOD, INSTANCE)(INSTANCE, 0)

#define DEFAULT_DESTROY(NAME) { return NULL; } void* NAME##_destroy(NAME* self, ...) { return NULL; }


#define __BRIDGE_CLASS_DECLARE_MACRO__(NAME, \
    STATIC_CLASS_FIELDS) \
  typedef struct __##NAME##_B_vClassObject__ \
  { \
    unsigned int method_shift[__VCLASS_METHOD_COUNT__]; \
    generic_function_t __init__; \
    generic_function_t __destroy__; \
    generic_function_t __to_str__; \
    generic_function_t __data__; \
    generic_function_t __iter__; \
    generic_function_t __next__; \
    generic_function_t __call__; \
    generic_function_t __getitem__; \
    generic_function_t __len__; \
    generic_function_t __neg__; \
    generic_function_t __add__; \
    generic_function_t __iadd__; \
    generic_function_t __sub__; \
    generic_function_t __isub__; \
    generic_function_t __mul__; \
    generic_function_t __imul__; \
    generic_function_t __div__; \
    generic_function_t __idiv__; \
    generic_function_t __mod__; \
    generic_function_t __imod__; \
    generic_function_t __and__; \
    generic_function_t __iand__; \
    generic_function_t __or__; \
    generic_function_t __ior__; \
    generic_function_t __xor__; \
    generic_function_t __ixor__; \
    generic_function_t __not__; \
    generic_function_t __inot__; \
    generic_function_t __contains__; \
    generic_function_t __cmp__; \
    generic_function_t __set__; \
    generic_function_t __get__; \
    generic_function_t __copy__; \
    generic_function_t __assign__; \
    generic_function_t __new__; \
    generic_function_t __delete__; \
    generic_function_t __lt__; \
    generic_function_t __gt__; \
    generic_function_t __eq__; \
    generic_function_t __le__; \
    generic_function_t __ge__; \
    generic_function_t __neq__; \
    generic_function_t __pow__; \
    generic_function_t __cast__; \
    generic_function_t __bitand__; \
    generic_function_t __bitiand__; \
    generic_function_t __bitor__; \
    generic_function_t __bitior__; \
    generic_function_t __bitxor__; \
    generic_function_t __bitixor__; \
    generic_function_t __bitnot__; \
    generic_function_t __bitinot__; \
    generic_function_t __inc__; \
    generic_function_t __dec__; \
    generic_function_t __lsh__; \
    generic_function_t __ilsh__; \
    generic_function_t __rsh__; \
    generic_function_t __irsh__; \
    generic_function_t __ineg__; \
    generic_function_t __listen__; \
    generic_function_t __shout__; \
    generic_function_t __id__; \
    __ClassObject__* cls; \
    __vTable__* vtable; \
    STATIC_CLASS_FIELDS; \
  } __##NAME##_B_vClassObject__; \
  typedef struct NAME##_B \
  { \
    NAME __base__; \
  } NAME##_B; \
  void* __##NAME##_B_static_init__(NAME##_B* self); \
  void* __##NAME##_B_static_destroy__(NAME##_B* self); \
  void* NAME##_B_init(NAME##_B* self , ...); \
  void* NAME##_B_destroy(NAME##_B* self, ...); \
  extern __ClassObject__ __##NAME##_B_ClassObject__; \
  extern __##NAME##_B_vClassObject__ __##NAME##_B_Default_vClassObject__; \
  extern NAME __##NAME##_B_Default_Instance__; \
  extern __ClassMetaData__ __##NAME##_B_Default_MetaData__;

#define __BRIDGE_CLASS_DEFINE_MACRO__(NAME, MASK, EXPR...) \
  __ClassObject__ __##NAME##_B_ClassObject__ = \
    (__ClassObject__){.mask=MASK|STATIC|BARE, \
                      .size=sizeof(NAME##_B), \
                      .default_vcls=(__vClassObject__*)&__##NAME##_B_Default_vClassObject__, \
                      .default_instance=(__ClassInstance__*)&__##NAME##_B_Default_Instance__, \
                      .name=TO_STR_LITERAL(NAME##_B), \
                      .__static_init__=(generic_function_t)__##NAME##_B_static_init__, \
                      .__static_destroy__=(generic_function_t)__##NAME##_B_static_destroy__}; \
  __##NAME##_B_vClassObject__ __##NAME##_Default_vClassObject__ = \
    (__##NAME##_B_vClassObject__){.__init__=(generic_function_t)NAME##_B_init, \
                                .__destroy__=(generic_function_t)NAME##_B_destroy, \
                                .cls=&__##NAME##_B_ClassObject__}; \
  NAME __##NAME##_B_Default_Instance__ = (NAME){}; \
  __ClassMetaData__ __##NAME##_B_Default_MetaData__ = \
    (__ClassMetaData__){.vcls=(__vClassObject__*)&__##NAME##_B_Default_vClassObject__}; \
  void* __##NAME##_B_static_init__(NAME##_B* self) { \
    __ON_INIT__(NAME##_B, \
      *self = (NAME##_B){}; \
      SCOPE_PUSH(&__##NAME##_B_ClassObject__, __class_destroy__); \
      SCOPE_DEFER(&__##NAME##_B_ClassObject__, __class_destroy__, __DEFAULT_PREDICATE__); \
    ); \
    if (self != &__##NAME##_B_Default_Instance__) { \
      SCOPE_PUSH(self, __##NAME##_B_static_destroy__); \
    } \
    EXPR; \
    return self; \
  } \
  void* NAME##_B_init(NAME##_B* self, ...) { \
    if (self != &__##NAME##_B_Default_Instance__ && \
        !__GET_CLASS_MASK_WAS_INIT__(&(__##NAME##_B_ClassObject__.mask))) { \
      NAME##_init(&__##NAME##_B_Default_Instance__); \
    } \
    __##NAME##_B_static_init__(self); \
    __##NAME##_B_ClassObject__.instance_count++; \
    __ON_INIT__(NAME##_B, \
      __SET_CLASS_MASK_WAS_INIT__(&(__##NAME##_B_ClassObject__.mask), TRUE); \
    ); \
    if (self != &__##NAME##_B_Default_Instance__) { \
      SCOPE_PUSH(self, __class_destroy_instance__, NAME##_B_destroy); \
    } \
    return self; \
  } \
  void* NAME##_B_destroy(NAME##_B* self, ...) { \
    return NULL; \
  } \
  void* __##NAME##_B_static_destroy__(NAME##_B* self)


  #define DEF_BRIDGE(NAME, STATIC_FIELDS) \
    __BRIDGE_CLASS_DECLARE_MACRO__(NAME, STATIC_FIELDS)
  
  #define BRIDGE_END(NAME, MASK, EXPR...) \
    __BRIDGE_CLASS_DEFINE_MACRO__(NAME, MASK, EXPR)

#define __AUX_CLS_VCLASS__(CLASS_NAME) (__vClassObject__*)&__##CLASS_NAME##_Default_vClassObject__
#define __AUX_CLS_CLASS_INIT__(CLASS_NAME) (CLASS_NAME*)CLASS_NAME##_init

#define __AUX_CLS_VCLASS_EXP__(CLASS_NAME) __AUX_EXP_MACRO_ARG__(__AUX_CLS_VCLASS__, CLASS_NAME)
#define __AUX_CLS_CLASS_INIT_EXP__(CLASS_NAME) __AUX_EXP_MACRO_ARG__(__AUX_CLS_CLASS_INIT__, CLASS_NAME)

#define __AUX_CLS_ALLOCA__(CLASS_NAME...) \
  __AUX_CLS_CLASS_INIT_EXP__(ARG1_VA_ARGS(CLASS_NAME))((ARG1_VA_ARGS(CLASS_NAME)*)alloca(sizeof(ARG1_VA_ARGS(CLASS_NAME))), ARG1_VA_ARGS_VA(CLASS_NAME, 0))


void* __aux_class_new_wrapper__(__vClassObject__* vcls, size_t size, __ClassInstance__* template_instance);

#define __AUX_CLS_MALLOC__(CLASS_NAME...) \
  (ARG1_VA_ARGS(CLASS_NAME)*)__aux_class_new_wrapper__(__AUX_CLS_VCLASS_EXP__(ARG1_VA_ARGS(CLASS_NAME)), ARG2_VA_ARGS(CLASS_NAME, 1), (__ClassInstance__*)__AUX_CLS_ALLOCA__(ARG1_VA_ARGS(CLASS_NAME), ARG2_VA_ARGS_VA(CLASS_NAME, 0, 0))) \


#define CLS(CLASS_NAME...) __AUX_CLS_ALLOCA__(CLASS_NAME)

#define NEW(CLASS_NAME...) __AUX_CLS_MALLOC__(CLASS_NAME)


