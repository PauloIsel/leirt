#ifndef __LISTEVENT_H__
#define __LISTEVENT_H__
#include "Event.h"


typedef struct listEvPtr{ 
  struct listEvPtr *next; 
  Event *ptr;    
} ListEvPtr;


#endif
