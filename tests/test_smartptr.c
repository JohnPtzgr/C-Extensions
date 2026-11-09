#include "../src/memory/smart_ptr.h"

int main() {
  SCOPE_BEGIN
  int sf[] = {1, 2, 3, 4};
  smartptr_t* ptr = CLS(smartptr_t, sf);
  printf("A: %d: {%d, %d, %d, %d}\n",
          ptr->data,
          ((int*)ptr->data)[0],
          ((int*)ptr->data)[1],
          ((int*)ptr->data)[2],
          ((int*)ptr->data)[3]
        );
  ptr->__meta__->reset(ptr);
  printf("B: %d, %d, %d\n", ptr->__meta__, ptr->__meta__->alloc, ptr->data);
  ptr->__meta__->alloc(ptr, 8);
  printf("C: %d\n", ptr->data);
  SCOPE_END
  return 0;
}