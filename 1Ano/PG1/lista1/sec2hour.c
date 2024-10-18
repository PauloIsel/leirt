#include <stdio.h>

int main() {
    int seconds, hours, minutes, secondsf;

    printf("Quantidade em segundos: ");
    scanf("%d", &seconds);


    hours = seconds / 3600;
    secondsf = seconds % 3600;
    minutes = secondsf / 60;
    secondsf %= 60;


    printf("Quantidade em horas, minutos e segundos: %dh %dmin e %ds\n", hours, minutes, secondsf);
    return 0;
}