# 0 "vector.c"
# 1 "/home/justengineer/dev/extraslib/src/algorithm//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "vector.c"
# 1 "../coop/oop_wrap.h" 1
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 402 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 403 "/usr/include/features.h" 2 3 4
# 510 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 730 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 731 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 732 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 511 "/usr/include/features.h" 2 3 4
# 534 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 535 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 214 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4

# 214 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 329 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 56 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 121 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
# 57 "/usr/include/stdlib.h" 2 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 98 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;



extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 177 "/usr/include/stdlib.h" 3 4
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 505 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
# 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 30 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
# 59 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 97 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;




# 1 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 1 3 4






typedef __clock_t clock_t;
# 127 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 1 3 4






typedef __clockid_t clockid_t;
# 129 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 3 4
typedef __time_t time_t;
# 130 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 1 3 4






typedef __timer_t timer_t;
# 131 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 144 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 145 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;




# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 156 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
# 176 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 24 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endianness.h" 1 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/endian.h" 2 3 4
# 25 "/usr/include/endian.h" 2 3 4
# 35 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{

  return __builtin_bswap16 (__bsx);



}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{

  return __builtin_bswap32 (__bsx);



}
# 69 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{

  return __builtin_bswap64 (__bsx);



}
# 36 "/usr/include/endian.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 1 3 4
# 32 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 3 4
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
# 37 "/usr/include/endian.h" 2 3 4
# 177 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 1 3 4




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 5 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 2 3 4


typedef __sigset_t sigset_t;
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 1 3 4







struct timeval
{




  __time_t tv_sec;
  __suseconds_t tv_usec;

};
# 38 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
struct timespec
{



  __time_t tv_sec;




  __syscall_slong_t tv_nsec;
# 31 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
};
# 40 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 59 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 91 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 102 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 127 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 153 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 180 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 227 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 1 3 4
# 44 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 2 3 4
# 45 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 3 4
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
# 47 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
# 76 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;



  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
# 53 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
};
# 77 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4
# 89 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;


  unsigned int __flags;
# 55 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
};
# 90 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4




struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
  int __data ;
} __once_flag;
# 24 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 228 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 515 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));



extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern __uint32_t arc4random (void)
     __attribute__ ((__nothrow__ , __leaf__)) ;


extern void arc4random_buf (void *__buf, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     __attribute__ ((__nothrow__ , __leaf__)) ;




extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;






extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));


extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));


extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));



# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 707 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 786 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 814 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 827 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 849 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 870 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 923 "/usr/include/stdlib.h" 3 4
extern int system (const char *__command) ;
# 940 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 960 "/usr/include/stdlib.h" 3 4
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 980 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
# 1012 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));





extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));






extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 1099 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 1145 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 1155 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 1156 "/usr/include/stdlib.h" 2 3 4
# 1167 "/usr/include/stdlib.h" 3 4

# 2 "../coop/oop_wrap.h" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 28 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 29 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 38 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 1 3 4




# 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 2 3 4




typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 41 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 42 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 43 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4



struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 44 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  struct _IO_FILE **_prevchain;
  int _mode;

  char _unused2[15 * sizeof (int) - 5 * sizeof (void *)];
};
# 45 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h" 3 4
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);







typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);







typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);


typedef int cookie_close_function_t (void *__cookie);






typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
# 48 "/usr/include/stdio.h" 2 3 4





typedef __gnuc_va_list va_list;
# 85 "/usr/include/stdio.h" 3 4
typedef __fpos_t fpos_t;
# 129 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 130 "/usr/include/stdio.h" 2 3 4
# 149 "/usr/include/stdio.h" 3 4
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
# 184 "/usr/include/stdio.h" 3 4
extern int fclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 194 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 211 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;




extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 228 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));






extern int fflush (FILE *__stream);
# 245 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 264 "/usr/include/stdio.h" 3 4
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));
# 299 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;





extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 334 "/usr/include/stdio.h" 3 4
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__nonnull__ (1)));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nonnull__ (1)));




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));





extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;




extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) __attribute__ ((__nonnull__ (1)));




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 463 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                                __attribute__ ((__nonnull__ (1)));
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 490 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 540 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) __attribute__ ((__nonnull__ (1)));
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 575 "/usr/include/stdio.h" 3 4
extern int fgetc (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getc (FILE *__stream) __attribute__ ((__nonnull__ (1)));





extern int getchar (void);






extern int getc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
extern int getchar_unlocked (void);
# 600 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 611 "/usr/include/stdio.h" 3 4
extern int fputc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));





extern int putchar (int __c);
# 627 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));







extern int putc_unlocked (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream) __attribute__ ((__nonnull__ (1)));


extern int putw (int __w, FILE *__stream) __attribute__ ((__nonnull__ (2)));







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2))) __attribute__ ((__nonnull__ (3)));
# 689 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) __attribute__ ((__nonnull__ (4)));


extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __attribute__ ((__nonnull__ (3)));







extern int fputs (const char *__restrict __s, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (2)));





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream) __attribute__ ((__nonnull__ (2)));






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) __attribute__ ((__nonnull__ (4)));
# 756 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream)
  __attribute__ ((__nonnull__ (4)));







extern int fseek (FILE *__stream, long int __off, int __whence)
  __attribute__ ((__nonnull__ (1)));




extern long int ftell (FILE *__stream) __attribute__ ((__nonnull__ (1)));




extern void rewind (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 793 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence)
  __attribute__ ((__nonnull__ (1)));




extern __off_t ftello (FILE *__stream) __attribute__ ((__nonnull__ (1)));
# 819 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos)
  __attribute__ ((__nonnull__ (1)));




extern int fsetpos (FILE *__stream, const fpos_t *__pos) __attribute__ ((__nonnull__ (1)));
# 850 "/usr/include/stdio.h" 3 4
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern void perror (const char *__s) __attribute__ ((__cold__));




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 887 "/usr/include/stdio.h" 3 4
extern int pclose (FILE *__stream) __attribute__ ((__nonnull__ (1)));





extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;






extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
# 931 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 949 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 973 "/usr/include/stdio.h" 3 4

# 3 "../coop/oop_wrap.h" 2
# 50 "../coop/oop_wrap.h"

# 50 "../coop/oop_wrap.h"
void* memcpy(void* DEST, const void* SRC, size_t COUNT) {
  for (size_t i = 0; i < COUNT / sizeof(void*); ++i) {
    ((void**)DEST)[i] = ((void**)SRC)[i];
  }
  for (size_t i = (COUNT / sizeof(void*)) * sizeof(void*);
       i < COUNT; ++i) {
    ((char*)DEST)[i] = ((char*)SRC)[i];
  }
  return DEST;
}




typedef enum {
  false,
  true
} BOOL;




