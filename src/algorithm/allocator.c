#include "allocator.h"


void* allocator_t_alloc(allocator_t* self, size_t size) {
  return self->alloc_fn(size);
}

void* allocator_t_free(allocator_t* self) {
  return self->free_fn();
}

CLASS_END(allocator_t, STATIC,
  __ON_INIT__(allocator_t,
    __allocator_t_Default_vClassObject__.alloc = (generic_function_t)allocator_t_alloc;
    __allocator_t_Default_vClassObject__.free = (generic_function_t)allocator_t_free;
  )
) DEFAULT_DESTROY(allocator_t)

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