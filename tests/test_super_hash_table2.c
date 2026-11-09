#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"

#define HASH_GROUP_SIZE 32
#define HASH_GROUP_MINI_HASH_SIZE (32 / HASH_GROUP_SIZE)

#define __DEFAULT_VTABLE_SIZE__ 8
#define __DEFAULT_VTABLE_MLT_OFFSET__ 8
#define __VTABLE_SIZE_IS_POWER_OF_2__ TRUE

typedef struct TableHash {
  size_t hashX;
  size_t hashY;
} TableHash;

typedef union TableKey {
  TableHash hashkey;
  struct {
    void* key;
    size_t hashY;
  } fullkey;
  unsigned char bytekey[sizeof(TableHash)];
} TableKey;

typedef struct TableNode TableNode;

typedef uint8_t group_mini_hash_t;

typedef struct NodeGroup {
  size_t group_start; //                            physical group data index
  union {
    uint32_t i32x1[1];
    uint16_t i16x2[2];
  } bloom_filter; //                                quick search look-up
  uint32_t op_counter; //                           ammortized operations
  uint8_t group_flag_mask; //                       group mode flags
  uint8_t size; //                                  optimize additions (tail index)
  uint16_t temperature; //                          group temperature
  uint32_t group_chain_mask_l32;
  uint64_t group_chain_mask_u64; //                 group chaining
  group_mini_hash_t mini_hash[HASH_GROUP_SIZE]; //  quick hash SIMD check
} NodeGroup;

typedef struct TableNode {
  TableKey key;
} TableNode;

typedef struct type_data_t type_data_t;

typedef struct TableData {
  struct {
    void* raw_data_ptr;
    type_data_t* type_data;
  } data;
} TableData;

typedef struct Table {
  // Utility fields
  uint64_t mask;
  size_t capacity;
  size_t group_num;
  size_t size;

  TableHash (*hash_function)(const void* key, size_t len); // hasher
  NodeGroup* groups; //                                       represents groups of nodes; each group corresponds to nodes[i]:nodes[i + HASH_GROUP_SIZE]
  TableNode* nodes; //                                        table nodes
  TableData* data; //                                         table data

  // Stats and adaptation
  size_t op_counter;
  size_t last_rebalance_time;
  
  // size_t* group_virtual_addr; //   virtual addressing for dynamic pattern optimizations of group access
} Table;

// Встроенные функции
static inline group_mini_hash_t get_mini_hash(TableHash hash) {
    return (hash.hashX ^ hash.hashY) & 0xFF;
}

static inline uint32_t get_bloom_bits(TableHash hash) {
    return (1llu << (hash.hashX & 31)) | (1llu << ((hash.hashY & 31) + 16));
}

Table* table_init(Table* table, size_t initial_capacity, TableHash (*hash_function)(const void* key, size_t len));
Table* table_resize(Table* table, size_t new_size);
void table_destroy(Table* table);
int table_insert(Table* table, const void* key, size_t key_len, TableData value);
void* table_find(Table* table, const void* key, size_t key_len);
int table_remove(Table* table, const void* key, size_t key_len);
Table* table_rebalance(Table* table);


#include <immintrin.h>

// SIMD поиск по 32 байтам mini_hash (AVX2)
static inline uint32_t simd8_match(const uint8_t* mini_hash, uint8_t target) {
  // Загружаем 32 байт mini_hash
  __m256i vtarget = _mm256_set1_epi8(target);
  __m256i vhash = _mm256_load_si256((const __m256i*)mini_hash);
  
  // Сравниваем
  __m256i vcmp = _mm256_cmpeq_epi8(vtarget, vhash);
  
  // Получаем маску совпадений (32 бит)
  return _mm256_movemask_epi8(vcmp);
}


#include <stdlib.h>
#include <string.h>

// Простая хеш-функция по умолчанию (можно заменить на xxhash, siphash и т.д.)
static TableHash default_hash(const void* key, size_t len) {
  const unsigned char* data = (const unsigned char*)key;
  uint64_t h1 = 0x9e3779b97f4a7c15ULL;
  uint64_t h2 = 0xbf58476d1ce4e5b9ULL;
  
  for (size_t i = 0; i < len; i++) {
    h1 ^= data[i];
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 16;
    
    h2 += data[i];
    h2 *= 0xc4ceb9fe1a85ec53ULL;
    h2 ^= h2 >> 23;
  }
  
  return (TableHash){.hashX = h1, .hashY = h2};
}


// Пакетная проверка bloom фильтра для нескольких групп
static inline __m256i simd32_bloom_check(const uint32_t* bloom_filters, 
                                         uint32_t bloom_bits) {
  __m256i vbloom = _mm256_loadu_si256((const __m256i*)bloom_filters);
  __m256i vbits = _mm256_set1_epi32(bloom_bits);
  
  // AND для проверки установленных битов
  __m256i vand = _mm256_and_si256(vbloom, vbits);
  
  // Сравниваем с vbits (должны быть равны для совпадения)
  return _mm256_cmpeq_epi32(vand, vbits);
}


