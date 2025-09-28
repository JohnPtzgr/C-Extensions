#include <stdio.h>
#include "../src/oop/exception.h"
#include <assert.h>

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
      TRY {
        printf("i: %d: %d / %d = %d\n", i, i, x, test_div(x, i));
        BREAKPOINT;
        printf("CONTINUE\n");
      } CATCH {
        printf("CAUGHT\n");
        printf("The error is '%s'\n", CAUGHT_EXCEPTION.exception_description);
      } FINALLY {
        char* results[] = {" NOT", ""};
        printf("THIS IS ALWAYS EXECUTED, HOWEVER THERE WAS%s AN ERROR\n", results[_ERRORB]);
        if (_ERRORB) {
          exception_t zero_exception = (exception_t){.exception_number=EDOM,
                                                    .context=0,
                                                    .status=0,
                                                    .exception_description="Division by zero(0) error"};
          RAISE(zero_exception);
        }
      }
      BREAKPOINT;
    }
    BREAKPOINT;
  } CATCH {
    if (CAUGHT_EXCEPTION.exception_number == EDOM) {
      printf("%s\n\n", CAUGHT_EXCEPTION.exception_description);
    }
    EXC_ASSERT(add == NULL && "add is not a null");
    // assert(8 == 9 && "8 is not 9!");
    EXIT_ON(&((exception_t){.exception_number=EASSERTEXC}));
  };
  return 0;
}

int test2_pushes() {
  TRY {
    test_div(100, 9);
  } CATCH {
    printf("Tries to catch div error!\n");
    PUSH_EXCEPTION(int);
  }
  return 0;
}

int test2() {
  TRY {
    test2_pushes();
  } CATCH {
    printf("Caught pushed error!\n");
  }
  return 0;
}


int main() {
  test2();
  test1();
  return 0;
}