#include "allocator.h"
#pragma once

#ifndef UCHAR_MAX
#define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
#endif // !UCHAR_MAX

DEF_CLASS(smartptr_t,
  generic_function_t alloc;
  generic_function_t free;
  allocator_t allocator;,
  void* data)

#define Smart_ptr() 

DEF_CLASS(generic_container_t,
  generic_function_t reserve;
  generic_function_t size;
  generic_function_t release;
  generic_function_t empty;
  generic_function_t max_size;
  generic_function_t clear;
  generic_function_t insert;
  generic_function_t erase;
  generic_function_t push_back;
  generic_function_t pop_back,
  smartptr_t ptr;
  size_t size;
  size_t capacity;
  size_t type_size;)

