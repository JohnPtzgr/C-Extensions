# 0 "tests/test_class_.c"
# 1 "/home/just_engineer/dev/extraslib//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "tests/test_class_.c"




# 1 "tests/../src/oop/class.h" 1
# 1 "tests/../src/oop/../memory/dyn_alloc.h" 1
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 415 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 416 "/usr/include/features.h" 2 3 4
# 523 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 730 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 731 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 732 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 524 "/usr/include/features.h" 2 3 4
# 547 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 548 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4

# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 344 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 56 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 131 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 132 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
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
  unsigned int __g_size[2] ;
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
  unsigned int __unused_initialized_1;
  unsigned int __unused_initialized_2;
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



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__)) __attribute__ ((__cold__));



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

# 2 "tests/../src/oop/../memory/dyn_alloc.h" 2
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
# 36 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
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
  int _flags2:24;

  char _short_backupbuf[1];
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

# 3 "tests/../src/oop/../memory/dyn_alloc.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 286 "/usr/include/string.h" 3 4
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 380 "/usr/include/string.h" 3 4
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));







extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4










extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlcpy (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



extern size_t strlcat (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
# 552 "/usr/include/string.h" 3 4

# 4 "tests/../src/oop/../memory/dyn_alloc.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stdarg.h" 1 3 4
# 5 "tests/../src/oop/../memory/dyn_alloc.h" 2

# 1 "tests/../src/oop/../memory/../oop/exception.h" 1
# 1 "/usr/include/errno.h" 1 3 4
# 28 "/usr/include/errno.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/lib/linux/uapi/x86/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 2 "/usr/lib/linux/uapi/x86/asm/errno.h" 2 3 4
# 2 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4








extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 52 "/usr/include/errno.h" 3 4

# 2 "tests/../src/oop/../memory/../oop/exception.h" 2

       
# 24 "tests/../src/oop/../memory/../oop/exception.h"

# 24 "tests/../src/oop/../memory/../oop/exception.h"
typedef struct exception_context_t
{
  char data[4096];
} exception_context_t;

extern exception_context_t _EXCEPTION_CONTEXT;
extern unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR;

typedef int exception_status_t;

typedef struct exception_t
{
  unsigned int exception_number;
  exception_status_t status;
  exception_context_t* context;
  char* exception_description;
} exception_t;

extern exception_t _EXCEPTION;

extern exception_t CAUGHT_EXCEPTION;
extern exception_context_t CAUGHT_EXCEPTION_CONTEXT;
# 54 "tests/../src/oop/../memory/../oop/exception.h"
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;


extern BOOL _ERRORB;
extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);
# 87 "tests/../src/oop/../memory/../oop/exception.h"
void* __raise_exception__(exception_t* exception);
# 100 "tests/../src/oop/../memory/../oop/exception.h"
void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...);
# 122 "tests/../src/oop/../memory/../oop/exception.h"
void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, void(*callback)());
# 7 "tests/../src/oop/../memory/dyn_alloc.h" 2
       
# 72 "tests/../src/oop/../memory/dyn_alloc.h"
typedef void*(*generic_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

void* __CALL_FUNCTION__(generic_function_t, void*);
void* __CALL_FUNCTION_N_ARGS__(generic_function_t, ... );





typedef struct __SCOPE_STACK__ {
  size_t capacity;
  size_t size;
  generic_function_t* actions;
  void** instances;
  void*** args;
  char* masks;
} __SCOPE_STACK__;

typedef struct __SCOPE_DEFER_CHUNK__ {
  long bias_sum;
  size_t min_indentation;
  size_t capacity;
  size_t size;
  generic_function_t* predicates;
  void*** predicate_args;
  generic_function_t* actions;
  void** instances;
  void*** args;
} __SCOPE_DEFER_CHUNK__;



typedef struct __SCOPE_DEFER_POOL__ {
  unsigned int chunk_bias_pos;
  unsigned int chunk_bias_neg;
  size_t active_size;
  size_t size;
  size_t capacity;
  size_t tokens;
  size_t indentation;
  void* tree_root;
  __SCOPE_DEFER_CHUNK__* chunks;
} __SCOPE_DEFER_POOL__;







void* __scope_stack_init__(__SCOPE_STACK__* stack);
size_t __scope_stack_destroy__(__SCOPE_STACK__* stack);
size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance,
  void** args);
size_t __scope_stack_pop__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack);
void* __scope_stack_top__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  generic_function_t predicate);
size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack);
size_t __scope_stack_find__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_find_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_skip__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);







void* __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args,
  size_t indentation);
size_t __scope_defer_chunk_find__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_skip__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk);
# 199 "tests/../src/oop/../memory/dyn_alloc.h"
void* __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_enter__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_escape__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_add_token__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_skip__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_force__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_find__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
# 228 "tests/../src/oop/../memory/dyn_alloc.h"
typedef struct __SCOPE_OBJECT__ {
  __SCOPE_STACK__* stack;
  __SCOPE_DEFER_POOL__* defer_pool;
  size_t size;
  size_t mask;
} __SCOPE_OBJECT__;

void* __scope_object_init__(__SCOPE_OBJECT__* scope,
  __SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope);
size_t __scope_object_enter__(__SCOPE_OBJECT__* scope);
size_t __scope_object_escape__(__SCOPE_OBJECT__* scope);
size_t __scope_object_change_bias__(__SCOPE_OBJECT__* scope,
  size_t bias_positive,
  size_t bias_negative);
size_t __scope_object_lock_pool__(__SCOPE_OBJECT__* scope);
size_t __scope_object_push__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_stage__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_defer__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  generic_function_t predicate,
  ...);
size_t __scope_object_skip__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);
size_t __scope_object_force__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);


extern __SCOPE_STACK__ __SCOPE_STACK_INST__;
extern __SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__;
extern __SCOPE_OBJECT__ __SCOPE_OBJECT_INST__;

void* __SCOPE_BEGIN__(__SCOPE_OBJECT__* scope,
  __SCOPE_DEFER_POOL__* pool,
  __SCOPE_STACK__* stack);

void* __SCOPE_END__(__SCOPE_OBJECT__* scope);

void* __SCOPE_CALLOC__(__SCOPE_OBJECT__* scope,
  size_t size,
  size_t type_size,
  void* filler,
  ...);

void* __SCOPE_FREE__(__SCOPE_OBJECT__* scope, void* data);

void* __SCOPE_FORCED_RELEASE__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

void* __SCOPE_SKIP__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

__SCOPE_OBJECT__* __LOCAL_SCOPE_NEW__();

void* __LOCAL_SCOPE_FREE__(__SCOPE_OBJECT__* local_scope);

void* __DEFAULT_PREDICATE__(void* instance, ...);

void* __TRUE_PREDICATE__(void* instance, ...);

void* __FALSE_PREDICATE__(void* instance, ...);
# 2 "tests/../src/oop/class.h" 2
# 1 "tests/../src/oop/../algorithm/hash.h" 1

       
# 28 "tests/../src/oop/../algorithm/hash.h"
size_t hash_finalise(size_t);

size_t hash_byte_array(void*, size_t);
# 3 "tests/../src/oop/class.h" 2

       
# 33 "tests/../src/oop/class.h"
typedef struct __vTableHash__ {
  size_t hashX;
  size_t hashY;
} __vTableHash__;

typedef struct __vTableNode__ {
  void* data;
  size_t data_mask;
  size_t data_shift;
  size_t mask;
  __vTableHash__ hash;
} __vTableNode__;
# 53 "tests/../src/oop/class.h"
typedef size_t (*__vTable_byte_hasher_t__)(const char* key, size_t k_hash);

typedef struct __vTable__ {
  __vTable_byte_hasher_t__ hasher;
  __vTableNode__* data;
  size_t size;
} __vTable__;

__vTableHash__ __class_vtable_hash__(const char* key);

void* __vTable_add__(__vTable__* table, __vTableHash__ hash, __vTableNode__ value);
void* __vTable_remove__(__vTable__* table, __vTableHash__ hash);
__vTableNode__* __vTable_get__(__vTable__* table, __vTableHash__ hash);
BOOL __vTable_check__(__vTable__* table, __vTableHash__ hash);
void* __vTable_join__(__vTable__* table, __vTable__* source);


typedef enum __m_enum__ {
  __m_init__,
  __m_destroy__,
  __m_cast__,
  __m_copy__,
  __m_assign__,
  __m_move__,
  __m_call__,
  __m_getitem__,
  __m_iter__,
  __m_id__,
  __m_set__,
  __m_get__,
  __m_cmp__,
  __m_listen__,
  __m_shout__,
  __m_new__,
  __m_delete__,
  __m_contains__,
  __m_data__,
  __m_next__,
  __m_begin__,
  __m_end__,
  __m_len__,
  __m_lt__,
  __m_gt__,
  __m_eq__,
  __m_le__,
  __m_ge__,
  __m_neq__,
  __m_neg__,
  __m_ineg__,
  __m_add__,
  __m_iadd__,
  __m_sub__,
  __m_isub__,
  __m_mul__,
  __m_imul__,
  __m_div__,
  __m_idiv__,
  __m_mod__,
  __m_imod__,
  __m_and__,
  __m_iand__,
  __m_or__,
  __m_ior__,
  __m_xor__,
  __m_ixor__,
  __m_not__,
  __m_inot__,
  __m_pow__,
  __m_bitand__,
  __m_bitiand__,
  __m_bitor__,
  __m_bitior__,
  __m_bitxor__,
  __m_bitixor__,
  __m_bitnot__,
  __m_bitinot__,
  __m_inc__,
  __m_dec__,
  __m_lsh__,
  __m_ilsh__,
  __m_rsh__,
  __m_irsh__
} __m_enum__;
# 199 "tests/../src/oop/class.h"
typedef struct __ClassObject__ __ClassObject__;

typedef struct __vClassObject__ __vClassObject__;

typedef struct __MetaObject__ {
  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __cast__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __move__;
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __iter__;
  generic_function_t __id__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __cmp__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __contains__;
  generic_function_t __data__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
  generic_function_t __len__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __neg__;
  generic_function_t __ineg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __pow__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;

  unsigned int* __method_shift__;

} __MetaObject__;

typedef struct __InheritanceListNode__ {
  __ClassObject__* cls;
  size_t adress_shift;
} __InheritanceListNode__;



typedef struct __InheritanceList__ {
  __InheritanceListNode__* list;
  __InheritanceListNode__* static_list;
  size_t capacity;
  size_t size;
} __InheritanceList__;

typedef struct __ClassInstance__ __ClassInstance__;

typedef struct __ClassInstance_R__ __ClassInstance_R__;


void* __InheritanceList_add__(__InheritanceList__* list, void* self,
  void* instance, __ClassObject__* cls);
void* __InheritanceList_remove__(__InheritanceList__* list, __ClassInstance__* instance);
size_t __InheritanceList_find__(__InheritanceList__* list, __vTableHash__ hash);
size_t __InheritanceList_find_built_in__(__InheritanceList__* list, __m_enum__ built_in_no);
void* __InheritanceList_init__(__InheritanceList__* list, __InheritanceListNode__* default_nodes);
void* __InheritanceList_destroy__(__InheritanceList__* list);


typedef struct class_field_t class_field_t;

typedef class_field_t* class_structure_t;




typedef struct __vClassObjectPrt__ {

  void* data;

} __vClassObjectPrt__;

typedef struct __ClassMetaObject__ {

  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __cast__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __move__;
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __iter__;
  generic_function_t __id__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __cmp__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __contains__;
  generic_function_t __data__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
  generic_function_t __len__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __neg__;
  generic_function_t __ineg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __pow__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;

  unsigned int* __method_shift__;

  __ClassObject__* cls;

} __ClassMetaObject__;

typedef struct type_object_t {

  __ClassMetaObject__* type_meta;
  const char* type_name;
  size_t type_size;
  size_t type_mask;

} type_object_t;

typedef struct class_field_t
{

  size_t field_mask;
  char* field_name;
  void* field_addr;
  type_object_t* type;

} class_field_t;

typedef struct __FundamentalVClass__ {
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __iter__;
  generic_function_t __id__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __cmp__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __contains__;
  generic_function_t __data__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
  generic_function_t __len__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __neg__;
  generic_function_t __ineg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __pow__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;

} __FundamentalVClass__;

struct __vClassObjectMeta__ {
  char __prot_vcls_data__[0];
  unsigned int __method_shift__[0];
  __vClassObjectPrt__ __protected__[0];
  __vTable__ __vtable__[0];
};

typedef struct __vClassObject__ {


  generic_function_t __init__;
  generic_function_t __destroy__;


  generic_function_t __cast__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __move__;


  __FundamentalVClass__ _f;


  unsigned int* __method_shift__;


  __ClassObject__* cls;


  struct __vClassObjectMeta__ __meta__;

} __vClassObject__;

typedef struct __ClassInstance__ {
  __vClassObject__ __meta__[0];
} __ClassInstance__;

typedef struct __ClassInterface__ {
  const __vClassObject__* __meta__;
  __ClassInstance__* self;
} __ClassInterface__;

typedef struct __Interface__ {
  const __MetaObject__* __meta__;
} __Interface__;







  typedef __FundamentalVClass__ __DefaultBase_FundamentalVClass__;


typedef struct __ClassObject__ {

  size_t instance_size;
  size_t vclass_size;
  size_t vclass_meta_size;
  size_t _f_class_size;
  size_t mask;
  size_t instance_count;

  size_t __vclass_cnt;
  size_t __vclass_capacity;

  const char* name;

  class_structure_t* fields;
  class_structure_t* static_fields;

  __InheritanceList__* inherits_from;

  __vClassObject__** alloc_vcls;

  __vClassObject__* default_vcls;
  __ClassInstance__* default_instance;

  __ClassObject__** __vcls_cls__;

  generic_function_t __static_init__;
  generic_function_t __static_destroy__;

  generic_function_t __class_object_init__;
  generic_function_t __class_object_destroy__;

} __ClassObject__;

void* __class_init__(__ClassObject__* cls);
void* __class_destroy__(__ClassObject__* cls);
void __class_inherit_static__(__ClassObject__* cls);
void __class_inherit__(__ClassObject__* cls);
void __class_inherit_instance__(__ClassInstance__* instance);

extern const char* __VCLASS_METHOD_UC_NAMES__[64];





void* __aux_class_new_vclass__(__ClassObject__* cls);

void* __aux_type_cast__(void* expr, type_object_t* src_type, type_object_t* trg_type, void* allocated_memory);
void* __aux_class_cast__(void* expr, __ClassMetaObject__* src_type, __ClassMetaObject__* trg_type, void* allocated_memory);



BOOL __GET_CLASS_MASK_IS_STATIC__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_FUNDAMENTAL__(size_t* mask);

BOOL __GET_CLASS_MASK_DERIVED__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_ABSTRACT__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_CONST__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_CUSTOM__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_SUPER__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BRIDGE__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BARE__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_ILLDEFINED__(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_INIT__(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask);

void __SET_CLASS_MASK_STATIC__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_FUNDAMENTAL__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_DERIVED__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_ABSTRACT__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_CONST__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_CUSTOM__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_SUPER__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BRIDGE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BARE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_ILLDEFINED__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_INIT__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask, BOOL new_type);
# 692 "tests/../src/oop/class.h"
typedef __ClassInstance__ DefaultBase_S; typedef DefaultBase_S DefaultBase;

typedef __vClassObject__ __DefaultBase_vClassObject__;

extern __ClassObject__ __DefaultBase_ClassObject__;
extern DefaultBase_S __DefaultBase_Default_Instance__;
extern __vClassObject__ __DefaultBase_Default_vClassObject__;
extern type_object_t __DefaultBase_type__;
extern type_object_t* DefaultBase_type;
extern void* __DefaultBase_static_init__(DefaultBase* self);
extern void* __DefaultBase_static_destroy__(DefaultBase* self);
# 1146 "tests/../src/oop/class.h"
void* __aux_class_new_wrapper__(__ClassObject__* cls, size_t size, __ClassInstance__* template_instance);
# 1305 "tests/../src/oop/class.h"
__Interface__* create_class(class_field_t* fields);
void* create_instance(type_object_t* type);
# 6 "tests/test_class_.c" 2

struct test_class_t
{
  long b;
};




typedef struct __tst_c_vClassObject__ __tst_c_vClassObject__; typedef struct tst_c_S { DefaultBase_S __base__; int z; __tst_c_vClassObject__* __meta__; } tst_c_S; typedef tst_c_S tst_c; typedef struct tst_c_R { DefaultBase __base__; int z; } tst_c_R; ;; typedef struct __tst_c_vClassObjectPrt__ { __vClassObjectPrt__ default_protected; ;; } __tst_c_vClassObjectPrt__; typedef __DefaultBase_FundamentalVClass__ __tst_c_FundamentalVClass__; struct __tst_c_vClassObjectMeta__ { char __prot_vcls_data__[sizeof(__tst_c_vClassObjectPrt__)]; unsigned int __method_shift__[64 + 0 + 0]; __vClassObjectPrt__* __protected__; __vTable__* __vtable__; }; typedef struct __tst_c_vClassObject__ { generic_function_t __init__; generic_function_t __destroy__; generic_function_t __cast__; generic_function_t __copy__; generic_function_t __assign__; generic_function_t __move__; __tst_c_FundamentalVClass__ _f; unsigned int* __method_shift__; __ClassObject__* cls; __DefaultBase_vClassObject__* __base__; int w; struct __tst_c_vClassObjectMeta__ __meta__; } __tst_c_vClassObject__; typedef struct __tst_c_ClassInterface__ { tst_c* self; const __tst_c_vClassObject__* __meta__; } __tst_c_ClassInterface__; extern void* __tst_c_static_init__(tst_c* self); extern void* __tst_c_static_destroy__(tst_c* self); extern void* tst_c_init(tst_c* self , ...); extern void* tst_c_destroy(tst_c* self, ...); extern __ClassObject__ __tst_c_ClassObject__; extern __tst_c_vClassObject__ __tst_c_Default_vClassObject__; extern tst_c_S __tst_c_Default_Instance__; extern type_object_t __tst_c_type__; extern type_object_t* tst_c_type; extern __InheritanceList__ __tst_c__InheritanceList__; extern __InheritanceListNode__ __tst_c__InheritanceListNodes__[8]; extern class_field_t __tst_c_fields__[0 + 1]; extern class_field_t __tst_c_static_fields__[0 + 1];;




