#include "../oop/class.h"
#pragma once

typedef void*(*alloc_function_t)(size_t);
typedef void*(*free_function_t)(void*);

DEF_CLASS(allocator_t
  ,
  alloc_function_t alloc_fn;
  free_function_t free_fn
  ,
  generic_function_t alloc;
  generic_function_t free);