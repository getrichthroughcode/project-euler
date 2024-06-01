#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



int SumOfProperDivisor(int n){
    double sum = 0;
    for (int k = 1; k <= n; k++){
        for (int j= 1; j <= k; j++){

            sum = sum + cos(2*M_PI*j*n/k);

        }
    }

    return (int) sum - n + 1;
    
}


int SumOfProperDivisors(int n){
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n%i == 0){
            sum = sum + i;
        }
    }
    return sum;
}


int main(){
    int sum = 0;
    int *HashTable = (int *)calloc(10000, sizeof(int));
    for (int a = 1; a <= 10000; a++){
        printf("%d\n",a);
        if (HashTable[a] == 0){
            int b = SumOfProperDivisors(a);
            int c = SumOfProperDivisors(b);
            if (b != a && c == a){
                sum = sum + b + a;
                HashTable[b] = 1;
                HashTable[a] = 1;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}