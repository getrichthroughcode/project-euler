#include <stdio.h>
#include <stdlib.h>



int main(){
  FILE* fichier;
  fichier = fopen("inter.txt","r");
  if (fichier == NULL){
    printf("impossile d'ouvrir le fichier");
    return 1;
  }
  int grille[100][50];
  int ligne,colonne;
  for (ligne = 0; ligne < 100; ligne++){
    for (colonne = 0; colonne < 50; colonne++){
    if (fscanf(fichier,"%1d",&grille[ligne][colonne]) != 1){
      printf("erreur lors de la lecture du fichier");
      return 1;
    }
  }
}
int tab[52];
for (int k = 0; k < 52; k++){
  tab[k] = 0;
}
int indice_res;
int indice_diz;
int indice_cen;
for(colonne = 49; colonne >= 0; colonne--){
  indice_res = colonne + 2;
  indice_diz = colonne + 1;
  indice_cen = colonne;
  int sum = tab[indice_res];
  printf("dizaine = %d\n",indice_diz);
  printf("centaine = %d\n",indice_cen);
  printf("sum = %d\n",sum);
  printf("valeur unité = %d\n",tab[indice_res]);
  printf("valeur dizaine = %d\n",tab[indice_diz]);
  printf("valeur centaine = %d\n",tab[indice_cen]);
  for (ligne = 0; ligne < 100; ligne++){
    sum = sum + grille[ligne][colonne];
  }
  printf("res = %d\n",sum);
  if (sum >= 100){
    tab[indice_res] = (sum%100)%10;
    tab[indice_cen] = tab[indice_cen] + sum/100;
    tab[indice_diz] = tab[indice_diz] + (sum%100)/10;
  }
  else{
    tab[indice_res] = sum%10;
    tab[indice_cen] = tab[indice_cen] + sum/100;
    tab[indice_diz] = tab[indice_diz] + sum/10;
  }
}
for (int k = 0; k < 10; k++){
  printf("%d",tab[k]);
}
return 1;
}
