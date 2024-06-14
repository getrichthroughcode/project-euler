#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 500 

int* IntegerToArray(int a){
    int* out = (int*) calloc(MAX_DIGITS, sizeof(int));
    if (out == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int idx = 0;
    while (a > 0) {
        out[idx++] = a % 10;
        a /= 10;
    }
    return out;
}

int* Multiply(int* a, int* b, int len1, int len2){
    int* result = (int*)calloc(len1 + len2, sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = a[i] * b[j];
            int sum = mul + result[i + j + 1]; 
            result[i + j] += sum / 10; 
            result[i + j + 1] = sum % 10; 
        }
    }
    return result;
}

int main(){
    int *out = IntegerToArray(1); // Initialize out with 1
    if (out == NULL) {
        return 1; // Exit if memory allocation fails
    }

    for (int i = 2; i <= 100; i++){
        int *temp = IntegerToArray(i);
        if (temp == NULL) {
            free(out);
            return 1; // Exit if memory allocation fails
        }
        int len1 = MAX_DIGITS;
        int len2 = MAX_DIGITS;
        while (temp[len1 - 1] == 0 && len1 > 1) len1--; // Get the actual length of temp
        while (out[len2 - 1] == 0 && len2 > 1) len2--; // Get the actual length of out
        int *mul_result = Multiply(out, temp, len2, len1);
        free(out); // Free the memory allocated for the previous 'out'
        out = mul_result;
        free(temp); // Free the memory allocated for 'temp'
    }

    int sum = 0;
    int len = MAX_DIGITS;
    while (out[len - 1] == 0 && len > 1) len--; // Get the actual length of out
    for (int i = 0; i < len; i++) {
        sum += out[i];
    }

    printf("Sum of the digits in 100! = %d\n", sum);

    free(out); // Free the memory allocated for 'out'

    return 0;
}
