#include "classes.h"

CLASS_END(DefaultObject, 0,
) DEFAULT_DESTROY

BOOL __GET_CLASS_MASK_IS_DYNAMIC(size_t* mask) {
  return (BOOL)((*mask & 1) && 1);
}

BOOL __GET_CLASS_MASK_IS_HYBRID(size_t* mask) {
  return (BOOL)((*mask & 2) && 1);
}

BOOL __GET_CLASS_MASK_INHERITS(size_t* mask) {
  return (BOOL)((*mask & 4) && 1);
}

BOOL __GET_CLASS_MASK_IS_ABSTRACT(size_t* mask) {
  return (BOOL)((*mask & 8) && 1);
}

BOOL __GET_CLASS_MASK_IS_CONST(size_t* mask) {
  return (BOOL)((*mask & 16) && 1);
}

BOOL __GET_CLASS_MASK_WAS_INIT(size_t* mask) {
  return (BOOL)((*mask & 32) && 1);
}

BOOL __GET_CLASS_MASK_IS_INNER(size_t* mask) {
  return (BOOL)((*mask & 64) && 1);
}

BOOL __GET_CLASS_MASK_IS_SUPER(size_t* mask) {
  return (BOOL)((*mask & 128) && 1);
}

BOOL __GET_CLASS_MASK_IS_TEMPLATE(size_t* mask) {
  return (BOOL)((*mask & 256) && 1);
}

BOOL __GET_CLASS_MASK_IS_BARE(size_t* mask) {
  return (BOOL)((*mask & 512) && 1);
}

unsigned int __GET_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  return (*mask) >> (__CHAR_BIT__ * sizeof(int));
}

void __SET_CLASS_MASK_DYNAMIC(size_t* mask, BOOL new_type) {
  *mask |= 1;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_HYBRID(size_t* mask, BOOL new_type) {
  *mask |= 2;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_INHERITS(size_t* mask, BOOL new_type) {
  *mask |= 4;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_ABSTRACT(size_t* mask, BOOL new_type) {
  *mask |= 8;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_CONST(size_t* mask, BOOL new_type) {
  *mask |= 16;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_WAS_INIT(size_t* mask, BOOL new_type) {
  *mask |= 32;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_INNER(size_t* mask, BOOL new_type) {
  *mask |= 64;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_SUPER(size_t* mask, BOOL new_type) {
  *mask |= 128;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_TEMPLATE(size_t* mask, BOOL new_type) {
  *mask |= 256;
  *mask ^= !new_type;
}

void __SET_CLASS_MASK_BARE(size_t* mask, BOOL new_type) {
  *mask |= 512;
  *mask ^= !new_type;
}

size_t __ADD_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  unsigned int cnt = (*mask) >> (__CHAR_BIT__ * sizeof(int));
  if (cnt + 1 != 0) {
    cnt++;
  }
  *mask &= (1ull << (__CHAR_BIT__ * sizeof(int))) - 1;
  *mask += ((size_t)cnt) << (__CHAR_BIT__ * sizeof(int));
  return cnt;
}

size_t __SUB_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  unsigned int cnt = (*mask) >> (__CHAR_BIT__ * sizeof(int));
  if (cnt != 0) {
    cnt--;
  }
  *mask &= (1ull << (__CHAR_BIT__ * sizeof(int))) - 1;
  *mask += ((size_t)cnt) << (__CHAR_BIT__ * sizeof(int));
  return cnt;
}

char* __BUILT_IN_METHOD_TABLE__[__BUILT_IN_METHOD_TABLE_SIZE__] = {
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
  "CMP",
  "SET",
  "GET",
  "COPY",
  "ASSIGN",
  "NEW",
  "LT",
  "GT",
  "EQ",
  "LE",
  "GE",
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
  "INEG"
};
