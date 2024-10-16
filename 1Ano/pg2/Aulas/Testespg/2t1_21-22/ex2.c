#include "structures.h"

void add_coord(Table *table, Coord *coord) {
    if (table->count == N_PLACES) return;

    table->arr[table->count] = *coord;
    table->count++;
}

int main() {
    Table table;
    table.count = 0;
    Coord coord;
    coord.lat = 3;
    coord.lng = 5;
    add_coord(&table, &coord);
    printf("%.2f\n", table.arr[0].lat);
    printf("%.2f\n", table.arr[0].lng);
    return 0;
}