Table* table_init(Table* table, size_t initial_capacity, TableHash (*hash_function)(const void* key, size_t len)) {
  *table = (Table){};
  table->capacity = initial_capacity;
  table->group_num = initial_capacity / HASH_GROUP_SIZE;
  posix_memalign((void**)&table->groups, 64, sizeof(NodeGroup) * initial_capacity / HASH_GROUP_SIZE);
  posix_memalign((void**)&table->nodes, 64, sizeof(TableNode) * initial_capacity);
  posix_memalign((void**)&table->data, 64, sizeof(TableData) * initial_capacity);
  table->hash_function = hash_function;
  // table->group_virtual_addr = (size_t*)malloc(sizeof(size_t) * initial_capacity / HASH_GROUP_SIZE);
  for (size_t i = 0; i < initial_capacity / HASH_GROUP_SIZE; ++i) {
    table->groups[i] = (NodeGroup){.group_start = i * HASH_GROUP_SIZE};
    // table->group_virtual_addr[i] = i;
  }
  return table;
}

Table* table_resize(Table* table, size_t new_size) {
  return table;
}

void table_destroy(Table* table){
  free(table->groups);
  free(table->nodes);
  free(table->data);
  // free(table->group_virtual_addr);
}

// static inline size_t table_probe(Table* table, TableHash hash) {
//   size_t id0 = hash.hashX % table->size;
//   size_t idx = id0;
//   size_t cnt = 1;
//   size_t pow = 0;
//   while (cnt < __DEFAULT_VTABLE_MLT_OFFSET__ * table->size &&
//          (table->data[idx].data &&
//           (hash.hashX != table->data[idx].hash.hashX ||
//            hash.hashY != table->data[idx].hash.hashY))) {
//     idx = (id0 + cnt) % table->size;
//     cnt *= 2;
//   }
//   return (__vTableProbeId__){.id=idx + 1, .pow=pow};
// }

int table_insert(Table* table, const void* key, size_t key_len, TableData value) {
  table->size++;
  TableNode* t_nodes = table->nodes;
  TableData* t_data = table->data;
  NodeGroup* t_groups = table->groups;
  size_t t_group_num = table->group_num;
  TableHash hash = table->hash_function(key, key_len);
  size_t group_index = (hash.hashX^(-hash.hashY)) & (t_group_num - 1);
  // size_t group_index = hash.hashX & (t_group_num - 1);
  // size_t group_index = (hash.hashX * 0x9e3779b97f4a7c15ULL) & (t_group_num - 1);
  size_t group_step = (hash.hashY & 0xFE) + 7;
  NodeGroup* og_group = &t_groups[group_index];
  // og_group->op_counter++;
  NodeGroup* group = og_group;
  size_t i = 0;
  // size_t offset = 1;
  while (group->size == HASH_GROUP_SIZE) {
    group_index += group_step;
    i++;
    if (i > 32) {
      printf("Long group chain! \n"
             "Debug data: {Step: %d, Table size: %d, Table capacity: %d, Group index: %d, Og group op count: %d, Og group index: %d}\n",
             i, table->size, table->capacity, group_index & (t_group_num - 1), og_group->op_counter, hash.hashX & (t_group_num - 1));
            //  group_step, table->size, table->capacity, group_index & (t_group_num - 1), og_group->op_counter, hash.hashX & (t_group_num - 1));
      return 0;
    }
    if ((i > t_group_num) || (i > 95)) {
      printf("Not enough space!\n");
      return 0;
    }
    // group = &t_groups[(group_index + ((((i + 1) * (i + 1)) >> 2))) & (t_group_num - 1)];
    group = &t_groups[(group_index) & (t_group_num - 1)];
    // offset++;
  }
  size_t node_index = group->group_start + group->size++;
  group->mini_hash[group->size - 1] = get_mini_hash(hash);
  og_group->bloom_filter.i32x1[0] |= get_bloom_bits(hash);
  og_group->op_counter = (((og_group->op_counter & ((1 << 12) - 1)) + 1) & ((1 << 12) - 1)) + \
                         og_group->op_counter & ((1llu << 32) - (1llu << 12));
  if (i > 64) {
    og_group->group_chain_mask_l32 |= 1llu << (i - 64);
  } else {
    og_group->group_chain_mask_u64 |= 1llu << i;
  }
  t_nodes[node_index] = (TableNode){.key.hashkey = hash};
  t_data[node_index] = value;
  // printf("Group is %d\n", group);
  // if (202692 == ((((group_index) & (t_group_num - 1)) + 1) & 0xFFFFFFFFu)) {
  //   printf("Groups (3358787): OG - %u, CR - %u, CRID - %u; Node: AD - %u, ID - %u\n", og_group, group, i, node_index, group->size - 1);
  // }
  return (int)(((group_index) & (t_group_num - 1)) + 1);
}

