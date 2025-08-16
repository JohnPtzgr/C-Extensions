#include "dyn_alloc_.h"

typedef struct __DEFER_POOL_NODE__
{
  void* instance;
  generic_function_t action;
} __DEFER_POOL_NODE__;

char __compare_defer_pool_node__(__DEFER_POOL_NODE__ a, __DEFER_POOL_NODE__ b) {
  if (!a.action || !b.action) {
    return a.instance < b.instance;
  }
  if (!a.instance || !b.instance) {
    return a.action < b.action;
  }
  return (a.instance < b.instance) || ((a.instance == b.instance) && (a.action < b.action));
}

#define __T_ARG_A__ defer_pool_tree
#define __T_ARG_B__ __DEFER_POOL_NODE__
#define __T_ARG_C__ __compare_defer_pool_node__
#include "../algorithm/rb_tree.h"



char* __scope_stack_mask_set_active__(char* mask, BOOL state) {
  *mask = *mask & (__UCHAR_MAX__ - 1);
  *mask |= state;
  return mask;
}

BOOL __scope_stack_mask_get_active__(char* mask) {
  return *mask & 1;
}

BOOL __scope_stack_special_call_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) || (action == 0);
}

BOOL __scope_stack_regular_predicate__(void* instance, generic_function_t action) {
  return ((size_t)instance > 0) && ((size_t)action > 0);
}

BOOL __scope_stack_indentation_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) && (action == 0);
}

BOOL __scope_stack_skip_predicate__(void* instance, generic_function_t action) {
  return ((size_t)instance > 0) && (action == 0);
}

BOOL __scope_stack_callable_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) && ((size_t)action > 0);
}


void* __CALL_ACTION_N_ARGS__(generic_function_t action,
                             void* instance,
                             void** args) {
  if (__scope_stack_indentation_predicate__(instance, action)) {
    return NULL;
  }
  if (!args) {
    if (action) {
      return action(instance, 0);
    } else {
      return ((generic_function_t)instance)(0);
    }
  }

  if (__scope_stack_indentation_predicate__(instance, action)) {
    free(args);
    return NULL;
  }

  size_t arg_size = 0;

  while (args[arg_size++]) {};

  void* result;
  switch (arg_size) {
  case 2:
    result = action(instance,
                    args[0],
                    0);
    break;
  case 3:
    result = action(instance, args[0], args[1], 0);
    break;
  case 4:
    result = action(instance, args[0], args[1], args[2], 0);
    break;
  case 5:
    result = action(instance, args[0], args[1], args[2], args[3], 0);
    break;
  case 6:
    result = action(instance, args[0], args[1], args[2], args[3], args[4], 0);
    break;
  case 7:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], 0);
    break;
  case 8:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], 0);
    break;
  case 9:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], 0);
    break;
  case 10:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], 0);
    break;
  case 11:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], 0);
    break;
  case 12:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10], 0);
    break;
  case 13:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], 0);
    break;
  case 14:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], args[12], 0);
    break;
  case 15:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], args[12], args[13], 0);
    break;
  case 16:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], args[12], args[13], args[14], 0);
    break;
  default:
    result = action(instance, args);
    break;
  }
  free(args);
  return result;
}


void* __CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(generic_function_t predicate,
                                             void* instance,
                                             generic_function_t action,
                                             void** args) {

  if (__scope_stack_indentation_predicate__(instance, action)) {
    return (void*)TRUE;
  }
  
  if (args == 0) {
    return predicate(instance, action);
  }

  size_t arg_size = 0;

  while (args[arg_size++]) {};

  void* result;
  switch (arg_size) {
  case 2:
    result = predicate(instance, action, args[0], 0);
    break;
  case 3:
    result = predicate(instance, action, args[0], args[1], 0);
    break;
  case 4:
    result = predicate(instance, action, args[0], args[1], args[2], 0);
    break;
  case 5:
    result = predicate(instance, action, args[0], args[1], args[2], args[3], 0);
    break;
  case 6:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], 0);
    break;
  case 7:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], 0);
    break;
  case 8:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], 0);
    break;
  case 9:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], 0);
    break;
  case 10:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], 0);
    break;
  case 11:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9], 0);
    break;
  case 12:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], 0);
    break;
  case 13:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], 0);
    break;
  case 14:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], args[12], 0);
    break;
  case 15:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], args[12], args[13], 0);
    break;
  case 16:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], args[12], args[13], args[14], 0);
    break;
  default:
    result = predicate(instance, action, args);
    break;
  }
  return result;
}


