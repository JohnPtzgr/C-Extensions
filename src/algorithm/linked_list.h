#include "../oop/class.h"
#pragma once

Class(
  DefaultBase
  ,
  linked_list_node_t
  ,
  struct linked_list_node_t* next;
  char value;
)

Class(
  DefaultBase
  ,
  linked_list_t
  ,
  linked_list_node_t* head;
  size_t size;
  size_t type_size;
  ,
  generic_function_t push;
  generic_function_t pop;
)

DEF_METHODS(push, pop, __move__, __copy__, __assign__, __init__, __destroy__, \
  __iter__, __next__, __contains__, __begin__, __end__)

#define LinkedList( TYPE ) \
  CLS(linked_list_t, sizeof(TYPE));

// #define __TEMPLATE__
// #ifndef __T_ARG_A__
// #define __T_ARG_A__ size_t
// #endif // Default Interface Type
// #include "../oop/templates.h"
// void* __TEMPLATE_1(__T_ARG_A__, LinkedList) (linked_list_t* self) {
//   METHOD(linked_list_t, __m_init__, self, sizeof(__T_ARG_A__))
//   __ADD_CLASS_MASK_COUNT_INSTANCES(&__linked_list_node_t_MASK);
//   return self;
// };
// #include "../oop/templates_undef.h"
