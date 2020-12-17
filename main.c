#include <stdio.h>
#include <stdlib.h>

#include "excercises.h"

int main(void)
{
  count();
  wraparound();
  overflow();
  printf("%s", show_classification(2.21223456));
  absolute_value(1);
  return EXIT_SUCCESS;
}
