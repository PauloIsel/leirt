#include <stdio.h>
#include <math.h>

double dp(double x1, double y1, double x2, double y2) { //formula da distância entre 2 pontos
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main() {
    double x1, x2, y1, y2, x3, y3;

    printf("Insira as coordenadas dos três cantos do terreno:\n");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    double lado1 = dp(x1, y1, x2, y2);
    double lado2 = dp(x2, y2, x3, y3);  // calcular o comprimento de cada um dos lados do terreno
    double lado3 = dp(x3, y3, x1, y1);

    double perimetro = lado1 + lado2 + lado3;

    printf("O perímetro do terreno é %.2f\n", perimetro);
    return 0;

}
// https://pt-pt.khanacademy.org/math/geometry/hs-geo-analytic-geometry/hs-geo-distance-and-midpoints/v/distance-formula#:~:text=Aprender%20a%20calcular%20a%20distância,distância%20entre%20quaisquer%20dois%20pontos.