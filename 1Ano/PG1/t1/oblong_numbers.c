#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é oblongo.
bool is_oblong(int n) {
    int i;
    for (i = 1; i * (i + 1) <= n; i++) {
        if (i * (i + 1) == n) {
            return true; // O número é oblongo.
        }
    }
    return false; // O número não é oblongo.
}

int main() {
    int num;

    while (1) {
        printf("Digite um numero inteiro (ou qualquer caractere não digito para sair): ");
        if (scanf("%d", &num) != 1) {
            // Se a entrada não for um número inteiro, saia do loop.
            break;
        }

        if (is_oblong(num)) {
            printf("E oblongo\n");
        }
    }

    return 0;
}
