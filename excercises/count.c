//
// Created by eduardo on 12/18/20.
//

#include <stdio.h>
#include "count.h"

unsigned int counter = 0;

void increment(void)
{
  counter++;
}

void retrieve(void)
{
  printf("%d\n", counter);
}

void count()
{
  for (int i = 0; i < 5; ++i) {
    retrieve();
    increment();
  }
  retrieve();
}