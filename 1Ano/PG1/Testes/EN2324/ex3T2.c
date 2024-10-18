#include <stdio.h>
#include <stdbool.h>

typedef struct set {
int elems[MAX_SET];
int size; // dimensão do set
} set_t;

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool random_subset(set_t *src_set, set_t *dst_set, int dst_size) {
    if (src_set->size < dst_size) {
        return false;
    }

    dst_set->size = 0;

    while (dst_set->size < dst_size) {
        int random_element = src_set->elems[rand_range(0, src_set->size -1)];

        bool found = false;
        for (int i = 0; i < dst_set->size; i++) {
            if (dst_set->elems[i] == random_element) {
                found = true;
                break;
            }
        }
        if (!found) {
            dst_set->elems[dst_set->size] = random_element;
            dst_set->size++;
        }
    }
    return true;
}