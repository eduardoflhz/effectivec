//
// Created by eduardo on 12/18/20.
//
#include <stdio.h>

#include "factorial.h"

int factorial(int n) {
  //base case
  if(n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}