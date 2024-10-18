#include <stdio.h>

int greatest_dig_seq(char data[]) {
    int result = 0;
    int current_seq = 0;

    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            current_seq++;
            printf("counting: %d\n", current_seq);
        }
        if (data[i] < '0' || data[i] > '9' || data[i+1] == '\0') {
            printf("c1:%d", current_seq);
            printf(" r1:%d\n", result);
            if (current_seq > result) {
                result = current_seq;
                printf("c2:%d", current_seq);
                printf(" r2:%d\n", result);
            }
            current_seq = 0;
            printf("seq_after_loop: %d\n", current_seq);
        }
    }
    return result;
}

int main() {
    char data[] = "2974porf5728oef230959dwdokv5946756856";

    printf("%d\n", greatest_dig_seq(data));

    return 0;
}