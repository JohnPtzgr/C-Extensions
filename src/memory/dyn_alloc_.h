#ifndef DYN_ALLOC_H
#define DYN_ALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma once


#ifndef __CHAR_BIT__
#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif // !CHAR_BIT
#define __CHAR_BIT__ CHAR_BIT
#endif // !__CHAR_BIT__

#ifndef __UCHAR_MAX__
#ifndef __SCHAR_MAX__
#define __SCHAR_MAX__ 127
#define __UCHAR_MAX__ 255
#else
#define __UCHAR_MAX__ (__SCHAR_MAX__ * 2 + 1)
#endif
#endif

#ifndef MIN
#define MIN(A, B) (A < B ? A : B)
#endif // !MAX


#ifndef MAX
#define MAX(A, B) (A > B ? A : B)
#endif // !MAX

#ifndef ARG1_VA_ARGS
#define ARG1_VA_ARGS( ARG1, ... ) ARG1
#define ARG1_VA_ARGS_VA( ARG1, ... ) __VA_ARGS__
#define ARG2_VA_ARGS( ARG1, ARG2, ... ) ARG2
#define ARG2_VA_ARGS_VA( ARG1, ARG2, ... ) __VA_ARGS__
#define ARG3_VA_ARGS( ARG1, ARG2, ARG3, ... ) ARG3
#define ARG3_VA_ARGS_VA( ARG1, ARG2, ARG3, ... ) __VA_ARGS__
#define ARG4_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ... ) ARG4
#define ARG4_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ... ) __VA_ARGS__
#define ARG5_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ... ) ARG5
#define ARG5_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ... ) __VA_ARGS__
#define ARG6_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ... ) ARG6
#define ARG6_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ... ) __VA_ARGS__
#define ARG7_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ... ) ARG7
#define ARG7_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ... ) __VA_ARGS__
#define ARG8_VA_ARGS( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ... ) ARG8
#define ARG8_VA_ARGS_VA( ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ... ) __VA_ARGS__
#endif // CHOOSE __VA_ARGS__ ARGUMENT (Up to 8-th)

#ifndef BOOL
typedef char BOOL;
#endif // !BOOL

#ifndef TRUE
typedef enum {
  FALSE = 0,
  TRUE = 1
};
#endif

#ifndef method_function_t
typedef void*(*method_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

size_t __CALL_FUNCTION__(generic_function_t, void*);
#endif // METHOD RELATED DEFINITIONS


#ifndef __SCOPE_STACK__


#define __SCOPE_STACK_INITIAL_CAPACITY__ 8

typedef struct __SCOPE_STACK__ {
  method_function_t* actions;
  void** instances;
  char* masks;
  size_t capacity;
  size_t size;
} __SCOPE_STACK__;


size_t __scope_stack_init__(__SCOPE_STACK__* stack);
size_t __scope_stack_destroy__(__SCOPE_STACK__* stack);
size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance);
size_t __scope_stack_pop__(__SCOPE_STACK__* stack);
void* __scope_stack_top__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  method_function_t predicate);
size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack);
size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance,
  method_function_t predicate);

typedef struct __SCOPE_DEFER_STACK__ {
  method_function_t* predicates;
  method_function_t* actions;
  void** instances;
  size_t* prev;
  size_t* next;
  size_t* free_chunks;
  size_t free_chunks_size;
  size_t capacity;
  size_t size;
} __SCOPE_DEFER_STACK__;


size_t __scope_defer_stack_init__(__SCOPE_STACK__* stack);
size_t __scope_defer_stack_destroy__(__SCOPE_STACK__* stack);
size_t __scope_defer_stack_push__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance);
size_t __scope_stack_check__(__SCOPE_STACK__* stack);


typedef struct __SCOPE_OBJECT__ {
  __SCOPE_STACK__ main_stack;
  __SCOPE_DEFER_STACK__ defer_stack;
} __SCOPE_OBJECT__;





#endif
#endif