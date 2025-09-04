#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <alloca.h>


double funcX2(double x) {
  return 12 * x * x - 18 * x + 2;
}

double solveF(double (*f)(double), double a, double b, double epsilon) {
  double x_mid;
  x_mid = (a + b) / 2;
  size_t iters = 0;
  printf("f(a) - f(b): %f - %f\n", f(a), f(b));
  while (((f(x_mid) * f(x_mid)) > (epsilon * epsilon)) && (iters < 256)) {
    if (f(x_mid) * f(b) >= 0) {
      b = x_mid;
    } else {
      a = x_mid;
    }
    x_mid = (a + b) / 2;
    // printf("F(X) %f\n", f(x_mid));
    iters++;
  }
  printf("SOLVED(IN %d ITERS) WITH ERROR OF %f: X IS %f\n", iters, (float)abs(f(x_mid)), (float)x_mid);
  return x_mid;
}

double solveF2(double (*f)(double), double a, double b, double epsilon) {
  double x_mid;
  double r;
  const static double alpha = 0.5;
  x_mid = (a + b) / 2;
  r = b - x_mid;
  size_t iters = (size_t)-1;
  printf("f(a) - f(b): %f - %f\n", f(a), f(b));
  while (((f(x_mid) * f(x_mid)) > (epsilon * epsilon)) && (++iters < 25)) {
    x_mid += (f(x_mid + r) - f(x_mid - r) - 2 * f(x_mid)) / \
      (2 * ((f(x_mid + epsilon) - f(x_mid)) / epsilon) + 4 * r * (f(x_mid) >= 0) / \
        (f(x_mid + r) - f(x_mid - r)));
    size_t exp = 0;
    while (((f(x_mid - r * alpha) * f(x_mid + r * alpha)) <= 0) && (exp++ < 6)) {
      r *= alpha;
    }
    r *= alpha;
  }
  printf("SOLVED(IN %d ITERS) WITH ERROR OF %f: X IS %f\n", iters, (float)abs(f(x_mid)), (float)x_mid);
  return x_mid;
}

double solveF3(double (*f)(double), double a, double b, double epsilon) {
  double x_mid;
  x_mid = (a + b) / 2;
  size_t iters = 0;
  printf("f(a) - f(b): %f - %f\n", f(a), f(b));
  while (((f(x_mid) * f(x_mid)) > (epsilon * epsilon)) && (iters < 256)) {
    x_mid = a - f(a) * (b - a) / (f(b) - f(a));
    if (f(x_mid) * f(a) < 0) {
      b = x_mid;
    } else {
      a = x_mid;
    }
    iters++;
  }
  printf("SOLVED(IN %d ITERS) WITH ERROR OF %f: X IS %f\n", iters, (float)abs(f(x_mid)), (float)x_mid);
  return x_mid;
}

double solveF4(double (*f)(double), double a, double b, double epsilon) {
  double x_mid;
  x_mid = (a + b) / 2;
  size_t iters = 0;
  printf("f(a) - f(b): %f - %f\n", f(a), f(b));
  while (((f(x_mid) * f(x_mid)) > (epsilon * epsilon)) && (iters < 256)) {
    x_mid -= f(x_mid) * (epsilon) / (f(x_mid + epsilon) - f(x_mid));
    iters++;
  }
  printf("SOLVED(IN %d ITERS) WITH ERROR OF %f: X IS %f\n", iters, (float)abs(f(x_mid)), (float)x_mid);
  return x_mid;
}

struct polynomial
{
  double* coefficients;
  size_t size;
};



void poly_init(struct polynomial* poly, size_t size, double* coefficients) {
  poly->size = size;
  poly->coefficients = (double*)calloc(size, sizeof(double));
  for (size_t i = 0; i < size; ++i) {
    poly->coefficients[i] = coefficients[i];
  }
}

void poly_destroy(struct polynomial* poly) {
  free(poly->coefficients);
  *poly = (struct polynomial){};
}

double poly_eval(struct polynomial* poly, double x) {
  double result = 0;
  for (size_t i = poly->size; i > 0; --i) {
    result = result * x + poly->coefficients[i - 1];
  }
  return result;
}

double poly_der_eval(struct polynomial* poly, double x) {
  double result = 0;
  for (size_t i = poly->size; i > 1; --i) {
    result = result * x + poly->coefficients[i - 1] * (i - 1);
  }
  return result;
}

void poly_der(struct polynomial* poly, struct polynomial* der) {
  der->size = poly->size - 1;
  for (size_t i = poly->size - 1; i > 0; --i) {
    der->coefficients[i - 1] = i * poly->coefficients[i];
  }
}

double absDBL(double __x) {
  if (__x < 0.0) {
    return -__x;
  }
  return __x;
}

double poly_newton_root(struct polynomial* poly, double a, double b, double epsilon) {
  double x_mid = (a + b) / 2;
  double dx = (b - a) / 2;
  size_t iters = 0;
  while ((absDBL(dx) > epsilon) && (iters < 256)) {
    dx = poly_eval(poly, x_mid) / poly_der_eval(poly, x_mid);
    x_mid -= dx;
    iters++;
  }
  printf("DXL %f / ITERS %d\n", (float)dx, iters);
  return x_mid;
}

