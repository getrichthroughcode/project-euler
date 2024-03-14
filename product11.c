#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_LIGNES 20
#define MAX_COLONNES 20


int main (){
  FILE* fichier;
  fichier = fopen("inter.txt","r");
  if (fichier == NULL){
    printf("Impossible d'ouvrir le fichier;\n");
    return 1;
  }
  int grille[MAX_LIGNES][MAX_COLONNES];
  int i,j;
  for (i = 0; i < MAX_LIGNES; i++){
    for (j = 0; j < MAX_COLONNES; j++){
      if (fscanf(fichier,"%d",&grille[i][j]) != 1){
        printf("Erreur lors de la lecture du fichier.\n");
        return 1;
      }
    }
  }
  int max = 0;
  int k = 0;
  for (i = 0; i < MAX_LIGNES; i++){
    for (j = 0; j < MAX_COLONNES; j++){
      int aux,auxh,auxv,auxod,auxog,max1,max2,max3;
      if (i < 17 && j < 3){
        aux = max;
        auxh = grille[i][j]*grille[i][j+1]*grille[i][j+2]*grille[i][j+3];
        auxv = grille[i][j]*grille[i+1][j]*grille[i+2][j]*grille[i+3][j];
        auxod= grille[i][j]*grille[i+1][j+1]*grille[i+2][j+2]*grille[i+3][j+3];
        max1 = fmax(auxh,auxv);
        max2 = fmax(auxod,aux);
        max = fmax(max1,max2);
      }
      if ( i < 17 && j > 2 && j < 17){
        aux = max;
        auxh = grille[i][j]*grille[i][j+1]*grille[i][j+2]*grille[i][j+3];
        auxv = grille[i][j]*grille[i+1][j]*grille[i+2][j]*grille[i+3][j];
        auxod = grille[i][j]*grille[i+1][j+1]*grille[i+2][j+2]*grille[i+3][j+3];
        auxog = grille[i][j]*grille[i+1][j-1]*grille[i+2][j-2]*grille[i+3][j-3];
        max1 = fmax(auxh,auxv);
        max2 = fmax(auxod,auxog);
        max3 = fmax(max1,max2);
        max = fmax(aux,max3);
        }
        if (i < 17 && j > 16){
          aux = max;
          auxv = grille[i][j]*grille[i+1][j]*grille[i+2][j]*grille[i+3][j];
          auxog = grille[i][j]*grille[i+1][j-1]*grille[i+2][j-2]*grille[i+3][j-3];
          max1 = fmax(auxv,auxog);
          max =fmax(aux,max1);
        }
        if (i > 16 && j < 17){
          aux = max;
          auxh = grille[i][j]*grille[i][j+1]*grille[i][j+2]*grille[i][j+3];
          max = fmax(aux,auxh);
        }
        if (i > 16 && j > 16){
          k++;
          printf("cas limite déjà inclus dans un produit %d\n",k);
        }
    }
  }
  printf("%d\n",max);
  return 1;
}
