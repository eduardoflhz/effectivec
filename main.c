#include <stdio.h>
#include <stdlib.h>

static unsigned int counter = 0;

void increment(void) {
  counter++;
  printf("%d", counter);
}

void retrieve(void) {
  printf("%d", counter);
}

int main(void) {
  for (int i = 0; i < 5; ++i) {
    increment();
    retrieve();
  }
  return EXIT_SUCCESS;
}
