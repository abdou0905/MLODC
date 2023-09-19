#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier);

int main() {
   TypeEntier entier=24;
   printf("factorielle de %" PRIu64 " = %" PRIu64 "\n", entier, factorielle(entier));   
};

TypeEntier factorielle(TypeEntier n) {
   TypeEntier resultat=1;
   for(int i=1; i<=n; i++) {
      resultat*=i;
   }
   return resultat;
};



