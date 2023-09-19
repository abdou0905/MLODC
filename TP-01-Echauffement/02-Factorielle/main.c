#include <stdio.h>
#include <inttypes.h>

typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier);

int main() {
   TypeEntier entier=15;

   for(int i=1; i<=entier; i++){
     printf("factorielle de %d = %" PRIu64 "\n", i, factorielle(i));
   };
   
}

TypeEntier factorielle(TypeEntier n) {
   TypeEntier resultat=1;
   for(int i=1; i<=n; i++) {
      resultat*=i;
   }
   return resultat;
};