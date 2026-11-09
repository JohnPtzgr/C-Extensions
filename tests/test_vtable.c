#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "../src/oop/exception.h"

#define __DEFAULT_VTABLE_SIZE__ 8
#define __DEFAULT_VTABLE_MLT_OFFSET__ 8
#define __VTABLE_SIZE_IS_POWER_OF_2__ TRUE

typedef struct __vTableHash__
{
  size_t hashX;
  size_t hashY;
} __vTableHash__;

typedef struct __vTableProbeId__
{
  size_t id;
  size_t pow;
} __vTableProbeId__;


typedef struct __vTableNode__
{
  void* data;
  size_t mask;
  __vTableHash__ hash;
} __vTableNode__;

typedef __vTableHash__(*vTableHasher)(const char* key);

typedef struct __vTable__
{
  vTableHasher hasher;
  __vTableNode__* data;
  size_t size;
  size_t inserts_num;
} __vTable__;

static inline uint32_t xxh32(const char* key, size_t len, uint32_t seed) {
  const uint32_t prime1 = 0x9E3779B1U;
  const uint32_t prime2 = 0x85EBCA6BU;
  const uint32_t prime3 = 0xC2B2AE35U;
  const uint32_t prime4 = 0x27D4EB2FU;
  
  uint32_t h32 = seed + prime1 + prime2;
  const uint8_t* p = (const uint8_t*)key;
  const uint8_t* end = p + len;
  
  // Process 4 bytes at a time
  for (; p <= end - 4; p += 4) {
    uint32_t lane = *(uint32_t*)p;
    lane *= prime2;
    lane = (lane << 31) | (lane >> 1);
    lane *= prime1;
    h32 ^= lane;
    h32 = (h32 << 27) | (h32 >> 5);
    h32 = h32 * prime1 + prime4;
  }
  
  // Remainder
  for (; p < end; p++) {
    h32 ^= *p * prime1;
    h32 = (h32 << 23) | (h32 >> 9);
    h32 *= prime2;
  }
  
  // Final avalanche
  h32 ^= h32 >> 15;
  h32 *= prime2;
  h32 ^= h32 >> 13;
  h32 *= prime3;
  h32 ^= h32 >> 16;
  
  return h32;
}

// Your interface
static inline size_t xxh_hasher(const char* key, char id) {
  return xxh32(key, 16, id * 0x9E3779B1U);
}

static inline __vTableHash__ fast_hash(const char* key) {
    // if (strlen(key) != 15) {
    //   return xxh32(key, strlen(key), id * 0x9E3779B1U);
    // }
  uint64_t low = *(uint64_t*)key;
    uint64_t high = *(uint64_t*)(key + 8);
    
  // SplitMix64 mixing function
  uint64_t z1 = low + high ^ 0xC4CEB9FE1A85EC53ULL;
  uint64_t z2 = low ^ high + 0x9E3779B97F4A7C15ULL;
  // uint64_t z1 = low + high;
  // uint64_t z2 = low ^ high;
  
  // z1 = (z1 ^ (z1 >> 30)) * 0xBF58476D1CE4E5B9ULL;
  // z2 = (z2 ^ (z2 >> 30)) * 0xBF58476D1CE4E5B9ULL;
  
  // z1 = (z1 ^ (z1 >> 27)) * 0x94D049BB133111EBULL;
  // z2 = (z2 ^ (z2 >> 27)) * 0x94D049BB133111EBULL;
  
  z1 ^= z1 >> 33;
  z2 ^= z2 >> 33;
  
  return (__vTableHash__){.hashX = z1, .hashY = z2};
  // uint64_t low = *(uint64_t*)key;
  // uint64_t high = *(uint64_t*)(key + 8);
  
  // // Two independent mixing chains
  // uint64_t h1 = low ^ high ^ 0x9E3779B97F4A7C15ULL;
  // uint64_t h2 = low + high ^ 0xC4CEB9FE1A85EC53ULL;
  
  // h1 ^= h1 >> 33;
  // h1 *= 0xFF51AFD7ED558CCDULL;
  // h1 ^= h1 >> 33;
  
  // h2 ^= h2 >> 33;
  // h2 *= 0xFF51AFD7ED558CCDULL;
  // h2 ^= h2 >> 33;
      
  // return (__vTableHash__){.hashX = h1, .hashY = h2};
    // uint64_t low = *(uint64_t*)key;
    // uint64_t high = *(uint64_t*)(key + 8);
    // uint64_t mix = low ^ high ^ (id * 0x9E3779B97F4A7C15ULL);
    
    // // Just two rounds of mixing
    // mix ^= mix >> 33;
    // mix *= 0xFF51AFD7ED558CCDULL;
    // mix ^= mix >> 33;
    
    // return mix;
}

