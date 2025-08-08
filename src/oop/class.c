#include "class.h"

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

typedef struct __vTable__
{
  generic_function_t hasher;
  __vTableNode__* data;
  size_t size;
} __vTable__;

size_t defaultVTableHasher(const char* key, char id) {

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

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

__vTableProbeId__ __vTable_probe__(__vTable__* table, __vTableHash__ hash) {
  size_t idx = hash.hashX & (table->size - 1);
  size_t cnt = 1;
  size_t pow = 0;
  while (cnt < __DEFAULT_VTABLE_MLT_OFFSET__ * table->size &&
         (table->data[idx].data &&
          (hash.hashX != table->data[idx].hash.hashX ||
           hash.hashY != table->data[idx].hash.hashY))) {
    printf("%d\n", pow);
    idx = (idx + cnt) & (table->size - 1);
    cnt *= 2;
    pow++;
  }
  if (cnt >= __DEFAULT_VTABLE_MLT_OFFSET__ * table->size) {
    return (__vTableProbeId__){};
  }
  return (__vTableProbeId__){.id=idx + 1, .pow=pow};
}

#else

size_t __vTable_probe__(__vTable__* table, __vTableHash__ hash) {
  size_t idx = hash.hashX % table->size;
  size_t cnt = 1;
  size_t pow = 0;
  while (cnt < __DEFAULT_VTABLE_MLT_OFFSET__ * table->size &&
         (table->data[idx].data &&
          (hash.hashX != table->data[idx].hash.hashX ||
           hash.hashY != table->data[idx].hash.hashY))) {
    idx = (idx + cnt) % table->size;
    cnt *= 2;
  }
  return (__vTableProbeId__){.id=idx + 1, .pow=pow};
}

#endif

void __vTableNode_set_mask_bit_t__(__vTableNode__* node, size_t cnt) {
  node->mask |= (1 << cnt);
}

void __vTableNode_set_mask_bit_f__(__vTableNode__* node, size_t cnt) {
  size_t tmp_val = (1 << cnt);
  node->mask = (node->mask |= tmp_val) ^ tmp_val;
}

size_t __vTable_reserve__(__vTable__* table, size_t new_size) {
  __vTableNode__* tmp_data = table->data;
  table->data = (__vTableNode__*)calloc(new_size, sizeof(__vTableNode__));
  size_t tmp_size = table->size;
  table->size = new_size;
  if (tmp_data = NULL) {
    return table->size;
  }
  __vTableProbeId__ idx = (__vTableProbeId__){};
  for (size_t i = 0; i < tmp_size; ++i) {
    printf("%d - %d, %d\n", i, idx.id, idx.pow);
    idx = __vTable_probe__(table, tmp_data[i].hash);
    printf("%d - %d, %d\n", i, idx.id, idx.pow);
    if (!idx.id) {
      free(table->data);
      table->data = tmp_data;
      return __vTable_reserve__(table, new_size * 2);
    }
    table->data[idx.id - 1].data = tmp_data[i].data;
    table->data[idx.id - 1].hash = tmp_data[i].hash;

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

    __vTableNode_set_mask_bit_t__(&(table->data[tmp_data[i].hash.hashX & (table->size - 1)]), idx.pow);

#else

    __vTableNode_set_mask_bit_t__(&(table->data[tmp_data[i].hash.hashX % table->size]), idx.pow);

#endif

  }
  free(tmp_data);
  return table->size;
}

void* __vTable_init__(__vTable__* table, size_t default_size, generic_function_t hasher) {
  *table = (__vTable__){.hasher = (generic_function_t)defaultVTableHasher};
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

void* __vTable_add__(__vTable__* table, char* key, void* value) {
  size_t hashX = (size_t)table->hasher(key, 0);
  size_t hashY = (size_t)table->hasher(key, 1);
  __vTableHash__ hash = (__vTableHash__){.hashX = hashX, .hashY = hashY};
  __vTableProbeId__ idx;
  idx = __vTable_probe__(table, hash);
  if (!idx.id) {
    printf("EXpand!\n");
    __vTable_reserve__(table, table->size * 2);
    idx = __vTable_probe__(table, hash);
  }
  table->data[idx.id - 1].data = value;
  table->data[idx.id - 1].hash = hash;

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

  __vTableNode_set_mask_bit_t__(&(table->data[hash.hashX & (table->size - 1)]), idx.pow);

#else

  __vTableNode_set_mask_bit_t__(&(table->data[hash.hashX % table->size]), idx.pow);

#endif
  return table;
}

void* __vTable_remove__(__vTable__* table, char* key) {
  size_t hashX = (size_t)table->hasher(key, 0);
  size_t hashY = (size_t)table->hasher(key, 1);
  __vTableHash__ hash = (__vTableHash__){.hashX = hashX, .hashY = hashY};
  __vTableProbeId__ idx;
  do {
    idx = __vTable_probe__(table, hash);
    if (!idx.id) {
      __vTable_reserve__(table, table->size * 2);
    }
  } while (!idx.id);
  table->data[idx.id - 1].data = 0;
  table->data[idx.id - 1].hash = (__vTableHash__){};

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

  __vTableNode_set_mask_bit_f__(&(table->data[hash.hashX & (table->size - 1)]), idx.pow);

#else

  __vTableNode_set_mask_bit_f__(&(table->data[hash.hashX % table->size]), idx.pow);

#endif
  return table;
}

void* __vTable_get__(__vTable__* table, char* key) {
  size_t hashX = (size_t)table->hasher(key, 0);
  size_t hashY = (size_t)table->hasher(key, 1);

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE
  
  size_t mask = table->data[hashX & (table->size - 1)].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hashX + primary_bit) & (table->size - 1)].hash.hashX == hashX &&
        table->data[(hashX + primary_bit) & (table->size - 1)].hash.hashY == hashY) {
      return table->data[(hashX + primary_bit) & (table->size - 1)].data;
    }
  }

#else
  
  size_t mask = table->data[hashX % table->size].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hashX + primary_bit) % table->size].hash.hashX == hashX &&
        table->data[(hashX + primary_bit) % table->size].hash.hashY == hashY) {
      return table->data[(hashX + primary_bit) % table->size].data;
    }
  }

#endif

  return NULL;
}

BOOL __vTable_check__(__vTable__* table, char* key) {
  size_t hashX = (size_t)table->hasher(key, 0);
  size_t hashY = (size_t)table->hasher(key, 1);

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE
  
  size_t mask = table->data[hashX & (table->size - 1)].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hashX + primary_bit) & (table->size - 1)].hash.hashX == hashX &&
        table->data[(hashX + primary_bit) & (table->size - 1)].hash.hashY == hashY) {
      return TRUE;
    }
  }

#else
  
  size_t mask = table->data[hashX % table->size].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hashX + primary_bit) % table->size].hash.hashX == hashX &&
        table->data[(hashX + primary_bit) % table->size].hash.hashY == hashY) {
      return TRUE;
    }
  }

#endif

  return FALSE;
}
