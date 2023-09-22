#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

char phrase1[]=" bottles of beer on the wall, ";
char phrase2[]=" bottles of beer.Take one down and pass it around, ";
char phrase3[]=" bottles of beer on the wall.";

void reciterVerse(int n) {
   if(n==0){
      afficherNoMore();
      printf("%s", phrase1);
      afficherNoMore();
      printf("%s", phrase2);
      afficherNombre(1);
      printf("%s", phrase3);
      printf("\n\n");

   }
   afficherNombre(n);
   printf("%s", phrase1);
   afficherNombre(n);
   printf("%s", phrase2);
   afficherNombre(n-1);
   printf("%s", phrase2);
   printf("\n\n");
}

void afficherNombre(int n) {
   printf("%d", n);
}

void afficherNoMore() {
   printf("No More");
}