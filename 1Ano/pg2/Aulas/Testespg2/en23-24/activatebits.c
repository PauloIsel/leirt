#include <stdio.h>
#include <limits.h>

void activateBits (long long *value, int step) {
    for (int i = 0; i < sizeof(*value) * CHAR_BIT; i += step) {
        *value |= 1LL << i;
    }
}


int main() {
    long long value = 0;
    activateBits(&value, 1);
    printf("%lld\n", value);
    return 0;
}


// void activateBits(long long *value, int step) {
//     for (int i = 0; i < sizeof(*value) * 8; i += step) {
//         *value |= (1LL << i);
//     }
// }

// int main() {

//     long long value = 0x123456789ABCDEF0;
//     activateBits(&value, 3);
//     printf("%llx\n", value);
//     return 0;

// }