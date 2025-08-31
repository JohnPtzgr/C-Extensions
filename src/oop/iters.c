#include "iters.h"

iterator_t* iterator_t_next(iterator_t* self) {
  if (!self) {
    return NULL;
  }
  self->cur_ptr += self->step;
  if (self->max_ptr) {
    if (self->cur_ptr >= self->max_ptr) {
      return NULL;
    }
  } else {
    BOOL stop = 0;
    for (size_t i = 0; i < self->step; ++i) {
      stop |= (((char*)(self->cur_ptr))[i] != 0);
    }
    if (!stop) {
      return NULL;
    }
  }
  return self;
}

iterator_t* iterator_t_prev(iterator_t* self) {
  if (!self) {
    return NULL;
  }
  self->cur_ptr -= self->step;
  return self;
}

CLASS_END(iterator_t,
  STATIC,
  __ON_INIT__(iterator_t,
    __iterator_t_Default_vClassObject__.__inc__ = (generic_function_t)iterator_t_next;
    __iterator_t_Default_vClassObject__.__dec__ = (generic_function_t)iterator_t_prev;
  )
) DEFAULT_DESTROY(iterator_t)

void* iterator_t_init(iterator_t* self, ...) {
  __AUX_INIT_BEGIN__(iterator_t)
  __M_VA_ARG__(3, NULL, (void*)1, NULL);
  self->cur_ptr = __ARG_LIST__[0];
  self->step = (size_t)__ARG_LIST__[1];
  self->max_ptr = __ARG_LIST__[2];
  __AUX_INIT_END__(iterator_t)
}