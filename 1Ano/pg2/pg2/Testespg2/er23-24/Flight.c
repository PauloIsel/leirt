#include "Flight.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *break_flight(char *text, int *code, char *start, char *end) {
    if (text == NULL) return NULL;
    char *replica = strdup(text);
    if (replica == NULL) return NULL;


    char *token = strtok(replica, "|");
    if (token == NULL) {
        free(replica);
        return NULL;
    }
    *code = atoi(token);


    token = strtok(NULL, "-");
    if (token == NULL) {
        free(replica);
        return NULL;
    }
    strcpy(start, token);


    token = strtok(NULL, "|");
    if (token == NULL) {
        free(replica);
        return NULL;
    }
    strcpy(end, token);


    token = strtok(NULL, "");
    if (token == NULL) {
        free(replica);
        return NULL;
    }
    char *desc = strdup(token);
    if (desc == NULL) return NULL;
    free(replica);


    return desc;
}

Flight *create_flight(char *text) {
    if(text == NULL) return NULL;

    Flight *flight = malloc(sizeof(Flight));
    if(flight == NULL) return NULL;

    flight->desc = break_flight(text, &flight->code, flight->start, flight->end);
    if(flight->desc == NULL) {
        free(flight);
        return NULL;
    }

    return flight;
}

void append_flight(Flight *flight, char *duration) {
    if(flight == NULL || duration == NULL) return;

    flight->desc = realloc(flight->desc, strlen(flight->desc) + strlen(duration) + 4);
    if(flight->desc == NULL) return;

    strcat(flight->desc, " [");
    strcat(flight->desc, duration);
    strcat(flight->desc, "]");
}



int main() {
    // Example strings to test
    char *flight1 = "12345|LIS-FNC|";
    char *flight2 = "23456|FNC-PDL|Origem: Funchal, Destino: Ponta Delgada";
    char *flight3 = "34567|JFK-LAX|New York -> Los Angeles";


    // Variables to store parsed information
    Flight *flight = create_flight(flight1);


    // Test flight 1
    printf("Testing flight 1:\n");
    if (flight->desc) {
        printf("Code: %d\nStart: %s\nEnd: %s\nDescription: %s\n", flight->code, flight->start, flight->end, flight->desc);
        free(flight->desc); 
    } else {
        printf("Failed to parse flight information.\n");
    }

//     printf("\n");

//     // flight = create_flight(flight2);
//     // //Test flight 2
//     // printf("Testing flight 2:\n");
//     // if (flight->desc) {
//     //     printf("Code: %d\nStart: %s\nEnd: %s\nDescription: %s\n", flight->code, flight->start, flight->end, flight->desc);
//     //     free(flight->desc); 
//     // } else {
//     //     printf("Failed to parse flight information.\n");
//     // }

//     // printf("\n");

//     // free(flight); 
//     // flight = create_flight(flight3);
//     // // Test flight 3
//     // printf("Testing flight 3:\n");
//     // if (flight->desc) {
//     //     printf("Code: %d\nStart: %s\nEnd: %s\nDescription: %s\n", flight->code, flight->start, flight->end, flight->desc);
//     //     free(flight->desc); 
//     // } else {
//     //     printf("Failed to parse flight information.\n");
//     // }

//     // free(flight); 

//     // flight = create_flight(flight1);
//     // printf("before append: %s\n", flight->desc);

//     // append_flight(flight, "2 horas e 10 min");
//     // printf("after append: %s\n", flight->desc);

//     // if(flight->desc) free(flight->desc); 
//     // free(flight); 

    return 0;
}