typedef void*(*method_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

typedef struct generic_method_t {
  void* obj_instance;
  method_function_t function;
} generic_method_t;

generic_method_t generic_method = {0, 0};

typedef struct class_method_t {
  void* class_instance;
  method_function_t class_function;
} class_method_t;




typedef struct __SCOPE_STACK_t {
  generic_method_t* actions;
  size_t capacity;
  size_t size;
  void* data;
} __SCOPE_STACK_t;



void __SCOPE_STACK_ALLOC(__SCOPE_STACK_t* stack, size_t capacity) {
  if (stack->capacity != 0) {
    free(stack->actions);
  }
  stack->capacity = 8;
  stack->actions = (generic_method_t*)malloc(sizeof(generic_method_t) * stack->capacity);
  stack->data = stack->actions;
}

void __SCOPE_STACK_RESERVE(__SCOPE_STACK_t* stack, size_t capacity) {
  if (stack->capacity >= capacity) {
    stack->size = (stack->size < capacity ? stack->size : capacity);
    return;
  }
  void* actions = stack->actions;
  stack->actions = (generic_method_t*)malloc(sizeof(generic_method_t) * capacity);
  stack->actions = (generic_method_t*)memcpy(stack->actions, actions, stack->size * sizeof(generic_method_t));
  if (stack->capacity != 0) {
    free(actions);
  }
  stack->capacity = capacity;
  stack->data = stack->actions;
}

void __SCOPE_STACK_INIT(__SCOPE_STACK_t* stack) {
  stack->size = 0;
  stack->capacity = 0;
  __SCOPE_STACK_ALLOC(stack, 8);
}

void __SCOPE_STACK_DESTROY(__SCOPE_STACK_t* stack) {
  free(stack->actions);
  stack->actions = 0;
  stack->capacity = 0;
  stack->size = 0;
}

void __SCOPE_STACK_PUSH(__SCOPE_STACK_t* stack, generic_method_t* action) {
  if (action != 0 && stack->actions == 0) {
    return;
  }
  if (action == 0 && stack->actions == 0) {
    __SCOPE_STACK_INIT(stack);
  }
  if (stack->capacity == 0) {
    __SCOPE_STACK_RESERVE(stack, 8);
  }
  if (stack->size + 1 >= stack->capacity) {
    __SCOPE_STACK_RESERVE(stack, stack->capacity * 2);
  }
  if (action != 0) {
    stack->actions[stack->size++] = *action;
  } else {
    stack->actions[stack->size++] = (generic_method_t){0, 0};
  }
}

generic_method_t* __SCOPE_STACK_POP(__SCOPE_STACK_t* stack) {
  if (stack->size == 0) {
    return 0;
  }
  if (stack->size <= stack->capacity / 4) {
    __SCOPE_STACK_RESERVE(stack, stack->capacity / 2);
  }
  generic_method_t* action = &(stack->actions[--stack->size]);
  if (action->function == 0 && action->obj_instance == 0) {
    return 0;
  }
  return action;
}

void* __SCOPE_STACK_TOP(__SCOPE_STACK_t* stack) {
  if (stack->size == 0) {
    return 0;
  }
  generic_method_t* action = &(stack->actions[--stack->size]);
  if (action->function == 0 && action->obj_instance == 0) {
    return 0;
  }
  return action;
}

void __SCOPE_STACK_EXECUTE(generic_method_t* method) {
  method->function(method->obj_instance);
}

void* __SCOPE_STACK_EXECUTE_ALL(__SCOPE_STACK_t* stack) {
  for (size_t i = stack->size; i > 0; --i) {
    printf("STACK ACTION: {%llu, %llu}\n", stack->actions[i - 1].function, stack->actions[i - 1].obj_instance);
    BOOL cmp;
    { size_t i = sizeof(stack->actions[i - 1]); size_t j = sizeof((generic_method_t) {0, 0}); BOOL result = (i == j); if (result) { for (size_t k = 0; k < i; ++k) { if (((char*)(&(stack->actions[i - 1])))[k] != ((char*)(&((generic_method_t) {0, 0})))[k]) { result = 0; break; } } }; cmp = result; };
    if (!cmp) {
      __SCOPE_STACK_EXECUTE(&(stack->actions[i - 1]));
    }
  }
}

__SCOPE_STACK_t __SCOPE_STACK = {0, 0, 0};

void* __SCOPE_STACK_HEAD = 0;
# 234 "../coop/oop_wrap.h"
BOOL __GET_CLASS_MASK_TYPE(size_t* mask) {
  return (*mask & 1) && 1;
}

BOOL __GET_CLASS_MASK_IS_HYBRID(size_t* mask) {
  return (*mask & 2) && 1;
}

BOOL __GET_CLASS_MASK_INHERITS(size_t* mask) {
  return (*mask & 4) && 1;
}

BOOL __GET_CLASS_MASK_IS_ABSTRACT(size_t* mask) {
  return (*mask & 8) && 1;
}

BOOL __GET_CLASS_MASK_IS_CONST(size_t* mask) {
  return (*mask & 16) && 1;
}

BOOL __GET_CLASS_MASK_WAS_INIT(size_t* mask) {
  return (*mask & 32) && 1;
}

BOOL __GET_CLASS_MASK_IS_INNER(size_t* mask) {
  return (*mask & 64) && 1;
}

BOOL __GET_CLASS_MASK_IS_SUPER(size_t* mask) {
  return (*mask & 128) && 1;
}

BOOL __GET_CLASS_MASK_IS_INTERFACE(size_t* mask) {
  return (*mask & 256) && 1;
}

unsigned int __GET_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  return (*mask) >> (8 * sizeof(int));
}

