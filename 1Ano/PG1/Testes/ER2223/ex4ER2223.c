#include <stdio.h>
#include <stdbool.h>

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

bool has_elements_consecutive (int v[], int dim, int value, int n_elements, int *first) {
    int element_count = 0;

    for (int i = 0; i < dim; i++) {
        if (v[i] == value) {
            element_count = count_consecutive(v, dim, i);
            if (element_count >= n_elements) {
                *first = i;
                return true;
            } else {
                return false;
            }
        }
    }
}

int main() {
    int a[12] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0};
    int dim = 12, value = 0, n_elems = 3, first = 0;

    bool b = has_elements_consecutive(a, dim, value, n_elems, &first);

    if (b) {
        printf("Subsequencia de %ds com início em %d e de dimensao %d\n", value, first, n_elems);
    } else {
        printf("Não foi encontrada uma subsequência de %d's com dimensão %d\n", value, n_elems);
    }

    return 0;
}