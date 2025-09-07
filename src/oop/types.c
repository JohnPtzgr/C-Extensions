#include "types.h"


CLASS_END(type_object_t, STATIC | BARE,)
DEFAULT_DESTROY(type_object_t);

void* type_object_t_init(type_object_t* self, ...) {
  __AUX_INIT_BEGIN__(type_object_t)
  __M_VA_ARG__(3, NULL, NULL, NULL)
  __ClassMetaData__* meta = __ARG_LIST__[2];
  self->type_name = (const char*)__ARG_LIST__[0];
  self->type_size = *((size_t*)&(__ARG_LIST__[1]));
  self->type_meta = (__ClassMetaData__){};
  if (meta) {
    self->type_meta = *meta;
  }
  __AUX_INIT_END__(type_object_t)
}


CLASS_END(var_object_t, STATIC | BARE,)
DEFAULT_DESTROY(var_object_t);

void* __aux_default_type_init__(void* self, ...) {
  return self;
}

void* var_object_t_init(var_object_t* self, ...) {
  __AUX_INIT_BEGIN__(var_object_t)
  __M_VA_ARG__(3, NULL, NULL, NULL)
  self->type = (type_object_t*)__ARG_LIST__[0];
  self->value = __ARG_LIST__[1];
  __AUX_INIT_END__(var_object_t)
}
