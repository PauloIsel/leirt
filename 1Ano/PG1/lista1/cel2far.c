#include <stdio.h>
int main() {
    float celsius;
    printf("valor em celsius:");
    scanf("%f", &celsius);
    float far = celsius*(9.0/5) +32;
    printf ("valor em fahrenheit: %.3f\n", far);
    return 0;
}