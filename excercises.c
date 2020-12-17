#include <ntsid.h>
//
// Created by Eduardo Flores on 17/12/20.
//
#include <stdio.h>
#include "excercises.h"
#include <limits.h>
#include <math.h>
#include <errno.h>

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