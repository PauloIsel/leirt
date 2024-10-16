#include <stdint.h>
#define ARRAY_SIZE 7
#define MARK 645
    uint8_t counter ;
    uint16_t array [] = {125 , 10 , 205 , 34 , 220 , 150 , 170};
    
void count_bigger ( uint16_t reference ) {
    uint8_t index = 0;
    counter = 0;
    while ( index < ARRAY_SIZE ) {
        int16_t tmp = compare ( reference , array [ index ] );
    if ( tmp > 0 ) counter ++;
    index ++;
    }
}
int16_t compare ( uint16_t reference , uint16_t value ) {
    int16_t result = 0;
    if ( value < reference ) result = - MARK ;
    else if ( value > reference ) result = MARK ;
    return result ;
}