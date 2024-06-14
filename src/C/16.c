#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 350 // Maximum number of digits for 2^1000

void multiplyBy2(int *digits, int *size) {
    int carry = 0;
    for (int i = 0; i < *size; i++) {
        int temp = digits[i] * 2 + carry;
        digits[i] = temp % 10;
        carry = temp / 10;
    }
    if (carry > 0) {
        digits[*size] = carry;
        (*size)++;
    }
}

int main() {
    int digits[MAX_DIGITS];
    memset(digits, 0, sizeof(digits));
    digits[0] = 1;
    int size = 1;

    // Calculating 2^1000
    for (int i = 0; i < 1000; i++) {
        multiplyBy2(digits, &size);
    }

    // Calculating the sum of digits
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += digits[i];
    }

    printf("The sum of the digits of 2^1000 is: %d\n", sum);

    return 0;
}