static inline __vTableHash__ defaultVTableHasher(const char* key) {
  return fast_hash(key);
  // return xxh_hasher(key, id);
  // return ((size_t)key) ^ (id * 428565993458070227l) + (*key * 254122516461927209l);
  size_t lookup_primes[16] = {
    428565993458070227l,
    254122516461927209l,
    532695996088977289l,
    313290182662825307l,
    860946449948972521l,
    319264523107532111l,
    202986391655519623l,
    275182499288387473l,
    962987202532100107l,
    733765330246036859l,
    147307587625942813l,
    613405566694294111l,
    769693398094706011l,
    398091924081499261l,
    727872227099913139l,
    400052032524586027l
  };
  volatile size_t hash = (size_t)(defaultVTableHasher);

  while (*key && (*key & 0b111111))
  {
    hash += lookup_primes[(*(key) + 0) & 15] ^ *((unsigned char*)key);
    hash ^= lookup_primes[(*(key) + 1) & 15];
    key++;
  }

  return (__vTableHash__){};
}

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

static inline __vTableProbeId__ __vTable_probe__(__vTable__* table, __vTableHash__ hash) {
  size_t id0 = (hash.hashX) & (table->size - 1);
  // size_t id0 = (hash.hashX^(-hash.hashY)) & (table->size - 1);
  size_t idx = id0;
  size_t cnt = 1;
  size_t pow = 0;
  // while (cnt < 30 &&
  while (cnt < table->size &&
         (table->data[idx].data &&
          (hash.hashX != table->data[idx].hash.hashX ||
           hash.hashY != table->data[idx].hash.hashY))) {
    idx = (id0 + cnt) & (table->size - 1);
    // cnt += 1;
    cnt *= 2;
    pow++;
  }
  // if (cnt >= table->size) {
  if (cnt >= table->size) {
    return (__vTableProbeId__){};
  }
  return (__vTableProbeId__){.id=idx + 1, .pow=pow};
}

#else

static inline size_t __vTable_probe__(__vTable__* table, __vTableHash__ hash) {
  size_t id0 = (hash.hashX^(-hash.hashY)) % table->size;
  size_t idx = id0;
  size_t cnt = 1;
  size_t pow = 0;
  while (cnt < table->size &&
         (table->data[idx].data &&
          (hash.hashX != table->data[idx].hash.hashX ||
           hash.hashY != table->data[idx].hash.hashY))) {
    idx = (id0 + cnt) % table->size;
    cnt *= 2;
  }
  return (__vTableProbeId__){.id=idx + 1, .pow=pow};
}

#endif

static inline void __vTableNode_set_mask_bit_t__(__vTableNode__* node, size_t cnt) {
  node->mask |= (1 << cnt);
}

static inline void __vTableNode_set_mask_bit_f__(__vTableNode__* node, size_t cnt) {
  size_t tmp_val = (1 << cnt);
  node->mask = (node->mask |= tmp_val) ^ tmp_val;
}

size_t __vTable_reserve__(__vTable__* table, size_t new_size) {
  __vTableNode__* tmp_data = table->data;
  table->data = (__vTableNode__*)calloc(new_size, sizeof(__vTableNode__));
  size_t tmp_size = table->size;
  table->size = new_size;
  if (tmp_data == NULL) {
    return table->size;
  }
  __vTableProbeId__ idx = (__vTableProbeId__){};
  for (size_t i = 0; i < tmp_size; ++i) {
    idx = __vTable_probe__(table, tmp_data[i].hash);
    if (!idx.id) {
      __vTable_reserve__(table, table->size * 2);
      idx = __vTable_probe__(table, tmp_data[i].hash);
    }
    table->data[idx.id - 1].data = tmp_data[i].data;
    table->data[idx.id - 1].hash = tmp_data[i].hash;

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

    size_t tmp_index = (tmp_data[i].hash.hashX) & (table->size - 1);
    // size_t tmp_index = (tmp_data[i].hash.hashX^(-tmp_data[i].hash.hashY)) & (table->size - 1);
    __vTableNode_set_mask_bit_t__(&(table->data[tmp_index]), idx.pow);

#else

    size_t tmp_index = (tmp_data[i].hash.hashX^(-tmp_data[i].hash.hashY)) % table->size;
    __vTableNode_set_mask_bit_t__(&(table->data[tmp_index]), idx.pow);

#endif

  }
  free(tmp_data);
  return table->size;
}

