#include "allocator.h"


static void* allocator_t_new(allocator_t* self, size_t size) {
  void* data =  self->alloc_fn(size);
  if (!data) {
    if (errexc.exception_number) {
      return NULL;
    } else {
      RAISE((exception_t){.exception_number=errno});
      return NULL;
    }
  }
  return data;
}

static void* allocator_t_delete(allocator_t* self, void* data) {
  self->free_fn(data);
  PUSH_EXCEPTION(void*);
  return NULL;
}

// __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_CLASS_OBJECT__()
// __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_DEFAULT_INSTANCE__()
// __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_EXTERN_DEFAULT_V_CLASS_OBJECT__()
// __GENERIC_CLASS_SEPARATE_DEFINE_MACRO_END__(allocator_t, STATIC)

// DefClass(DefaultBase,
//   allocator_t,
//   STATIC,
//   __ON_INIT__(allocator_t) {
//     __allocator_t_Default_vClassObject__._f.__new__ = (generic_function_t)allocator_t_new;
//     __allocator_t_Default_vClassObject__._f.__delete__ = (generic_function_t)allocator_t_delete;
//   }
// )

__ClassObject__ __allocator_t_ClassObject__ = (__ClassObject__){.mask=1,
  .instance_size=sizeof(allocator_t_S),
  .vclass_size=sizeof(__allocator_t_vClassObject__),
  .default_vcls=(__vClassObject__*)&__allocator_t_Default_vClassObject__,
  .default_instance=(__ClassInstance__*)&__allocator_t_Default_Instance__,
  .name="allocator_t", .__vcls_cls__=&__allocator_t_Default_vClassObject__.cls,
  .fields=(class_field_t**)&__allocator_t_fields__,
  .static_fields=(class_field_t**)&__allocator_t_static_fields__,
  .__static_init__=(generic_function_t)__allocator_t_static_init__,
  .__static_destroy__=(generic_function_t)__allocator_t_static_destroy__};
__allocator_t_vClassObject__ __allocator_t_Default_vClassObject__ = \
    (__allocator_t_vClassObject__){
        .__init__=(generic_function_t)allocator_t_init,
        .__destroy__=(generic_function_t)allocator_t_destroy,
        .cls=&__allocator_t_ClassObject__,
        .__meta__.__protected__=(__vClassObjectPrt__*)&(__allocator_t_Default_vClassObject__.__meta__.__prot_vcls_data__),
        .__base__=&__DefaultBase_Default_vClassObject__,
        ._f.__new__=(generic_function_t)allocator_t_new,
        ._f.__delete__=(generic_function_t)allocator_t_delete,
    };
allocator_t_S __allocator_t_Default_Instance__ = (allocator_t_S){};
type_object_t __allocator_t_type__ = (type_object_t){.type_mask=1,
  .type_size=sizeof(allocator_t_S),
  .type_meta=(__ClassMetaObject__*)&__allocator_t_Default_vClassObject__,
  .type_name="allocator_t"};
type_object_t* allocator_t_type = &__allocator_t_type__;
__InheritanceList__ __allocator_t__InheritanceList__ = (__InheritanceList__){};
__InheritanceListNode__ __allocator_t__InheritanceListNodes__[8] = {};
class_field_t __allocator_t_fields__[sizeof(__allocator_t_fields__) / sizeof(class_field_t)] = {};
class_field_t __allocator_t_static_fields__[sizeof(__allocator_t_static_fields__) / sizeof(class_field_t)] = {};
void* __allocator_t_static_init__(allocator_t_S* self) { *self = (allocator_t_S){};
  __DefaultBase_ClassObject__.__static_init__((void*)self);
  if (!__GET_CLASS_MASK_WAS_STATIC_INIT__(&(__allocator_t_ClassObject__.mask))) {
    if ((void*)self != (void*)&__allocator_t_Default_Instance__) {
      __allocator_t_static_init__((void*)&__allocator_t_Default_Instance__);
    } else {
      if (!__allocator_t_ClassObject__.inherits_from) {
        __allocator_t_ClassObject__.inherits_from = &__allocator_t__InheritanceList__;
        __InheritanceList_init__(__allocator_t_ClassObject__.inherits_from,
                                 __allocator_t__InheritanceListNodes__);
        __InheritanceList_add__(__allocator_t_ClassObject__.inherits_from,
                                (void*)self,
                                (void*)self + sizeof(void*),
                                &__DefaultBase_ClassObject__);
      }
      __scope_object_push__(&(*__aux_mt_scope_object_inst_location__()),
                            (void*)(&__allocator_t_ClassObject__),
                            (generic_function_t)(__class_destroy__), 0);
      __scope_object_defer__(&(*__aux_mt_scope_object_inst_location__()), (void*)(&__allocator_t_ClassObject__), (generic_function_t)(__class_destroy__), (generic_function_t)(__DEFAULT_PREDICATE__), 0);
    }
  };
  if (!__GET_CLASS_MASK_IS_BARE__(&(__allocator_t_ClassObject__.mask))) {
    *(void**)(&self->__meta__) = (void*)&__allocator_t_Default_vClassObject__;
  }
  if ((void*)self != (void*)&__allocator_t_Default_Instance__) {
    __scope_object_push__(&(*__aux_mt_scope_object_inst_location__()), (void*)(self), (generic_function_t)(__allocator_t_static_destroy__), 0);
  }
  if (!__GET_CLASS_MASK_WAS_INIT__(&(__allocator_t_ClassObject__.mask))) {
    __allocator_t_Default_vClassObject__._f.__new__ = (generic_function_t)allocator_t_new;
    __allocator_t_Default_vClassObject__._f.__delete__ = (generic_function_t)allocator_t_delete;
  };
  if (!__GET_CLASS_MASK_WAS_STATIC_INIT__(&(__allocator_t_ClassObject__.mask))) {
    __SET_CLASS_MASK_WAS_STATIC_INIT__(&(__allocator_t_ClassObject__.mask), TRUE);
    __class_inherit_static__(&__allocator_t_ClassObject__);
    if (__allocator_t_ClassObject__.__class_object_init__) {
      __allocator_t_ClassObject__.__class_object_init__(&__allocator_t_ClassObject__);
    }
  };
  return self;
} void* __allocator_t_static_destroy__(allocator_t_S* self)
DEFAULT_DESTROY(allocator_t)

void* allocator_t_init(allocator_t* self, ...) {
  __AUX_INIT_BEGIN__(allocator_t)
  __M_VA_ARG__(2, malloc, free)
  switch (__ARG_CNT__)
  {
  case 1:
    if (__ARG_LIST__[0] == INVALID) {
      __ARG_LIST__[0] = malloc;
    }
    break;
  
  case 2:
    if (__ARG_LIST__[1] == INVALID) {
      __ARG_LIST__[1] = free;
    }
    break;
  
  default:
    break;
  }
  self->alloc_fn = (alloc_function_t)__ARG_LIST__[0];
  self->free_fn = (free_function_t)__ARG_LIST__[1];
  __AUX_INIT_END__(allocator_t)
}

allocator_t default_allocator = (allocator_t){.alloc_fn=(alloc_function_t)malloc,
                                              .free_fn=(free_function_t)free,
                                              .__meta__=&__allocator_t_Default_vClassObject__};
