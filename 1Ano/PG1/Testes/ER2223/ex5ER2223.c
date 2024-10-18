#include <stdio.h>
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

int main() {
    char teste[] = "teste de recurso de PG1 dia 31 de janeiro";
    int len = strlen(teste);

    // Inverter a ordem dos caracteres no array
    chars_invert_order(teste, 0, len - 1);

    // Exibir o resultado
    printf("%s\n", teste);

    return 0;
}