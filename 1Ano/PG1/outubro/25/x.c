#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_CHAR_RESULT 100

void str_trim(char source[], char destination[]) {
    // Implemente a lógica de remoção de espaços em branco se necessário
    // Este exemplo simples apenas copia a string original para a de destino
    strcpy(destination, source);
}

bool name_middle_compressed(char orig[], char result[]) {
    int k, i = 0;
    int end_firstname = 0;
    int start_lastname = 0;
    int wordcount = 0;

    char origf[MAX_CHAR_RESULT] = "";
    str_trim(orig, origf);

    // Encontrar as posições do final do primeiro nome e do início do último nome
    for (k = 0; origf[k] != '\0'; k++) {
        if (end_firstname == 0 && isspace(origf[k])) {
            end_firstname = k;
            wordcount++;
        }

        if (isspace(origf[k])) {
            start_lastname = k;
            wordcount++;
        }
    }

    if (end_firstname == 0 || wordcount < 2) {
        return false;  // Não há nome completo para processar
    }

    // Resetar a contagem de palavras
    wordcount = 0;

    // Percorrer a string original para formar o resultado
    for (k = 0; origf[k] != '\0'; k++) {
        if (k < end_firstname || k > start_lastname) {
            result[i++] = (k == 0 || k == start_lastname) ? toupper(origf[k]) : tolower(origf[k]);
        } else if (isalpha(origf[k]) && isspace(origf[k - 1])) {
            // Se é uma letra e vem após um espaço em branco, adiciona a primeira letra por extenso
            result[i++] = ' ';
            result[i++] = toupper(origf[k]);

            // Adicionar letras adicionais até o próximo espaço ou fim da string
            while (isalpha(origf[k + 1])) {
                result[i++] = tolower(origf[++k]);
            }

            // Adicionar o ponto após a última letra
            result[i++] = '.';
        }
    }

    result[i++] = '\0';  // Adicionar o terminador nulo
    return true;
}

int main() {
    char orig[] = "pedro manoel v. rodrigues";
    char result[MAX_CHAR_RESULT];

    if (name_middle_compressed(orig, result)) {
        printf("Nome formatado: %s\n", result);
    } else {
        printf("Nome inválido.\n");
    }

    return 0;
}