size_t __scope_stack_reserve__(__SCOPE_STACK__* stack, size_t capacity) {
  generic_function_t* tmp_actions = stack->actions;
  void** tmp_instances = stack->instances;
  void*** tmp_args = stack->args;
  char* tmp_masks = stack->masks;
  stack->actions = (generic_function_t*)malloc(sizeof(generic_function_t) * capacity);
  stack->instances = (void**)malloc(sizeof(void*) * capacity);
  stack->args = (void***)malloc(sizeof(void**) * capacity);
  stack->masks = (char*)malloc(capacity);
  if (stack->capacity) {
    memcpy(stack->actions,
      tmp_actions,
      sizeof(generic_function_t) * MIN(stack->size, capacity));
    memcpy(stack->instances,
      tmp_instances,
      sizeof(void*) * MIN(stack->size, capacity));
    memcpy(stack->args,
      tmp_args,
      sizeof(void**) * MIN(stack->size, capacity));
    memcpy(stack->masks,
      tmp_masks,
      sizeof(char) * MIN(stack->size, capacity));
    for (size_t i = MIN(stack->size, capacity); i < stack->size; ++i) {
      __CALL_ACTION_N_ARGS__(tmp_actions[i],
                             tmp_instances[i],
                             tmp_args[i]);
    }
    free(tmp_actions);
    free(tmp_instances);
    free(tmp_masks);
    free(tmp_args);
  }
  stack->capacity = capacity;
  stack->size = MIN(stack->size, capacity);
  return stack->size;
}

void* __scope_stack_init__(__SCOPE_STACK__* stack) {
  stack->capacity = 0;
  stack->size = 0;
  __scope_stack_reserve__(stack, __SCOPE_STACK_INITIAL_CAPACITY__);
  __scope_stack_push__(stack, NULL, NULL, NULL);
  return stack;
}

size_t __scope_stack_destroy__(__SCOPE_STACK__* stack) {
  if (stack->capacity) {
    for (size_t i = stack->size; i > 0; --i) {
      if (!__scope_stack_indentation_predicate__(stack->instances[i - 1],
        stack->actions[i - 1])) {
        __CALL_ACTION_N_ARGS__(stack->actions[i - 1],
                               stack->instances[i - 1],
                               stack->args[i - 1]);
      }
    }
    free(stack->actions);
    free(stack->instances);
    free(stack->masks);
    free(stack->args);
  }
  *stack = (__SCOPE_STACK__){};
  return 0;
}

size_t __scope_stack_push__(__SCOPE_STACK__* stack,
                            generic_function_t action,
                            void* instance,
                            void** args) {
  if (stack->size + 1 == stack->capacity) {
    __scope_stack_reserve__(stack, stack->capacity * 2);
  }
  stack->actions[stack->size] = action;
  stack->instances[stack->size] = instance;
  stack->args[stack->size] = args;
  stack->masks[stack->size] = !__scope_stack_indentation_predicate__(instance, action);
  stack->size++;
  return stack->size;
}

size_t __scope_stack_pop__(__SCOPE_STACK__* stack) {
  stack->size--;
  if (__scope_stack_mask_get_active__(stack->masks + stack->size)) {
    __CALL_ACTION_N_ARGS__(stack->actions[stack->size],
      stack->instances[stack->size],
      stack->args[stack->size]);
  }
  if ((4 * stack->size < stack->capacity) &&
    (2 * stack->size > __SCOPE_STACK_INITIAL_CAPACITY__)) {
    __scope_stack_reserve__(stack, stack->capacity / 2);
  }
  return stack->size;
}

size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack) {
  size_t count_releases = 0;
  while (!__scope_stack_indentation_predicate__(stack->instances[stack->size - 1],
         stack->actions[stack->size - 1])) {
    if (stack->masks[stack->size - 1]) {
      count_releases++;
    }
    __scope_stack_pop__(stack);
  }
  __scope_stack_pop__(stack);
  return count_releases;
}

size_t __scope_stack_find__(__SCOPE_STACK__* stack,
                            generic_function_t action,
                            void* instance) {
  size_t i = stack->size;
  while (stack->instances[i - 1] != instance &&
    stack->actions[i - 1] != action &&
    __scope_stack_mask_get_active__(stack->masks + i)) {
    i--;
    if (i == 0) {
      return 0;
    }
  }
  return i - 1;
}

size_t __scope_stack_find_action__(__SCOPE_STACK__* stack, generic_function_t action) {
  size_t i = stack->size;
  while (stack->actions[i - 1] != action &&
    __scope_stack_mask_get_active__(stack->masks + i)) {
    i--;
    if (i == 0) {
      return 0;
    }
  }
  return i - 1;
}

size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack, void* instance) {
  size_t i = stack->size;
  while (stack->instances[i - 1] != instance &&
    __scope_stack_mask_get_active__(stack->masks + i)) {
    i--;
    if (i == 0) {
      return 0;
    }
  }
  return i - 1;
}

