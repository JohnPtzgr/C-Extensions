#include "class.h"

#pragma once

DEF_CLASS(iterator_t,
  ,
  size_t step;
  void* cur_ptr;
  void* max_ptr;
)

#define Iter(DATA_PTR...) iterator_t_init(alloca(sizeof(iterator_t)), \
                                          ARG1_VA_ARGS(DATA_PTR), \
                                          sizeof(*ARG1_VA_ARGS(DATA_PTR)), \
                                          ARG1_VA_ARGS_VA(DATA_PTR, 0))

#define IterNext(iterator) __iterator_t_Default_vClassObject__.__inc__(iterator, 0)
#define IterPrev(iterator) __iterator_t_Default_vClassObject__.__dec__(iterator, 0)

