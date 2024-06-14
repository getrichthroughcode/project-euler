#include <stdio.h>
#include <stdlib.h>

void sommetab (int long, int tab1[],int tab2[]){
  int i = 0;
  while (i < l){
    *tab1[i] = *tab[i] + *tab2[i];
    i++;
  }
}



int main (){
  int tab1[3] = {0,1,2};
  int tab2[3] = {4,5,6};
  sommetab(3,tab1,tab2);
  int i = 0;
  while (i < 3){
    printf ("%d %d\n", tab1[i],i);
    i++;
  }
  return 0;
}