size_t __scope_stack_skip__(__SCOPE_STACK__* stack,
                            generic_function_t action,
                            void* instance) {
  size_t i = __scope_stack_find__(stack, action, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack, generic_function_t action) {
  size_t i = __scope_stack_find_action__(stack, action);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack, void* instance) {
  size_t i = __scope_stack_find_instance__(stack, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
                             __SCOPE_DEFER_POOL__* defer_pool,
                             generic_function_t action,
                             void* instance,
                             generic_function_t predicate,
                             void** predicate_args) {
  size_t i = __scope_stack_find__(stack, action, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(predicate,
                                             stack->instances[i],
                                             stack->actions[i],
                                             predicate_args)) {
    __CALL_ACTION_N_ARGS__(stack->actions[i],
                           stack->instances[i],
                           stack->args[i]);
    return 0;
  }
  __scope_defer_pool_push__(defer_pool,
    action,
    instance,
    stack->args[i],
    predicate,
    predicate_args);
  return stack->size;
}

size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
                                    __SCOPE_DEFER_POOL__* defer_pool,
                                    generic_function_t action,
                                    generic_function_t predicate,
                                    void** predicate_args) {
  size_t i = __scope_stack_find_action__(stack, action);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(predicate,
                                             stack->instances[i],
                                             stack->actions[i],
                                             predicate_args)) {
    if (i == stack->size - 1) {
      __scope_stack_pop__(stack);
    }
    __CALL_ACTION_N_ARGS__(stack->actions[i],
                           stack->instances[i],
                           stack->args[i]);
    return 0;
  }
  __scope_defer_pool_push__(defer_pool,
    action,
    stack->instances[i],
    stack->args[i],
    predicate,
    predicate_args);
  if (i == stack->size - 1) {
    __scope_stack_pop__(stack);
  }
  return stack->size;
}

size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
                                      __SCOPE_DEFER_POOL__* defer_pool,
                                      void* instance,
                                      generic_function_t predicate,
                                      void** predicate_args) {
  size_t i = __scope_stack_find_instance__(stack, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (i == stack->size - 1) {
    stack->size--;
  }
  if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(predicate,
                                             stack->instances[i],
                                             stack->actions[i],
                                             predicate_args)) {
    __CALL_ACTION_N_ARGS__(stack->actions[i],
                           stack->instances[i],
                           stack->args[i]);
    return 0;
  }
  __scope_defer_pool_push__(defer_pool,
    stack->actions[i],
    instance,
    stack->args[i],
    predicate,
    predicate_args);
  return stack->size;
}

void* __scope_stack_top__(__SCOPE_STACK__* stack) {
  return stack->instances[stack->size - 1];
}

size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack, generic_function_t predicate) {
  while (!predicate(stack->instances[stack->size - 1],
      stack->actions[stack->size - 1],
      stack,
    0)) {
    __scope_stack_pop__(stack);
  }
  return stack->size;
}

size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack) {
  while (!__scope_stack_pop__(stack));
}


size_t __scope_defer_chunk_reserve__(__SCOPE_DEFER_CHUNK__* chunk, size_t capacity) {
  generic_function_t* tmp_predicates = chunk->predicates;
  generic_function_t* tmp_actions = chunk->actions;
  void** tmp_instances = chunk->instances;
  void*** tmp_args = chunk->args;
  void*** tmp_predicate_args = chunk->predicate_args;
  chunk->predicates = (generic_function_t*)calloc(capacity, sizeof(generic_function_t));
  chunk->actions = (generic_function_t*)calloc(capacity, sizeof(generic_function_t));
  chunk->instances = (void**)calloc(capacity, sizeof(void*));
  chunk->args = (void***)calloc(capacity, sizeof(void**));
  chunk->predicate_args = (void***)calloc(capacity, sizeof(void**));
  if (chunk->capacity) {
    memcpy(chunk->predicates,
      tmp_predicates,
      sizeof(generic_function_t) * MIN(chunk->size, capacity));
    memcpy(chunk->actions,
      tmp_actions,
      sizeof(generic_function_t) * MIN(chunk->size, capacity));
    memcpy(chunk->instances,
      tmp_instances,
      sizeof(void*) * MIN(chunk->size, capacity));
    memcpy(chunk->args,
      tmp_args,
      sizeof(void**) * MIN(chunk->size, capacity));
    memcpy(chunk->predicate_args,
      tmp_predicate_args,
      sizeof(void**) * MIN(chunk->size, capacity));
    for (size_t i = MIN(chunk->size, capacity); i < chunk->size; ++i) {
      __CALL_ACTION_N_ARGS__(chunk->actions[i],
                             chunk->instances[i],
                             chunk->args[i]);
    }
    free(tmp_predicates);
    free(tmp_actions);
    free(tmp_instances);
    free(tmp_args);
    free(tmp_predicate_args);
  }
  chunk->capacity = capacity;
  chunk->size = MIN(chunk->size, capacity);
  return chunk->size;
}

void* __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk) {
  chunk->capacity = 0;
  chunk->size = 0;
  chunk->bias_sum = 0;
  chunk->min_indentation = __UINT64_MAX__;
  __scope_defer_chunk_reserve__(chunk, __SCOPE_DEFER_CHUNK_INITIAL_CAPACITY__);
  return chunk;
}

size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk) {
  if (chunk->capacity) {
    for (size_t i = 0; i < chunk->size; ++i) {
      __CALL_ACTION_N_ARGS__(chunk->actions[i], chunk->instances[i], chunk->args[i]);
    }
  }
  free(chunk->predicates);
  free(chunk->actions);
  free(chunk->instances);
  free(chunk->args);
  free(chunk->predicate_args);
  *chunk = (__SCOPE_DEFER_CHUNK__){};
  return 0;
}

