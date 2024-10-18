#include <stdio.h>
#include <stdbool.h>


bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29; 
    }
    return days[month];
}


int year_remaining_days(int day, int month, int year) {
    int daysRemaining = 0;
    for (int i = month; i <= 12; i++) {
        int daysInCurrentMonth = days_in_month(i, year);
        if (i == month) {
            daysRemaining += daysInCurrentMonth - day + 1;
        } else {
            daysRemaining += daysInCurrentMonth;
        }
    }
    return daysRemaining;
}

int main() {
    int day, month, year;

    printf("Insira o dia, mês e ano. (exemplo:5/10/2023)\n");
    scanf("%d/%d/%d", &day, &month, &year);

    int remainingDays = year_remaining_days(day, month, year);
    printf("Faltam %d dias até o final do ano %d.\n", remainingDays, year);

    return 0;
}
