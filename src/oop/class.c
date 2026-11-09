#include "class.h"

typedef struct __vTableProbeId__
{
  size_t id;
  size_t pow;
} __vTableProbeId__;

static inline size_t defaultVTableHasher(const char* key, char id) {

  size_t lookup_primes[16] = {
    428565993458070227llu,
    254122516461927209llu,
    532695996088977289llu,
    313290182662825307llu,
    860946449948972521llu,
    319264523107532111llu,
    202986391655519623llu,
    275182499288387473llu,
    962987202532100107llu,
    733765330246036859llu,
    147307587625942813llu,
    613405566694294111llu,
    769693398094706011llu,
    398091924081499261llu,
    727872227099913139llu,
    400052032524586027llu
  };
  size_t hash = (size_t)(defaultVTableHasher);

  while (*key)
  {
    hash += lookup_primes[(*(key) + id) & 15] ^ *((unsigned char*)key);
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
  {
    TRY {
      table->data = (__vTableNode__*)calloc(new_size, sizeof(__vTableNode__));
    } CATCH(errexc) {
      table->data = tmp_data;
      THROW(size_t);
    }
  }
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
  {
    TRY {
      free(tmp_data);
    } CATCH(errexc) {
      free(table->data);
      table->data = tmp_data;
      THROW(size_t);
    }
  }
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

void* __InheritanceList_reserve__(__InheritanceList__* list, size_t new_capacity) {
  __InheritanceListNode__* tmp_list = (list->list ? list->list : list->static_list);
  list->list = (__InheritanceListNode__*)malloc(new_capacity * sizeof(__InheritanceListNode__));
  EXCTH_ASSERT(void*, list->list);
  if (list->capacity) {
    memcpy(list->list, tmp_list, list->capacity * sizeof(__InheritanceListNode__));
    if (tmp_list != list->static_list) {
      TRY {
        free(tmp_list);
      } CATCH(errexc) {
        free(list->list); errctx = EXCEPTION_CTX_LTR;
        list->list = tmp_list;
        THROW(void*);
      }
    }
  }
  list->capacity = new_capacity;
  return list;
}

void* __InheritanceList_init__(__InheritanceList__* list, __InheritanceListNode__* default_nodes) {
  list->size = 0;
  list->capacity = 0;
  if (!default_nodes) {
    list->list = 0;
    __InheritanceList_reserve__(list, __DEFAULT_INHERITANCE_LIST_CAPACITY__);
  } else {
    list->list = default_nodes;
    list->static_list = default_nodes;
    list->capacity = __STATIC_INHERITANCE_LIST_NODES__;
  }
  PUSH_EXCEPTION(void*);
  return list;
}

void* __InheritanceList_destroy__(__InheritanceList__* list) {
  if (list->list != list->static_list) {
    TRY {
      free(list->list);
    } CATCH(errexc) {
      THROW(void*);
    }
  }
  *list = (__InheritanceList__){};
  return NULL;
}

void* __InheritanceList_add__(__InheritanceList__* list,
                              void* self,
                              void* instance,
                              __ClassObject__* cls) {
  if (list->size + 1 == list->capacity) {
    __InheritanceList_reserve__(list, 2 * list->capacity);
    PUSH_EXCEPTION(void*);
  }
  list->list[list->size].adress_shift = (size_t)(instance - self);
  list->list[list->size].cls = cls;
  list->size++;
  __SET_CLASS_MASK_SUPER__(&cls->mask, TRUE); \
  return list;
}

void* __InheritanceList_remove__(__InheritanceList__* list, __ClassInstance__* instance) {
  size_t i = 0;
  while ((i < list->size) && (list->list[i].cls != instance->__meta__->cls)) { ++i; }
  
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
    if (__vTable_check__(*(__vTable__**)((void*)list->list[i].cls->default_vcls + \
                                list->list[i].cls->vclass_size - \
                                sizeof(void*)), hash)) {
      return i;
    }
    i++;
  }
  return (size_t)INVALID;
}

size_t __InheritanceList_find_built_in__(__InheritanceList__* list, __m_enum__ built_in_no) {
  size_t i = 0;
  while (i < list->size) {
    if (*(&(list->list[i].cls->default_vcls->__init__) + \
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

BOOL __GET_CLASS_MASK_IS_FUNDAMENTAL__(size_t* mask) {
  return (BOOL)((*mask & 2) && 1);
}

BOOL __GET_CLASS_MASK_DERIVED__(size_t* mask) {
  return (BOOL)((*mask & 4) && 1);
}

BOOL __GET_CLASS_MASK_IS_ABSTRACT__(size_t* mask) {
  return (BOOL)((*mask & 8) && 1);
}

BOOL __GET_CLASS_MASK_IS_CONST__(size_t* mask) {
  return (BOOL)((*mask & 16) && 1);
}

BOOL __GET_CLASS_MASK_IS_CUSTOM__(size_t* mask) {
  return (BOOL)((*mask & 32) && 1);
}

BOOL __GET_CLASS_MASK_IS_SUPER__(size_t* mask) {
  return (BOOL)((*mask & 64) && 1);
}

BOOL __GET_CLASS_MASK_IS_BRIDGE__(size_t* mask) {
  return (BOOL)((*mask & 128) && 1);
}

BOOL __GET_CLASS_MASK_IS_BARE__(size_t* mask) {
  return (BOOL)((*mask & 256) && 1);
}

BOOL __GET_CLASS_MASK_IS_ILLDEFINED__(size_t* mask) {
  return (BOOL)((*mask & 512) && 1);
}

BOOL __GET_CLASS_MASK_WAS_INIT__(size_t* mask) {
  return (BOOL)((*mask & 1024) && 1);
}

BOOL __GET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask) {
  return (BOOL)((*mask & 2048) && 1);
}

void __SET_CLASS_MASK_STATIC__(size_t* mask, BOOL new_type) {
  *mask |= 1;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_FUNDAMENTAL__(size_t* mask, BOOL new_type) {
  *mask |= 2;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_DERIVED__(size_t* mask, BOOL new_type) {
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

void __SET_CLASS_MASK_CUSTOM__(size_t* mask, BOOL new_type) {
  *mask |= 32;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_SUPER__(size_t* mask, BOOL new_type) {
  *mask |= 64;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_BRIDGE__(size_t* mask, BOOL new_type) {
  *mask |= 128;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_BARE__(size_t* mask, BOOL new_type) {
  *mask |= 256;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_ILLDEFINED__(size_t* mask, BOOL new_type) {
  *mask |= 512;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_WAS_INIT__(size_t* mask, BOOL new_type) {
  *mask |= 1024;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask, BOOL new_type) {
  *mask |= 2048;
  *mask ^= !new_type;
}



__ClassObject__ __DefaultBase_ClassObject__ = \
    (__ClassObject__){.mask=BARE|STATIC|ABSTRACT|FUNDAMENTAL|SUPER,
                      .instance_size=sizeof(__ClassInstance__),
                      .vclass_size=sizeof(__vClassObject__),
                      .default_vcls=(__vClassObject__*)&__DefaultBase_Default_vClassObject__,
                      .default_instance=(__ClassInstance__*)&__DefaultBase_Default_Instance__,
                      .name="DefaultBase",
                      ._f_class_size=sizeof(__FundamentalVClass__),
                      .__vcls_cls__=&__DefaultBase_Default_vClassObject__.cls,
                      .vclass_meta_size=sizeof(struct __vClassObjectMeta__),
                      .__static_init__=(generic_function_t)__DefaultBase_static_init__,
                      .__static_destroy__=(generic_function_t)__DefaultBase_static_destroy__,
                      .fields=&(class_structure_t){(class_field_t[]){ \
                        __AUX_CLASS_FIELD__(__ClassInstance__, \
                                            __meta__, \
                                            &(type_object_t){.type_name="__vClassObject__", \
                                            .type_size=sizeof(__vClassObject__)}), \
                        (class_field_t){} \
                      }}, \
                      .static_fields=&(class_structure_t){(class_field_t[]){ \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __init__, \
                                            &(type_object_t){.type_name="generic_function_t", \
                                            .type_size=sizeof(generic_function_t)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __destroy__, \
                                            &(type_object_t){.type_name="generic_function_t", \
                                            .type_size=sizeof(generic_function_t)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __cast__, \
                                            &(type_object_t){.type_name="generic_function_t", \
                                            .type_size=sizeof(generic_function_t)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __copy__, \
                                            &(type_object_t){.type_name="generic_function_t", \
                                            .type_size=sizeof(generic_function_t)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __assign__, \
                                            &(type_object_t){.type_name="generic_function_t", \
                                            .type_size=sizeof(generic_function_t)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __move__, \
                                            &(type_object_t){.type_name="generic_function_t", \
                                            .type_size=sizeof(generic_function_t)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            _f, \
                                            &(type_object_t){.type_name="__FundamentalVClass__", \
                                            .type_size=sizeof(__FundamentalVClass__)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __method_shift__, \
                                            &(type_object_t){.type_name="unsigned int*", \
                                            .type_size=sizeof(unsigned int*)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            cls, \
                                            &(type_object_t){.type_name="__ClassObject__*", \
                                            .type_size=sizeof(__ClassObject__*)}), \
                        __AUX_CLASS_FIELD__(__vClassObject__, \
                                            __meta__, \
                                            &(type_object_t){.type_name="__vClassObjectMeta__", \
                                            .type_size=sizeof(struct __vClassObjectMeta__)}), \
                        (class_field_t){} \
                      }}
                     };
type_object_t __DefaultBase_type__ = (type_object_t){.type_mask=BARE|STATIC|ABSTRACT,
                                                     .type_meta=(__ClassMetaObject__*)&__DefaultBase_Default_vClassObject__,
                                                     .type_name="__ClassInstance__",
                                                     .type_size=sizeof(__ClassInstance__)};
type_object_t* DefaultBase_type = &__DefaultBase_type__;
__vClassObject__ __DefaultBase_Default_vClassObject__ = (__vClassObject__){.cls=&__DefaultBase_ClassObject__,
                                                                           .__init__=(generic_function_t)__DefaultBase_static_init__,
                                                                           .__destroy__=(generic_function_t)__DefaultBase_static_destroy__};
__ClassInstance__ __DefaultBase_Default_Instance__ = (__ClassInstance__){};

void* __DefaultBase_static_init__(__AUX_CLASS_VARSTRUCT__(DefaultBase)* self) {
  return self;
}

void* __DefaultBase_static_destroy__(__AUX_CLASS_VARSTRUCT__(DefaultBase)* self) {
  return NULL;
}


void* __class_init__(__ClassObject__* cls) {
  __vTable__** vtable = (__vTable__**)((void*)cls->default_vcls + \
                                       cls->vclass_size - \
                                       sizeof(void*));
  *vtable = (__vTable__*)malloc(sizeof(__vTable__));
  EXCTH_ASSERT(void*, *vtable);
  TRY {
    __vTable_init__(*vtable, 0, 0);
  } CATCH(errexc) {
    free(*vtable);
    THROW(void*);
  }
  return cls;
}

void* __class_destroy__(__ClassObject__* cls) {
  if (!__GET_CLASS_MASK_WAS_INIT__(&(cls->mask))) {
    return NULL;
  }
  if (cls->__class_object_destroy__) {
    cls->__class_object_destroy__(cls);
  }
  size_t index = 0;
  cls->default_vcls->__destroy__(cls->default_instance);
  PUSH_EXCEPTION(void*);
  cls->__static_destroy__(cls->default_instance);
  while (cls->alloc_vcls && index < cls->__vclass_cnt) {
    if (cls->alloc_vcls[index] != NULL) {
      __vTable__** vtable = (__vTable__**)((void*)cls->alloc_vcls[index] + \
                                           cls->vclass_size - \
                                           sizeof(void*));

      if (*vtable) {
        __vTable_destroy__(*vtable);
        free(*vtable);
      }
      free(cls->alloc_vcls[index]);
      PUSH_EXCEPTION(void*);
    }
    index++;
  }
  __vTable__** vtable = (__vTable__**)((void*)cls->default_vcls + \
                                        cls->vclass_size - \
                                        sizeof(void*));
  if (*vtable) {
    __vTable_destroy__(*vtable);
    free(*vtable);
    *vtable = NULL;
  }
  if (cls->inherits_from) {
    __InheritanceList_destroy__(cls->inherits_from);
    cls->inherits_from = 0;
  }
  if (cls->alloc_vcls) {
    free(cls->alloc_vcls);
    cls->alloc_vcls = 0;
  }
  PUSH_EXCEPTION(void*);
  __SET_CLASS_MASK_WAS_INIT__(&(cls->mask), FALSE);
  return NULL;
}

void __class_inherit_static__(__ClassObject__* cls) {
  size_t static_fill[__VCLASS_METHOD_COUNT__ + 1];
  size_t cnt = 0;
  for (size_t i = 0; i < __VCLASS_METHOD_COUNT__; ++i) {
    if (!*(&(cls->default_vcls->__init__) + i)) {
      static_fill[cnt++] = 1 + i;
    }
  }
  for (size_t i = cnt; i < __VCLASS_METHOD_COUNT__ + 1; ++i) {
    static_fill[i] = 0;
  }
  if (__GET_CLASS_MASK_IS_FUNDAMENTAL__(&cls->mask)) {
    for (size_t i = 0; i < cls->inherits_from->size && cnt; ++i) {
      size_t shift = 0;
      while (static_fill[shift]) {
        if (*(&(cls->inherits_from->list[i].cls->default_vcls->__init__) + \
            static_fill[shift] - 1)) {
          *(&(cls->default_vcls->__init__) + static_fill[shift] - 1) = \
            *(&(cls->inherits_from->list[i].cls->default_vcls->__init__) + \
            static_fill[shift] - 1);
          cls->default_vcls->__method_shift__[static_fill[shift] - 1] = cls->inherits_from->list[i].adress_shift + \
            cls->inherits_from->list[i].cls->default_vcls->__method_shift__[static_fill[shift] - 1];
          static_fill[shift] = static_fill[--cnt];
        } else {
          shift++;
        }
      }
    }
  } else {
    memcpy(&cls->default_vcls->_f,
           &cls->inherits_from->list->cls->default_vcls->_f,
           cls->_f_class_size);
  }
}

void __class_inherit__(__ClassObject__* cls) {
  __vTable__** vtable = (__vTable__**)((void*)cls->default_vcls + \
                                        cls->vclass_size - \
                                        sizeof(void*));
  for (size_t i = cls->inherits_from->size; i > 0; --i) {
    if (!__GET_CLASS_MASK_IS_BARE__(&(cls->inherits_from->list[i - 1].cls->mask))) {
      __vTable__** vtablei = (__vTable__**)((void*)cls->inherits_from->list[i - 1].cls->default_vcls + \
                                            cls->vclass_size - \
                                            sizeof(void*));
      __vTable_join__(*vtable, \
                      *vtablei);
      BREAKPOINT;
    }
  }
}

void* __aux_default_delete_instance__(void* ptr) {
  free(ptr);
  PUSH_EXCEPTION(void*);
  return NULL;
}

void* __aux_class_new_wrapper__(__ClassObject__* cls, size_t size, __ClassInstance__* template_instance) {
  void* ptr = NULL;
  if (__GET_CLASS_MASK_IS_FUNDAMENTAL__(&cls->mask)) {
    ptr = malloc(size * cls->instance_size);
    EXCTH_ASSERT(void*, ptr);
    TRY {
      SCOPE_PUSH(ptr, __aux_default_delete_instance__);
      BREAKPOINT;
      for (size_t i = 0; i < size; ++i) {
        memcpy(ptr + i * cls->instance_size, template_instance, cls->instance_size);
        SCOPE_PUSH(ptr + i * cls->instance_size, cls->__static_destroy__);
        BREAKPOINT;
      }
      BREAKPOINT;
    } CATCH(errexc) {
      free(ptr);
      THROW(void*);
    }
    if (cls->default_vcls->__copy__) {
      for (size_t i = 0; i < size; ++i) {
        cls->default_vcls->__copy__(ptr + i * cls->instance_size, template_instance);
      }
    } else if (cls->default_vcls->__assign__) {
      for (size_t i = 0; i < size; ++i) {
        cls->default_vcls->__init__(ptr + i * cls->instance_size, 0);
        cls->default_vcls->__assign__(ptr + i * cls->instance_size, template_instance);
      }
    } else {
      for (size_t i = 0; i < size; ++i) {
        memcpy(ptr + i * cls->instance_size, template_instance, cls->instance_size);
        SCOPE_PUSH(ptr + i * cls->instance_size, cls->__static_destroy__);
        BREAKPOINT;
      }
    }
  } else {
    __vClassObject__* vcls;
    if (__GET_CLASS_MASK_IS_STATIC__(&cls->mask)) {
      vcls = cls->default_vcls;
    } else {
      vcls = *(__vClassObject__**)((char*)template_instance + cls->instance_size - sizeof(void*));
    }
    if (vcls->_f.__new__) {
      ptr = vcls->_f.__new__(vcls, size * cls->instance_size);
    } else {
      ptr = malloc(size * cls->instance_size);
    }
    EXCTH_ASSERT(void*, ptr);
    TRY {
      if (vcls->_f.__delete__) {
        SCOPE_PUSH(ptr, vcls->_f.__delete__);
      } else {
        SCOPE_PUSH(ptr, __aux_default_delete_instance__);
      }
      BREAKPOINT;
      if (vcls->__copy__) {
        for (size_t i = 0; i < size; ++i) {
          vcls->__copy__(ptr + i * cls->instance_size, template_instance);
        }
      } else if (vcls->__assign__) {
        for (size_t i = 0; i < size; ++i) {
          vcls->__init__(ptr + i * cls->instance_size, 0);
          vcls->__assign__(ptr + i * cls->instance_size, template_instance);
        }
      } else {
        for (size_t i = 0; i < size; ++i) {
          memcpy(ptr + i * cls->instance_size, template_instance, cls->instance_size);
          SCOPE_PUSH(ptr + i * cls->instance_size, cls->__static_destroy__);
          BREAKPOINT;
        }
        BREAKPOINT
      }
    } CATCH(errexc) {
      free(ptr);
      THROW(void*);
    }
  }
    PUSH_EXCEPTION(void*);
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

void* __aux_class_new_vclass_reserve__(__ClassObject__* cls) {
  if (!cls->alloc_vcls) {
    cls->alloc_vcls = calloc(DEFAULT_VCLASS_LIST_SIZE, sizeof(void*));
    cls->__vclass_cnt = 0;
    cls->__vclass_capacity = DEFAULT_VCLASS_LIST_SIZE;
    return cls;
  }
  __vClassObject__** tmp_vcls = cls->alloc_vcls;
  cls->__vclass_capacity *= 2;
  cls->alloc_vcls = calloc(cls->__vclass_capacity, sizeof(void*));
  PUSH_EXCEPTION(void*);
  memcpy(cls->alloc_vcls, tmp_vcls, cls->__vclass_cnt);
  free(tmp_vcls);
  PUSH_EXCEPTION(void*);
  return cls;
}

void* __aux_class_new_vclass__(__ClassObject__* cls) {
  __vClassObject__* new_vclass = (__vClassObject__*)malloc(cls->vclass_size);
  EXCTH_ASSERT(void*, new_vclass);
  memcpy(new_vclass, cls->default_vcls, cls->vclass_size);
  if (!cls->alloc_vcls || (cls->__vclass_cnt + 1 == cls->__vclass_capacity)) {
    TRY {
      __aux_class_new_vclass_reserve__(cls);
    } CATCH(errexc) {
      free(new_vclass);
      THROW(void*);
    }
  }
  cls->alloc_vcls[cls->__vclass_cnt++] = new_vclass;
  return new_vclass;
}

void* __aux_type_cast__(void* expr, type_object_t* src_type, type_object_t* trg_type, void* allocated_memory) {
  void* result = NULL;
  if (src_type && src_type->type_meta) {
    if (trg_type && trg_type->type_meta) {
      if (src_type->type_meta->cls && trg_type->type_meta->cls) {
        return __aux_class_cast__(expr,
                                  src_type->type_meta,
                                  trg_type->type_meta,
                                  allocated_memory);
      }
      if (src_type == trg_type || \
          (strncmp(src_type->type_name,
                    trg_type->type_name,
                    __CLASS_NAME_MAX_LENGTH__) == 0)) {
        return expr;
      }
    }
    if (src_type->type_meta->__cast__) {
      result = src_type->type_meta->__cast__(expr,
                                             src_type,
                                             trg_type,
                                             allocated_memory,
                                             0);
    }
  }
  if (trg_type && !result && trg_type->type_meta->__cast__) {
    result = trg_type->type_meta->__cast__(trg_type->type_meta->__init__(allocated_memory,
                                                                         0),
                                           src_type,
                                           trg_type,
                                           expr,
                                           0);
  }
  return result;
}

void* __aux_class_cast__(void* expr, __ClassMetaObject__* src_class, __ClassMetaObject__* trg_class, void* allocated_memory) {
  void* result = NULL;
  if (src_class) {
    if (trg_class && \
        (src_class == trg_class || \
         (strncmp(src_class->cls->name,
                  trg_class->cls->name,
                  __CLASS_NAME_MAX_LENGTH__) == 0))) {
      return expr;
    }
    if (src_class->cls->mask & DERIVED) {
      __InheritanceList__* list = src_class->cls->inherits_from;
      for (size_t i = 0; i < list->size; ++i) {
        if (strncmp(trg_class->cls->name, list->list->cls->name, __CLASS_NAME_MAX_LENGTH__) == 0) {
          return expr + list->list[i].adress_shift;
        }
      }
    }
    if (src_class->__cast__) {
      result = src_class->__cast__(expr, src_class, trg_class, allocated_memory, 0);
    }
  }
  if (trg_class && !result && trg_class->__cast__) {
    result = trg_class->__cast__(trg_class->__init__(allocated_memory,
                                                     0),
                                 src_class,
                                 trg_class,
                                 expr,
                                 0);
  }
  return result;
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