size_t poly_reduce(struct polynomial* poly) {
  size_t shift = 0;
  while ((shift <= poly->size) && (poly->coefficients[shift++] == 0)) {};
  if (--shift) {
    for (size_t j = 0; j < poly->size - shift; ++j) {
      poly->coefficients[j] = poly->coefficients[j + shift];
    }
  }
  poly->size -= shift;
  return shift;
}

#define INF 1e20

void poly_find_root(struct polynomial* poly, double* roots, int* root_cnt, double epsilon) {
  if (poly->size < 3) {
    if (poly->size == 1) {
      *root_cnt = !poly->coefficients[0];
      *roots = 0;
      return;
    }
    *root_cnt = 1;
    *roots = -poly->coefficients[0] / poly->coefficients[1];
    return;
  }
  *root_cnt = 0;
  size_t shift = poly_reduce(poly);
  if (shift) {
    *root_cnt = 1;
    *roots = 0.0;
  }
  struct polynomial derivative = (struct polynomial){.size=poly->size - 1};
  derivative.coefficients = alloca((poly->size - 1) * sizeof(double));
  double* der_roots = alloca((poly->size - 1) * sizeof(double));
  int der_root_cnt = 0;
  poly_der(poly, &derivative);
  poly_find_root(&derivative, der_roots, &der_root_cnt, epsilon);
  double lbound;
  double ubound;
  if (der_root_cnt) {
    double lroot = der_roots[0];
    double rroot = der_roots[der_root_cnt - 1];
    double exp2val = 1;
    while (absDBL(poly_eval(poly, lroot)) < epsilon) {
      exp2val *= 2;
      lroot -= exp2val;
    }
    while (absDBL(poly_eval(poly, rroot)) < epsilon) {
      exp2val *= 2;
      rroot -= exp2val;
    }
    lbound = lroot;
    ubound = rroot;
    for (size_t i = 0; i < __CHAR_BIT__ * sizeof(double); ++i) {
      while (absDBL(poly_eval(poly, lbound)) < epsilon) {
        exp2val *= 2;
        lbound -= exp2val;
      }
      if (poly_eval(poly, lbound) * poly_eval(poly, lroot) > 0) {
        exp2val *= 2;
        lbound -= exp2val;
      } else {
        break;
      }
    }
    exp2val = 1;
    for (size_t i = 0; i < __CHAR_BIT__ * sizeof(double); ++i) {
      while (absDBL(poly_eval(poly, ubound)) < epsilon) {
        exp2val *= 2;
        ubound -= exp2val;
      }
      if (poly_eval(poly, ubound) * poly_eval(poly, rroot) > 0) {
        exp2val *= 2;
        ubound += exp2val;
      } else {
        break;
      }
    }
  } else {
    lbound = -INF;
    ubound = INF;
  }
  double a = lbound;
  double b;
  int skip = 0;
  for (size_t i = 0; i < der_root_cnt; ++i) {
    printf("RT_(I:%d) - %f\n", i, (float)der_roots[i]);
  }
  for (size_t i = 0; i < der_root_cnt; ++i) {
    b = der_roots[i];
    if (skip) {
      skip = 0;
      a = b;
      continue;
    }
    if (absDBL(poly_eval(poly, b)) < epsilon) {
      roots[(*root_cnt)++] = b;
      a = b;
      skip = 1;
      continue;
    }
    if ((poly_eval(poly, a) * poly_eval(poly, b)) < -epsilon) {
      roots[(*root_cnt)++] = poly_newton_root(poly, a, b, epsilon);
    }
    a = b;
  }
  b = ubound;
  if (!skip && \
      ((poly_eval(poly, a) * poly_eval(poly, b)) < -epsilon)) {
    roots[(*root_cnt)++] = poly_newton_root(poly, a, b, epsilon);
  }
}

int main() {
  double epsilon = 1e-7;
  // printf("X: %.40f\n", solveF(funcX2, 0.75, 2, epsilon));
  // // printf("X: %.40f\n", solveF2(funcX2, 0.75, 2, epsilon));
  // printf("X: %.40f\n", solveF3(funcX2, 0.75, 2, epsilon));
  // printf("X: %.40f\n", solveF4(funcX2, 0.75, 2, epsilon));
  
  struct polynomial poly = (struct polynomial){};
  double coef[] = {0, 1.0, 0, -1.0/6, 0, 1.0/120, 0, -1.0/5040};
  double roots[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int root_cnt = 0;
  for (size_t i = 0; i < (sizeof(coef) / sizeof(double)); ++i) {
    printf("C%d - %f\n", i, (float)coef[i]);
  }
  poly_init(&poly, sizeof(coef) / sizeof(double), coef);
  poly_find_root(&poly, roots, &root_cnt, epsilon);
  printf("%f - %f - %f - %f\n", (float)roots[0], (float)roots[1], (float)roots[2], (float)roots[3]);
  poly_destroy(&poly);
  return 0;
}
