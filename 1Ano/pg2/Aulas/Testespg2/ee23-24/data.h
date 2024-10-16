#ifndef __DATA_H__
#define __DATA_H__

#include "types.h"

Data* dCreate();

void dAdd(Data* d, const char* name, int num);

void dSort(Data* d);

void dPrint(Data* d);

void dDelete(Data* d);

#endif