__ClassObject__ __tst_c_ClassObject__ = (__ClassObject__){.mask=0, .instance_size=sizeof(tst_c_S), .vclass_size=sizeof(__tst_c_vClassObject__), .default_vcls=(__vClassObject__*)&__tst_c_Default_vClassObject__, .default_instance=(__ClassInstance__*)&__tst_c_Default_Instance__, .name="tst_c", .__vcls_cls__=&__tst_c_Default_vClassObject__.cls, .fields=(class_field_t**)&__tst_c_fields__, .static_fields=(class_field_t**)&__tst_c_static_fields__, .__static_init__=(generic_function_t)__tst_c_static_init__, .__static_destroy__=(generic_function_t)__tst_c_static_destroy__}; __tst_c_vClassObject__ __tst_c_Default_vClassObject__ = (__tst_c_vClassObject__){.__init__=(generic_function_t)tst_c_init, .__destroy__=(generic_function_t)tst_c_destroy, .cls=&__tst_c_ClassObject__, .__meta__.__protected__=(__vClassObjectPrt__*)&(__tst_c_Default_vClassObject__.__meta__.__prot_vcls_data__), .__base__=&__DefaultBase_Default_vClassObject__}; tst_c_S __tst_c_Default_Instance__ = (tst_c_S){}; type_object_t __tst_c_type__ = (type_object_t){.type_mask=0, .type_size=sizeof(tst_c_S), .type_meta=(__ClassMetaObject__*)&__tst_c_Default_vClassObject__, .type_name="tst_c"}; type_object_t* tst_c_type = &__tst_c_type__; __InheritanceList__ __tst_c__InheritanceList__ = (__InheritanceList__){}; __InheritanceListNode__ __tst_c__InheritanceListNodes__[8] = {}; class_field_t __tst_c_fields__[sizeof(__tst_c_fields__) / sizeof(class_field_t)] = {}; class_field_t __tst_c_static_fields__[sizeof(__tst_c_static_fields__) / sizeof(class_field_t)] = {}; void* __tst_c_static_init__(tst_c* self) { __DefaultBase_ClassObject__.__static_init__((void*)self); if (!__GET_CLASS_MASK_WAS_STATIC_INIT__(&(__tst_c_ClassObject__.mask))) { if ((void*)self != (void*)&__tst_c_Default_Instance__) { __tst_c_static_init__((tst_c*)(void*)&__tst_c_Default_Instance__); } else { *(tst_c_S*)self = (tst_c_S){}; if (!__tst_c_ClassObject__.inherits_from) { __tst_c_ClassObject__.inherits_from = &__tst_c__InheritanceList__; __InheritanceList_init__(__tst_c_ClassObject__.inherits_from, __tst_c__InheritanceListNodes__); __InheritanceList_add__(__tst_c_ClassObject__.inherits_from, (void*)self, (void*)self + sizeof(void*), &__DefaultBase_ClassObject__); } __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(&__tst_c_ClassObject__), (generic_function_t)(__class_destroy__), 0); __scope_object_defer__(&__SCOPE_OBJECT_INST__, (void*)(&__tst_c_ClassObject__), (generic_function_t)(__class_destroy__), (generic_function_t)(__DEFAULT_PREDICATE__), 0); }; }; if (!__GET_CLASS_MASK_IS_BARE__(&(__tst_c_ClassObject__.mask))) { *(void**)(&self->__meta__) = (void*)&__tst_c_Default_vClassObject__; } if ((void*)self != (void*)&__tst_c_Default_Instance__) { __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(self), (generic_function_t)(__tst_c_static_destroy__), 0); } self->z = 0; printf("TST_C init!\n");; if (!__GET_CLASS_MASK_WAS_STATIC_INIT__(&(__tst_c_ClassObject__.mask))) { __SET_CLASS_MASK_WAS_STATIC_INIT__(&(__tst_c_ClassObject__.mask), TRUE); __class_inherit_static__(&__tst_c_ClassObject__); if (__tst_c_ClassObject__.__class_object_init__) { __tst_c_ClassObject__.__class_object_init__(&__tst_c_ClassObject__); }; }; return self; } void* __tst_c_static_destroy__(tst_c* self)


  { ; return 
# 23 "tests/test_class_.c" 3 4
 ((void *)0)
# 23 "tests/test_class_.c"
 ; } void* tst_c_destroy(tst_c* self, ...) { ; return 
# 23 "tests/test_class_.c" 3 4
 ((void *)0)
# 23 "tests/test_class_.c"
 ; }

void* tst_c_init(tst_c* self, ...) { if ((void*)self != (void*)&__tst_c_Default_Instance__ && !__GET_CLASS_MASK_WAS_INIT__(&(__tst_c_ClassObject__.mask))) { tst_c_init((void*)&__tst_c_Default_Instance__); } __tst_c_static_init__((void*)self); ((((__tst_c_ClassObject__.mask & 8) == 0) && "Abstract class is not instantiable!") ? ((void*)0) : __exc_assert_fail__(&_EXCEPTION, "Assertion failed! '" "((__tst_c_ClassObject__.mask & ABSTRACT) == 0) && \"Abstract class is not instantiable!\"" "' in file " "tests/test_class_.c" ":" "25", __func__, ((void*)0)) ); __tst_c_ClassObject__.instance_count++; if (!__GET_CLASS_MASK_WAS_INIT__(&(__tst_c_ClassObject__.mask))) { if (!__GET_CLASS_MASK_IS_STATIC__(&(__tst_c_ClassObject__.mask))) { __class_init__((__ClassObject__*)&__tst_c_ClassObject__); if (__GET_CLASS_MASK_DERIVED__(&(__tst_c_ClassObject__.mask))) { __class_inherit__(&__tst_c_ClassObject__); } }; };; ; __tst_c_ClassObject__.instance_count++; if (!__GET_CLASS_MASK_WAS_INIT__(&(__tst_c_ClassObject__.mask))) { __SET_CLASS_MASK_WAS_INIT__(&(__tst_c_ClassObject__.mask), TRUE);; }; if ((void*)self != (void*)&__tst_c_Default_Instance__) { __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(self), (generic_function_t)(tst_c_destroy), 0); } return self;; }

int asda() {
  struct tst_c_S as;







}
# 99 "tests/test_class_.c"
int main() {
  __SCOPE_BEGIN__(&__SCOPE_OBJECT_INST__, &__SCOPE_DEFER_POOL_INST__, &__SCOPE_STACK_INST__);;
  sizeof(__DefaultBase_Default_vClassObject__.__meta__);




  __SCOPE_END__(&__SCOPE_OBJECT_INST__);;
}
# 0 "src/memory/dyn_alloc.c"
# 1 "/home/just_engineer/dev/extraslib//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "src/memory/dyn_alloc.c"
# 1 "src/memory/dyn_alloc.h" 1
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 415 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 416 "/usr/include/features.h" 2 3 4
# 523 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 730 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 731 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 732 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 524 "/usr/include/features.h" 2 3 4
# 547 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 548 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4

# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 344 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 56 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 131 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 132 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
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
  unsigned int __g_size[2] ;
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
  unsigned int __unused_initialized_1;
  unsigned int __unused_initialized_2;
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



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__)) __attribute__ ((__cold__));



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

# 2 "src/memory/dyn_alloc.h" 2
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
# 36 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
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
  int _flags2:24;

  char _short_backupbuf[1];
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

# 3 "src/memory/dyn_alloc.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 286 "/usr/include/string.h" 3 4
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 380 "/usr/include/string.h" 3 4
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));







extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4










extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlcpy (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



extern size_t strlcat (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
# 552 "/usr/include/string.h" 3 4

# 4 "src/memory/dyn_alloc.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stdarg.h" 1 3 4
# 5 "src/memory/dyn_alloc.h" 2

# 1 "src/memory/../oop/exception.h" 1
# 1 "/usr/include/errno.h" 1 3 4
# 28 "/usr/include/errno.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/lib/linux/uapi/x86/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 2 "/usr/lib/linux/uapi/x86/asm/errno.h" 2 3 4
# 2 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4








extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 52 "/usr/include/errno.h" 3 4

# 2 "src/memory/../oop/exception.h" 2

       
# 24 "src/memory/../oop/exception.h"

# 24 "src/memory/../oop/exception.h"
typedef struct exception_context_t
{
  char data[4096];
} exception_context_t;

extern exception_context_t _EXCEPTION_CONTEXT;
extern unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR;

typedef int exception_status_t;

typedef struct exception_t
{
  unsigned int exception_number;
  exception_status_t status;
  exception_context_t* context;
  char* exception_description;
} exception_t;

extern exception_t _EXCEPTION;

extern exception_t CAUGHT_EXCEPTION;
extern exception_context_t CAUGHT_EXCEPTION_CONTEXT;
# 54 "src/memory/../oop/exception.h"
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;


extern BOOL _ERRORB;
extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);
# 87 "src/memory/../oop/exception.h"
void* __raise_exception__(exception_t* exception);
# 100 "src/memory/../oop/exception.h"
void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...);
# 122 "src/memory/../oop/exception.h"
void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, void(*callback)());
# 7 "src/memory/dyn_alloc.h" 2
       
# 72 "src/memory/dyn_alloc.h"
typedef void*(*generic_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

void* __CALL_FUNCTION__(generic_function_t, void*);
void* __CALL_FUNCTION_N_ARGS__(generic_function_t, ... );





typedef struct __SCOPE_STACK__ {
  size_t capacity;
  size_t size;
  generic_function_t* actions;
  void** instances;
  void*** args;
  char* masks;
} __SCOPE_STACK__;

typedef struct __SCOPE_DEFER_CHUNK__ {
  long bias_sum;
  size_t min_indentation;
  size_t capacity;
  size_t size;
  generic_function_t* predicates;
  void*** predicate_args;
  generic_function_t* actions;
  void** instances;
  void*** args;
} __SCOPE_DEFER_CHUNK__;



typedef struct __SCOPE_DEFER_POOL__ {
  unsigned int chunk_bias_pos;
  unsigned int chunk_bias_neg;
  size_t active_size;
  size_t size;
  size_t capacity;
  size_t tokens;
  size_t indentation;
  void* tree_root;
  __SCOPE_DEFER_CHUNK__* chunks;
} __SCOPE_DEFER_POOL__;







void* __scope_stack_init__(__SCOPE_STACK__* stack);
size_t __scope_stack_destroy__(__SCOPE_STACK__* stack);
size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance,
  void** args);
size_t __scope_stack_pop__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack);
void* __scope_stack_top__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  generic_function_t predicate);
size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack);
size_t __scope_stack_find__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_find_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_skip__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);







void* __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args,
  size_t indentation);
size_t __scope_defer_chunk_find__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_skip__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk);
# 199 "src/memory/dyn_alloc.h"
void* __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_enter__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_escape__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_add_token__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_skip__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_force__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_find__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
# 228 "src/memory/dyn_alloc.h"
typedef struct __SCOPE_OBJECT__ {
  __SCOPE_STACK__* stack;
  __SCOPE_DEFER_POOL__* defer_pool;
  size_t size;
  size_t mask;
} __SCOPE_OBJECT__;

void* __scope_object_init__(__SCOPE_OBJECT__* scope,
  __SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope);
size_t __scope_object_enter__(__SCOPE_OBJECT__* scope);
size_t __scope_object_escape__(__SCOPE_OBJECT__* scope);
size_t __scope_object_change_bias__(__SCOPE_OBJECT__* scope,
  size_t bias_positive,
  size_t bias_negative);
size_t __scope_object_lock_pool__(__SCOPE_OBJECT__* scope);
size_t __scope_object_push__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_stage__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_defer__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  generic_function_t predicate,
  ...);
size_t __scope_object_skip__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);
size_t __scope_object_force__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);


extern __SCOPE_STACK__ __SCOPE_STACK_INST__;
extern __SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__;
extern __SCOPE_OBJECT__ __SCOPE_OBJECT_INST__;

void* __SCOPE_BEGIN__(__SCOPE_OBJECT__* scope,
  __SCOPE_DEFER_POOL__* pool,
  __SCOPE_STACK__* stack);

void* __SCOPE_END__(__SCOPE_OBJECT__* scope);

void* __SCOPE_CALLOC__(__SCOPE_OBJECT__* scope,
  size_t size,
  size_t type_size,
  void* filler,
  ...);

void* __SCOPE_FREE__(__SCOPE_OBJECT__* scope, void* data);

void* __SCOPE_FORCED_RELEASE__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

void* __SCOPE_SKIP__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

__SCOPE_OBJECT__* __LOCAL_SCOPE_NEW__();

void* __LOCAL_SCOPE_FREE__(__SCOPE_OBJECT__* local_scope);

void* __DEFAULT_PREDICATE__(void* instance, ...);

void* __TRUE_PREDICATE__(void* instance, ...);

void* __FALSE_PREDICATE__(void* instance, ...);
# 2 "src/memory/dyn_alloc.c" 2

typedef struct __DEFER_POOL_NODE__
{
  void* instance;
  generic_function_t action;
} __DEFER_POOL_NODE__;

static char __compare_defer_pool_node__(__DEFER_POOL_NODE__ a, __DEFER_POOL_NODE__ b) {
  if (!a.action || !b.action) {
    return a.instance < b.instance;
  }
  if (!a.instance || !b.instance) {
    return a.action < b.action;
  }
  return (a.instance < b.instance) || ((a.instance == b.instance) && (a.action < b.action));
}




# 1 "src/memory/../algorithm/rb_tree.h" 1
# 13 "src/memory/../algorithm/rb_tree.h"
# 1 "src/memory/../algorithm/../oop/templates.h" 1
# 14 "src/memory/../algorithm/rb_tree.h" 2
# 25 "src/memory/../algorithm/rb_tree.h"
char areKeysEqual_defer_pool_tree___compare_defer_pool_node__(__DEFER_POOL_NODE__ keyA, __DEFER_POOL_NODE__ keyB) {
  return !(__compare_defer_pool_node__(keyA, keyB) || __compare_defer_pool_node__(keyB, keyA));
}


typedef enum { __RB_TREE_RED__, __RB_TREE_BLACK__ } __RB_TREE_COLOR_T__;

typedef struct RBNode {
  __DEFER_POOL_NODE__ key;
  void* data;
  __RB_TREE_COLOR_T__ color;
  struct RBNode* left, *right, *parent;
} RBNode;

RBNode* createNode_defer_pool_tree(__DEFER_POOL_NODE__ key, void* data) {
  RBNode* node = (RBNode*)malloc(sizeof(RBNode));
  node->key = key;
  node->data = data;
  node->color = __RB_TREE_RED__;
  node->left = node->right = node->parent = 
# 44 "src/memory/../algorithm/rb_tree.h" 3 4
                                           ((void *)0)
# 44 "src/memory/../algorithm/rb_tree.h"
                                               ;
  return node;
}

void leftRotate_defer_pool_tree(RBNode **root, RBNode *x) {
  RBNode* y = x->right;
  x->right = y->left;
  if (y->left) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (!x->parent) {
    *root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void rightRotate_defer_pool_tree(RBNode **root, RBNode *y) {
  RBNode *x = y->left;
  y->left = x->right;
  if (x->right) {
    x->right->parent = y;
  }
  x->parent = y->parent;
  if (!y->parent) {
    *root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }
  x->right = y;
  y->parent = x;
}

void insertFixup_defer_pool_tree(RBNode **root, RBNode *z) {
  while (z->parent && z->parent->color == __RB_TREE_RED__) {
    if (z->parent == z->parent->parent->left) {
      RBNode *y = z->parent->parent->right;
      if (y && y->color == __RB_TREE_RED__) {
        z->parent->color = __RB_TREE_BLACK__;
        y->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          leftRotate_defer_pool_tree(root, z);
        }
        z->parent->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        rightRotate_defer_pool_tree(root, z->parent->parent);
      }
    } else {
      RBNode *y = z->parent->parent->left;
      if (y && y->color == __RB_TREE_RED__) {
        z->parent->color = __RB_TREE_BLACK__;
        y->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          rightRotate_defer_pool_tree(root, z);
        }
        z->parent->color = __RB_TREE_BLACK__;
        z->parent->parent->color = __RB_TREE_RED__;
        leftRotate_defer_pool_tree(root, z->parent->parent);
      }
    }
  }
  (*root)->color = __RB_TREE_BLACK__;
}

