#include "../oop/class.h"
#pragma once

typedef void*(*alloc_function_t)(size_t);
typedef void*(*free_function_t)(void*);

Class(
  DefaultBase
  ,
  allocator_t
  ,
  alloc_function_t alloc_fn;
  free_function_t free_fn
);

extern allocator_t default_allocator;

DEF_METHODS(__new__, __delete__, __init__, __destroy__, )
