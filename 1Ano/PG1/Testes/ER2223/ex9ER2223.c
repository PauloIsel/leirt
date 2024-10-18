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

int queue_reserve_places (Queue *q, int n_places) {
    for (int i = 0; i <= q->n_places; i++) {
        if (queue_check_places (q, FREE, i) == n_places) {


        }

    }


    return -1;
}