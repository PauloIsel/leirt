#include "ListEvent.h"
#include "Event.h"
#include <stdio.h>
#include <stdlib.h>

int compareEventDate(Event *event1, Event *event2) {
    int year = event1->year - event2->year;
    if (year != 0) {
        return year;
    } else {
        int month = event1->month - event2->month;
        if (month != 0) {
            return month;
        } else {
            return event1->day - event2->day;
        }
    }
}

int listInsert(ListEvPtr **headAddr, char *text) {
    Event *newEvent = eventCreate(text);
    if (newEvent == NULL) {
        printf("Failed to create event.\n");
        return -1;
    }

    int comparison = *headAddr == NULL ? 1 : compareEventDate((*headAddr)->ptr, newEvent);
    if (comparison == 0) return 0;

    if (comparison > 0) {
        ListEvPtr *Auxnode = malloc(sizeof(ListEvPtr));
        if(Auxnode == NULL) {
            return -1;
        }
        Auxnode->ptr = newEvent;
        Auxnode->next = *headAddr;
        *headAddr = Auxnode;
        return 1;
    } else {
        return listInsert(&((*headAddr)->next), text);
    }
}

void listPrint(ListEvPtr *head) {
    if (head == NULL) return;

    ListEvPtr *current = head;
    head = current->next;

    printf("%d-%d-%d %s\n", current->ptr->year, current->ptr->month, current->ptr->day, current->ptr->desc);
    listPrint(head);
}

void ListDelete(ListEvPtr **headAddr, int deleteInfo) {
    if (*headAddr == NULL) return;

    ListEvPtr *current = *headAddr;
    *headAddr = current->next;

    if (deleteInfo) {
        free(current->ptr->desc);
        free(current->ptr);
    }

    free(current);
    ListDelete(headAddr, deleteInfo);
}

int main() {
    ListEvPtr *head = NULL;

    // Insert events
    if (listInsert(&head, " Christmas   : 2022/12/25") != 1) {
        printf("Failed to insert event.\n");
        return -1;
    }
    if (listInsert(&head, "Halloween  :  2022/10/31 ") != 1) {
        printf("Failed to insert event.\n");
        return -1;
    }
    if (listInsert(&head, " Independence Day  :2022/07/04") != 1) {
        printf("Failed to insert event.\n");
        return -1;
    }

    listPrint(head);

    ListDelete(&head, 1);

    return 0;
}