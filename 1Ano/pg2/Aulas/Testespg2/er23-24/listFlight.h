#ifndef __LISTFLIGHT_H__
#define __LISTFLIGHT_H__
#include "flight.h"

typedef struct listFlight{ 
  Flight *flight; 
  struct listFlight *next; 
} ListFlight;

#endif