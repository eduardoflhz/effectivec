//
// Created by eduardo on 12/18/20.
//
#include <math.h>

#include "fclassification.h"

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

int absolute_value(int a)
{
  if (a < 0)
    return -a;
  return a;
}
