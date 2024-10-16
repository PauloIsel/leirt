#include "TagData.h"
#include <stdio.h>

int showalltitles(TagData *data, void *context) {
    printf("Title: %s\n", data->title);
    return 1;
}

int showHighTracks(TagData *data, void *context) {
    int highTrack = *(char *)context;
    if (data->track > highTrack) {
        printf("%s\n", data->album);
        return 1;
    }
    return 0; 
}

//size_t f1 (TagData *a, nelems, showalltitles, Hightracks);

size_t f1(void *a[], size_t nElem, int (*action)(TagData *data, void *context), void * context ){ 
    size_t s = 0; 

    while(nElem--) 
        s += (*action)(a++, context); 
    return s; 
}