#include <stdio.h>
#include <stdlib.h>

#include "excercises/casting.h"
#include "excercises/count.h"
#include "excercises/fclassification.h"
#include "excercises/memory_management.h"
#include "excercises/wrapflow.h"
#include "excercises/factorial.h"


int main(int argc, char *argv[])
{
  count();
  wraparound();
  overflow();
  printf("%s", show_classification(2.21223456));
  absolute_value(1);
  memory_management();
  func(14);
  if (argc != 3 && argc != 4) {
    char *errmsg = (char *)malloc(80);
    sprintf(
      errmsg,
      "Sorry %s\n",
      getenv("USER")
      );
    usage(errmsg);
    free(errmsg);
    exit(EXIT_FAILURE);
  }
  factorial(10);
  return EXIT_SUCCESS;
}
