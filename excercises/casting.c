//
// Created by eduardo on 12/18/20.
//

#include "casting.h"

void casting()
{
  int si = 5;
  short ss = 8;
  long sl = (long)si;
  unsigned short us = (unsigned short)(ss + sl);
}

int safe_conversion(signed long value)
{
  if ((value < SCHAR_MIN) || (value > SCHAR_MAX))
    return ERANGE;
  signed char sc = (signed char)value;
  return sc;
}
