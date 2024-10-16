#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{ 
  int number;        // Número de identificação 
  char *name;        // Nome (string alojada dinamicamente) 
  char *function;    // Cargo desempenhado (string alojada dinamicamente) 
} Member;

typedef struct listStaff{ 
  struct listStaff *next;  // ligação na lista 
  Member *ref;             // referência: ponteiro para o elemento de dados 
} ListStaff;

void listInvert(ListStaff **headAddr) {
    ListStaff *prev = NULL;
    ListStaff *current = *headAddr;
    ListStaff *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headAddr = prev;
}


int main() {
    ListStaff *head = NULL;
    ListStaff *node = malloc(sizeof(ListStaff));
    Member *member = malloc(sizeof(Member));
    member->number = 1;
    member->name = strdup("John");
    member->function = strdup("Manager");
    node->ref = member;
    node->next = head;
    head = node;

    node = malloc(sizeof(ListStaff));
    member = malloc(sizeof(Member));
    member->number = 2;
    member->name = strdup("Jane");
    member->function = strdup("Assistant");
    node->ref = member;
    node->next = head;
    head = node;

    node = malloc(sizeof(ListStaff));
    member = malloc(sizeof(Member));
    member->number = 3;
    member->name = strdup("Alice");
    member->function = strdup("Secretary");
    node->ref = member;
    node->next = head;
    head = node;

    // Print original list
    printf("Original List:\n");
    ListStaff *current = head;
    while (current != NULL) {
        printf("%d %s %s\n", current->ref->number, current->ref->name, current->ref->function);
        current = current->next;
    }

    // Invert the list
    listInvert(&head);

    // Print inverted list
    printf("\nInverted List:\n");
    current = head;
    while (current != NULL) {
        printf("%d %s %s\n", current->ref->number, current->ref->name, current->ref->function);
        current = current->next;
    }

    // Free memory
    current = head;
    while (current != NULL) {
        ListStaff *temp = current;
        current = current->next;
        free(temp->ref->name);
        free(temp->ref->function);
        free(temp->ref);
        free(temp);
    }

    return 0;
}