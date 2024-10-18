#include <stdio.h>
#include <stdbool.h>

bool mirror_number(int n) {
      if (n < 0 || n > 9999) {
        return false;
    }

    int mirrored_number = 0;
    int input_number = n;

    while (n > 0) {
        int digit = n % 10;
        mirrored_number = mirrored_number * 10 + digit;
        n = n / 10;
    }

    if ((input_number / 100) == (mirrored_number / 100)) {
        return true;
    } else return false;

}

int count_mirror_numbers_in_interval(int start, int end) {
    if(start > end) {
        return 0;
    }

    int countnumber = start;
    int count = 0;

    do {
        if(mirror_number(countnumber)) {
            count++;
        }   
        countnumber++;
    } while (countnumber <= end);

    return count;
}

int main() {
    // Example of usage
    int result = count_mirror_numbers_in_interval(1000, 3000);
    printf("Count of mirror numbers in the interval: %d\n", result);

    return 0;
}