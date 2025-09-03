#include "class.h"

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

    __vTableNode_set_mask_bit_t__(&(table->data[tmp_data[i].hash.hashX & (table->size - 1)]), idx.pow);

#else

    __vTableNode_set_mask_bit_t__(&(table->data[tmp_data[i].hash.hashX % table->size]), idx.pow);

#endif

  }
  free(tmp_data);
  return table->size;
}

void* __vTable_init__(__vTable__* table, size_t default_size, generic_function_t hasher) {
  *table = (__vTable__){.hasher = (__vTable_byte_hasher_t__)defaultVTableHasher};
  if (hasher) {
    table->hasher = (__vTable_byte_hasher_t__)hasher;
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

void* __vTable_add__(__vTable__* table, __vTableHash__ hash, __vTableNode__ node) {
  __vTableProbeId__ idx;
  idx = __vTable_probe__(table, hash);
  if (!idx.id) {
    __vTable_reserve__(table, table->size * 2);
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
      printf("FOUND!\n");
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
  }
  for (size_t i = 0; i < source->size; ++i) {
    if (source->data[i].hash.hashX || source->data[i].hash.hashY) {
      __vTable_add__(table, source->data[i].hash, source->data[i]);
    }
  }
  return table;
}

void* __InheritanceList_reserve__(__InheritanceList__* list, size_t new_capacity) {
  __InheritanceListNode__* tmp_list = list->list;
  list->list = (__InheritanceListNode__*)malloc(new_capacity * sizeof(__InheritanceListNode__));
  // if (!list->list) {
  //   return NULL;
  // }
  if (list->capacity) {
    memcpy(list->list, tmp_list, list->capacity * sizeof(__InheritanceListNode__));
    free(tmp_list);
  }
  list->capacity = new_capacity;
  return list;
}

void* __InheritanceList_init__(__InheritanceList__* list) {
  list->size = 0;
  list->capacity = 0;
  __InheritanceList_reserve__(list, __DEFAULT_INHERITANCE_LIST_CAPACITY__);
  return list;
}

void* __InheritanceList_destroy__(__InheritanceList__* list) {
  free(list->list);
  *list = (__InheritanceList__){};
  return NULL;
}

void* __InheritanceList_add__(__InheritanceList__* list,
                              void* self,
                              void* instance,
                              __ClassObject__* class) {
  if (list->size + 1 == list->capacity) {
    __InheritanceList_reserve__(list, 2 * list->capacity);
  }
  list->list[list->size].adress_shift = (size_t)(instance - self);
  list->list[list->size].class = class;
  list->size++;
  return list;
}

void* __InheritanceList_remove__(__InheritanceList__* list, __ClassInstance__* instance) {
  size_t i = 0;
  while ((i < list->size) && (list->list[i].class != instance->__meta__->vcls->cls)) { ++i; }
  
  if (i + 1 == list->size) {
    list->size--;
    return list;
  } else if (i + 1 < list->size) {
    list->size--;
    memmove(list->list + i * sizeof(__InheritanceListNode__), \
            list->list + (i + 1) * sizeof(__InheritanceListNode__),
            list->size - i);
    return list;
  }
  return NULL;
}

size_t __InheritanceList_find__(__InheritanceList__* list, __vTableHash__ hash) {
  size_t i = 0;
  while (i < list->size) {
    if (__vTable_check__(list->list[i].class->static_vtable, hash)) {
      return i * 2;
    } else if (__vTable_check__(list->list[i].class->default_vcls->vtable, hash)) {
      return i * 2 + 1;
    }
    i++;
  }
  return (size_t)INVALID;
}

size_t __InheritanceList_find_built_in__(__InheritanceList__* list, __m_enum__ built_in_no) {
  size_t i = 0;
  while (i < list->size) {
    if (*(&(list->list[i].class->default_vcls->__init__) + \
        built_in_no)) {
      return i;
    }
    i++;
  }
  return (size_t)INVALID;
}

BOOL __GET_CLASS_MASK_IS_STATIC__(size_t* mask) {
  return (BOOL)((*mask & 1) && 1);
}

BOOL __GET_CLASS_MASK_IS_HYBRID__(size_t* mask) {
  return (BOOL)((*mask & 2) && 1);
}

BOOL __GET_CLASS_MASK_INHERITS__(size_t* mask) {
  return (BOOL)((*mask & 4) && 1);
}

BOOL __GET_CLASS_MASK_IS_ABSTRACT__(size_t* mask) {
  return (BOOL)((*mask & 8) && 1);
}

BOOL __GET_CLASS_MASK_IS_CONST__(size_t* mask) {
  return (BOOL)((*mask & 16) && 1);
}

BOOL __GET_CLASS_MASK_IS_INNER__(size_t* mask) {
  return (BOOL)((*mask & 32) && 1);
}

BOOL __GET_CLASS_MASK_IS_SUPER__(size_t* mask) {
  return (BOOL)((*mask & 64) && 1);
}

BOOL __GET_CLASS_MASK_IS_TEMPLATE__(size_t* mask) {
  return (BOOL)((*mask & 128) && 1);
}

BOOL __GET_CLASS_MASK_IS_BARE__(size_t* mask) {
  return (BOOL)((*mask & 256) && 1);
}

BOOL __GET_CLASS_MASK_WAS_INIT__(size_t* mask) {
  return (BOOL)((*mask & 512) && 1);
}

void __SET_CLASS_MASK_STATIC__(size_t* mask, BOOL new_type) {
  *mask |= 1;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_HYBRID__(size_t* mask, BOOL new_type) {
  *mask |= 2;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_INHERITS__(size_t* mask, BOOL new_type) {
  *mask |= 4;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_ABSTRACT__(size_t* mask, BOOL new_type) {
  *mask |= 8;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_CONST__(size_t* mask, BOOL new_type) {
  *mask |= 16;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_INNER__(size_t* mask, BOOL new_type) {
  *mask |= 32;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_SUPER__(size_t* mask, BOOL new_type) {
  *mask |= 64;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_TEMPLATE__(size_t* mask, BOOL new_type) {
  *mask |= 128;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_BARE__(size_t* mask, BOOL new_type) {
  *mask |= 256;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_WAS_INIT__(size_t* mask, BOOL new_type) {
  *mask |= 512;
  *mask ^= !new_type;
}
void* __class_init__(__vClassObject__* default_vclass) {
  default_vclass->cls->static_vtable = (__vTable__*)malloc(sizeof(__vTable__));
  default_vclass->vtable = (__vTable__*)malloc(sizeof(__vTable__));
  __vTable_init__(default_vclass->cls->static_vtable, 0, 0);
  __vTable_init__(default_vclass->vtable, 0, 0);
  return default_vclass;
}

void* __class_destroy__(__ClassObject__* class) {
  if (!__GET_CLASS_MASK_WAS_INIT__(&(class->mask))) {
    return NULL;
  }
  size_t index = 0;
  if (__GET_CLASS_MASK_IS_BARE__(&(class->mask))) {
    class->default_vcls->__destroy__(class->default_instance);
  } else {
    __class_destroy_instance__(class->default_instance, class->default_vcls->__destroy__);
  }
  class->__static_destroy__(class->default_instance);
  while (class->vcls && index < class->__vclass_cnt) {
    if (class->vcls[index] != NULL) {
      if (class->vcls[index]->vtable) {
        __vTable_destroy__(class->vcls[index]->vtable);
        free(class->vcls[index]->vtable);
      }
      free(class->vcls[index]);
    }
    index++;
  }
  if (class->default_vcls->vtable) {
    __vTable_destroy__(class->default_vcls->vtable);
    free(class->default_vcls->vtable);
    class->default_vcls->vtable = 0;
  }
  if (class->inherits_from) {
    __InheritanceList_destroy__(class->inherits_from);
    free(class->inherits_from);
    class->inherits_from = 0;
  }
  if (class->vcls) {
    free(class->vcls);
    class->vcls = 0;
  }
  if (class->static_vtable) {
    __vTable_destroy__(class->static_vtable);
    free(class->static_vtable);
    class->static_vtable = 0;
  }
  __SET_CLASS_MASK_WAS_INIT__(&(class->mask), FALSE);
  return NULL;
}

void* __class_init_instance__(__ClassInstance__* instance,
                              __vClassObject__* default_vclass) {
  instance->__meta__ = (__ClassMetaData__*)malloc(sizeof(__ClassMetaData__));
  instance->__meta__->vcls = default_vclass;
  instance->__meta__->vtable = (__vTable__*)malloc(sizeof(__vTable__));
  __vTable_init__(instance->__meta__->vtable, 0, 0);
  return instance;
}

void* __class_destroy_instance__(__ClassInstance__* instance,
                                 generic_function_t destructor) {
  destructor(instance);
  if (instance->__meta__->vtable && \
      !__GET_CLASS_MASK_IS_STATIC__(&instance->__meta__->vcls->cls->mask)) {
    __vTable_destroy__(instance->__meta__->vtable);
    free(instance->__meta__->vtable);
    instance->__meta__->vtable = 0;
    free(instance->__meta__);
    instance->__meta__ = 0;
  };
  return NULL;
}

void __class_inherit_static__(__ClassObject__* class) {
  size_t static_fill[__VCLASS_METHOD_COUNT__ + 1];
  size_t cnt = 0;
  for (size_t i = 0; i < __VCLASS_METHOD_COUNT__; ++i) {
    if (!*(&(class->default_vcls->__init__) + i)) {
      static_fill[cnt++] = 1 + i;
    }
  }
  for (size_t i = cnt; i < __VCLASS_METHOD_COUNT__ + 1; ++i) {
    static_fill[i] = 0;
  }
  for (size_t i = 0; i < class->inherits_from->size && cnt; ++i) {
    size_t shift = 0;
    while (static_fill[shift]) {
      if (*(&(class->inherits_from->list[i].class->default_vcls->__init__) + \
          static_fill[shift] - 1)) {
        *(&(class->default_vcls->__init__) + static_fill[shift] - 1) = \
          *(&(class->inherits_from->list[i].class->default_vcls->__init__) + \
          static_fill[shift] - 1);
        class->default_vcls->method_shift[static_fill[shift] - 1] = class->inherits_from->list[i].adress_shift + \
          class->inherits_from->list[i].class->default_vcls->method_shift[static_fill[shift] - 1];
        static_fill[shift] = static_fill[--cnt];
      } else {
        shift++;
      }
    }
  }
}

void __class_inherit__(__ClassObject__* class) {
  for (size_t i = class->inherits_from->size; i > 0; --i) {
    if (!__GET_CLASS_MASK_IS_BARE__(&(class->inherits_from->list[i - 1].class->mask))) {
      __vTable_join__(class->static_vtable, \
                      class->inherits_from->list[i - 1].class->static_vtable);
      __vTable_join__(class->default_vcls->vtable, \
                      class->inherits_from->list[i - 1].class->default_vcls->vtable);
    }
  }
}

void __class_inherit_instance__(__ClassInstance__* instance) {
  for (size_t i = instance->__meta__->vcls->cls->inherits_from->size; i > 0; --i) {
    if (!__GET_CLASS_MASK_IS_BARE__(&(instance->__meta__->vcls->cls->inherits_from->list[i - 1].class->mask)) && \
        !__GET_CLASS_MASK_IS_STATIC__(&(instance->__meta__->vcls->cls->inherits_from->list[i - 1].class->mask)) && \
        __GET_CLASS_MASK_WAS_INIT__(&(instance->__meta__->vcls->cls->inherits_from->list[i - 1].class->mask))) {
      __vTable_join__(instance->__meta__->vtable, \
                      instance->__meta__->vcls->cls->inherits_from->list[i - 1].class->default_instance->__meta__->vtable);
    }
  }
}

void* __aux_default_delete_instance__(void* ptr) {
  free(ptr);
  return NULL;
}

void* __aux_class_new_wrapper__(__vClassObject__* vcls, size_t size, __ClassInstance__* template_instance) {
  void* ptr = NULL;
  if (vcls->__new__) {
    ptr = vcls->__new__(vcls, size * vcls->cls->instance_size);
  } else {
    ptr = malloc(size * vcls->cls->instance_size);
  }
  if (vcls->__delete__) {
    SCOPE_PUSH(ptr, vcls->__delete__);
  } else {
    SCOPE_PUSH(ptr, __aux_default_delete_instance__);
  }
  if (vcls->__copy__) {
    for (size_t i = 0; i < size; ++i) {
      vcls->__copy__(ptr + i * vcls->cls->instance_size, template_instance);
    }
  } else if (vcls->__assign__) {
    for (size_t i = 0; i < size; ++i) {
      vcls->__init__(ptr + i * vcls->cls->instance_size, 0);
      vcls->__assign__(ptr + i * vcls->cls->instance_size, template_instance);
    }
  } else {
    for (size_t i = 0; i < size; ++i) {
      memcpy(ptr + i * vcls->cls->instance_size, template_instance, vcls->cls->instance_size);
      SCOPE_PUSH(ptr + i * vcls->cls->instance_size, vcls->cls->__static_destroy__);
    }
  }
  return ptr;
}

void* __aux_class_new_vclass_check_vclass__(void* vclass, size_t vclass_size) {
  for (size_t i = 0; i < vclass_size / sizeof(size_t); ++i) {
    if (((size_t*)vclass)[i]) {
      return vclass;
    }
  }
  return NULL;
}

void* __aux_class_new_vclass_reserve__(__ClassObject__* class) {
  if (!class->vcls) {
    class->vcls = calloc(DEFAULT_VCLASS_LIST_SIZE, sizeof(void*));
    class->__vclass_cnt = 0;
    class->__vclass_capacity = DEFAULT_VCLASS_LIST_SIZE;
    return class;
  }
  __vClassObject__** tmp_vcls = class->vcls;
  class->__vclass_capacity *= 2;
  class->vcls = calloc(class->__vclass_capacity, sizeof(void*));
  memcpy(class->vcls, tmp_vcls, class->__vclass_cnt);
  free(tmp_vcls);
  return class;
}

void* __aux_class_new_vclass__(__ClassObject__* class) {
  __vClassObject__* new_vclass = (__vClassObject__*)malloc(class->vclass_size);
  memcpy(new_vclass, class->default_vcls, class->vclass_size);
  if (!class->vcls || (class->__vclass_cnt + 1 == class->__vclass_capacity)) {
    __aux_class_new_vclass_reserve__(class);
  }
  class->vcls[class->__vclass_cnt++] = new_vclass;
  printf("%d\n", 0);
  return new_vclass;
}


const char* __VCLASS_METHOD_UC_NAMES__[] = {
  "INIT",
  "DESTROY",
  "TO_STR",
  "DATA",
  "ITER",
  "NEXT",
  "CALL",
  "GETITEM",
  "LEN",
  "NEG",
  "ADD",
  "IADD",
  "SUB",
  "ISUB",
  "MUL",
  "IMUL",
  "DIV",
  "IDIV",
  "MOD",
  "IMOD",
  "AND",
  "IAND",
  "OR",
  "IOR",
  "XOR",
  "IXOR",
  "NOT",
  "INOT",
  "CONTAINS",
  "SET",
  "GET",
  "COPY",
  "ASSIGN",
  "NEW",
  "DELETE",
  "CMP",
  "LT",
  "GT",
  "EQ",
  "LE",
  "GE",
  "NEQ",
  "POW",
  "CAST",
  "BITAND",
  "BITIAND",
  "BITOR",
  "BITIOR",
  "BITXOR",
  "BITIXOR",
  "BITNOT",
  "BITINOT",
  "INC",
  "DEC",
  "LSH",
  "ILSH",
  "RSH",
  "IRSH",
  "INEG",
  "LISTEN",
  "SHOUT",
  "ID"
};
