#include <stdio.h>

void number_to_string(int n, char str_number[]) {
    int i = 0;

    while (n > 0) {
        int curr_digit = n % 10;
        str_number[i] = curr_digit + '0';
        i++;
        n = n / 10;
    }
    str_number[i] = '\0';

    int start = 0;
    int end = i - 1;

    for (int start = 0; start < end; start++, end--) {
        char temp = str_number[start];
        str_number[start] = str_number[end];
        str_number[end] = temp;
    }

}

int main() {
    int n;
    scanf("%d", &n);
    char str_number[10];

    number_to_string(n, str_number);
    printf("str_number: \"%s\"\n", str_number);

    return 0;
}