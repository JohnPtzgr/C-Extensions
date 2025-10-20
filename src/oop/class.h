#include "../src/memory/dyn_alloc.h"
#include "../src/algorithm/hash.h"

#pragma once


#define __DEFAULT_VTABLE_SIZE__ 8
#define __DEFAULT_VTABLE_MLT_OFFSET__ 8
#define __VTABLE_SIZE_IS_POWER_OF_2__ TRUE

#define __DEFAULT_INHERITANCE_LIST_CAPACITY__ 8

#define __VCLASS_METHOD_COUNT__ 64

#define __CLASS_NAME_MAX_LENGTH__ 256

#define __STATIC_INHERITANCE_LIST_NODES__ 8

typedef struct __vTableHash__ {
  size_t hashX;
  size_t hashY;
} __vTableHash__;

typedef struct __vTableNode__ {
  void* data;
  size_t data_mask;
  size_t data_shift;
  size_t mask;
  __vTableHash__ hash;
} __vTableNode__;

#define __AUX_16_BYTE_VHASH__(X...) ((__vTableHash__){.hashX=__AUX_16_BYTE_HASH_S__(__AUX_HASH_S_ULL_D__, X), \
                                                      .hashY=__AUX_16_BYTE_HASH_S__(__AUX_HASH_S_ULL_E__, X)})


#define _CE_VHASH16(X) __AUX_16_BYTE_VHASH__(X)


typedef size_t (*__vTable_byte_hasher_t__)(const char* key, size_t k_hash);

typedef struct __vTable__ {
  __vTable_byte_hasher_t__ hasher;
  __vTableNode__* data;
  size_t size;
} __vTable__;

__vTableHash__ __class_vtable_hash__(const char* key);

void* __vTable_add__(__vTable__* table, __vTableHash__ hash, __vTableNode__ value);
void* __vTable_remove__(__vTable__* table, __vTableHash__ hash);
__vTableNode__* __vTable_get__(__vTable__* table, __vTableHash__ hash);
BOOL __vTable_check__(__vTable__* table, __vTableHash__ hash);
void* __vTable_join__(__vTable__* table, __vTable__* source);


