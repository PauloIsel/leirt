#include "bst.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int bstinsert(BstEvPtr **rootAddr, Event *event) {
//     if(rootAddr == NULL || event == NULL) {
//         return -1;
//     }

//     if(*rootAddr == NULL) {
//         BstEvPtr *newNode = malloc(sizeof(BstEvPtr));
//         if(newNode == NULL) {
//             return -1;
//         }
//         newNode->ptr = event;
//         newNode->left = newNode->right = NULL;
//         *rootAddr = newNode;
//         return 1;
//     }
    
//     int comparison = *rootAddr == NULL ? 1 : strcmp((*rootAddr)->ptr->desc, event->desc);
//     if(comparison == 0) {
//         return 0;
//     }
//     if(comparison < 0) {
//         return bstinsert(&(*rootAddr)->left, event);
//     } else {
//         return bstinsert(&(*rootAddr)->right, event);
//     }
// }

int bstinsert (BstEvPtr **rootAddr, Event *event){
    if (rootAddr == NULL){ //
        *rootAddr = malloc(sizeof(BstEvPtr));
        if(*rootAddr== NULL) return 0;
        (*rootAddr)->ptr = event;
        (*rootAddr)->left = (*rootAddr)->right = NULL; 
        return 1;
    }
    
    int cmp = strcmp(event->desc, (*rootAddr)->ptr->desc);
    if(cmp == 0) return 0; //Já existe
    if (cmp < 0) return bstinsert(&(*rootAddr)->left, event);
    if (cmp > 0) return bstinsert(&(*rootAddr)->right, event);
}


// int bstPrintEvent(BstEvPtr *root, char *desc) {
//     if(root == NULL) {
//         puts("Event not found");
//         return 0;
//     }
//     int comparison = strcmp(root->ptr->desc, desc);

//     BstEvPtr *current = root;

//     if(comparison == 0) {
//         printf("%s\n", current->ptr->desc);
//         return 1;
//     } else {
//         root = comparison < 0 ? current->left : current->right;
//         return bstPrintEvent(root, desc);
//     }
// }

int bstPrintEvent(BstEvPtr *root, char *desc){
    if (root == NULL) return 0;

    int cmp = strcmp(desc, root->ptr->desc);
    if (cmp == 0){
        Event *e = root->ptr;
        fprintf(stdout, "%d-%d-%d", e->year, e->month, e->day);
        return 1;
    }
    if (cmp < 0) return bstPrintEvent(root->left, desc);
    if (cmp > 0) return bstPrintEvent(root->right, desc);
}


int main() {
    BstEvPtr *root = NULL;

    // Create some events
    Event *event1 = eventCreate("Christmas: 2022/12-25");    
    Event *event2 = eventCreate("Thanksgiving : 2022//11 - 26");
    Event *event3 = eventCreate("New Year: 2023 01 - 01");

    // Insert events into the binary search tree
    int res1 = bstinsert(&root, event1);
    int res2 = bstinsert(&root, event2);
    int res3 = bstinsert(&root, event3);

    // Print the results
    printf("Insert event1: %d\n", res1); // Should print 1
    bstPrintEvent(root, "Thanksgiving");

    printf("Insert event2: %d\n", res2); // Should print 1
    printf("%d\n", bstPrintEvent(root, "New Year"));

    printf("Insert event3: %d\n", res3); // Should print 1
    printf("%d\n", bstPrintEvent(root, "Christmas")); // Should return 1

    // Try to insert an event with the same description
    Event *event4 = eventCreate("Christmas: 2022/12-25");
    int res4 = bstinsert(&root, event4);
    printf("Insert event4: %d\n", res4); // Should print 0


    return 0;
}