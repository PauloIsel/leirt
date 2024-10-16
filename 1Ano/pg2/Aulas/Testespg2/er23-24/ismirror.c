#include <stdio.h>
#include <limits.h>


// int ismirror(unsigned long value) {
//     int numBits = sizeof(value) * CHAR_BIT;

//     for (int i = 0; i < numBits / 2; ++i) {
//         printf("i: %d\n", i);
//         unsigned long rightBit = (value >> i) & 1;
//         printf("rightBit: %lu\n", rightBit);

//         unsigned long leftBit = (value >> (numBits - i)) & 1;
//         printf("leftBit: %lu\n", leftBit);

//         if (rightBit != leftBit) {
//             return 0;
//         }

//     }

//     return 1;
// }

int ismirror(unsigned long value) {
    int numBits = sizeof(unsigned long) * CHAR_BIT;

    // Encontre o bit mais significativo (MSB) que não é zero
    while (numBits > 0 && !(value & (1UL << (numBits - 1)))) {
        --numBits;
    }

    for (int i = 0; i < numBits / 2; i++) {

        int leftBit = (value >> (numBits - 1 - i)) & 1;
        int rightBit = (value >> i) & 1;

        printf("%d, %d\n", leftBit, rightBit);

        if (rightBit != leftBit) {
            return 0;
        }
    }
    return 1;
}


int main() {
    unsigned long value = 5; // 101
    printf("%d\n", ismirror(value));
    return 0;
}