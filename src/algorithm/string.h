#include "container.h"

DEF_CLASS(string_t
  ,
  smartptr_t data,
  size_t size,
  size_t capacity
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