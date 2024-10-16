#include <stdio.h>
void print_ints(int arr[], int n);
void print_doubles(double arr[], int n);

void f2() {
    int sdds = 234424;
    printf("F2 %d\n", sdds);
}

void f1() {
    static int n;
    printf("F1 %d\n", n);
    n++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6};
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    print_ints(arr, 5);
    print_doubles(arr2, 5);

    f1(); f2(); f1(); f1();
    return 0;
}