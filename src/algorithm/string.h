#include "container.h"
#pragma once

DEF_CLASS(string_t
  ,
  smartptr_t data;
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
  generic_function_t substr;
)

DEF_METHODS(reserve, size, release, empty, max_size, clear, insert, erase, \
  push_back, pop_back, append, find, rfind, slice, substr, \
  __move__, __copy__, __assign__, __init__, __destroy__, \
  __iter__, __next__, __contains__, __begin__, __end__)