#include <stdio.h>
#include <stdlib.h>

int seq (int n){
  return (n*(n+1))/2;
}

int count (int n){
  int out = 0;
  for (int i = 1; i < n-1; i++){
    if (n%i == 0){
      out++;
    }
  }
  return out;
}



int main (){
  int n = 1;
    while (count(seq (n)) < 500){
        n++;
    }
  printf("%d\n", seq(n));
  return 0;  
}
