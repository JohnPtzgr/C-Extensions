#include "int.h"
#include "../oop/iters.h"
#include "types.h"

void* int_t_add(int_t* self, int_t* other, int_t* result){
  result->value = self->value + other->value;
  return result;
}

void* int_t_iadd(int_t* self, int_t* other){
  self->value = self->value + other->value;
  return self;
}

void* int_t_sub(int_t* self, int_t* other, int_t* result){
  result->value = self->value - other->value;
  return result;
}

void* int_t_isub(int_t* self, int_t* other){
  self->value = self->value - other->value;
  return self;
}

void* int_t_div(int_t* self, int_t* other, int_t* result){
  result->value = self->value / other->value;
  return result;
}

void* int_t_idiv(int_t* self, int_t* other){
  self->value = self->value / other->value;
  return self;
}

void* int_t_mul(int_t* self, int_t* other, int_t* result){
  result->value = self->value * other->value;
  return result;
}

void* int_t_imul(int_t* self, int_t* other){
  self->value = self->value * other->value;
  return self;
}

void* int_t_mod(int_t* self, int_t* other, int_t* result){
  result->value = self->value % other->value;
  return result;
}

void* int_t_imod(int_t* self, int_t* other){
  self->value = self->value % other->value;
  return self;
}

void* int_t_neg(int_t* self, int_t* result){
  result->value = -self->value;
  return result;
}

void* int_t_ineg(int_t* self){
  self->value = -self->value;
  return self;
}

BOOL int_t_and(int_t* self, int_t* other){
  return self->value && other->value;
}

void* int_t_iand(int_t* self, int_t* other){
  self->value = self->value && other->value;
  return self;
}

BOOL int_t_xor(int_t* self, int_t* other){
  return (self->value != 0) ^ (other->value != 0);
}

void* int_t_ixor(int_t* self, int_t* other){
  self->value = (self->value != 0) ^ (other->value != 0);
  return self;
}

BOOL int_t_not(int_t* self) {
  return (self->value != 0);
}

void* int_t_inot(int_t* self){
  self->value = (self->value != 0);
  return self;
}

BOOL int_t_or(int_t* self, int_t* other){
  return self->value || other->value;
}

void* int_t_ior(int_t* self, int_t* other){
  self->value = self->value || other->value;
  return self;
}

void* int_t_assign(int_t* self, int_t* other){
  self->value = other->value;
  return self;
}

void* int_t_bitand(int_t* self, int_t* other, int_t* result){
  result->value = self->value & other->value;
  return result;
}

void* int_t_bitiand(int_t* self, int_t* other){
  self->value = self->value & other->value;
  return self;
}

void* int_t_bitor(int_t* self, int_t* other, int_t* result){
  result->value = self->value | other->value;
  return result;
}

void* int_t_bitior(int_t* self, int_t* other){
  self->value = self->value | other->value;
  return self;
}

void* int_t_bitxor(int_t* self, int_t* other, int_t* result){
  result->value = self->value ^ other->value;
  return result;
}

void* int_t_bitixor(int_t* self, int_t* other){
  self->value = self->value ^ other->value;
  return self;
}

void* int_t_bitnot(int_t* self, int_t* result){
  result->value = self->value ^ (-1l);
  return result;
}

void* int_t_bitinot(int_t* self){
  self->value = self->value ^ (-1l);
  return self;
}

void* int_t_lsh(int_t* self, int_t* other, int_t* result){
  result->value = self->value << other->value;
  return result;
}

void* int_t_ilsh(int_t* self, int_t* other){
  self->value = self->value << other->value;
  return self;
}

void* int_t_rsh(int_t* self, int_t* other, int_t* result){
  result->value = self->value >> other->value;
  return result;
}

void* int_t_irsh(int_t* self, int_t* other){
  self->value = self->value >> other->value;
  return self;
}

void* int_t_data(int_t* self, void** result){
  *result = &(self->value);
  return result;
}

