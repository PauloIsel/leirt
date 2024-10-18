#include <stdio.h>
#include <stdbool.h>

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

bool park_check_place(const Parking *pk, int state, int *idx) {
    if (*idx < 0 || *idx >= MAX_PARK) return false;

    if (state == 0) { // livre
        for (int i = *idx; i < MAX_PARK; i++) {
            if (pk->places[i].busy == 0) {
                *idx = i;
                return true;
            }
        }
    } else { // ocupado
        for (int i = *idx; i < MAX_PARK; i++) {
            if (pk->places[i].busy == 1) {
                *idx = i;
                return true;
            }
        }
    }

    return false;
}

int park_in (Parking *pk, Time t_in) {
    int idx = 0;

    if (park_check_place(pk, 0, &idx) == true) {
        pk->places[idx].busy = 1;
        pk->places[idx].hour_in = t_in;
        pk->total++;

        return idx;
    } else return -1;
}

int main() {
    Parking parkingLot = {
        .places[0].busy = 1,
        .total = 1,
    };

    // Testa a função park_in
    Time entryTime = {13, 30}; // Tempo de entrada
    int result = park_in(&parkingLot, entryTime);

    if (result != -1) {
        printf("Car parked at index %d\n", result);
    } else {
        printf("Parking lot is full\n");
    }

    return 0;
}