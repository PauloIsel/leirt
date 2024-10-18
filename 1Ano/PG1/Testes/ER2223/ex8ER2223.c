#include <stdio.h>

#define MAX 80
#define FREE 0
#define BUSY 1

typedef struct {
 int number; // nº do lugar
 int state; // FREE ou BUSY
} Place;

typedef struct {
 char name; // nome da fila
 Place places[MAX]; // Máximo de lugares por fila
 int n_places; // número lugares da fila
} Queue;

typedef struct {
 Queue queues[MAX]; // Máximo de filas
 int n_queues; // número de filas
} MovieTheater;

int queue_check_places (Queue *q, int state, int idx) {
    int count_consecutive = 0;

    for (int i = idx; i < q->n_places; i++) {
        if (q->places[i].state == state) {
            count_consecutive++;
        }
    }
    return count_consecutive;
}

int main() {
    // Exemplo de uso
    MovieTheater theater;

    // Inicializar algumas filas com lugares para teste
    theater.n_queues = 2;

    // Fila 1
    theater.queues[0].name = 'A';
    theater.queues[0].n_places = 5;
    for (int i = 0; i < 5; i++) {
        theater.queues[0].places[i].number = i + 1;
        theater.queues[0].places[i].state = BUSY;
    }

    // Fila 2
    theater.queues[1].name = 'B';
    theater.queues[1].n_places = 8;
    for (int i = 0; i < 8; i++) {
        theater.queues[1].places[i].number = i + 1;
        theater.queues[1].places[i].state = (i % 2 == 0) ? BUSY : FREE;
    }

    // Verificar lugares consecutivos ocupados na Fila 1 a partir da posição 2
    int result = queue_check_places(&theater.queues[0], BUSY, 2);

    printf("Número de lugares consecutivos ocupados: %d\n", result);

    return 0;
}