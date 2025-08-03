#include "dyn_alloc_.h"


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
  return (instance > 0) && (action > 0);
}

BOOL __scope_stack_indentation_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) && (action == 0);
}

BOOL __scope_stack_skip_predicate__(void* instance, generic_function_t action) {
  return (instance > 0) && (action == 0);
}

BOOL __scope_stack_callable_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) && (action > 0);
}


size_t __scope_stack_reserve__(__SCOPE_STACK__* stack, size_t capacity) {
  generic_function_t* tmp_actions = stack->actions;
  void** tmp_instances = stack->instances;
  char* tmp_masks = stack->masks;
  stack->actions = (generic_function_t*)malloc(sizeof(generic_function_t) * capacity);
  stack->instances = (void**)malloc(sizeof(void*) * capacity);
  stack->masks = (char*)malloc(capacity);
  if (stack->capacity) {
    memcpy(stack->actions,
      tmp_actions,
      sizeof(generic_function_t) * MIN(stack->size, capacity));
    memcpy(stack->instances,
      tmp_instances,
      sizeof(void*) * MIN(stack->size, capacity));
    memcpy(stack->masks,
      tmp_masks,
      sizeof(char) * MIN(stack->size, capacity));
    for (size_t i = MIN(stack->size, capacity); i < stack->size; ++i) {
      if (stack->actions[i - 1]) {
        stack->actions[i - 1](stack->instances[i - 1], 0);
      } else {
        ((generic_function_t)stack->instances[i - 1])(0);
      }
    }
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
    for (size_t i = stack->size; i > 0; --i) {
      if (!__scope_stack_indentation_predicate__(stack->instances[i - 1],
        stack->actions[i - 1])) {
        if (stack->actions[i - 1]) {
          stack->actions[i - 1](stack->instances[i - 1], 0);
        } else {
          ((generic_function_t)stack->instances[i - 1])(0);
        }
      }
    }
    free(stack->actions);
    free(stack->instances);
    free(stack->masks);
  }
  *stack = (__SCOPE_STACK__){0};
  return 0;
}

size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance) {
  if (stack->size + 1 == stack->capacity) {
    __scope_stack_reserve__(stack, stack->capacity * 2);
  }
  stack->actions[stack->size] = action;
  stack->instances[stack->size] = instance;
  stack->masks[stack->size] = __scope_stack_regular_predicate__(instance, action);
  stack->size++;
  return stack->size;
}

size_t __scope_stack_pop__(__SCOPE_STACK__* stack) {
  stack->size--;
  if (__scope_stack_mask_get_active__(stack->masks + stack->size)) {
    (stack->actions[stack->size])((stack->instances[stack->size]), 0);
  } else {
    if (__scope_stack_callable_predicate__(stack->instances[stack->size],
      stack->actions[stack->size])) {
        ((generic_function_t)(stack->instances[stack->size]))(0);
      }
  }
  if ((4 * stack->size < stack->capacity) &&
    (2 * stack->size > __SCOPE_STACK_INITIAL_CAPACITY__)) {
    __scope_stack_reserve__(stack, stack->capacity / 2);
  }
  return stack->size;
}

size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack) {
  size_t i = stack->size - 1;
  while (!__scope_stack_indentation_predicate__(stack->instances[i], stack->actions[i]))
  {
    __scope_stack_pop__(stack);
  }
  __scope_stack_pop__(stack);
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

size_t __scope_stack_find_action__(__SCOPE_STACK__* stack,
  generic_function_t action) {
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

size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack,
  void* instance) {
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

size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack,
  generic_function_t action) {
  size_t i = __scope_stack_find_action__(stack, action);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack,
  void* instance) {
  size_t i = __scope_stack_find_instance__(stack, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  void* instance,
  generic_function_t predicate) {
  size_t i = __scope_stack_find__(stack, action, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (predicate(instance, action)) {
    if (action) {
      action(instance, 0);
    } else {
      ((generic_function_t)instance)(0);
    }
    return 0;
  }
  __scope_defer_pool_push__(defer_pool, action, instance, predicate);
  return stack->size;
}

size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  generic_function_t predicate) {
  size_t i = __scope_stack_find_action__(stack, action);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (predicate(stack->instances[i], action)) {
    action(stack->instances[i]);
    return 0;
  }
  __scope_defer_pool_push__(defer_pool, action, stack->instances[i], predicate);
  return stack->size;
}

size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  void* instance,
  generic_function_t predicate) {
  size_t i = __scope_stack_find_instance__(stack, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (i == stack->size - 1) {
    stack->size--;
  }
  if (predicate(instance, stack->actions[i])) {
    if (stack->actions[i]) {
      stack->actions[i](instance, 0);
    } else {
      ((generic_function_t)instance)(0);
    }
    return 0;
  }
  __scope_defer_pool_push__(defer_pool, stack->actions[i], instance, predicate);
  return stack->size;
}

void* __scope_stack_top__(__SCOPE_STACK__* stack) {
  return stack->instances[stack->size - 1];
}

size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  generic_function_t predicate) {
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
  chunk->predicates = (generic_function_t*)malloc(sizeof(generic_function_t) * capacity);
  chunk->actions = (generic_function_t*)malloc(sizeof(generic_function_t) * capacity);
  chunk->instances = (void**)malloc(sizeof(void*) * capacity);
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
    for (size_t i = MIN(chunk->size, capacity); i < chunk->size; ++i) {
      if (chunk->actions[i - 1]) {
        chunk->actions[i - 1](chunk->instances[i - 1], 0);
      } else {
        ((generic_function_t)chunk->instances[i - 1])(0);
      }
    }
    free(tmp_predicates);
    free(tmp_actions);
    free(tmp_instances);
  }
  chunk->capacity = capacity;
  chunk->size = MIN(chunk->size, capacity);
  return chunk->size;
}

