#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <alloca.h>
#include "../oop/exception.h"
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

#ifndef INVALID
#define INVALID ((void*)-1)
#endif // !INVALID

#ifndef MIN
#define MIN(A, B) (A < B ? A : B)
#endif // !MAX


#ifndef MAX
#define MAX(A, B) (A > B ? A : B)
#endif // !MAX

#ifndef ARG1_VA_ARGS
#define __AUX_EXP_MACRO_ARG__(MACRO_TO_EXP, ARG) MACRO_TO_EXP(ARG)
#define ARG0_VA(ARG0...) ARG0
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

#ifndef TO_STR_LITERAL
#define TO_STR_LITERAL(ARG) #ARG
#endif // !TO_STR_LITERAL

#ifndef generic_function_t
typedef void*(*generic_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

void* __CALL_FUNCTION__(generic_function_t, void*);
void* __CALL_FUNCTION_N_ARGS__(generic_function_t, ... );
#endif // METHOD RELATED DEFINITIONS


#ifndef __SCOPE_STACK__

typedef struct __SCOPE_STACK__ {
  size_t capacity;
  size_t size;
  generic_function_t* actions;
  void** instances;
  void*** args;
  char* masks;
} __SCOPE_STACK__;

typedef struct __SCOPE_DEFER_CHUNK__ {
  long bias_sum;
  size_t min_indentation;
  size_t capacity;
  size_t size;
  generic_function_t* predicates;
  void*** predicate_args;
  generic_function_t* actions;
  void** instances;
  void*** args;
} __SCOPE_DEFER_CHUNK__;



typedef struct __SCOPE_DEFER_POOL__ {
  unsigned int chunk_bias_pos;
  unsigned int chunk_bias_neg;
  size_t active_size;
  size_t size;
  size_t capacity;
  size_t tokens;
  size_t indentation;
  void* tree_root;
  __SCOPE_DEFER_CHUNK__* chunks;
} __SCOPE_DEFER_POOL__;


#ifndef __SCOPE_STACK_INITIAL_CAPACITY__
#define __SCOPE_STACK_INITIAL_CAPACITY__ 8
#endif


void* __scope_stack_init__(__SCOPE_STACK__* stack);
size_t __scope_stack_destroy__(__SCOPE_STACK__* stack);
size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance,
  void** args);
size_t __scope_stack_pop__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack);
void* __scope_stack_top__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  generic_function_t predicate);
size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack);
size_t __scope_stack_find__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_find_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_skip__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);


#ifndef __SCOPE_DEFER_CHUNK_INITIAL_CAPACITY__
#define __SCOPE_DEFER_CHUNK_INITIAL_CAPACITY__ 8
#endif


void* __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args,
  size_t indentation);
size_t __scope_defer_chunk_find__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_skip__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk);


#ifndef __SCOPE_DEFER_POOL_INITIAL_CAPACITY__
#define __SCOPE_DEFER_POOL_INITIAL_CAPACITY__ 2
#define __SCOPE_DEFER_POOL_DEFAULT_POSITIVE_BIAS__ 4
#define __SCOPE_DEFER_POOL_DEFAULT_NEGATIVE_BIAS__ 1
#endif


void* __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_enter__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_escape__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_add_token__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_skip__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_force__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_find__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);


#ifndef __SCOPE_OBJECT_MAX_ARGUMENT_COUNT__
#define __SCOPE_OBJECT_MAX_ARGUMENT_COUNT__ 32
#define __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__ 8
#endif


typedef struct __SCOPE_OBJECT__ {
  __SCOPE_STACK__* stack;
  __SCOPE_DEFER_POOL__* defer_pool;
  size_t size;
  size_t mask;
} __SCOPE_OBJECT__;

void* __scope_object_init__(__SCOPE_OBJECT__* scope,
  __SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope);
size_t __scope_object_enter__(__SCOPE_OBJECT__* scope);
size_t __scope_object_escape__(__SCOPE_OBJECT__* scope);
size_t __scope_object_change_bias__(__SCOPE_OBJECT__* scope,
  size_t bias_positive,
  size_t bias_negative);
size_t __scope_object_lock_pool__(__SCOPE_OBJECT__* scope);
size_t __scope_object_push__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_stage__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_defer__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  generic_function_t predicate,
  ...);
size_t __scope_object_skip__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);
size_t __scope_object_force__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);


extern __SCOPE_STACK__ __SCOPE_STACK_INST__;
extern __SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__;
extern __SCOPE_OBJECT__ __SCOPE_OBJECT_INST__;

void* __SCOPE_BEGIN__(__SCOPE_OBJECT__* scope,
  __SCOPE_DEFER_POOL__* pool,
  __SCOPE_STACK__* stack);

void* __SCOPE_END__(__SCOPE_OBJECT__* scope);

void* __SCOPE_CALLOC__(__SCOPE_OBJECT__* scope,
  size_t size,
  size_t type_size,
  void* filler,
  ...);

void* __SCOPE_FREE__(__SCOPE_OBJECT__* scope, void* data);

void* __SCOPE_FORCED_RELEASE__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

void* __SCOPE_SKIP__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

__SCOPE_OBJECT__* __LOCAL_SCOPE_NEW__();

void* __LOCAL_SCOPE_FREE__(__SCOPE_OBJECT__* local_scope);

void* __DEFAULT_PREDICATE__(void* instance, ...);

void* __TRUE_PREDICATE__(void* instance, ...);

void* __FALSE_PREDICATE__(void* instance, ...);

