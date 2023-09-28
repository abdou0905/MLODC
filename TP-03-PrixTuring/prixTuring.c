/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

//READ ME
//to do
// pour le moment: arrive a copier les informations du premier winner dans Data
// objectif = boucle sur l'ensemble des winners
// par la suite: passer à l'étape de parcourir l'ensemble des data: copier de data vers le fichier out.csv

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// VARIABLES
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Definition de la struct Data: les différentes informations du fichier
typedef struct{
	int annee;
	char *nomWinner;
	char *natures;
}  Winner; 

//Structures comprenants toutes les data stockées en memoire
Winner* dataWinners; 

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//FONCTIONS
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
	@valideFichier
	Renvoie true si bonne affectation, false sinon
*/

bool fichierValide(FILE * fichier, char fileName[]) {
	bool resultat=false;
	if(fichier != NULL) {
		resultat=true;
	} else {
		printf("Erreur avec le fichier %s",fileName);
	}
	return resultat;
}

/*
	@numberOfWinners 
	prend en paramètre le fichier de données (FILE) et retourne le nombre de ligne qu’il contient
*/
int numberOfWinners(FILE* fichier) {
	int resultat=0;
	char caractere;
	
	//lire pour connaitre le nombre de ligne
	while((caractere=fgetc(fichier)) != EOF) {
		if(caractere == ';'){
			resultat++;
		}
	}

	return resultat/2;
}

/*
	@afficheNumberOfWinners
	affiche le nombre de ligne du fichier //TEST
*/
void afficheNumberOfWinners(int number) {
	printf("Nombre de ligne du fichier= %d\n", number);
}


/*
	@attribuerDate
	attribue dans dataWinner la date du winner traité
*/
void attribuerDate(char dateChaine[], int numeroWinner, Winner* dataWinners) {
	int date= atoi(dateChaine);
	dataWinners[numeroWinner].annee=date;
	printf("winner numero %d date = %d\n", numeroWinner, dataWinners[numeroWinner].annee);
}

/*
	@attribuerNom
	attribue dans dataWinner le nom du winner traité
*/
void attribuerNom(char nomChaine[], int numeroWinner, Winner* dataWinners) {
	dataWinners[numeroWinner].nomWinner=nomChaine;
	printf("winner numero %d nom = %s\n", numeroWinner, dataWinners[numeroWinner].nomWinner);
}

/*
	@attribuerNom
	attribue dans dataWinner la nature du winner traité
*/
void attribuerNature(char nomChaine[], int numeroWinner, Winner* dataWinners) {
	dataWinners[numeroWinner].natures=nomChaine;
	printf("winner numero %d nature = %s\n", numeroWinner, dataWinners[numeroWinner].natures);
}


/*
	@readWinners
	lit en memoire les informations du fichier d'origine + stocke en memoire les données dans dataWinners
*/			
void readWinners(FILE* fichier) {
	//lecture du fichier
	// rewind(fichier);
	// char caractere;
	// while((caractere=fgetc(fichier)) != EOF) {
	// 	printf("%c", caractere);
	// }
	rewind(fichier);
	printf("\n\nTEST affectation donnee\n");

	//stockage des infos dans le tableau de data
	int numberOfLines=numberOfWinners(fichier);
	rewind(fichier);
	int numeroWinner=0;
	
   char caractere2; // caractere en cours de lecture
   while (numeroWinner < numberOfLines) { // tant que different de saut de ligne,on parcour la meme ligne
      for (int numeroColonne = 0; numeroColonne <= 2; numeroColonne++) { // parcours des colonnes de la ligne
   	   // Declaration et Initilisation du buffer
         char buffer[500];
         memset(buffer, 0, sizeof(buffer));

         // Nombre de caractere de notre type de données
         int nombreCaractere = 0;

         // On parcours le fichier jusqu'à rencontrer un ;
         while ((caractere2 = fgetc(fichier)) != EOF) {
            if(caractere2=='\n') {
 					numeroWinner++;
					break;
				} else if (caractere2 != ';') {
               buffer[nombreCaractere] = caractere2; // On remplie le buffer des caractères en cours de lectures
               nombreCaractere++;
            } else {
               break; // Sortie de boucle si rencontre d'un ;
            }
         }

         // On marque la fin de la chaine de caractère
          buffer[nombreCaractere] = '\0';

         // Attribution en fonction du type de données
         if (numeroColonne == 0) {
            attribuerDate(buffer, numeroWinner, dataWinners);
         } else if (numeroColonne == 1) {
            attribuerNom(buffer, numeroWinner, dataWinners);
         } else if (numeroColonne == 2) {
            attribuerNature(buffer, numeroWinner, dataWinners);
         }
         
			// Sortie si on rencontre un saut de ligne
         if (caractere2 == '\n') {
            break;
         }
      }   
   }
}


/*
	@printWinners
	prend les donnes data et vient les ecrires dans fichier
*/
void printWinners(FILE* Fichier, Winner* datas) {
	// TO DO
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

   //Declaration des variables fichiers
	FILE * turingWinners = fopen(filename, "r");
	FILE * out = fopen(outputFilename, "r");

	if(fichierValide(turingWinners,filename) && fichierValide(out, outputFilename)) {
		//Allocation dynamique en mémoire de datas
		int nb = numberOfWinners(turingWinners);
		dataWinners = (Winner *)malloc(nb*sizeof(Winner));

		//Lis le fichier + stocke en memoire les infos dans dataWinners
		printf("\nLECTURE DU FICHIER 'TuringWinners.csv'\n\n\n");
		readWinners(turingWinners);	

		//Copie de dataWinners vers out
		/// utilisation de la fonction printWinner
	}
	
	//Fermeture des fichiers
	fclose(turingWinners);
	fclose(out);

	//liberation de la memoire
	free(dataWinners);

	return EXIT_SUCCESS;
}
