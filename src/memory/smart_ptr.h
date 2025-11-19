#include "allocator.h"

typedef struct smartptr_t_S smartptr_t;
typedef struct uniqueptr_t_S uniqueptr_t;
typedef struct sharedptr_t_S sharedptr_t;
typedef struct weakptr_t_S weakptr_t;

typedef struct anyptr_t {
  void* data;
  union anyptr_container_t {
    size_t counter;
    sharedptr_t* owner;
  } container;
} anyptr_t;

Class(
  DefaultBase,
  smartptr_t,
  void* data,
  allocator_t allocator;
  void* (*alloc)(smartptr_t_S* self);
  void (*free)(smartptr_t_S* self);
  anyptr_t (*make_unique)(smartptr_t_S* self);
  anyptr_t (*make_shared)(smartptr_t_S* self);
)

#define Smart_ptr()

Class(
  DefaultBase,
  uniqueptr_t,
  void* data,
  allocator_t allocator;
  void* (*alloc)(uniqueptr_t_S* self);
  void (*free)(uniqueptr_t_S* self);
  anyptr_t (*make_shared)(uniqueptr_t_S* self);
)

Class(
  DefaultBase,
  sharedptr_t,
  void* data;
  size_t counter,
  allocator_t allocator;
  void* (*alloc)(sharedptr_t_S* self);
  void (*free)(sharedptr_t_S* self);
  BOOL(*unique)(sharedptr_t_S* self);
  void (*reset)(sharedptr_t_S* self);
  size_t (*use_count)(sharedptr_t_S* self);
  void* (*get)(sharedptr_t_S* self);
  anyptr_t (*make_unique)(sharedptr_t_S* self);
)


Class(
  DefaultBase,
  weakptr_t,
  void* data;
  sharedptr_t* owner,
  void (*update)(weakptr_t_S* self);
  BOOL (*expired)(weakptr_t_S* self);
  BOOL (*unique)(weakptr_t_S* self);
  void (*reset)(weakptr_t_S* self);
  size_t (*use_count)(weakptr_t_S* self);
  void* (*get)(weakptr_t_S* self);
)