void __SET_CLASS_MASK_TYPE(size_t* mask, BOOL new_type) {
  *mask |= 1;
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

void __SET_CLASS_MASK_INTERFACE(size_t* mask, BOOL new_type) {
  *mask |= 256;
  *mask ^= !new_type;
}

void __ADD_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  unsigned int cnt = (*mask) >> (8 * sizeof(int));
  if (cnt + 1 != 0) {
    cnt++;
  }
  *mask &= (1ull << (8 * sizeof(int))) - 1;
  *mask += cnt;
}

void __SUB_CLASS_MASK_COUNT_INSTANCES(size_t* mask) {
  unsigned int cnt = (*mask) >> (8 * sizeof(int));
  if (cnt != 0) {
    cnt--;
  }
  *mask &= (1ull << (8 * sizeof(int))) - 1;
  *mask += cnt;
}
# 2 "vector.c" 2


typedef struct generic_container_t { void* data; size_t size;; method_function_t __meta[0]; } generic_container_t; void* generic_container_t_init(generic_container_t* self); void* generic_container_t_destroy(generic_container_t* self); size_t __generic_container_t_MASK = 0; method_function_t __meta_generic_container_t[2 + 2] = {(method_function_t) generic_container_t_init, (method_function_t) generic_container_t_destroy, };



void* gen_cont_free(generic_container_t* self) {
  free(self->data);
  self->data = 0;
  self->size = 0;
  return self;
}
void* gen_cont_alloc(generic_container_t* self,
  size_t size) {
  if (self->data != 0) {
    gen_cont_free(self->data);
  }
  self->data = malloc(size);
  self->size = size;
  return self;
}
typedef enum { default_ } __generic_container_t_LIST;;
void* generic_container_t_init(generic_container_t* self) { __SET_CLASS_MASK_WAS_INIT(&__generic_container_t_MASK, 1); if (sizeof(__meta_generic_container_t) == 2 * sizeof(method_function_t)) { __SET_CLASS_MASK_INNER(&__generic_container_t_MASK, 1); } self->data = 0; self->size = 0; { method_function_t* __METHOD_PTR = 0; __generic_container_t_LIST __METHOD_ID = 0; if (!__GET_CLASS_MASK_IS_CONST(&__generic_container_t_MASK)) { if (__GET_CLASS_MASK_IS_INNER(&__generic_container_t_MASK)) { memcpy((void*)(&(self)) + __METHOD_ID * sizeof(method_function_t), &gen_cont_alloc, sizeof(method_function_t)); } else { if (__GET_CLASS_MASK_TYPE(&__generic_container_t_MASK) && (__METHOD_ID >= 2)) { ((generic_container_t*)(self))->__meta[__METHOD_ID - 2] = gen_cont_alloc; } else { __meta_generic_container_t[__METHOD_ID] = gen_cont_alloc; }; }; }; }; { method_function_t* __METHOD_PTR = 0; __generic_container_t_LIST __METHOD_ID = 1; if (!__GET_CLASS_MASK_IS_CONST(&__generic_container_t_MASK)) { if (__GET_CLASS_MASK_IS_INNER(&__generic_container_t_MASK)) { memcpy((void*)(&(self)) + __METHOD_ID * sizeof(method_function_t), &gen_cont_free, sizeof(method_function_t)); } else { if (__GET_CLASS_MASK_TYPE(&__generic_container_t_MASK) && (__METHOD_ID >= 2)) { ((generic_container_t*)(self))->__meta[__METHOD_ID - 2] = gen_cont_free; } else { __meta_generic_container_t[__METHOD_ID] = gen_cont_free; }; }; }; };; __SCOPE_STACK_PUSH(&__SCOPE_STACK, &(generic_method_t){.obj_instance=self, .function=__meta_generic_container_t[1]}); __SCOPE_STACK_PUSH(&__SCOPE_STACK, &(generic_method_t){.obj_instance=&__generic_container_t_MASK, .function=(method_function_t)__SUB_CLASS_MASK_COUNT_INSTANCES}); return self; } void* generic_container_t_destroy(generic_container_t* self)




  {
  if (self->data != 0) {
    gen_cont_free(self);
  }
  return self;
}