size_t __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk) {
  chunk->capacity = 0;
  chunk->size = 0;
  __scope_defer_chunk_reserve__(chunk, __SCOPE_DEFER_CHUNK_INITIAL_CAPACITY__);
  return 0;
}

size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk) {
  if (chunk->capacity) {
    for (size_t i = chunk->size; i > 0; --i) {
      if (chunk->actions[i - 1]) {
        chunk->actions[i - 1](chunk->instances[i - 1], 0);
      } else {
        ((generic_function_t)chunk->instances[i - 1])(0);
      }
    }
  }
  free(chunk->predicates);
  free(chunk->actions);
  free(chunk->instances);
  *chunk = (__SCOPE_DEFER_CHUNK__){0};
  return 0;
}

size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance,
  generic_function_t predicate) {
  if (chunk->size + 1 == chunk->capacity) {
    __scope_defer_chunk_reserve__(chunk, 2 * chunk->capacity);
  }
  chunk->actions[chunk->size] = action;
  chunk->instances[chunk->size] = instance;
  chunk->predicates[chunk->size] = predicate;
  return ++chunk->size;
}

size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
  size_t bias_positive,
  size_t bias_negative) {
  for (size_t i = chunk->size; i > 0; --i) {
    if (chunk->predicates[i - 1](chunk->instances[i - 1], chunk->actions[i - 1])) {
      chunk->bias_sum += bias_positive;
      if (chunk->actions[i - 1]) {
        chunk->actions[i - 1](chunk->instances[i - 1], 0);
      } else {
        ((generic_function_t)chunk->instances[i - 1])(0);
      }
      chunk->size--;
      chunk->actions[i - 1] = chunk->actions[chunk->size];
      chunk->instances[i - 1] = chunk->instances[chunk->size];
      chunk->predicates[i - 1] = chunk->instances[chunk->size];
    } else {
      chunk->bias_sum -= bias_negative;
    }
  }
  return chunk->size;
}

size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk) {
  return chunk->bias_sum;
}


size_t __scope_defer_pool_reserve__(__SCOPE_DEFER_POOL__* pool, size_t capacity) {
  __SCOPE_DEFER_CHUNK__* tmp_chunks = pool->chunks;
  pool->chunks = (__SCOPE_DEFER_CHUNK__*)malloc(sizeof(__SCOPE_DEFER_CHUNK__) * capacity);
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

size_t __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool) {
  pool->active_size = 0;
  pool->size = 0;
  pool->capacity = 0;
  pool->chunk_bias_neg = 1;
  pool->chunk_bias_pos = 4;
  pool->indentation = 0;
  pool->tokens = 0;
  __scope_defer_pool_reserve__(pool, __SCOPE_DEFER_POOL_INITIAL_CAPACITY__);
  return 0;
}

size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool) {
  for (size_t i = 0; i < pool->size; ++i) {
    __scope_defer_chunk_destroy__(&(pool->chunks[i]));
  }
  *pool = (__SCOPE_DEFER_POOL__){0};
  return 0;
}

size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
  generic_function_t action,
  void* instance,
  generic_function_t predicate) {
  if (pool->indentation < pool->size) {
    __scope_defer_chunk_push__(&(pool->chunks[pool->indentation]),
      action,
      instance,
      predicate);
  } else {
    if (pool->size + 1 == pool->capacity) {
      __scope_defer_pool_reserve__(pool, pool->capacity * 2);
    }
    __scope_defer_chunk_init__(&(pool->chunks[pool->size]));
    __scope_defer_chunk_push__(&(pool->chunks[pool->size]),
      action,
      instance,
      predicate);
    pool->size++;
  }
  pool->active_size++;
  return pool->size;
}

size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool) {
  for(size_t i = pool->size; (pool->tokens > 0) && (i > pool->indentation - 1); --i) {
    if (pool->chunks[i - 1].bias_sum >= 0) {
      pool->tokens = MIN(pool->tokens - pool->chunks[i - 1].size, 0);
      __scope_defer_chunk_check__(&(pool->chunks[i - 1]),
        pool->chunk_bias_pos,
        pool->chunk_bias_neg);
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


size_t __scope_object_init__(__SCOPE_OBJECT__* scope,
  __SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* pool) {
  scope->stack = stack;
  scope->defer_pool = pool;
  __scope_stack_init__(scope->stack);
  __scope_defer_pool_init__(scope->defer_pool);
  return 0;
}

size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope) {
  __scope_stack_destroy__(scope->stack);
  __scope_defer_pool_destroy__(scope->defer_pool);
  *scope = (__SCOPE_OBJECT__){0};
  return 0;
}

size_t __scope_object_enter__(__SCOPE_OBJECT__* scope) {
  __scope_stack_push__(scope->stack, NULL, NULL);
  __scope_defer_pool_enter__(scope->defer_pool);
  return 0;
}

size_t __scope_object_escape__(__SCOPE_OBJECT__* scope) {
  __scope_defer_pool_escape__(scope->defer_pool);
  return 0;
}

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


__SCOPE_STACK__ __SCOPE_STACK_INST__ = (__SCOPE_STACK__){0};
__SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__ = (__SCOPE_DEFER_POOL__){0};
__SCOPE_OBJECT__ __SCOPE_OBJECT_INST__ = (__SCOPE_OBJECT__){0};
