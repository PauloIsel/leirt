#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 500

    int8_t tmp;
    uint16_t vowels;
    char str [] = " Helloo World !";

int16_t is_vowel (char c) {
    int16_t ret = -1;
    if (c == 'a')ret = 1;
    if (c == 'e')ret = 2;
    if (c == 'i')ret = 3;
    if (c == 'o')ret = 4;
    if (c == 'u')ret = 5;
    return ret ;
}

uint16_t count_vowels ( uint16_t len , char str [] ) {
    uint16_t i = 0;
    int16_t tmp;
    if ( len > MAX_LEN ) len = MAX_LEN ;
    vowels = 0;

    while ( i < len && str [i] != '\0' ) {
        tmp = is_vowel(str[i] );
        if ( tmp > 0 ) vowels = vowels + 1;
        i = i + 1;
    }
    return i;
}



int main () {
    uint16_t len = strlen(str);
    uint16_t num = count_vowels(len, str);
    printf("The string size = %u contains %u vowels.\n", num, vowels);
    return 0;   
}