#include "allocator.h"

DEF_CLASS(smartptr_t
  ,
  void* data
  ,
  allocator_t allocator;
  generic_function_t make_unique;
  generic_function_t make_shared;
  generic_function_t make_weak;
)

#define Smart_ptr()

DEF_CLASS(uniqueptr_t
  ,
  void* data
  ,
  allocator_t allocator;
  generic_function_t make_shared;
  generic_function_t make_weak;
)

DEF_CLASS(sharedptr_t
  ,
  void* data
  ,
  allocator_t allocator;
  generic_function_t make_unique;
  generic_function_t make_weak;
)

DEF_CLASS(weakptr_t
  ,
  void* data
  ,
  allocator_t allocator;
  generic_function_t make_unique;
  generic_function_t make_shared;
)