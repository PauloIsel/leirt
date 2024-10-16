#ifndef __SCALE_H__
#define __SCALE_H__
#include "rectangle.h"

void scale(Rectangle *rp, double factor);

#endif
//scale.h deve ser incluido no ficheiro aplic.c

//a assinatura da função multiply não é colocada por ser uma função exclusivamente utilizada
//no ficheiro scale.c (multiply é uma função "privada" do ficheiro scale.c) 