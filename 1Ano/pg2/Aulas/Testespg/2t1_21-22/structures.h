#include <stdio.h>
#include <math.h>
#define N_PLACES 10

typedef struct { 
  double lat; // Latitude 
  double lng; // Longitude 
  double distance; // Distância a (0,0) 
} Coord;

typedef struct { 
  int count;          // N.º de elementos efetivamente na lista 
  Coord arr[N_PLACES];// Array com N_PLACES elementos criados estaticamente 
} Table; 
