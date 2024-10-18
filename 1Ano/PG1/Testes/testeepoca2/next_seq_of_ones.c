#include <stdio.h>

typedef struct {
    int start;
    int size;
} range_t;

range_t next_seq_of_ones(const int bits[], int length, int start) {
    range_t result = {0, 0};

    if (start < 0 || start >= length || bits[start] == 0) {
        return result;  // Se a posição de início for inválida ou bits[start] for zero, retorna {0, 0}.
    }

    result.start = start;

    // Encontra o tamanho da sequência de uns.
    while (start < length && bits[start] == 1) {
        result.size++;
        start++;
    }

    return result;
}

int main() {
    // Exemplo de uso
    int bits[] = {0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1};
    int length = 12;

    range_t result1 = next_seq_of_ones(bits, length, 1);
    printf("Resultado 1: { %d, %d }\n", result1.start, result1.size);

    range_t result2 = next_seq_of_ones(bits, length, 5);
    printf("Resultado 2: { %d, %d }\n", result2.start, result2.size);

    range_t result3 = next_seq_of_ones(bits, length, 10);
    printf("Resultado 3: { %d, %d }\n", result3.start, result3.size);

    return 0;
}