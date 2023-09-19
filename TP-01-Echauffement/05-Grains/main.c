#include <stdio.h>
#include <stdint.h>
#define NBSQUARES 64

int64_t nbGrainOneGivenSquare(int square) {
   int64_t result = 1;

   for (int i = 1; i < square; i++) {
      result *= 2;
   }

   return result;
}

int main() {
   // 1] Donner le nombre de grain sur une case donnée
   int numberSquare = 0;
   printf("\nCase dont vous souhaitez le nombre de grains: ");
   scanf("%d", &numberSquare);
   printf("\nLe nombre de Grains sur la case numero %d = %I64d", numberSquare, nbGrainOneGivenSquare(numberSquare));

   // 2] Nombre total de Grain sur le plateau d'échec
   int64_t nbGrainsTot = 0;
   for (int i = 1; i <= NBSQUARES; i++) {
      nbGrainsTot += nbGrainOneGivenSquare(i);
   }

   printf("\nLe nombre total de grain sur l'echiquier est : %I64d\n", nbGrainsTot);
   return 0;
}