#define __TEMPLATE__
#define __T_ARG_A__ defer_pool_tree
#define __T_ARG_B__ __DEFER_POOL_NODE__
#define __T_ARG_C__ __compare_defer_pool_node__
#include "../oop/templates.h"

size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
                                  generic_function_t action,
                                  void* instance,
                                  void** args,
                                  generic_function_t predicate,
                                  void** predicate_args,
                                  size_t indentation) {
  if (chunk->size + 1 == chunk->capacity) {
    __scope_defer_chunk_reserve__(chunk, 2 * chunk->capacity);
  }
  chunk->bias_sum += 1;
  chunk->min_indentation = MIN(chunk->min_indentation, indentation);
  chunk->actions[chunk->size] = action;
  chunk->instances[chunk->size] = instance;
  chunk->predicates[chunk->size] = predicate;
  chunk->args[chunk->size] = args;
  chunk->predicate_args[chunk->size] = predicate_args;
  return ++chunk->size;
}

size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
                                   __SCOPE_DEFER_POOL__* pool) {
  for (size_t i = chunk->size; i > 0; --i) {
    if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(chunk->predicates[i - 1],
                                               chunk->instances[i - 1],
                                               chunk->actions[i - 1],
                                               chunk->predicate_args[i - 1])) {
      chunk->bias_sum += pool->chunk_bias_pos;
      __CALL_ACTION_N_ARGS__(chunk->actions[i - 1],
                             chunk->instances[i - 1],
                             chunk->args[i - 1]);
      free(chunk->predicate_args[i - 1]);
      chunk->size--;
      RBNode* root = (RBNode*)pool->tree_root;
      __TEMPLATE_1(__T_ARG_A__, rbDelete)((__DEFER_POOL_NODE__){.action=chunk->actions[i - 1], .instance=chunk->instances[i - 1]}, &root);
      pool->tree_root = (void*)root;
      chunk->actions[i - 1] = chunk->actions[chunk->size];
      chunk->instances[i - 1] = chunk->instances[chunk->size];
      chunk->predicates[i - 1] = chunk->predicates[chunk->size];
      chunk->args[i - 1] = chunk->args[chunk->size];
      chunk->predicate_args[i - 1] = chunk->predicate_args[chunk->size];
    } else {
      chunk->bias_sum -= pool->chunk_bias_neg;
    }
  }
  return chunk->size;
}

size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk) {
  return chunk->bias_sum;
}

size_t __scope_defer_chunk_find__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance) {
  for (size_t i = chunk->size; i > 0; --i) {
    if (action && (action == chunk->actions[i - 1])) {
      if (instance && (instance == chunk->instances[i - 1])) {
        return i - 1;
      } else if (!instance) {
        return i - 1;
      }
    } else if (!action && (instance == chunk->instances[i - 1])) {
      return i - 1;
    }
  }
  return (size_t)-1;
}

size_t __scope_defer_chunk_skip__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance) {
  size_t index = __scope_defer_chunk_find__(chunk, action, instance);
  if (index > chunk->size) {
    return (size_t)-1;
  }
  chunk->size--;
  if (chunk->size > 0) {
    chunk->actions[index] = chunk->actions[chunk->size];
    chunk->instances[index] = chunk->instances[chunk->size];
    chunk->args[index] = chunk->args[chunk->size];
    chunk->predicates[index] = chunk->predicates[chunk->size];
    chunk->predicate_args[index] = chunk->predicate_args[chunk->size];
  }
  return chunk->size;
}


size_t __scope_defer_pool_reserve__(__SCOPE_DEFER_POOL__* pool, size_t capacity) {
  __SCOPE_DEFER_CHUNK__* tmp_chunks = pool->chunks;
  pool->chunks = (__SCOPE_DEFER_CHUNK__*)calloc(capacity, sizeof(__SCOPE_DEFER_CHUNK__));
  if (pool->capacity) {
    size_t index_shift = 0;
    for (size_t i = 0; i < pool->capacity; ++i) {
      if (!(tmp_chunks[i].size && i < pool->size)) {
        __scope_defer_chunk_destroy__(&(tmp_chunks[i]));
        index_shift++;
      } else {
        pool->chunks[i - index_shift] = tmp_chunks[i];
      }
    }
    free(tmp_chunks);
  }
  pool->capacity = capacity;
  pool->size = MIN(pool->size, capacity);
  return pool->size;
}

void* __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool) {
  pool->active_size = 0;
  pool->size = 0;
  pool->capacity = 0;
  pool->chunk_bias_neg = __SCOPE_DEFER_POOL_DEFAULT_NEGATIVE_BIAS__;
  pool->chunk_bias_pos = __SCOPE_DEFER_POOL_DEFAULT_POSITIVE_BIAS__;
  pool->indentation = 0;
  pool->tokens = 0;
  pool->tree_root = NULL;
  __scope_defer_pool_reserve__(pool, __SCOPE_DEFER_POOL_INITIAL_CAPACITY__);
  return pool;
}

