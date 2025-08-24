#include "functional.h"


void* callable_method_call(callable_t* self, ...) {
  __M_VA_ARG__(16);
  switch (__ARG_CNT__) {
    case 0:
      return self->func_ptr(0);
    case 1:
      return self->func_ptr(__ARG_LIST__[0], 0);
    case 2:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], 0);
    case 3:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], 0);
    case 4:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], 0);
    case 5:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], 0);
    case 6:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], 0);
    case 7:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], 0);
    case 8:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], 0);
    case 9:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], 0);
    case 10:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], 0);
    case 11:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], 0);
    case 12:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], 0);
    case 13:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], 0);
    case 14:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], 0);
    case 15:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], \
        __ARG_LIST__[14], 0);
    case 16:
      return self->func_ptr(__ARG_LIST__[0], __ARG_LIST__[1], \
        __ARG_LIST__[2], __ARG_LIST__[3], __ARG_LIST__[4], \
        __ARG_LIST__[5], __ARG_LIST__[6], __ARG_LIST__[7], \
        __ARG_LIST__[8], __ARG_LIST__[9], __ARG_LIST__[10], \
        __ARG_LIST__[11], __ARG_LIST__[12], __ARG_LIST__[13], \
        __ARG_LIST__[14], __ARG_LIST__[15], 0);
    
    default:
      return NULL;
  }
}

__ClassObject__ __callable_t_ClassObject__ = (__ClassObject__){.mask=1,
                                                               .size=sizeof(callable_t),
                                                               .default_vcls=(__vClassObject__*)&__callable_t_Default_vClassObject__,
                                                               .default_instance=(__ClassInstance__*)&__callable_t_Default_Instance__,
                                                               .name="callable_t",
                                                               .__static_init__=(generic_function_t)__callable_t_static_init__,
                                                               .__static_destroy__=(generic_function_t)__callable_t_static_destroy__};
__callable_t_vClassObject__ __callable_t_Default_vClassObject__ = (__callable_t_vClassObject__){.__init__=(generic_function_t)callable_t_init,
                                                                                                .__destroy__=(generic_function_t)callable_t_destroy,
                                                                                                .__call__=(generic_function_t)callable_method_call,
                                                                                                .cls=&__callable_t_ClassObject__};
callable_t __callable_t_Default_Instance__ = (callable_t){};
__ClassMetaData__ __callable_t_Default_MetaData__ = (__ClassMetaData__){.vcls=(__vClassObject__*)&__callable_t_Default_vClassObject__};
void* __callable_t_static_init__(callable_t* self) {
  if (!__GET_CLASS_MASK_WAS_INIT__(&(__callable_t_ClassObject__.mask))) {
    *self = (callable_t){};
    __scope_object_push__(&__SCOPE_OBJECT_INST__,
                          (void*)(&__callable_t_ClassObject__),
                          (generic_function_t)(__class_destroy__),
                          0);
    __scope_object_defer__(&__SCOPE_OBJECT_INST__,
                           (void*)(&__callable_t_ClassObject__),
                           (generic_function_t)(__class_destroy__),
                           (generic_function_t)(__DEFAULT_PREDICATE__),
                           0);
  }
  if (!__GET_CLASS_MASK_IS_BARE__(&(__callable_t_ClassObject__.mask))) {
    ((__ClassInstance__*)self)->__meta__ = &__callable_t_Default_MetaData__;
  }
  if (self != &__callable_t_Default_Instance__) {
    __scope_object_push__(&__SCOPE_OBJECT_INST__,
                          (void*)(self), (generic_function_t)(__callable_t_static_destroy__), 0);
  }
  if (!__GET_CLASS_MASK_WAS_INIT__(&(__callable_t_ClassObject__.mask))) {
    __callable_t_Default_vClassObject__.__call__ = (generic_function_t)callable_method_call;
  }
  return self;
}
void* __callable_t_static_destroy__(callable_t* self) DEFAULT_DESTROY(callable_t);

void* callable_t_init(callable_t* self, ...) {
  __AUX_INIT_BEGIN__(callable_t);
  __M_VA_ARG__(1, 0);
  self->func_ptr = __ARG_LIST__[0];
  __AUX_INIT_END__(callable_t);
}
