#include "smart_ptr.h"


static void* smartptr_t_new(smartptr_t* self, size_t size) {
  allocator_t allocator = self->__meta__->vcls->allocator;
  self->data = allocator.__meta__->vcls->__new__(&allocator, size, 0);
  PUSH_EXCEPTION(void*);
  return self;
}

static void* smartptr_t_delete(smartptr_t* self) {
  if (!self->data) {
    return NULL;
  }
  allocator_t allocator = self->__meta__->vcls->allocator;
  allocator.__meta__->vcls->__delete__(&allocator, self->data, 0);
  PUSH_EXCEPTION(void*);
  return self;
}

static void* smartptr_t_call(smartptr_t* self, size_t size) {
  allocator_t allocator = self->__meta__->vcls->allocator;
  if (self->data) {
    allocator.__meta__->vcls->__delete__(&allocator, self->data, 0);
  }
  if (size) {
    self->data = allocator.__meta__->vcls->__new__(&allocator, size, 0);
  }
  return self;
}

CLASS_END(smartptr_t, STATIC,
  __ON_INIT__(smartptr_t,
    allocator_t_init(&(__smartptr_t_Default_vClassObject__.allocator));
    __smartptr_t_Default_vClassObject__.__new__ = (generic_function_t)smartptr_t_new;
    __smartptr_t_Default_vClassObject__.__delete__ = (generic_function_t)smartptr_t_delete;
  )
  self->data = NULL;
) {
  return NULL;
}

void* smartptr_t_destroy(smartptr_t* self, ...) {
  if (!self->data) {
    return NULL;
  }
  self->__meta__->vcls->__delete__(self->data);
  PUSH_EXCEPTION(void*);
  return NULL;
}

void* smartptr_t_init(smartptr_t* self, ...) {
  __AUX_INIT_BEGIN__(smartptr_t)
  __M_VA_ARG__(2, 0, 0);
  if (!__ARG_LIST__[1]) {
    self->__meta__ = (__smartptr_t_ClassMetaData__*)__aux_class_new_meta__(&__smartptr_t_ClassObject__);
    self->__meta__->vcls = (__smartptr_t_vClassObject__*)__aux_class_new_vclass__(&__smartptr_t_ClassObject__);
    memcpy(&self->__meta__->vcls->allocator, __ARG_LIST__[1], sizeof(allocator_t));
  }
  if (!__ARG_LIST__[0]) {
    self->__meta__->vcls->__new__(self->data, __ARG_LIST__[0]);
  }
  __AUX_INIT_END__(smartptr_t)
}

CLASS_END(uniqueptr_t, STATIC,
  __ON_INIT__(uniqueptr_t,
    allocator_t_init(&(__smartptr_t_Default_vClassObject__.allocator));
    __smartptr_t_Default_vClassObject__.__new__ = (generic_function_t)smartptr_t_new;
    __smartptr_t_Default_vClassObject__.__delete__ = (generic_function_t)smartptr_t_delete;
  )
  self->data = NULL;
) {
  return NULL;
}

CLASS_END(sharedptr_t, STATIC,
  __ON_INIT__(sharedptr_t,
    allocator_t_init(&(__smartptr_t_Default_vClassObject__.allocator));
    __smartptr_t_Default_vClassObject__.__new__ = (generic_function_t)smartptr_t_new;
    __smartptr_t_Default_vClassObject__.__delete__ = (generic_function_t)smartptr_t_delete;
  )
  self->data = NULL;
) {
  return NULL;
}

CLASS_END(weakptr_t, STATIC,
  __ON_INIT__(weakptr_t,
    allocator_t_init(&(__smartptr_t_Default_vClassObject__.allocator));
    __smartptr_t_Default_vClassObject__.__new__ = (generic_function_t)smartptr_t_new;
    __smartptr_t_Default_vClassObject__.__delete__ = (generic_function_t)smartptr_t_delete;
  )
  self->data = NULL;
) {
  return NULL;
}
