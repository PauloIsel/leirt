#include <stdio.h>


void activateBits(long long *value, int step) {
    for (int i = 0; i < sizeof(*value) * 8; i += step) {
        *value |= (1LL << i);
    }
}

int main() {

    long long value = 0x123456789ABCDEF0;
    activateBits(&value, 3);
    printf("%llx\n", value);
    return 0;

}