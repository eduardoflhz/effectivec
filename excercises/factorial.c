//
// Created by eduardo on 12/18/20.
//
#include <stdio.h>

#include "factorial.h"

void factorial(int n) {
  int i;
  unsigned long long fact = 1;
  // shows error if the user enters a negative integer
  if (n < 0)
    printf("Error! Factorial of a negative number doesn't exist.");
  else {
    for (i = 1; i <= n; ++i) {
      fact *= i;
    }
    printf("Factorial of %d = %llu", n, fact);
  }
}