typedef struct vector_t { generic_container_t __base; size_t size; size_t type_size;; method_function_t __meta[0];} vector_t;void* vector_t_init(vector_t* self); void* vector_t_destroy(vector_t* self); size_t __vector_t_MASK = 4; method_function_t __meta_vector_t[2 + 10] = {(method_function_t) vector_t_init, (method_function_t) vector_t_destroy, };


typedef struct darray_t {
    void* data;
    size_t type_size;
    size_t da_size;
    size_t da_capacity;
} darray_t;


void array_init(darray_t* array, size_t type_size) {
    array->da_capacity = 16;
    array->da_size = 0;
    array->data = malloc(type_size * array->da_capacity);
    array->type_size = type_size;
}



void array_init_with(darray_t* array, size_t type_size, size_t size, const void* value) {
    array->da_capacity = 2 * size;
    array->da_size = size;
    array->data = malloc(type_size * array->da_capacity);
    array->type_size = type_size;
    for (size_t i = 0; i < size; ++i) {
        memcpy(array->data + i * type_size, value, type_size);
    }
}


void array_init_from(darray_t* array, size_t type_size, const void* source, size_t size) {
    array->da_capacity = 2 * size;
    array->da_size = size;
    array->data = malloc(type_size * array->da_capacity);
    array->type_size = type_size;
    memcpy(array->data, source, type_size * size);
}


void array_copy(darray_t* array, const void* source, size_t size) {
    if (1 + size >= array->da_capacity) {
        array->da_capacity = 2 * size;
        free(array->data);
        array->data = malloc(array->type_size * array->da_capacity);
    }
    memcpy(array->data, source, array->type_size * size);
    array->da_size = size;
}


void array_destroy(darray_t* array) {
    array->da_capacity = 0;
    array->da_size = 0;
    free(array->data);
    array->type_size = 0;
}


void array_destroy_with(darray_t* array, generic_function_t destroy) {
    for (size_t i = 0; i < array->da_size; ++i) {
        destroy(array->data + i * array->type_size);
    }
    array->da_capacity = 0;
    array->da_size = 0;
    free(array->data);
    array->type_size = 0;
}


void* array_get(darray_t* array) {
    return array->data;
}


void array_push(darray_t* array, const void* value) {
    if (array->da_size + 1 >= array->da_capacity) {
        void* buffer = malloc(array->type_size * array->da_capacity * 2);
        memcpy(buffer, array->data, array->da_size * array->type_size);
        free(array->data);
        array->data = buffer;
        array->da_capacity *= 2;
    }
    memcpy(array->data + array->da_size * array->type_size,
           value,
           array->type_size);
    array->da_size++;
}


void array_pop(darray_t* array) {
    if (array->da_size == 0) {
        return;
    }
    if (array->da_size + 1 >= array->da_capacity / 4 && array->da_size > 16) {
        void* buffer = malloc(array->type_size * array->da_capacity / 2);
        memcpy(buffer, array->data, array->da_size * array->type_size);
        free(array->data);
        array->data = buffer;
        array->da_capacity /= 2;
    }
    for (size_t i = 0; i < array->type_size; ++i) {
        *(unsigned char*)(array->data + array->da_size * array->type_size + i) = 0;
    }
    array->da_size--;
}


void array_insert(darray_t* array, size_t index, const void* value) {
    size_t max_size = array->da_size + 1;
    if (index > array->da_size) {
        max_size = index + 1;
    }
    if (max_size >= array->da_capacity) {
        while (array->da_capacity <= max_size) {
            array->da_capacity *= 2;
        }
        void* buffer = malloc(array->type_size * array->da_capacity);
        memcpy(buffer, array->data, array->da_size * array->type_size);
        free(array->data);
        array->data = buffer;
    }
    if (index < array->da_size) {
        memmove(array->data + (index + 1) * array->type_size,
                array->data + index * array->type_size,
                (array->da_size - index) * array->type_size);
    }
    memcpy(array->data + index * array->type_size,
           value,
           array->type_size);
    array->da_size++;
}

void array_remove(darray_t* array, size_t index) {
    if (array->da_size <= index) {
        return;
    }
    if (array->da_size < index + 1) {
        memmove(array->data + index * array->type_size,
                array->data + (index + 1) * array->type_size,
                (array->da_size - index - 1) * array->type_size);
        array->da_size--;
    } else {
        array_pop(array);
    }
}