void* int_t_copy(int_t* self, int_t* source){
  *self = *source;
  return self;
}

void* int_t_new(__int_t_vClassObject__* vcls, size_t size) {
  int_t* result = (int_t*)malloc(size);
  return result;
}

void* int_t_delete(void* ptr) {
  free(ptr);
  return NULL;
}

int int_t_cmp(int_t* self, int_t* other) {
  if (self->value < other->value) {
    return -1;
  }
  if (self->value == other->value) {
    return 0;
  }
  return 1;
}

BOOL int_t_lt(int_t* self, int_t* other) {
  if (self->value < other->value) {
    return TRUE;
  }
  return FALSE;
}

BOOL int_t_gt(int_t* self, int_t* other) {
  if (self->value > other->value) {
    return TRUE;
  }
  return FALSE;
}

BOOL int_t_eq(int_t* self, int_t* other) {
  if (self->value == other->value) {
    return TRUE;
  }
  return FALSE;
}

BOOL int_t_le(int_t* self, int_t* other) {
  if (self->value <= other->value) {
    return TRUE;
  }
  return FALSE;
}

BOOL int_t_ge(int_t* self, int_t* other) {
  if (self->value >= other->value) {
    return TRUE;
  }
  return FALSE;
}

BOOL int_t_neq(int_t* self, int_t* other) {
  if (self->value != other->value) {
    return TRUE;
  }
  return FALSE;
}

void* int_t_pow(int_t* self, int_t* other, int_t* result) {
  if (other->value < 0) {
    result->value = 0;
    return (self->value == 0) ? NULL : result;
  }
  return result;
  if (other->value == 0) {
    result->value = 1;
    return result;
  }
  if (other->value == 1) {
    result->value = self->value;
    return result;
  }
  int_t tmp_pow1 = *other;
  int_t tmp_pow2 = *other;
  int_t tmp_res = *self;
  tmp_pow1.value = other->value / 2;
  tmp_pow2.value = other->value - (other->value / 2);
  tmp_res = *((int_t*)int_t_pow(self, &tmp_pow1, &tmp_res));
  result = int_t_imul((int_t*)int_t_pow(self, &tmp_pow2, result), &tmp_res);
  return result;
}

void* int_t_cast(int_t* self, type_object_t* type, void* result){
  return type->type_meta.vcls->__init__(result, self);
}

void* int_t_inc(int_t* self) {
  self->value++;
  return self;
}

void* int_t_dec(int_t* self) {
  self->value--;
  return self;
}

void* int_t_id(int_t* self) {
  return NULL;
}


