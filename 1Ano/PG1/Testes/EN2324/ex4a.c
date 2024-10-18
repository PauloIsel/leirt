#include <stdio.h>
#include <stdbool.h>

#define MAX_NAME 80
#define MAX_T 1000

typedef struct {
    int day;
    int month;
    int year;
} date_t;

typedef struct {
    char arrival_city[MAX_NAME];
    float travel_cost;
    date_t departure_date;
} travel_t;

typedef struct {
    travel_t travels[MAX_T];
    int num_travels;
} agency_travel_t;

int date_cmp(const date_t d1, const date_t d2) {
    if (d1.year < d2.year) return -1;
    if (d1.year == d2.year) return 0;
    if (d1.year > d2.year) return 1;
    if (d1.month < d2.month) return -1;
    if (d1.month == d2.month) return 0;
    if (d1.month > d2.month) return 1;
    if (d1.day < d2.day) return -1;
    if (d1.day == d2.day) return 0;
    if (d1.day > d2.day) return 1;
}

int date_weekday(const date_t d) {
    return d.day % 7;
}

bool travel_add(agency_travel_t *ag, const travel_t *tr) {
    if (ag->num_travels >= MAX_T) {
        return false;
    }

    for (int i = 0; i < ag->num_travels; i++) {
        if (date_cmp(ag->travels[i].departure_date, tr->departure_date) == 0) {
            int j;
            for (j = 0; tr->arrival_city[j] != '\0' && ag->travels[i].arrival_city[j] != '\0'; j++) {
                if (tr->arrival_city[j] != ag->travels[i].arrival_city[j]) {
                    break;
                }
            }
            if (tr->arrival_city[j] == '\0' && ag->travels[i].arrival_city[j] == '\0') {
                return false;
            }
        }
    }

    // Add the travel to the agency
    ag->travels[ag->num_travels] = *tr;
    ag->num_travels++;

    printf("Travel added successfully.\n");
    return true;
}