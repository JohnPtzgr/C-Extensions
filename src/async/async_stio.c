#include "async_stio.h"
#include "pthread.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "unistd.h"


async_handler_t __AUX_MT_SCOPE_STACK_INST__[2 * MAX_THREAD_COUNT] = {};
jmp_buf __zero_jmp_buffer__;

static inline size_t __aux_mt_get_thread_idx__(pthread_t thread_id) {
  size_t seed = *(int*)&thread_id;
  size_t step = 0;
  size_t i = seed;
  pthread_t i_thread = *(pthread_t*)__aux_default_thread_0_init_ptr__;
  do {
    i = (i + step) % (2 * MAX_THREAD_COUNT);
    i_thread = ((pthread_t*)__aux_mt_thread_ids_ptr__)[i];
    step = step * 2 + 1;
  } while (!pthread_equal(i_thread, thread_id) && \
           !pthread_equal(i_thread, \
                          *(pthread_t*)__aux_default_thread_0_init_ptr__));
  if (pthread_equal(i_thread,
                    *(pthread_t*)__aux_default_thread_0_init_ptr__)) {
    ((pthread_t*)__aux_mt_thread_ids_ptr__)[i] = thread_id;
  }
  return i;
}

async_handler_t* __aux_mt_async_handler_location__() {
  pthread_t self = pthread_self();
  size_t i = __aux_mt_get_thread_idx__(self);
  return &(__AUX_MT_SCOPE_STACK_INST__[i]);
}

void* __aux_async_coroutine_init_calloc__(size_t size) {
  return calloc(size, 1);
}

void* __async_handler_reserve__(async_handler_t* self, size_t capacity) {
  async_coroutine_t* prev_data = self->cr_list_data;
  self->cr_list_data = (async_coroutine_t*)malloc(capacity * sizeof(async_coroutine_t));
  if (prev_data) {
    memcpy(self->cr_list_data, prev_data, self->cr_list_size * sizeof(async_coroutine_t));
    free(prev_data);
  }
  self->cr_list_capacity = capacity;
  return self;
}

void* __async_handler_init__(async_handler_t* self, size_t stack_size) {
  self->cr_list_size = 0;
  self->cr_list_data = NULL;
  self->stack_size = ((stack_size < 8) ? 8 : stack_size) * (stack_size != 0);
  __async_handler_reserve__(self, CR_LIST_INITIAL_CAPACITY);
  return self;
}

void* __async_handler_destroy__(async_handler_t* self) {
  if (!self->cr_list_data) {
    return NULL;
  }
  for (size_t i = 0; i < self->cr_list_size; ++i) {
    free(self->cr_list_data[i].static_state_data);
  }
  free(self->cr_list_data);
  sleep(10);
  self->cr_list_size = 0;
  return NULL;
}

int const static inline __async_handler_set_cr_mask_init__(async_coroutine_t* crt, BOOL init) {
  crt->__mask__ |= 1;
  crt->__mask__ ^= (!init) * 1;
  return crt->__mask__;
}

int const static inline __async_handler_get_cr_mask_init__(async_coroutine_t* crt) {
  return crt->__mask__ & 1;
}

void __async_handler_manager__(async_handler_t* self) {
  for (size_t i = 0; i < self->cr_list_size; ++i) {
    if (!setjmp(self->__jmp_buf__)) {
      __async_handler_set_cr_mask_init__(&self->cr_list_data[i], TRUE);
      self->cr_list_data[i].function(&self->cr_list_data[i], self->cr_list_data[i].arg);
    }
  }
  int manager_state = 1;
  int jump_result = 0;
  while (manager_state)
  {
    if (!self->cr_list_size) {
      manager_state = 0;
      break;
    }
    for (size_t i = 0; i < self->cr_list_size; ++i) {
      if (!__async_handler_get_cr_mask_init__(&self->cr_list_data[i])) {
        if (!setjmp(self->__jmp_buf__)) {
          __async_handler_set_cr_mask_init__(&self->cr_list_data[i], TRUE);
          self->cr_list_data[i].function(&self->cr_list_data[i], self->cr_list_data[i].arg);
        }
        continue;
      }
      if (jump_result = setjmp(self->__jmp_buf__)) {
        if (!self->cr_list_size) {
          return;
        }
        switch (jump_result)
        {
          case -1:
            if (self->signal_handler) {
              manager_state = self->signal_handler(&self->cr_list_data[i],
                                                   -1,
                                                   manager_state);
            } else {
              __async_handler_remove__(self, &self->cr_list_data[i]);
              manager_state = 0;
            }
            break;

          case 1:
            break;

          default:
            if (self->signal_handler) {
              self->cr_list_data[i].__state__ = self->signal_handler(&self->cr_list_data[i],
                                                                     jump_result,
                                                                     manager_state);
            }
            break;
        }
      } else {
        longjmp(self->cr_list_data[i].__jmp_buf__, 1 + i);
        break;
      }
    }
  }
  return;
}

