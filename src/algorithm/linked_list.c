#include "linked_list.h"
#include "string.h"

static void* linked_list_push(linked_list_t*, void*);
static void* linked_list_pop(linked_list_t*, void*);

CLASS_END(linked_list_node_t, 0, ;) DEFAULT_DESTROY(linked_list_node_t);
void* linked_list_node_t_init(linked_list_node_t* self, ...) {
  __AUX_INIT_BEGIN__(linked_list_node_t)
  __M_VA_ARG__(4, 0, 0, 0, 0);
  __AUX_INIT_END__(linked_list_node_t)
}

CLASS_END(linked_list_t, STATIC,
  __linked_list_t_Default_vClassObject__.push = (generic_function_t)linked_list_push;
  __linked_list_t_Default_vClassObject__.pop = (generic_function_t)linked_list_pop;
  self->head = NULL;
  self->size = 0;
) DEFAULT_DESTROY(linked_list_t);
void* linked_list_t_init(linked_list_t* self, ...) {
  __AUX_INIT_BEGIN__(linked_list_t)
  __M_VA_ARG__(4, 0, 0, 0, 0);
  __AUX_INIT_END__(linked_list_t)
}

void* linked_list_push(linked_list_t* self, void* obj) {
  linked_list_node_t* node = \
    (linked_list_node_t*)calloc(1, sizeof(linked_list_node_t) + self->type_size);
  PUSH_EXCEPTION(void*);
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
  PUSH_EXCEPTION(void*);
  self->head = node->next;
  return self;
}