void* __vTable_init__(__vTable__* table, size_t default_size, vTableHasher hasher) {
  *table = (__vTable__){.hasher = (vTableHasher)defaultVTableHasher};
  if (hasher) {
    table->hasher = hasher;
  }
  __vTable_reserve__(table, default_size ? default_size : __DEFAULT_VTABLE_SIZE__);
  return table;
}

void* __vTable_destroy__(__vTable__* table) {
  if (table->data) {
    free(table->data);
  }
  return NULL;
}

void* __vTable_add__(__vTable__* table, const char* key, void* value) {
  __vTableHash__ hash = table->hasher(key);
  __vTableProbeId__ idx = __vTable_probe__(table, hash);
  if (!idx.id) {
    __vTable_reserve__(table, table->size * 2);
    idx = __vTable_probe__(table, hash);
  }
  table->inserts_num++;
  table->data[idx.id - 1].data = value;
  table->data[idx.id - 1].hash = hash;

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

  __vTableNode_set_mask_bit_t__(&(table->data[(hash.hashX) & (table->size - 1)]), idx.pow);
  // __vTableNode_set_mask_bit_t__(&(table->data[(hash.hashX^(-hash.hashY)) & (table->size - 1)]), idx.pow);

#else

  __vTableNode_set_mask_bit_t__(&(table->data[(hash.hashX^(-hash.hashY)) % table->size]), idx.pow);

#endif
  return table;
}

void* __vTable_remove__(__vTable__* table, const char* key) {
  __vTableHash__ hash = table->hasher(key);
  __vTableProbeId__ idx;
  do {
    idx = __vTable_probe__(table, hash);
    if (!idx.id) {
      return table;
    }
  } while (!idx.id);
  if (!(table->data[idx.id - 1].hash.hashX | table->data[idx.id - 1].hash.hashY)) {
    return table;
  }
  table->data[idx.id - 1].data = 0;
  table->data[idx.id - 1].hash = (__vTableHash__){};
  table->inserts_num--;

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

  __vTableNode_set_mask_bit_f__(&(table->data[(hash.hashX^(-hash.hashY)) & (table->size - 1)]), idx.pow);

#else

  __vTableNode_set_mask_bit_f__(&(table->data[(hash.hashX^(-hash.hashY)) % table->size]), idx.pow);

#endif
  return table;
}

static inline void** __vTable_get__(__vTable__* table, const char* key) {
  __vTableHash__ hash = table->hasher(key);
  size_t og_offset = (hash.hashX^(-hash.hashY));

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE
  
  size_t mask = table->data[og_offset & (table->size - 1)].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    // const size_t offset = __builtin_ctzll(primary_bit);
    const size_t offset = primary_bit / 2;
    if (table->data[(og_offset + offset) & (table->size - 1)].hash.hashX == hash.hashX &&
        table->data[(og_offset + offset) & (table->size - 1)].hash.hashY == hash.hashY) {
      // printf("True\n");
      return &table->data[(og_offset + offset) & (table->size - 1)].data;
    }
  }

#else
  
  size_t mask = table->data[og_offset % table->size].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(og_offset + primary_bit / 2) % table->size].hash.hashX == hash.hashX &&
        table->data[(og_offset + primary_bit / 2) % table->size].hash.hashY == hash.hashY) {
      return table->data[(og_offset + primary_bit / 2) % table->size].data;
    }
  }

#endif

  return NULL;
}

static inline BOOL __vTable_count__(__vTable__* table) {
  return table->inserts_num;
}

