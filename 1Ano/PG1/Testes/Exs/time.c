#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} time_t;

void add_time(time_t *t1, time_t *t2, time_t *result) {
    result->hours = t1->hours + t2->hours;
    result->minutes = t1->minutes + t2->minutes;
    result->seconds = t1->seconds + t2->seconds;

    if (result->seconds >= 60) {
        result->seconds -= 60;
        result->minutes++;
    }
    if (result->minutes >= 60) {
        result->minutes -= 60;
        result->hours++;
    }
    if (result->hours >= 24) {
        result->hours -= 24;
    }
}

int main() {
    time_t time1, time2, result;

    printf("Enter time1: ");
    scanf("%d:%d:%d", &time1.hours, &time1.minutes, &time1.seconds);

    printf("Enter time2: ");
    scanf("%d:%d:%d", &time2.hours, &time2.minutes, &time2.seconds);

    add_time(&time1, &time2, &result);

    printf("\nAdded time: %d:%d:%d", result.hours, result.minutes, result.seconds);

    return 0;
}