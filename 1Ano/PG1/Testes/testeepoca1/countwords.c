#include <stdio.h>

int countwords (const char str[]) {
    int count = 0;

    for(int k = 0; str[k] != '\0'; k++) {
        if(str[k] != ' ' && (str[k+1] == ' ' || str[k+1] == '\0')) {
            count++;
            
        }
    }

    return count;
}

int main() {

    char src[] = "Hello world";
    printf("%d\n", countwords(src));

    return 0;
}