size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool) {
  for (size_t i = 0; i < pool->size; ++i) {
    __scope_defer_chunk_destroy__(&(pool->chunks[i]));
  }
  free(pool->chunks);
  __TEMPLATE_1(__T_ARG_A__, freeTree)((RBNode*)pool->tree_root);
  *pool = (__SCOPE_DEFER_POOL__){};
  return 0;
}

size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
                                 generic_function_t action,
                                 void* instance,
                                 void** args,
                                 generic_function_t predicate,
                                 void** predicate_args) {
  if (pool->indentation < pool->size) {
    __scope_defer_chunk_push__(&(pool->chunks[pool->indentation]),
                               action,
                               instance,
                               args,
                               predicate,
                               predicate_args,
                               pool->indentation);
    RBNode* root = (RBNode*)pool->tree_root;
    __TEMPLATE_1(__T_ARG_A__, rbInsert)((__DEFER_POOL_NODE__){.action = action, .instance=instance},
                                        (void*)pool->indentation, &root);
    pool->tree_root = (void*)root;
  } else {
    if (pool->size + 1 == pool->capacity) {
      __scope_defer_pool_reserve__(pool, pool->capacity * 2);
    }
    __scope_defer_chunk_init__(&(pool->chunks[pool->size]));
    __scope_defer_chunk_push__(&(pool->chunks[pool->size]),
                               action,
                               instance,
                               args,
                               predicate,
                               predicate_args,
                               pool->indentation);
    RBNode* root = (RBNode*)pool->tree_root;
    __TEMPLATE_1(__T_ARG_A__, rbInsert)((__DEFER_POOL_NODE__){.action = action, .instance=instance},
                                        (void*)pool->size, &root);
    pool->tree_root = (void*)root;
    pool->size++;
    pool->active_size++;
  }
  return pool->size;
}

size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool) {
  size_t count_releases = 0;
  size_t tmp_size;
  for(size_t i = pool->size; (pool->tokens > 0) && (i > 0) &&
      (pool->chunks[i - 1].min_indentation >= pool->indentation - 1); --i) {
    if (pool->chunks[i - 1].bias_sum >= 0) {
      pool->tokens = MIN(pool->tokens - pool->chunks[i - 1].size, 0);
      tmp_size = pool->chunks[i - 1].size;
      count_releases += tmp_size - __scope_defer_chunk_check__(&(pool->chunks[i - 1]),
                                                               pool);
      pool->chunks[i - 1].bias_sum /= 2;
      if (!pool->chunks[i - 1].size) {
        pool->active_size--;
      }
    } else {
      pool->chunks[i - 1].bias_sum /= 2;
      pool->chunks[i - 1].bias_sum += pool->chunk_bias_pos * MIN(pool->tokens,
                                                                 pool->chunks[i - 1].size);
    }
  }
  if ((pool->active_size * 4 < pool->capacity)  &&
      (2 * pool->active_size > __SCOPE_DEFER_POOL_INITIAL_CAPACITY__)) {
    __scope_defer_pool_reserve__(pool, pool->active_size * 2);
  }
  return count_releases;
}

size_t __scope_defer_pool_enter__(__SCOPE_DEFER_POOL__* pool) {
  pool->indentation++;
  return pool->size;
}

size_t __scope_defer_pool_escape__(__SCOPE_DEFER_POOL__* pool) {
  __scope_defer_pool_check__(pool);
  pool->indentation--;
  return pool->size;
}

size_t __scope_defer_pool_add_token__(__SCOPE_DEFER_POOL__* pool){
  pool->tokens++;
  return pool->size;
}

size_t __scope_defer_pool_skip__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action) {
  RBNode* root = (RBNode*)pool->tree_root;
  RBNode* node = __TEMPLATE_1(__T_ARG_A__, rbFind)((__DEFER_POOL_NODE__){.action = action,.instance=instance},
                                                   &root);
  __TEMPLATE_1(__T_ARG_A__, rbDelete)((__DEFER_POOL_NODE__){.action = action, .instance=instance},
                                      &root);
  pool->tree_root = (void*)root;
  return (size_t)(node > 0);
}

size_t __scope_defer_pool_force__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action) {

  size_t chunk = __scope_defer_pool_find__(pool, instance, action);

  if (chunk >= pool->size) {
    return (size_t)-1;
  }

  size_t index = __scope_defer_chunk_find__(&(pool->chunks[chunk]), action, instance);

  if (index > pool->chunks[chunk].size) {
    return (size_t)-1;
  }

  __CALL_ACTION_N_ARGS__(pool->chunks[chunk].actions[index],
                         pool->chunks[chunk].instances[index],
                         pool->chunks[chunk].args[index]);
  
  RBNode* root = (RBNode*)pool->tree_root;
  __TEMPLATE_1(__T_ARG_A__, rbDelete)((__DEFER_POOL_NODE__){.action = action,.instance=instance},
                                      &root);
  pool->tree_root = (void*)root;

  pool->chunks[chunk].size--;
  if (!pool->chunks[chunk].size) {
    pool->active_size--;
    return (size_t)-1;
  }

  pool->chunks[chunk].actions[index] = pool->chunks[chunk].actions[pool->chunks[chunk].size];
  pool->chunks[chunk].instances[index] = pool->chunks[chunk].instances[pool->chunks[chunk].size];
  pool->chunks[chunk].args[index] = pool->chunks[chunk].args[pool->chunks[chunk].size];
  pool->chunks[chunk].predicates[index] = pool->chunks[chunk].predicates[pool->chunks[chunk].size];
  pool->chunks[chunk].predicate_args[index] = pool->chunks[chunk].predicate_args[pool->chunks[chunk].size];

  return chunk;
}

