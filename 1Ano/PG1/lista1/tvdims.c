#include <stdio.h>
#include <math.h>

int main() {
    double d_p, alt, comp;

    printf("Indique a diagonal do ecrã em polegadas: ");
    scanf("%lf", &d_p);

    const double inchToCm = 2.54;
    const double compinch = 16.0;
    const double altinch = 9.0;
    double d_pcm = d_p * inchToCm;
    
    comp = (d_pcm / sqrt((compinch*compinch)+(altinch*altinch))*compinch);
    alt = (d_pcm / sqrt((compinch*compinch)+(altinch*altinch))*altinch);

    printf("O ecrã tem %.1lfcm de altura e %.1lfcm de comprimento.\n", alt, comp);
    return 0;

}