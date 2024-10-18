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

void travel_apply_discount(agency_travel_t *ag, const date_t d, int disc) {
    for (int i = 0; i < ag->num_travels; i++) {
        if (date_weekday(ag->travels[i].departure_date) <= 4 && date_weekday(ag->travels[i].departure_date) >= 1) {
            printf("%d\n", date_weekday(ag->travels[i].departure_date));
            int discount = ag->travels[i].travel_cost * (disc / 100.0);
            ag->travels[i].travel_cost -= discount;
        }
    }
}

int main() {
    // Exemplo de uso
    agency_travel_t ag;
    ag.num_travels = 2;

    // Configuração de viagens de teste
    ag.travels[0].departure_date.day = 23;
    ag.travels[0].departure_date.month = 2;
    ag.travels[0].departure_date.year = 2024;
    ag.travels[0].travel_cost = 500.0;

    ag.travels[1].departure_date.day = 12;
    ag.travels[1].departure_date.month = 2;
    ag.travels[1].departure_date.year = 2024;
    ag.travels[1].travel_cost = 700.0;

    // Aplica desconto de 10% para viagens com partida entre segunda e quinta-feira
    travel_apply_discount(&ag, ag.travels[0].departure_date, 20);

    // Imprime os custos de viagem após o desconto
    for (int i = 0; i < ag.num_travels; i++) {
        printf("Viagem %d: Custo após desconto = %.2f\n", i + 1, ag.travels[i].travel_cost);
    }

    return 0;
}