void rbInsert_defer_pool_tree(__DEFER_POOL_NODE__ key, void* data, RBNode** root) {
  RBNode *z = createNode_defer_pool_tree(key, data);
  RBNode *y = 
# 125 "src/memory/../algorithm/rb_tree.h" 3 4
             ((void *)0)
# 125 "src/memory/../algorithm/rb_tree.h"
                 ;
  RBNode *x = *root;

  while (x) {
    y = x;
    if (__compare_defer_pool_node__(z->key, x->key)) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (!y) {
    *root = z;
  } else if (__compare_defer_pool_node__(z->key, y->key)) {
    y->left = z;
  } else {
    y->right = z;
  }
  insertFixup_defer_pool_tree(root, z);
}

RBNode* rbFind_defer_pool_tree(__DEFER_POOL_NODE__ key, RBNode** root) {
  RBNode* node = *root;
  while (node) {
    if (areKeysEqual_defer_pool_tree___compare_defer_pool_node__(key, node->key)) {
      return node;
    } else if (__compare_defer_pool_node__(key, node->key)) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return 
# 158 "src/memory/../algorithm/rb_tree.h" 3 4
        ((void *)0)
# 158 "src/memory/../algorithm/rb_tree.h"
            ;
}

RBNode* treeMinimum_defer_pool_tree(RBNode* node) {
  while (node->left) {
    node = node->left;
  }
  return node;
}

void transplant_defer_pool_tree(RBNode **root, RBNode *u, RBNode *v) {
  if (!u->parent) {
    *root = v;
  } else if (u == u->parent->left) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }
  if (v) {
    v->parent = u->parent;
  }
}

void deleteFixup_defer_pool_tree(RBNode **root, RBNode *x, RBNode *xParent) {
  while (x != *root && (!x || x->color == __RB_TREE_BLACK__)) {
    if (x == xParent->left) {
      RBNode *w = xParent->right;
      if (w && w->color == __RB_TREE_RED__) {
        w->color = __RB_TREE_BLACK__;
        xParent->color = __RB_TREE_RED__;
        leftRotate_defer_pool_tree(root, xParent);
        w = xParent->right;
      }
      if ((!w->left || w->left->color == __RB_TREE_BLACK__) &&
        (!w->right || w->right->color == __RB_TREE_BLACK__)) {
        if (w) {
          w->color = __RB_TREE_RED__;
        }
        x = xParent;
        xParent = x->parent;
      } else {
        if (!w->right || w->right->color == __RB_TREE_BLACK__) {
          if (w->left) {
            w->left->color = __RB_TREE_BLACK__;
          }
          if (w) {
            w->color = __RB_TREE_RED__;
          }
          rightRotate_defer_pool_tree(root, w);
          w = xParent->right;
        }
        if (w) {
          w->color = xParent->color;
        }
        xParent->color = __RB_TREE_BLACK__;
        if (w && w->right) {
          w->right->color = __RB_TREE_BLACK__;
        }
        leftRotate_defer_pool_tree(root, xParent);
        x = *root;
      }
    } else {
      RBNode *w = xParent->left;
      if (w && w->color == __RB_TREE_RED__) {
        w->color = __RB_TREE_BLACK__;
        xParent->color = __RB_TREE_RED__;
        rightRotate_defer_pool_tree(root, xParent);
        w = xParent->left;
      }
      if ((!w->right || w->right->color == __RB_TREE_BLACK__) &&
        (!w->left || w->left->color == __RB_TREE_BLACK__)) {
        if (w) {
          w->color = __RB_TREE_RED__;
        }
        x = xParent;
        xParent = x->parent;
      } else {
        if (!w->left || w->left->color == __RB_TREE_BLACK__) {
          if (w->right) {
            w->right->color = __RB_TREE_BLACK__;
          }
          if (w) {
            w->color = __RB_TREE_RED__;
          }
          leftRotate_defer_pool_tree(root, w);
          w = xParent->left;
        }
        if (w) {
          w->color = xParent->color;
        }
        xParent->color = __RB_TREE_BLACK__;
        if (w && w->left) {
          w->left->color = __RB_TREE_BLACK__;
        }
        rightRotate_defer_pool_tree(root, xParent);
        x = *root;
      }
    }
  }
  if (x) {
    x->color = __RB_TREE_BLACK__;
  }
}

void rbDelete_defer_pool_tree(__DEFER_POOL_NODE__ key, RBNode** root) {
  RBNode *z = rbFind_defer_pool_tree(key, root);
  if (!z) {
    return;
  }
  RBNode *y = z;
  RBNode *x;
  RBNode *xParent;
  __RB_TREE_COLOR_T__ yOriginalColor = y->color;
  if (!z->left) {
    x = z->right;
    xParent = z->parent;
    transplant_defer_pool_tree(root, z, z->right);
  } else if (!z->right) {
    x = z->left;
    xParent = z->parent;
    transplant_defer_pool_tree(root, z, z->left);
  } else {
    y = treeMinimum_defer_pool_tree(z->right);
    yOriginalColor = y->color;
    x = y->right;
    if (y->parent == z) {
      xParent = y;
    }
    else {
      transplant_defer_pool_tree(root, y, y->right);
      y->right = z->right;
      if (y->right) {
        y->right->parent = y;
      }
      xParent = y->parent;
    }
    transplant_defer_pool_tree(root, z, y);
    y->left = z->left;
    if (y->left) {
      y->left->parent = y;
    }
    y->color = z->color;
  }
  free(z);
  if (yOriginalColor == __RB_TREE_BLACK__) {
    deleteFixup_defer_pool_tree(root, x, xParent);
  }
}

void inorderHelper_defer_pool_tree(RBNode *node) {
  if (node) {
    inorderHelper_defer_pool_tree(node->left);
    printf("%d(%s) ", node->key, node->color == __RB_TREE_RED__ ? "R" : "B");
    inorderHelper_defer_pool_tree(node->right);
  }
}

void inorder_defer_pool_tree(RBNode** root) {
  inorderHelper_defer_pool_tree(*root);
  printf("\n");
}

void freeTree_defer_pool_tree(RBNode* node) {
  if (node) {
    freeTree_defer_pool_tree(node->left);
    freeTree_defer_pool_tree(node->right);
    free(node);
  }
}

# 1 "src/memory/../algorithm/../oop/templates_undef.h" 1
# 329 "src/memory/../algorithm/rb_tree.h" 2
# 23 "src/memory/dyn_alloc.c" 2



static char* __scope_stack_mask_set_active__(char* mask, BOOL state) {
  *mask = *mask & ((0x7f * 2 + 1) - 1);
  *mask |= state;
  return mask;
}

static BOOL __scope_stack_mask_get_active__(char* mask) {
  return *mask & 1;
}

static BOOL __scope_stack_special_call_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) || (action == 0);
}

static BOOL __scope_stack_regular_predicate__(void* instance, generic_function_t action) {
  return ((size_t)instance > 0) && ((size_t)action > 0);
}

static BOOL __scope_stack_indentation_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) && (action == 0);
}

static BOOL __scope_stack_skip_predicate__(void* instance, generic_function_t action) {
  return ((size_t)instance > 0) && (action == 0);
}

static BOOL __scope_stack_callable_predicate__(void* instance, generic_function_t action) {
  return (instance == 0) && ((size_t)action > 0);
}


void* __CALL_ACTION_N_ARGS__(generic_function_t action,
                             void* instance,
                             void** args) {
  if (__scope_stack_indentation_predicate__(instance, action)) {
    return 
# 61 "src/memory/dyn_alloc.c" 3 4
          ((void *)0)
# 61 "src/memory/dyn_alloc.c"
              ;
  }
  if (!args) {
    if (action) {
      return action(instance, 0);
    } else {
      return ((generic_function_t)instance)(0);
    }
  }

  if (__scope_stack_indentation_predicate__(instance, action)) {
    free(args);
    return 
# 73 "src/memory/dyn_alloc.c" 3 4
          ((void *)0)
# 73 "src/memory/dyn_alloc.c"
              ;
  }

  size_t arg_size = 0;

  while (args[arg_size++]) {};

  void* result;
  switch (arg_size) {
  case 2:
    result = action(instance,
                    args[0],
                    0);
    break;
  case 3:
    result = action(instance, args[0], args[1], 0);
    break;
  case 4:
    result = action(instance, args[0], args[1], args[2], 0);
    break;
  case 5:
    result = action(instance, args[0], args[1], args[2], args[3], 0);
    break;
  case 6:
    result = action(instance, args[0], args[1], args[2], args[3], args[4], 0);
    break;
  case 7:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], 0);
    break;
  case 8:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], 0);
    break;
  case 9:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], 0);
    break;
  case 10:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], 0);
    break;
  case 11:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], 0);
    break;
  case 12:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10], 0);
    break;
  case 13:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], 0);
    break;
  case 14:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], args[12], 0);
    break;
  case 15:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], args[12], args[13], 0);
    break;
  case 16:
    result = action(instance, args[0], args[1], args[2], args[3], args[4],
                    args[5], args[6], args[7], args[8], args[9], args[10],
                    args[11], args[12], args[13], args[14], 0);
    break;
  default:
    result = action(instance, args);
    break;
  }
  free(args);
  return result;
}


static void* __CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(generic_function_t predicate,
                                             void* instance,
                                             generic_function_t action,
                                             void** args) {

  if (__scope_stack_indentation_predicate__(instance, action)) {
    return (void*)TRUE;
  }

  if (args == 0) {
    return predicate(instance, action);
  }

  size_t arg_size = 0;

  while (args[arg_size++]) {};

  void* result;
  switch (arg_size) {
  case 2:
    result = predicate(instance, action, args[0], 0);
    break;
  case 3:
    result = predicate(instance, action, args[0], args[1], 0);
    break;
  case 4:
    result = predicate(instance, action, args[0], args[1], args[2], 0);
    break;
  case 5:
    result = predicate(instance, action, args[0], args[1], args[2], args[3], 0);
    break;
  case 6:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], 0);
    break;
  case 7:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], 0);
    break;
  case 8:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], 0);
    break;
  case 9:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], 0);
    break;
  case 10:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], 0);
    break;
  case 11:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9], 0);
    break;
  case 12:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], 0);
    break;
  case 13:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], 0);
    break;
  case 14:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], args[12], 0);
    break;
  case 15:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], args[12], args[13], 0);
    break;
  case 16:
    result = predicate(instance, action, args[0], args[1], args[2], args[3],
                       args[4], args[5], args[6], args[7], args[8], args[9],
                       args[10], args[11], args[12], args[13], args[14], 0);
    break;
  default:
    result = predicate(instance, action, args);
    break;
  }
  return result;
}


static size_t __scope_stack_reserve__(__SCOPE_STACK__* stack, size_t capacity) {
  generic_function_t* tmp_actions = stack->actions;
  void** tmp_instances = stack->instances;
  void*** tmp_args = stack->args;
  char* tmp_masks = stack->masks;
  stack->actions = (generic_function_t*)malloc(sizeof(generic_function_t) * capacity);
  stack->instances = (void**)malloc(sizeof(void*) * capacity);
  stack->args = (void***)malloc(sizeof(void**) * capacity);
  stack->masks = (char*)malloc(capacity);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 249 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 249 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 249 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 249 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  if (stack->capacity) {
    memcpy(stack->actions,
      tmp_actions,
      sizeof(generic_function_t) * (stack->size < capacity ? stack->size : capacity));
    memcpy(stack->instances,
      tmp_instances,
      sizeof(void*) * (stack->size < capacity ? stack->size : capacity));
    memcpy(stack->args,
      tmp_args,
      sizeof(void**) * (stack->size < capacity ? stack->size : capacity));
    memcpy(stack->masks,
      tmp_masks,
      sizeof(char) * (stack->size < capacity ? stack->size : capacity));
    for (size_t i = (stack->size < capacity ? stack->size : capacity); i < stack->size; ++i) {
      __CALL_ACTION_N_ARGS__(tmp_actions[i],
                             tmp_instances[i],
                             tmp_args[i]);
    }
    free(tmp_actions);
    free(tmp_instances);
    free(tmp_masks);
    free(tmp_args);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 272 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 272 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 272 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 272 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  stack->capacity = capacity;
  stack->size = (stack->size < capacity ? stack->size : capacity);
  return stack->size;
}

void* __scope_stack_init__(__SCOPE_STACK__* stack) {
  stack->capacity = 0;
  stack->size = 0;
  __scope_stack_reserve__(stack, 8);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 283 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 283 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 283 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 283 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  __scope_stack_push__(stack, 
# 284 "src/memory/dyn_alloc.c" 3 4
                             ((void *)0)
# 284 "src/memory/dyn_alloc.c"
                                 , 
# 284 "src/memory/dyn_alloc.c" 3 4
                                   ((void *)0)
# 284 "src/memory/dyn_alloc.c"
                                       , 
# 284 "src/memory/dyn_alloc.c" 3 4
                                         ((void *)0)
# 284 "src/memory/dyn_alloc.c"
                                             );
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 285 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 285 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 285 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 285 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return stack;
}

size_t __scope_stack_destroy__(__SCOPE_STACK__* stack) {
  if (stack->capacity) {
    for (size_t i = stack->size; i > 0; --i) {
      if (!__scope_stack_indentation_predicate__(stack->instances[i - 1],
        stack->actions[i - 1])) {
        __CALL_ACTION_N_ARGS__(stack->actions[i - 1],
                               stack->instances[i - 1],
                               stack->args[i - 1]);
      }
    }
    free(stack->actions);
    free(stack->instances);
    free(stack->masks);
    free(stack->args);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 303 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 303 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 303 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 303 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  *stack = (__SCOPE_STACK__){};
  return 0;
}

size_t __scope_stack_push__(__SCOPE_STACK__* stack,
                            generic_function_t action,
                            void* instance,
                            void** args) {
  if (stack->size + 1 == stack->capacity) {
    __scope_stack_reserve__(stack, stack->capacity * 2);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 315 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 315 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 315 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 315 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  stack->actions[stack->size] = action;
  stack->instances[stack->size] = instance;
  stack->args[stack->size] = args;
  stack->masks[stack->size] = !__scope_stack_indentation_predicate__(instance, action);
  stack->size++;
  return stack->size;
}

size_t __scope_stack_pop__(__SCOPE_STACK__* stack) {
  stack->size--;
  if (__scope_stack_mask_get_active__(stack->masks + stack->size)) {
    __CALL_ACTION_N_ARGS__(stack->actions[stack->size],
      stack->instances[stack->size],
      stack->args[stack->size]);
  }
  if ((4 * stack->size < stack->capacity) &&
    (2 * stack->size > 8)) {
    __scope_stack_reserve__(stack, stack->capacity / 2);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 335 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 335 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 335 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 335 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  return stack->size;
}

size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack) {
  size_t count_releases = 0;
  while (!__scope_stack_indentation_predicate__(stack->instances[stack->size - 1],
         stack->actions[stack->size - 1])) {
    if (stack->masks[stack->size - 1]) {
      count_releases++;
    }
    __scope_stack_pop__(stack);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 348 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 348 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 348 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 348 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  __scope_stack_pop__(stack);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 351 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 351 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 351 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 351 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  return count_releases;
}

size_t __scope_stack_find__(__SCOPE_STACK__* stack,
                            generic_function_t action,
                            void* instance) {
  size_t i = stack->size;
  while (stack->instances[i - 1] != instance &&
    stack->actions[i - 1] != action &&
    __scope_stack_mask_get_active__(stack->masks + i)) {
    i--;
    if (i == 0) {
      return 0;
    }
  }
  return i - 1;
}

size_t __scope_stack_find_action__(__SCOPE_STACK__* stack, generic_function_t action) {
  size_t i = stack->size;
  while (stack->actions[i - 1] != action &&
    __scope_stack_mask_get_active__(stack->masks + i)) {
    i--;
    if (i == 0) {
      return 0;
    }
  }
  return i - 1;
}

size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack, void* instance) {
  size_t i = stack->size;
  while (stack->instances[i - 1] != instance &&
    __scope_stack_mask_get_active__(stack->masks + i)) {
    i--;
    if (i == 0) {
      return 0;
    }
  }
  return i - 1;
}

size_t __scope_stack_skip__(__SCOPE_STACK__* stack,
                            generic_function_t action,
                            void* instance) {
  size_t i = __scope_stack_find__(stack, action, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack, generic_function_t action) {
  size_t i = __scope_stack_find_action__(stack, action);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack, void* instance) {
  size_t i = __scope_stack_find_instance__(stack, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  return stack->size;
}

size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
                             __SCOPE_DEFER_POOL__* defer_pool,
                             generic_function_t action,
                             void* instance,
                             generic_function_t predicate,
                             void** predicate_args) {
  size_t i = __scope_stack_find__(stack, action, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(predicate,
                                             stack->instances[i],
                                             stack->actions[i],
                                             predicate_args)) {
    __CALL_ACTION_N_ARGS__(stack->actions[i],
                           stack->instances[i],
                           stack->args[i]);
    return 0;
  }
  __scope_defer_pool_push__(defer_pool,
    action,
    instance,
    stack->args[i],
    predicate,
    predicate_args);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 437 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 437 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 437 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 437 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  return stack->size;
}

size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
                                    __SCOPE_DEFER_POOL__* defer_pool,
                                    generic_function_t action,
                                    generic_function_t predicate,
                                    void** predicate_args) {
  size_t i = __scope_stack_find_action__(stack, action);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(predicate,
                                             stack->instances[i],
                                             stack->actions[i],
                                             predicate_args)) {
    if (i == stack->size - 1) {
      __scope_stack_pop__(stack);
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 454 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 454 "src/memory/dyn_alloc.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 454 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 454 "src/memory/dyn_alloc.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
    }
    __CALL_ACTION_N_ARGS__(stack->actions[i],
                           stack->instances[i],
                           stack->args[i]);
    return 0;
  }
  __scope_defer_pool_push__(defer_pool,
    action,
    stack->instances[i],
    stack->args[i],
    predicate,
    predicate_args);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 467 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 467 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 467 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 467 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  if (i == stack->size - 1) {
    __scope_stack_pop__(stack);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 470 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 470 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 470 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 470 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  return stack->size;
}

size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
                                      __SCOPE_DEFER_POOL__* defer_pool,
                                      void* instance,
                                      generic_function_t predicate,
                                      void** predicate_args) {
  size_t i = __scope_stack_find_instance__(stack, instance);
  __scope_stack_mask_set_active__(&(stack->masks[i]), 0);
  if (i == stack->size - 1) {
    stack->size--;
  }
  if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(predicate,
                                             stack->instances[i],
                                             stack->actions[i],
                                             predicate_args)) {
    __CALL_ACTION_N_ARGS__(stack->actions[i],
                           stack->instances[i],
                           stack->args[i]);
    return 0;
  }
  __scope_defer_pool_push__(defer_pool,
    stack->actions[i],
    instance,
    stack->args[i],
    predicate,
    predicate_args);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 500 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 500 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 500 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 500 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  return stack->size;
}

void* __scope_stack_top__(__SCOPE_STACK__* stack) {
  return stack->instances[stack->size - 1];
}

size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack, generic_function_t predicate) {
  while (!predicate(stack->instances[stack->size - 1],
      stack->actions[stack->size - 1],
      stack,
    0)) {
    __scope_stack_pop__(stack);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 514 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 514 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 514 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 514 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  return stack->size;
}

size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack) {
  while (!__scope_stack_pop__(stack)) {
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 521 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 521 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 521 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 521 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  };
}


static size_t __scope_defer_chunk_reserve__(__SCOPE_DEFER_CHUNK__* chunk, size_t capacity) {
  generic_function_t* tmp_predicates = chunk->predicates;
  generic_function_t* tmp_actions = chunk->actions;
  void** tmp_instances = chunk->instances;
  void*** tmp_args = chunk->args;
  void*** tmp_predicate_args = chunk->predicate_args;
  chunk->predicates = (generic_function_t*)calloc(capacity, sizeof(generic_function_t));
  chunk->actions = (generic_function_t*)calloc(capacity, sizeof(generic_function_t));
  chunk->instances = (void**)calloc(capacity, sizeof(void*));
  chunk->args = (void***)calloc(capacity, sizeof(void**));
  chunk->predicate_args = (void***)calloc(capacity, sizeof(void**));
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 537 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 537 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 537 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 537 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  if (chunk->capacity) {
    memcpy(chunk->predicates,
      tmp_predicates,
      sizeof(generic_function_t) * (chunk->size < capacity ? chunk->size : capacity));
    memcpy(chunk->actions,
      tmp_actions,
      sizeof(generic_function_t) * (chunk->size < capacity ? chunk->size : capacity));
    memcpy(chunk->instances,
      tmp_instances,
      sizeof(void*) * (chunk->size < capacity ? chunk->size : capacity));
    memcpy(chunk->args,
      tmp_args,
      sizeof(void**) * (chunk->size < capacity ? chunk->size : capacity));
    memcpy(chunk->predicate_args,
      tmp_predicate_args,
      sizeof(void**) * (chunk->size < capacity ? chunk->size : capacity));
    for (size_t i = (chunk->size < capacity ? chunk->size : capacity); i < chunk->size; ++i) {
      __CALL_ACTION_N_ARGS__(chunk->actions[i],
                             chunk->instances[i],
                             chunk->args[i]);
    }
    free(tmp_predicates);
    free(tmp_actions);
    free(tmp_instances);
    free(tmp_args);
    free(tmp_predicate_args);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 564 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 564 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 564 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 564 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  chunk->capacity = capacity;
  chunk->size = (chunk->size < capacity ? chunk->size : capacity);
  return chunk->size;
}

void* __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk) {
  chunk->capacity = 0;
  chunk->size = 0;
  chunk->bias_sum = 0;
  chunk->min_indentation = 0xffffffffffffffffUL;
  __scope_defer_chunk_reserve__(chunk, 8);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 577 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 577 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 577 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 577 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return chunk;
}

