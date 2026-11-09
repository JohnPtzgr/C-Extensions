#include "time.h"
#include "cstdlib"
#include "cstdio"
#include <unordered_map>
#include <string>
// typedef std::size_t size_t;


static inline size_t defaultVTableHasher(const char* key, char id) {

  size_t lookup_primes[16] = {
    428565993458070227,
    254122516461927209,
    532695996088977289,
    313290182662825307,
    860946449948972521,
    319264523107532111,
    202986391655519623,
    275182499288387473,
    962987202532100107,
    733765330246036859,
    147307587625942813,
    613405566694294111,
    769693398094706011,
    398091924081499261,
    727872227099913139,
    400052032524586027
  };
  size_t hash = (size_t)(defaultVTableHasher);

  while (*key)
  {
    hash += lookup_primes[(*(key) + id) & 15] ^ *((unsigned char*)key);
    hash ^= lookup_primes[(*(key) + id) & 15];
    key++;
  }

  return hash;
}

class hasher {
 public:
  inline size_t operator()(const char* key) const {
    return defaultVTableHasher(key, 0);
  }
};


int main() {
  char* str = (char*)malloc(2000000000);
  size_t rnd = 1;
  for (size_t i = 0; i < 200000000; ++i) {
    rnd <<= 2;
    rnd = (rnd * 147307587625942813) & 428565993458070227;
    str[i] = 32 + ((rnd + i) & 63);
  }
  std::unordered_map<char*, void*, hasher> m;
  printf("init\n");
  clock_t time_s = clock();
  rnd = 1;
  for (size_t i = 0; i < 120000; ++i) {
    rnd = (rnd * 428565993458070227 * (str[i * 16] + 1)) % 147307587625942813;
    str[i * 16 + 15] = '\0';
    str[i * 16 + (rnd & 7)] = 'a';
    // printf("%d = \"%s\" = %d(X) = %d(Y)\n", i, str + 16 * i, defaultVTableHasher(str + 16 * i, 0), defaultVTableHasher(str + 16 * i, 1));
    m.insert({str + 16 * i, (void*)(i + 1)});    // __vTable_add__(&t, str + 16 * i, (void*)(i + 1));
    // if (!__vTable_check__(&t, str + 16 * i)) {
    //   printf("%d - Critical Error!\n", i);
    //   free(str);
    //   __vTable_destroy__(&t);
    //   exit(0);
    // }
  }
  clock_t time_f = clock();
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  time_s = clock();
  rnd = 1;
  for (size_t i = 0; i < 120000; ++i) {
    if (!m.count(str + 16 * i)) {
      printf("%d - Critical Error!\n", i);
      free(str);
      // __vTable_destroy__(&t);
      m;
      return 0;
    }
  }
  time_f = clock();
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  // for (size_t i = 0; i < t.size; ++i) {
  //   printf("%d - %d - %d - %d\n", t.data[i].data, t.data[i].mask, t.data[i].hash.hashX, t.data[i].hash.hashY);
  // }
  free(str);
  printf("destroy\n");
  // __vTable_destroy__(&t);
  int z = 90;
  printf("%u\n", z & (char)(-(char)z));
  return 0;
} 