#include "linked_list.h"

CLASS_END(linked_list_node_t, ;) DEFAULT_DESTROY;

CLASS_END(linked_list_t,
  self->push = (method_function_t)linked_list_push;
  self->pop = (method_function_t)linked_list_pop;
  self->head = NULL;
  self->size = 0;
  METHOD_ARGS(1, sizeof(size_t));
  self->type_size = (size_t*)__ARG_LIST__[0];
) DEFAULT_DESTROY

void* linked_list_push(linked_list_t* self, void* obj) {
  linked_list_node_t* node = \
    (linked_list_node_t*)calloc(1, sizeof(linked_list_node_t) + self->type_size);
  memcpy(&(node->value), obj, self->type_size);
  linked_list_node_t* prev_head = self->head;
  if (self->head == 0) {
    self->head = node;
  }
  self->head->next = prev_head;
  return self;
}

void* linked_list_pop(linked_list_t* self, void* obj) {
  memcpy(obj, &(self->head->value), self->type_size);
  linked_list_node_t* node = self->head;
  free(self->head);
  self->head = node->next;
  return self;
}

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