static inline BOOL __vTable_check__(__vTable__* table, const char* key) {
  const vTableHasher t_hasher = table->hasher;
  const __vTableNode__* t_data = table->data;
  const size_t t_size = table->size;
  __vTableHash__ hash = t_hasher(key);
  const size_t og_offset = hash.hashX;
  // const size_t og_offset = (hash.hashX^(-hash.hashY));

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE
  
  size_t mask = t_data[og_offset & (t_size - 1)].mask / 2;
  size_t primary_bit = 0;
  do {
    // const size_t offset = __builtin_ctzll(primary_bit)
    if (t_data[(og_offset + primary_bit) & (t_size - 1)].hash.hashX == hash.hashX &&
        t_data[(og_offset + primary_bit) & (t_size - 1)].hash.hashY == hash.hashY) {
      // printf("True\n");
      return TRUE;
    }
    primary_bit = mask & (-mask);
    mask ^= primary_bit;
  } while (primary_bit);

#else
  
  size_t mask = table->data[og_offset % table->size].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(og_offset + primary_bit / 2) % table->size].hash.hashX == hash.hashX &&
        table->data[(og_offset + primary_bit / 2) % table->size].hash.hashY == hash.hashY) {
      return TRUE;
    }
  }

#endif

  return FALSE;
}

#define ScalarFX 50


int main() {
  const size_t sc = 2400;
  const size_t default_size = (1llu << 18);

  __vTable__ t;
  clock_t time_s;
  clock_t time_f;
  size_t count_overwrites = 0;
  const size_t ops = sc * ScalarFX;
  char* str = (char*)malloc(32 * sc * ScalarFX);
  size_t rnd = 1;
  for (size_t i = 0; i < 32 * sc * ScalarFX; ++i) {
    rnd <<= 2;
    rnd ^= (rnd >> 33);
    rnd = (rnd * 147307587625942813) ^ 428565993458070227;
    rnd ^= (rnd >> 33);
    str[i] = 1 + (rnd & 254);
  }
  rnd = 1;
  for (size_t i = 0; i < ops; ++i) {
    // rnd = (rnd * 428565993458070227 * (str[i * 16] + 1)) % 147307587625942813;
    // str[i * 16 + (rnd & 15)] = 1 + (rnd & 127);
    str[i * 16 + 15] = '\0';
  }
  __vTable_init__(&t, default_size, 0);
  printf("init\n");
  time_s = clock();
  rnd = 1;
  for (size_t i = 0; i < ops; ++i) {
    // printf("%d = \"%s\" = %d(X) = %d(Y)\n", i, str + 16 * i, defaultVTableHasher(str + 16 * i, 0), defaultVTableHasher(str + 16 * i, 1));
    __vTable_add__(&t, str + 16 * i, (void*)(i + 1));
    // if (!__vTable_check__(&t, str + 16 * i)) {
    //   printf("%d - Critical Error!\n", i);
    //   free(str);
    //   __vTable_destroy__(&t);
    //   exit(0);
    // }
  }
  time_f = clock();
  printf("Alpha: %f\n", ((double)ops)/((double)t.size));
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  volatile char *ptr = (char*)t.data;
  time_s = clock();
  for (int i = 0; i < (ops / 4096); i++) {
      (void)*ptr;  // Just touch memory
      ptr += 4096; // Skip to next page
  }
  time_f = clock();
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  // Stay within the same page (no TLB misses)
  volatile __vTableNode__ *ptr3 = (__vTableNode__*)t.data;
  char sum3 = 0;
  time_s = clock();
  for (int i = 0; i < ops; i++) {
    sum3 += ptr3[i & 0xFFF].hash.hashX;  // Within same 4KB page
  }
  time_f = clock();
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  printf("Sum: %d (prevent optimization)\n", sum3);
  time_s = clock();
  rnd = 1;
  volatile int a = 0;
  volatile int b = 1;
  for (size_t i = 0; i < ops; ++i) {
    for (size_t j = 0; j < 1; j++) {
      if (!__vTable_check__(&t, str + 16 * i)) {
        printf("%d - Critical Error!\n", i);
        free(str);
        __vTable_destroy__(&t);
        exit(0);
      } else {
        a += i;
      }
      if (b) {
        b += a + 1;
      }
    }
  }
  time_f = clock();
  printf("Alpha: %f\n", ((double)ops)/((double)t.size));
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  time_s = clock();
  rnd = 1;
  a = 0;
  b = 1;
  for (size_t i = 0; i < ops; ++i) {
    for (size_t j = 0; j < 10; j++) {
      if (!__vTable_check__(&t, str + 16 * i)) {
        printf("%d - Critical Error!\n", i);
        free(str);
        __vTable_destroy__(&t);
        exit(0);
      } else {
        a += i;
      }
      if (b) {
        b += a + 1;
      }
    }
  }
  time_f = clock();
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  time_s = clock();
  rnd = 1;
  a = 0;
  b = 1;
  for (size_t i = 0; i < ops; ++i) {
    for (size_t j = 0; j < 100; j++) {
      if (!__vTable_check__(&t, str + 16 * i)) {
        printf("%d - Critical Error!\n", i);
        free(str);
        __vTable_destroy__(&t);
        exit(0);
      } else {
        a += i;
      }
      if (b) {
        b += a + 1;
      }
    }
  }
  time_f = clock();
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  time_s = clock();
  rnd = 1;
  a = 0;
  b = 1;
  for (size_t i = 0; i < ops; ++i) {
    for (size_t j = 0; j < 10000; j++) {
      if (!__vTable_check__(&t, str + 16 * i)) {
        printf("%d - Critical Error!\n", i);
        free(str);
        __vTable_destroy__(&t);
        exit(0);
      }
      // else {
      //   a += i;
      // }
      // if (b) {
      //   b += a + 1;
      // }
    }
  }
  time_f = clock();
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  // for (size_t i = 0; i < t.size; ++i) {
  //   printf("%d - %d - %d - %d\n", t.data[i].data, t.data[i].mask, t.data[i].hash.hashX, t.data[i].hash.hashY);
  // }
  time_s = clock();
  rnd = 1;
  a = 0;
  b = 1;
  for (size_t i = 0; i < ops; ++i) {
    for (size_t j = 0; j < 1; j++) {
      if (__vTable_check__(&t, str + 16 * i + 1)) {
        a += i;
      }
    }
  }
  time_f = clock();
  printf("Time diff - %d ms with %d False+\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC, a);
  free(str);
  printf("destroy\n");
  __vTable_destroy__(&t);
  int z = 90;
  printf("%u\n", z & (char)(-(char)z));
  return 0;
} 




#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <ctype.h>
#include "unistd.h"
#include "sys/select.h"

// Include your hash table code here (or #include the header)

#define BUFFER_SIZE 65536  // 64KB read buffer
#define MAX_WORD_LEN 1024

// Simple word normalization (lowercase, remove punctuation)
static void normalize_word(char *dest, const char *src) {
    int j = 0;
    for (int i = 0; src[i] && i < MAX_WORD_LEN-1; i++) {
        char c = src[i];
        if (isalnum(c) || c == '\'' || c == '-') {
            dest[j++] = tolower(c);
        } else if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
            break;  // Stop at word boundary
        }
        // Skip other punctuation
    }
    dest[j] = '\0';
}

