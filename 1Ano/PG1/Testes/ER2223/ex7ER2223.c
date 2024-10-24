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


bool phrase_is_capicua (char words[]) {
    int lengtharray = strlen (words);
    char phrase_no_spaces[lengtharray + 1];
    int nospace = 0;

    for (int k = 0; k < lengtharray; k++) {
        if (words[k] != ' ') {
            phrase_no_spaces[nospace] = words[k];
            nospace++;
        }
    }
    phrase_no_spaces[nospace] = '\0';

    return word_is_capicua(phrase_no_spaces);
}

int main() {
    char words[80]="anotaram a data da maratona";
    
    phrase_is_capicua(words) ? printf("true") : printf("false");
}