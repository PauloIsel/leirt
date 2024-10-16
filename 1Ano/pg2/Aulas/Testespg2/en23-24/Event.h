#ifndef __EVENT_H__
#define __EVENT_H__
#define Delim  "/-,.: " 

typedef struct{ 
    char *desc;   // descrição - string alojada dinamicamente 
    int  year;    // ano 
    short month; // mês 
    short day;   // dia 
}Event;

char *eventSplit(char *text, int *yPtr, int *mPtr, int *dPtr);

void eventDescAppend(Event *event, char *str);

Event *eventCreate(char *text);

#endif