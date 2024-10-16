#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "car.h"
#include "carset.h"

Car mycars[] = {
  {"00- C -  34 DD",1},
       {"02 - 45EE",1},
        {"04  12BB",1},
      {"06NU   68 ",0},
       {"eE - 56fF",0}
               };

char* plateNormalize( char *plate )
{
  int dest=0;
  for (int i=0; plate[i]!='\0'; i++)
    if (isalnum(plate[i]))
      plate[dest++] = toupper(plate[i]);
  plate[dest]='\0';
  return plate;
}



int main()
{
  CarSet carset;
  carset_inic(&carset);
  carset_print(carset);

  for (int i=0; i<sizeof(mycars)/sizeof(mycars[0]); i++)
  {
    plateNormalize(mycars[i].plate);
    carset_add(&carset, mycars[i]);
  }
  puts("Antes de ordenar");
  carset_print(carset);
  
  carSort(&carset);

  puts("Depois de ordenar");
  carset_print(carset);

  char matricula[20]="AA  12     BB ";

  if (carFindPlate(&carset, matricula))
   puts("ENCONTREI");
  else
    puts("NAO ENCONTREI"); 

  strcpy(matricula, "   06 nU 68   ");
  if (carFindPlate(&carset, matricula))
   puts("ENCONTREI");
  else
    puts("NAO ENCONTREI");

  strcpy(matricula, "   06 nU 68   ");
  if (carFindPlate(&carset, matricula))
    puts("ENCONTREI");
  else
    puts("NAO ENCONTREI");

  carset_print(carset);
  return 0;
}
