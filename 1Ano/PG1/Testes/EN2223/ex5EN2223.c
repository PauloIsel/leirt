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

int main() {
    // Exemplo de uso
    const char src[] = "Hello World, Today i a great day!";
    char dst[100];  // Assumindo um tamanho máximo para dst
    char letter = 'a';

    int removedCount = remove_case_letter(src, dst, letter);

    printf("Output: %s\n", dst);
    printf("Number of characters removed: %d\n", removedCount);

    return 0;
}