size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk) {
  if (chunk->capacity) {
    for (size_t i = 0; i < chunk->size; ++i) {
      __CALL_ACTION_N_ARGS__(chunk->actions[i], chunk->instances[i], chunk->args[i]);
    }
  }
  free(chunk->predicates);
  free(chunk->actions);
  free(chunk->instances);
  free(chunk->args);
  free(chunk->predicate_args);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 592 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 592 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 592 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 592 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  *chunk = (__SCOPE_DEFER_CHUNK__){};
  return 0;
}





# 1 "src/memory/../oop/templates.h" 1
# 602 "src/memory/dyn_alloc.c" 2

size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
                                  generic_function_t action,
                                  void* instance,
                                  void** args,
                                  generic_function_t predicate,
                                  void** predicate_args,
                                  size_t indentation) {
  if (chunk->size + 1 == chunk->capacity) {
    __scope_defer_chunk_reserve__(chunk, 2 * chunk->capacity);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 612 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 612 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 612 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 612 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  chunk->bias_sum += 1;
  chunk->min_indentation = (chunk->min_indentation < indentation ? chunk->min_indentation : indentation);
  chunk->actions[chunk->size] = action;
  chunk->instances[chunk->size] = instance;
  chunk->predicates[chunk->size] = predicate;
  chunk->args[chunk->size] = args;
  chunk->predicate_args[chunk->size] = predicate_args;
  return ++chunk->size;
}

size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
                                   __SCOPE_DEFER_POOL__* pool) {
  for (size_t i = chunk->size; i > 0; --i) {
    if (__CHECK_DEFER_CHUNK_PREDICATE_N_ARGS__(chunk->predicates[i - 1],
                                               chunk->instances[i - 1],
                                               chunk->actions[i - 1],
                                               chunk->predicate_args[i - 1])) {
      chunk->bias_sum += pool->chunk_bias_pos;
      __CALL_ACTION_N_ARGS__(chunk->actions[i - 1],
                             chunk->instances[i - 1],
                             chunk->args[i - 1]);
      free(chunk->predicate_args[i - 1]);
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 636 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 636 "src/memory/dyn_alloc.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 636 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 636 "src/memory/dyn_alloc.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
      chunk->size--;
      RBNode* root = (RBNode*)pool->tree_root;
      rbDelete_defer_pool_tree((__DEFER_POOL_NODE__){.action=chunk->actions[i - 1],
                                            .instance=chunk->instances[i - 1]},
                                          &root);
      pool->tree_root = (void*)root;
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 643 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 643 "src/memory/dyn_alloc.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 643 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 643 "src/memory/dyn_alloc.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
      chunk->actions[i - 1] = chunk->actions[chunk->size];
      chunk->instances[i - 1] = chunk->instances[chunk->size];
      chunk->predicates[i - 1] = chunk->predicates[chunk->size];
      chunk->args[i - 1] = chunk->args[chunk->size];
      chunk->predicate_args[i - 1] = chunk->predicate_args[chunk->size];
    } else {
      chunk->bias_sum -= pool->chunk_bias_neg;
    }
  }
  return chunk->size;
}

size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk) {
  return chunk->bias_sum;
}

size_t __scope_defer_chunk_find__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance) {
  for (size_t i = chunk->size; i > 0; --i) {
    if (action && (action == chunk->actions[i - 1])) {
      if (instance && (instance == chunk->instances[i - 1])) {
        return i - 1;
      } else if (!instance) {
        return i - 1;
      }
    } else if (!action && (instance == chunk->instances[i - 1])) {
      return i - 1;
    }
  }
  return (size_t)((void*)-1);
}

size_t __scope_defer_chunk_skip__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance) {
  size_t index = __scope_defer_chunk_find__(chunk, action, instance);
  if (index > chunk->size) {
    return (size_t)((void*)-1);
  }
  chunk->size--;
  if (chunk->size > 0) {
    chunk->actions[index] = chunk->actions[chunk->size];
    chunk->instances[index] = chunk->instances[chunk->size];
    chunk->args[index] = chunk->args[chunk->size];
    chunk->predicates[index] = chunk->predicates[chunk->size];
    chunk->predicate_args[index] = chunk->predicate_args[chunk->size];
  }
  return chunk->size;
}


static size_t __scope_defer_pool_reserve__(__SCOPE_DEFER_POOL__* pool, size_t capacity) {
  __SCOPE_DEFER_CHUNK__* tmp_chunks = pool->chunks;
  pool->chunks = (__SCOPE_DEFER_CHUNK__*)calloc(capacity, sizeof(__SCOPE_DEFER_CHUNK__));
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 699 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 699 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 699 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 699 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  if (pool->capacity) {
    size_t index_shift = 0;
    for (size_t i = 0; i < pool->capacity; ++i) {
      if (!(tmp_chunks[i].size && i < pool->size)) {
        __scope_defer_chunk_destroy__(&(tmp_chunks[i]));
        if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 705 "src/memory/dyn_alloc.c" 3 4
       (*__errno_location ())
# 705 "src/memory/dyn_alloc.c"
       )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 705 "src/memory/dyn_alloc.c" 3 4
       (*__errno_location ())
# 705 "src/memory/dyn_alloc.c"
       ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
        index_shift++;
      } else {
        pool->chunks[i - index_shift] = tmp_chunks[i];
      }
    }
    free(tmp_chunks);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 712 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 712 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 712 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 712 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  pool->capacity = capacity;
  pool->size = (pool->size < capacity ? pool->size : capacity);
  return pool->size;
}

void* __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool) {
  pool->active_size = 0;
  pool->size = 0;
  pool->capacity = 0;
  pool->chunk_bias_neg = 1;
  pool->chunk_bias_pos = 4;
  pool->indentation = 0;
  pool->tokens = 0;
  pool->tree_root = 
# 727 "src/memory/dyn_alloc.c" 3 4
                   ((void *)0)
# 727 "src/memory/dyn_alloc.c"
                       ;
  __scope_defer_pool_reserve__(pool, 2);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 729 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 729 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 729 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 729 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return pool;
}

size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool) {
  for (size_t i = 0; i < pool->size; ++i) {
    __scope_defer_chunk_destroy__(&(pool->chunks[i]));
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 736 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 736 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 736 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 736 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  free(pool->chunks);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 739 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 739 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 739 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 739 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  freeTree_defer_pool_tree((RBNode*)pool->tree_root);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 741 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 741 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 741 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 741 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  *pool = (__SCOPE_DEFER_POOL__){};
  return 0;
}

size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
                                 generic_function_t action,
                                 void* instance,
                                 void** args,
                                 generic_function_t predicate,
                                 void** predicate_args) {
  if (pool->indentation < pool->size) {
    __scope_defer_chunk_push__(&(pool->chunks[pool->indentation]),
                               action,
                               instance,
                               args,
                               predicate,
                               predicate_args,
                               pool->indentation);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 760 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 760 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 760 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 760 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
    RBNode* root = (RBNode*)pool->tree_root;
    rbInsert_defer_pool_tree((__DEFER_POOL_NODE__){.action = action, .instance=instance},
                                        (void*)pool->indentation, &root);
    pool->tree_root = (void*)root;
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 765 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 765 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 765 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 765 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  } else {
    if (pool->size + 1 == pool->capacity) {
      __scope_defer_pool_reserve__(pool, pool->capacity * 2);
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 769 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 769 "src/memory/dyn_alloc.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 769 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 769 "src/memory/dyn_alloc.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
    }
    __scope_defer_chunk_init__(&(pool->chunks[pool->size]));
    __scope_defer_chunk_push__(&(pool->chunks[pool->size]),
                               action,
                               instance,
                               args,
                               predicate,
                               predicate_args,
                               pool->indentation);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 779 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 779 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 779 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 779 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
    RBNode* root = (RBNode*)pool->tree_root;
    rbInsert_defer_pool_tree((__DEFER_POOL_NODE__){.action = action, .instance=instance},
                                        (void*)pool->size, &root);
    pool->tree_root = (void*)root;
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 784 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 784 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 784 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 784 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
    pool->size++;
    pool->active_size++;
  }
  return pool->size;
}

size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool) {
  size_t count_releases = 0;
  size_t tmp_size;
  for(size_t i = pool->size; (pool->tokens > 0) && (i > 0) &&
      (pool->chunks[i - 1].min_indentation >= pool->indentation - 1); --i) {
    if (pool->chunks[i - 1].bias_sum >= 0) {
      pool->tokens = (pool->tokens - pool->chunks[i - 1].size < 0 ? pool->tokens - pool->chunks[i - 1].size : 0);
      tmp_size = pool->chunks[i - 1].size;
      count_releases += tmp_size - __scope_defer_chunk_check__(&(pool->chunks[i - 1]),
                                                               pool);
      pool->chunks[i - 1].bias_sum /= 2;
      if (!pool->chunks[i - 1].size) {
        pool->active_size--;
      }
    } else {
      pool->chunks[i - 1].bias_sum /= 2;
      pool->chunks[i - 1].bias_sum += pool->chunk_bias_pos * (pool->tokens < pool->chunks[i - 1].size ? pool->tokens : pool->chunks[i - 1].size)
                                                                                          ;
    }
  }
  if ((pool->active_size * 4 < pool->capacity) &&
      (2 * pool->active_size > 2)) {
    __scope_defer_pool_reserve__(pool, pool->active_size * 2);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 814 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 814 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 814 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 814 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  }
  return count_releases;
}

size_t __scope_defer_pool_enter__(__SCOPE_DEFER_POOL__* pool) {
  pool->indentation++;
  return pool->size;
}

size_t __scope_defer_pool_escape__(__SCOPE_DEFER_POOL__* pool) {
  __scope_defer_pool_check__(pool);
  pool->indentation--;
  return pool->size;
}

size_t __scope_defer_pool_add_token__(__SCOPE_DEFER_POOL__* pool){
  pool->tokens++;
  return pool->size;
}

size_t __scope_defer_pool_skip__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action) {
  RBNode* root = (RBNode*)pool->tree_root;
  RBNode* node = rbFind_defer_pool_tree((__DEFER_POOL_NODE__){.action = action,.instance=instance},
                                                   &root);
  rbDelete_defer_pool_tree((__DEFER_POOL_NODE__){.action = action, .instance=instance},
                                      &root);
  pool->tree_root = (void*)root;
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 844 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 844 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 844 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 844 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  return (size_t)(node > 0);
}

size_t __scope_defer_pool_force__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action) {

  size_t chunk = __scope_defer_pool_find__(pool, instance, action);

  if (chunk >= pool->size) {
    return (size_t)((void*)-1);
  }

  size_t index = __scope_defer_chunk_find__(&(pool->chunks[chunk]), action, instance);

  if (index > pool->chunks[chunk].size) {
    return (size_t)((void*)-1);
  }

  __CALL_ACTION_N_ARGS__(pool->chunks[chunk].actions[index],
                         pool->chunks[chunk].instances[index],
                         pool->chunks[chunk].args[index]);

  RBNode* root = (RBNode*)pool->tree_root;
  rbDelete_defer_pool_tree((__DEFER_POOL_NODE__){.action = action,.instance=instance},
                                      &root);
  pool->tree_root = (void*)root;
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 872 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 872 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 872 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 872 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };

  pool->chunks[chunk].size--;
  if (!pool->chunks[chunk].size) {
    pool->active_size--;
    return (size_t)((void*)-1);
  }

  pool->chunks[chunk].actions[index] = pool->chunks[chunk].actions[pool->chunks[chunk].size];
  pool->chunks[chunk].instances[index] = pool->chunks[chunk].instances[pool->chunks[chunk].size];
  pool->chunks[chunk].args[index] = pool->chunks[chunk].args[pool->chunks[chunk].size];
  pool->chunks[chunk].predicates[index] = pool->chunks[chunk].predicates[pool->chunks[chunk].size];
  pool->chunks[chunk].predicate_args[index] = pool->chunks[chunk].predicate_args[pool->chunks[chunk].size];

  return chunk;
}

size_t __scope_defer_pool_find__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action) {
  RBNode* root = (RBNode*)pool->tree_root;
  RBNode* node = rbFind_defer_pool_tree((__DEFER_POOL_NODE__){.action = action,.instance=instance},
                                                   &root);
  pool->tree_root = (void*)root;
  if (!node) {
    return (size_t)((void*)-1);
  }
  return (size_t)node->data;
}


void* __scope_object_init__(__SCOPE_OBJECT__* scope,
                            __SCOPE_STACK__* stack,
                            __SCOPE_DEFER_POOL__* pool) {
  scope->stack = stack;
  scope->defer_pool = pool;
  scope->size = 0;
  scope->mask = 3;
  __scope_stack_init__(scope->stack);
  __scope_defer_pool_init__(scope->defer_pool);
  __scope_defer_pool_add_token__(scope->defer_pool);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 913 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 913 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 913 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 913 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return scope;
}

size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope) {
  if (!scope->stack) {
    return 0;
  }
  __scope_stack_destroy__(scope->stack);
  __scope_defer_pool_destroy__(scope->defer_pool);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 923 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 923 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 923 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 923 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  *scope = (__SCOPE_OBJECT__){};
  return 0;
}

