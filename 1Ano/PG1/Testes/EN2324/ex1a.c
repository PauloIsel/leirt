#include <stdio.h>

int sum_divisors(int n) {
    int divisors_sum = 0;
    int div = 0;

    for(int i = 1; i < n; i++) {
        if (n % i == 0) {
            div = i;
            divisors_sum += div;
        }
    }
    return divisors_sum;
}

int main() {
    int n;

    while(scanf("%d", &n) == 1) { 
        printf("%d\n", sum_divisors(n));
    }

    return 0;	
}