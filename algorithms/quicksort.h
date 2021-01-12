/**
 * \file quicksort.h
 * \author eduardo
 * Create on Tue 2021-01-12 19:16 UTC
 * 
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H
void swap(int *xp, int *yp);
int partition(int a[], int lb, int ub);
void quicksort(int a[], int lb, int ub);
#endif