size_t __scope_object_enter__(__SCOPE_OBJECT__* scope) {
  if (!scope->stack) {
    return 0;
  }
  __scope_stack_push__(scope->stack, 
# 932 "src/memory/dyn_alloc.c" 3 4
                                    ((void *)0)
# 932 "src/memory/dyn_alloc.c"
                                        , 
# 932 "src/memory/dyn_alloc.c" 3 4
                                          ((void *)0)
# 932 "src/memory/dyn_alloc.c"
                                              , 
# 932 "src/memory/dyn_alloc.c" 3 4
                                                ((void *)0)
# 932 "src/memory/dyn_alloc.c"
                                                    );
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 933 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 933 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 933 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 933 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  if (scope->mask) {
    __scope_defer_pool_enter__(scope->defer_pool);
  } else {
    scope->defer_pool->indentation++;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_lock_pool__(__SCOPE_OBJECT__* scope) {
  scope->mask = (scope->mask || 1) ^ 1;
  return 0;
}

size_t __scope_object_unlock_pool__(__SCOPE_OBJECT__* scope) {
  scope->mask = scope->mask || 1;
  return 0;
}

size_t __scope_object_escape__(__SCOPE_OBJECT__* scope) {
  if (!scope->stack) {
    return 0;
  }
  scope->size -= __scope_stack_pop_top__(scope->stack);
  if (scope->mask && 1) {
    scope->size -= __scope_defer_pool_escape__(scope->defer_pool);
  } else {
    scope->defer_pool->indentation--;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_push__(__SCOPE_OBJECT__* scope,
                             void* instance,
                             generic_function_t action,
                             ...) {
  if (!scope->stack) {
    return 0;
  }
  va_list __ARGUMENT_POINTERS__;
  void* __args_stack__[8] = {};
  void** args = __args_stack__;
  size_t __ARG_CNT__ = 0;
  size_t args_capacity = 8;
  {
    
# 980 "src/memory/dyn_alloc.c" 3 4
   __builtin_va_start(
# 980 "src/memory/dyn_alloc.c"
   __ARGUMENT_POINTERS__
# 980 "src/memory/dyn_alloc.c" 3 4
   ,
# 980 "src/memory/dyn_alloc.c"
   action
# 980 "src/memory/dyn_alloc.c" 3 4
   )
# 980 "src/memory/dyn_alloc.c"
                                          ;
    for (size_t i = 0;
         (i < 32) &&
         (args[i] = 
# 983 "src/memory/dyn_alloc.c" 3 4
                   __builtin_va_arg(
# 983 "src/memory/dyn_alloc.c"
                   __ARGUMENT_POINTERS__
# 983 "src/memory/dyn_alloc.c" 3 4
                   ,
# 983 "src/memory/dyn_alloc.c"
                   void*
# 983 "src/memory/dyn_alloc.c" 3 4
                   )
# 983 "src/memory/dyn_alloc.c"
                                                       );
         ++i) {
      __ARG_CNT__++;
      if (__ARG_CNT__ == args_capacity) {
        if (__ARG_CNT__ == 8) {
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 989 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 989 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 989 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 989 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
          memcpy(args, __args_stack__, args_capacity);
        } else {
          void** tmp_args = args;
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 994 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 994 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 994 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 994 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
          memcpy(args, tmp_args, args_capacity);
          free(tmp_args);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 997 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 997 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 997 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 997 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
        }
        args_capacity *= 2;
      }
    }
    
# 1002 "src/memory/dyn_alloc.c" 3 4
   __builtin_va_end(
# 1002 "src/memory/dyn_alloc.c"
   __ARGUMENT_POINTERS__
# 1002 "src/memory/dyn_alloc.c" 3 4
   )
# 1002 "src/memory/dyn_alloc.c"
                                ;
  }
  if (args_capacity == 8) {
    if (__ARG_CNT__ > 0) {
      args = (void**)malloc(sizeof(void*) * (__ARG_CNT__ + 1));
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1007 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 1007 "src/memory/dyn_alloc.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1007 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 1007 "src/memory/dyn_alloc.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
      memcpy(args, __args_stack__, args_capacity);
    } else {
      args = 0;
    }
  }
  if (args) {
    args[__ARG_CNT__] = 
# 1014 "src/memory/dyn_alloc.c" 3 4
                       ((void *)0)
# 1014 "src/memory/dyn_alloc.c"
                           ;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  __scope_stack_push__(scope->stack, action, instance, args);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1018 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1018 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1018 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1018 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  if (action || instance) {
    scope->size++;
  }
  return 0;
}


size_t __scope_object_defer__(__SCOPE_OBJECT__* scope,
                              void* instance,
                              generic_function_t action,
                              generic_function_t predicate,
                              ...) {
  if (!scope->stack) {
    return 0;
  }
  va_list __ARGUMENT_POINTERS__;
  void* __args_stack__[8] = {};
  void** args = __args_stack__;
  size_t __ARG_CNT__ = 0;
  size_t args_capacity = 8;
  {
    
# 1040 "src/memory/dyn_alloc.c" 3 4
   __builtin_va_start(
# 1040 "src/memory/dyn_alloc.c"
   __ARGUMENT_POINTERS__
# 1040 "src/memory/dyn_alloc.c" 3 4
   ,
# 1040 "src/memory/dyn_alloc.c"
   predicate
# 1040 "src/memory/dyn_alloc.c" 3 4
   )
# 1040 "src/memory/dyn_alloc.c"
                                             ;
    for (size_t i = 0;
         (i < 32) &&
         (args[i] = 
# 1043 "src/memory/dyn_alloc.c" 3 4
                   __builtin_va_arg(
# 1043 "src/memory/dyn_alloc.c"
                   __ARGUMENT_POINTERS__
# 1043 "src/memory/dyn_alloc.c" 3 4
                   ,
# 1043 "src/memory/dyn_alloc.c"
                   void*
# 1043 "src/memory/dyn_alloc.c" 3 4
                   )
# 1043 "src/memory/dyn_alloc.c"
                                                       );
         ++i) {
      __ARG_CNT__++;
      if (__ARG_CNT__ + 1 == args_capacity) {
        if (__ARG_CNT__ + 1 == 8) {
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1049 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1049 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1049 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1049 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
          memcpy(args, __args_stack__, args_capacity);
        } else {
          void** tmp_args = args;
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1054 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1054 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1054 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1054 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
          memcpy(args, tmp_args, args_capacity);
          free(tmp_args);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1057 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1057 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1057 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1057 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
        }
        args_capacity *= 2;
      }
    }
    
# 1062 "src/memory/dyn_alloc.c" 3 4
   __builtin_va_end(
# 1062 "src/memory/dyn_alloc.c"
   __ARGUMENT_POINTERS__
# 1062 "src/memory/dyn_alloc.c" 3 4
   )
# 1062 "src/memory/dyn_alloc.c"
                                ;
  }
  if (args_capacity == 8) {
    if (__ARG_CNT__ > 0) {
      args = (void**)malloc(sizeof(void*) * (__ARG_CNT__ + 1));
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1067 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 1067 "src/memory/dyn_alloc.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1067 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 1067 "src/memory/dyn_alloc.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
      memcpy(args, __args_stack__, args_capacity);
    } else {
      args = 0;
    }
  }
  if (args) {
    args[__ARG_CNT__] = 
# 1074 "src/memory/dyn_alloc.c" 3 4
                       ((void *)0)
# 1074 "src/memory/dyn_alloc.c"
                           ;
  }
  size_t result;
  if (action && instance) {
    result = __scope_stack_defer__(scope->stack,
                                   scope->defer_pool,
                                   action,
                                   instance,
                                   predicate,
                                   args);
  } else if (action) {
    result = __scope_stack_defer_action__(scope->stack,
                                          scope->defer_pool,
                                          action,
                                          predicate,
                                          args);
  } else {
    result = __scope_stack_defer_instance__(scope->stack,
                                            scope->defer_pool,
                                            instance,
                                            predicate,
                                            args);
  }
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1097 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1097 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1097 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1097 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  if (!result && scope->stack->size) {
    scope->size--;
  }
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_stage__(__SCOPE_OBJECT__* scope,
                              void* instance,
                              generic_function_t action,
                              ...) {
  if (!scope->stack) {
    return 0;
  }
  BOOL is_staged = FALSE;
  if (instance) {
    if (action) {
      if (scope->stack->actions[scope->stack->size - 1] == action &&
          scope->stack->instances[scope->stack->size - 1] == instance) {
        is_staged = TRUE;
      }
    } else {
      if (scope->stack->instances[scope->stack->size - 1] == instance) {
        is_staged = TRUE;
      }
    }
  } else {
    if (scope->stack->actions[scope->stack->size - 1] == action) {
      is_staged = TRUE;
    }
  }
  va_list __ARGUMENT_POINTERS__;
  void* __args_stack__[8] = {};
  void** args = __args_stack__;
  size_t __ARG_CNT__ = 0;
  size_t args_capacity = 8;
  generic_function_t predicate = (generic_function_t)
# 1134 "src/memory/dyn_alloc.c" 3 4
                                                    ((void *)0)
# 1134 "src/memory/dyn_alloc.c"
                                                        ;
  {
    
# 1136 "src/memory/dyn_alloc.c" 3 4
   __builtin_va_start(
# 1136 "src/memory/dyn_alloc.c"
   __ARGUMENT_POINTERS__
# 1136 "src/memory/dyn_alloc.c" 3 4
   ,
# 1136 "src/memory/dyn_alloc.c"
   action
# 1136 "src/memory/dyn_alloc.c" 3 4
   )
# 1136 "src/memory/dyn_alloc.c"
                                          ;
    if (is_staged) {
      predicate = (generic_function_t)
# 1138 "src/memory/dyn_alloc.c" 3 4
                                     __builtin_va_arg(
# 1138 "src/memory/dyn_alloc.c"
                                     __ARGUMENT_POINTERS__
# 1138 "src/memory/dyn_alloc.c" 3 4
                                     ,
# 1138 "src/memory/dyn_alloc.c"
                                     void*
# 1138 "src/memory/dyn_alloc.c" 3 4
                                     )
# 1138 "src/memory/dyn_alloc.c"
                                                                         ;
    }
    for (size_t i = 0;
         (i < 32) &&
         (args[i] = 
# 1142 "src/memory/dyn_alloc.c" 3 4
                   __builtin_va_arg(
# 1142 "src/memory/dyn_alloc.c"
                   __ARGUMENT_POINTERS__
# 1142 "src/memory/dyn_alloc.c" 3 4
                   ,
# 1142 "src/memory/dyn_alloc.c"
                   void*
# 1142 "src/memory/dyn_alloc.c" 3 4
                   )
# 1142 "src/memory/dyn_alloc.c"
                                                       );
         ++i) {
      __ARG_CNT__++;
      if (__ARG_CNT__ + 1 == args_capacity) {
        if (__ARG_CNT__ + 1 == 8) {
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1148 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1148 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1148 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1148 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
          memcpy(args, __args_stack__, args_capacity);
        } else {
          void** tmp_args = args;
          args = (void**)malloc(sizeof(void*) * args_capacity * 2);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1153 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1153 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1153 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1153 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
          memcpy(args, tmp_args, args_capacity);
          free(tmp_args);
          if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1156 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1156 "src/memory/dyn_alloc.c"
         )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1156 "src/memory/dyn_alloc.c" 3 4
         (*__errno_location ())
# 1156 "src/memory/dyn_alloc.c"
         ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
        }
        args_capacity *= 2;
      }
    }
    
# 1161 "src/memory/dyn_alloc.c" 3 4
   __builtin_va_end(
# 1161 "src/memory/dyn_alloc.c"
   __ARGUMENT_POINTERS__
# 1161 "src/memory/dyn_alloc.c" 3 4
   )
# 1161 "src/memory/dyn_alloc.c"
                                ;
  }
  if (args_capacity == 8) {
    if (__ARG_CNT__ > 0) {
      args = (void**)malloc(sizeof(void*) * (__ARG_CNT__ + 1));
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1166 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 1166 "src/memory/dyn_alloc.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1166 "src/memory/dyn_alloc.c" 3 4
     (*__errno_location ())
# 1166 "src/memory/dyn_alloc.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
      memcpy(args, __args_stack__, sizeof(void*) * (__ARG_CNT__ + 1));
    } else {
      args = 0;
    }
  }
  if (args) {
    args[__ARG_CNT__] = 
# 1173 "src/memory/dyn_alloc.c" 3 4
                       ((void *)0)
# 1173 "src/memory/dyn_alloc.c"
                           ;
  }
  if (is_staged) {
    size_t result;
    if (action && instance) {
      result = __scope_stack_defer__(scope->stack,
                                    scope->defer_pool,
                                    action,
                                    instance,
                                    predicate,
                                    args);
    } else if (action) {
      result = __scope_stack_defer_action__(scope->stack,
                                            scope->defer_pool,
                                            action,
                                            predicate,
                                            args);
    } else {
      result = __scope_stack_defer_instance__(scope->stack,
                                              scope->defer_pool,
                                              instance,
                                              predicate,
                                              args);
    }
    if (!result && scope->stack->size) {
      scope->size--;
    }
  } else {
    __scope_stack_push__(scope->stack, action, instance, args);
    if (action || instance) {
      scope->size++;
    }
  }
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1206 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1206 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1206 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1206 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_skip__(__SCOPE_OBJECT__* scope,
                             void* instance,
                             generic_function_t action) {
  RBNode* root = (RBNode*)scope->defer_pool->tree_root;
  RBNode* node = rbFind_defer_pool_tree((__DEFER_POOL_NODE__){
                                                   .action=action,
                                                   .instance=instance},
                                                   &root);
  if (!scope->stack) {
    return 0;
  }
  if (node) {
    __scope_defer_pool_skip__(scope->defer_pool, instance, action);
  } else {
    if (action && instance) {
      __scope_stack_skip__(scope->stack, action, instance);
    } else if (action) {
      __scope_stack_skip_action__(scope->stack, action);
    } else {
      __scope_stack_skip_instance__(scope->stack, instance);
    }
  }
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1233 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1233 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1233 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1233 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 0;
}

size_t __scope_object_force__(__SCOPE_OBJECT__* scope,
                              void* instance,
                              generic_function_t action) {
  RBNode* root = (RBNode*)scope->defer_pool->tree_root;
  RBNode* node = rbFind_defer_pool_tree((__DEFER_POOL_NODE__){
                                                   .action=action,
                                                   .instance=instance},
                                                   &root);
  if (!scope->stack) {
    return 0;
  }
  if (node) {
    __scope_defer_pool_force__(scope->defer_pool, instance, action);
  } else {
    size_t index = 0;
    if (action && instance) {
      index = __scope_stack_find__(scope->stack, action, instance);
    } else if (action) {
      index = __scope_stack_find_action__(scope->stack, action);
    } else {
      index = __scope_stack_find_instance__(scope->stack, instance);
    }
    if (index >= scope->stack->size) {
      return 0;
    }
    __CALL_ACTION_N_ARGS__(scope->stack->actions[index],
                           scope->stack->instances[index],
                           scope->stack->args[index]);
    scope->stack->masks[index] = 0;
  }
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1268 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1268 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1268 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1268 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  __scope_defer_pool_add_token__(scope->defer_pool);
  return 1;
}

size_t __scope_object_change_bias__(__SCOPE_OBJECT__* scope,
                                    size_t bias_positive,
                                    size_t bias_negative) {
  scope->defer_pool->chunk_bias_pos = bias_positive;
  scope->defer_pool->chunk_bias_neg = bias_negative;
  return 0;
}

# 1 "src/memory/../oop/templates_undef.h" 1
# 1282 "src/memory/dyn_alloc.c" 2


__SCOPE_STACK__ __SCOPE_STACK_INST__ = (__SCOPE_STACK__){};
__SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__ = (__SCOPE_DEFER_POOL__){};
__SCOPE_OBJECT__ __SCOPE_OBJECT_INST__ = (__SCOPE_OBJECT__){};


void* __SCOPE_BEGIN__(__SCOPE_OBJECT__* scope,
  __SCOPE_DEFER_POOL__* pool,
  __SCOPE_STACK__* stack) {
  if (scope->mask & 2) {
    return (void*)__scope_object_enter__(scope);
  }
  __scope_object_init__(scope, stack, pool);
  return (void*)__scope_object_enter__(scope);
}

void* __SCOPE_END__(__SCOPE_OBJECT__* scope) {
  __scope_object_escape__(scope);
  if (scope->defer_pool->indentation == 0) {
    __scope_object_destroy__(scope);
  }
  return 
# 1304 "src/memory/dyn_alloc.c" 3 4
        ((void *)0)
# 1304 "src/memory/dyn_alloc.c"
            ;
}

void* __SCOPE_CALLOC__(__SCOPE_OBJECT__* scope,
                       size_t size,
                       size_t type_size,
                       void* filler,
                       ...) {
  void* data;
  if (filler) {
    data = malloc(size * type_size);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1315 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 1315 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1315 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 1315 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    for (size_t i = 0; i < size; ++i) {
      memcpy(data + type_size * i, filler, type_size);
    }
  } else {
    data = calloc(size, type_size);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1321 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 1321 "src/memory/dyn_alloc.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1321 "src/memory/dyn_alloc.c" 3 4
   (*__errno_location ())
# 1321 "src/memory/dyn_alloc.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  }
  __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(data), (generic_function_t)(free), 0);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1324 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1324 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1324 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1324 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return data;
}

void* __SCOPE_FREE__(__SCOPE_OBJECT__* scope, void* data) {
  __scope_object_skip__(scope, data, (generic_function_t)free);
  free(data);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1331 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1331 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1331 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1331 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return 
# 1332 "src/memory/dyn_alloc.c" 3 4
        ((void *)0)
# 1332 "src/memory/dyn_alloc.c"
            ;
}

void* __SCOPE_FORCED_RELEASE__(__SCOPE_OBJECT__* scope,
                               void* data,
                               generic_function_t action,
                               ...) {
  __scope_object_force__(scope, data, action);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1340 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1340 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1340 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1340 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return 
# 1341 "src/memory/dyn_alloc.c" 3 4
        ((void *)0)
# 1341 "src/memory/dyn_alloc.c"
            ;
}

void* __SCOPE_SKIP__(__SCOPE_OBJECT__* scope,
                     void* data,
                     generic_function_t action,
                     ...) {
  __scope_object_skip__(scope, data, action);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1349 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1349 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1349 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1349 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return 
# 1350 "src/memory/dyn_alloc.c" 3 4
        ((void *)0)
# 1350 "src/memory/dyn_alloc.c"
            ;
}

typedef struct __SCOPE_OBJECT_TRIPLET__ {
  __SCOPE_OBJECT__ obj;
  __SCOPE_STACK__ stack;
  __SCOPE_DEFER_POOL__ pool;
} __SCOPE_OBJECT_TRIPLET__;

__SCOPE_OBJECT__* __LOCAL_SCOPE_NEW__() {
  __SCOPE_OBJECT_TRIPLET__* scope = (__SCOPE_OBJECT_TRIPLET__*)malloc(sizeof(__SCOPE_OBJECT_TRIPLET__));
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((__SCOPE_OBJECT__**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1361 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1361 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1361 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1361 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((__SCOPE_OBJECT__**)&(__EXCEPTION_RESULT__));; } };
  return (__SCOPE_OBJECT__*)__scope_object_init__(&(scope->obj), &(scope->stack), &(scope->pool));
}

void* __LOCAL_SCOPE_FREE__(__SCOPE_OBJECT__* local_scope) {
  __scope_object_destroy__(local_scope);
  free(local_scope);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 1368 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1368 "src/memory/dyn_alloc.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 1368 "src/memory/dyn_alloc.c" 3 4
 (*__errno_location ())
# 1368 "src/memory/dyn_alloc.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return 
# 1369 "src/memory/dyn_alloc.c" 3 4
        ((void *)0)
# 1369 "src/memory/dyn_alloc.c"
            ;
}

void* __DEFAULT_PREDICATE__(void* instance, ...) {
  return 
# 1373 "src/memory/dyn_alloc.c" 3 4
        ((void *)0)
# 1373 "src/memory/dyn_alloc.c"
            ;
}

void* __TRUE_PREDICATE__(void* instance, ...) {
  return (void*)TRUE;
}

void* __FALSE_PREDICATE__(void* instance, ...) {
  return (void*)FALSE;
}
# 0 "src/oop/class.c"
# 1 "/home/just_engineer/dev/extraslib//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "src/oop/class.c"
# 1 "src/oop/class.h" 1
# 1 "src/oop/../memory/dyn_alloc.h" 1
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 415 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 416 "/usr/include/features.h" 2 3 4
# 523 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 730 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 731 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 732 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 524 "/usr/include/features.h" 2 3 4
# 547 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 548 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4

# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 344 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 56 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 131 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 132 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
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
  unsigned int __g_size[2] ;
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
  unsigned int __unused_initialized_1;
  unsigned int __unused_initialized_2;
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



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__)) __attribute__ ((__cold__));



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

# 2 "src/oop/../memory/dyn_alloc.h" 2
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
# 36 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
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
  int _flags2:24;

  char _short_backupbuf[1];
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

# 3 "src/oop/../memory/dyn_alloc.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 286 "/usr/include/string.h" 3 4
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 380 "/usr/include/string.h" 3 4
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));







extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4










extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlcpy (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



extern size_t strlcat (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
# 552 "/usr/include/string.h" 3 4

# 4 "src/oop/../memory/dyn_alloc.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stdarg.h" 1 3 4
# 5 "src/oop/../memory/dyn_alloc.h" 2

# 1 "src/oop/../memory/../oop/exception.h" 1
# 1 "/usr/include/errno.h" 1 3 4
# 28 "/usr/include/errno.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/lib/linux/uapi/x86/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 2 "/usr/lib/linux/uapi/x86/asm/errno.h" 2 3 4
# 2 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4








extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 52 "/usr/include/errno.h" 3 4

# 2 "src/oop/../memory/../oop/exception.h" 2

       
# 24 "src/oop/../memory/../oop/exception.h"

# 24 "src/oop/../memory/../oop/exception.h"
typedef struct exception_context_t
{
  char data[4096];
} exception_context_t;

extern exception_context_t _EXCEPTION_CONTEXT;
extern unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR;

typedef int exception_status_t;

typedef struct exception_t
{
  unsigned int exception_number;
  exception_status_t status;
  exception_context_t* context;
  char* exception_description;
} exception_t;

extern exception_t _EXCEPTION;

extern exception_t CAUGHT_EXCEPTION;
extern exception_context_t CAUGHT_EXCEPTION_CONTEXT;
# 54 "src/oop/../memory/../oop/exception.h"
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;


extern BOOL _ERRORB;
extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);
# 87 "src/oop/../memory/../oop/exception.h"
void* __raise_exception__(exception_t* exception);
# 100 "src/oop/../memory/../oop/exception.h"
void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...);
# 122 "src/oop/../memory/../oop/exception.h"
void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, void(*callback)());
# 7 "src/oop/../memory/dyn_alloc.h" 2
       
# 72 "src/oop/../memory/dyn_alloc.h"
typedef void*(*generic_function_t)(void*, ... );
typedef void*(*generic_function_t)(void*, ... );

void* __CALL_FUNCTION__(generic_function_t, void*);
void* __CALL_FUNCTION_N_ARGS__(generic_function_t, ... );





typedef struct __SCOPE_STACK__ {
  size_t capacity;
  size_t size;
  generic_function_t* actions;
  void** instances;
  void*** args;
  char* masks;
} __SCOPE_STACK__;

typedef struct __SCOPE_DEFER_CHUNK__ {
  long bias_sum;
  size_t min_indentation;
  size_t capacity;
  size_t size;
  generic_function_t* predicates;
  void*** predicate_args;
  generic_function_t* actions;
  void** instances;
  void*** args;
} __SCOPE_DEFER_CHUNK__;



typedef struct __SCOPE_DEFER_POOL__ {
  unsigned int chunk_bias_pos;
  unsigned int chunk_bias_neg;
  size_t active_size;
  size_t size;
  size_t capacity;
  size_t tokens;
  size_t indentation;
  void* tree_root;
  __SCOPE_DEFER_CHUNK__* chunks;
} __SCOPE_DEFER_POOL__;







void* __scope_stack_init__(__SCOPE_STACK__* stack);
size_t __scope_stack_destroy__(__SCOPE_STACK__* stack);
size_t __scope_stack_push__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance,
  void** args);