// Version 1: Basic scan (no hash table, for verification)
long count_word_basic(const char *filename, const char *target) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    
    char buffer[BUFFER_SIZE];
    char word[MAX_WORD_LEN];
    char normalized_target[MAX_WORD_LEN];
    char normalized_word[MAX_WORD_LEN];
    long count = 0;
    int in_word = 0;
    int word_pos = 0;
    
    // Normalize target once
    normalize_word(normalized_target, target);
    
    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (char *c = buffer; *c; c++) {
            if (isalnum(*c) || *c == '\'' || *c == '-') {
                if (!in_word) {
                    in_word = 1;
                    word_pos = 0;
                }
                if (word_pos < MAX_WORD_LEN - 1) {
                    word[word_pos++] = tolower(*c);
                }
            } else {
                if (in_word) {
                    word[word_pos] = '\0';
                    normalize_word(normalized_word, word);
                    if (strcmp(normalized_word, normalized_target) == 0) {
                        count++;
                    }
                    in_word = 0;
                }
            }
        }
    }
    
    // Handle last word if file doesn't end with newline
    if (in_word) {
        word[word_pos] = '\0';
        normalize_word(normalized_word, word);
        if (strcmp(normalized_word, normalized_target) == 0) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

// Version 2: Build hash table of ALL words, then lookup target
// This shows your table's strength - build once, query many times
typedef struct {
    char *word;
    long count;
} WordCount;

long count_word_with_hashtable(const char *filename, const char *target, int warmup) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    
    __vTable__ table;
    char normalized_target[MAX_WORD_LEN];

    normalize_word(normalized_target, target);
    printf("Norm target: \"%s\"\n", normalized_target);
    
    // Initialize hash table (size will grow automatically)
    __vTable_init__(&table, 1 << 19, 0);  // Start with 1M slots
    __vTable_add__(&table, normalized_target, (void*)0);
    printf("Is added - %d\n", __vTable_check__(&table, normalized_target));
    printf("Hash table initialized with %zu slots\n", table.size);
    
    char buffer[BUFFER_SIZE];
    char word[MAX_WORD_LEN];
    char normalized[MAX_WORD_LEN];
    long total_words = 0;
    long unique_words = 0;
    int in_word = 0;
    int word_pos = 0;
    
    clock_t build_start = clock();
    
    // First pass: build frequency table
    printf("Building hash table from %s...\n", filename);
    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (char *c = buffer; *c; c++) {
            if (isalnum(*c) || *c == '\'' || *c == '-') {
                if (!in_word) {
                    in_word = 1;
                    word_pos = 0;
                }
                if (word_pos < MAX_WORD_LEN - 1) {
                    word[word_pos++] = tolower(*c);
                }
            } else {
                if (in_word) {
                    word[word_pos] = '\0';
                    total_words++;
                    
                    // Normalize for hashing
                    normalize_word(normalized, word);
                    
                    // Look up word in hash table
                    size_t* cnt = (size_t*)__vTable_get__(&table, normalized);
                    
                    
                    if (cnt) {
                        // Word exists - increment count
                        (*cnt)++;
                    
                        // printf("Norm target word(\"%s\") %d-%d(cnt)-%d\n", normalized, total_words, cnt, *cnt);
                    } else {
                        __vTable_add__(&table, normalized, (void*)1);
                        unique_words++;
                        // printf("Norm word(\"%s\") %d-%d(cnt)\n", normalized, total_words, cnt);
                        // // New word - create entry
                        // wc = (WordCount*)malloc(sizeof(WordCount));
                        // wc->word = strdup(normalized);
                        // wc->count = 1;
                    }
                    // select(0, NULL, NULL, NULL, &(struct timeval){.tv_usec=250000});
                    in_word = 0;
                }
            }
        }
    }
    size_t *count;
    // count = (size_t*)__vTable_get__(&table, normalized_target);
    // printf("Count: %ld\n", *count);
    
    // Handle last word
    if (in_word) {
        word[word_pos] = '\0';
        total_words++;
        normalize_word(normalized, word);
        
        size_t* cnt = (size_t*)__vTable_get__(&table, normalized);
        if (cnt) {
            (*cnt)++;
        } else {
            __vTable_add__(&table, normalized, (void*)1);
            unique_words++;
            // wc = (WordCount*)malloc(sizeof(WordCount));
            // wc->word = strdup(normalized);
            // wc->count = 1;
        }
    }
    // count = (size_t*)__vTable_get__(&table, normalized_target);
    // printf("Count: %ld\n", *count);
    
    clock_t build_end = clock();
    double build_time = ((double)(build_end - build_start) * 1000 / CLOCKS_PER_SEC);
    
    printf("File statistics:\n");
    printf("  Total words: %ld\n", total_words);
    printf("  Unique words: %ld\n", table.inserts_num);
    printf("  Allocated space: %ld\n", table.size);
    printf("  Load factor (α): %.4f\n", (double)unique_words / table.size);
    printf("  Build time: %.2f ms\n", build_time);
    
    // Optional warmup - do multiple lookups to get hot cache
    if (warmup > 0) {
        printf("Warming up with %d lookups...\n", warmup);
        for (int i = 0; i < warmup; i++) {
            volatile size_t *wc = (size_t*)__vTable_get__(&table, normalized_target);
            (void)wc;  // Prevent optimization
        }
    }
    count = (size_t*)__vTable_get__(&table, normalized_target);
    printf("Count: %ld\n", *count);
    
    // Lookup target word
    // normalize_word(normalized_target, target);
    
    // clock_t lookup_start = clock();
    // clock_t lookup_end = clock();
    
    // double lookup_time = ((double)(lookup_end - lookup_start) * 1000 / CLOCKS_PER_SEC);
    // long count = result ? result->count : 0;
    
    // printf("\nTarget word '%s' (normalized: '%s'):\n", target, normalized_target);
    // printf("  Lookup time: %.3f ms\n", lookup_time);
    // printf("  Lookup time per op: %.2f ns\n", lookup_time * 1e6);
    
    // Cleanup
    fclose(file);
    size_t result = *count;
    __vTable_destroy__(&table);
    return result;
}

