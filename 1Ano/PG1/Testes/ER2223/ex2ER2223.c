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
    int num;
    int result;

    printf("N ? ");

    while (scanf("%d", &num) == 1) {
        if (num >= 1) {
            result = dividers_qty(num);
            printf("count = %d \n", result);
            printf("N ?\n");
        }
    }
     return 0;
}