size_t __scope_stack_pop__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_top__(__SCOPE_STACK__* stack);
void* __scope_stack_top__(__SCOPE_STACK__* stack);
size_t __scope_stack_pop_until__(__SCOPE_STACK__* stack,
  generic_function_t predicate);
size_t __scope_stack_pop_all__(__SCOPE_STACK__* stack);
size_t __scope_stack_find__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_find_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_find_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_skip__(__SCOPE_STACK__* stack,
  generic_function_t action,
  void* instance);
size_t __scope_stack_skip_action__(__SCOPE_STACK__* stack,
  generic_function_t action);
size_t __scope_stack_skip_instance__(__SCOPE_STACK__* stack,
  void* instance);
size_t __scope_stack_defer__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_action__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  generic_function_t action,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_stack_defer_instance__(__SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* defer_pool,
  void* instance,
  generic_function_t predicate,
  void** predicate_args);







void* __scope_defer_chunk_init__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_destroy__(__SCOPE_DEFER_CHUNK__* chunk);
size_t __scope_defer_chunk_push__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args,
  size_t indentation);
size_t __scope_defer_chunk_find__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_skip__(__SCOPE_DEFER_CHUNK__* chunk,
  generic_function_t action,
  void* instance);
size_t __scope_defer_chunk_check__(__SCOPE_DEFER_CHUNK__* chunk,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_chunk_get_bias_sum__(__SCOPE_DEFER_CHUNK__* chunk);
# 199 "src/oop/../memory/dyn_alloc.h"
void* __scope_defer_pool_init__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_destroy__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_push__(__SCOPE_DEFER_POOL__* pool,
  generic_function_t action,
  void* instance,
  void** args,
  generic_function_t predicate,
  void** predicate_args);
size_t __scope_defer_pool_check__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_enter__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_escape__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_add_token__(__SCOPE_DEFER_POOL__* pool);
size_t __scope_defer_pool_skip__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_force__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
size_t __scope_defer_pool_find__(__SCOPE_DEFER_POOL__* pool,
  void* instance,
  generic_function_t action);
# 228 "src/oop/../memory/dyn_alloc.h"
typedef struct __SCOPE_OBJECT__ {
  __SCOPE_STACK__* stack;
  __SCOPE_DEFER_POOL__* defer_pool;
  size_t size;
  size_t mask;
} __SCOPE_OBJECT__;

void* __scope_object_init__(__SCOPE_OBJECT__* scope,
  __SCOPE_STACK__* stack,
  __SCOPE_DEFER_POOL__* pool);
size_t __scope_object_destroy__(__SCOPE_OBJECT__* scope);
size_t __scope_object_enter__(__SCOPE_OBJECT__* scope);
size_t __scope_object_escape__(__SCOPE_OBJECT__* scope);
size_t __scope_object_change_bias__(__SCOPE_OBJECT__* scope,
  size_t bias_positive,
  size_t bias_negative);
size_t __scope_object_lock_pool__(__SCOPE_OBJECT__* scope);
size_t __scope_object_push__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_stage__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  ...);
size_t __scope_object_defer__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action,
  generic_function_t predicate,
  ...);
size_t __scope_object_skip__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);
size_t __scope_object_force__(__SCOPE_OBJECT__* scope,
  void* instance,
  generic_function_t action);


extern __SCOPE_STACK__ __SCOPE_STACK_INST__;
extern __SCOPE_DEFER_POOL__ __SCOPE_DEFER_POOL_INST__;
extern __SCOPE_OBJECT__ __SCOPE_OBJECT_INST__;

void* __SCOPE_BEGIN__(__SCOPE_OBJECT__* scope,
  __SCOPE_DEFER_POOL__* pool,
  __SCOPE_STACK__* stack);

void* __SCOPE_END__(__SCOPE_OBJECT__* scope);

void* __SCOPE_CALLOC__(__SCOPE_OBJECT__* scope,
  size_t size,
  size_t type_size,
  void* filler,
  ...);

void* __SCOPE_FREE__(__SCOPE_OBJECT__* scope, void* data);

void* __SCOPE_FORCED_RELEASE__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

void* __SCOPE_SKIP__(__SCOPE_OBJECT__* scope,
  void* data,
  generic_function_t action,
  ...);

__SCOPE_OBJECT__* __LOCAL_SCOPE_NEW__();

void* __LOCAL_SCOPE_FREE__(__SCOPE_OBJECT__* local_scope);

void* __DEFAULT_PREDICATE__(void* instance, ...);

void* __TRUE_PREDICATE__(void* instance, ...);

void* __FALSE_PREDICATE__(void* instance, ...);
# 2 "src/oop/class.h" 2
# 1 "src/oop/../algorithm/hash.h" 1

       
# 28 "src/oop/../algorithm/hash.h"
size_t hash_finalise(size_t);

size_t hash_byte_array(void*, size_t);
# 3 "src/oop/class.h" 2

       
# 33 "src/oop/class.h"
typedef struct __vTableHash__ {
  size_t hashX;
  size_t hashY;
} __vTableHash__;

typedef struct __vTableNode__ {
  void* data;
  size_t data_mask;
  size_t data_shift;
  size_t mask;
  __vTableHash__ hash;
} __vTableNode__;
# 53 "src/oop/class.h"
typedef size_t (*__vTable_byte_hasher_t__)(const char* key, size_t k_hash);

typedef struct __vTable__ {
  __vTable_byte_hasher_t__ hasher;
  __vTableNode__* data;
  size_t size;
} __vTable__;

__vTableHash__ __class_vtable_hash__(const char* key);

void* __vTable_add__(__vTable__* table, __vTableHash__ hash, __vTableNode__ value);
void* __vTable_remove__(__vTable__* table, __vTableHash__ hash);
__vTableNode__* __vTable_get__(__vTable__* table, __vTableHash__ hash);
BOOL __vTable_check__(__vTable__* table, __vTableHash__ hash);
void* __vTable_join__(__vTable__* table, __vTable__* source);


typedef enum __m_enum__ {
  __m_init__,
  __m_destroy__,
  __m_cast__,
  __m_copy__,
  __m_assign__,
  __m_move__,
  __m_call__,
  __m_getitem__,
  __m_iter__,
  __m_id__,
  __m_set__,
  __m_get__,
  __m_cmp__,
  __m_listen__,
  __m_shout__,
  __m_new__,
  __m_delete__,
  __m_contains__,
  __m_data__,
  __m_next__,
  __m_begin__,
  __m_end__,
  __m_len__,
  __m_lt__,
  __m_gt__,
  __m_eq__,
  __m_le__,
  __m_ge__,
  __m_neq__,
  __m_neg__,
  __m_ineg__,
  __m_add__,
  __m_iadd__,
  __m_sub__,
  __m_isub__,
  __m_mul__,
  __m_imul__,
  __m_div__,
  __m_idiv__,
  __m_mod__,
  __m_imod__,
  __m_and__,
  __m_iand__,
  __m_or__,
  __m_ior__,
  __m_xor__,
  __m_ixor__,
  __m_not__,
  __m_inot__,
  __m_pow__,
  __m_bitand__,
  __m_bitiand__,
  __m_bitor__,
  __m_bitior__,
  __m_bitxor__,
  __m_bitixor__,
  __m_bitnot__,
  __m_bitinot__,
  __m_inc__,
  __m_dec__,
  __m_lsh__,
  __m_ilsh__,
  __m_rsh__,
  __m_irsh__
} __m_enum__;
# 199 "src/oop/class.h"
typedef struct __ClassObject__ __ClassObject__;

typedef struct __vClassObject__ __vClassObject__;

typedef struct __MetaObject__ {
  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __cast__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __move__;
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __iter__;
  generic_function_t __id__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __cmp__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __contains__;
  generic_function_t __data__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
  generic_function_t __len__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __neg__;
  generic_function_t __ineg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __pow__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;

  unsigned int* __method_shift__;

} __MetaObject__;

typedef struct __InheritanceListNode__ {
  __ClassObject__* cls;
  size_t adress_shift;
} __InheritanceListNode__;



typedef struct __InheritanceList__ {
  __InheritanceListNode__* list;
  __InheritanceListNode__* static_list;
  size_t capacity;
  size_t size;
} __InheritanceList__;

typedef struct __ClassInstance__ __ClassInstance__;

typedef struct __ClassInstance_R__ __ClassInstance_R__;


void* __InheritanceList_add__(__InheritanceList__* list, void* self,
  void* instance, __ClassObject__* cls);
void* __InheritanceList_remove__(__InheritanceList__* list, __ClassInstance__* instance);
size_t __InheritanceList_find__(__InheritanceList__* list, __vTableHash__ hash);
size_t __InheritanceList_find_built_in__(__InheritanceList__* list, __m_enum__ built_in_no);
void* __InheritanceList_init__(__InheritanceList__* list, __InheritanceListNode__* default_nodes);
void* __InheritanceList_destroy__(__InheritanceList__* list);


typedef struct class_field_t class_field_t;

typedef class_field_t* class_structure_t;




typedef struct __vClassObjectPrt__ {

  void* data;

} __vClassObjectPrt__;

typedef struct __ClassMetaObject__ {

  generic_function_t __init__;
  generic_function_t __destroy__;
  generic_function_t __cast__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __move__;
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __iter__;
  generic_function_t __id__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __cmp__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __contains__;
  generic_function_t __data__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
  generic_function_t __len__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __neg__;
  generic_function_t __ineg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __pow__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;

  unsigned int* __method_shift__;

  __ClassObject__* cls;

} __ClassMetaObject__;

typedef struct type_object_t {

  __ClassMetaObject__* type_meta;
  const char* type_name;
  size_t type_size;
  size_t type_mask;

} type_object_t;

typedef struct class_field_t
{

  size_t field_mask;
  char* field_name;
  void* field_addr;
  type_object_t* type;

} class_field_t;

typedef struct __FundamentalVClass__ {
  generic_function_t __call__;
  generic_function_t __getitem__;
  generic_function_t __iter__;
  generic_function_t __id__;
  generic_function_t __set__;
  generic_function_t __get__;
  generic_function_t __cmp__;
  generic_function_t __listen__;
  generic_function_t __shout__;
  generic_function_t __new__;
  generic_function_t __delete__;
  generic_function_t __contains__;
  generic_function_t __data__;
  generic_function_t __next__;
  generic_function_t __begin__;
  generic_function_t __end__;
  generic_function_t __len__;
  generic_function_t __lt__;
  generic_function_t __gt__;
  generic_function_t __eq__;
  generic_function_t __le__;
  generic_function_t __ge__;
  generic_function_t __neq__;
  generic_function_t __neg__;
  generic_function_t __ineg__;
  generic_function_t __add__;
  generic_function_t __iadd__;
  generic_function_t __sub__;
  generic_function_t __isub__;
  generic_function_t __mul__;
  generic_function_t __imul__;
  generic_function_t __div__;
  generic_function_t __idiv__;
  generic_function_t __mod__;
  generic_function_t __imod__;
  generic_function_t __and__;
  generic_function_t __iand__;
  generic_function_t __or__;
  generic_function_t __ior__;
  generic_function_t __xor__;
  generic_function_t __ixor__;
  generic_function_t __not__;
  generic_function_t __inot__;
  generic_function_t __pow__;
  generic_function_t __bitand__;
  generic_function_t __bitiand__;
  generic_function_t __bitor__;
  generic_function_t __bitior__;
  generic_function_t __bitxor__;
  generic_function_t __bitixor__;
  generic_function_t __bitnot__;
  generic_function_t __bitinot__;
  generic_function_t __inc__;
  generic_function_t __dec__;
  generic_function_t __lsh__;
  generic_function_t __ilsh__;
  generic_function_t __rsh__;
  generic_function_t __irsh__;

} __FundamentalVClass__;

struct __vClassObjectMeta__ {
  char __prot_vcls_data__[0];
  unsigned int __method_shift__[0];
  __vClassObjectPrt__ __protected__[0];
  __vTable__ __vtable__[0];
};

typedef struct __vClassObject__ {


  generic_function_t __init__;
  generic_function_t __destroy__;


  generic_function_t __cast__;
  generic_function_t __copy__;
  generic_function_t __assign__;
  generic_function_t __move__;


  __FundamentalVClass__ _f;


  unsigned int* __method_shift__;


  __ClassObject__* cls;


  struct __vClassObjectMeta__ __meta__;

} __vClassObject__;

typedef struct __ClassInstance__ {
  __vClassObject__ __meta__[0];
} __ClassInstance__;

typedef struct __ClassInterface__ {
  const __vClassObject__* __meta__;
  __ClassInstance__* self;
} __ClassInterface__;

typedef struct __Interface__ {
  const __MetaObject__* __meta__;
} __Interface__;







  typedef __FundamentalVClass__ __DefaultBase_FundamentalVClass__;


typedef struct __ClassObject__ {

  size_t instance_size;
  size_t vclass_size;
  size_t vclass_meta_size;
  size_t _f_class_size;
  size_t mask;
  size_t instance_count;

  size_t __vclass_cnt;
  size_t __vclass_capacity;

  const char* name;

  class_structure_t* fields;
  class_structure_t* static_fields;

  __InheritanceList__* inherits_from;

  __vClassObject__** alloc_vcls;

  __vClassObject__* default_vcls;
  __ClassInstance__* default_instance;

  __ClassObject__** __vcls_cls__;

  generic_function_t __static_init__;
  generic_function_t __static_destroy__;

  generic_function_t __class_object_init__;
  generic_function_t __class_object_destroy__;

} __ClassObject__;

void* __class_init__(__ClassObject__* cls);
void* __class_destroy__(__ClassObject__* cls);
void __class_inherit_static__(__ClassObject__* cls);
void __class_inherit__(__ClassObject__* cls);
void __class_inherit_instance__(__ClassInstance__* instance);

extern const char* __VCLASS_METHOD_UC_NAMES__[64];





void* __aux_class_new_vclass__(__ClassObject__* cls);

void* __aux_type_cast__(void* expr, type_object_t* src_type, type_object_t* trg_type, void* allocated_memory);
void* __aux_class_cast__(void* expr, __ClassMetaObject__* src_type, __ClassMetaObject__* trg_type, void* allocated_memory);



BOOL __GET_CLASS_MASK_IS_STATIC__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_FUNDAMENTAL__(size_t* mask);

BOOL __GET_CLASS_MASK_DERIVED__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_ABSTRACT__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_CONST__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_CUSTOM__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_SUPER__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BRIDGE__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_BARE__(size_t* mask);

BOOL __GET_CLASS_MASK_IS_ILLDEFINED__(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_INIT__(size_t* mask);

BOOL __GET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask);

void __SET_CLASS_MASK_STATIC__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_FUNDAMENTAL__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_DERIVED__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_ABSTRACT__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_CONST__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_CUSTOM__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_SUPER__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BRIDGE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_BARE__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_ILLDEFINED__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_INIT__(size_t* mask, BOOL new_type);

void __SET_CLASS_MASK_WAS_STATIC_INIT__(size_t* mask, BOOL new_type);
# 692 "src/oop/class.h"
typedef __ClassInstance__ DefaultBase_S; typedef DefaultBase_S DefaultBase;

typedef __vClassObject__ __DefaultBase_vClassObject__;

extern __ClassObject__ __DefaultBase_ClassObject__;
extern DefaultBase_S __DefaultBase_Default_Instance__;
extern __vClassObject__ __DefaultBase_Default_vClassObject__;
extern type_object_t __DefaultBase_type__;
extern type_object_t* DefaultBase_type;
extern void* __DefaultBase_static_init__(DefaultBase* self);
extern void* __DefaultBase_static_destroy__(DefaultBase* self);
# 1146 "src/oop/class.h"
void* __aux_class_new_wrapper__(__ClassObject__* cls, size_t size, __ClassInstance__* template_instance);
# 1305 "src/oop/class.h"
__Interface__* create_class(class_field_t* fields);
void* create_instance(type_object_t* type);
# 2 "src/oop/class.c" 2

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
  return (__vTableHash__){.hashX=defaultVTableHasher(key, 0),
                          .hashY=defaultVTableHasher(key, 1)};
}



static inline __vTableProbeId__ __vTable_probe__(__vTable__* table, __vTableHash__ hash) {
  size_t id0 = hash.hashX & (table->size - 1);
  size_t idx = id0;
  size_t cnt = 1;
  size_t pow = 0;
  while (cnt < 8 * table->size &&
         (table->data[idx].data &&
          (hash.hashX != table->data[idx].hash.hashX ||
           hash.hashY != table->data[idx].hash.hashY))) {
    idx = (id0 + cnt) & (table->size - 1);
    cnt *= 2;
    pow++;
  }
  if (cnt >= 8 * table->size) {
    return (__vTableProbeId__){};
  }
  return (__vTableProbeId__){.id=idx + 1, .pow=pow};
}
# 85 "src/oop/class.c"
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
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 97 "src/oop/class.c" 3 4
 (*__errno_location ())
# 97 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 97 "src/oop/class.c" 3 4
 (*__errno_location ())
