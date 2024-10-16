#include <stdio.h>

int verifyWord(char *word, char *phrase) {
    for (int i = 0; phrase[i] != '\0'; i++) {
        if (word[0] == phrase[i]) {
            int j = 0;
            while (word[j] != '\0' && word[j] == phrase[i+j]) {
                j++;
            }
            if (word[j] == '\0') {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char word[] = "world";
    char phrase[] = "Hello, world!";
    printf("%d\n", verifyWord(word, phrase));
    return 0;
}