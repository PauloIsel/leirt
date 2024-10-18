#include <stdio.h>
#include <string.h>
#include <ctype.h>

void snakeToCamel(char *str) {
    int length = strlen(str);
    int i, j = 0;
    int capitalizeNext = 1;

    for (i = 0; i < length; i++) {
        if (str[i] == '_') {
            capitalizeNext = 1;
        } else {
            if (j == 0 || j == length - 1 || capitalizeNext) {
                str[j++] = toupper(str[i]);
                capitalizeNext = 0;
            } else {
                str[j++] = str[i];
            }
        }
    }

    str[j] = '\0';
}

int main() {
    char snakeCase[] = "__var_start_end__with_underscores__";
    snakeToCamel(snakeCase);
    printf("Camel Case: %s\n", snakeCase);
    return 0;
}