# 97 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  size_t tmp_size = table->size;
  table->size = new_size;
  if (tmp_data == 
# 100 "src/oop/class.c" 3 4
                 ((void *)0)
# 100 "src/oop/class.c"
                     ) {
    return table->size;
  }
  __vTableProbeId__ idx = (__vTableProbeId__){};
  for (size_t i = 0; i < tmp_size; ++i) {
    idx = __vTable_probe__(table, tmp_data[i].hash);
    if (!idx.id) {
      __vTable_reserve__(table, table->size * 2);
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 108 "src/oop/class.c" 3 4
     (*__errno_location ())
# 108 "src/oop/class.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 108 "src/oop/class.c" 3 4
     (*__errno_location ())
# 108 "src/oop/class.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
      idx = __vTable_probe__(table, tmp_data[i].hash);
    }
    table->data[idx.id - 1].data = tmp_data[i].data;
    table->data[idx.id - 1].hash = tmp_data[i].hash;



    __vTableNode_set_mask_bit_t__(&(table->data[tmp_data[i].hash.hashX & (table->size - 1)]), idx.pow);







  }
  free(tmp_data);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 126 "src/oop/class.c" 3 4
 (*__errno_location ())
# 126 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 126 "src/oop/class.c" 3 4
 (*__errno_location ())
# 126 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((size_t*)&(__EXCEPTION_RESULT__));; } };
  return table->size;
}

void* __vTable_init__(__vTable__* table, size_t default_size, generic_function_t hasher) {
  *table = (__vTable__){.hasher = (__vTable_byte_hasher_t__)defaultVTableHasher};
  if (hasher) {
    table->hasher = (__vTable_byte_hasher_t__)hasher;
  }
  __vTable_reserve__(table, default_size ? default_size : 8);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 136 "src/oop/class.c" 3 4
 (*__errno_location ())
# 136 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 136 "src/oop/class.c" 3 4
 (*__errno_location ())
# 136 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return table;
}

void* __vTable_destroy__(__vTable__* table) {
  if (table->data) {
    free(table->data);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 143 "src/oop/class.c" 3 4
   (*__errno_location ())
# 143 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 143 "src/oop/class.c" 3 4
   (*__errno_location ())
# 143 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  }
  return 
# 145 "src/oop/class.c" 3 4
        ((void *)0)
# 145 "src/oop/class.c"
            ;
}

void* __vTable_add__(__vTable__* table, __vTableHash__ hash, __vTableNode__ node) {
  __vTableProbeId__ idx;
  idx = __vTable_probe__(table, hash);
  if (!idx.id) {
    __vTable_reserve__(table, table->size * 2);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 153 "src/oop/class.c" 3 4
   (*__errno_location ())
# 153 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 153 "src/oop/class.c" 3 4
   (*__errno_location ())
# 153 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    idx = __vTable_probe__(table, hash);
  }
  table->data[idx.id - 1].data = node.data;
  table->data[idx.id - 1].data_mask = node.data_mask;
  table->data[idx.id - 1].data_shift = node.data_shift;
  table->data[idx.id - 1].hash = hash;



  __vTableNode_set_mask_bit_t__(&(table->data[hash.hashX & (table->size - 1)]), idx.pow);






  return table;
}

void* __vTable_remove__(__vTable__* table, __vTableHash__ hash) {
  __vTableProbeId__ idx;
  do {
    idx = __vTable_probe__(table, hash);
    if (!idx.id) {
      __vTable_reserve__(table, table->size * 2);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 179 "src/oop/class.c" 3 4
   (*__errno_location ())
# 179 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 179 "src/oop/class.c" 3 4
   (*__errno_location ())
# 179 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    }
  } while (!idx.id);
  table->data[idx.id - 1] = (__vTableNode__){};



  __vTableNode_set_mask_bit_f__(&(table->data[hash.hashX & (table->size - 1)]), idx.pow);






  return table;
}

__vTableNode__* __vTable_get__(__vTable__* table, __vTableHash__ hash) {



  size_t mask = table->data[hash.hashX & (table->size - 1)].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashX == hash.hashX &&
        table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashY == hash.hashY) {
      return &(table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)]);
    }
  }
# 224 "src/oop/class.c"
  return 
# 224 "src/oop/class.c" 3 4
        ((void *)0)
# 224 "src/oop/class.c"
            ;
}

BOOL __vTable_check__(__vTable__* table, __vTableHash__ hash) {



  size_t mask = table->data[hash.hashX & (table->size - 1)].mask;
  while (mask) {
    size_t primary_bit = mask & (-mask);
    mask ^= primary_bit;
    if (table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashX == hash.hashX &&
        table->data[(hash.hashX + primary_bit / 2) & (table->size - 1)].hash.hashY == hash.hashY) {
      return TRUE;
    }
  }
# 255 "src/oop/class.c"
  return FALSE;
}

void* __vTable_join__(__vTable__* table, __vTable__* source) {
  if (!source) {
    return 
# 260 "src/oop/class.c" 3 4
          ((void *)0)
# 260 "src/oop/class.c"
              ;
  }
  if (source->size >= table->size) {
    __vTable_reserve__(table, source->size * 2);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 264 "src/oop/class.c" 3 4
   (*__errno_location ())
# 264 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 264 "src/oop/class.c" 3 4
   (*__errno_location ())
# 264 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  }
  for (size_t i = 0; i < source->size; ++i) {
    if (source->data[i].hash.hashX || source->data[i].hash.hashY) {
      __vTable_add__(table, source->data[i].hash, source->data[i]);
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 269 "src/oop/class.c" 3 4
     (*__errno_location ())
# 269 "src/oop/class.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 269 "src/oop/class.c" 3 4
     (*__errno_location ())
# 269 "src/oop/class.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    }
  }
  return table;
}

void* __InheritanceList_reserve__(__InheritanceList__* list, size_t new_capacity) {
  __InheritanceListNode__* tmp_list = (list->list ? list->list : list->static_list);
  list->list = (__InheritanceListNode__*)malloc(new_capacity * sizeof(__InheritanceListNode__));
    ((list->list != 0) ? ((void*)0) : __exc_assert_fail__(&_EXCEPTION, "Assertion failed! '" "list->list != 0" "' in file " "src/oop/class.c" ":" "278", __func__, ((void*)0)) );
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 279 "src/oop/class.c" 3 4
   (*__errno_location ())
# 279 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 279 "src/oop/class.c" 3 4
   (*__errno_location ())
# 279 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  if (list->capacity) {
    memcpy(list->list, tmp_list, list->capacity * sizeof(__InheritanceListNode__));
    if (tmp_list != list->static_list) {
      free(tmp_list);
    }
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 285 "src/oop/class.c" 3 4
   (*__errno_location ())
# 285 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 285 "src/oop/class.c" 3 4
   (*__errno_location ())
# 285 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  }
  list->capacity = new_capacity;
  return list;
}

void* __InheritanceList_init__(__InheritanceList__* list, __InheritanceListNode__* default_nodes) {
  list->size = 0;
  list->capacity = 0;
  if (!default_nodes) {
    list->list = 0;
    __InheritanceList_reserve__(list, 8);
  } else {
    list->list = default_nodes;
    list->static_list = default_nodes;
    list->capacity = 8;
  }
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 302 "src/oop/class.c" 3 4
 (*__errno_location ())
# 302 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 302 "src/oop/class.c" 3 4
 (*__errno_location ())
# 302 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return list;
}

void* __InheritanceList_destroy__(__InheritanceList__* list) {
  if (list->list != list->static_list) {
    free(list->list);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 309 "src/oop/class.c" 3 4
   (*__errno_location ())
# 309 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 309 "src/oop/class.c" 3 4
   (*__errno_location ())
# 309 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  }
  *list = (__InheritanceList__){};
  return 
# 312 "src/oop/class.c" 3 4
        ((void *)0)
# 312 "src/oop/class.c"
            ;
}

void* __InheritanceList_add__(__InheritanceList__* list,
                              void* self,
                              void* instance,
                              __ClassObject__* cls) {
  if (list->size + 1 == list->capacity) {
    __InheritanceList_reserve__(list, 2 * list->capacity);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 321 "src/oop/class.c" 3 4
   (*__errno_location ())
# 321 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 321 "src/oop/class.c" 3 4
   (*__errno_location ())
# 321 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  }
  list->list[list->size].adress_shift = (size_t)(instance - self);
  list->list[list->size].cls = cls;
  list->size++;
  __SET_CLASS_MASK_SUPER__(&cls->mask, TRUE);
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
    memmove(list->list + i * sizeof(__InheritanceListNode__),
            list->list + (i + 1) * sizeof(__InheritanceListNode__),
            list->size - i);
    return list;
  }
  return 
# 344 "src/oop/class.c" 3 4
        ((void *)0)
# 344 "src/oop/class.c"
            ;
}

size_t __InheritanceList_find__(__InheritanceList__* list, __vTableHash__ hash) {
  size_t i = 0;
  while (i < list->size) {
    if (__vTable_check__(*(__vTable__**)((void*)list->list[i].cls->default_vcls +
                                list->list[i].cls->vclass_size -
                                sizeof(void*)), hash)) {
      return i;
    }
    i++;
  }
  return (size_t)((void*)-1);
}

size_t __InheritanceList_find_built_in__(__InheritanceList__* list, __m_enum__ built_in_no) {
  size_t i = 0;
  while (i < list->size) {
    if (*(&(list->list[i].cls->default_vcls->__init__) +
        built_in_no)) {
      return i;
    }
    i++;
  }
  return (size_t)((void*)-1);
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



__ClassObject__ __DefaultBase_ClassObject__ =
    (__ClassObject__){.mask=256|1|8|2|64,
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
                      .fields=&(class_structure_t){(class_field_t[]){
                        (class_field_t){.field_addr=&((__ClassInstance__*)
# 495 "src/oop/class.c" 3 4
                       ((void *)0)
# 495 "src/oop/class.c"
                       )->__meta__, .field_name="__meta__", .type=(type_object_t*)&(type_object_t){.type_name="__vClassObject__", .type_size=sizeof(__vClassObject__)}}


                                                                                 ,
                        (class_field_t){}
                      }},
                      .static_fields=&(class_structure_t){(class_field_t[]){
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 502 "src/oop/class.c" 3 4
                       ((void *)0)
# 502 "src/oop/class.c"
                       )->__init__, .field_name="__init__", .type=(type_object_t*)&(type_object_t){.type_name="generic_function_t", .type_size=sizeof(generic_function_t)}}


                                                                                   ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 506 "src/oop/class.c" 3 4
                       ((void *)0)
# 506 "src/oop/class.c"
                       )->__destroy__, .field_name="__destroy__", .type=(type_object_t*)&(type_object_t){.type_name="generic_function_t", .type_size=sizeof(generic_function_t)}}


                                                                                   ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 510 "src/oop/class.c" 3 4
                       ((void *)0)
# 510 "src/oop/class.c"
                       )->__cast__, .field_name="__cast__", .type=(type_object_t*)&(type_object_t){.type_name="generic_function_t", .type_size=sizeof(generic_function_t)}}


                                                                                   ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 514 "src/oop/class.c" 3 4
                       ((void *)0)
# 514 "src/oop/class.c"
                       )->__copy__, .field_name="__copy__", .type=(type_object_t*)&(type_object_t){.type_name="generic_function_t", .type_size=sizeof(generic_function_t)}}


                                                                                   ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 518 "src/oop/class.c" 3 4
                       ((void *)0)
# 518 "src/oop/class.c"
                       )->__assign__, .field_name="__assign__", .type=(type_object_t*)&(type_object_t){.type_name="generic_function_t", .type_size=sizeof(generic_function_t)}}


                                                                                   ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 522 "src/oop/class.c" 3 4
                       ((void *)0)
# 522 "src/oop/class.c"
                       )->__move__, .field_name="__move__", .type=(type_object_t*)&(type_object_t){.type_name="generic_function_t", .type_size=sizeof(generic_function_t)}}


                                                                                   ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 526 "src/oop/class.c" 3 4
                       ((void *)0)
# 526 "src/oop/class.c"
                       )->_f, .field_name="_f", .type=(type_object_t*)&(type_object_t){.type_name="__FundamentalVClass__", .type_size=sizeof(__FundamentalVClass__)}}


                                                                                      ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 530 "src/oop/class.c" 3 4
                       ((void *)0)
# 530 "src/oop/class.c"
                       )->__method_shift__, .field_name="__method_shift__", .type=(type_object_t*)&(type_object_t){.type_name="unsigned int*", .type_size=sizeof(unsigned int*)}}


                                                                              ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 534 "src/oop/class.c" 3 4
                       ((void *)0)
# 534 "src/oop/class.c"
                       )->cls, .field_name="cls", .type=(type_object_t*)&(type_object_t){.type_name="__ClassObject__*", .type_size=sizeof(__ClassObject__*)}}


                                                                                 ,
                        (class_field_t){.field_addr=&((__vClassObject__*)
# 538 "src/oop/class.c" 3 4
                       ((void *)0)
# 538 "src/oop/class.c"
                       )->__meta__, .field_name="__meta__", .type=(type_object_t*)&(type_object_t){.type_name="__vClassObjectMeta__", .type_size=sizeof(struct __vClassObjectMeta__)}}


                                                                                            ,
                        (class_field_t){}
                      }}
                     };
type_object_t __DefaultBase_type__ = (type_object_t){.type_mask=256|1|8,
                                                     .type_meta=(__ClassMetaObject__*)&__DefaultBase_Default_vClassObject__,
                                                     .type_name="__ClassInstance__",
                                                     .type_size=sizeof(__ClassInstance__)};
type_object_t* DefaultBase_type = &__DefaultBase_type__;
__vClassObject__ __DefaultBase_Default_vClassObject__ = (__vClassObject__){.cls=&__DefaultBase_ClassObject__,
                                                                           .__init__=(generic_function_t)__DefaultBase_static_init__,
                                                                           .__destroy__=(generic_function_t)__DefaultBase_static_destroy__};
__ClassInstance__ __DefaultBase_Default_Instance__ = (__ClassInstance__){};

void* __DefaultBase_static_init__(DefaultBase* self) {
  return self;
}

void* __DefaultBase_static_destroy__(DefaultBase* self) {
  return 
# 560 "src/oop/class.c" 3 4
        ((void *)0)
# 560 "src/oop/class.c"
            ;
}


void* __class_init__(__ClassObject__* cls) {
  __vTable__** vtable = (__vTable__**)((void*)cls->default_vcls +
                                       cls->vclass_size -
                                       sizeof(void*));
  *vtable = (__vTable__*)malloc(sizeof(__vTable__));
  ((*vtable != 0) ? ((void*)0) : __exc_assert_fail__(&_EXCEPTION, "Assertion failed! '" "*vtable != 0" "' in file " "src/oop/class.c" ":" "569", __func__, ((void*)0)) );
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 570 "src/oop/class.c" 3 4
 (*__errno_location ())
# 570 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 570 "src/oop/class.c" 3 4
 (*__errno_location ())
# 570 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  __vTable_init__(*vtable, 0, 0);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 572 "src/oop/class.c" 3 4
 (*__errno_location ())
# 572 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 572 "src/oop/class.c" 3 4
 (*__errno_location ())
# 572 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return cls;
}

void* __class_destroy__(__ClassObject__* cls) {
  if (!__GET_CLASS_MASK_WAS_INIT__(&(cls->mask))) {
    return 
# 578 "src/oop/class.c" 3 4
          ((void *)0)
# 578 "src/oop/class.c"
              ;
  }
  if (cls->__class_object_destroy__) {
    cls->__class_object_destroy__(cls);
  }
  size_t index = 0;
  cls->default_vcls->__destroy__(cls->default_instance);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 585 "src/oop/class.c" 3 4
 (*__errno_location ())
# 585 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 585 "src/oop/class.c" 3 4
 (*__errno_location ())
# 585 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  cls->__static_destroy__(cls->default_instance);
  while (cls->alloc_vcls && index < cls->__vclass_cnt) {
    if (cls->alloc_vcls[index] != 
# 588 "src/oop/class.c" 3 4
                                 ((void *)0)
# 588 "src/oop/class.c"
                                     ) {
      __vTable__** vtable = (__vTable__**)((void*)cls->alloc_vcls[index] +
                                           cls->vclass_size -
                                           sizeof(void*));

      if (*vtable) {
        __vTable_destroy__(*vtable);
        free(*vtable);
      }
      free(cls->alloc_vcls[index]);
      if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 598 "src/oop/class.c" 3 4
     (*__errno_location ())
# 598 "src/oop/class.c"
     )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 598 "src/oop/class.c" 3 4
     (*__errno_location ())
# 598 "src/oop/class.c"
     ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    }
    index++;
  }
  __vTable__** vtable = (__vTable__**)((void*)cls->default_vcls +
                                        cls->vclass_size -
                                        sizeof(void*));
  if (*vtable) {
    __vTable_destroy__(*vtable);
    free(*vtable);
    *vtable = 
# 608 "src/oop/class.c" 3 4
             ((void *)0)
# 608 "src/oop/class.c"
                 ;
  }
  if (cls->inherits_from) {
    __InheritanceList_destroy__(cls->inherits_from);
    cls->inherits_from = 0;
  }
  if (cls->alloc_vcls) {
    free(cls->alloc_vcls);
    cls->alloc_vcls = 0;
  }
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 618 "src/oop/class.c" 3 4
 (*__errno_location ())
# 618 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 618 "src/oop/class.c" 3 4
 (*__errno_location ())
# 618 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  __SET_CLASS_MASK_WAS_INIT__(&(cls->mask), FALSE);
  return 
# 620 "src/oop/class.c" 3 4
        ((void *)0)
# 620 "src/oop/class.c"
            ;
}

