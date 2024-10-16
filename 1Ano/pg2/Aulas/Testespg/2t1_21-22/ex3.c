#include "structures.h"

int compare_coord(const void *coord1, const void *coord2) {
    Coord* c1 = (Coord*)coord1;
    Coord* c2 = (Coord*)coord2;
    if (c1 > c2) return -1;
    if (c1 < c2) return 0;

}

int main() {
    Table table;
    table.count = 0;
    Coord coord;
    coord.lat = 3;
    coord.lng = 5;
    compare_coord(&table.arr[0], &coord);
    printf("%.2f\n", table.arr[0].lat);
    printf("%.2f\n", table.arr[0].lng);
    printf("%.2f\n", compare_coord(&table.arr[0], &coord));
}