#define SCOPE_BEGIN __SCOPE_BEGIN__(&__SCOPE_OBJECT_INST__, &__SCOPE_DEFER_POOL_INST__, &__SCOPE_STACK_INST__);

#define BEGIN { SCOPE_BEGIN

#define SCOPE_END __SCOPE_END__(&__SCOPE_OBJECT_INST__);

#define PURGE_HEAP __scope_object_destroy__(&__SCOPE_OBJECT_INST__);

#define RETURN(EXPR...) SCOPE_END return EXPR;

#define FUNCTION(RETURN_TYPE, FUNCTION_NAME, ARGUMENTS...) RETURN_TYPE FUNCTION_NAME(ARGUMENTS) BEGIN

#define END SCOPE_END }

#define FOR(VAR, COND, EXPR) for (VAR; COND; EXPR) BEGIN

#define SCOPE_PUSH(INSTANCE, ACTION...) __scope_object_push__(&__SCOPE_OBJECT_INST__, \
  (void*)(INSTANCE), (generic_function_t)(ARG1_VA_ARGS(ACTION, 0)), ARG1_VA_ARGS_VA(ACTION, 0))

#define SCOPE_DEFER(INSTANCE, ACTION, PREDICATE...) __scope_object_defer__(&__SCOPE_OBJECT_INST__, \
  (void*)(INSTANCE), (generic_function_t)(ACTION), (generic_function_t)(ARG1_VA_ARGS(PREDICATE, 0)), \
  ARG1_VA_ARGS_VA(PREDICATE, 0))

#define STAGE(INSTANCE, ACTION...) __scope_object_stage__(&__SCOPE_OBJECT_INST__, \
  (void*)(INSTANCE), (generic_function_t)(ARG1_VA_ARGS(ACTION, 0)), ARG1_VA_ARGS_VA(ACTION, 0))

#define FORCE_RELEASE(INSTANCE...) __SCOPE_FORCED_RELEASE__(&__SCOPE_OBJECT_INST__, \
  ARG1_VA_ARGS(INSTANCE, 0), (generic_function_t)ARG2_VA_ARGS(INSTANCE, 0))

#define SKIP(INSTANCE...) __SCOPE_SKIP__(&__SCOPE_OBJECT_INST__, \
  ARG1_VA_ARGS(INSTANCE, 0), (generic_function_t)ARG2_VA_ARGS(INSTANCE, 0))

#define ALLOC(SIZE...) (ARG2_VA_ARGS(SIZE, void)*)__SCOPE_CALLOC__(&__SCOPE_OBJECT_INST__, \
  ARG1_VA_ARGS(SIZE), sizeof(ARG2_VA_ARGS(SIZE, (char)0)), ARG2_VA_ARGS_VA(SIZE, 0, 0))

#define FREE(DATA) __SCOPE_FREE__(&__SCOPE_OBJECT_INST__, DATA)

#define NEW_LOCAL_SCOPE __LOCAL_SCOPE_NEW__()

#define DESTROY_LOCAL_SCOPE(LOCAL_SCOPE) __LOCAL_SCOPE_FREE__(LOCAL_SCOPE)

#define LSCOPE_BEGIN(SCOPE) __SCOPE_BEGIN__(SCOPE, NULL, NULL);

#define LSBEGIN(SCOPE) { LSCOPE_BEGIN(SCOPE)

#define LSCOPE_END(SCOPE) __SCOPE_END__(SCOPE);

#define LSPURGE_HEAP(SCOPE) __scope_object_destroy__(SCOPE);

#define LSRETURN(SCOPE, EXPR...) LSCOPE_END return EXPR;

#define LSEND(SCOPE) LSCOPE_END(SCOPE) }

#define LSFOR(SCOPE, VAR, COND, EXPR) for (VAR; COND; EXPR) LSBEGIN(SCOPE)

#define LSCOPE_PUSH(SCOPE, INSTANCE, ACTION...) __scope_object_push__(SCOPE, \
  (void*)(INSTANCE), (generic_function_t)(ARG1_VA_ARGS(ACTION, 0)), ARG1_VA_ARGS_VA(ACTION, 0))

#define LSCOPE_DEFER(SCOPE, INSTANCE, ACTION, PREDICATE...) __scope_object_defer__(SCOPE, \
  (void*)(INSTANCE), (generic_function_t)(ACTION), (generic_function_t)(ARG1_VA_ARGS(PREDICATE, 0)), \
  ARG1_VA_ARGS_VA(PREDICATE, 0))

#define LSSTAGE(SCOPE, INSTANCE, ACTION...) __scope_object_stage__(SCOPE, \
  (void*)(INSTANCE), (generic_function_t)(ARG1_VA_ARGS(ACTION, 0)), ARG1_VA_ARGS_VA(ACTION, 0))

#define LSFORCE_RELEASE(SCOPE, INSTANCE...) __SCOPE_FORCED_RELEASE__(SCOPE, \
  ARG1_VA_ARGS(INSTANCE, 0), (generic_function_t)ARG2_VA_ARGS(INSTANCE, 0))

#define LSSKIP(SCOPE, INSTANCE...) __SCOPE_SKIP__(SCOPE, \
  ARG1_VA_ARGS(INSTANCE, 0), (generic_function_t)ARG2_VA_ARGS(INSTANCE, 0))

#define LSALLOC(SCOPE, SIZE...) (ARG2_VA_ARGS(SIZE, void)*)__SCOPE_CALLOC__(SCOPE, \
  ARG1_VA_ARGS(SIZE), sizeof(ARG2_VA_ARGS(SIZE, (char)0)), ARG2_VA_ARGS_VA(SIZE, 0, 0))

#endif
