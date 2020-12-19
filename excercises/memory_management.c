//
// Created by eduardo on 12/18/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "memory_management.h"

#ifdef DMALLOC
#include <dmalloc.h>
#endif

typedef struct {
  size_t num;
  int data[];
} widget;

void usage(char *msg) {
  fprintf(stderr, "%s", msg);
//  free(msg);
  msg = NULL;
}

int memory_management(void)
{
  char *str = (char *)malloc(16);
  if (str) {
    strncpy(str, "This is a string.", 15);
    str[15] = '\0';
    printf("str = %s", str);
    free(str);
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}

void *func(size_t array_size) {
  widget *p = (widget *)malloc(sizeof(widget) + sizeof(int) * array_size);
  if (!p)
    return NULL;
  p->num = array_size;
  for (size_t i = 0; i < p->num; ++i) {
    p->data[i] = i;
  }
  for (int i = 0; i < p->num; ++i) {
    printf("%d ", p->data[i]);
  }
  return NULL;
}
