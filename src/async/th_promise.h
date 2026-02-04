#include "promise.h"

typedef struct thread_t {
  promise_target_t target;
  void* args;
  void* state;
  void* result;
  promise_predicate_t predicate;
  promise_callback_t callback;
  struct promise_handler_t** dependencies;
  size_t ref_count;
  promise_handler_mask_t mask;
  promise_handler_status_t status;
  promise_handler_signal_t signal;
  pthread_t thread;
} thread_t;