void array_clear(darray_t* array) {
    array->da_size = 0;
}


size_t array_find(const darray_t* array, const void* value) {
    for (size_t i = 0; i < array->da_size; ++i) {
        if (strncmp(array->data + i * array->type_size, value, array->type_size) == 0) {
            return i;
        }
    }
    return -1;
}


size_t array_rfind(const darray_t* array, const void* value) {
    for (size_t i = array->da_size; i > 0; --i) {
        if (strncmp(array->data + (i - 1) * array->type_size, value, array->type_size) == 0) {
            return i - 1;
        }
    }
    return -1;
}


size_t array_find_all(const darray_t* array, const void* value, darray_t* container) {
    array_clear(container);
    for (size_t i = 0; i < array->da_size; ++i) {
        if (memcmp(array->data + i * array->type_size, value, array->type_size) == 0) {
            array_push(container, &i);
        }
    }
    return container->da_size;
}


size_t array_split(darray_t* array, const void* value, darray_t* container) {
    array_clear(container);
    darray_t tmp_array[1];
    darray_t iter_array[1];
    array_init(tmp_array, sizeof(size_t));
    array_find_all(array, value, tmp_array);
    size_t initial_index = 0;
    size_t iter_index = 0;
    for (size_t i = 0; i < tmp_array->da_size; ++i) {
        iter_index = ((size_t*)tmp_array->data)[i] + 1;
        iter_array->da_capacity = 4 * (iter_index - initial_index) / 3;
        iter_array->data = malloc(iter_array->da_capacity * array->type_size);
        iter_array->da_size = iter_index - initial_index - 1;
        iter_array->type_size = array->type_size;
        memcpy(iter_array->data,
               array->data + initial_index * array->type_size,
               iter_array->da_size * array->type_size);
        initial_index = iter_index;
        if (iter_array->da_size > 0) {
            array_push(container, &iter_array);
        }
    }
    if (initial_index < array->da_size) {
        iter_index = array->da_size;
        iter_array->da_capacity = 4 * (iter_index - initial_index) / 3;
        iter_array->data = malloc(iter_array->da_capacity * array->type_size);
        iter_array->da_size = iter_index - initial_index;
        iter_array->type_size = array->type_size;
        memcpy(iter_array->data,
                array->data + initial_index * array->type_size,
                iter_array->da_size * array->type_size);
        if (iter_array->da_size > 0) {
            array_push(container, &iter_array);
        }
    }
    array_destroy(tmp_array);
    return container->da_size;
}




typedef struct iterator_t {
    darray_t container[1];
    size_t index;
    unsigned char flags;
} iterator_t;
# 275 "vector.c"
void iterator_init(iterator_t* iterator, darray_t* array) {
    memcpy(iterator->container, array, sizeof(darray_t));
    iterator->index = 0;
    iterator->flags = 0;
}


void iterator_destroy(iterator_t* iterator) {
    iterator->container->data = 
# 283 "vector.c" 3 4
                               ((void *)0)
# 283 "vector.c"
                                   ;
    iterator->container->da_capacity = 0;
    iterator->container->da_size = 0;
    iterator->container->type_size = 0;
    iterator->index = 0;
    iterator->flags = 0;
}


void* iterator_next(iterator_t* iterator) {
    iterator->flags &= ((0x7f*2 + 1) ^ 8);
    iterator->flags &= ((0x7f*2 + 1) ^ 16);
    iterator->index++;
    if (iterator->index == iterator->container->da_size) {
        iterator->index = 0;
        iterator->flags |= 1 |
                           2 |
                           8;
    }
    return iterator->container->data + iterator->index * iterator->container->type_size;
}


void* iterator_prev(iterator_t* iterator) {
    iterator->flags &= ((0x7f*2 + 1) ^ 8);
    iterator->flags &= ((0x7f*2 + 1) ^ 16);
    if (iterator->index == 0) {
        iterator->index = iterator->container->da_size;
        iterator->flags |= 1 |
                           4 |
                           16;
    }
    iterator->index--;
    return iterator->container->data + iterator->index * iterator->container->type_size;
}


