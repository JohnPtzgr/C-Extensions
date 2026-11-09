#include "string.h"
#include "stdlib.h"
#include "limits.h"

typedef unsigned char byte_t;

#if __SIZE_MAX__ == 0xffffffffffffffffUL

#if __CHAR_BIT__ == 8

typedef byte_t u8chr_t[1];
typedef byte_t u16chr_t[2];
typedef byte_t u32chr_t[4];

typedef union {
  struct {
    size_t type:2;
    size_t size:62;
    size_t meta:2;
    size_t capacity:62;
    byte_t* bytearray;
    void* mapping;
  } normal_kind;
  struct {
    byte_t type:2;
    byte_t overlong:1;
    byte_t size:5;
    byte_t string[31];
  } sso_kind;
  union {
    struct {
      byte_t type:2;
      byte_t meta:6;
      byte_t data[31];
    } template;
    struct {
      size_t type:2;
      size_t size:62;
      size_t overlong:1;
      size_t special:1;
      size_t capacity:62;
      u8chr_t* data;
      void* mapping;
    } utf8;
    struct {
      size_t type:2;
      size_t size:62;
      size_t endianness:1; // 0 - LE, 1 - BE
      size_t special:1;
      size_t capacity:62;
      u16chr_t* data;
      void* mapping;
    } utf16;
    struct {
      size_t type:2;
      size_t size:62;
      size_t endianness:1; // 0 - LE, 1 - BE
      size_t special:1;
      size_t capacity:62;
      u32chr_t* data;
      void* mapping;
    } utf32;
  } generic_kind;
};
#elif __CHAR_BIT__ == 16

//WIP

#elif __CHAR_BIT__ == 32

//WIP

#elif __CHAR_BIT__ == 64

//WIP

#endif

#elif __SIZE_MAX__ == 0xffffffffUL
#endif


