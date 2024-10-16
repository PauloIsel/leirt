#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listFlight.h"

Flight *listRemove(ListFlight **headAddr, int code) {
    if (*headAddr == NULL) {
        return NULL;
    }

    if ((*headAddr)->flight->code == code) {
        ListFlight *aux = *headAddr;
        *headAddr = aux->next;
        Flight *flight = aux->flight;
        free(aux);
        return flight;
    } else {
        return listRemove(&((*headAddr)->next), code);
    } 
}

int main() {
    ListFlight *head = NULL;
    Flight *flight = create_flight("12345|LIS-FNC|Lisboa -> Funchal");
    ListFlight *node = malloc(sizeof(ListFlight));
    node->flight = flight;
    node->next = NULL;
    head = node;

    Flight *flight2 = create_flight("23456|FNC-PDL|Origem: Funchal, Destino: Ponta Delgada");
    ListFlight *node2 = malloc(sizeof(ListFlight));
    node2->flight = flight2;
    node2->next = NULL;
    head->next = node2;

    Flight *flight3 = create_flight("34567|PDL-LIS|Ponta Delgada -> Lisboa");
    ListFlight *node3 = malloc(sizeof(ListFlight));
    node3->flight = flight3;
    node3->next = NULL;
    head->next->next = node3;

    Flight *flight4 = create_flight("45678|LIS-JFK|Lisboa -> New York");
    ListFlight *node4 = malloc(sizeof(ListFlight));
    node4->flight = flight4;
    node4->next = NULL;
    head->next->next->next = node4;

    printf("%p\n", &head->flight->code);
    printf("%p\n", listRemove(&head, 12345));
}