void* iterator_at(iterator_t* iterator, size_t index) {
    iterator->flags &= ((0x7f*2 + 1) ^ 8);
    iterator->flags &= ((0x7f*2 + 1) ^ 16);
    if (index >= iterator->container->da_size) {
        return 
# 324 "vector.c" 3 4
              ((void *)0)
# 324 "vector.c"
                  ;
    }
    iterator->index = index;
    return iterator->container->data + iterator->index * iterator->container->type_size;
}

BOOL iterator_BOOL(iterator_t* iterator) {
    if (iterator->flags & (8 |
        16)) {
        return false;
    }
    return true;
}

void reset(iterator_t* iterator) {
    iterator->flags = 0;
    iterator->index = 0;
}




typedef struct string_t {
    darray_t container[1];
} string_t;

void string_init(string_t* string) {
    array_init(string->container, 1);
}

void string_init_from(string_t* string, const char* input_string, size_t string_size) {
    array_init_from(string->container, 1, input_string, string_size + 1);
    ((char*)string->container->data)[string_size] = '\0';
}

void string_destroy(string_t* string) {
    array_destroy(string->container);
}
# 405 "vector.c"
typedef struct heap_t {
    darray_t* pointers_on_heap;
    darray_t* pointers_on_stack;
    size_t pointers_allocated;
    size_t pointers_freed;
    size_t pointers_total;
} heap_t;


void heap_init(heap_t* heap) {
    heap->pointers_allocated = 0;
    heap->pointers_freed = 0;
    heap->pointers_total = 0;
    heap->pointers_on_heap = malloc(sizeof(darray_t));
    heap->pointers_on_stack = malloc(sizeof(darray_t));
    array_init(heap->pointers_on_heap, sizeof(heap));
    array_init(heap->pointers_on_stack, sizeof(heap));
}


void heap_destroy(heap_t* heap) {
    for (size_t i = 0; i < heap->pointers_total; ++i) {
        if (((void***)array_get(heap->pointers_on_stack))[i] != 
# 427 "vector.c" 3 4
                                                               ((void *)0)
# 427 "vector.c"
                                                                   ) {
            free(((void**)array_get(heap->pointers_on_heap))[i]);
        }
    }
    array_destroy(heap->pointers_on_heap);
    array_destroy(heap->pointers_on_stack);
    heap->pointers_allocated = 0;
    heap->pointers_freed = 0;
    heap->pointers_total = 0;
}


void heap_alloc(heap_t* heap, size_t size, size_t type_size, void* address) {
    heap->pointers_allocated++;
    heap->pointers_total++;
    *((void**)address) = malloc(type_size * size);
    array_push(heap->pointers_on_stack, &address);
    array_push(heap->pointers_on_heap, address);
}


void heap_alloc_init(heap_t* heap, size_t size, size_t type_size, void* address, void* init_value) {
    heap->pointers_allocated++;
    heap->pointers_total++;
    *((void**)address) = malloc(type_size * size);
    for (size_t i = 0; i < size * type_size; i += type_size) {
        memcpy(*((void**)address), &init_value, type_size);
    }
    array_push(heap->pointers_on_stack, &address);
    array_push(heap->pointers_on_heap, address);
}


void heap_dealloc(heap_t* heap, void* address) {
    for (size_t i = heap->pointers_total; i > 0; --i) {
        if (((void**)array_get(heap->pointers_on_heap))[i - 1] == address) {
            free(((void**)array_get(heap->pointers_on_heap))[i - 1]);
            ((void***)array_get(heap->pointers_on_stack))[i - 1] = 
# 464 "vector.c" 3 4
                                                                  ((void *)0)
# 464 "vector.c"
                                                                      ;
            heap->pointers_allocated--;
            if (i == heap->pointers_total) {
                array_pop(heap->pointers_on_heap);
                array_pop(heap->pointers_on_stack);
                heap->pointers_total--;
            } else {
                heap->pointers_freed++;
            }
        }
    }
}


