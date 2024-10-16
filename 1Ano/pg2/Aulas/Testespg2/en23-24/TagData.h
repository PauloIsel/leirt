#ifndef __TAGDATA_H__
#define __TAGDATA_H__
#include <stdlib.h>


#define MAX_FILENAME 100
#define MAX_TITLE 30
#define MAX_ARTIST 30
#define MAX_ALBUM 30 
#define MAX_COMMENT 30

typedef struct{
 char filename[MAX_FILENAME + 1];
 char title[MAX_TITLE + 1];
 char artist[MAX_ARTIST + 1];
 char album[MAX_ALBUM + 1];
 short year;
 char comment[MAX_COMMENT + 1];
 char track;
 char genre;
} TagData; 

// typedef struct{
//  TagData *data; // aponta para array de tags (o array tem alojamento estático)
//  int space; // capacidade do array; quantidade de elementos
//  int count; // quantidade de elementos preenchidos
//  int (*comp)(const void *, const void *); // Função de comparação para
//  // ordenar o array data.
// } StoreArr; 

#endif