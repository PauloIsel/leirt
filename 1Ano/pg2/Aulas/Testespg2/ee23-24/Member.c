#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char text[] = "23;Joao;Engenheiro";
    Member *member = memberCreate(text);
    printf("Number: %d\nName: %s\nFunction: %s\n", member->number, member->name, member->function);
    return 0;
}