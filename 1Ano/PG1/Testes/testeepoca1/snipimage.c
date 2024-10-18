#include <stdio.h>

#define MAXL 100
#define MAXC 100

typedef struct {
 int pixels[MAXL][MAXC]; // Conjunto de pixeis
 int lines; // Número de linhas usadas (0 a lines-1)
 int cols; // Número de colunas usadas (0 a cols -1)
} Image;

void snipImage(Image *photo, int sl, int sc, int ln, int cn, Image *res) {
    if(sl < 0 || sl + ln > photo->lines || sc < 0 || sc + cn > photo->cols) {   
        res->lines = 0;
        res->cols = 0;
        return;
    }

    res->lines = ln;
    res->cols = cn;

    int i, j;

    for(i = 0; i < ln; i++) {
        for(j = 0; j < cn; j++) {
            res->pixels[i][j] = photo->pixels[sl + i][sc + j];
        }
    }
}