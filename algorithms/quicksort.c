/**
 * file quicksort.c
 * author eduardo
 * Create on Tue 2021-01-12 19:16 UTC
 * 
 */

#include "quicksort.h"
void swapval(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int lb, int ub)
{
   int pivot = a[lb];
   int start = lb, end = ub;
   while (start < end) {
       while (a[start] <= pivot) {
           start++;
       }
       while (a[end] > pivot) {
           end--; 
       }
       if (start < end) {
           swapval(&a[start], &a[end]);
       }
   }
   swapval(&a[lb], &a[end]);
   return end;
}

void quicksort(int a[], int lb, int ub)
{
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc-1);
        quicksort(a, loc+1, ub);
    }
}
