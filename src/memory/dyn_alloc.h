#include <stdlib.h>
#include <stdio.h>
#pragma once

//#undef __CHAR_BIT__
#ifndef __CHAR_BIT__
#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif // !CHAR_BIT
#define __CHAR_BIT__ CHAR_BIT
#endif // !__CHAR_BIT__

#ifndef MIN
#define MIN(A, B) (A < B ? A : B)
#endif // !MAX


#ifndef MAX
#define MAX(A, B) (A > B ? A : B)
#endif // !MAX

#ifndef ARG1_VA_ARGS
#define ARG1_VA_ARGS( ARG1, ... ) ARG1
#define ARG2_VA_ARGS( ARG1, ARG2, ... ) ARG2
#define ARG3_VA_ARGS( ARG1, ARG2, ARG3, ... ) ARG3
#define ARG4_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ... ) ARG4
#define ARG5_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ... ) ARG5
#define ARG6_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ... ) ARG6
#define ARG7_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ... ) ARG7
#define ARG8_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ... ) ARG8
#endif // CHOOSE __VA_ARGS__ ARGUMENT (Up to 8-th)

#ifndef BOOL
typedef enum {
  FALSE = 0,
  TRUE = 1
} BOOL;
#endif // !BOOL

#ifndef BITWISE_CMP
#define BITWISE_CMP( VAR_PTR, OBJA, ... ) { \
  size_t i = sizeof(OBJA); \
  size_t j = sizeof(__VA_ARGS__); \
  BOOL result = (BOOL)(i == j); \
  if (result) { \
    for (size_t k = 0; k < i; ++k) { \
      if (((char*)(&(OBJA)))[k] != ((char*)(&(__VA_ARGS__)))[k]) { \
        result = FALSE; \
        break; \
      } \
    } \
  }; \
  *(VAR_PTR) = result; }
#endif // !BITWISE_CMP


#ifndef memcpy
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
#endif // !memcpy


#ifndef method_function_t
typedef void*(*method_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

typedef struct generic_method_t {
  void* obj_instance;
  method_function_t function;
} generic_method_t;

generic_method_t generic_method = {0, 0};

typedef struct class_method_t {
  void* class_instance;
  method_function_t class_function;
} class_method_t;
#endif // METHOD RELATED DEFINITIONS


#ifndef __SCOPE_STACK_t
typedef struct __SCOPE_STACK_t {
  generic_method_t* actions;
  size_t capacity;
  size_t size;
  void* data;
} __SCOPE_STACK_t;

#define __SCOPE_STACK_INITIAL_CAPACITY 8

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

#endif // SCOPE STACK RELATED DEFINITIONS


#ifndef BEGIN
#define BEGIN __SCOPE_STACK_PUSH(&__SCOPE_STACK, (generic_method_t){0, 0});

#define SCOPE_END \
  while ((__SCOPE_STACK_HEAD = __SCOPE_STACK_POP(&__SCOPE_STACK)) != 0) { \
    __SCOPE_STACK_EXECUTE((generic_method_t*)__SCOPE_STACK_HEAD); \
  } \
  if (__SCOPE_STACK.size==0) { \
    __SCOPE_STACK_DESTROY(&__SCOPE_STACK); \
  }

#define PURGE_HEAP __SCOPE_STACK_EXECUTE_ALL(&__SCOPE_STACK); \
  __SCOPE_STACK_DESTROY(&__SCOPE_STACK);

#define RETURN( EXPR ) SCOPE_END return EXPR;

#define FUNC( RETURN_TYPE, FUNCTION_NAME, ... ) RETURN_TYPE FUNCTION_NAME(__VA_ARGS__) { BEGIN;

#define END SCOPE_END }

#define FOR( VAR, COND, EXPR ) for (VAR; COND; EXPR) { \
  BEGIN

#define FOREACH( TYPE, VAR, SRC ) for (size_t FOR_EACH_ITER = 0; FOR_EACH_ITER < SRC.size; ++FOR_EACH_ITER) { \
  TYPE VAR = ((TYPE*)SRC.data)[FOR_EACH_ITER]; \
  BEGIN

#endif // SCOPE STACK TEMPLATES DEFINITIONS

