#include "allocator.h"
#include "../oop/iters.h"
#pragma once

#ifndef UCHAR_MAX
#define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
#endif // !UCHAR_MAX

DEF_CLASS(smartptr_t
  ,
  void* data
  ,
  generic_function_t alloc;
  generic_function_t free;
  allocator_t allocator;
)

#define Smart_ptr() 

DEF_CLASS(generic_container_t
  ,
  smartptr_t ptr;
  size_t size;
  size_t capacity;
  ,
  generic_function_t reserve;
  generic_function_t size;
  generic_function_t release;
  generic_function_t empty;
  generic_function_t max_size;
  generic_function_t clear;
  generic_function_t insert;
  generic_function_t erase;
  generic_function_t push_back;
  generic_function_t pop_back;
  generic_function_t append;
  generic_function_t find;
  generic_function_t rfind;
  generic_function_t slice;
)