typedef enum __m_enum__ {
  __m_init__,
  __m_destroy__,
  __m_move__,
  __m_data__,
  __m_iter__,
  __m_next__,
  __m_begin__,
  __m_end__,
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

typedef struct __ClassObject__ __ClassObject__;

typedef struct __vClassObject__ __vClassObject__;

typedef struct __MetaObject__ {
  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __move__;
  generic_function_t __data__;
  generic_function_t __iter__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
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

  unsigned int* method_shift;

} __MetaObject__;

typedef struct __InheritanceListNode__ {
  __ClassObject__* cls;
  size_t adress_shift;
} __InheritanceListNode__;

#define INHERITANCE_LIST_STATIC_SIZE 8

typedef struct __InheritanceList__ {
  __InheritanceListNode__* list;
  __InheritanceListNode__* static_list;
  size_t capacity;
  size_t size;
} __InheritanceList__;

typedef struct __ClassInstance__ __ClassInstance__;

typedef struct __ClassInstance_R__ __ClassInstance_R__;


void* __InheritanceList_add__(__InheritanceList__* list, void* self,
  void* instance, __ClassObject__* cls);
void* __InheritanceList_remove__(__InheritanceList__* list, __ClassInstance__* instance);
size_t __InheritanceList_find__(__InheritanceList__* list, __vTableHash__ hash);
size_t __InheritanceList_find_built_in__(__InheritanceList__* list, __m_enum__ built_in_no);
void* __InheritanceList_init__(__InheritanceList__* list, __InheritanceListNode__* default_nodes);
void* __InheritanceList_destroy__(__InheritanceList__* list);


typedef struct class_field_t class_field_t;

typedef class_field_t* class_structure_t;


#define DEFAULT_VCLASS_LIST_SIZE 8

typedef struct __vClassObjectPrt__ {

  void* data;

} __vClassObjectPrt__;

typedef struct __ClassMetaObject__ {

  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __move__;
  generic_function_t __data__;
  generic_function_t __iter__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
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

  unsigned int* method_shift;

  __ClassObject__* cls;

  __vTable__* vtable;

} __ClassMetaObject__;

typedef struct type_object_t {

  __ClassMetaObject__* type_meta;
  const char* type_name;
  size_t type_size;
  size_t type_mask;

} type_object_t;

typedef struct class_field_t
{

  size_t field_mask;
  type_object_t type;

} class_field_t;

typedef struct __vClassObject__ {

  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __move__;
  generic_function_t __data__;
  generic_function_t __iter__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
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

  unsigned int* method_shift;

  __ClassObject__* cls;

  __vTable__* vtable;

  __vClassObjectPrt__* protected;

} __vClassObject__;

typedef struct __ClassInstance__ {
  __vClassObject__ __meta__[0];
} __ClassInstance__;

typedef struct __ClassInterface__ {
  const __vClassObject__* __meta__;
  __ClassInstance__* self;
} __ClassInterface__;

typedef __vClassObject__ ____ClassInstance___vClassObject__;

extern __ClassObject__ ____ClassInstance___ClassObject__;
extern __ClassInstance__ ____ClassInstance___Default_Instance__;
extern __vClassObject__ ____ClassInstance___Default_vClassObject__;
extern type_object_t __ClassInstance___type;
extern void* ____ClassInstance___static_init__(__ClassInstance__* self);
extern void* ____ClassInstance___static_destroy__(__ClassInstance__* self);

typedef struct __Interface__ {
  const __MetaObject__* __meta__;
} __Interface__;

#define DefaultBase __ClassInstance__

typedef struct __ClassObject__ {

  size_t instance_size;
  size_t vclass_size;
  size_t mask;
  size_t instance_count;

  size_t __vclass_cnt;
  size_t __vclass_capacity;

  const char* name;

  class_structure_t fields;
  class_structure_t static_fields;

  __vTable__* static_vtable;

  __InheritanceList__* inherits_from;

  __vClassObject__** alloc_vcls;

  __vClassObject__* default_vcls;
  __ClassInstance__* default_instance;

  generic_function_t __static_init__;
  generic_function_t __static_destroy__;

  generic_function_t __class_object_init__;
  generic_function_t __class_object_destroy__;

} __ClassObject__;

void* __class_init__(__vClassObject__* default_vclass);
void* __class_destroy__(__ClassObject__* cls);
void* __class_destroy_instance__(__ClassInstance__* instance,
  generic_function_t destructor);
void __class_inherit_static__(__ClassObject__* cls);
void __class_inherit__(__ClassObject__* cls);
void __class_inherit_instance__(__ClassInstance__* instance);

extern const char* __VCLASS_METHOD_UC_NAMES__[__VCLASS_METHOD_COUNT__];


#define PRIVATE(PRIVATE_TYPE, PRIVATE_NAME) struct PRIVATE_TYPE* __p_##PRIVATE_NAME


void* __aux_class_new_vclass__(__ClassObject__* cls);

void* __aux_type_cast__(void* expr, type_object_t* src_type, type_object_t* trg_type, void* allocated_memory);
void* __aux_class_cast__(void* expr, __ClassMetaObject__* src_type, __ClassMetaObject__* trg_type, void* allocated_memory);


#ifndef __GET_CLASS_MASK_IS_DYNAMIC
BOOL __GET_CLASS_MASK_IS_STATIC__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_FUNDAMENTAL__(size_t* mask);

BOOL __GET_CLASS_MASK_INHERITS__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_ABSTRACT__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_CONST__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_INNER__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_SUPER__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BRIDGE__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BARE__(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_INIT__(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask);

void __SET_CLASS_MASK_STATIC__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_FUNDAMENTAL__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_INHERITS__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_ABSTRACT__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_CONST__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_INNER__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_SUPER__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BRIDGE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BARE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_INIT__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask, BOOL new_type);

#define STATIC 1
#define FUNDAMENTAL 2
#define INHERITS 4
#define ABSTRACT 8
#define CONST 16
#define INNER 32
#define SUPER 64
#define BRIDGE 128
#define BARE 256

#endif // CLASS MASK RELATED DEFINITIONS

#define __ON_INIT__(NAME, EXPR...) \
  if (!__GET_CLASS_MASK_WAS_INIT__(&(__##NAME##_ClassObject__.mask))) { \
    EXPR; \
  }

#define __ON_STATIC_INIT__(NAME, EXPR...) \
  if (!__GET_CLASS_MASK_WAS_STATIC_INIT__(&(__##NAME##_ClassObject__.mask))) { \
    EXPR; \
  }

#define __CLASS_MASK__(NAME) __##NAME##_ClassObject__.mask

#define __AUX_META__(NAME) __##NAME##_Default_vClassObject__

#define META(NAME) __AUX_META__(NAME)

#define _C META(_CLASS)

#define DEF_METHODS(...)

#define __GENERIC_CLASS_DECLARE_MACRO__(NAME, \
    CLASS_FIELDS, \
    RAW_FIELDS, \
    STATIC_CLASS_FIELDS, \
    PROTECTED_STATIC_CLASS_FIELDS, \
    CLASS_FIELD_COUNT, \
    STATIC_CLASS_FIELD_COUNT, \
    CLASS_DEFINITION_EXPR... \
  ) \
  typedef struct __##NAME##_vClassObject__ __##NAME##_vClassObject__; \
  typedef struct NAME \
  { \
    CLASS_FIELDS; \
  } NAME; \
  typedef struct NAME##_R \
  { \
    RAW_FIELDS; \
  } NAME##_R; \
  CLASS_DEFINITION_EXPR; \
  typedef struct __##NAME##_vClassObjectPrt__ { \
    __vClassObjectPrt__ default_protected; \
    PROTECTED_STATIC_CLASS_FIELDS; \
  } __##NAME##_vClassObjectPrt__; \
  typedef struct __##NAME##_vClassObject__ \
  { \
    generic_function_t __init__; \
    generic_function_t __destroy__; \
    generic_function_t __move__; \
    generic_function_t __data__; \
    generic_function_t __iter__; \
    generic_function_t __next__; \
    generic_function_t __begin__; \
    generic_function_t __end__; \
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
    unsigned int* method_shift; \
    __ClassObject__* cls; \
    __vTable__* vtable; \
    __vClassObjectPrt__* __protected__; \
    STATIC_CLASS_FIELDS; \
    char __prot_vcls_data__[sizeof(__##NAME##_vClassObjectPrt__)]; \
    unsigned int __method_shift__[__VCLASS_METHOD_COUNT__ + \
                                  CLASS_FIELD_COUNT + \
                                  STATIC_CLASS_FIELD_COUNT]; \
  } __##NAME##_vClassObject__; \
  typedef struct __##NAME##_ClassInterface__ { \
    NAME* self; \
    const __##NAME##_vClassObject__* __meta__; \
  } __##NAME##_ClassInterface__; \
  extern void* __##NAME##_static_init__(NAME* self); \
  extern void* __##NAME##_static_destroy__(NAME* self); \
  extern void* NAME##_init(NAME* self , ...); \
  extern void* NAME##_destroy(NAME* self, ...); \
  extern __ClassObject__ __##NAME##_ClassObject__; \
  extern __##NAME##_vClassObject__ __##NAME##_Default_vClassObject__; \
  extern NAME __##NAME##_Default_Instance__; \
  extern type_object_t __##NAME##_type__; \
  extern type_object_t* NAME##_type; \
  extern __InheritanceList__ __##NAME##__InheritanceList__; \
  extern __InheritanceListNode__ __##NAME##__InheritanceListNodes__[__STATIC_INHERITANCE_LIST_NODES__]; \
  extern class_field_t __##NAME##_fields__[CLASS_FIELD_COUNT]; \
  extern class_field_t __##NAME##_static_fields__[STATIC_CLASS_FIELD_COUNT]; \


#define __GENERIC_CLASS_DEFINE_MACRO__(NAME, BASE, MASK, EXPR...) \
  __ClassObject__ __##NAME##_ClassObject__ = \
    (__ClassObject__){.mask=MASK, \
                      .instance_size=sizeof(NAME), \
                      .vclass_size=sizeof(__##NAME##_vClassObject__), \
                      .default_vcls=(__vClassObject__*)&__##NAME##_Default_vClassObject__, \
                      .default_instance=(__ClassInstance__*)&__##NAME##_Default_Instance__, \
                      .name=#NAME, \
                      .fields=__##NAME##_fields__, \
                      .static_fields=__##NAME##_static_fields__, \
                      .__static_init__=(generic_function_t)__##NAME##_static_init__, \
                      .__static_destroy__=(generic_function_t)__##NAME##_static_destroy__}; \
  __##NAME##_vClassObject__ __##NAME##_Default_vClassObject__ = \
    (__##NAME##_vClassObject__){.__init__=(generic_function_t)NAME##_init, \
                                .__destroy__=(generic_function_t)NAME##_destroy, \
                                .cls=&__##NAME##_ClassObject__, \
                                .__protected__=(__vClassObjectPrt__*)&(__##NAME##_Default_vClassObject__.__prot_vcls_data__), \
                                .__base__=&__##BASE##_Default_vClassObject__}; \
  NAME __##NAME##_Default_Instance__ = (NAME){}; \
  type_object_t __##NAME##_type__ = (type_object_t){.type_mask=MASK, \
                                                    .type_size=sizeof(NAME), \
                                                    .type_meta=(__ClassMetaObject__*)&__##NAME##_Default_vClassObject__, \
                                                    .type_name=#NAME}; \
  type_object_t* NAME##_type = &__##NAME##_type__; \
  __InheritanceList__ __##NAME##__InheritanceList__ = (__InheritanceList__){}; \
  __InheritanceListNode__ __##NAME##__InheritanceListNodes__[__STATIC_INHERITANCE_LIST_NODES__] = {}; \
  class_field_t __##NAME##_fields__[sizeof(__##NAME##_fields__)] = {}; \
  class_field_t __##NAME##_static_fields__[sizeof(__##NAME##_static_fields__)] = {}; \
  void* __##NAME##_static_init__(NAME* self) { \
    __##BASE##_ClassObject__.__static_init__((void*)self); \
    __ON_STATIC_INIT__(NAME, \
      if (self != &__##NAME##_Default_Instance__) { \
        __##NAME##_static_init__(&__##NAME##_Default_Instance__); \
      } else { \
        *self = (NAME){}; \
        if (!__##NAME##_ClassObject__.inherits_from) { \
          __##NAME##_ClassObject__.inherits_from = &__##NAME##__InheritanceList__; \
          __InheritanceList_init__(__##NAME##_ClassObject__.inherits_from, __##NAME##__InheritanceListNodes__); \
          __InheritanceList_add__(__##NAME##_ClassObject__.inherits_from, \
                                  (void*)self, \
                                  (void*)self + sizeof(void*), \
                                  &__##BASE##_ClassObject__); \
        } \
        SCOPE_PUSH(&__##NAME##_ClassObject__, __class_destroy__); \
        SCOPE_DEFER(&__##NAME##_ClassObject__, __class_destroy__, __DEFAULT_PREDICATE__); \
      } \
    ); \
    if (!__GET_CLASS_MASK_IS_BARE__(&(__##NAME##_ClassObject__.mask))) { \
      *(__ClassMetaObject__**)(&self->__meta__) = (__ClassMetaObject__*)&__##NAME##_Default_vClassObject__; \
    } \
    if (self != &__##NAME##_Default_Instance__) { \
      SCOPE_PUSH(self, __##NAME##_static_destroy__); \
    } \
    EXPR; \
    __ON_STATIC_INIT__(NAME, \
      __SET_CLASS_MASK_WAS_STATIC_INIT__(&(__##NAME##_ClassObject__.mask), TRUE); \
      __class_inherit_static__(&__##NAME##_ClassObject__); \
      if (__##NAME##_ClassObject__.__class_object_init__) { \
        __##NAME##_ClassObject__.__class_object_init__(&__##NAME##_ClassObject__); \
      } \
    ); \
    return self; \
  } \
  void* __##NAME##_static_destroy__(NAME* self)

#define __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_CLASS_OBJECT__(NAME, MASK, EXPR...) \
  __ClassObject__ __##NAME##_ClassObject__ = \
    (__ClassObject__){.mask=MASK, \
                      .instance_size=sizeof(NAME), \
                      .vclass_size=sizeof(__##NAME##_vClassObject__), \
                      .default_vcls=(__vClassObject__*)&__##NAME##_Default_vClassObject__, \
                      .default_instance=(__ClassInstance__*)&__##NAME##_Default_Instance__, \
                      .name=#NAME, \
                      .fields=__##NAME##_fields__, \
                      .static_fields=__##NAME##_static_fields__, \
                      .__static_init__=(generic_function_t)__##NAME##_static_init__, \
                      .__static_destroy__=(generic_function_t)__##NAME##_static_destroy__, \
                      EXPR};

#define __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_DEFAULT_V_CLASS_OBJECT__(NAME, BASE, MASK, EXPR...) \
  __##NAME##_vClassObject__ __##NAME##_Default_vClassObject__ = \
    (__##NAME##_vClassObject__){.__init__=(generic_function_t)NAME##_init, \
                                .__destroy__=(generic_function_t)NAME##_destroy, \
                                .cls=&__##NAME##_ClassObject__, \
                                .__protected__=(__vClassObjectPrt__*)&(__##NAME##_Default_vClassObject__.__prot_vcls_data__), \
                                .__base__=&__##BASE##_Default_vClassObject__, \
                                EXPR}; \

#define __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_DEFAULT_INSTANCE__(NAME, MASK, EXPR...) \
  NAME __##NAME##_Default_Instance__ = (NAME){EXPR}; \

#define __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_END__(NAME, MASK, EXPR...) \
  type_object_t NAME##_type = (type_object_t){.type_mask=MASK, \
                                              .type_size=sizeof(NAME), \
                                              .type_meta=(__ClassMetaObject__*)&__##NAME##_Default_vClassObject__, \
                                              .type_name=#NAME}; \
  void* __##NAME##_static_init__(NAME* self) { \
    __##BASE##_ClassObject__.__static_init__((void*)self); \
    __ON_STATIC_INIT__(NAME, \
      if (self != &__##NAME##_Default_Instance__) { \
        __##NAME##_static_init__(&__##NAME##_Default_Instance__); \
      } else { \
        *self = (NAME){}; \
        if (!__##NAME##_ClassObject__.inherits_from) { \
          __##NAME##_ClassObject__.inherits_from = &__##NAME##__InheritanceList__; \
          __InheritanceList_init__(__##NAME##_ClassObject__.inherits_from, __##NAME##__InheritanceListNodes__); \
          __InheritanceList_add__(__##NAME##_ClassObject__.inherits_from, \
                                  (void*)self, \
                                  (void*)self + sizeof(void*), \
                                  &__##BASE##_ClassObject__); \
        } \
        SCOPE_PUSH(&__##NAME##_ClassObject__, __class_destroy__); \
        SCOPE_DEFER(&__##NAME##_ClassObject__, __class_destroy__, __DEFAULT_PREDICATE__); \
      } \
    ); \
    if (!__GET_CLASS_MASK_IS_BARE__(&(__##NAME##_ClassObject__.mask))) { \
      *(__ClassMetaObject__**)(&self->__meta__) = (__ClassMetaObject__*)&__##NAME##_Default_vClassObject__; \
    } \
    if (self != &__##NAME##_Default_Instance__) { \
      SCOPE_PUSH(self, __##NAME##_static_destroy__); \
    } \
    EXPR; \
    __ON_STATIC_INIT__(NAME, \
      __SET_CLASS_MASK_WAS_STATIC_INIT__(&(__##NAME##_ClassObject__.mask), TRUE); \
      __class_inherit_static__(&__##NAME##_ClassObject__); \
      if (__##NAME##_ClassObject__.__class_object_init__) { \
        __##NAME##_ClassObject__.__class_object_init__(&__##NAME##_ClassObject__); \
      } \
    ); \
    return self; \
  } \
  void* __##NAME##_static_destroy__(NAME* self)


#define __AUX_CLASS_DECL_EXP__(NAME, \
                               FIELDS, \
                               RAW_FIELDS, \
                               STATIC_FIELDS, \
                               PROTECTED_FIELDS, \
                               FIELDS_CNT, \
                               STATIC_FIELDS_CNT, \
                               EXPR...) \
  __GENERIC_CLASS_DECLARE_MACRO__(NAME, \
                                  FIELDS, \
                                  RAW_FIELDS, \
                                  STATIC_FIELDS, \
                                  PROTECTED_FIELDS, \
                                  FIELDS_CNT, \
                                  STATIC_FIELDS_CNT, \
                                  EXPR);


#define __AUX_CLASS_VCLASS_T__(NAME) __##NAME##_vClassObject__

#define __AUX_CLASS_DECL__(BASE, NAME, ARGS...) \
  __AUX_CLASS_DECL_EXP__(NAME, \
                         BASE __base__; \
                         ARG2_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;); \
                         __AUX_CLASS_VCLASS_T__(NAME)* __meta__, \
                         BASE __base__; \
                         ARG2_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         __AUX_CLASS_VCLASS_T__(BASE)* __base__; \
                         ARG3_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         ARG4_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         ARG5_VA_ARGS(ARGS, 0, 0, 0, 0, 0, 0), \
                         ARG6_VA_ARGS(ARGS, 0, 0, 0, 0, 0, 0), \
                         ARG7_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;) \
                         ) \

#define __AUX_CLASS_DECL_BARE__(BASE, NAME, ARGS...) \
  __AUX_CLASS_DECL_EXP__(NAME, \
                         BASE __base__; \
                         ARG2_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;); \
                         __vClassObject__ __meta__[0], \
                         BASE __base__; \
                         ARG2_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         __AUX_CLASS_VCLASS_T__(BASE)* __base__; \
                         ARG3_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         ARG4_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         ARG5_VA_ARGS(ARGS, 0, 0, 0, 0, 0, 0), \
                         ARG6_VA_ARGS(ARGS, 0, 0, 0, 0, 0, 0), \
                         ARG7_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;) \
                         ) \

#define __AUX_CLASS_DECL_BRIDGE__(BASE, ARGS...) \
  __AUX_CLASS_DECL_EXP__(BASE##_B, \
                         BASE __base__; \
                         __vClassObject__ __meta__[0], \
                         BASE __base__;, \
                         ARG2_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         ARG3_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;), \
                         ARG4_VA_ARGS(ARGS, 0, 0, 0, 0, 0, 0), \
                         ARG5_VA_ARGS(ARGS, 0, 0, 0, 0, 0, 0), \
                         ARG6_VA_ARGS(ARGS, ;, ;, ;, ;, ;, ;) \
                         ) \

#define __AUX_CLASS_END_CLASS_OBJ__(NAME, MASK, EXPR...) \
  __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_CLASS_OBJECT__(NAME, MASK, EXPR)

#define __AUX_CLASS_END_V_CLASS_OBJ__(NAME, BASE, MASK, EXPR...) \
  __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_DEFAULT_V_CLASS_OBJECT__(NAME, BASE, MASK, EXPR)

#define __AUX_CLASS_END_INSTANCE__(NAME, MASK, EXPR...) \
  __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_DEFAULT_INSTANCE__(NAME, MASK, EXPR)

#define __AUX_CLASS_END_SEP__(NAME, MASK, EXPR...) \
  __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_END__(NAME, MASK, EXPR)


#define __BRIDGE_CLASS_DEFINE_MACRO__(NAME, MASK, EXPR...) \
  __AUX_CLASS_END_CLASS_OBJ__(NAME##_B, MASK | BARE | STATIC | BRIDGE); \
  __AUX_CLASS_END_INSTANCE__(NAME##_B, 0, 0); \
  __##NAME##_B_vClassObject__ __##NAME##_B_Default_vClassObject__ = \
    (__##NAME##_B_vClassObject__){.__init__=(generic_function_t)NAME##_B_init, \
                                  .__destroy__=(generic_function_t)NAME##_B_destroy, \
                                  .cls=&__##NAME##_B_ClassObject__, \
                                  .__protected__=(__vClassObjectPrt__*)&(__##NAME##_B_Default_vClassObject__.__prot_vcls_data__)}; \
  type_object_t NAME##_B_type = (type_object_t){.type_mask=MASK|STATIC|BARE|BRIDGE, \
                                                .type_size=sizeof(NAME), \
                                                .type_meta=(__ClassMetaObject__*)&__##NAME##_B_Default_vClassObject__, \
                                                .type_name=#NAME"_B"}; \
  void* __##NAME##_B_static_init__(NAME##_B* self) { \
    __ON_STATIC_INIT__(NAME##_B, \
      if (self != &__##NAME##_B_Default_Instance__) { \
        __##NAME##_B_static_init__(&__##NAME##_B_Default_Instance__); \
      } else { \
        *self = (NAME##_B){}; \
        SCOPE_PUSH(&__##NAME##_B_ClassObject__, __class_destroy__); \
        SCOPE_DEFER(&__##NAME##_B_ClassObject__, __class_destroy__, __DEFAULT_PREDICATE__); \
      } \
    ); \
    if (self != &__##NAME##_B_Default_Instance__) { \
      SCOPE_PUSH(self, __##NAME##_B_static_destroy__); \
    } \
    EXPR; \
    __ON_STATIC_INIT__(NAME##_B, \
      __SET_CLASS_MASK_WAS_STATIC_INIT__(&(__##NAME##_B_ClassObject__.mask), TRUE); \
      if (__##NAME##_B_ClassObject__.__class_object_init__) { \
        __##NAME##_B_ClassObject__.__class_object_init__(&__##NAME##_B_ClassObject__); \
      } \
    ); \
    return self; \
  } \
  void* NAME##_B_init(NAME##_B* self, ...) { \
    if (self != &__##NAME##_B_Default_Instance__ && \
        !__GET_CLASS_MASK_WAS_INIT__(&(__##NAME##_B_ClassObject__.mask))) { \
      NAME##_B_init(&__##NAME##_B_Default_Instance__); \
    } \
    __##NAME##_B_static_init__(self); \
    EXC_ASSERT(((__##NAME##_B_ClassObject__.mask & ABSTRACT) == 0) && "Abstract class is not instantiable!"); \
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

#define __BRIDGE_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_DEFAULT_V_CLASS_OBJECT__(NAME, MASK, EXPR...) \
  __##NAME##_B_vClassObject__ __##NAME##_B_Default_vClassObject__ = \
    (__##NAME##_B_vClassObject__){.__init__=(generic_function_t)NAME##_B_init, \
                                  .__destroy__=(generic_function_t)NAME##_B_destroy, \
                                  .cls=&__##NAME##_B_ClassObject__, \
                                  .__protected__=(__vClassObjectPrt__*)&(__##NAME##_B_Default_vClassObject__.__prot_vcls_data__), \
                                  EXPR}; \

#define __AUX_CLS_VCLASS__(CLASS_NAME) (&__##CLASS_NAME##_Default_vClassObject__)
#define __AUX_CLS_DEF_INST__(CLASS_NAME) (&__##CLASS_NAME##_Default_Instance__)
#define __AUX_CLS_CLASS_INIT__(CLASS_NAME) (CLASS_NAME*)CLASS_NAME##_init

#define __AUX_CLS_VCLASS_EXP__(CLASS_NAME) __AUX_EXP_MACRO_ARG__(__AUX_CLS_VCLASS__, CLASS_NAME)
#define __AUX_CLS_CLASS_INIT_EXP__(CLASS_NAME) __AUX_EXP_MACRO_ARG__(__AUX_CLS_CLASS_INIT__, CLASS_NAME)

#define __AUX_CLS_ALLOCA__(CLASS_NAME...) \
  __AUX_CLS_CLASS_INIT_EXP__(ARG1_VA_ARGS(CLASS_NAME))((ARG1_VA_ARGS(CLASS_NAME)*)alloca(sizeof(ARG1_VA_ARGS(CLASS_NAME))), ARG1_VA_ARGS_VA(CLASS_NAME, 0))

void* __aux_class_new_wrapper__(__vClassObject__* vcls, size_t size, __ClassInstance__* template_instance);

#define __AUX_CLS_MALLOC__(CLASS_NAME...) \
  (ARG1_VA_ARGS(CLASS_NAME)*)__aux_class_new_wrapper__((__vClassObject__*)__AUX_CLS_VCLASS_EXP__(ARG1_VA_ARGS(CLASS_NAME)), ARG2_VA_ARGS(CLASS_NAME, 1), (__ClassInstance__*)__AUX_CLS_ALLOCA__(ARG1_VA_ARGS(CLASS_NAME), ARG2_VA_ARGS_VA(CLASS_NAME, 0, 0))) \

#define __AUX_CLS_COPY__(CLASS_NAME, ARGS...) ((CLASS_NAME*)__AUX_CLS_VCLASS__(CLASS_NAME)->__copy__(__AUX_CLS_ALLOCA__(CLASS_NAME), ARG1_VA_ARGS_VA(ARGS, __AUX_CLS_DEF_INST__(CLASS_NAME))))

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
  EXC_ASSERT(((__##NAME##_ClassObject__.mask & ABSTRACT) == 0) && "Abstract class is not instantiable!"); \
  __##NAME##_ClassObject__.instance_count++; \
  __ON_INIT__(NAME, \
    if (!__GET_CLASS_MASK_IS_STATIC__(&(__##NAME##_ClassObject__.mask))) { \
      __class_init__((__vClassObject__*)&__##NAME##_Default_vClassObject__); \
      if (__GET_CLASS_MASK_INHERITS__(&(__##NAME##_ClassObject__.mask))) { \
        __class_inherit__(&__##NAME##_ClassObject__); \
      } \
    } \
  ); \

#define __AUX_ADD_INHERITS__(NAME, BASE, FIELD_NAME) { \
  __##BASE##_ClassObject__.__static_init__((void*)(&(self->FIELD_NAME))); \
    __ON_INIT__(NAME, \
      __InheritanceList_add__(__##NAME##_ClassObject__.inherits_from, \
                              (void*)self, \
                              (void*)&(self->FIELD_NAME), \
                              &__##BASE##_ClassObject__); \
    ); \
  } \

// Base class name, This class name, Field name
#define AddBase(BASE, NAME, FIELD) \\
  __AUX_ADD_INHERITS__(NAME, BASE, FIELD)


#define __AUX_INIT_END__(NAME) \
  __##NAME##_ClassObject__.instance_count++; \
  __ON_INIT__(NAME, \
    __SET_CLASS_MASK_WAS_INIT__(&(__##NAME##_ClassObject__.mask), TRUE); \
  ); \
  if (self != &__##NAME##_Default_Instance__) { \
    SCOPE_PUSH(self, __class_destroy_instance__, NAME##_destroy); \
  } \
  return self; \

#define DefInit(NAME, EXPR...) \
  void* NAME##_init(NAME* self, ...) { \
    __AUX_INIT_BEGIN__(NAME); \
    EXPR; \
    __AUX_INIT_END__(NAME); \
  } \


#define DefInitBegin(NAME, EXPR...) \
  __AUX_INIT_BEGIN__(NAME);

#define DefInitEnd(NAME, EXPR...) \
  __AUX_INIT_END__(NAME);


#define Static_Cast(TARGET_TYPE, EXPR...) (*(TARGET_TYPE*)(&(EXPR)))

#define Dynamic_Cast(TARGET_TYPE, SOURCE_TYPE, EXPR...) ((TARGET_TYPE*)__aux_type_cast__((void*)(EXPR), (type_object_t*)SOURCE_TYPE##_type, (type_object_t*)TARGET_TYPE##_type, alloca(sizeof(TARGET_TYPE))))

#define Class_Cast(TARGET_TYPE, SOURCE_TYPE, EXPR...) ((TARGET_TYPE*)__aux_class_cast__((void*)(EXPR), SOURCE_TYPE##_type->type_meta, TARGET_TYPE##_type->type_meta, alloca(sizeof(TARGET_TYPE))))


#define __AUX_SMETHOD__(CLASS, METHOD) \
  __##CLASS##_Default_vClassObject__.METHOD

#define __AUX_FIELD_DELTA_ADDR__(CLASS, METHOD_A, METHOD_B) ((Static_Cast(size_t, (void*){&__AUX_SMETHOD__(CLASS, METHOD_A)}) - Static_Cast(size_t, (void*){&__AUX_SMETHOD__(CLASS, METHOD_B)})) / sizeof(void*))

#define __AUX_METHOD_IDX__(CLASS, METHOD) \
  __AUX_FIELD_DELTA_ADDR__(CLASS, METHOD, __init__)

#define __AUX_METHOD_SHIFT_ID__(CLASS, METHOD, ID) \
  ((ID >= (sizeof(__vClassObject__) / sizeof(void*))) ? (ID - __AUX_FIELD_DELTA_ADDR__(CLASS, __protected__, __id__)) : (ID))

#define __AUX_METHOD_SHIFT__(CLASS, METHOD, ID) __AUX_SMETHOD__(CLASS, method_shift)[__AUX_METHOD_SHIFT_ID__(CLASS, METHOD, ID)]

#define __AUX_IMETHOD__(CLASS, METHOD, INSTANCE...) (ARG1_VA_ARGS(INSTANCE)->METHOD)

#define SMETHOD(CLASS, METHOD, INSTANCE...) __AUX_SMETHOD__(CLASS, METHOD)((void*)((void**)ARG1_VA_ARGS(INSTANCE) + (size_t){__AUX_METHOD_SHIFT__(CLASS, METHOD, __AUX_METHOD_IDX__(CLASS, METHOD))}), ARG1_VA_ARGS_VA(INSTANCE, 0))

#define IMETHOD(CLASS, METHOD, INSTANCE...) __AUX_IMETHOD__(CLASS, METHOD, INSTANCE)(INSTANCE, 0)

#define DEFAULT_DESTROY(NAME) { return NULL; } void* NAME##_destroy(NAME* self, ...) { return NULL; }

#define DEFAULT_INIT(NAME) void* NAME##_init(NAME* self, ...) { \
  __AUX_INIT_BEGIN__(NAME); \
  __AUX_INIT_END__(NAME); \
}


#define AsInterface(INSTANCE, META) \
  (__ClassInterface__){.self=(void*)(INSTANCE), \
                       .__meta__=(__vClassObject__*)(META)}


// Base, Name, Fields, Static Fields, Protected Fields, Field Cnt, Static Field Cnt, EXPR
#define Class(BASE, NAME...) __AUX_CLASS_DECL__(BASE, ARG1_VA_ARGS(NAME), NAME)

// Base, Name, Fields, Static Fields, Protected Fields, Field Cnt, Static Field Cnt, EXPR
#define BareClass(BASE, NAME...) __AUX_CLASS_DECL_BARE__(BASE, ARG1_VA_ARGS(NAME), NAME)

#define __AUX_BRIDGE_CLASS_DECL__(NAME, STATIC_FIELDS...) \
  __AUX_CLASS_DECL_BRIDGE__(NAME, STATIC_FIELDS) \

#define __AUX_BRIDGE_CLASS_DECL_EXP__(NAME, STATIC_FIELDS...) \
  __AUX_BRIDGE_CLASS_DECL__(NAME, STATIC_FIELDS) \

// Name, Static Fields
#define BridgeClass(NAME...) \
  __AUX_BRIDGE_CLASS_DECL_EXP__(ARG1_VA_ARGS(NAME), ARG1_VA_ARGS_VA(NAME, ;))

#define __AUX_BRIDGE_END__(NAME, MASK, EXPR...) \
  __BRIDGE_CLASS_DEFINE_MACRO__(NAME, MASK, EXPR)

// Base, Name, Type(Mask: 0 for default), EXPR for static init
#define DefClass(BASE, NAME, TYPE, EXPR...) \
  __GENERIC_CLASS_DEFINE_MACRO__(NAME, BASE, TYPE, EXPR)

// Base, Name, Type(Mask: 0 for default), EXPR for static init
#define DefBridgeClass(NAME, TYPE, EXPR...) \
  __AUX_BRIDGE_END__(NAME, TYPE, STATIC | BARE, EXPR)


#define CLS(CLASS_NAME...) (__AUX_CLS_ALLOCA__(CLASS_NAME))

#define COPY(CLASS_NAME, ARGS) (__AUX_CLS_COPY__(CLASS_NAME, ARGS))

#define NEW(CLASS_NAME...) (__AUX_CLS_MALLOC__(CLASS_NAME))

#define NEW_VCLASS(CLASS_NAME) __aux_class_new_vclass__(&__##CLASS_NAME##_ClassObject__)

__Interface__* create_class(class_field_t* fields);
void* create_instance(type_object_t* type);
