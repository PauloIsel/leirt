#include <string.h>
#include <ctype.h>
#include <stdio.h>

char *firstUpper(char *str) {
    int Upper = 1;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            str[j++] = str[i];
            if(isalpha(str[i+1])) Upper = 1;
        } else {
            if (Upper) {
                str[j++] = toupper(str[i]);
                Upper = 0;
            } else {
                str[j++] = tolower(str[i]);
            }
        }
    }

    str[j] = '\0';

    return str;
}


int main() {
    char str[] = "  RIta    REIS dos SANtos";
    printf("%p\n", str);
    firstUpper(str);
    printf("%s\n", str);
    printf("%p\n", str);
    return 0;
}