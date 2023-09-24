#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrices.h"

//Fonctions sur les matrices

//on veut générer des matrices de tailles variables

Matrice* creer(int val, int nbLigne, int nbColonne) {
   //On alloue dynamiquement la memoire à Matrice
   Matrice* mat = (Matrice*)malloc(sizeof(Matrice));

   //On definit le nombre de ligne et colonne 
   mat->nbLigne= nbLigne;
   mat->nbColonne = nbColonne;

   //On alloue dynamiquement la memoire pour les pointeurs de la ligne matrice
   mat->elements = (int**)malloc(nbLigne * sizeof(int*));

   for (int i = 0; i < nbLigne; i++) {
      //On alloue dynamiquement la memoire pour les pointeurs des colonnes de la matrices
      mat->elements[i] = (int*)malloc(nbColonne * sizeof(int));

      for (int j = 0; j < nbColonne; j++) {
         mat->elements[i][j] = val;
      }
   }
   return mat;

}

void initialiserLigne(int numLigne, int valeur, Matrice* A){
   // printf("je suis dans initialiser");
   // printf("%d", A->nbColonne);
   // printf("%d", A->elements[1][1]);
   for (int i=0; i<A->nbColonne; i++){
      A->elements[numLigne][i]=valeur;
      printf("%d", A->elements[numLigne][i]);
   }  
}

//Multiplie les matrices A.B
Matrice* multiplier(Matrice* A, Matrice* B){
   //Creation de la matrice resultat
   Matrice* resultat=creer(0, A->nbLigne, B->nbColonne);

   //On effectue la multiplication
   for(int i=0;i<A->nbLigne; i++){ // On parcours les lignes de A
      for(int j=0; j<B->nbColonne;j++){ //On parcours les colonnes de B
         for(int k=0; k<resultat->nbLigne; k++) { //On parcours les lignes de resultats
            resultat->elements[i][j] += A->elements[i][k] * B->elements[k][j];
         }
      }
   }
   return resultat;
}

void afficherMatrice(Matrice* A) {
   for(int i=0; i<A->nbLigne; i++) {
      for(int j=0; j<A->nbColonne;j++) {
         printf("%d", A->elements[i][j]);
      }
      printf("\n");
   }
}

void libererMatrice(Matrice* A){
   for (int i = 0; i < A->nbLigne; i++) {
      free(A->elements[i]);
   }
   free(A->elements);
   free(A);
}