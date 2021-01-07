//
// Created by eduardo on 12/18/20.
//
#include <stdio.h>
#include <limits.h>

#include "wrapflow.h"

void wraparound(void)
{
    unsigned int ui = 4294967295, sum = 2;
    if (ui > UINT_MAX - sum)
        puts("Too large!");
    else
        puts("Good");
}

#define Abs(i) ((i) < 0 ? -(i) : (i))
#define AbsM(i, flag) ((i) < 0 ? (i) : ((i)==(flag) ? (flag) : -(i)))

void overflow(void)
{
    signed int si = -25;
    signed int abs_sim = AbsM(si, INT_MIN);
    signed int abs_si = Abs(si);
    printf("AbsM: %d\n", abs_sim);
    printf("Abs: %d\n", abs_si);
}
