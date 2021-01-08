#include <stdio.h>
#include <stdlib.h>

#include "excercises/casting.h"
#include "excercises/count.h"
#include "excercises/fclassification.h"
#include "excercises/memory_management.h"
#include "excercises/wrapflow.h"
#include "excercises/factorial.h"
#include "excercises/bubble.h"
#include "excercises/fibbonacci.h"
//#include "excercises/locale.h"
#include "excercises/file.h"

int main(int argc, char *argv[])
{
    count();
    wraparound();
    overflow();
    printf("%s", show_classification(2.21223456));
    absolute_value(1);
    memory_management();
    func(14);
    //if (argc != 3 && argc != 4) {
    //    char *errmsg = (char *)malloc(80);
    //    sprintf(
    //            errmsg,
    //            "Sorry %s\n",
    //            getenv("USER")
    //           );
    //    usage(errmsg);
    //    free(errmsg);
    //    exit(EXIT_FAILURE);
    //}
    printf("Factorial: %llu\n", factorial(5));
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);
    for(int i = 1;i<50; ++i) {
        printf("%llu ",factorial(i));
    }
    //locale();
    open_file();
    open_file_alt();
    printf("status: %d", formatted());
    return EXIT_SUCCESS;
}
