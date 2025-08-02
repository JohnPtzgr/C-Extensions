#ifdef __TEMPLATE__
#ifdef __T_ARG_A__
#ifndef __CONCAT_1_MACRO__
#define __CONCAT_1_MACRO__( __A ) \
  __A
#define __CONCAT_1_MACRO_U__( __A ) \
  __A
#define __CONCAT_2_MACRO__( __A, __B ) \
  __A##__B
#define __CONCAT_2_MACRO_U__( __A, __B ) \
  __A##_##__B
#define __CONCAT_3_MACRO__( __A, __B, __C ) \
  __A##__B##__C
#define __CONCAT_3_MACRO_U__( __A, __B, __C ) \
  __A##_##__B##_##__C
#define __CONCAT_4_MACRO__( __A, __B, __C, __D ) \
  __A##__B##__C##__D
#define __CONCAT_4_MACRO_U__( __A, __B, __C, __D ) \
  __A##_##__B##_##__C##_##__D
#define __CONCAT_5_MACRO__( __A, __B, __C, __D, __E ) \
  __A##__B##__C##__D##__E
#define __CONCAT_5_MACRO_U__( __A, __B, __C, __D, __E ) \
  __A##_##__B##_##__C##_##__D##__E
#define __CONCAT_6_MACRO__( __A, __B, __C, __D, __E, __F ) \
  __A##__B##__C##__D##__E##__F
#define __CONCAT_6_MACRO_U__( __A, __B, __C, __D, __E, __F ) \
  __A##_##__B##_##__C##_##__D##__E##__F
#define __CONCAT_7_MACRO__( __A, __B, __C, __D, __E, __F, __G ) \
  __A##__B##__C##__D##__E##__F##__G
#define __CONCAT_7_MACRO_U__( __A, __B, __C, __D, __E, __F, __G ) \
  __A##_##__B##_##__C##_##__D##__E##__F##__G
#define __CONCAT_8_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H ) \
  __A##__B##__C##__D##__E##__F##__G##__H
#define __CONCAT_8_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H ) \
  __A##_##__B##_##__C##_##__D##__E##__F##__G##__H
#define __CONCAT_9_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I
#define __CONCAT_9_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I ) \
  __A##_##__B##_##__C##_##__D##__E##__F##__G##__H##__I
#endif // !CONCAT_MACRO
#ifndef __TEMPLATE_1
#define __TEMPLATE_1(ARG1, \
  NAME) __CONCAT_2_MACRO_U__(NAME, ARG1)
#endif // !__TEMPLATE_1
#ifdef __T_ARG_H__
#define __T_ARG_CNT__ 8
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(ARG1, \
  ARG2, ARG3, NAME) __CONCAT_4_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(ARG1, \
  ARG2, ARG3, ARG4, NAME) __CONCAT_5_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4)
#endif // !__TEMPLATE_4
#ifndef __TEMPLATE_5
#define __TEMPLATE_5(ARG1, \
  ARG2, ARG3, ARG4, ARG5, NAME) __CONCAT_6_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // !__TEMPLATE_5
#ifndef __TEMPLATE_6
#define __TEMPLATE_6(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, NAME) __CONCAT_7_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6)
#endif // !__TEMPLATE_6
#ifndef __TEMPLATE_7
#define __TEMPLATE_7(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, NAME) __CONCAT_8_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7)
#endif // !__TEMPLATE_7
#ifndef __TEMPLATE_8
#define __TEMPLATE_8(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, NAME) __CONCAT_9_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8)
#endif // !__TEMPLATE_8
#else
#ifdef __T_ARG_G__
#define __T_ARG_CNT__ 7
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(ARG1, \
  ARG2, ARG3, NAME) __CONCAT_4_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(ARG1, \
  ARG2, ARG3, ARG4, NAME) __CONCAT_5_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4)
#endif // !__TEMPLATE_4
#ifndef __TEMPLATE_5
#define __TEMPLATE_5(ARG1, \
  ARG2, ARG3, ARG4, ARG5, NAME) __CONCAT_6_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // !__TEMPLATE_5
#ifndef __TEMPLATE_6
#define __TEMPLATE_6(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, NAME) __CONCAT_7_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6)
#endif // !__TEMPLATE_6
#ifndef __TEMPLATE_7
#define __TEMPLATE_7(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, NAME) __CONCAT_8_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7)
#endif // !__TEMPLATE_7
#else
#ifdef __T_ARG_F__
#define __T_ARG_CNT__ 6
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(ARG1, \
  ARG2, ARG3, NAME) __CONCAT_4_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(ARG1, \
  ARG2, ARG3, ARG4, NAME) __CONCAT_5_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4)
#endif // !__TEMPLATE_4
#ifndef __TEMPLATE_5
#define __TEMPLATE_5(ARG1, \
  ARG2, ARG3, ARG4, ARG5, NAME) __CONCAT_6_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // !__TEMPLATE_5
#ifndef __TEMPLATE_6
#define __TEMPLATE_6(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, NAME) __CONCAT_7_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6)
#endif // !__TEMPLATE_6
#else
#ifdef __T_ARG_E__
#define __T_ARG_CNT__ 5
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(ARG1, \
  ARG2, ARG3, NAME) __CONCAT_4_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(ARG1, \
  ARG2, ARG3, ARG4, NAME) __CONCAT_5_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4)
#endif // !__TEMPLATE_4
#ifndef __TEMPLATE_5
#define __TEMPLATE_5(ARG1, \
  ARG2, ARG3, ARG4, ARG5, NAME) __CONCAT_6_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // !__TEMPLATE_5
#else
#ifdef __T_ARG_D__
#define __T_ARG_CNT__ 4
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(ARG1, \
  ARG2, ARG3, NAME) __CONCAT_4_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(ARG1, \
  ARG2, ARG3, ARG4, NAME) __CONCAT_5_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4)
#endif // !__TEMPLATE_4
#else
#ifdef __T_ARG_C__
#define __T_ARG_CNT__ 3
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(ARG1, \
  ARG2, ARG3, NAME) __CONCAT_4_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3)
#endif // !__TEMPLATE_3
#else
#ifdef __T_ARG_B__
#define __T_ARG_CNT__ 2
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)
#endif // !__TEMPLATE_2
#else
#define __T_ARG_CNT__ 1
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#ifdef __T_VA__
#define __T_ARG_CNT__ 0
#define __TEMPLATE_VA(NAME) __TEMPLATE_1(__T_VA__, NAME)
#endif
#else
#error NO TEMPLATE ARGUMENTS WERE PROVIDED
#endif
#endif