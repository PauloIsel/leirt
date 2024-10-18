#include <stdio.h>

typedef struct {
 int hours, minutes;
} Hour;

int hr_min_diff(Hour h1, Hour h2) {
    int minutesh1 = h1.hours * 60 + h1.minutes; 
    int minutesh2 = h2.hours * 60 + h2.minutes; 

    return (minutesh1 - minutesh2);
}

int main() {
    Hour time1 = {8, 30}; // 8:30 AM
    Hour time2 = {5, 45}; // 5:45 AM

    int hoursDifference = hr_min_diff(time1, time2);

    printf("Hour Difference: %d minutes\n", hoursDifference);

    return 0;
}