#include <stdio.h>
#include <stdbool.h>

bool mirror_number(int n) {
      if (n < 0 || n > 9999) {
        return false;
    }

    int mirrored_number = 0;
    int input_number = n;
    printf("input: %d\n", input_number);

    while (n > 0) {
        int digit = n % 10;
        mirrored_number = mirrored_number * 10 + digit;
        n = n / 10;
    }
    printf("mirrored: %d\n", mirrored_number);

    if ((input_number / 100) == (mirrored_number / 100)) {
        return true;
    } else return false;

}

int main() {
    // Examples of usage
    printf("%d\n", mirror_number(1221)); // true
    printf("%d\n", mirror_number(3003)); // true
    printf("%d\n", mirror_number(0330)); // true
    printf("%d\n", mirror_number(2222)); // true

    // Examples that return false
    printf("%d\n", mirror_number(1234)); // false
    printf("%d\n", mirror_number(9876)); // false

    return 0;
}
/*
0330
330

330
33


*/