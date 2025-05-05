#ifndef DYN_ALLOC_H
#define DYN_ALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
void* memcpy(void* DEST, const void* SRC, size_t COUNT);
#endif // !memcpy


#ifndef method_function_t
typedef void*(*method_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

typedef struct generic_method_t {
  void* obj_instance;
  method_function_t function;
} generic_method_t;

extern generic_method_t generic_method;

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

void __SCOPE_STACK_ALLOC(__SCOPE_STACK_t* stack, size_t capacity);

void __SCOPE_STACK_RESERVE(__SCOPE_STACK_t* stack, size_t capacity);

void __SCOPE_STACK_INIT(__SCOPE_STACK_t* stack);

void __SCOPE_STACK_DESTROY(__SCOPE_STACK_t* stack);

void __SCOPE_STACK_PUSH(__SCOPE_STACK_t* stack, generic_method_t action);

generic_method_t* __SCOPE_STACK_POP(__SCOPE_STACK_t* stack);

void* __SCOPE_STACK_TOP(__SCOPE_STACK_t* stack);

void __SCOPE_STACK_EXECUTE(generic_method_t* method);

void* __SCOPE_STACK_EXECUTE_ALL(__SCOPE_STACK_t* stack);

extern __SCOPE_STACK_t __SCOPE_STACK;

extern void* __SCOPE_STACK_HEAD;

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

#define FOR( VAR, COND, EXPR ) for (VAR; COND; EXPR) { BEGIN

#define FOREACH( TYPE, VAR, SRC ) for (size_t FOR_EACH_ITER = 0; FOR_EACH_ITER < SRC.size; ++FOR_EACH_ITER) { \
  TYPE VAR = ((TYPE*)SRC.data)[FOR_EACH_ITER]; \
  BEGIN

#endif // SCOPE STACK TEMPLATES DEFINITIONS

#endif
