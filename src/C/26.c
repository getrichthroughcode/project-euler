#include <stdlib.h>
#include <stdio.h>

int LengthOfRecurringFactor(int n) {
    if (n <= 1) {
        // Return 0 for invalid input
        return 0;
    }

    int* marker = (int*) calloc(n, sizeof(int));
    if (!marker) {
        // If memory allocation fails, return 0
        perror("Failed to allocate memory");
        return 0;
    }

    int out = 0;
    int Dividend = 1;
    int Remainder = 1;

    while (marker[Dividend % n] == 0) {
        printf("point: %d\n",Dividend%n);
        out++;
        Remainder = Dividend % n;
        Dividend = 10 * Remainder;
        //printf("%d\n", Dividend / n);
        marker[Remainder] = 1;
    }

    free(marker);
    return out;
}

int main() {
    int n = 1000; 
    int max = 0;
    int result = 0;

    for (int k = 2; k < n; k++) {
        printf("Trying %d\n", k);
        int length = LengthOfRecurringFactor(k);
        if (max < length) {
            max = length;
            result = k;
        }
        
    }

    printf("Longest recurring cycle is obtained for : %d\n", result);

    return 0;
}
