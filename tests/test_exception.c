#include <stdio.h>
#include "../src/oop/exception.h"
#include <assert.h>
#include "string.h"
#include "stdlib.h"

// The function never causes the program to terminate or exit early
#define _NoThrow

// The function never raises an exception
#define _NoExcept

/*
* This function calculates the sum of two integers.
* It takes two integer arguments and returns their sum.
*/
_NoThrow _NoExcept int add(int a, int b) {
  return a + b;
}

int test_div(int x, int y) {
  if (!y) {
    exception_t zero_exception = (exception_t){.exception_number=EDOM,
                                               .context=0,
                                               .status=0,
                                               .exception_description="Division by zero(0) error"};
    THROW(int, zero_exception);
    // RAISE(zero_exception);
  }
  // assert(x == y);
  EXC_ASSERT(x == 10 * y);
  printf("%d - %d\n", x, y);
  return x / y;
}

int test1() {
  TRY {
    int x = 100;
    for (int i = 10; i >= -10; --i) {
      exception_t exc = (exception_t){.exception_number=9, .exception_description=NULL + 0*(size_t)("9 exc"), .context=&EXCEPTION_CTX_LTR};
      strcpy(exc.context->data, "AbCdEfGhI\n");
      TRY {
        printf("i: %d: %d / %d = %d\n", i, i, x, test_div(x, i));
        BREAKPOINT;
        printf("CONTINUE\n");
        RAISE(exc)
      } CATCH(errexc) {
        char* s = (char*)exception_str(&caught_exception);
        printf("%s\n", s);
        free(s);
        printf("CAUGHT cvc\n");
        printf("The error is '%s'\n", caught_exception.exception_description);
      } FINALLY {
        char* results[] = {" NOT", ""};
        printf("THIS IS ALWAYS EXECUTED, HOWEVER THERE WAS%s AN ERROR\n", results[exception_was_caught]);
        if (exception_was_caught) {
          exception_t zero_exception = (exception_t){.exception_number=EDOM,
                                                     .context=0,
                                                     .status=0,
                                                     .exception_description="Division by zero(0) error"};
          RAISE(zero_exception);
        }
        BREAKPOINT;
        printf("This is only printed if there were no exceptions above\n");
      }
      BREAKPOINT;
    }
    BREAKPOINT;
  } CATCH(errexc) {
    if (caught_exception.exception_number == EDOM) {
      printf("%s\n\n", caught_exception.exception_description);
    }
    // EXC_ASSERT(add == NULL && "add is not a null");
    // assert(8 == 9 && "8 is not 9!");
    // EXIT_ON(&((exception_t){.exception_number=EASSERTEXC}));
  } FINALLY {
    printf("Finally! Not really :(\n");
    THROW(int);
  };
  {
    TRY {
      printf("Second TRY/CATCH\n");
    } CATCH(errexc) {
      BREAKPOINT
    };
  }
  return 0;
}

int test2_pushes() {
  TRY {
    test_div(100, 9);
  } CATCH(errexc) {
    printf("Tries to catch div error!\n");
    PUSH_EXCEPTION(int);
  }
  return 0;
}

_NoThrow _NoExcept int test2() {
  TRY {
    test2_pushes();
  } CATCH(errexc) {
    printf("Caught pushed error!\n");
  }
  return 0;
}


int test3_1() {
  printf("1+-\n");
  errctx = EXCEPTION_CTX_LTR;
  exception_t exc = (exception_t){.exception_number=9,
                                  .exception_description="9 exc",
                                  .context=&errctx};
  strcpy(exc.context->data, "AbCdEfGhI\n");
  THROW(int, exc);
  return 0;
}

int test3_2() {
  TRY {
    printf("2+\n");
    test3_1();
  } CATCH(errexc) {
    printf("2-\n");
    THROW(int);
  }
  return 0;
}

int test3_3() {
  TRY {
    printf("3+\n");
    test3_2();
  } CATCH(errexc) {
    printf("3-\n");
    THROW(int);
  }
  return 0;
}

int test3_4() {
  TRY {
    printf("4+\n");
    test3_3();
  } CATCH(errexc) {
    printf("4-\n");
    THROW(int);
  }
  return 0;
}

int test3_5() {
  TRY {
    printf("5+\n");
    test3_4();
  } CATCH(errexc) {
    printf("5-\n");
    THROW(int);
  }
  return 0;
}

int test3() {
  TRY {
    printf("TST-3\n");
    test3_5();
  } CATCH(errexc) {
    char* exc_str = (char*)exception_str(&caught_exception);
    printf(exc_str);
    free(exc_str);
    test3_5();
  }
  return 0;
}


int main() {
  test3();
  test2();
  test1();
  return 0;
}