// Version 3: Benchmark multiple lookups
void benchmark_lookups(const char *filename, const char *words[], int num_words, int iterations) {
    printf("\n=== BENCHMARK: %d lookups × %d iterations ===\n", num_words, iterations);
    
    __vTable__ table;
    __vTable_init__(&table, 1 << 20, 0);
    
    // Build table first
    FILE *file = fopen(filename, "r");
    if (!file) return;
    
    char buffer[BUFFER_SIZE];
    char word[MAX_WORD_LEN];
    char normalized[MAX_WORD_LEN];
    int in_word = 0;
    int word_pos = 0;
    
    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (char *c = buffer; *c; c++) {
            if (isalnum(*c) || *c == '\'' || *c == '-') {
                if (!in_word) {
                    in_word = 1;
                    word_pos = 0;
                }
                if (word_pos < MAX_WORD_LEN - 1) {
                    word[word_pos++] = tolower(*c);
                }
            } else {
                if (in_word) {
                    word[word_pos] = '\0';
                    normalize_word(normalized, word);
                    
                    if (!__vTable_get__(&table, normalized)) {
                        __vTable_add__(&table, normalized, (void*)(intptr_t)1);
                    }
                    in_word = 0;
                }
            }
        }
    }
    fclose(file);
    
    printf("Table built. Size: %zu, α: %.4f\n", table.size, 
           (double)__vTable_count__(&table) / table.size);
    
    // Normalize all target words
    char *normalized_words[num_words];
    for (int i = 0; i < num_words; i++) {
        normalized_words[i] = malloc(MAX_WORD_LEN);
        normalize_word(normalized_words[i], words[i]);
    }
    
    // Cold cache lookups (first time)
    volatile long dummy = 0;
    clock_t start = clock();
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < num_words; i++) {
            if (__vTable_get__(&table, normalized_words[i])) {
                dummy++;
            }
        }
    }
    clock_t end = clock();
    double cold_time = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
    double cold_per_op = cold_time * 1e6 / (num_words * iterations);
    
    // Hot cache lookups (second pass - should be in cache)
    start = clock();
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < num_words; i++) {
            if (__vTable_get__(&table, normalized_words[i])) {
                dummy++;
            }
        }
    }
    end = clock();
    double hot_time = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
    double hot_per_op = hot_time * 1e6 / (num_words * iterations);
    
    printf("\nResults (%d words × %d iterations = %d ops):\n", 
           num_words, iterations, num_words * iterations);
    printf("  Cold cache: %.2f ms total, %.2f ns/op\n", cold_time, cold_per_op);
    printf("  Hot cache:  %.2f ms total, %.2f ns/op\n", hot_time, hot_per_op);
    printf("  Speedup: %.2fx\n", cold_per_op / hot_per_op);
    printf("  Dummy: %ld (prevent optimization)\n", dummy);
    
    // Cleanup
    for (int i = 0; i < num_words; i++) {
        free(normalized_words[i]);
    }
    
    // Free table
    for (size_t i = 0; i < table.size; i++) {
        if (table.data[i].data) {
            // No need to free strings since we used simple integers
        }
    }
    __vTable_destroy__(&table);
}

