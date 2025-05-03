#ifdef __T_ARG_A__
#ifndef __CONCAT_2_MACRO__
#define __CONCAT_2_MACRO__( X, Y ) X##Y
#endif // !CONCAT_MACRO
#ifndef __TEMPLATE_1
#define __TEMPLATE_1(__T_ARG_A__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__)
#endif // !__TEMPLATE_1
#ifdef __T_ARG_H__
#define __T_ARG_CNT__ 8
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, __T_ARG_D__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__##_##__T_ARG_D__)
#endif // !__TEMPLATE_4
#else
#ifdef __T_ARG_G__
#define __T_ARG_CNT__ 7
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, __T_ARG_D__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__##_##__T_ARG_D__)
#endif // !__TEMPLATE_4
#else
#ifdef __T_ARG_F__
#define __T_ARG_CNT__ 6
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, __T_ARG_D__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__##_##__T_ARG_D__)
#endif // !__TEMPLATE_4
#else
#ifdef __T_ARG_E__
#define __T_ARG_CNT__ 5
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, __T_ARG_D__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__##_##__T_ARG_D__)
#endif // !__TEMPLATE_4
#else
#ifdef __T_ARG_D__
#define __T_ARG_CNT__ 4
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__)
#endif // !__TEMPLATE_3
#ifndef __TEMPLATE_4
#define __TEMPLATE_4(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, __T_ARG_D__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__##_##__T_ARG_D__)
#endif // !__TEMPLATE_4
#else
#ifdef __T_ARG_C__
#define __T_ARG_CNT__ 3
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__)
#endif // !__TEMPLATE_2
#ifndef __TEMPLATE_3
#define __TEMPLATE_3(__T_ARG_A__, __T_ARG_B__, __T_ARG_C__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__##_##__T_ARG_C__)
#endif // !__TEMPLATE_3
#else
#ifdef __T_ARG_B__
#define __T_ARG_CNT__ 2
#ifndef __TEMPLATE_2
#define __TEMPLATE_2(__T_ARG_A__, __T_ARG_B__, NAME) __CONCAT_2_MACRO__(NAME, _##__T_ARG_A__##_##__T_ARG_B__)
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
#else
#error NO TEMPLATE ARGUMENTS WERE PROVIDED
#endif