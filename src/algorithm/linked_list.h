#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "../oop/classes.h"

#ifndef linked_list_t
STATIC_CLASS(linked_list_node_t,
  struct linked_list_node_t* next;
  char value,
  0
)

STATIC_CLASS(linked_list_t,
  linked_list_node_t* head;
  size_t size;
  size_t type_size;
  method_function_t push;
  method_function_t pop,
  0
)

void* linked_list_push(linked_list_t*, void*);
void* linked_list_pop(linked_list_t*, void*);
#endif


#define __TEMPLATE__
#ifndef __T_ARG_A__
#define __T_ARG_A__ size_t
#endif // Default Interface Type
#include "../oop/templates.h"
void* __TEMPLATE_1(__T_ARG_A__, LinkedList) (linked_list_t* self) {
  METHOD(linked_list_t, __m_init__, self, sizeof(__T_ARG_A__))
  __ADD_CLASS_MASK_COUNT_INSTANCES(&__linked_list_node_t_MASK);
  return self;
};
#include "../oop/templates_undef.h"

#endif
