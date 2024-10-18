#include <stdio.h>

int dividers_qty (int n) {
    int k = 0;
    int count = 0;

    for(k = 1; k <= n ; k++) {
        if (n % k == 0) {
        count++;
        }
    }
    return count;
}

int main() {
    int n;
    int result;

    printf("Escolha um numero inteiro:\n");
    scanf("%d", &n);

    result = dividers_qty(n);

    printf("%d e divisivel por %d numeros.", n, result);

    return 0;
}
