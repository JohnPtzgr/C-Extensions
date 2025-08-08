#include "../memory/dyn_alloc_.h"

#define __DEFAULT_VTABLE_SIZE__ 8
#define __DEFAULT_VTABLE_MLT_OFFSET__ 1
#define __VTABLE_SIZE_IS_POWER_OF_2__ TRUE

typedef struct __vTable__ __vTable__;

typedef struct __ClassObject__ __ClassObject__;

typedef struct __vClassObject__ __vClassObject__;

typedef struct __InheritanceListNode__
{
  __ClassObject__* class_object;
  struct __InheritanceListNode__* next;
} __InheritanceListNode__;


typedef struct __ClassObject__
{

  size_t size;
  __vTable__* static_vtable;
  
  size_t mask;

  size_t instance_count;
  __InheritanceListNode__* inherits_from;
  size_t inherit_count;

  __vClassObject__* vcls;

} __ClassObject__;


typedef struct __vClassObject__
{

  __ClassObject__* cls;
  
  __vTable__* vtable;

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
  generic_function_t __cmp__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __new__;
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

} __vClassObject__;

typedef struct __BaseClass__
{
  __vClassObject__* __meta__;
} __BaseClass__;

typedef struct __PRIVATE__
{
  void* data;
} __PRIVATE__;



typedef struct X
{
  __BaseClass__ __base__;
  int x;
} X;





int x(){
  X a = {};
  ((__BaseClass__*)&a)->__meta__->__add__(&a, 0);
  sizeof(__vClassObject__);
}
