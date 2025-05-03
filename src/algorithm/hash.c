#include "hash.h"

#if (__SIZE_WIDTH__ == 64)
size_t hash_finalise(size_t hash) {
  hash ^= hash >> 27;
  hash *= 0x3C79AC492BA7B653UL;
  hash ^= hash >> 33;
  hash *= 0x1C69B3F74AC4AE35UL;
  hash ^= hash >> 27;
  return hash;
}
#else
size_t hash_finalise(size_t hash) {
  hash ^= hash >> 16;
  hash *= 0x7feb352dU;
  hash ^= hash >> 15;
  hash *= 0x846ca68bU;
  hash ^= hash >> 16;
  return hash;
}
#endif

size_t hash_byte_array(void* src, size_t cnt) {
  size_t hash_val = 5381;
  size_t chunk_cnt = 0;
  for (size_t i = 0; i < cnt; chunk_cnt = (i += sizeof(size_t))) {
    hash_val = (hash_val << 5) + hash_val + *(size_t*)(src + i);
  }
  for (size_t i = chunk_cnt - sizeof(size_t); i < cnt; ++i) {
    hash_val = (hash_val << 5) + hash_val + *(char*)(src + i);
  }
  hash_val = hash_finalise(hash_val);
  return hash_val;
}
