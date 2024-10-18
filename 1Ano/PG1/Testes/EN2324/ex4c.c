#include <stdio.h>

#include <stdio.h>

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
    int day = d.day;
    int month = d.month;
    int year = d.year;

    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int day_of_week = (day + 13 * (month + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    return (day_of_week + 6) % 7;
}

int travel_cheaper(agency_travel_t *ag, const date_t d1, const date_t d2, const char destination[]) {
    if (ag->num_travels == MAX_T) return -1;

    float cheapest_travel = ag->travels[0].travel_cost;

    for (int i = 0; i < ag->num_travels; i++) {
        if(date_cmp(d1, ag->travels[i].departure_date) >= 0 && date_cmp(d2, ag->travels[i].departure_date) <= 0) {

            int same_destination = 1;
            for (int j = 0; destination[j] != '\0' && ag->travels[i].arrival_city[j] != '\0'; j++) {
                if (ag->travels[i].arrival_city[j] != destination[j]) {
                    same_destination = 0;
                    break;
                }
            }
            if (same_destination) {
                if (ag->travels[i].travel_cost < cheapest_travel) {
                    cheapest_travel = ag->travels[i].travel_cost;
                }
            }
        }

    }
    
    return (cheapest_travel == ag->travels[0].travel_cost)? -1 : cheapest_travel;
}
