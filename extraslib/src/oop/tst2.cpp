#include "lambda.h"
//#include "../algorithm/vector.h"

STATIC_CLASS(a, int x, 0)
CLASS_END(a) {
  printf("%d\n", self->x);
  return 0;
}

int main() {
  //INIT(vector_t, a);
  //a.__base.data = 0;
  //darray_t b;
  //array_init_from(&b, 1, a.__base.data, 1);
  BEGIN
  INIT(a, b);
  b.x = 90;
  //SCOPE_END
  PURGE_HEAP;
  return 0;
}

//lambda_t s;