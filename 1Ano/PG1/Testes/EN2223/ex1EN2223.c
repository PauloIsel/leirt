#include <stdio.h>
#include <stdbool.h>

bool isprime (int n) {
    if (n < 1) return false;

    for (int i = 2; i < n; i++) {
        return (n % i == 0) ? false : true;
    }
}

int main() {
    int n;

    while (scanf("%d", &n) == 1) {
        if (isprime(n)) {
            printf("Numero primo\n", n);
        } else {
            if (n > 1) {
                printf("Numero nao primo\n");
            }
        }
    }

    return 0;
}