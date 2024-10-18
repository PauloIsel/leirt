#include <stdio.h>

int count_consecutive (int vals[], int dim, int idx) {
    int result = 0;
    int count = 1;

    for (int i = idx; i < dim; i++) {
        if (vals[i] == vals[i+1]) {
            count++;
        }
        if (vals[i] != vals[i+1]) {
            if (count > result) {
                result = count;
            }
            count = 0;
        }
    }
    return result;
}


int main() {
    int vals[12] = {1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    int idx = 8;
    int dim = 12;

    int count = count_consecutive(vals, dim, idx);

    printf("Subsequencia de %d com início em %d e de dimensão %d\n", vals[idx], idx, count);

    return 0;
}