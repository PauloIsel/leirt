#include <stdio.h>

int remove_case_letter (const char src[], char dst[], char letter) {
    int removed_letter = 0;
    int j = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        char src_curr_pos = src[i];

        if (src_curr_pos >= 'A' && src_curr_pos <= 'Z') {
            src_curr_pos += ('a' - 'A');
        }
        if (letter >= 'A' && letter <= 'Z') {
            letter += ('a' - 'A');
        }
        if (src_curr_pos != letter) {
            dst[j] = src[i];
            j++;
        } else removed_letter++;
    }
    dst[j] = '\0';

    return removed_letter;
}

int remove_all_case_letters (const char src[], char dst[], char letters[]) {
    int removed_letters = 0;

    for (int i = 0; letters[i]!= '\0'; i++) {
        int removed_letter = remove_case_letter(src, dst, letters[i]);
        removed_letters += removed_letter;
    }

    return removed_letters;
}


int main() {
    // Exemplo de uso
    const char src[] = "Hello World, how are you doing today?";
    char dst[100];  // Assumindo um tamanho máximo para dst
    char letters[] = "loH";

    int removedCount = remove_all_case_letters(src, dst, letters);

    printf("Output: %s\n", dst);
    printf("Number of characters removed: %d\n", removedCount);

    return 0;
}