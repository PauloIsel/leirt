#ifndef __BST_H__
#define __BST_H__
#include "event.h"


typedef struct bstEvPtr{ 
  struct bstEvPtr *left, *right; 
  Event *ptr; 
} BstEvPtr;

#endif