#include "linked_list.h"
#include "string.h"

CLASS_END(linked_list_node_t, ;) DEFAULT_DESTROY;

CLASS_END(linked_list_t,
  self->push = (method_function_t)linked_list_push;
  self->pop = (method_function_t)linked_list_pop;
  self->head = NULL;
  self->size = 0;
  METHOD_ARGS(1, (void*)sizeof(size_t));
  self->type_size = ((size_t*)__ARG_LIST__)[0];
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
