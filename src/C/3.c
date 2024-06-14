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
  long int m    = 600851475143;
  double x = sqrt (m);
  for (int i = 2; i < x; i++){
    if ((is_prime(i)==1) && (m%i == 0))
      printf ("on vient de rencontrer un diviseur premier : %d\n", i);
  }
  return 0;

}
