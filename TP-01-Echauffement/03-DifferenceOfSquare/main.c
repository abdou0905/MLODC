#include <stdio.h>
#include <math.h>


int sommeDesCarrees(int nombre) {
   int resultat=0;
   for(int i=1; i<=nombre;i++)  {
      resultat+= pow(i,2);
   }
   printf("somme des carre %d", resultat);
   return resultat;
}

double carreeDeSomme(int nombre) {
   double resultat=0;
   double somme=0;
   for(int i=0; i<=nombre;i++){
      somme+=i;
      printf("somme=%f\n", somme);
   }
   resultat = pow(somme,2);
   printf("carre de la somme %f\n", resultat);

   return resultat;
}

int main() {
   int nombre = 0;
   printf("Entrez un entier: ");
   scanf("%d",&nombre);
   printf("\nLa difference est : %f", carreeDeSomme(nombre)-sommeDesCarrees(nombre));
   return 0; 
};
