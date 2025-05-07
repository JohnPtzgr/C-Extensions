#ifndef CONTAINER_H
#define CONTAINER_H
#include "../oop/classes.h"

#ifndef UCHAR_MAX
#define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
#endif // !UCHAR_MAX

STATIC_CLASS(smartptr_t,
  void* data,
  0)

STATIC_CLASS(generic_container_t,
  void* data;
  size_t type_size;
  size_t size,
  2)

void* gen_cont_free(generic_container_t*);
void* gen_cont_alloc(generic_container_t*, size_t, size_t);

#endif