size_t __scope_defer_pool_find__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action) {
  RBNode* root = (RBNode*)pool->tree_root;
  RBNode* node = __TEMPLATE_1(__T_ARG_A__, rbFind)((__DEFER_POOL_NODE__){.action = action,.instance=instance},
                                                   &root);
  pool->tree_root = (void*)root;
  if (!node) {
    return (size_t)-1;
  }
  return (size_t)node->data;
}


void* __scope_object_init__(__SCOPE_OBJECT__* scope,
                            __SCOPE_STACK__* stack,
                            __SCOPE_DEFER_POOL__* pool) {
  scope->stack = stack;
  scope->defer_pool = pool;
  scope->size = 0;
  scope->mask = 3;
  __scope_stack_init__(scope->stack);
  __scope_defer_pool_init__(scope->defer_pool);
  __scope_defer_pool_add_token__(scope->defer_pool);
  return scope;
}

size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope) {
  if (!scope->stack) {
    return 0;
  }
  __scope_stack_destroy__(scope->stack);
  __scope_defer_pool_destroy__(scope->defer_pool);
  *scope = (__SCOPE_OBJECT__){};
  return 0;
}

size_t __scope_object_enter__(__SCOPE_OBJECT__* scope) {
  if (!scope->stack) {
    return 0;
  }
  __scope_stack_push__(scope->stack, NULL, NULL, NULL);
  if (scope->mask) {
    __scope_defer_pool_enter__(scope->defer_pool);
  } else {
    scope->defer_pool->indentation++;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_lock_pool__(__SCOPE_OBJECT__* scope) {
  scope->mask = (scope->mask || 1) ^ 1;
  return 0;
}

size_t __scope_object_unlock_pool__(__SCOPE_OBJECT__* scope) {
  scope->mask = scope->mask || 1;
  return 0;
}

size_t __scope_object_escape__(__SCOPE_OBJECT__* scope) {
  if (!scope->stack) {
    return 0;
  }
  scope->size -= __scope_stack_pop_top__(scope->stack);
  if (scope->mask && 1) {
    scope->size -= __scope_defer_pool_escape__(scope->defer_pool);
  } else {
    scope->defer_pool->indentation--;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_push__(__SCOPE_OBJECT__* scope,
                             void* instance,
                             generic_function_t action,
                             ...) {
  if (!scope->stack) {
    return 0;
  }
  va_list __ARGUMENT_POINTERS__;
  void* __args_stack__[__SCOPE_OBJECT_STACK_ARGUMENT_SIZE__] = {};
  void** args = __args_stack__;
  size_t __ARG_CNT__ = 0;
  size_t args_capacity = __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__;
  {
    va_start(__ARGUMENT_POINTERS__, action);
    for (size_t i = 0;
         (i < __SCOPE_OBJECT_MAX_ARGUMENT_COUNT__) &&
         (args[i] = va_arg(__ARGUMENT_POINTERS__, void*));
         ++i) {
      __ARG_CNT__++;
      if (__ARG_CNT__ == args_capacity) {
        if (__ARG_CNT__ == __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__) {
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          memcpy(args, __args_stack__, args_capacity);
        } else {
          void** tmp_args = args;
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          memcpy(args, tmp_args, args_capacity);
          free(tmp_args);
        }
        args_capacity *= 2;
      }
    }
    va_end(__ARGUMENT_POINTERS__);
  }
  if (args_capacity == __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__) {
    if (__ARG_CNT__ > 0) {
      args = (void**)malloc(sizeof(void*) * (__ARG_CNT__ + 1));
      memcpy(args, __args_stack__, args_capacity);
    } else {
      args = 0;
    }
  }
  if (args) {
    args[__ARG_CNT__] = NULL;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  __scope_stack_push__(scope->stack, action, instance, args);
  if (action || instance) {
    scope->size++;
  }
  return 0;
}


size_t __scope_object_defer__(__SCOPE_OBJECT__* scope,
                              void* instance,
                              generic_function_t action,
                              generic_function_t predicate,
                              ...) {
  if (!scope->stack) {
    return 0;
  }
  va_list __ARGUMENT_POINTERS__;
  void* __args_stack__[__SCOPE_OBJECT_STACK_ARGUMENT_SIZE__] = {};
  void** args = __args_stack__;
  size_t __ARG_CNT__ = 0;
  size_t args_capacity = __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__;
  {
    va_start(__ARGUMENT_POINTERS__, predicate);
    for (size_t i = 0;
         (i < __SCOPE_OBJECT_MAX_ARGUMENT_COUNT__) &&
         (args[i] = va_arg(__ARGUMENT_POINTERS__, void*));
         ++i) {
      __ARG_CNT__++;
      if (__ARG_CNT__ + 1 == args_capacity) {
        if (__ARG_CNT__ + 1 == __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__) {
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          memcpy(args, __args_stack__, args_capacity);
        } else {
          void** tmp_args = args;
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          memcpy(args, tmp_args, args_capacity);
          free(tmp_args);
        }
        args_capacity *= 2;
      }
    }
    va_end(__ARGUMENT_POINTERS__);
  }
  if (args_capacity == __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__) {
    if (__ARG_CNT__ > 0) {
      args = (void**)malloc(sizeof(void*) * (__ARG_CNT__ + 1));
      memcpy(args, __args_stack__, args_capacity);
    } else {
      args = 0;
    }
  }
  if (args) {
    args[__ARG_CNT__] = NULL;
  }
  size_t result;
  if (action && instance) {
    result = __scope_stack_defer__(scope->stack,
                                   scope->defer_pool,
                                   action,
                                   instance,
                                   predicate,
                                   args);
  } else if (action) {
    result = __scope_stack_defer_action__(scope->stack,
                                          scope->defer_pool,
                                          action,
                                          predicate,
                                          args);
  } else {
    result = __scope_stack_defer_instance__(scope->stack,
                                            scope->defer_pool,
                                            instance,
                                            predicate,
                                            args);
  }
  if (!result && scope->stack->size) {
    scope->size--;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_stage__(__SCOPE_OBJECT__* scope,
                              void* instance,
                              generic_function_t action,
                              ...) {
  if (!scope->stack) {
    return 0;
  }
  BOOL is_staged = FALSE;
  if (instance) {
    if (action) {
      if (scope->stack->actions[scope->stack->size - 1] == action &&
          scope->stack->instances[scope->stack->size - 1] == instance) {
        is_staged = TRUE;
      }
    } else {
      if (scope->stack->instances[scope->stack->size - 1] == instance) {
        is_staged = TRUE;
      }
    }
  } else {
    if (scope->stack->actions[scope->stack->size - 1] == action) {
      is_staged = TRUE;
    }
  }
  va_list __ARGUMENT_POINTERS__;
  void* __args_stack__[__SCOPE_OBJECT_STACK_ARGUMENT_SIZE__] = {};
  void** args = __args_stack__;
  size_t __ARG_CNT__ = 0;
  size_t args_capacity = __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__;
  generic_function_t predicate = (generic_function_t)NULL;
  {
    va_start(__ARGUMENT_POINTERS__, action);
    if (is_staged) {
      predicate = (generic_function_t)va_arg(__ARGUMENT_POINTERS__, void*);
    }
    for (size_t i = 0;
         (i < __SCOPE_OBJECT_MAX_ARGUMENT_COUNT__) &&
         (args[i] = va_arg(__ARGUMENT_POINTERS__, void*));
         ++i) {
      __ARG_CNT__++;
      if (__ARG_CNT__ + 1 == args_capacity) {
        if (__ARG_CNT__ + 1 == __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__) {
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          memcpy(args, __args_stack__, args_capacity);
        } else {
          void** tmp_args = args;
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          memcpy(args, tmp_args, args_capacity);
          free(tmp_args);
        }
        args_capacity *= 2;
      }
    }
    va_end(__ARGUMENT_POINTERS__);
  }
  if (args_capacity == __SCOPE_OBJECT_STACK_ARGUMENT_SIZE__) {
    if (__ARG_CNT__ > 0) {
      args = (void**)malloc(sizeof(void*) * (__ARG_CNT__ + 1));
      memcpy(args, __args_stack__, sizeof(void*) * (__ARG_CNT__ + 1));
    } else {
      args = 0;
    }
  }
  if (args) {
    args[__ARG_CNT__] = NULL;
  }
  if (is_staged) {
    size_t result;
    if (action && instance) {
      result = __scope_stack_defer__(scope->stack,
                                    scope->defer_pool,
                                    action,
                                    instance,
                                    predicate,
                                    args);
    } else if (action) {
      result = __scope_stack_defer_action__(scope->stack,
                                            scope->defer_pool,
                                            action,
                                            predicate,
                                            args);
    } else {
      result = __scope_stack_defer_instance__(scope->stack,
                                              scope->defer_pool,
                                              instance,
                                              predicate,
                                              args);
    }
    if (!result && scope->stack->size) {
      scope->size--;
    }
  } else {
    __scope_stack_push__(scope->stack, action, instance, args);
    if (action || instance) {
      scope->size++;
    }
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_skip__(__SCOPE_OBJECT__* scope,
                             void* instance,
                             generic_function_t action) {
  RBNode* root = (RBNode*)scope->defer_pool->tree_root;
  RBNode* node = __TEMPLATE_1(__T_ARG_A__, rbFind)((__DEFER_POOL_NODE__){
                                                   .action=action,
                                                   .instance=instance},
                                                   &root);
  if (!scope->stack) {
    return 0;
  }
  if (node) {
    __scope_defer_pool_skip__(scope->defer_pool, instance, action);
  } else {
    if (action && instance) {
      __scope_stack_skip__(scope->stack, action, instance);
    } else if (action) {
      __scope_stack_skip_action__(scope->stack, action);
    } else {
      __scope_stack_skip_instance__(scope->stack, instance);
    }
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_force__(__SCOPE_OBJECT__* scope,
                              void* instance,
                              generic_function_t action) {
  RBNode* root = (RBNode*)scope->defer_pool->tree_root;
  RBNode* node = __TEMPLATE_1(__T_ARG_A__, rbFind)((__DEFER_POOL_NODE__){
                                                   .action=action,
                                                   .instance=instance},
                                                   &root);
  if (!scope->stack) {
    return 0;
  }
  if (node) {
    __scope_defer_pool_force__(scope->defer_pool, instance, action);
  } else {
    size_t index = 0;
    if (action && instance) {
      index = __scope_stack_find__(scope->stack, action, instance);
    } else if (action) {
      index = __scope_stack_find_action__(scope->stack, action);
    } else {
      index = __scope_stack_find_instance__(scope->stack, instance);
    }
    if (index >= scope->stack->size) {
      return 0;
    }
    __CALL_ACTION_N_ARGS__(scope->stack->actions[index],
                           scope->stack->instances[index],
                           scope->stack->args[index]);
    scope->stack->masks[index] = 0;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 1;
}

size_t __scope_object_change_bias__(__SCOPE_OBJECT__* scope,
                                    size_t bias_positive,
                                    size_t bias_negative) {
  scope->defer_pool->chunk_bias_pos = bias_positive;
  scope->defer_pool->chunk_bias_neg = bias_negative;
  return 0;
}

#include "../oop/templates_undef.h"


__SCOPE_STACK__ __SCOPE_STACK_INST__ = (__SCOPE_STACK__){};
__SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__ = (__SCOPE_DEFER_POOL__){};
__SCOPE_OBJECT__ __SCOPE_OBJECT_INST__ = (__SCOPE_OBJECT__){};


void* __SCOPE_BEGIN__(__SCOPE_OBJECT__* scope,
  __SCOPE_DEFER_POOL__* pool,
  __SCOPE_STACK__* stack) {
  if (scope->mask & 2) {
    return (void*)__scope_object_enter__(scope);
  }
  __scope_object_init__(scope, stack, pool);
  return (void*)__scope_object_enter__(scope);
}

void* __SCOPE_END__(__SCOPE_OBJECT__* scope) {
  __scope_object_escape__(scope);
  if (scope->defer_pool->indentation == 0) {
    __scope_object_destroy__(scope);
  }
  return NULL;
}

void* __SCOPE_CALLOC__(__SCOPE_OBJECT__* scope,
                       size_t size,
                       size_t type_size,
                       void* filler,
                       ...) {
  void* data;
  if (filler) {
    data = malloc(size * type_size);
    for (size_t i = 0; i < size; ++i) {
      memcpy(data + type_size * i, filler, type_size);
    }
  } else {
    data = calloc(size, type_size);
  }
  SCOPE_PUSH(data, free);
  return data;
}

void* __SCOPE_FREE__(__SCOPE_OBJECT__* scope, void* data) {
  __scope_object_skip__(scope, data, (generic_function_t)free);
  free(data);
  return NULL;
}

void* __SCOPE_FORCED_RELEASE__(__SCOPE_OBJECT__* scope,
                               void* data,
                               generic_function_t action,
                               ...) {
  __scope_object_force__(scope, data, action);
  return 0;
}

void* __SCOPE_SKIP__(__SCOPE_OBJECT__* scope,
                     void* data,
                     generic_function_t action,
                     ...) {
  __scope_object_skip__(scope, data, action);
  return 0;
}

typedef struct __SCOPE_OBJECT_TRIPLET__ {
  __SCOPE_OBJECT__ obj;
  __SCOPE_STACK__ stack;
  __SCOPE_DEFER_POOL__ pool;
} __SCOPE_OBJECT_TRIPLET__;

__SCOPE_OBJECT__* __LOCAL_SCOPE_NEW__() {
  __SCOPE_OBJECT_TRIPLET__* scope = (__SCOPE_OBJECT_TRIPLET__*)malloc(sizeof(__SCOPE_OBJECT_TRIPLET__));
  return (__SCOPE_OBJECT__*)__scope_object_init__(&(scope->obj), &(scope->stack), &(scope->pool));
}

void* __LOCAL_SCOPE_FREE__(__SCOPE_OBJECT__* local_scope) {
  __scope_object_destroy__(local_scope);
  free(local_scope);
  return NULL;
}

void* __DEFAULT_PREDICATE__(void* instance, ...) {
  return NULL;
}

void* __TRUE_PREDICATE__(void* instance, ...) {
  return (void*)TRUE;
}

void* __FALSE_PREDICATE__(void* instance, ...) {
  return (void*)FALSE;
}

