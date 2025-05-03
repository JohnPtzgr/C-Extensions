#include "../oop/classes.h"

#ifndef linked_list_t
STATIC_CLASS(linked_list_node_t,
  linked_list_node_t* next;
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
void* __TEMPLATE_1(__T_ARG_A__, LinkedList) (linked_list_t*);
#include "../oop/templates_undef.h"
