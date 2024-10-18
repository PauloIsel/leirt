#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void chars_invert_order (char str[], int idxLeft, int idxRight) {

    while (idxLeft < idxRight) {
        char temp = str[idxLeft];
        str[idxLeft] = str[idxRight];
        str[idxRight] = temp;
        idxLeft++;
        idxRight--;
    }
}

bool word_is_capicua (char word[]) {
    int lengtharray = strlen(word);
    char invertedword[lengtharray + 1];

    strcpy (invertedword, word);
    chars_invert_order (invertedword, 0, lengtharray - 1);

    return strcmp (word, invertedword) == 0;
}

int main() {
    char words[80] = "radar";

    word_is_capicua(words) ? printf("true") : printf("false");
}