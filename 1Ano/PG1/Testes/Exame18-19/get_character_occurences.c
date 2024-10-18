#include <stdio.h>

void get_character_occurrences(char str[], int ocurrs[26]) {
    for (int i = 0; i < 26; i++) {
        ocurrs[i] = 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        int index = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 'a' : (str[i] >= 'A' && str[i] <= 'Z') ? str[i] - 'A' : -1;

        if (index != -1) {
            ocurrs[index]++;
        }
    }
}