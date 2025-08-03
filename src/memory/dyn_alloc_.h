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
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;
#endif

#ifndef method_function_t
typedef void*(*method_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

size_t __CALL_FUNCTION__(generic_function_t, void*);
#endif // METHOD RELATED DEFINITIONS


#ifndef __SCOPE_STACK__

typedef struct __SCOPE_STACK__ {
  size_t capacity;
  size_t size;
  method_function_t* actions;
  void** instances;
  char* masks;
} __SCOPE_STACK__;

typedef struct __SCOPE_DEFER_CHUNK__ {
  long bias_sum;
  size_t capacity;
  size_t size;
  method_function_t* predicates;
  method_function_t* actions;
  void** instances;
} __SCOPE_DEFER_CHUNK__;

typedef struct __SCOPE_DEFER_POOL__ {
  unsigned int chunk_bias_pos;
  unsigned int chunk_bias_neg;
  size_t active_size;
  size_t size;
  size_t capacity;
  size_t tokens;
  size_t indentation;
  __SCOPE_DEFER_CHUNK__* chunks;
} __SCOPE_DEFER_POOL__;

#ifndef __SCOPE_STACK_INITIAL_CAPACITY__
#define __SCOPE_STACK_INITIAL_CAPACITY__ 8
#endif


size_t __scope_stack_init__(__SCOPE_STACK__* stack);
size_t __scope_stack_destroy__(__SCOPE_STACK__* stack);
size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance);
size_t __scope_stack_pop__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack);
void* __scope_stack_top__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  method_function_t predicate);
size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack);
size_t __scope_stack_find__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance);
size_t __scope_stack_find_action__(__SCOPE_STACK__* stack,
  method_function_t action);
size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_skip__(__SCOPE_STACK__* stack,
  method_function_t action,
  void* instance);
size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack,
  method_function_t action);
size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  method_function_t action,
  void* instance,
  method_function_t predicate);
size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  method_function_t action,
  method_function_t predicate);
size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  void* instance,
  method_function_t predicate);


#ifndef __SCOPE_DEFER_CHUNK_INITIAL_CAPACITY__
#define __SCOPE_DEFER_CHUNK_INITIAL_CAPACITY__ 8
#endif


size_t __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
  method_function_t action,
  void* instance,
  method_function_t predicate);
size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
  size_t bias_positive,
  size_t bias_negative);
size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk);


#ifndef __SCOPE_DEFER_POOL_INITIAL_CAPACITY__
#define __SCOPE_DEFER_POOL_INITIAL_CAPACITY__ 2
#endif

size_t __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
  method_function_t action,
  void* instance,
  method_function_t predicate);
size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_enter__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_escape__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_add_token__(__SCOPE_DEFER_POOL__* pool);


typedef struct __SCOPE_OBJECT__ {
  __SCOPE_STACK__* stack;
  __SCOPE_DEFER_POOL__* defer_pool;
} __SCOPE_OBJECT__;

size_t __scope_object_init__(__SCOPE_OBJECT__* scope,
  __SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope);
size_t __scope_object_enter__(__SCOPE_OBJECT__* scope);
size_t __scope_object_escape__(__SCOPE_OBJECT__* scope);
size_t __scope_object_push__(__SCOPE_OBJECT__* scope,
  void* instance,
  method_function_t action);
size_t __scope_object_defer__(__SCOPE_OBJECT__* scope,
  void* instance,
  method_function_t action,
  method_function_t predicate);
size_t __scope_object_skip__(__SCOPE_OBJECT__* scope,
  void* instance,
  method_function_t action);


extern __SCOPE_STACK__ __SCOPE_STACK_INST__;
extern __SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__;
extern __SCOPE_OBJECT__ __SCOPE_OBJECT_INST__;


#endif
#endif
