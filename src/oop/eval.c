#include "eval.h"


typedef struct __vTableProbeId__
{
  size_t id;
  size_t pow;
} __vTableProbeId__;

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

__vTableHash__ __class_vtable_hash__(const char* key) {
  return (__vTableHash__){.hashX=defaultVTableHasher(key, 0), \
                          .hashY=defaultVTableHasher(key, 1)};
}

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

static inline __vTableProbeId__ __vTable_probe__(__vTable__* table, __vTableHash__ hash) {
  size_t id0 = hash.hashX & (table->size - 1);
  size_t idx = id0;
  size_t cnt = 1;
  size_t pow = 0;
  while (cnt < __DEFAULT_VTABLE_MLT_OFFSET__ * table->size &&
         (table->data[idx].data &&
          (hash.hashX != table->data[idx].hash.hashX ||
           hash.hashY != table->data[idx].hash.hashY))) {
    idx = (id0 + cnt) & (table->size - 1);
    cnt *= 2;
    pow++;
  }
  if (cnt >= __DEFAULT_VTABLE_MLT_OFFSET__ * table->size) {
    return (__vTableProbeId__){};
  }
  return (__vTableProbeId__){.id=idx + 1, .pow=pow};
}

#else

static inline size_t __vTable_probe__(__vTable__* table, __vTableHash__ hash) {
  size_t id0 = hash.hashX % table->size;
  size_t idx = id0;
  size_t cnt = 1;
  size_t pow = 0;
  while (cnt < __DEFAULT_VTABLE_MLT_OFFSET__ * table->size &&
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

static size_t __vTable_reserve__(__vTable__* table, size_t new_size) {
  __vTableNode__* tmp_data = table->data;
  table->data = (__vTableNode__*)calloc(new_size, sizeof(__vTableNode__));
  PUSH_EXCEPTION(size_t);
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
      PUSH_EXCEPTION(size_t);
      idx = __vTable_probe__(table, tmp_data[i].hash);
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
  PUSH_EXCEPTION(size_t);
  return table->size;
}

void* __vTable_init__(__vTable__* table, size_t default_size, generic_function_t hasher) {
  *table = (__vTable__){.hasher = (__vTable_byte_hasher_t__)defaultVTableHasher};
  if (hasher) {
    table->hasher = (__vTable_byte_hasher_t__)hasher;
  }
  __vTable_reserve__(table, default_size ? default_size : __DEFAULT_VTABLE_SIZE__);
  PUSH_EXCEPTION(void*);
  return table;
}

void* __vTable_destroy__(__vTable__* table) {
  if (table->data) {
    free(table->data);
    PUSH_EXCEPTION(void*);
  }
  return NULL;
}

void* __vTable_add__(__vTable__* table, __vTableHash__ hash, __vTableNode__ node) {
  __vTableProbeId__ idx;
  idx = __vTable_probe__(table, hash);
  if (!idx.id) {
    __vTable_reserve__(table, table->size * 2);
    PUSH_EXCEPTION(void*);
    idx = __vTable_probe__(table, hash);
  }
  table->data[idx.id - 1].data = node.data;
  table->data[idx.id - 1].data_mask = node.data_mask;
  table->data[idx.id - 1].data_shift = node.data_shift;
  table->data[idx.id - 1].hash = hash;

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

  __vTableNode_set_mask_bit_t__(&(table->data[hash.hashX & (table->size - 1)]), idx.pow);

#else

  __vTableNode_set_mask_bit_t__(&(table->data[hash.hashX % table->size]), idx.pow);

#endif
  return table;
}

void* __vTable_remove__(__vTable__* table, __vTableHash__ hash) {
  __vTableProbeId__ idx;
  do {
    idx = __vTable_probe__(table, hash);
    if (!idx.id) {
      __vTable_reserve__(table, table->size * 2);
    PUSH_EXCEPTION(void*);
    }
  } while (!idx.id);
  table->data[idx.id - 1] = (__vTableNode__){};

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE

  __vTableNode_set_mask_bit_f__(&(table->data[hash.hashX & (table->size - 1)]), idx.pow);

#else

  __vTableNode_set_mask_bit_f__(&(table->data[hash.hashX % table->size]), idx.pow);

#endif
  return table;
}

__vTableNode__* __vTable_get__(__vTable__* table, __vTableHash__ hash) {

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE
  
  size_t mask = table->data[hash.hashX & (table->size - 1)].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashX == hash.hashX &&
        table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashY == hash.hashY) {
      return &(table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)]);
    }
  }