TableData* table_get(Table* table, const void* key, size_t key_len) {
  TableNode* t_nodes = table->nodes;
  TableData* t_data = table->data;
  NodeGroup* t_groups = table->groups;
  size_t t_group_num = table->group_num;
  TableHash hash = table->hash_function(key, key_len);
  size_t group_index = (hash.hashX^(-hash.hashY)) & (t_group_num - 1);
  // size_t group_index = hash.hashX & (t_group_num - 1);
  // size_t group_index = (hash.hashX * 0x9e3779b97f4a7c15ULL) & (t_group_num - 1);
  size_t group_step = (hash.hashY & 0xFE) + 7;
  NodeGroup* og_group = &t_groups[group_index];
  NodeGroup* group = og_group;
  uint8_t minihash = get_mini_hash(hash);
  size_t bloom_bits = get_bloom_bits(hash);
  TableKey tkey = (TableKey){.hashkey = hash};
  uint64_t group_mask = og_group->group_chain_mask_u64;

  size_t og_group_start = og_group->group_start;
  TableNode* happy_path_node_ptr = &t_nodes[og_group_start];
  // const TableNode happy_path_nodes[] = {t_nodes[og_group_start], t_nodes[og_group_start + 1], t_nodes[og_group_start + 2], t_nodes[og_group_start + 3]};

  // if (group_mask) {
  //   group_mask--;
  // } else {
  //   return 0;
  // }
  
  // FAST PATH 2: Check mini-hashes with SCALAR first for small groups
  // if (og_group->size < HASH_GROUP_SIZE) {
  if ((og_group->bloom_filter.i32x1[0] & bloom_bits) != bloom_bits) {
    return NULL;
  }

  if (og_group->size < 13) {
    // Scalar loop for small groups - cheaper than AVX2 setup
    for (size_t i = 0; i < og_group->size; i++) {
      if (og_group->mini_hash[i] == minihash) {
        if (happy_path_node_ptr[i].key.hashkey.hashX == hash.hashX &&
            happy_path_node_ptr[i].key.hashkey.hashY == hash.hashY) {
          return &t_data[og_group_start + i];
        }
      }
    }
  } else {
    // AVX2 only for larger groups where it's worth it
    uint32_t match_mask = simd8_match((uint8_t*)og_group->mini_hash, minihash);
    // match_mask &= ~0x0F;  // Skip first 4
    
    while (match_mask) {
      // printf("Possible match!\n");
      // int slot = __builtin_ctz(match_mask);
      size_t slot = match_mask & (-match_mask);
      match_mask ^= slot;
      slot = __builtin_ctzll(slot);
      
      if (happy_path_node_ptr[slot].key.hashkey.hashX == hash.hashX &&
          happy_path_node_ptr[slot].key.hashkey.hashY == hash.hashY) {
        return &t_data[og_group_start + slot];
      }
    }
  }
  // }

  size_t offset = 1;
  uint32_t match_mask = 0;
  offset = group_mask & (-group_mask);
  group_mask ^= offset;
  while (group_mask) {
    offset = group_mask & (-group_mask);
    group_mask ^= offset;
    offset = __builtin_ctzll(offset);
    group = &t_groups[(group_index + (offset * group_step)) & (t_group_num - 1)];
    // printf("Get (%d) Group is %d\n", offset - 3, group);
    
    if (match_mask = simd8_match((uint8_t*)group->mini_hash, minihash)) {
      size_t current_group_start = group->group_start;
      TableNode* node_first = &t_nodes[group->group_start];
      _mm_prefetch((const char*)&t_nodes[group->group_start], _MM_HINT_T0);
      while (match_mask) {
        // printf("Possible match!\n");
        // int slot = __builtin_ctz(match_mask);
        size_t slot = match_mask & (-match_mask);
        match_mask ^= slot;
        slot = __builtin_ctzll(slot);
        
        if (node_first[slot].key.hashkey.hashX == hash.hashX &&
            node_first[slot].key.hashkey.hashY == hash.hashY) {
          return &t_data[current_group_start + slot];
        }
      }
      // printf("%d\n", simd8_match((uint8_t*)group->mini_hash, minihash));
    }
    
  }
  return NULL;
}

int table_remove(Table* table, const void* key, size_t key_len);
Table* table_rebalance(Table* table);


TableHash fastihasher(uint64_t key, size_t len){
  uint64_t h1 = 0x9e3779b97f4a7c15ULL;
  uint64_t h2 = 0xbf58476d1ce4e5b9ULL;
  return (TableHash){.hashX = ((key * h2) ^ h1), .hashY = ((key * h1) ^ h2)};
}

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

