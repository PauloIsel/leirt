#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{ 
  int number;        // Número de identificação 
  char *name;        // Nome (string alojada dinamicamente) 
  char *function;    // Cargo desempenhado (string alojada dinamicamente) 
} Member;

typedef struct bstStaff{ 
  struct bstStaff *left, *right; // ligações na árvore 
  Member *ref;             // referência: ponteiro para o elemento de dados 
} BstStaff;

int bstGetNumber(BstStaff *root, char *name) {
    if (root == NULL) return -1;
    int cmp = strcmp(name, root->ref->name);
    if (cmp == 0) return root->ref->number;
    if (cmp < 0) return bstGetNumber(root->left, name);
    return bstGetNumber(root->right, name);
}