#else
  
  size_t mask = table->data[hash.hashX % table->size].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hash.hashX + primary_bit / 2) % table->size].hash.hashX == hash.hashX &&
        table->data[(hash.hashX + primary_bit / 2) % table->size].hash.hashY == hash.hashY) {
      return &(table->data[(hash.hashX + primary_bit / 2) % table->size]);
    }
  }

#endif

  return NULL;
}

BOOL __vTable_check__(__vTable__* table, __vTableHash__ hash) {

#if __VTABLE_SIZE_IS_POWER_OF_2__ == TRUE
  
  size_t mask = table->data[hash.hashX & (table->size - 1)].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashX == hash.hashX &&
        table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashY == hash.hashY) {
      return TRUE;
    }
  }

#else
  
  size_t mask = table->data[hash.hashX % table->size].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hash.hashX + primary_bit / 2) % table->size].hash.hashX == hash.hashX &&
        table->data[(hash.hashX + primary_bit / 2) % table->size].hash.hashY == hash.hashY) {
      return TRUE;
    }
  }

#endif

  return FALSE;
}

void* __vTable_join__(__vTable__* table, __vTable__* source) {
  if (!source) {
    return NULL;
  }
  if (source->size >= table->size) {
    __vTable_reserve__(table, source->size * 2);
    PUSH_EXCEPTION(void*);
  }
  for (size_t i = 0; i < source->size; ++i) {
    if (source->data[i].hash.hashX || source->data[i].hash.hashY) {
      __vTable_add__(table, source->data[i].hash, source->data[i]);
      PUSH_EXCEPTION(void*);
    }
  }
  return table;
}


long long __LL_ADD_FUNCTION(long long a, long long b) {
  return a + b;
}

long long __LL_SUB_FUNCTION(long long a, long long b) {
  return a - b;
}

long long __LL_DIV_FUNCTION(long long a, long long b) {
  return a / b;
}

long long __LL_MUL_FUNCTION(long long a, long long b) {
  return a * b;
}

long long __LL_MOD_FUNCTION(long long a, long long b) {
  return a % b;
}

long long __LL_AND_FUNCTION(long long a, long long b) {
  return a & b;
}

long long __LL_OR_FUNCTION(long long a, long long b) {
  return a | b;
}

long long __LL_XOR_FUNCTION(long long a, long long b) {
  return a ^ b;
}

long long __LL_POW_FUNCTION(long long a, long long b) {
  if (b < 0) {
    return 0;
  }
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a;
  }
  return __LL_POW_FUNCTION(a, b / 2) * __LL_POW_FUNCTION(a, (b + 1) / 2);
}

long double __LD_ADD_FUNCTION(long double a, long double b) {
  return a + b;
}

long double __LD_SUB_FUNCTION(long double a, long double b) {
  return a - b;
}

long double __LD_DIV_FUNCTION(long double a, long double b) {
  return a / b;
}

long double __LD_MUL_FUNCTION(long double a, long double b) {
  return a * b;
}

long double __LD_POW_FUNCTION(long double a, long double b) {
  if (b < 0) {
    return 1 / a;
  }
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a;
  }
  return __LL_POW_FUNCTION(a, b / 2) * __LL_POW_FUNCTION(a, (b + 1) / 2);
}

int __LAMBDA_EXPRESSION_GET_TYPE(const __int16_t* mask) {
  return (*mask) & 7;
}

void __LAMBDA_EXPRESSION_SET_TYPE(__int16_t* mask, int type) {
  *mask &= (1 << (sizeof(__int16_t) * __CHAR_BIT__)) - 8;
}


typedef enum TOKEN_TYPE {
  NIL_T,
  VAR_T,
  FUNCTION_T,
  NUMERIC_T,
  TABLE_T,
  EXTERN_T
} TOKEN_TYPE;

typedef enum OP_TOKEN {
  NONE,
  VAR_T,
  FUNCTION_T,
  NUMERIC_T,
  TABLE_T,
  EXTERN_T
} OP_TOKEN;

typedef struct eval_proc_op_t {
  OP_TOKEN token;
  void* arg1;
  void* arg2;
  void* arg3;
} eval_proc_op_t;

typedef struct eval_proc_var_t {
} eval_proc_var_t;


void* eval_compile(eval_proc_t* self, const char* string, ...) {
  char cur_token[EVAL_MAX_TOKEN_LENGTH];
  TOKEN_TYPE cur_token_type;

  return NULL;
}

void* eval_run(eval_proc_t* self, ...) {
  return NULL;
}

CLASS_END(eval_proc_t, STATIC, ;) DEFAULT_DESTROY(eval_proc_t);
