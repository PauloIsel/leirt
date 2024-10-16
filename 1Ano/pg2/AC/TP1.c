#include <stdint.h>
#include <stdio.h>

# define RED_SCALE 2
# define AMBAR_SCALE 1
# define GREEN_SCALE 0

# define WARNING_TIME 300
# define CRITICAL_TIME 150

uint8_t color_histogram [3];

uint16_t times [] = { 65535 , 500 , 301 , 300 , 299 , 151 , 150 , 149 , 1 , 0 };

uint8_t color_scale ( uint16_t t ) {
    uint8_t c = GREEN_SCALE ;

    if ( t >= CRITICAL_TIME && t <= WARNING_TIME ) {
        c = AMBAR_SCALE ;
    } else if ( t < CRITICAL_TIME ) {
    c = RED_SCALE ;
    }
    return c ;
}

void test_color_scale ( uint16_t array_t [] , uint8_t array_c [] ,int16_t array_t_size ) {
    int16_t i ;

    for ( i = 0; i < array_t_size ; i ++ ) {
        array_c [color_scale (array_t [i])]++;
    }
}

int16_t main ( void ) {
    uint16_t i = 0;

    while ( i < 3 ) {
        color_histogram [ i ++] = 0;
    }
    test_color_scale ( times , color_histogram , 10 );
    return 0;
}
