#include "smart_ptr.h"


static void* smartptr_alloc(smartptr_t* self, size_t size) {
  allocator_t allocator = self->__meta__->allocator;
  self->data = allocator.__meta__->_f.__new__(&allocator,
                                              size + 2 * sizeof(int),
                                              0) + \
               2 * sizeof(int);
  EXCTH_ASSERT(void*, self->data);
  PUSH_EXCEPTION(void*)
  return self;
}

static void smartptr_free(smartptr_t* self) {
  if (!self->data) {
    return;
  }
  allocator_t allocator = self->__meta__->allocator;
  allocator.__meta__->_f.__delete__(&allocator,
                                    self->data - 2 * sizeof(int),
                                    0);
}

static void* smartptr_call(smartptr_t* self, size_t size) {
  if (self->data) {
    smartptr_free(self);
  }
  PUSH_EXCEPTION(void*);
  if (size) {
    smartptr_alloc(self, size);
  }
  PUSH_EXCEPTION(void*);
  return self;
}

DefClass(DefaultBase,
  smartptr_t,
  STATIC,
  __ON_INIT__(smartptr_t,
    allocator_t_init(&self->__meta__->allocator);
    allocator_t allocator = self->__meta__->allocator;
    self->__meta__->_f.__new__ = \
        (generic_function_t)allocator.__meta__->_f.__new__;
    self->__meta__->_f.__delete__ = \
        (generic_function_t)allocator.__meta__->_f.__delete__;
    self->__meta__->_f.__call__ = (generic_function_t)smartptr_call;
    self->__meta__->alloc = smartptr_alloc;
    self->__meta__->free = smartptr_free;
    self->__meta__->make_unique = NULL;
    self->__meta__->make_shared = NULL;
  )
  self->data = NULL;
) {
  return NULL;
}

void* smartptr_t_destroy(smartptr_t_S* self, ...) {
  if (!self->data) {
    return NULL;
  }
  smartptr_free(self);
  PUSH_EXCEPTION(void*);
  self->data = NULL;
  return NULL;
}

void* smartptr_t_init(smartptr_t_S* self, ...) {
  __AUX_INIT_BEGIN__(smartptr_t)
  __M_VA_ARG__(2, 0, 0);
  if (!__ARG_LIST__[1]) {
    self->__meta__ = (__smartptr_t_vClassObject__*)__aux_class_new_vclass__(&__smartptr_t_ClassObject__);
    memcpy(&self->__meta__->allocator, __ARG_LIST__[1], sizeof(allocator_t));
  }
  PUSH_EXCEPTION(void*);
  if (!__ARG_LIST__[0]) {
    smartptr_new(self, *(size_t*)&__ARG_LIST__[0]);
  }
  PUSH_EXCEPTION(void*);
  __AUX_INIT_END__(smartptr_t)
}


static void* uniqueptr_alloc(uniqueptr_t_S* self, size_t size) {
  allocator_t allocator = self->__meta__->allocator;
  self->data = allocator.__meta__->_f.__new__(&allocator, size, 0);
  EXCTH_ASSERT(void*, self->data);
  PUSH_EXCEPTION(void*)
  return self;
}

static void uniqueptr_free(uniqueptr_t_S* self) {
  if (!self->data) {
    return;
  }
  allocator_t allocator = self->__meta__->allocator;
  allocator.__meta__->_f.__delete__(&allocator, self->data, 0);
}

static void* uniqueptr_call(uniqueptr_t_S* self, size_t size) {
  allocator_t allocator = self->__meta__->allocator;
  if (self->data) {
    allocator.__meta__->_f.__delete__(&allocator, self->data, 0);
  }
  PUSH_EXCEPTION(void*);
  if (size) {
    self->data = allocator.__meta__->_f.__new__(&allocator, size, 0);
  }
  PUSH_EXCEPTION(void*);
  return self;
}

static void* uniqueptr_copy(uniqueptr_t_S* self, uniqueptr_t_S* other) {
  *self = *other;
  other->data = 0;
  return self;
}

