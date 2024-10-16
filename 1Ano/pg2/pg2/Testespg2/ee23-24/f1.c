#include <stdio.h>
#include <stdlib.h>


//-4 3 -1 -3 0 4 -7 -8 -6 5 -9 7 -5 8 0 6 2 1 9 -2

int *a, option=2, r; 
(...)  // Preenchimento do array dinâmico a. 
size_t size=20; 
r = f1(a, size, f2, chg, &option);


int f1(int a[], size_t size, int (*cond)(const int * e), int (*act)(int *data, void *context), void * context) { 
  size_t i, s=0; 
  for(i = 0; i < size; i++) 
    if(cond == NULL || cond(a+i))   
      s += act(a+i, context); 
  return s; 
}

int f2(const int * e) { 
  return (*e == 2); 
} 

int chg(int * n, int * lim) {
  int r = (*lim > 4);
  *n = r ? *n * *n : -*n;
  return r;
}


int f3 (const int * e) {
  return ((*e % 2) == 0);
}

int f4 (int *n, int *lim) {
    *n = lim;
    return 1;
}