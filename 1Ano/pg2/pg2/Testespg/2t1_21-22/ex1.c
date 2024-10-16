#include "structures.h"

void fill_coord( Coord *coord, double lat, double lng ) {
    coord->lat = lat;
    coord->lng = lng;
    coord->distance = sqrt(pow(lat,2) + pow(lng,2));
    
}

int main() {
    Table table;
    table.count = 0;

    fill_coord(&table.arr[0], 3, 5);
    printf("%.2f\n", table.arr[0].lat);
    printf("%.2f\n", table.arr[0].lng);
    printf("%.2f\n", table.arr[0].distance);

    return 0;
}