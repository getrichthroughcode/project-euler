#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (){
  int limit = 10001;
  int nombre = 2;
  int compteur = 0;
  while (compteur < limit){
    int test = 1;
    for (int i = 2;  i < nombre; i++){
      if (nombre%i == 0) {
        test = 0;
      }

    }
    if (test == 1){
      compteur ++;
      nombre++;
    }
    else{
      nombre++;
    }

  }
  printf ("%d\n %d",nombre-1, compteur);
  return 0;
}
