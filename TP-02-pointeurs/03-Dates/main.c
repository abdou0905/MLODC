#include <stdlib.h>
#include <stdio.h>

//Declarations
enum Mois {
   JANVIER, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

struct Date {
   int jour;
   enum Mois mois;
   int annee; 
};
typedef struct Date Date;

//Prototype des fonctions 
void initialiseDate(Date *pDate);
void afficheDate(Date *pDate);
Date creerDateParCopie ();
Date* newDate();

int main() {
   //declaration de ma date et de son pointeur
   Date date;
   Date *pDate = &date;
   printf("\nQuestion b\n");
   initialiseDate(pDate);
   afficheDate(pDate);

   printf("\nQuestion c\n");
   Date nouvelleDate;
   nouvelleDate = creerDateParCopie();
   afficheDate(&nouvelleDate);

   printf ("\nQuestion d\n");
   Date* myNewDate; // new date est un pointeur
   myNewDate = newDate(); 
   afficheDate(myNewDate);



}

//Question B] Initialise la date en parametre
void initialiseDate(Date *pDate) {
   printf("\nQuelle est votre date de naissance?\n");
   printf("\nformat: DD MM YYYY\n");
   scanf("%d %d %d", &pDate->jour, (int*)&pDate->mois, &pDate->annee);
   // scanf("%d %s %d", &pDate->jour, &pDate->mois, &pDate->annee);

   printf("\n");
}



//Question B]Affiche la date passée en paramètre

void afficheDate(Date *pDate) {
   printf("\nLa date est: %d /%d /%d", pDate->jour, pDate->mois, pDate->annee);
}

//Question C]Creation d'une date et son initialisation

Date creerDateParCopie () {
   Date nouvelleDate;
   Date* pNouvelleDate = &nouvelleDate;
   initialiseDate(pNouvelleDate);
   return nouvelleDate;
}

// Question D] 
Date* newDate() {
   Date* nouvelleDate = (Date*)malloc(sizeof(Date));
   initialiseDate(nouvelleDate);
   return nouvelleDate;
}