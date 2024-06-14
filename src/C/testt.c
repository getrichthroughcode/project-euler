#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (void)
{
  int i, nb, compter, test;
  test = compter = 0;
  printf ("Entrez un nombre entier : ");
  if (scanf ("%d", &nb) != 1)
    return -1;

  if (nb % 2 == 0)
          test = 1;
  else{
      for (i = 3 ; i < nb; i+=2, compter++)
        if (nb % i == 0)
          test = 1;
  }
  if (!test)
          printf ("%d nombre premier, nombre iterations = %d\n",
                          nb, compter);
  else
          printf ("%d n'est pas nombre premier, nombre iterations = %d\n",nb, compter);
  return 0;
}
