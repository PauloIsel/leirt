#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool name_middle_compressed(char orig[], char result[]) {
    int k = 0, j = 0;
    bool has_first_name = false, has_last_name = false;

    // Remover espaços iniciais
    while (isspace(orig[k]))
        k++;

    // Percorrer o nome original
    while (orig[k] != '\0') {
        // Se encontrar um caractere não espaço
        if (!isspace(orig[k])) {
            // Se não temos o primeiro nome, estamos no primeiro nome
            if (!has_first_name) {
                result[j++] = toupper(orig[k]);
                has_first_name = true;
            }
            // Se já temos o primeiro nome, verificamos os nomes do meio
            else {
                // Se encontrarmos um espaço e o próximo caractere não for espaço
                if (orig[k] == ' ' && orig[k + 1] != ' ') {
                    // Verificamos se o nome do meio é grande o suficiente para ser abreviado
                    if (strlen(result) > 2) {
                        result[j++] = toupper(orig[k + 1]);
                        result[j++] = '.';
                    }
                }
                // Se não for um espaço, adicionamos o caractere ao resultado
                else {
                    result[j++] = orig[k];
                }
            }
        }

        k++;
    }

    // Remover espaços finais
    while (isspace(result[j - 1])) {
        result[j - 1] = '\0';
        j--;
    }

    // Adicionar o último nome, se houver
    if (has_first_name) {
        // Encontrar o último espaço no resultado
        int last_space = j - 1;
        while (last_space >= 0 && !isspace(result[last_space]))
            last_space--;

        // Adicionar o último nome, se encontrado
        if (last_space >= 0) {
            for (int i = last_space + 1; i < j; i++) {
                result[j++] = toupper(result[i]);
            }
            result[j++] = '\0';
            has_last_name = true;
        }
    }

    // Se tiver pelo menos um nome próprio e um apelido, a conversão é bem-sucedida
    return has_first_name && has_last_name;
}

int main() {
    char orig[] = "  pedro manuel  vieira   rodrigues  ";
    char result[100];  // Tamanho arbitrário, ajuste conforme necessário

    if (name_middle_compressed(orig, result)) {
        printf("Nome original: %s\n", orig);
        printf("Conversão: %s\n", result);
    } else {
        printf("A conversão não foi possível.\n");
    }

    return 0;
}
