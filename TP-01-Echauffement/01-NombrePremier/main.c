#include <stdio.h>
#include <stdbool.h>

bool estParfait(int nombre) {
   int somme=0;
   if(nombre==1) {
      return true;
   } else {
      for(int i=1; i<nombre; i++) {
         if (nombre % i == 0) {
            somme+=i;
         }
      };
      return somme == nombre;
   }   
}

int main() {
   int nombre;
   printf ("\nVeuillez entrer un entier positif: ");
   scanf("%d", &nombre);
  
   if( nombre > 0) {
      for (int i=1; i<=nombre; i++) {
         if(estParfait(i)){
            printf("%d est parfait\n", i);
         } else {
            printf("%d non parfait\n", i);
         }
      }
   } else {
      printf("Veuillez entrer un entier strictement positif");
   }
   return 0;
}
