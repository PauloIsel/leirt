#include <stdio.h>
#define MAX_FILENAME 30
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

size_t tagScan( TagData a[], size_t nElem, int (*action)(TagData *data, void *context ), void * context ) {
    int count = 0;
    for (int i = 0; i < nElem; i++) {
        count += action(&a[i], context);
    }
    return count;
}
