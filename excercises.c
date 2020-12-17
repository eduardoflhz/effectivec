//
// Created by Eduardo Flores on 17/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <memory.h>

#include "excercises.h"

typedef struct {
  size_t num;
  int data[];
} widget;

#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))

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

int memory_management() {
//  widget *p = malloc(sizeof(widget));
//  if (!p)
//    return EXIT_FAILURE;
//  else {
//    widget w = {"abc", 9, 3.2};
//    memcpy(p, &w, sizeof(widget));
//    printf("p.i = %d. \n", p->i);
//    return EXIT_SUCCESS;
//  }

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

int absolute_value(int a) {
  if (a < 0)
    return -a;
  return a;
}

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

void wraparound()
{
  unsigned int ui = 4294967295, sum = 2;
  if (ui > UINT_MAX - sum)
    puts("Too large!");
  else
    puts("Good");
}

#define Abs(i) ((i) < 0 ? -(i) : (i))
#define AbsM(i, flag) ((i) < 0 ? (i) : ((i)==(flag) ? (flag) : -(i)))

void overflow()
{
  signed int si = -25;
  signed int abs_sim = AbsM(si, INT_MIN);
  signed int abs_si = Abs(si);
  printf("AbsM: %d\n", abs_sim);
  printf("Abs: %d\n", abs_si);
}

const char *show_classification(double x)
{
  switch(fpclassify(x)) {
    case FP_INFINITE: return "Inf";
    case FP_NAN: return "NaN";
    case FP_NORMAL: return "normal";
    case FP_SUBNORMAL: return "subnormal";
    case FP_ZERO: return "zero";
    default: return "unknown";
  }
}

__unused void casting()
{
  int si = 5;
  short ss = 8;
  long sl = (long)si;
  unsigned short us = (unsigned short)(ss + sl);
}

__unused errno_t safe_conversion(signed long value)
{
  if ((value < SCHAR_MIN) || (value > SCHAR_MAX))
    return ERANGE;
  signed char sc = (signed char)value;
  return sc;
}
