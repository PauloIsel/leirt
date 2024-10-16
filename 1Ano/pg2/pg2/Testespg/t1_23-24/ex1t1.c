#include <stdio.h>
#include <limits.h>

int countTrailingZeros(unsigned long long data) {
    int count = 0;
    int word_size = sizeof(data) * CHAR_BIT;

    for (int i = 0; i < word_size; ++i) {
        if ((data & 1) == 0) {
            count++; 
        } else {
            break; 
        }
        data >>= 1;
    }
    
    return count;
}

int main() {
    printf("%d\n", countTrailingZeros(124));
    printf("%d\n", countTrailingZeros(120));
    printf("%d\n", countTrailingZeros(156));
    return 0;
}