#include <stdio.h>

int main() {
    int numeros[4];
    int i, maior, menor;
    double media;

    for (i = 0; i < 4; i++){
    printf("Valores? \n");
    scanf("%d", &numeros[i]);
    }

    menor = maior = numeros[0];

    for (i=1; i < 4; i++) {
        if(numeros[i] < menor)
            menor = numeros[i];
        }
    for (i=1; i < 4; i++) {
        if(numeros[i] > maior)
            maior = numeros[i];
        }

    media = (numeros[0]+numeros[1]+numeros[2]+numeros[3]-maior-menor)/2.0;

    printf("Media dos intermedios: %.2f \n", media);
    return 0;
}