DefClass(DefaultBase,
  uniqueptr_t,
  STATIC,
  __ON_INIT__(uniqueptr_t,
    allocator_t_init(&self->__meta__->allocator);
    allocator_t allocator = self->__meta__->allocator;
    self->__meta__->_f.__new__ = \
        (generic_function_t)allocator.__meta__->_f.__new__;
    self->__meta__->_f.__delete__ = \
        (generic_function_t)allocator.__meta__->_f.__delete__;
    self->__meta__->_f.__call__ = (generic_function_t)ptr_call;
    self->__meta__->alloc = ptr_alloc;
    self->__meta__->free = ptr_free;
    self->__meta__->make_shared = NULL;
  )
  self->data = NULL;
) {
  return NULL;
}

void* uniqueptr_t_destroy(uniqueptr_t_S* self, ...) {
  if (!self->data) {
    return NULL;
  }
  uniqueptr_delete(self);
  PUSH_EXCEPTION(void*);
  return NULL;
}

void* smartptr_t_init(smartptr_t_S* self, ...) {
  __AUX_INIT_BEGIN__(smartptr_t)
  __M_VA_ARG__(2, 0, 0);
  if (!__ARG_LIST__[1]) {
    self->__meta__ = (__smartptr_t_vClassObject__*)__aux_class_new_vclass__(&__smartptr_t_ClassObject__);
    memcpy(&self->__meta__->allocator, __ARG_LIST__[1], sizeof(allocator_t));
  }
  PUSH_EXCEPTION(void*);
  if (!__ARG_LIST__[0]) {
    smartptr_new(self, *(size_t*)&__ARG_LIST__[0]);
  }
  PUSH_EXCEPTION(void*);
  __AUX_INIT_END__(smartptr_t)
}

void* smartptr_t_init(smartptr_t_S* self, ...) {
  __AUX_INIT_BEGIN__(smartptr_t)
  __M_VA_ARG__(2, 0, 0);
  if (!__ARG_LIST__[1]) {
    self->__meta__ = (__smartptr_t_vClassObject__*)__aux_class_new_vclass__(&__smartptr_t_ClassObject__);
    memcpy(&self->__meta__->allocator, __ARG_LIST__[1], sizeof(allocator_t));
  }
  PUSH_EXCEPTION(void*);
  if (!__ARG_LIST__[0]) {
    self->__meta__->_f.__new__(self->data, __ARG_LIST__[0]);
  }
  PUSH_EXCEPTION(void*);
  __AUX_INIT_END__(smartptr_t)
}


static void* sharedptr_alloc(smartptr_t_S* self, size_t size) {
  allocator_t allocator = self->__meta__->allocator;
  self->data = allocator.__meta__->_f.__new__(&allocator, size, 0);
  EXCTH_ASSERT(void*, self->data);
  PUSH_EXCEPTION(void*)
  return self;
}

static void sharedptr_free(smartptr_t_S* self) {
  if (!self->data) {
    return;
  }
  allocator_t allocator = self->__meta__->allocator;
  allocator.__meta__->_f.__delete__(&allocator, self->data, 0);
}

static void* sharedptr_call(smartptr_t_S* self, size_t size) {
  allocator_t allocator = self->__meta__->allocator;
  if (self->data) {
    allocator.__meta__->_f.__delete__(&allocator, self->data, 0);
  }
  PUSH_EXCEPTION(void*);
  if (size) {
    self->data = allocator.__meta__->_f.__new__(&allocator, size, 0);
  }
  PUSH_EXCEPTION(void*);
  return self;
}

DefClass(DefaultBase,
  sharedptr_t,
  STATIC,
  __ON_INIT__(sharedptr_t,
    allocator_t_init(&self->__meta__->allocator);
    allocator_t allocator = self->__meta__->allocator;
    self->__meta__->_f.__new__ = \
        (generic_function_t)allocator.__meta__->_f.__new__;
    self->__meta__->_f.__delete__ = \
        (generic_function_t)allocator.__meta__->_f.__delete__;
    self->__meta__->_f.__call__ = (generic_function_t)sharedptr_call;
    self->__meta__->alloc = sharedptr_alloc;
    self->__meta__->free = sharedptr_free;
    self->__meta__->make_unique = NULL;
  )
  self->data = NULL;
) {
  return NULL;
}

static void* weakptr_copy(weakptr_t_S* self, weakptr_t* other) {
  *self = *other;
  self->owner->counter++;
  return self;
}

DefClass(DefaultBase,
  weakptr_t,
  STATIC,
  __ON_INIT__(weakptr_t,
    self->__meta__->__copy__ = (generic_function_t)weakptr_copy;
  )
  self->data = NULL;
) {
  return NULL;
}
