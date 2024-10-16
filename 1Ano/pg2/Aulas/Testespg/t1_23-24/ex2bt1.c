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

int printRecentAlbum(TagData *tag, void *context) {
    int tagcount = 0;
    if(tag->year < 2002) {
        return 0;
    } else {
        printf("%s\n", tag->title);
        tagcount++;
    }
    return tagcount;
}


int main() {
    TagData tag;
    tag.year = 2000;
    printRecentAlbum(&tag, NULL);
    return 0;
}