#include <stdio.h>
#include <stdlib.h>

int longcol(long n){
  if (n == 1){
    return 1;
  }
  if (n%2==0){
    return 1+longcol(n/2);
  }
  else{
    return 1+longcol(3*n+1);
  }
  }



int main (){
  long n = 200000;
  long out = 0;
  int aux = 0;
  while (n < 1000000){
    int aux1 = longcol(n);
    if (aux1 > aux ){
      aux = aux1;
      out = n;
      n++;
    }
    else{
      n++;
    }
  }
  printf("%ld\n %d ",out, aux);
  return 0;
}
