#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carset.h"

Car *carFindPlate( CarSet *set, char *plate )
{
  plateNormalize(plate);
  Car car;
  strcpy(car.plate, plate);
  return bsearch(&car, set->cars, set->count, sizeof(set->cars[0]), compare);
}

int compare(const void *p1, const void *p2)
{
  Car *ptr1 = (Car*) p1;
  Car *ptr2 = (Car*) p2;
  return strcmp(ptr1->plate, ptr2->plate);
}

void carSort( CarSet *set )
{
  qsort(set->cars, set->count, sizeof(set->cars[0]), compare);
}

void carset_inic(CarSet *ptr)
{
  ptr->count = 0;
}

int isCarsetEmpty(CarSet set)
{
  return (set.count==0);
}

int isCarsetFull(CarSet set)
{
   return (set.count>=MAX_CARS);
}

void carset_add(CarSet *ptr, Car car)
{
  if (isCarsetFull(*ptr))
  {
    fprintf(stderr, "CarSet is full!!!\n");
    return; 
  }
  // Ainda há espaço no carset

  ptr->cars[ptr->count] = car;
  ptr->count++;
}

void carset_print(CarSet set)
{
  puts("---------------------------------------------");
  printf("Status: isEmpty: %s isFull: %s Count: %d\n",
         isCarsetEmpty(set) ? "Sim" : "Não",
         isCarsetFull(set) ? "Sim" : "Não",
         set.count);
  puts("---------------------------------------------");

  puts("---------INICIO--------------");
  for (int i=0; i<set.count; i++)
    printf("Plate [%s] isPresent: %s\n", 
           set.cars[i].plate,
           set.cars[i].present ? "Sim" : "Não");
  puts("-----------FIM--------------");
}
