#ifdef __TEMPLATE__


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
  __A##_##__B##_##__C##_##__D##_##__E

#define __CONCAT_6_MACRO__( __A, __B, __C, __D, __E, __F ) \
  __A##__B##__C##__D##__E##__F
#define __CONCAT_6_MACRO_U__( __A, __B, __C, __D, __E, __F ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F

#define __CONCAT_7_MACRO__( __A, __B, __C, __D, __E, __F, __G ) \
  __A##__B##__C##__D##__E##__F##__G
#define __CONCAT_7_MACRO_U__( __A, __B, __C, __D, __E, __F, __G ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G

#define __CONCAT_8_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H ) \
  __A##__B##__C##__D##__E##__F##__G##__H
#define __CONCAT_8_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H

#define __CONCAT_9_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I
#define __CONCAT_9_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I

#define __CONCAT_10_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J
#define __CONCAT_10_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J

#define __CONCAT_11_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J##__K
#define __CONCAT_11_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J##_##__K

#define __CONCAT_12_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J##__K##__L
#define __CONCAT_12_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J##_##__K##_##__L

#define __CONCAT_13_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J##__K##__L##__M
#define __CONCAT_13_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J##_##__K##_##__L##_##__M

#define __CONCAT_14_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J##__K##__L##__M##__N
#define __CONCAT_14_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J##_##__K##_##__L##_##__M##_##__N

#define __CONCAT_15_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N, __O ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J##__K##__L##__M##__N##__O
#define __CONCAT_15_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N, __O ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J##_##__K##_##__L##_##__M##_##__N##_##__O

#define __CONCAT_16_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N, __O, __P ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J##__K##__L##__M##__N##__O##__P
#define __CONCAT_16_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N, __O, __P ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J##_##__K##_##__L##_##__M##_##__N##_##__O##_##__P

#define __CONCAT_17_MACRO__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N, __O, __P, __Q ) \
  __A##__B##__C##__D##__E##__F##__G##__H##__I##__J##__K##__L##__M##__N##__O##__P##__Q
#define __CONCAT_17_MACRO_U__( __A, __B, __C, __D, __E, __F, __G, __H, __I, __J, __K, __L, __M, __N, __O, __P, __Q ) \
  __A##_##__B##_##__C##_##__D##_##__E##_##__F##_##__G##_##__H##_##__I##_##__J##_##__K##_##__L##_##__M##_##__N##_##__O##_##__P##_##__Q
#endif // !CONCAT_MACRO


#ifndef __TEMPLATE_1
#define __TEMPLATE_1(ARG1, \
  NAME) __CONCAT_2_MACRO_U__(NAME, ARG1)

#define __TEMPLATE_2(ARG1, \
  ARG2, NAME) __CONCAT_3_MACRO_U__(NAME, \
  ARG1, ARG2)

#define __TEMPLATE_3(ARG1, \
  ARG2, ARG3, NAME) __CONCAT_4_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3)

#define __TEMPLATE_4(ARG1, \
  ARG2, ARG3, ARG4, NAME) __CONCAT_5_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4)

#define __TEMPLATE_5(ARG1, \
  ARG2, ARG3, ARG4, ARG5, NAME) __CONCAT_6_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5)

#define __TEMPLATE_6(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, NAME) __CONCAT_7_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6)

#define __TEMPLATE_7(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, NAME) __CONCAT_8_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7)

#define __TEMPLATE_8(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, NAME) __CONCAT_9_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8)

#define __TEMPLATE_9(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, NAME) __CONCAT_10_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9)

#define __TEMPLATE_10(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, NAME) __CONCAT_11_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10)

#define __TEMPLATE_11(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, NAME) __CONCAT_12_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11)

#define __TEMPLATE_12(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, NAME) __CONCAT_13_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12)

#define __TEMPLATE_13(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, NAME) __CONCAT_14_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13)

#define __TEMPLATE_14(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, NAME) __CONCAT_15_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14)

#define __TEMPLATE_15(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, NAME) __CONCAT_16_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15)

#define __TEMPLATE_16(ARG1, \
  ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16, NAME) __CONCAT_17_MACRO_U__(NAME, \
  ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16)
#endif // !__TEMPLATE_X


#ifndef __T_ARG_CNT__

#define __T_ARG_CNT__ 0 __R_ARG__

#ifdef __T_ARG_A__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 1
#endif

#ifdef __T_ARG_B__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 2
#endif

#ifdef __T_ARG_C__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 3
#endif

#ifdef __T_ARG_D__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 4
#endif

#ifdef __T_ARG_E__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 5
#endif

#ifdef __T_ARG_F__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 6
#endif

#ifdef __T_ARG_G__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 7
#endif

#ifdef __T_ARG_H__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 8
#endif

#ifdef __T_ARG_I__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 9
#endif

#ifdef __T_ARG_J__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 10
#endif

#ifdef __T_ARG_K__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 11
#endif

#ifdef __T_ARG_L__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 12
#endif

#ifdef __T_ARG_M__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 13
#endif

#ifdef __T_ARG_N__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 14
#endif

#ifdef __T_ARG_O__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 15
#endif

#ifdef __T_ARG_P__
#undef __T_ARG_CNT__
#define __T_ARG_CNT__ 16
#endif
#endif

#ifdef __T_VA__
#define __T_ARG_CNT__ 0
#define __TEMPLATE_VA(NAME) __TEMPLATE_1(__T_VA__, NAME)
#endif

#ifndef __T_ARG_A__
#define __T_ARG_A__
#endif
#ifndef __T_ARG_B__
#define __T_ARG_B__
#endif
#ifndef __T_ARG_C__
#define __T_ARG_C__
#endif
#ifndef __T_ARG_D__
#define __T_ARG_D__
#endif
#ifndef __T_ARG_E__
#define __T_ARG_E__
#endif
#ifndef __T_ARG_F__
#define __T_ARG_F__
#endif
#ifndef __T_ARG_G__
#define __T_ARG_G__
#endif
#ifndef __T_ARG_H__
#define __T_ARG_H__
#endif
#ifndef __T_ARG_I__
#define __T_ARG_I__
#endif
#ifndef __T_ARG_J__
#define __T_ARG_J__
#endif
#ifndef __T_ARG_K__
#define __T_ARG_K__
#endif
#ifndef __T_ARG_L__
#define __T_ARG_L__
#endif
#ifndef __T_ARG_M__
#define __T_ARG_M__
#endif
#ifndef __T_ARG_N__
#define __T_ARG_N__
#endif
#ifndef __T_ARG_O__
#define __T_ARG_O__
#endif
#ifndef __T_ARG_P__
#define __T_ARG_P__
#endif
#endif