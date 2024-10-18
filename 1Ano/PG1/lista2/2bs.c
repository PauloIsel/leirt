#include <stdio.h>

double near_pi(int n) {
    double pi_approx = 0.0;
    int sign = 1;
    int denominator = 1;

    for (int i = 0; i < n; i++) {
        pi_approx += (double) sign / denominator;
        sign *= -1; 
        denominator += 2; 
    }

    return pi_approx * 4.0; 
}

int main() {
    int n;
    printf("Digite o número de termos para calcular o valor aproximado de π: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("O número de termos deve ser pelo menos 1.\n");
        return 1; 
    }

    double approximation = near_pi(n);

    printf("O valor aproximado de π com %d termos é: %lf\n", n, approximation);

    return 0;
}
