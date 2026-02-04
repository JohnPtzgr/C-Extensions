#include "smart_ptr.h"
#include "pthread.h"


static void* smartptr_alloc(smartptr_t* self, size_t size) {
  allocator_t* allocator = self->__meta__->allocator;
  self->data = allocator->__meta__->_f.__new__(allocator,
                                               size,
                                               0);
  EXC_ASSERT(self->data);
  PUSH_EXCEPTION(void*);
  return self;
}

static void smartptr_free(smartptr_t* self) {
  if (!self->data) {
    return;
  }
  allocator_t* allocator = self->__meta__->allocator;
  allocator->__meta__->_f.__delete__(allocator,
                                     self->data,
                                     0);
  if (errchk) {
    return;
  }
  self->data = NULL;
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

static void* smartptr_copy(smartptr_t_S* self, smartptr_t_S* other) {
  __AUX_INIT_BEGIN__(smartptr_t)
  *self = *other;
  other->data = 0;
  __AUX_INIT_END__(smartptr_t)
}

static anyptr_t smartptr_make_unique(smartptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  uniqueptr_t* ptr = CLS(uniqueptr_t,
                         self->data,
                         self->__meta__->allocator);
  self->data = NULL;
  Static_Cast(uniqueptr_t, container_ptr.unique) = *ptr;
  return container_ptr;
}

static anyptr_t smartptr_make_shared(smartptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  sharedptr_t* ptr = CLS(sharedptr_t,
                         self->data,
                         self->__meta__->allocator);
  self->data = NULL;
  Static_Cast(sharedptr_t, container_ptr.shared) = *ptr;
  return container_ptr;
}

static anyptr_t smartptr_link_weak(smartptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  weakptr_t* ptr = CLS(weakptr_t, self);
  Static_Cast(weakptr_t, container_ptr.weak) = *ptr;
  return container_ptr;
}

static void* smartptr_reset(smartptr_t_S* self) {
  void* ptr = self->data;
  self->data = NULL;
  return ptr;
}

DefClass(DefaultBase,
  smartptr_t,
  STATIC,
  __ON_STATIC_INIT__(smartptr_t) {
    self->__meta__->allocator = &default_allocator;
    self->__meta__->_f.__call__ = \
        (generic_function_t)smartptr_call;
    self->__meta__->alloc = smartptr_alloc;
    self->__meta__->free = smartptr_free;
    self->__meta__->make_unique = smartptr_make_unique;
    self->__meta__->make_shared = smartptr_make_shared;
    self->__meta__->link_weak = smartptr_link_weak;
    self->__meta__->reset = smartptr_reset;
  }
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
  return NULL;
}

void* __aux_smartptr_set_allocator(__smartptr_t_vClassObject__* meta, allocator_t* allocator) {
  if (meta->allocator != allocator) {
    if (meta->cls->alloc_vcls) {
      for (size_t i = 0; i < meta->cls->__vclass_cnt; ++i) {
        if (((__smartptr_t_vClassObject__*)meta->cls->alloc_vcls[i])->allocator == allocator) {
          return meta->cls->alloc_vcls[i];
        }
      }
    }
    __smartptr_t_vClassObject__* new_meta = (__smartptr_t_vClassObject__*)__aux_class_new_vclass__(meta->cls);
    new_meta->allocator = allocator;
    return new_meta;
  }
  return meta;
}

void* smartptr_t_init(smartptr_t_S* self, ...) {
  __AUX_INIT_BEGIN__(smartptr_t)
  __M_VA_ARG__(2, 0, 0);
  if (__ARG_LIST__[1]) {
    self->__meta__ = __aux_smartptr_set_allocator(
                        (__smartptr_t_vClassObject__*)self->__meta__,
                        __ARG_LIST__[1]
                     );
  }
  PUSH_EXCEPTION(void*);
  self->data = __ARG_LIST__[0];
  PUSH_EXCEPTION(void*);
  __AUX_INIT_END__(smartptr_t)
}


static void* uniqueptr_alloc(uniqueptr_t_S* self, size_t size) {
  allocator_t* allocator = self->__meta__->allocator;
  self->data = allocator->__meta__->_f.__new__(allocator, size, 0);
  EXCTH_ASSERT(void*, self->data);
  PUSH_EXCEPTION(void*);
  return self;
}

static void uniqueptr_free(uniqueptr_t_S* self) {
  if (!self->data) {
    return;
  }
  allocator_t* allocator = self->__meta__->allocator;
  allocator->__meta__->_f.__delete__(allocator, self->data, 0);
  if (errchk) {
    return;
  }
  self->data = NULL;
}

static void* uniqueptr_call(uniqueptr_t_S* self, size_t size) {
  allocator_t* allocator = self->__meta__->allocator;
  if (self->data) {
    allocator->__meta__->_f.__delete__(allocator, self->data, 0);
  }
  PUSH_EXCEPTION(void*);
  if (size) {
    self->data = allocator->__meta__->_f.__new__(allocator, size, 0);
  }
  PUSH_EXCEPTION(void*);
  return self;
}

static void* uniqueptr_copy(uniqueptr_t_S* self, uniqueptr_t_S* other) {
  __AUX_INIT_BEGIN__(uniqueptr_t)
  *self = *other;
  other->data = 0;
  __AUX_INIT_END__(uniqueptr_t)
}

static anyptr_t uniqueptr_make_smart(uniqueptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  smartptr_t* ptr = CLS(smartptr_t,
                        self->data,
                        self->__meta__->allocator);
  self->data = NULL;
  Static_Cast(smartptr_t, container_ptr.smart) = *ptr;
  return container_ptr;
}

static anyptr_t uniqueptr_make_shared(uniqueptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  sharedptr_t* ptr = CLS(sharedptr_t,
                         self->data,
                         self->__meta__->allocator);
  self->data = NULL;
  Static_Cast(sharedptr_t, container_ptr.shared) = *ptr;
  return container_ptr;
}

static anyptr_t uniqueptr_link_weak(uniqueptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  weakptr_t* ptr = CLS(weakptr_t, self);
  Static_Cast(weakptr_t, container_ptr.weak) = *ptr;
  return container_ptr;
}

static void* uniqueptr_reset(uniqueptr_t_S* self) {
  void* ptr = self->data;
  self->data = NULL;
  return ptr;
}

DefClass(DefaultBase,
  uniqueptr_t,
  STATIC,
  __ON_STATIC_INIT__(uniqueptr_t) {
    self->__meta__->allocator = &default_allocator;
    self->__meta__->_f.__call__ = \
        (generic_function_t)uniqueptr_call;
    self->__meta__->__copy__ = \
        (generic_function_t)uniqueptr_copy;
    self->__meta__->alloc = uniqueptr_alloc;
    self->__meta__->free = uniqueptr_free;
    self->__meta__->make_smart = uniqueptr_make_smart;
    self->__meta__->make_shared = uniqueptr_make_shared;
    self->__meta__->link_weak = uniqueptr_link_weak;
    self->__meta__->reset = uniqueptr_reset;
  }
  self->data = NULL;
) {
  return NULL;
}

void* uniqueptr_t_destroy(uniqueptr_t_S* self, ...) {
  if (!self->data) {
    return NULL;
  }
  size_t i = 0;
  while ((self->data == INVALID) && \
         (i < UNIQUEPTR_MAX_TIMEOUT_CYCLES)) {
    i++;
    sched_yield();
  }
  if (self->data == INVALID) {
    SCOPE_DEFER(self, uniqueptr_t_destroy, __FALSE_PREDICATE__);
    errexc = (exception_t){.exception_number=EDEADLK}; 
    errctx = EXCEPTION_CTX_LTR;
    strcpy(errctx.data, "Attempt to destroy resource (uniqueptr_t) caused a deadlock!\n");
    THROW(void*, errexc);
  }
  uniqueptr_free(self);
  PUSH_EXCEPTION(void*);
  return NULL;
}

void* uniqueptr_t_init(uniqueptr_t_S* self, ...) {
  __AUX_INIT_BEGIN__(uniqueptr_t)
  __M_VA_ARG__(2, 0, 0);
  if (__ARG_LIST__[1]) {
    self->__meta__ = __aux_smartptr_set_allocator(
                       (__smartptr_t_vClassObject__*)self->__meta__,
                       __ARG_LIST__[1]
                     );
  }
  PUSH_EXCEPTION(void*);
  if (__ARG_LIST__[0]) {
    self->data = __ARG_LIST__[0];
  }
  PUSH_EXCEPTION(void*);
  __AUX_INIT_END__(uniqueptr_t)
}


BareClass(
  DefaultBase,
  sharedptr_manager_t,
  size_t weak_ptr_counter;
  size_t shared_ptr_counter;
  pthread_mutex_t mutex;
)

void* sharedptr_manager_t_init(sharedptr_manager_t* self, ... ) {
  pthread_mutex_init(&self->mutex, NULL);
  return self;
}

void* sharedptr_manager_t_destroy(sharedptr_manager_t* self, ... ) {
  pthread_mutex_destroy(&self->mutex);
  return self;
}

void sharedptr_manager_add_shared(sharedptr_manager_t* self) {
  pthread_mutex_lock(&self->mutex);
  self->shared_ptr_counter++;
  pthread_mutex_unlock(&self->mutex);
}

void sharedptr_manager_add_weak(sharedptr_manager_t* self) {
  pthread_mutex_lock(&self->mutex);
  self->weak_ptr_counter++;
  pthread_mutex_unlock(&self->mutex);
}

BOOL sharedptr_manager_sub_shared(sharedptr_manager_t* self) {
  pthread_mutex_lock(&self->mutex);
  self->shared_ptr_counter--;
  if (!self->shared_ptr_counter) {
    return TRUE;
  }
  pthread_mutex_unlock(&self->mutex);
  return FALSE;
}

BOOL sharedptr_manager_sub_weak(sharedptr_manager_t* self) {
  pthread_mutex_lock(&self->mutex);
  self->weak_ptr_counter--;
  pthread_mutex_unlock(&self->mutex);
  return !self->weak_ptr_counter;
}

DefClass(
  DefaultBase,
  sharedptr_manager_t,
  STATIC | BARE,
  self->shared_ptr_counter = 0;
  self->weak_ptr_counter = 0;
) {
  return NULL;
}


static void* sharedptr_alloc(sharedptr_t_S* self, size_t size) {
  allocator_t* allocator = self->__meta__->allocator;
  self->data = allocator->__meta__->_f.__new__(allocator, size, 0);
  EXCTH_ASSERT(void*, self->data);
  PUSH_EXCEPTION(void*);
  return self;
}

static void sharedptr_free(sharedptr_t_S* self) {
  if (!self->data) {
    return;
  }
  allocator_t* allocator = self->__meta__->allocator;
  allocator->__meta__->_f.__delete__(allocator, self->data, 0);
  if (errchk) {
    return;
  }
  self->data = NULL;
}

static void* sharedptr_call(sharedptr_t_S* self, size_t size) {
  allocator_t* allocator = self->__meta__->allocator;
  if (self->data) {
    allocator->__meta__->_f.__delete__(allocator, self->data, 0);
  }
  PUSH_EXCEPTION(void*);
  if (size) {
    self->data = allocator->__meta__->_f.__new__(allocator, size, 0);
  }
  PUSH_EXCEPTION(void*);
  return self;
}

static void* sharedptr_copy(sharedptr_t_S* self, sharedptr_t_S* other) {
  __AUX_INIT_BEGIN__(sharedptr_t)
  *self = *other;
  sharedptr_manager_add_shared(self->manager);
  __AUX_INIT_END__(sharedptr_t)
}

static anyptr_t sharedptr_make_smart(sharedptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  if (self->__meta__->unique(self)) {
    smartptr_t* ptr = CLS(smartptr_t,
                          self->data,
                          self->__meta__->allocator);
    self->data = NULL;
    Static_Cast(smartptr_t, container_ptr.smart) = *ptr;
  }
  return container_ptr;
}

static anyptr_t sharedptr_make_unique(sharedptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  if (self->__meta__->unique(self)) {
    uniqueptr_t* ptr = CLS(uniqueptr_t,
                           self->data,
                           self->__meta__->allocator);
    self->data = NULL;
    Static_Cast(uniqueptr_t, container_ptr.unique) = *ptr;
  }
  return container_ptr;
}

static anyptr_t sharedptr_link_weak(sharedptr_t* self) {
  anyptr_t container_ptr = (anyptr_t){};
  weakptr_t* ptr = CLS(weakptr_t, self);
  sharedptr_manager_add_weak(self->manager);
  Static_Cast(weakptr_t, container_ptr.weak) = *ptr;
  return container_ptr;
}

BOOL sharedptr_unique(sharedptr_t* self) {
  return self->manager->shared_ptr_counter < 2;
}

void* sharedptr_reset(sharedptr_t* self) {
  void* ptr = self->data;
  if (sharedptr_manager_sub_shared(self->manager)) {
    pthread_mutex_unlock(&self->manager->mutex);
    free(self->manager);
  }
  self->data = NULL;
  self->manager = NULL;
  return ptr;
}

size_t sharedptr_ref_count(sharedptr_t* self) {
  return self->manager->shared_ptr_counter;
}

size_t sharedptr_weak_ref_count(sharedptr_t* self) {
  return self->manager->weak_ptr_counter;
}

void* sharedptr_get(sharedptr_t* self) {
  self->data;
}

DefClass(DefaultBase,
  sharedptr_t,
  STATIC,
  __ON_STATIC_INIT__(sharedptr_t) {
    self->__meta__->allocator = &default_allocator;
    self->__meta__->_f.__call__ = (generic_function_t)sharedptr_call;
    self->__meta__->alloc = sharedptr_alloc;
    self->__meta__->free = sharedptr_free;
    self->__meta__->make_unique = sharedptr_make_unique;
    self->__meta__->make_smart = sharedptr_make_smart;
    self->__meta__->link_weak = sharedptr_link_weak;
    self->__meta__->reset = sharedptr_reset;
    self->__meta__->unique = sharedptr_unique;
    self->__meta__->ref_count = sharedptr_ref_count;
    self->__meta__->weak_ref_count = sharedptr_weak_ref_count;
    self->__meta__->get = sharedptr_get;
  }
  self->data = NULL;
) {
  return NULL;
}

void* sharedptr_t_destroy(sharedptr_t_S* self, ...) {
  if (!self->data) {
    return NULL;
  }
  if (sharedptr_manager_sub_shared(self->manager)) {
    sharedptr_free(self);
    pthread_mutex_unlock(&self->manager->mutex);
    free(self->manager);
  }
  PUSH_EXCEPTION(void*);
  return NULL;
}

void* sharedptr_t_init(sharedptr_t_S* self, ...) {
  __AUX_INIT_BEGIN__(sharedptr_t)
  __M_VA_ARG__(2, 0, 0);
  if (__ARG_LIST__[1]) {
    self->__meta__ = __aux_smartptr_set_allocator(
                       (__smartptr_t_vClassObject__*)self->__meta__,
                       __ARG_LIST__[1]
                     );
  }
  PUSH_EXCEPTION(void*);
  if (__ARG_LIST__[0]) {
    self->data = __ARG_LIST__[0];
  }
  PUSH_EXCEPTION(void*);
  self->manager = (sharedptr_manager_t*)sharedptr_manager_t_init(
                    calloc(1, sizeof(sharedptr_manager_t)),
                    0
                  );
  __AUX_INIT_END__(sharedptr_t)
}


static void* weakptr_copy(weakptr_t_S* self, weakptr_t* other) {
  __AUX_INIT_BEGIN__(weakptr_t)
  *self = *other;
  __AUX_INIT_END__(weakptr_t)
}

void weakptr_update(weakptr_t* self) {
  self->data = self->owner.smart->data;
}

BOOL weakptr_expired(weakptr_t* self) {
  weakptr_update(self);
  return !self->data;
}

void* weakptr_reset(weakptr_t* self) {
  void* ptr = self->data;
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __sharedptr_manager_t_ClassObject__.name)) {
    sharedptr_manager_sub_weak(self->owner.shared->manager);
  }
  self->data = NULL;
  self->owner.smart = NULL;
  return ptr;
}

