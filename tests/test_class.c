#include "../src/oop/class.c"

int main() {
  __vTable__ t;
  __vTable_init__(&t, 0, 0);
  printf("init\n");
  int x = 90;
  int y = 100;
  __vTable_add__(&t, "a", (void*)x);
  __vTable_add__(&t, "b", (void*)x);
  __vTable_add__(&t, "c", (void*)x);
  __vTable_add__(&t, "d", (void*)x);
  for (size_t i = 0; i < t.size; ++i) {
    printf("%d, %d, %d, %d\n", t.data[i].data, t.data[i].hash.hashX, t.data[i].hash.hashY, t.data[i].mask);
  }
  __vTable_add__(&t, "e", (void*)x);
  __vTable_add__(&t, "f", (void*)x);
  __vTable_add__(&t, "g", (void*)x);
  __vTable_add__(&t, "h", (void*)x);
  for (size_t i = 0; i < t.size; ++i) {
    printf("%d, %d, %d, %d\n", t.data[i].data, t.data[i].hash.hashX, t.data[i].hash.hashY, t.data[i].mask);
  }
  __vTable_add__(&t, "i", (void*)x);
  __vTable_add__(&t, "j", (void*)x);
  __vTable_add__(&t, "k", (void*)x);
  __vTable_add__(&t, "l", (void*)x);
  for (size_t i = 0; i < t.size; ++i) {
    printf("%d, %d, %d, %d\n", t.data[i].data, t.data[i].hash.hashX, t.data[i].hash.hashY, t.data[i].mask);
  }
  __vTable_add__(&t, "m", (void*)x);
  __vTable_add__(&t, "n", (void*)x);
  __vTable_add__(&t, "o", (void*)x);
  __vTable_add__(&t, "p", (void*)x);
  for (size_t i = 0; i < t.size; ++i) {
    printf("%d, %d, %d, %d\n", t.data[i].data, t.data[i].hash.hashX, t.data[i].hash.hashY, t.data[i].mask);
  }
  printf("\n%d\n", __vTable_check__(&t, "w"));
  __vTable_destroy__(&t);
  printf("destroy\n");
  int z = 90;
  printf("%u\n", z & (char)(-(char)z));
  return 0;
} 