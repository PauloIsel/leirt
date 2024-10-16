#ifndef __CAR_H__
#define __CAR_H__

#define CAR_PLATE_SIZE 20

typedef struct{
 char plate[CAR_PLATE_SIZE]; // Matrícula da viatura
 short present; // 1 = está presente; 0 = está ausente
} Car; 

#endif
