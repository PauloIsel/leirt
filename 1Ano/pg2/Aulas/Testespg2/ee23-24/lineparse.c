#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100

int lineParse(char *text, int *number, char *name, char *job){
    char *delim = ";";
    char *copia = strdup(text);
    if(copia == NULL) return 0;

    char *aux = strtok(copia, delim);
    if(aux == NULL){
        free(copia);
        return 0;
    }
    *number=atoi(aux);

    aux = strtok(NULL, delim);
    if(aux == NULL){
        free(copia);
        return 0;
    }
    strcpy(name, aux);

    aux = strtok(NULL, delim);
    if(aux == NULL){
        free(copia);
        return 0;
    }
    strcpy(job, aux);

    return 1;
}