void weakptr_lock(weakptr_t* self) {
  weakptr_update(self);
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __smartptr_t_ClassObject__.name)) {
    return;
  }
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __uniqueptr_t_ClassObject__.name)) {          
    self->owner.unique->data = INVALID;
    return;
  }
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __sharedptr_t_ClassObject__.name)) {
    return;
  }
}

void weakptr_unlock(weakptr_t* self) {
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __smartptr_t_ClassObject__.name)) {
    return;
  }
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __uniqueptr_t_ClassObject__.name)) {
    self->owner.unique->data = self->data;
    return;
  }
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __sharedptr_t_ClassObject__.name)) {
    return;
  }
}

void* weakptr_get(weakptr_t* self) {
  weakptr_update(self);
  return self->data;
}

DefClass(DefaultBase,
  weakptr_t,
  STATIC | BARE,
  __ON_STATIC_INIT__(weakptr_t) {
    __weakptr_t_Default_vClassObject__.__copy__ = (generic_function_t)weakptr_copy;
    __weakptr_t_Default_vClassObject__.update = weakptr_update;
    __weakptr_t_Default_vClassObject__.expired = weakptr_expired;
    __weakptr_t_Default_vClassObject__.get = weakptr_get;
    __weakptr_t_Default_vClassObject__.reset = weakptr_reset;
    __weakptr_t_Default_vClassObject__.lock = weakptr_lock;
    __weakptr_t_Default_vClassObject__.unlock = weakptr_unlock;
  }
  self->data = NULL;
) {
  return NULL;
}

void* weakptr_t_init(weakptr_t* self, ... ) {
  __AUX_INIT_BEGIN__(weakptr_t)
  __M_VA_ARG__(2, 0);
  PUSH_EXCEPTION(void*);
  if (__ARG_LIST__[0]) {
    self->owner.smart = (smartptr_t*)__ARG_LIST__[0];
    self->data = self->owner.smart->data;
  }
  PUSH_EXCEPTION(void*);
  __AUX_INIT_END__(weakptr_t)
}

void* weakptr_t_destroy(weakptr_t* self, ... ) {
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __smartptr_t_ClassObject__.name)) {
    return NULL;
  }
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __uniqueptr_t_ClassObject__.name)) {
    return NULL;
  }
  if (!strcmp(self->owner.smart->__meta__->cls->name,
              __sharedptr_t_ClassObject__.name)) {
    sharedptr_manager_sub_weak(self->owner.shared->manager);
    return NULL;
  }
}

