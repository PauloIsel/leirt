#include <stdio.h>

int count_consecutive (int vals[], int idx, int dim) {
    int k = 0;
    int count = 1;

    if (idx < 0 || idx >= dim) {
        return 0;
    }

    for(k = idx + 1; k < dim; k++) {
        if (vals[k] == vals[idx]) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    
    int vals[11]={1,1,1,0,0,0,1,1,0,0,0}, idx=8, dim=11;
int count = count_consecutive(vals, idx, dim);
printf("Subsequência de %ds com início em %d e de dimensão %d\n",vals[idx],idx, count);

    return 0;
}