void __class_inherit_static__(__ClassObject__* cls) {
  size_t static_fill[64 + 1];
  size_t cnt = 0;
  for (size_t i = 0; i < 64; ++i) {
    if (!*(&(cls->default_vcls->__init__) + i)) {
      static_fill[cnt++] = 1 + i;
    }
  }
  for (size_t i = cnt; i < 64 + 1; ++i) {
    static_fill[i] = 0;
  }
  if (__GET_CLASS_MASK_IS_FUNDAMENTAL__(&cls->mask)) {
    for (size_t i = 0; i < cls->inherits_from->size && cnt; ++i) {
      size_t shift = 0;
      while (static_fill[shift]) {
        if (*(&(cls->inherits_from->list[i].cls->default_vcls->__init__) +
            static_fill[shift] - 1)) {
          *(&(cls->default_vcls->__init__) + static_fill[shift] - 1) =
            *(&(cls->inherits_from->list[i].cls->default_vcls->__init__) +
            static_fill[shift] - 1);
          cls->default_vcls->__method_shift__[static_fill[shift] - 1] = cls->inherits_from->list[i].adress_shift +
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
  __vTable__** vtable = (__vTable__**)((void*)cls->default_vcls +
                                        cls->vclass_size -
                                        sizeof(void*));
  for (size_t i = cls->inherits_from->size; i > 0; --i) {
    if (!__GET_CLASS_MASK_IS_BARE__(&(cls->inherits_from->list[i - 1].cls->mask))) {
      __vTable__** vtablei = (__vTable__**)((void*)cls->inherits_from->list[i - 1].cls->default_vcls +
                                            cls->vclass_size -
                                            sizeof(void*));
      __vTable_join__(*vtable,
                      *vtablei);
      if (
# 669 "src/oop/class.c" 3 4
     (*__errno_location ()) 
# 669 "src/oop/class.c"
     || _EXCEPTION.exception_number) { _ERRORB = TRUE; break; };
    }
  }
}

void* __aux_default_delete_instance__(void* ptr) {
  free(ptr);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 676 "src/oop/class.c" 3 4
 (*__errno_location ())
# 676 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 676 "src/oop/class.c" 3 4
 (*__errno_location ())
# 676 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return 
# 677 "src/oop/class.c" 3 4
        ((void *)0)
# 677 "src/oop/class.c"
            ;
}

void* __aux_class_new_wrapper__(__ClassObject__* cls, size_t size, __ClassInstance__* template_instance) {
  void* ptr = 
# 681 "src/oop/class.c" 3 4
             ((void *)0)
# 681 "src/oop/class.c"
                 ;
  if (__GET_CLASS_MASK_IS_FUNDAMENTAL__(&cls->mask)) {
    ptr = malloc(size * cls->instance_size);
    ((ptr != 0) ? ((void*)0) : __exc_assert_fail__(&_EXCEPTION, "Assertion failed! '" "ptr != 0" "' in file " "src/oop/class.c" ":" "684", __func__, ((void*)0)) );
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 685 "src/oop/class.c" 3 4
   (*__errno_location ())
# 685 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 685 "src/oop/class.c" 3 4
   (*__errno_location ())
# 685 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(ptr), (generic_function_t)(__aux_default_delete_instance__), 0);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 687 "src/oop/class.c" 3 4
   (*__errno_location ())
# 687 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 687 "src/oop/class.c" 3 4
   (*__errno_location ())
# 687 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    for (size_t i = 0; i < size; ++i) {
      memcpy(ptr + i * cls->instance_size, template_instance, cls->instance_size);
      __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(ptr + i * cls->instance_size), (generic_function_t)(cls->__static_destroy__), 0);
      if (
# 691 "src/oop/class.c" 3 4
     (*__errno_location ()) 
# 691 "src/oop/class.c"
     || _EXCEPTION.exception_number) { _ERRORB = TRUE; break; };
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
        __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(ptr + i * cls->instance_size), (generic_function_t)(cls->__static_destroy__), 0);
        if (
# 706 "src/oop/class.c" 3 4
       (*__errno_location ()) 
# 706 "src/oop/class.c"
       || _EXCEPTION.exception_number) { _ERRORB = TRUE; break; };
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
    ((ptr != 0) ? ((void*)0) : __exc_assert_fail__(&_EXCEPTION, "Assertion failed! '" "ptr != 0" "' in file " "src/oop/class.c" ":" "721", __func__, ((void*)0)) );
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 722 "src/oop/class.c" 3 4
   (*__errno_location ())
# 722 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 722 "src/oop/class.c" 3 4
   (*__errno_location ())
# 722 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
    if (vcls->_f.__delete__) {
      __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(ptr), (generic_function_t)(vcls->_f.__delete__), 0);
    } else {
      __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(ptr), (generic_function_t)(__aux_default_delete_instance__), 0);
    }
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 728 "src/oop/class.c" 3 4
   (*__errno_location ())
# 728 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 728 "src/oop/class.c" 3 4
   (*__errno_location ())
# 728 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
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
        __scope_object_push__(&__SCOPE_OBJECT_INST__, (void*)(ptr + i * cls->instance_size), (generic_function_t)(cls->__static_destroy__), 0);
        if (
# 742 "src/oop/class.c" 3 4
       (*__errno_location ()) 
# 742 "src/oop/class.c"
       || _EXCEPTION.exception_number) { _ERRORB = TRUE; break; };
      }
    }
  }
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 746 "src/oop/class.c" 3 4
 (*__errno_location ())
# 746 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 746 "src/oop/class.c" 3 4
 (*__errno_location ())
# 746 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return ptr;
}

void* __aux_class_new_vclass_check_vclass__(void* vclass, size_t vclass_size) {
  for (size_t i = 0; i < vclass_size / sizeof(size_t); ++i) {
    if (((size_t*)vclass)[i]) {
      return vclass;
    }
  }
  return 
# 756 "src/oop/class.c" 3 4
        ((void *)0)
# 756 "src/oop/class.c"
            ;
}

void* __aux_class_new_vclass_reserve__(__ClassObject__* cls) {
  if (!cls->alloc_vcls) {
    cls->alloc_vcls = calloc(8, sizeof(void*));
    cls->__vclass_cnt = 0;
    cls->__vclass_capacity = 8;
    return cls;
  }
  __vClassObject__** tmp_vcls = cls->alloc_vcls;
  cls->__vclass_capacity *= 2;
  cls->alloc_vcls = calloc(cls->__vclass_capacity, sizeof(void*));
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 769 "src/oop/class.c" 3 4
 (*__errno_location ())
# 769 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 769 "src/oop/class.c" 3 4
 (*__errno_location ())
# 769 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  memcpy(cls->alloc_vcls, tmp_vcls, cls->__vclass_cnt);
  free(tmp_vcls);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 772 "src/oop/class.c" 3 4
 (*__errno_location ())
# 772 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 772 "src/oop/class.c" 3 4
 (*__errno_location ())
# 772 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  return cls;
}

void* __aux_class_new_vclass__(__ClassObject__* cls) {
  __vClassObject__* new_vclass = (__vClassObject__*)malloc(cls->vclass_size);
  if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 778 "src/oop/class.c" 3 4
 (*__errno_location ())
# 778 "src/oop/class.c"
 )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 778 "src/oop/class.c" 3 4
 (*__errno_location ())
# 778 "src/oop/class.c"
 ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  memcpy(new_vclass, cls->default_vcls, cls->vclass_size);
  if (!cls->alloc_vcls || (cls->__vclass_cnt + 1 == cls->__vclass_capacity)) {
    __aux_class_new_vclass_reserve__(cls);
    if (CAUGHT_EXCEPTION.exception_number) { void* __EXCEPTION_RESULT__ = __raise_exception__(&(CAUGHT_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } else { if (_ERRORB = (_EXCEPTION.exception_number || 
# 782 "src/oop/class.c" 3 4
   (*__errno_location ())
# 782 "src/oop/class.c"
   )) { if (!_EXCEPTION.exception_number) { _EXCEPTION.exception_number = 
# 782 "src/oop/class.c" 3 4
   (*__errno_location ())
# 782 "src/oop/class.c"
   ; } void* __EXCEPTION_RESULT__ = __raise_exception__(&(_EXCEPTION));; return *((void**)&(__EXCEPTION_RESULT__));; } };
  }
  cls->alloc_vcls[cls->__vclass_cnt++] = new_vclass;
  return new_vclass;
}

void* __aux_type_cast__(void* expr, type_object_t* src_type, type_object_t* trg_type, void* allocated_memory) {
  void* result = 
# 789 "src/oop/class.c" 3 4
                ((void *)0)
# 789 "src/oop/class.c"
                    ;
  if (src_type && src_type->type_meta) {
    if (trg_type && trg_type->type_meta) {
      if (src_type->type_meta->cls && trg_type->type_meta->cls) {
        return __aux_class_cast__(expr,
                                  src_type->type_meta,
                                  trg_type->type_meta,
                                  allocated_memory);
      }
      if (src_type == trg_type ||
          (strncmp(src_type->type_name,
                    trg_type->type_name,
                    256) == 0)) {
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
  void* result = 
# 825 "src/oop/class.c" 3 4
                ((void *)0)
# 825 "src/oop/class.c"
                    ;
  if (src_class) {
    if (trg_class &&
        (src_class == trg_class ||
         (strncmp(src_class->cls->name,
                  trg_class->cls->name,
                  256) == 0))) {
      return expr;
    }
    if (src_class->cls->mask & 4) {
      __InheritanceList__* list = src_class->cls->inherits_from;
      for (size_t i = 0; i < list->size; ++i) {
        if (strncmp(trg_class->cls->name, list->list->cls->name, 256) == 0) {
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
# 0 "src/oop/exception.c"
# 1 "/home/just_engineer/dev/extraslib//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "src/oop/exception.c"
# 1 "src/oop/../../src/oop/exception.h" 1
# 1 "/usr/include/errno.h" 1 3 4
# 25 "/usr/include/errno.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 415 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 416 "/usr/include/features.h" 2 3 4
# 523 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 730 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 731 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 732 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 524 "/usr/include/features.h" 2 3 4
# 547 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 548 "/usr/include/features.h" 2 3 4
# 26 "/usr/include/errno.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/lib/linux/uapi/x86/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 2 "/usr/lib/linux/uapi/x86/asm/errno.h" 2 3 4
# 2 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4









# 37 "/usr/include/errno.h" 3 4
extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 52 "/usr/include/errno.h" 3 4

# 2 "src/oop/../../src/oop/exception.h" 2

       
# 24 "src/oop/../../src/oop/exception.h"

# 24 "src/oop/../../src/oop/exception.h"
typedef struct exception_context_t
{
  char data[4096];
} exception_context_t;

extern exception_context_t _EXCEPTION_CONTEXT;
extern unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR;

typedef int exception_status_t;

typedef struct exception_t
{
  unsigned int exception_number;
  exception_status_t status;
  exception_context_t* context;
  char* exception_description;
} exception_t;

extern exception_t _EXCEPTION;

extern exception_t CAUGHT_EXCEPTION;
extern exception_context_t CAUGHT_EXCEPTION_CONTEXT;
# 54 "src/oop/../../src/oop/exception.h"
typedef char BOOL;
typedef enum { FALSE = 0, TRUE = 1} BOOL_VALUES;


extern BOOL _ERRORB;
extern void(*_EXC_ASSERT_CALLBACK)();

void* __check_uncaught_exception__(exception_t* exception);
# 87 "src/oop/../../src/oop/exception.h"
void* __raise_exception__(exception_t* exception);
# 100 "src/oop/../../src/oop/exception.h"
void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...);
# 122 "src/oop/../../src/oop/exception.h"
void* __exc_assert_fail__(exception_t* exception, char* description, const char* function_name, void(*callback)());
# 2 "src/oop/exception.c" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4

# 229 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 344 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 56 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 131 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 132 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
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
  unsigned int __g_size[2] ;
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
  unsigned int __unused_initialized_1;
  unsigned int __unused_initialized_2;
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



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__)) __attribute__ ((__cold__));



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

# 3 "src/oop/exception.c" 2
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
# 36 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
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
  int _flags2:24;

  char _short_backupbuf[1];
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

# 4 "src/oop/exception.c" 2
# 1 "/usr/include/unistd.h" 1 3 4
# 27 "/usr/include/unistd.h" 3 4

# 202 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/posix_opt.h" 1 3 4
# 203 "/usr/include/unistd.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/environments.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/environments.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/environments.h" 2 3 4
# 207 "/usr/include/unistd.h" 2 3 4
# 226 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 227 "/usr/include/unistd.h" 2 3 4
# 255 "/usr/include/unistd.h" 3 4
typedef __useconds_t useconds_t;
# 267 "/usr/include/unistd.h" 3 4
typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 287 "/usr/include/unistd.h" 3 4
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 309 "/usr/include/unistd.h" 3 4
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
# 339 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
# 358 "/usr/include/unistd.h" 3 4
extern int close (int __fd);




extern void closefrom (int __lowfd) __attribute__ ((__nothrow__ , __leaf__));







extern ssize_t read (int __fd, void *__buf, size_t __nbytes)
    __attribute__ ((__access__ (__write_only__, 2, 3)));





extern ssize_t write (int __fd, const void *__buf, size_t __n)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
# 389 "/usr/include/unistd.h" 3 4
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset)
    __attribute__ ((__access__ (__write_only__, 2, 3)));






extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset)
    __attribute__ ((__access__ (__read_only__, 2, 3)));
# 437 "/usr/include/unistd.h" 3 4
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 452 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
# 464 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);







extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));






extern int usleep (__useconds_t __useconds);
# 489 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;






extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;



extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
# 531 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
# 545 "/usr/include/unistd.h" 3 4
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__))
    __attribute__ ((__access__ (__write_only__, 1)));




extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;


extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
# 564 "/usr/include/unistd.h" 3 4
extern char **__environ;







extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 619 "/usr/include/unistd.h" 3 4
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "/usr/include/x86_64-linux-gnu/bits/confname.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT,


    _SC_MINSIGSTKSZ,


    _SC_SIGSTKSZ

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,


    _CS_V6_ENV,

    _CS_V7_ENV

  };
# 631 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));


extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));



extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 3)));




extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));

extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));






extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
# 682 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));






extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));



extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));



extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));




extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__write_only__, 2, 1)));
# 722 "/usr/include/unistd.h" 3 4
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
# 778 "/usr/include/unistd.h" 3 4
extern __pid_t fork (void) __attribute__ ((__nothrow__));







extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
# 799 "/usr/include/unistd.h" 3 4
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));



extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));




extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));




extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;




extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)))
     __attribute__ ((__access__ (__write_only__, 2, 3)));





extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;


extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)))
     __attribute__ ((__access__ (__write_only__, 3, 4)));



extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));




extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







# 1 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 3 4








extern char *optarg;
# 50 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 91 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));


# 28 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 2 3 4


# 49 "/usr/include/x86_64-linux-gnu/bits/getopt_posix.h" 3 4

# 904 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));






extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));



extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;





extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__access__ (__write_only__, 1, 2)));
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__read_only__, 1, 2)));




extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));


extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));



extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));





extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));







extern int fsync (int __fd);
# 1002 "/usr/include/unistd.h" 3 4
extern long int gethostid (void);


extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));





extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
# 1026 "/usr/include/unistd.h" 3 4
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 1049 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
# 1070 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;





extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
# 1091 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
# 1114 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1150 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);
# 1162 "/usr/include/unistd.h" 3 4
extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 1201 "/usr/include/unistd.h" 3 4
int getentropy (void *__buffer, size_t __length)
    __attribute__ ((__access__ (__write_only__, 1, 2)));
# 1221 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/unistd_ext.h" 1 3 4
# 1222 "/usr/include/unistd.h" 2 3 4


# 5 "src/oop/exception.c" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 286 "/usr/include/string.h" 3 4
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 380 "/usr/include/string.h" 3 4
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));







extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)))
    __attribute__ ((__access__ (__read_only__, 1, 2)))
    __attribute__ ((__access__ (__read_only__, 3, 4)));



extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/14/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4










extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern size_t strlcpy (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



extern size_t strlcat (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__read_write__, 1, 3)));
# 552 "/usr/include/string.h" 3 4

# 6 "src/oop/exception.c" 2


# 7 "src/oop/exception.c"
exception_t _EXCEPTION = (exception_t){};

exception_context_t _EXCEPTION_CONTEXT = (exception_context_t){};

exception_t CAUGHT_EXCEPTION = (exception_t){};

exception_context_t CAUGHT_EXCEPTION_CONTEXT = (exception_context_t){};

unsigned long __EXCEPTION_SCOPE_INDENTATION_VAR = 0;

BOOL _ERRORB = FALSE;

void* __raise_exception__(exception_t* exception) {
  _EXCEPTION = *exception;
  if (_EXCEPTION.context) {
    _EXCEPTION_CONTEXT = *(exception->context);
  }
  _ERRORB = TRUE;
  
# 25 "src/oop/exception.c" 3 4
 (*__errno_location ()) 
# 25 "src/oop/exception.c"
       = exception->exception_number;
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) {
    __exit_on_exception__(&_EXCEPTION, 0);
  }
  return ((void*)-1);
}

void* __exit_on_exception__(exception_t* exception, void*(*clean_up)(), ...) {
  if (exception->exception_number == _EXCEPTION.exception_number && _EXCEPTION.exception_number) {
    if (clean_up) {
      clean_up();
    }
    perror(_EXCEPTION.exception_description);
    const static unsigned int buffer_size = 128;
    char buffer[buffer_size];
    if (!_EXCEPTION.context) {
      _EXCEPTION.context = &_EXCEPTION_CONTEXT;
    }
    sprintf(buffer, "Terminating program with exit status %d.\n", exception->exception_number);
    write(2, buffer, strlen(buffer) + 1);
    if (_EXCEPTION.context->data[0]) {
      const char exc_ctx_str[] = "The following section is first "
                                 "32"
                                 " byte(s) of exception context:\n";
      write(2, exc_ctx_str, sizeof(exc_ctx_str));
      write(2, _EXCEPTION.context->data, 32);
    }
    (exit)(exception->exception_number);
  }
  return 
# 54 "src/oop/exception.c" 3 4
        ((void *)0)
# 54 "src/oop/exception.c"
            ;
}

void* __check_uncaught_exception__(exception_t* exception) {
  if (
# 58 "src/oop/exception.c" 3 4
     (*__errno_location ()) 
# 58 "src/oop/exception.c"
           || _EXCEPTION.exception_number) {
    __exit_on_exception__(exception, 0);
  }
  return 
# 61 "src/oop/exception.c" 3 4
        ((void *)0)
# 61 "src/oop/exception.c"
            ;
}

void* __exc_assert_fail__(exception_t* exception,
                          char* description,
                          const char* function_name,
                          void(*callback)()) {
  size_t sz = strlen(description);
  exception->context = 0;
  size_t fn_sz = strlen(function_name);
  for (size_t i = 0; i < fn_sz; ++i) {
    _EXCEPTION_CONTEXT.data[i] = function_name[i];
  }
  exception->exception_description = description;
  exception->exception_number = 256;
  
# 76 "src/oop/exception.c" 3 4
 (*__errno_location ()) 
# 76 "src/oop/exception.c"
       = 256;
  if (!__EXCEPTION_SCOPE_INDENTATION_VAR) {
    __exit_on_exception__(&_EXCEPTION, 0);
  }
  exception->status = 0;
  return 
# 81 "src/oop/exception.c" 3 4
        ((void *)0)
# 81 "src/oop/exception.c"
            ;
}
