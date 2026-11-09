#include "allocator.h"


#define UNIQUEPTR_MAX_TIMEOUT_CYCLES 1024


typedef struct smartptr_t_S smartptr_t;
typedef struct uniqueptr_t_S uniqueptr_t;
typedef struct sharedptr_t_S sharedptr_t;
typedef struct weakptr_t_S weakptr_t;

typedef struct sharedptr_manager_t_S sharedptr_manager_t_S;

typedef union anyptr_t {
  struct {
    __vClassObject__* __meta__;
    DefaultBase_S __base__;
    void* data;
  } smart;
  struct {
    __vClassObject__* __meta__;
    DefaultBase_S __base__;
    void* data;
  } unique;
  struct {
    __vClassObject__* __meta__;
    DefaultBase_S __base__;
    void* data;
    sharedptr_manager_t_S* manager;
  } shared;
  struct {
    __vClassObject__ __meta__[0];
    DefaultBase_S __base__;
    void* data;
    union {
      sharedptr_t* shared;
      smartptr_t* smart;
      uniqueptr_t* unique;
    } owner;
  } weak;
} anyptr_t;


Class(
  DefaultBase,
  smartptr_t,
  void* data,
  allocator_t* allocator;
  void* (*alloc)(smartptr_t_S* self, size_t size);
  void (*free)(smartptr_t_S* self);
  void* (*reset)(smartptr_t_S* self);
  anyptr_t (*make_unique)(smartptr_t_S* self);
  anyptr_t (*make_shared)(smartptr_t_S* self);
  anyptr_t (*link_weak)(smartptr_t_S* self);
)


Class(
  DefaultBase,
  uniqueptr_t,
  void* data,
  allocator_t* allocator;
  void* (*alloc)(uniqueptr_t_S* self, size_t size);
  void (*free)(uniqueptr_t_S* self);
  void* (*reset)(uniqueptr_t_S* self);
  anyptr_t (*make_shared)(uniqueptr_t_S* self);
  anyptr_t (*make_smart)(uniqueptr_t_S* self);
  anyptr_t (*link_weak)(uniqueptr_t_S* self);
)


Class(
  DefaultBase,
  sharedptr_t,
  void* data;
  sharedptr_manager_t_S* manager,
  allocator_t* allocator;
  void* (*alloc)(sharedptr_t_S* self, size_t size);
  void (*free)(sharedptr_t_S* self);
  BOOL(*unique)(sharedptr_t_S* self);
  void* (*reset)(sharedptr_t_S* self);
  size_t (*ref_count)(sharedptr_t_S* self);
  size_t (*weak_ref_count)(sharedptr_t_S* self);
  void* (*get)(sharedptr_t_S* self);
  anyptr_t (*make_unique)(sharedptr_t_S* self);
  anyptr_t (*make_smart)(sharedptr_t_S* self);
  anyptr_t (*link_weak)(sharedptr_t_S* self);
)


BareClass(
  DefaultBase,
  weakptr_t,
  void* data;
  union {
    sharedptr_t* shared;
    smartptr_t* smart;
    uniqueptr_t* unique;
  } owner,
  void (*update)(weakptr_t_S* self);
  BOOL (*expired)(weakptr_t_S* self);
  BOOL (*unique)(weakptr_t_S* self);
  void* (*reset)(weakptr_t_S* self);
  void (*lock)(weakptr_t_S* self);
  void (*unlock)(weakptr_t_S* self);
  void* (*get)(weakptr_t_S* self);
)