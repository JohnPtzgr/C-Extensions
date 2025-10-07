#include "container.h"
#include "../oop/iters.h"

#ifndef UCHAR_MAX
#define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
#endif // !UCHAR_MAX

static void* generic_container_t_reserve(generic_container_t* self, size_t new_capacity) {
  __smartptr_t_vClassObject__* sp_vcls = self->ptr.__meta__->vcls;
  self->capacity = new_capacity;
  if (!self->ptr.data) {
    sp_vcls->__new__(&(self->ptr), new_capacity);
    PUSH_EXCEPTION(void*);
    return self;
  }
  smartptr_t tmp_ptr = self->ptr;
  self->ptr = *(smartptr_t*)(sp_vcls->__new__(&(self->ptr), new_capacity));
  PUSH_EXCEPTION(void*);
  self->size = MIN(self->size, self->capacity);
  memcpy(self->ptr.data, tmp_ptr.data, self->size);
  sp_vcls->__delete__(&(tmp_ptr));
  PUSH_EXCEPTION(void*);
  return self;
}

void* generic_container_iter(generic_container_t* self, iterator_t* iter) {
  return iterator_t_init(iter, self->ptr, self->size);
}

void* generic_container_assign(generic_container_t* self, generic_container_t* other) {
  uniqueptr_t* uptr = self->ptr.__meta__->vcls->make_unique(&self->ptr, CLS(uniqueptr_t));
  uptr->__meta__->vcls->__assign__(uptr, &other->ptr);
  __m_assign__;
  __m_begin__;
  __m_contains__;
  __m_copy__;
  __m_data__;
  __m_end__;
  __m_getitem__;
  __m_len__;
  __m_move__;
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
  __ON_STATIC_INIT__(generic_container_t,
    self->__meta__->vcls->reserve = \
      (generic_function_t)generic_container_t_reserve;
    self->__meta__->vcls->__iter__ = \
      (generic_function_t)generic_container_iter;
  )
  return NULL;
}

void* generic_container_t_init(generic_container_t* self, ...) {
  __AUX_INIT_BEGIN__(generic_container_t)
  __M_VA_ARG__(2, 0, 0);
  smartptr_t_init(&self->ptr, __ARG_LIST__[0], __ARG_LIST__[1], 0);
  __AUX_INIT_END__(generic_container_t)
}