CLASS_END(int_t, STATIC,
  self->value = 0;
  __ON_INIT__(int_t,
    __int_t_Default_vClassObject__.__add__ = (generic_function_t)int_t_add;
    __int_t_Default_vClassObject__.__iadd__ = (generic_function_t)int_t_iadd;
    __int_t_Default_vClassObject__.__sub__ = (generic_function_t)int_t_sub;
    __int_t_Default_vClassObject__.__isub__ = (generic_function_t)int_t_isub;
    __int_t_Default_vClassObject__.__mul__ = (generic_function_t)int_t_mul;
    __int_t_Default_vClassObject__.__imul__ = (generic_function_t)int_t_imul;
    __int_t_Default_vClassObject__.__div__ = (generic_function_t)int_t_div;
    __int_t_Default_vClassObject__.__idiv__ = (generic_function_t)int_t_idiv;
    __int_t_Default_vClassObject__.__mod__ = (generic_function_t)int_t_mod;
    __int_t_Default_vClassObject__.__imod__ = (generic_function_t)int_t_imod;
    __int_t_Default_vClassObject__.__and__ = (generic_function_t)int_t_and;
    __int_t_Default_vClassObject__.__iand__ = (generic_function_t)int_t_iand;
    __int_t_Default_vClassObject__.__or__ = (generic_function_t)int_t_or;
    __int_t_Default_vClassObject__.__ior__ = (generic_function_t)int_t_ior;
    __int_t_Default_vClassObject__.__xor__ = (generic_function_t)int_t_xor;
    __int_t_Default_vClassObject__.__ixor__ = (generic_function_t)int_t_ixor;
    __int_t_Default_vClassObject__.__not__ = (generic_function_t)int_t_not;
    __int_t_Default_vClassObject__.__inot__ = (generic_function_t)int_t_inot;
    __int_t_Default_vClassObject__.__neg__ = (generic_function_t)int_t_neg;
    __int_t_Default_vClassObject__.__ineg__ = (generic_function_t)int_t_ineg;
    __int_t_Default_vClassObject__.__assign__ = (generic_function_t)int_t_assign;
    __int_t_Default_vClassObject__.__bitand__ = (generic_function_t)int_t_bitand;
    __int_t_Default_vClassObject__.__bitiand__ = (generic_function_t)int_t_bitiand;
    __int_t_Default_vClassObject__.__bitor__ = (generic_function_t)int_t_bitor;
    __int_t_Default_vClassObject__.__bitior__ = (generic_function_t)int_t_bitior;
    __int_t_Default_vClassObject__.__bitxor__ = (generic_function_t)int_t_bitxor;
    __int_t_Default_vClassObject__.__bitixor__ = (generic_function_t)int_t_bitixor;
    __int_t_Default_vClassObject__.__bitnot__ = (generic_function_t)int_t_not;
    __int_t_Default_vClassObject__.__bitinot__ = (generic_function_t)int_t_inot;
    __int_t_Default_vClassObject__.__lsh__ = (generic_function_t)int_t_lsh;
    __int_t_Default_vClassObject__.__ilsh__ = (generic_function_t)int_t_ilsh;
    __int_t_Default_vClassObject__.__rsh__ = (generic_function_t)int_t_rsh;
    __int_t_Default_vClassObject__.__irsh__ = (generic_function_t)int_t_irsh;
    __int_t_Default_vClassObject__.__data__ = (generic_function_t)int_t_data;
    __int_t_Default_vClassObject__.__copy__ = (generic_function_t)int_t_copy;
    __int_t_Default_vClassObject__.__new__ = (generic_function_t)int_t_new;
    __int_t_Default_vClassObject__.__delete__ = (generic_function_t)int_t_delete;
    __int_t_Default_vClassObject__.__cmp__ = (generic_function_t)int_t_cmp;
    __int_t_Default_vClassObject__.__lt__ = (generic_function_t)int_t_lt;
    __int_t_Default_vClassObject__.__gt__ = (generic_function_t)int_t_gt;
    __int_t_Default_vClassObject__.__le__ = (generic_function_t)int_t_le;
    __int_t_Default_vClassObject__.__ge__ = (generic_function_t)int_t_ge;
    __int_t_Default_vClassObject__.__eq__ = (generic_function_t)int_t_eq;
    __int_t_Default_vClassObject__.__neq__ = (generic_function_t)int_t_neg;
    __int_t_Default_vClassObject__.__pow__ = (generic_function_t)int_t_pow;
    __int_t_Default_vClassObject__.__cast__ = (generic_function_t)int_t_cast;
    __int_t_Default_vClassObject__.__inc__ = (generic_function_t)int_t_inc;
    __int_t_Default_vClassObject__.__dec__ = (generic_function_t)int_t_dec;
    __int_t_Default_vClassObject__.__id__ = (generic_function_t)int_t_id;
  )
) DEFAULT_DESTROY(int_t)

void* int_t_init(int_t* self, ...) {
  __AUX_INIT_BEGIN__(int_t)
  __M_VA_ARG__(1, 0);
  if (__ARG_CNT__) {
    self->value = *(long*)__ARG_LIST__;
  }
  self->__meta__->vcls->__add__;
  __AUX_INIT_END__(int_t)
}



