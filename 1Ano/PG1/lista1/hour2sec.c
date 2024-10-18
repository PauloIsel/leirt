#include <stdio.h>

int main() {
    int hours, minutes, seconds, finalseconds;

    printf("Quantidade em horas, minutos e segundos: ");
    scanf("%d %d %d", &hours, &minutes, &seconds);

    finalseconds = hours * 3600 + minutes * 60 + seconds;

    printf("Quantidade em segundos: %d", finalseconds);
    return 0;

}