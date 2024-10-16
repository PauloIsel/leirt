#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ISBN 30

typedef struct { // Descritor dos dados de um livro
 char *title; // string alojada dinamicamente
 char isbn[MAX_ISBN]; // string com dimensão fixa
 char *authors; // string alojada dinamicamente
 char *publisher; // string alojada dinamicamente
} Book;

typedef struct{ // Descritor de um vetor
 Book **refs; // array alojado dinamicamente
 int size; // quantidade de elementos preenchidos
 int space; // quantidade de elementos alojados
} VecBookRef;

Book *find_isbn(VecBookRef *vec, char *isbn) {
    for (int i = 0; i < vec->size; i++) {
        if(strcmp(vec->refs[i]->isbn,isbn) == 0) {
            return vec->refs[i];
        }    
    }
    return NULL;
}
