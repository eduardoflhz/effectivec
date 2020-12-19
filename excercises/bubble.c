//
// Created by eduardo on 12/19/20.
//

#include <stdio.h>
#include "bubble.h"

void swap(int *xp, int *yp)
{
  *xp = *xp*(*yp);
  *yp = *xp/(*yp);
  *xp = *xp/(*yp);
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      swap(&arr[i],&arr[i + 1]);
    }
  }
  if (n - 1 > 1) {
    bubbleSort(arr, n - 1);
  }
}

void printArray(int arr[], int n)
{
  puts("Bubble sort: ");
  for (int k = 0; k < n; ++k) {
    printf("%d, ", arr[k]);
  }
}