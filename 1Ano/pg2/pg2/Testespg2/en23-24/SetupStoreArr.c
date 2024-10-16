#include "TagData.h"

void setupStoreArr(StoreArr *a, TagData *data, int nElem, int(*comp)(const void*, const void*) ) {
    a->data = data;
    a->space = nElem;
    a->count = 0;
    a->comp = comp;
}

void sortStoreArr(StoreArr *arr) {
    if(arr == NULL) return;
    qsort(arr->data, arr->count, sizeof(TagData), arr->comp);
}

int trackComp (const void *e1, const void *e2) {
    TagData *t1 = (TagData *) e1;
    TagData *t2 = (TagData *) e2;
    return t1->track - t2->track;
}

int insertOrd(StoreArr *arr, TagData *tag) {
    if (arr->count == arr->space) return 0;

    for (int i = 0; i < arr->count; i++) {
        if (arr->comp(tag, &arr->data[i]) < 0) {
            for (int j = arr->count; j > i; j--) {
                arr->data[j] = arr->data[j - 1];
            }
            arr->data[i] = *tag;
            arr->count++;
            return 1;
        }
    }
    arr->data[arr->count] = *tag;
    arr->count++;
    return 1;
}
