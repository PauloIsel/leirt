#ifndef __BSTFLIGHT_H__
#define __BSTFLIGHT_H__
#include "Flight.h"
#include "listFlight.h"

typedef struct bstFlight{ 
  char end[3+1]; 
  ListFlight *subset; 
  struct bstFlight *left, *right; 
} BstFlight;


#endif
