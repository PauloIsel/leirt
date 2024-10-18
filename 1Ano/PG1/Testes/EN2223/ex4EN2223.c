#include <stdio.h>

void encode (char dest[], const char src[]) {
    int count = 1;
    int j = 0;

    for (int i = 0; src[i]!= '\0'; i++) {
        if (src[i] >= 'a' && src[i] <= 'z') {
            if (src[i] == src[i+1]) {
                count++;
            }
            if (src[i] != src[i+1]) {
                dest[j] = src[i];
                dest[j+1] = count + '0';
                j+= 2;
                count = 1;
            }
        }
    }
    dest[j] = '\0';
}

int main() {
    // Exemplo de uso
    char src[] = "maaaaaaaaqeeemmmmmm";
    char dest[100];

    encode(dest, src);

    printf("a string dest fica igual a \"%s\"\n", dest);

    return 0;
}