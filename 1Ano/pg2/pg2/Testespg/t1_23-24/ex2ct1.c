#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int compare(const void *p1, const void *p2) {
    TagData *ptr1 = (TagData*) p1;
    TagData *ptr2 = (TagData*) p2;
    return strcmp(ptr1->year, ptr2->year);
}

int yearExist (TagData *a, size_t nElem, short year) {
    for (int i = 0; &a[i] != '\0'; i++) {
        bsearch(&a[i], a, nElem, sizeof(a[0]), compare);
        if(a->year == year) {
            return 1;
        } else return 0;    
    }
}

int main() {
    TagData tag[] = {
        {"a", "a", "a", "a", 2000, "a", 'a', 'a'},
        {"b", "b", "b", "b", 2001, "b", 'b', 'b'},
        {"c", "c", "c", "c", 2002, "c", 'c', 'c'},
    };
    for (int i = 0; &tag[i] != '\0'; i++) {
        if(yearExist(tag, i, 2000)) {
            printf("%s\n", tag[i].title);
        }
    }
    return 0;
}