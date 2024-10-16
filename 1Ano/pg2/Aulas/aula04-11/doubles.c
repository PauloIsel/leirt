#include <stdio.h>
#include <stdlib.h>


static int compare(const void* p1, const void* p2) {
    double* ptr1 = (double*) p1;
    double* ptr2 = (double*) p2;
    return *ptr1 - *ptr2;
}

static void sort(double arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);
}

void print_doubles(double arr[], int n) {
    sort(arr, n);
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%f, ", arr[i]);
    }
    printf("}\n");
}