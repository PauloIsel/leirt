#include "Event.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *eventSplit(char *text, int *yPtr, int *mPtr, int *dPtr) {
    if (text == NULL) return NULL;

    char *replica = strdup(text);
    if (replica == NULL) return NULL;

    char *token = strtok(replica, ":");
    if (token == NULL) {
        free(replica);
        return NULL;
    }

    token = strtok(NULL, Delim);
    if (token == NULL) {
        free(replica);
        return NULL;
    }
    *yPtr = atoi(token);

    token = strtok(NULL, Delim);
    if (token == NULL) {
        free(replica);
        return NULL;
    }
    *mPtr = atoi(token);

    token = strtok(NULL, Delim);
    if (token == NULL) {
        free(replica);
        return NULL;
    }
    *dPtr = atoi(token);
    
    return replica;
}

Event *eventCreate(char *text) {
    if (text == NULL) return NULL;

    int y, m, d;
    char *replica = eventSplit(text, &y, &m, &d);
    if (replica == NULL) return NULL;

    Event *event = malloc(sizeof(Event));
    if (event == NULL) {
        free(replica);
        return NULL;
    }

    event->year = y;
    event->month = m;
    event->day = d;
    event->desc = replica;

    return event;
}

void eventDescAppend(Event *event, char *str) {
    if (str == NULL) return;

    event->desc = realloc(event->desc, strlen(event->desc) + strlen(str) + 1);
    if (event->desc == NULL) return;

    strcat(event->desc, str);
}


void EventDelete (Event *event, int condition) {
    if (event == NULL) return;
    if(condition) free(event->desc);
    free(event);
}

// int main() {
//     int y, m, d;
//     char *replica = eventSplit("Pg2 - 1.º teste parcial:    2023-11-10", &y, &m, &d);
//     if(replica) printf("Year: %d\nMonth: %d\nDay: %d\n", y, m, d);
//     free(replica);
//     replica = eventSplit("ISEL, Fim das aulas: 2023/12.20", &y, &m, &d);
//     if(replica) printf("Year: %d\nMonth: %d\nDay: %d\n", y, m, d);
//     free(replica);
//     replica = eventSplit("Pg2 - Exame de epoca normal: 2024     01--08", &y, &m, &d);
//     if(replica) printf("Year: %d\nMonth: %d\nDay: %d\n", y, m, d);
//     free(replica);
//     replica = eventSplit("", &y, &m, &d);
//     if(replica) printf("Year: %d\nMonth: %d\nDay: %d\n", y, m, d);
//     free(replica);
    

// //     return 0;
// // }

// int main() {
//     Event *event = eventCreate("Pg2 - 1.º teste parcial:    2023-11-10");
//     if(event) printf("Year: %d\nMonth: %d\nDay: %d\n", event->year, event->month, event->day);
//     EventDelete(event, 1);

//     event = eventCreate("ISEL, Fim das aulas: 2023/12.20");
//     if(event) printf("Year: %d\nMonth: %d\nDay: %d\n", event->year, event->month, event->day);
//     EventDelete(event, 1);

//     event = eventCreate("Pg2 - Exame de epoca normal: 2024     01--08");
//     if(event) printf("Year: %d\nMonth: %d\nDay: %d\n", event->year, event->month, event->day);
//     EventDelete(event, 1);

//     event = eventCreate("Pg2 - Exame de epoca normal: 2024");
//     // Append a description
//     char *desc = "This is a test description.";
//     eventDescAppend(event, desc);

//     // Check if the description was correctly appended
//     printf("Description: %s\n", event->desc);

//     // Clean up
//     EventDelete(event, 1);

//     return 0;
// }