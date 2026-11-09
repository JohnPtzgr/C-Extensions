#include "smart_ptr.h"
#pragma once


Class(
  DefaultBase
  ,
  generic_container_t
  ,
  void* ptr;
  size_t size;
  size_t capacity;
  ,
  allocator_t* allocator;
  void (*reserve)(generic_container_t* self, size_t type_size, size_t capacity);
  size_t (*size)(generic_container_t* self, size_t type_size);
  void (*release)(generic_container_t* self);
  BOOL (*empty)(generic_container_t* self);
  size_t (*max_size)(generic_container_t* self, size_t type_size);
  void (*clear)(generic_container_t* self);
  void* (*insert)(generic_container_t* self, size_t type_size, size_t index, void* data);
  void (*erase)(generic_container_t* self, size_t type_size, void* data);
  void (*push_back)(generic_container_t* self, size_t type_size, void* data);
  void (*emplace_back)(generic_container_t* self, type_object_t* type, ... );
  void (*pop_back)(generic_container_t* self, size_t type_size);
  void (*append)(generic_container_t* self, generic_container_t* other);
  size_t (*find)(generic_container_t* self, size_t type_size, void* data);
  size_t (*rfind)(generic_container_t* self, size_t type_size, void* data);
  void* (*slice)(generic_container_t* self, size_t type_size, generic_container_t* slice_container, size_t begin, size_t end, size_t step);
)

DEF_METHODS(__move__, __copy__, __assign__, __init__, __destroy__, \
  __iter__, __next__, __contains__, __begin__, __end__)

