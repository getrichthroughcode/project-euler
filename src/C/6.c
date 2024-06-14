#include <stdio.h>
#include <stdlib.h>

int main (){
  int n = 100;
  int out = ((n*n*(n+1)*(n+1))/4)-((n*(n+1)*(2*n+1))/6);
  printf("%d", out);
  return 0;
}