void* __async_handler_call__(async_handler_t* self) {
  size_t stack_padding_size = self->stack_size;
  if (!self->stack_size) {
    size_t max_size = 0;
    for (size_t i = 0; i < self->cr_list_size; ++i) {
      size_t size_i = self->cr_list_data[i].stack_size_ubnd;
      max_size = (max_size < size_i) ? size_i : max_size;
    }
    stack_padding_size = max_size;
    self->stack_size = stack_padding_size;
  }
  // printf("StackSize: %d\n", stack_padding_size);
  char stack_padding[stack_padding_size];
  stack_padding[0] = 0;
  stack_padding[stack_padding_size - 1] = stack_padding_size & (char)(__SCHAR_MAX__ * 2 + 1);
  __async_handler_manager__(self);
  return NULL;
}

size_t __async_handler_find__(async_handler_t* self, async_coroutine_t* crt) {
  if (!crt) {
    return self->cr_list_size;
  }
  if (crt->index) {
    return crt->index - 1;
  }
  for (size_t i = 0; i < self->cr_list_size; ++i) {
    if (self->cr_list_data[i].function == crt->function && \
        self->cr_list_data[i].heap_state_data == self->cr_list_data[i].heap_state_data && \
        self->cr_list_data[i].static_state_data == self->cr_list_data[i].static_state_data) {
      return i;
    }
  }
  return self->cr_list_size;
}

void* __async_handler_remove__(async_handler_t* self, async_coroutine_t* crt) {
  size_t i = __async_handler_find__(self, crt);
  if (i >= self->cr_list_size || !self->cr_list_size) {
    return NULL;
  }
  free(crt->static_state_data);
  if (crt->dependency) {
    async_coroutine_t* tmp_crt = crt->dependency;
    free(crt->arg);
    memcpy(crt, tmp_crt, sizeof(async_coroutine_t));
    free(tmp_crt);
    return NULL;
  }
  self->cr_list_size--;
  free(self->cr_list_data[i].arg);
  self->cr_list_data[i] = self->cr_list_data[self->cr_list_size];
  self->cr_list_data[i].index = i + 1;
  if (self->cr_list_size == 0) {
    __async_handler_destroy__(self);
  }
  return NULL;
}

void* __async_handler_add__(async_handler_t* self, async_coroutine_t* crt) {
  if (!self->cr_list_data) {
    __async_handler_init__(self, 0);
  }
  if (self->cr_list_size + 1 == self->cr_list_capacity) {
    __async_handler_reserve__(self, self->cr_list_capacity * 2);
  }
  memcpy(&self->cr_list_data[self->cr_list_size], crt, sizeof(async_coroutine_t));
  self->cr_list_data[self->cr_list_size].handler = self;
  if (crt->arg_size > 4096) {
    printf("ARGSIZE: %d\n", crt->arg_size);
    crt->arg_size = 4096;
  }
  self->cr_list_data[self->cr_list_size].arg = crt->arg;
  self->cr_list_data[self->cr_list_size].index = 1 + self->cr_list_size;
  self->cr_list_size++;
  free(crt);
  return &self->cr_list_data[self->cr_list_size - 1];
}

static const inline size_t __aux_get_high_bit__(size_t x) {
  size_t pow_max = sizeof(size_t) * __CHAR_BIT__ - 1;
  size_t pow_min = 0;
  size_t x2 = 1;
  while (pow_max - pow_min <= 1) {
    x2 = 1llu << ((pow_min + pow_max) / 2);
    if (x > x2) {
      pow_min = (pow_min + pow_max) / 2;
    } else {
      pow_max = (pow_min + pow_max) / 2;
    }
  }

  if (x & (2 * x2)) {
    return 2 * x2;
  }

  if (x & x2) {
    return x2;
  }
  
  return x2 / 2;
}

