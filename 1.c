#include <stdio.h>
#include <stdlib.h>

int main (){
  int compt = 0;
  for (int i = 0; i < 1000; i++)
    if (i%3 == 0 || i%5 == 0){
      compt += i;
    }
  printf ("%d", compt);
  return 0;
}
