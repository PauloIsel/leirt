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


int main() {
    Parking parkingLot;
    parkingLot.total = 0; // Initialize total occupied spots

    // Initialize parkingLot places as per your requirements
    // For example, let's initialize the first 10 spots as occupied
    for (int i = 0; i < 10; i++) {
        parkingLot.places[i].busy = 1; // 1 indicates occupied
        parkingLot.total++;
        // You may also initialize the entry time if needed
    }

    // Test the park_check_place function
    int index = 5; // Start searching from index 5
    int stateToCheck = 0; // Looking for a free spot

    bool result = park_check_place(&parkingLot, stateToCheck, &index);

    if (result) {
        printf("Found a free spot at index %d\n", index);
    } else {
        printf("No free spots found\n");
    }

    return 0;
}