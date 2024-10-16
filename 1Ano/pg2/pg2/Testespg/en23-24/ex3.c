#include <stdio.h>
#include <ctype.h>

void mnemonic(char *str) {
    int dest = 0;
    int index;

    for (int k = 0; str[k] != '\0'; k++) {
        if(isalpha(str[k])) {
            str[dest++] = str[k];
            if(isspace(str[k+1])) {
                index = k;
                str[dest++] = ' ';
                break;

            }
        }
    }

    for (int i = index+1; str[i] != '\0'; i++) {
        if(isspace(str[i]) && isalpha(str[i+1])) {
            str[dest++] = toupper(str[++i]);
        }
    }

    str[dest] = '\0';
}

int main() {
    char str1[] = "     Luis         Vaz    de     Camoes    ";
    char str2[] = "    RIta REIS dos   SANtos   ";
    mnemonic(str1);
    printf("%s\n", str1);
    mnemonic(str2);
    printf("%s\n", str2);
    return 0;
}