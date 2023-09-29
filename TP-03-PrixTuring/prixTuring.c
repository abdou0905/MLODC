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
// BUG dans la memoire je pense: essayer peut etre d'imprimer l'ensemble des donnees de data une fois qu'elles ont ete copié
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
	// faire la copie dans le fichier directement, MALIN!
	
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
	rewind(fichier);
	char caractere;
	while((caractere=fgetc(fichier)) != EOF) {
		printf("%c", caractere);
	}

	rewind(fichier);
	printf("\n\nCOPIE DES DONNEES FICHIERS EN MEMOIRE\n");

	//stockage des infos dans le tableau de data
	int numberOfLines=numberOfWinners(fichier);
	int numeroWinner=0;
	rewind(fichier);
	
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
				numeroWinner++;
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
void printWinners(FILE* fichierDestinationCopie, Winner* datas, int nbOfWinner) {
	//copier les informations

	// char chaine1[5];
	// char chaine2[100];
	// char chaine3[200];

	// sprintf(chaine1, "%d", datas[0].annee);
	// printf("\n%s", chaine1);

	// sprintf(chaine2, "%s", datas[3].nomWinner);
	// printf("\n%s",chaine2);
	// // printf("\n%s", datas[0].natures);

	// sprintf(chaine3, "%s", datas[0].natures);
	// printf("\n%s", chaine3);



	for(int i=0; i<nbOfWinner;i++){
		//initialisation du buffer
		char buffer[500];
      memset(buffer, 0, sizeof(buffer));

		
		
		//faire buffer= une ligne complete
		// char chaine1[6];

		// sprintf(chaine1, "%d", datas[i].annee);

		// strcat(buffer, chaine1);
		// char chaine2[100];
		// strcpy(chaine2,datas[i].nomWinner);
		// printf("%s",chaine2);

		// strcat(buffer, chaine2);
		// strcat(buffer, datas[i].natures);

		// printf("buffer = %s", buffer);


		printf("date winner %d = %d\n",i,datas[i].annee);
		printf("nom winner %d = %s\n",i,datas[i].nomWinner);
		printf("natures winner %d = %s\n",i,datas[i].natures);

		//copie de une ligne	dans le fichier out
		// fputs(buffer,fichierDestinationCopie);
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

   //Declaration des variables fichiers
	FILE * turingWinners = fopen(filename, "r");//read mode
	FILE * out = fopen(outputFilename, "w"); //write mode

	if(fichierValide(turingWinners,filename) && fichierValide(out, outputFilename)) {
		//Allocation dynamique en mémoire de datas
		int nbOfWinner = numberOfWinners(turingWinners);
		dataWinners = (Winner *)malloc(nbOfWinner*sizeof(Winner));

		//Lis le fichier + stocke en memoire les infos dans dataWinners
		printf("\nLECTURE DU FICHIER 'TuringWinners.csv'\n\n\n");
		readWinners(turingWinners);	

		//Copie de dataWinners vers out
		// / utilisation de la fonction printWinner
		printf("\nCOPIE DES DONNES DANS OUT.CSV\n\n");

		

		printWinners(out,dataWinners,nbOfWinner);

	}
	
	//Fermeture des fichiers
	fclose(turingWinners);
	fclose(out);

	//liberation de la memoire
	free(dataWinners);

	return EXIT_SUCCESS;
}
