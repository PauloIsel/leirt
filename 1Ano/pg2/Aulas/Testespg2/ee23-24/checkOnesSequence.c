#include <limits.h>
#include <stdio.h>

int checkOnesSequence(unsigned long data, int minSize) {
    int currentSequenceLength = 0;

    while (data > 0) {
        if (data & 1) {
            currentSequenceLength++; 
            if (currentSequenceLength >= minSize) {
                return 1; 
            }
        } else {
            currentSequenceLength = 0; 
        }
        data >>= 1;
    
        return 0;
    }
}

int main() {
    unsigned long data1 = 15;   //1111
    unsigned long data2 = 0;    //0000
    unsigned long data3 = 10;   //1010
    unsigned long data4 = 7;    //0111
    int minSize = 3;

    printf("Testando data1 (0x%lX): %d\n", data1, checkOnesSequence(data1, minSize));
    printf("Testando data2 (0x%lX): %d\n", data2, checkOnesSequence(data2, minSize));
    printf("Testando data3 (0x%lX): %d\n", data3, checkOnesSequence(data3, minSize));
    printf("Testando data4 (0x%lX): %d\n", data4, checkOnesSequence(data4, minSize));

    return 0;
}