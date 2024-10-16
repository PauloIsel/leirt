


typedef struct waiter {
 struct waiter *next; // ligação em lista
 char *name; // nome do utente; alojar dinamicamente
} Waiter;
typedef struct {
    Waiter *first;
    Waiter *last;
    int size;
} Queue;

void qPut(Queue *q, char *s) {
    for( int i = 0; i < q->size; i++) {
        
    }
}