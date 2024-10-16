#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

typedef struct{ 
  int number;        // Número de identificação 
  char *name;        // Nome (string alojada dinamicamente) 
  char *function;    // Cargo desempenhado (string alojada dinamicamente) 
} Member;

typedef struct{ 
  int count;      // Quantidade de ponteiros alojados e preenchidos no array 
  Member **array; // Array de ponteiros, alojado dinamicamente 
} Staff;

Member *memberCreate(char *text) {
    if(text == NULL) return NULL;

    int number;
    char name[100], job[100];
    int member = lineParse(text, &number, name, job);
    if (member) {
        Member *member = malloc(sizeof(Member));
        if (member == NULL) return NULL;

        member->number = number;
        member->name = strdup(name);
        if(member->name == NULL) {
            free(member);
            return NULL;
        }

        member->function = strdup(job);
        if(member->function == NULL) {
            free(member->name);
            free(member);
            return NULL;
        }
        
        return member;
    }
}

void *staffAdd(Staff *staff, Member *member) {
    if(staff == NULL || member == NULL) return NULL;

    staff->array = realloc(staff->array, (staff->count + 1) * sizeof(Member *));
    if(staff->array == NULL) return;

    staff->array[staff->count] = member;
    staff->count++;
}
