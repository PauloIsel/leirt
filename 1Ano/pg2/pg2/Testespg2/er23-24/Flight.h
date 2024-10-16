#ifndef __EVENT_H__
#define __EVENT_H__
#define Delim  "|-" 

typedef struct{ 
  int code;          // Código de reserva 
  char start[3+1];   // Aeroporto de partida 
  char end[3+1];     // Aeroporto de chegada 
  char *desc;        // Descrição do voo (string alojada dinamicamente) 
} Flight;

char *break_flight(char *text, int *code, char *start, char *end);

Flight *create_flight(char *text);

void append_flight(Flight *flight, char *duration);

#endif