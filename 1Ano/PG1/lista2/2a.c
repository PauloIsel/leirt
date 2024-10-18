#include <stdio.h>

int main() {

    int num; 
    int n = 0;
    int count = 0;
    int alleq;
    int increasing;
    int decreasing;

    do {
        printf("Digite um número:");
        scanf("%d", &num);
        count++;
    }

    while (n != num);

        if (n != num) {
            alleq = 0;
        }
        if (num < n) {
            increasing = 0;
        }
        if (num > n) {
            decreasing = 0;
        }
        n = num;
    
        if(count <= 2 && n == num)
            printf("Digite pelo menos 2 digitos diferentes de 0.");

        if (alleq && count > 2) {
            printf("Todos iguais\n");
        } else if (increasing && count > 2) {
            printf("Em ordem crescente\n");
        } else if (decreasing && count > 2) {
            printf("Em ordem decrescente\n");
        } else if(count > 2) {
            printf("Em ordem arbitrária\n");
        }
    return 0;
}