// // Simple test main
// int main(int argc, char **argv) {
//     if (argc < 3) {
//         printf("Usage: %s <filename> <word> [warmup_lookups]\n", argv[0]);
//         printf("Example: %s file.txt the 10000\n", argv[0]);
//         return 1;
//     }
    
//     const char *filename = argv[1];
//     const char *target = argv[2];
//     int warmup = (argc > 3) ? atoi(argv[3]) : 0;
    
//     printf("Testing word count for '%s' in %s\n", target, filename);
//     printf("========================================\n\n");
    
//     // Version 1: Basic scan (verification)
//     printf("--- Basic scan (no hash table) ---\n");
//     clock_t start = clock();
//     long basic_count = count_word_basic(filename, target);
//     clock_t end = clock();
//     if (basic_count >= 0) {
//         printf("Count: %ld\n", basic_count);
//         printf("Time: %.2f ms\n\n", ((double)(end - start) * 1000 / CLOCKS_PER_SEC));
//     }
    
//     // Version 2: Hash table version
//     printf("--- Hash table version ---\n");
//     long ht_count = count_word_with_hashtable(filename, target, warmup);
//     printf("\n");
    
//     // Version 3: Benchmark multiple common words
//     const char *common_words[] = {"the", "be", "to", "of", "and", "a", "in", "that", "have", "i"};
//     benchmark_lookups(filename, common_words, 10, 10000);
    
//     return 0;
// }
