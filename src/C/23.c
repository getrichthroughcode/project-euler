#include <stdlib.h>
#include <stdio.h>


int SumOfProperDivisors(int n){
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n%i == 0){
            sum = sum + i;
        }
    }
    return sum;
}



int IsAbundantNumber(int n){
   if (SumOfProperDivisors(n) > n){
        return 1;
   }
    return 0;
}


int IsSumOf2AbundantNumber(int n){
    for (int i = 1; i < n; i++){
        if (IsAbundantNumber(i) == 1 && IsAbundantNumber(n-i)){
            return 1;
        }
    }
    return 0;
}


int main(){
    int limit = 25183;
    int sum = 0;
    for (int k = 1; k < limit; k++){
        printf("%d\n",k);
        if (IsSumOf2AbundantNumber(k) == 0){
            sum = sum + k;
        }
    }
    printf("%d\n",sum);
    return 1;
}