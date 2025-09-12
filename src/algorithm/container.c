#include "container.h"

static void* smartptr_t_alloc(smartptr_t* self, size_t size) {
  allocator_t allocator = ((__smartptr_t_vClassObject__*)self->__meta__->vcls)->allocator;
  self->data = ((__allocator_t_vClassObject__*)(allocator.__meta__->vcls))->alloc(&allocator, size, 0);
  PUSH_EXCEPTION(void*);
  return self;
}

static void* smartptr_t_free(smartptr_t* self) {
  if (!self->data) {
    return NULL;
  }
  allocator_t allocator = ((__smartptr_t_vClassObject__*)self->__meta__->vcls)->allocator;
  ((__allocator_t_vClassObject__*)(allocator.__meta__->vcls))->free(&allocator, self->data, 0);
  PUSH_EXCEPTION(void*);
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
  ((__smartptr_t_vClassObject__*)(self->__meta__->vcls))->free(self->data);
  PUSH_EXCEPTION(void*);
  return NULL;
}

void* smartptr_t_init(smartptr_t* self, ...) {
  __AUX_INIT_BEGIN__(smartptr_t)
  __M_VA_ARG__(1, 0);
  if (!__ARG_LIST__[0]) {
    ((__smartptr_t_vClassObject__*)(self->__meta__->vcls))->alloc(self->data, __ARG_LIST__[0]);
  }
  __AUX_INIT_END__(smartptr_t)
}


static void* generic_container_t_reserve(generic_container_t* self, size_t new_capacity) {
  __smartptr_t_vClassObject__* sp_vcls = (__smartptr_t_vClassObject__*)(self->ptr.__meta__->vcls);
  self->capacity = new_capacity;
  if (!self->ptr.data) {
    sp_vcls->alloc(&(self->ptr), self->type_size * new_capacity);
    PUSH_EXCEPTION(void*);
    return self;
  }
  smartptr_t tmp_ptr = self->ptr;
  self->ptr = *(smartptr_t*)(sp_vcls->alloc(&(self->ptr), new_capacity));
  PUSH_EXCEPTION(void*);
  self->size = MIN(self->size, self->capacity);
  memcpy(self->ptr.data, tmp_ptr.data, self->type_size * self->size);
  sp_vcls->free(&(tmp_ptr));
  PUSH_EXCEPTION(void*);
  return self;
}


void* generic_container_iter(generic_container_t* self, ...) {
  return NEW(iterator_t,
             1,
             self->ptr.data,
             (self->type_size == 0 ? 1 : self->type_size),
             self->ptr.data + self->type_size * self->size);
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
  self->__meta__->vcls->reserve = \
    (generic_function_t)generic_container_t_reserve;
  return NULL;
}

void* generic_container_t_init(generic_container_t* self, ...) {
  __AUX_INIT_BEGIN__(generic_container_t)
  __M_VA_ARG__(3, (void*)1, 0, 0);
  __smartptr_t_vClassObject__* sp_vcls = self->ptr.__meta__->vcls;
  self->type_size = (size_t)__ARG_LIST__[0];
  self->size = (size_t)__ARG_LIST__[1];
  if (__ARG_LIST__[2] && __ARG_LIST__[2] != INVALID) {
    self->ptr.__meta__->vcls = (__smartptr_t_vClassObject__*)__aux_class_new_vclass__( \
      self->ptr.__meta__->vcls->cls);
    sp_vcls->allocator = *(allocator_t*)__ARG_LIST__[2];
  }
  if (self->size) {
    self->ptr = *(smartptr_t*)(sp_vcls->alloc(&(self->ptr), self->size));
    PUSH_EXCEPTION(void*);
  }
  __AUX_INIT_END__(generic_container_t)
}