#include <stdio.h>

int inverts(int n) {
        int result = 0;

        while(n > 0) {
            int lastnum = n % 10;
            result = result * 10 + lastnum;
            n = n / 10;
        }

        return result;
    }

int main() {
    int number;

    while (scanf("%d", &number) == 1) {
        printf("%d\n", inverts(number));
    }

    return 0;
}