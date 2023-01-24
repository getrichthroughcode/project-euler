#include <stdio.h>
#include <stdlib.h>

int fibonacci (int n){
  if (n == 0){
    return 1;
  }
  if (n == 1){
    return 1;
  }
  else
    return (fibonacci(n-1)+fibonacci(n-2));
}

int main (){
  int n  = 0;
  int out= 0;
  while (fibonacci(n) <= 4000000){
    if (fibonacci(n)%2 == 0){
      out += fibonacci(n);
    }
    n+=1;
  }
  printf("%d", out);
}
