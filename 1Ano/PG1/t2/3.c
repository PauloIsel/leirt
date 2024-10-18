#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIME_SIZE 13 // "hh:mm:ss,xxx\0"
#define BUFFER_SIZE 1024 // Tamanho do buffer para ler as linhas

// Função para converter tempo de legenda em milissegundos
long convert_to_milliseconds(const char *time_str) {
    int hours, minutes, seconds, milliseconds;
    sscanf(time_str, "%02d:%02d:%02d,%03d", &hours, &minutes, &seconds, &milliseconds);
    return (long)hours * 3600000 + (long)minutes * 60000 + (long)seconds * 1000 + milliseconds;
}

// Função para formatar tempo de milissegundos de volta para string de tempo
void format_time(long milliseconds, char *time_str) {
    int hours = (int)(milliseconds / 3600000);
    milliseconds %= 3600000;
    int minutes = (int)(milliseconds / 60000);
    milliseconds %= 60000;
    int seconds = (int)(milliseconds / 1000);
    milliseconds %= 1000;
    sprintf(time_str, "%02d:%02d:%02d,%03d", hours, minutes, seconds, (int)milliseconds);
}

// Função para copiar e ajustar o segundo arquivo
void copy_and_adjust(FILE *src, FILE *dest, long offset, int *sequence_number) {
    char line[BUFFER_SIZE];
    char time_str_start[TIME_SIZE];
    char time_str_end[TIME_SIZE];
    long start, end;

    while (fgets(line, BUFFER_SIZE, src) != NULL) {
        if (sscanf(line, "%d", sequence_number) == 1) {
            // Imprime o número de sequência incrementado
            fprintf(dest, "%d\n", (*sequence_number)++);

            // Lê e ajusta os tempos de início e fim
            fgets(line, BUFFER_SIZE, src);
            sscanf(line, "%12s --> %12s", time_str_start, time_str_end);
            start = convert_to_milliseconds(time_str_start) + offset;
            end = convert_to_milliseconds(time_str_end) + offset;
            format_time(start, time_str_start);
            format_time(end, time_str_end);
            fprintf(dest, "%s --> %s\n", time_str_start, time_str_end);
        } else {
            // Copia a linha de texto ou linha em branco
            fputs(line, dest);
        }
    }
}

int main() {
    char first_file_name[BUFFER_SIZE];
    char second_file_name[BUFFER_SIZE];
    char output_file_name[BUFFER_SIZE];
    char last_time_str[TIME_SIZE];
    long offset;
    int sequence_number = 1;

    // Solicita ao usuário os nomes dos arquivos e a última hora do primeiro arquivo
    printf("Digite o nome do primeiro arquivo de legendas: ");
    scanf("%s", first_file_name);
    printf("Digite o nome do segundo arquivo de legendas: ");
    scanf("%s", second_file_name);
    printf("Digite o nome do arquivo de legendas de saída: ");
    scanf("%s", output_file_name);
    printf("Digite o último tempo do primeiro arquivo de legendas (hh:mm:ss,xxx): ");
    scanf("%s", last_time_str);

    // Converte o último tempo do primeiro arquivo para milissegundos
    offset = convert_to_milliseconds(last_time_str);

    FILE *first_file = fopen(first_file_name, "r");
    FILE *second_file = fopen(second_file_name, "r");
    FILE *output_file = fopen(output_file_name, "w");

    // Verifica se os arquivos foram abertos com sucesso
    if (first_file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo: %s\n", first_file_name);
        return EXIT_FAILURE;
    }
    if (second_file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo: %s\n", second_file_name);
        fclose(first_file); // Certifique-se de fechar o primeiro arquivo antes de sair
        return EXIT_FAILURE;
    }
    if (output_file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo: %s\n", output_file_name);
        fclose(first_file); // Certifique-se de fechar os arquivos já abertos antes de sair
        fclose(second_file);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    // Copia o conteúdo do primeiro arquivo para o arquivo de saída
    while (fgets(buffer, BUFFER_SIZE, first_file) != NULL) {
        fputs(buffer, output_file);
        if (sscanf(buffer, "%d", &sequence_number) == 1) {
            // Atualiza o número da sequência após cada bloco de legenda
            sequence_number++;
        }
    }

    // Ajusta e copia as legendas do segundo arquivo
    copy_and_adjust(second_file, output_file, offset, &sequence_number);

    // Fecha todos os arquivos
    fclose(first_file);
    fclose(second_file);
    fclose(output_file);

    printf("A fusão dos arquivos de legendas foi concluída com sucesso!\n");

    return EXIT_SUCCESS;
}