static inline size_t fast_hash(const char* key, char id) {
    // if (strlen(key) != 15) {
    //   return xxh32(key, strlen(key), id * 0x9E3779B1U);
    // }
    uint64_t low = *(uint64_t*)key;
    uint64_t high = *(uint64_t*)(key + 8);
    uint64_t mix = low ^ high ^ (id * 0x9E3779B97F4A7C15llu);
    
    // Just two rounds of mixing
    mix ^= mix >> 33;
    mix *= 0xFF51AFD7ED558CCDllu;
    mix ^= mix >> 33;
    
    return mix;
}

static inline TableHash test_hash(const void* key, size_t len) {
    uint32_t h = xxh32(key, len, 0x9E3779B9);
    return (TableHash){.hashX = h, .hashY = h ^ 0x9E3779B9};
}

static inline size_t defaultVTableHasher(const char* key, char id) {
  return fast_hash(key, id);
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
    hash += lookup_primes[(*(key) + id) & 15] ^ *((unsigned char*)key);
    hash ^= lookup_primes[(*(key) + id) & 15];
    key++;
  }

  return hash;
}

static inline TableHash default_t_hasher(const char* key, size_t len) {
  // return (TableHash){.hashX=xxh32(key, len, 0), .hashY=xxh32(key, len, 1)};
  return (TableHash){.hashX=defaultVTableHasher(key, 0), .hashY=defaultVTableHasher(key, 1)};
  // return test_hash(key, len);
}

#define ScalarFX 50

int main() {

  // const size_t ax = 1;
  // const size_t bx = 5000000;
  const size_t sc = 150000;
  const size_t default_size = (1llu << 24);

  Table t;
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
  table_init(&t, default_size, (TableHash (*)(const void *key, size_t len))default_t_hasher);
  printf("init\n");
  time_s = clock();
  for (size_t i = 0; i < ops; ++i) {
    // printf("%d = \"%s\" = %d(X) = %d(Y)\n", i, str + 16 * i, defaultVTableHasher(str + 16 * i, 0), defaultVTableHasher(str + 16 * i, 1));
    int insert_res = table_insert(&t, str + 16 * i, 16, (TableData){.data.raw_data_ptr=(void*)(i + 1), .data.type_data=NULL});
    if (!insert_res) {
      printf("%d - Critical Error!\n", i);
      free(str);
      table_destroy(&t);
      exit(0);
    }
    // if (i == 3358787) {
    //   printf("Insert result(3358787) is %u\n", insert_res);
    // }
    // if (!__vTable_check__(&t, str + 16 * i)) {
    //   printf("%d - Critical Error!\n", i);
    //   free(str);
    //   __vTable_destroy__(&t);
    //   exit(0);
    // }
  }
  time_f = clock();
  printf("Alpfa: %f\n", ((double)ops)/((double)t.capacity));
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
  volatile TableData *ptr3 = (TableData*)t.data;
  char sum3 = 0;
  time_s = clock();
  for (int i = 0; i < ops; i++) {
    sum3 += (char)(size_t)ptr3[i & 0xFFF].data.raw_data_ptr;  // Within same 4KB page
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
      if (!table_get(&t, str + 16 * i, 16)) {
        printf("%d - Critical Error!\n", i);
        free(str);
        table_destroy(&t);
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
  printf("Alpha: %f\n", ((double)ops)/((double)t.capacity));
  printf("Time diff - %d ms\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC);
  time_s = clock();
  rnd = 1;
  a = 0;
  b = 1;
  for (size_t i = 0; i < ops; ++i) {
    for (size_t j = 0; j < 100; j++) {
      if (!table_get(&t, str + 16 * i, 16)) {
        printf("%d - Critical Error!\n", i);
        free(str);
        table_destroy(&t);
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
    for (size_t j = 0; j < 1000; j++) {
      if (!table_get(&t, str + 16 * i, 16)) {
        printf("%d - Critical Error!\n", i);
        free(str);
        table_destroy(&t);
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
  // for (size_t i = 0; i < t.size; ++i) {
  //   printf("%d - %d - %d - %d\n", t.data[i].data, t.data[i].mask, t.data[i].hash.hashX, t.data[i].hash.hashY);
  // }
  time_s = clock();
  rnd = 1;
  a = 0;
  b = 1;
  for (size_t i = 0; i < ops; ++i) {
    for (size_t j = 0; j < 1; j++) {
      if (table_get(&t, str + 16 * (i) + 1, 16)) {
        a++;
      }
    }
  }
  time_f = clock();
  printf("Time diff - %d ms with %d False+\n", (time_f - time_s) * 1000 / CLOCKS_PER_SEC, a);
  free(str);
  printf("destroy\n");
  table_destroy(&t);
  return 0;
}














