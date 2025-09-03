#include "container.h"

void* smartptr_t_alloc(smartptr_t* self, size_t size) {
  allocator_t allocator = ((__smartptr_t_vClassObject__*)self->__base__.__meta__->vcls)->allocator;
  self->data = ((__allocator_t_vClassObject__*)(allocator.__base__.__meta__->vcls))->alloc(&allocator, size, 0);
  return self;
}

void* smartptr_t_free(smartptr_t* self, size_t size) {
  if (!self->data) {
    return NULL;
  }
  allocator_t allocator = ((__smartptr_t_vClassObject__*)self->__base__.__meta__->vcls)->allocator;
  ((__allocator_t_vClassObject__*)(allocator.__base__.__meta__->vcls))->free(&allocator, 0);
  return self;
}

CLASS_END(smartptr_t, STATIC,
  __ON_INIT__(smartptr_t,
    allocator_t_init(&(__smartptr_t_Default_vClassObject__.allocator));
    __smartptr_t_Default_vClassObject__.alloc = (generic_function_t)smartptr_t_alloc;
    __smartptr_t_Default_vClassObject__.free = (generic_function_t)smartptr_t_free;
  )
  self->data = NULL;
) {
  return NULL;
}

void* smartptr_t_destroy(smartptr_t* self, ...) {
  if (!self->data) {
    return NULL;
  }
  return ((__smartptr_t_vClassObject__*)(self->__base__.__meta__->vcls))->free(self->data);
}

void* smartptr_t_init(smartptr_t* self, ...) {
  __AUX_INIT_BEGIN__(smartptr_t)
  __M_VA_ARG__(1, 0);
  if (!__ARG_LIST__[0]) {
    ((__smartptr_t_vClassObject__*)(self->__base__.__meta__->vcls))->alloc(self->data, __ARG_LIST__[0]);
  }
  __AUX_INIT_END__(smartptr_t)
}


void* generic_container_t_reserve(generic_container_t* self, size_t new_capacity) {
  if (!self->ptr.data) {
    ((__smartptr_t_vClassObject__*)(self->ptr.__base__.__meta__->vcls))->alloc(&(self->ptr), self->type_size * new_capacity);
  }
  smartptr_t tmp_ptr = self->ptr;
  self->ptr = *(smartptr_t*)(((__smartptr_t_vClassObject__*)(self->ptr.__base__.__meta__->vcls))->alloc(&(self->ptr),
                                                                                                        new_capacity));
  memcpy(self->ptr.data, tmp_ptr.data, self->type_size * self->size);
  ((__smartptr_t_vClassObject__*)(tmp_ptr.__base__.__meta__->vcls))->free(&(tmp_ptr));
  return self;
}

CLASS_END(generic_container_t, STATIC,
  // generic_function_t reserve;
  // generic_function_t size;
  // generic_function_t release;
  // generic_function_t empty;
  // generic_function_t max_size;
  // generic_function_t clear;
  // generic_function_t insert;
  // generic_function_t erase;
  // generic_function_t push_back;
  // generic_function_t pop_back,
  // smartptr_t ptr;
  // size_t size;
  // size_t capacity;
  // size_t type_size;
) {
  ((__generic_container_t_vClassObject__*)(self->__base__.__meta__->vcls))->reserve = \
    (generic_function_t)generic_container_t_reserve;
  return NULL;
}

void* generic_container_t_init(generic_container_t* self, ...) {
  __AUX_INIT_BEGIN__(generic_container_t)
  __M_VA_ARG__(3, (void*)1, 0, 0);
  self->type_size = (size_t)__ARG_LIST__[0];
  self->size = (size_t)__ARG_LIST__[1];
  if (__ARG_LIST__[2] && __ARG_LIST__[2] != INVALID) {
    self->ptr.__base__.__meta__->vcls = (__vClassObject__*)__aux_class_new_vclass__( \
      self->ptr.__base__.__meta__->vcls->cls);
    ((__smartptr_t_vClassObject__*)(self->ptr.__base__.__meta__->vcls))->allocator = \
      *(allocator_t*)__ARG_LIST__[2];
  }
  __AUX_INIT_END__(generic_container_t)
}