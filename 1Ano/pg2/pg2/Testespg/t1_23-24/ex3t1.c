#include <stdio.h>
#include <ctype.h>

//AC---BS..12
char *uniformize(char *str) {
    int index = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(isalnum(str[i])) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

int main() {
    char str[] = "AC-#$_-BS..12";
    uniformize(str);
    printf("%s\n", str);
    return 0;
}