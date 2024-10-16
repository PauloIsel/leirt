#include <stdio.h>
#include <stdlib.h>

static int compare(const void* p1, const void* p2) {
    int* ptr1 = (int*) p1;
    int* ptr2 = (int*) p2;
    return *ptr1 - *ptr2;
}

static void sort(int arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);
}

void print_ints(int arr[], int n) {
    sort(arr, n);
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}