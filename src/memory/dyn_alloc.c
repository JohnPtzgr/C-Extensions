#include "dyn_alloc.h"


void* memcpy(void* DEST, const void* SRC, size_t COUNT) {
  for (size_t i = 0; i < COUNT / sizeof(void*); ++i) {
    ((size_t*)DEST)[i] = ((size_t*)SRC)[i];
  }
  for (size_t i = (COUNT / sizeof(void*)) * sizeof(void*); 
       i < COUNT; ++i) {
    ((char*)DEST)[i] = ((char*)SRC)[i];
  }
  return DEST;
}

generic_method_t generic_method = {0, 0};

void __SCOPE_STACK_ALLOC(__SCOPE_STACK_t* stack, size_t capacity) {
  if (stack->capacity != 0) {
    free(stack->actions);
  }
  stack->capacity = __SCOPE_STACK_INITIAL_CAPACITY;
  stack->actions = (generic_method_t*)malloc(sizeof(generic_method_t) * stack->capacity);
  stack->data = stack->actions;
}

void __SCOPE_STACK_RESERVE(__SCOPE_STACK_t* stack, size_t capacity) {
  if (stack->capacity >= capacity) {
    stack->size = (stack->size < capacity ? stack->size : capacity);
    return;
  }
  void* actions = stack->actions;
  stack->actions = (generic_method_t*)malloc(sizeof(generic_method_t) * capacity);
  stack->actions = (generic_method_t*)memcpy(stack->actions, actions, stack->size * sizeof(generic_method_t));
  if (stack->capacity != 0) {
    free(actions);
  }
  stack->capacity = capacity;
  stack->data = stack->actions;
}

void __SCOPE_STACK_INIT(__SCOPE_STACK_t* stack) {
  stack->size = 0;
  stack->capacity = 0;
  __SCOPE_STACK_ALLOC(stack, __SCOPE_STACK_INITIAL_CAPACITY);
}

void __SCOPE_STACK_DESTROY(__SCOPE_STACK_t* stack) {
  free(stack->actions);
  stack->actions = 0;
  stack->capacity = 0;
  stack->size = 0;
}

void __SCOPE_STACK_PUSH(__SCOPE_STACK_t* stack, generic_method_t action) {
  BOOL action_type = FALSE;
  generic_method_t tmp_gen_meth = {0, 0};
  BITWISE_CMP(&action_type, action, tmp_gen_meth);
  if (action_type && stack->actions == 0) {
    return;
  }
  if (action_type && stack->actions == 0) {
    __SCOPE_STACK_INIT(stack);
  }
  if (stack->capacity == 0) {
    __SCOPE_STACK_RESERVE(stack, __SCOPE_STACK_INITIAL_CAPACITY);
  }
  if (stack->size + 1 >= stack->capacity) {
    __SCOPE_STACK_RESERVE(stack, stack->capacity * 2);
  }
  //printf("%llu\n", action.function);
  stack->actions[stack->size++] = action;
}

generic_method_t* __SCOPE_STACK_POP(__SCOPE_STACK_t* stack) {
  if (stack->size == 0) {
    return 0;
  }
  if (stack->size <= stack->capacity / 4) {
    __SCOPE_STACK_RESERVE(stack, stack->capacity / 2);
  }
  generic_method_t* action = &(stack->actions[--stack->size]);
  if (action->function == 0 && action->obj_instance == 0) {
    return 0;
  }
  return action;
}

void* __SCOPE_STACK_TOP(__SCOPE_STACK_t* stack) {
  if (stack->size == 0) {
    return 0;
  }
  generic_method_t* action = &(stack->actions[--stack->size]);
  if (action->function == 0 && action->obj_instance == 0) {
    return 0;
  }
  return action;
}

void __SCOPE_STACK_EXECUTE(generic_method_t* method) {
  method->function(method->obj_instance);
}

void* __SCOPE_STACK_EXECUTE_ALL(__SCOPE_STACK_t* stack) {
  for (size_t i = stack->size; i > 0; --i) {
    BOOL cmp = TRUE;
    generic_method_t tmp_gen_meth = {0, 0};
    //printf("i-%llu; j-%llu;\n", stack->actions->function, stack->actions->obj_instance);
    BITWISE_CMP(&cmp, stack->actions[i - 1], tmp_gen_meth);
    if (!cmp) {
      __SCOPE_STACK_EXECUTE(&(stack->actions[i - 1]));
      //printf("%d", i);
    }
  }
  return stack;
}

__SCOPE_STACK_t __SCOPE_STACK = {0, 0, 0};

void* __SCOPE_STACK_HEAD = 0;