void collect_garbage(heap_t* heap, void* reference_address) {
    int tmp_object_on_stack_old = 0;
    int tmp_object_on_stack_new = tmp_object_on_stack_old + 1;
    int flag = 1;
    for (size_t i = heap->pointers_total; (i > 0) && (flag & 1); --i) {
        flag &= 3;
        if (&tmp_object_on_stack_new < &tmp_object_on_stack_old) {
            if (((void***)array_get(heap->pointers_on_stack))[i - 1] <= (void**)reference_address) {
                free(((void**)array_get(heap->pointers_on_heap))[i - 1]);
                ((void**)array_get(heap->pointers_on_stack))[i - 1] = 
# 487 "vector.c" 3 4
                                                                     ((void *)0)
# 487 "vector.c"
                                                                         ;
                heap->pointers_allocated--;
                if (i == heap->pointers_total) {
                    array_pop(heap->pointers_on_heap);
                    array_pop(heap->pointers_on_stack);
                    heap->pointers_total--;
                } else {
                    heap->pointers_freed++;
                }
                flag |= 2;
                flag |= 4;
            }
        } else {
            if (((void***)array_get(heap->pointers_on_stack))[i - 1] >= (void**)reference_address) {
                free(((void**)array_get(heap->pointers_on_heap))[i - 1]);
                ((void**)array_get(heap->pointers_on_stack))[i - 1] = 
# 502 "vector.c" 3 4
                                                                     ((void *)0)
# 502 "vector.c"
                                                                         ;
                heap->pointers_allocated--;
                if (i == heap->pointers_total) {
                    array_pop(heap->pointers_on_heap);
                    array_pop(heap->pointers_on_stack);
                    heap->pointers_total--;
                } else {
                    heap->pointers_freed++;
                }
                flag |= 2;
                flag |= 4;
            }
        }
        if (flag & 2) {
            flag &= 2 + ((flag & 4) > 0);
        }
    }
}


typedef enum { default_ } __vector_t_LIST;;
void* vector_t_init(vector_t* self) { __meta_generic_container_t[0](&(self->__base)); __SET_CLASS_MASK_SUPER(&__generic_container_t_MASK, 1); for (size_t i = 2; i < (sizeof(__meta_vector_t) / sizeof(method_function_t) < sizeof(__meta_generic_container_t) / sizeof(method_function_t) ? sizeof(__meta_vector_t) / sizeof(method_function_t) : sizeof(__meta_generic_container_t) / sizeof(method_function_t)); ++i) { __meta_vector_t[i] = __meta_generic_container_t[i]; } if (__GET_CLASS_MASK_TYPE(&__vector_t_MASK)) { if (__GET_CLASS_MASK_TYPE(&__generic_container_t_MASK)) { for (size_t i = 2; i < (sizeof(__meta_vector_t) / sizeof(method_function_t) < sizeof(__meta_generic_container_t) / sizeof(method_function_t) ? sizeof(__meta_vector_t) / sizeof(method_function_t) : sizeof(__meta_generic_container_t) / sizeof(method_function_t)); ++i) { self->__meta[i - 2] = self->__base.__meta[i - 2]; } } else { for (size_t i = 2; i < (sizeof(__meta_vector_t) / sizeof(method_function_t) < sizeof(__meta_generic_container_t) / sizeof(method_function_t) ? sizeof(__meta_vector_t) / sizeof(method_function_t) : sizeof(__meta_generic_container_t) / sizeof(method_function_t)); ++i) { self->__meta[i - 2] = __meta_generic_container_t[i]; } } } else { if (__GET_CLASS_MASK_TYPE(&__generic_container_t_MASK)) { for (size_t i = 2; i < (sizeof(__meta_vector_t) / sizeof(method_function_t) < sizeof(__meta_generic_container_t) / sizeof(method_function_t) ? sizeof(__meta_vector_t) / sizeof(method_function_t) : sizeof(__meta_generic_container_t) / sizeof(method_function_t)); ++i) { __meta_vector_t[i] = self->__base.__meta[i]; } } } self->size = 0; self->type_size = 0;; __SCOPE_STACK_PUSH(&__SCOPE_STACK, &(generic_method_t){.obj_instance=self, .function=__meta_vector_t[1]}); __SCOPE_STACK_PUSH(&__SCOPE_STACK, &(generic_method_t){.obj_instance=&__vector_t_MASK, .function=(method_function_t)__SUB_CLASS_MASK_COUNT_INSTANCES}); return self; } void* vector_t_destroy(vector_t* self)


  {
  self->size = 0;
  self->type_size = 0;

  return self;
}
