#include "dyn_alloc_.h"

char __scope_stack_mask_set_active__(char* mask, BOOL state) {
  *mask = *mask & (__UCHAR_MAX__ - 1);
  *mask |= state;
  return mask;
}

BOOL __scope_stack_mask_get_active__(char* mask) {
  return *mask & 1;
}

BOOL __scope_stack_special_call_predicate__(void* instance, method_function_t action) {
  return (instance == 0) || (action == 0);
}

BOOL __scope_stack_regular_predicate__(void* instance, method_function_t action) {
  return (instance > 0) && (action > 0);
}

BOOL __scope_stack_indentation_predicate__(void* instance, method_function_t action) {
  return (instance == 0) && (action == 0);
}

BOOL __scope_stack_skip_predicate__(void* instance, method_function_t action) {
  return (instance > 0) && (action == 0);
}

BOOL __scope_stack_callable_predicate__(void* instance, method_function_t action) {
  return (instance == 0) && (action > 0);
}

size_t __scope_stack_reserve__(__SCOPE_STACK__* stack, size_t capacity) {
  method_function_t* tmp_actions;
  void** tmp_instances;
  char* tmp_masks;
  stack->actions = malloc(sizeof(method_function_t) * capacity);
  stack->masks = malloc(capacity);
  if (stack->capacity) {
    memcpy(stack->actions, tmp_actions, sizeof(method_function_t) * MIN(stack->capacity, capacity));
    memcpy(stack->instances, tmp_instances, sizeof(void*) * MIN(stack->capacity, capacity));
    memcpy(stack->masks, tmp_masks, sizeof(char) * MIN(stack->capacity, capacity));
    free(tmp_actions);
    free(tmp_instances);
    free(tmp_masks);
  }
  stack->capacity = capacity;
  stack->size = MIN(stack->size, capacity);
  return stack->size;
}

size_t __scope_stack_init__(__SCOPE_STACK__* stack) {
  stack->capacity = 0;
  stack->size = 0;
  __scope_stack_reserve__(stack, __SCOPE_STACK_INITIAL_CAPACITY__);
  return __scope_stack_push__(stack, 0, 0);
}

size_t __scope_stack_destroy__(__SCOPE_STACK__* stack) {
  if (stack->capacity) {
    free(stack->actions);
    free(stack->instances);
    free(stack->masks);
  }
  stack->capacity = 0;
  stack->size = 0;
  return 0;
}

size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance) {
  if (stack->size + 1 == stack->capacity) {
    __scope_stack_reserve__(stack, stack->capacity * 2);
  }
  stack->actions[stack->size] = action;
  stack->instances[stack->size] = instance;
  stack->masks[stack->size] = 1 ^ __scope_stack_0_predicate__(instance, action);
  stack->size++;
  return stack->size;
}

size_t __scope_stack_pop__(__SCOPE_STACK__* stack) {
  stack->size--;
  if (__scope_stack_mask_get_active__(stack->masks[stack->size])) {
    (stack->actions[stack->size])((stack->instances[stack->size]));
  }
  if ((4 * stack->size < stack->capacity) &&
    (2 * stack->size > __SCOPE_STACK_INITIAL_CAPACITY__)) {
    __scope_stack_reserve__(stack, stack->capacity / 2);
  }
  return stack->size;
}

size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance,
  method_function_t predicate) {
  if (!predicate(instance, action)) {
    return 0;
  }
  size_t i = stack->size;
  while (stack->instances[i - 1] != instance &&
    stack->actions[i - 1] != action) {
    i--;
    if (i == 0) {
      return 0;
    }
  }
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

void* __scope_stack_top__(__SCOPE_STACK__* stack) {
  return stack->instances[stack->size - 1];
}

size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  method_function_t predicate) {
  while (!predicate(stack->instances[stack->size - 1],
    stack->actions[stack->size - 1])) {
    __scope_stack_pop__(stack);
  }
  return stack->size;
}

size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack) {
  while (!__scope_stack_pop__(stack));
}