void __async_handler_save__(async_handler_t* self, async_coroutine_t* crt, ... ) {
  va_list __ARGUMENT_POINTERS__;
  size_t idx = __async_handler_find__(self, crt);
  if (idx >= self->cr_list_size) {
    return;
  }
  static const size_t static_arg_list_size = CR_ARG_LIST_MAX_SIZE * sizeof(void*) * 2;
  char __args_stack__[static_arg_list_size] = {};
  char* args = __args_stack__;
  size_t args_size = 0;
  size_t args_capacity = static_arg_list_size;
  {
    void* arg_i = NULL;
    va_start(__ARGUMENT_POINTERS__, crt);
    for (size_t i = 0;
         (i < CR_ARG_LIST_MAX_SIZE) &&
         (arg_i = va_arg(__ARGUMENT_POINTERS__, void*));
         ++i) {
      size_t arg_size = *(size_t*)arg_i;
      if (args_size + arg_size >= args_capacity) {
        if (args_capacity == static_arg_list_size) {
          args = (char*)malloc(((args_capacity < (2 * args_size)) ? \
                                2 * __aux_get_high_bit__(args_size) : \
                                args_capacity) * 2);
          memcpy(args, __args_stack__, args_capacity);
        } else {
          char* tmp_args = args;
          args = (char*)malloc(((args_capacity < (2 * args_size)) ? \
                                2 * __aux_get_high_bit__(args_size) : \
                                args_capacity) * 2);
          memcpy(args, tmp_args, args_capacity);
          free(tmp_args);
        }
        args_capacity = ((args_capacity < (2 * args_size)) ? \
                        2 * __aux_get_high_bit__(args_size) : \
                        args_capacity) * 2;
      }
      memcpy(args + arg_size, arg_i, arg_size);
      args_size += arg_size;
    }
    va_end(__ARGUMENT_POINTERS__);
  }
  if (args_capacity == static_arg_list_size) {
    args = (char*)malloc(((args_capacity < (2 * args_size)) ? \
                          2 * __aux_get_high_bit__(args_size) : \
                          args_capacity) * 2);
    memcpy(args, __args_stack__, args_size);
  }
  self->cr_list_data[idx].heap_state_data = (generic_cr_state_t*)args;
}

void __async_handler_restore__(async_handler_t* self, async_coroutine_t* crt, ... ) {
  va_list __ARGUMENT_POINTERS__;
  size_t idx = __async_handler_find__(self, crt);
  if (idx >= self->cr_list_size) {
    return;
  }
  size_t arg_shift = 0;
  {
    void* arg_i = NULL;
    va_start(__ARGUMENT_POINTERS__, crt);
    for (size_t i = 0;
         (i < CR_ARG_LIST_MAX_SIZE) &&
         (arg_i = va_arg(__ARGUMENT_POINTERS__, void*));
         ++i) {
      size_t arg_size = *(size_t*)arg_i;
      memcpy(arg_i, self->cr_list_data[idx].heap_state_data + arg_shift, arg_size);
      arg_shift += arg_size;
    }
    va_end(__ARGUMENT_POINTERS__);
  }
  free(self->cr_list_data[idx].heap_state_data);
  return;
}

void __async_coroutine_sync_call__(async_coroutine_t* self,
                                   async_coroutine_t* target) {
  async_coroutine_t* src = malloc(sizeof(async_coroutine_t));
  memcpy(src, self, sizeof(async_coroutine_t));
  memcpy(self, target, sizeof(async_coroutine_t));
  self->handler = src->handler;
  self->arg = malloc(target->arg_size);
  memcpy(self->arg, target->arg, target->arg_size);
  self->dependency = src;
  self->function(self, self->arg);
}

void* __async_coroutine_async_call__(async_coroutine_t** self,
                                     async_coroutine_t* target) {
  size_t idx = (*self)->index - 1;
  async_coroutine_t* trg = __async_handler_add__(&__async_handler__, target);
  (*self) = &__async_handler__.cr_list_data[idx];
  return trg;
}
