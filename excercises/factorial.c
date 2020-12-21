//
// Created by eduardo on 12/18/20.
//
#include <stdio.h>

#include "factorial.h"

unsigned long long factorial(unsigned int n) {
  if(n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}