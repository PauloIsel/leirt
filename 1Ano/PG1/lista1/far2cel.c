#include <stdio.h>
int main() {
    float fahrenheit;
    printf("Insira o valor em graus fahrenheit:");
    scanf("%f", &fahrenheit);
    float far = (fahrenheit - 32.0)/1.8;
    printf("Valor em graus celsius: %.2f\n", far);
    return 0;
}
