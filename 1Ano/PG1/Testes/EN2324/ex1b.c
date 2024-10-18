#include <stdio.h>
#include <stdbool.h>

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


bool friendly_numbers(int n1, int n2) {
    if(sum_divisors(n1) == n2 && sum_divisors(n2) == n1) {
        return true;
    } else {
    return false;
    }

}

int main() {
    int n1, n2;

    while(1) {
        scanf("%d %d", &n1, &n2);
        if(friendly_numbers(n1, n2)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}