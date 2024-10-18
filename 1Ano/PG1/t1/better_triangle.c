#include <stdio.h>
#include <math.h>

double dp(double x1, double y1, double x2, double y2) { //formula da distância entre 2 pontos
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double distinctpoints(double x1, double y1, double x2, double y2, double x3, double y3) { //verificar se os pontos são todos diferentes
    return ((x1 != x2 || y1 != y2) && (x1 != x3 || y1 != y3) && (x2 != x3 || y2 != y3)); 
}

double samestraight(double x1, double y1, double x2, double y2, double x3, double y3) { //usando a formula de cálculo da área do triângulo podemos concluir que, caso a preposição seja falsa, a área do triângulo será nula, o que é impossível e levará a que a combinação de pontos seja inválida
    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0;
}

int main() {
    double x1, x2, y1, y2, x3, y3;

    printf("Insira as coordenadas dos tres cantos do terreno:\n");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    if(!distinctpoints(x1, y1, x2, y2, x3, y3) || samestraight(x1, y1, x2, y2, x3, y3)) {  //caso alguma das preposições não seja cumprida, a combinação de pontos não é valida para o cálculo do perímetro
        printf("Nao e possivel medir o perimetro com a configuracao de pontos fornecida.\n");
        return 1;
    }

    double lado1 = dp(x1, y1, x2, y2);
    double lado2 = dp(x2, y2, x3, y3);     // calcular o comprimento de cada um dos lados do terreno
    double lado3 = dp(x3, y3, x1, y1);
    double perimetro = lado1 + lado2 + lado3;

    printf("O perimetro do terreno e %.2f\n", perimetro);
    return 0;
}