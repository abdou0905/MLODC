#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int main() {
   Matrice *A, *B, *C;
   A = creer(1, 3, 3); // valeurInitiale, nbreLignes, nbreColonnes
   B = creer(1, 3, 3);

   printf("Matrice A created\n");
   afficherMatrice(A);
   printf("Matrice B created\n");
   afficherMatrice(B);

   initialiserLigne(2, 1, A);
   initialiserLigne(2, 2, B);

   printf("Matrice A init\n");
   afficherMatrice(A);
   printf("Matrice B init\n");
   afficherMatrice(B);
   
   C = multiplier(A, B);  

   libererMatrice(A);
   libererMatrice(B);
   libererMatrice(C);
   // free(A);
   // free(B);
}