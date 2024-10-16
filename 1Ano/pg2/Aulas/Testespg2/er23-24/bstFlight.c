#include "bstFlight.h"
#include <stdlib.h>

void bstInsert(BstFlight **rootAddr, Flight *flight) {
    if (*rootAddr == NULL) {

        BstFlight *new_node = (BstFlight *)malloc(sizeof(BstFlight));

        if (new_node == NULL) return;

        strcpy(new_node->end, flight->end);
        new_node->subset = NULL;
        new_node->left = NULL;
        new_node->right = NULL;

        listInsert(&(new_node->subset), flight);

        *rootAddr = new_node;
    } else {

        int cmp = strcmp(flight->end, (*rootAddr)->end);
        if (cmp < 0) {
            bstInsert(&((*rootAddr)->left), flight);
        } else if (cmp > 0) {
            bstInsert(&((*rootAddr)->right), flight);
        } else {
            listInsert(&((*rootAddr)->subset), flight);
        }
    }
}