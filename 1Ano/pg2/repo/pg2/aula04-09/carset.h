#ifndef __CARSET_H__
#define __CARSET_H__

#include "car.h"

#define MAX_CARS 5

typedef struct{
 int count; // número de elementos preenchidos no array cars
 Car cars[MAX_CARS];
} CarSet;

void carset_inic(CarSet *ptr);
int isCarsetEmpty(CarSet set);
int isCarsetFull(CarSet set);
void carset_print(CarSet set);

void carset_add(CarSet *ptr, Car car);
Car *carFindPlate( CarSet *set, char *plate );
int compare(const void *p1, const void *p2);
void carSort( CarSet *set );
#endif

