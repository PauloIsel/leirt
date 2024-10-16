#include <stdio.h>
#include <ctype.h>

void mnemonic (char *str) {
    int word = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i]) && word == 0) {
            str[j++] = str[i];
            if(isspace(str[i+1])) {
                str[j++] = ' ';
                word = 1;
            }
        }
        if(word) {
            if (isspace(str[i]) && isalpha(str[i+1])) {
                str[j++] = toupper(str[i+1]);
            }
        }
    }
    
    str[j] = '\0';
}

int main() {
    char str[] = "  RIta REIS dos SANtos";
    mnemonic(str);
    printf("%s\n", str);
    return 0;
}