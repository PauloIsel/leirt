#include <stdio.h>

#define MAX_PARK 300

typedef struct {
 int hour;
 int minute;
} Time;

typedef struct {
 int busy; // 0 – livre; 1 - ocupado
 Time hour_in; // tempo de entrada
} Park;

typedef struct {
 Park places[MAX_PARK]; // lugares do parque
 int total; // total dos ocupados
} Parking;

double park_calc_cost (const Time *t_in, const Time *t_out, int t_fraction, double v_fraction) {
    Time t_diff;

    t_diff.hour = t_out->hour - t_in->hour;
    t_diff.minute = t_out->minute - t_in->minute;
    if (t_diff.minute < 0) {
        t_diff.hour -= 1;
        t_diff.minute += 60 + 1 + t_diff.hour * 60;
    } else t_diff.minute += 1 + t_diff.hour * 60;

    //printf("%d\n", t_diff.minute);

    float fractioncount = t_diff.minute / t_fraction;
    //printf("div:%f\n", fractioncount);
    float nextfraction = t_diff.minute % t_fraction;
    //printf("resto:%f\n", nextfraction);
    int fractionstopay = fractioncount;

        if (nextfraction != 0) {
            fractionstopay += 1;
    }
    //printf("%d\n", fractionstopay);

    return fractionstopay * v_fraction;
}

int main() {
    Time entryTime = {20, 00}; // Tempo de entrada
    Time exitTime = {21, 01};  // Tempo de saída
    int timeFraction = 15;     // Fração de tempo em minutos
    double valueFraction = 0.5; // Valor por fração

    double cost = park_calc_cost(&entryTime, &exitTime, timeFraction, valueFraction);

    printf("Custo do estacionamento: %.2lf euros\n", cost);

    return 0;
}

