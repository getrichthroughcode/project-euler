#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime (int n){
  double p = sqrt (n);
  for (int i = 2; i < p+1; i++){
    if (n%i==0){
      return 0;
    }
  }
  return 1;
}

int main (){
  long out = 5;
  for (int i = 5; i < 2000000; i+=2){
    if (is_prime(i)==1){
      out += i;
    }
   }
   printf("%ld", out);
 }
