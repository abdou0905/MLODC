/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
<<<<<<< HEAD
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

//valideFichier
// Renvoie true si bonne affectation, false sinon
bool fichierValide(FILE * fichier, char fileName[]) {
	bool resultat=false;
	if(fichier != NULL) {
		resultat=true;
	} else {
		printf("Erreur avec le fichier %s",fileName);
	}
	return resultat;
}

// numberOfWinners 
//prend en paramètre le fichier de données (FILE) et retourne le nombre de ligne qu’il contient
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

//afficheNumberOfWinners
void afficheNumberOfWinners(int number) {
	printf("Nombre de ligne du fichier= %d\n", number);
}


// numberOfChar
int numberOfChar(char chaine[]) {
	int i=0;
	int resultat = 0;
	while(chaine[i] != ';') {
		i++;
		resultat++;
	}
	return resultat;

}

void attribuerDate(char dateChaine[], int numeroWinner, Winner* dataWinners) {
	int date= atoi(dateChaine);
	dataWinners[numeroWinner].annee=date;
	printf("winner numero %d date = %d\n", numeroWinner, dataWinners[numeroWinner].annee);
}

void attribuerNom(char nomChaine[], int numeroWinner, Winner* dataWinners) {
	dataWinners[numeroWinner].nomWinner=nomChaine;
	printf("winner numero %d nom = %s\n", numeroWinner, dataWinners[numeroWinner].nomWinner);
}

void attribuerNature(char nomChaine[], int numeroWinner, Winner* dataWinners) {
	dataWinners[numeroWinner].natures=nomChaine;
	printf("winner numero %d nature = %s\n", numeroWinner, dataWinners[numeroWinner].natures);
}


			
//readWinners 
//lit et stocke en memoire les info du fichier, dans le tableau datas
void readWinners(FILE* fichier) {
	//lecture du fichier
	char caractere;
	while((caractere=fgetc(fichier)) != EOF) {
		printf("%c", caractere);
	}
	rewind(fichier);

	//stockage des infos dans le tableau de data

	//numero du winner en cours de lecture
	int numeroWinner=0;
	//0: date; 1: nomWinner; 2:nature
	int numeroColonne=0;
	//caractere en cours de lecture
	char caractere2;
	
		for(numeroColonne=0; numeroColonne<=2;numeroColonne++){
			//Declaration et Initilisation du buffer
			char buffer[500];
			memset(buffer,0,sizeof(buffer));

			//Nombre de caractere de notre type de données
			int nombreCaractere=0;

			//On parcours le fichier jusqu'à rencontrer un ;
			while((caractere2=fgetc(fichier)) != EOF) {
				if(caractere2 != ';'){
					buffer[nombreCaractere]=caractere2; //On remplie le buffer des caractères en cours de lectures
					nombreCaractere++;
				} else {
					break; //Sortie de boucle si rencontre d'un ;
				}
			}
		
			//On marque la fin de la chaine de caractère
			buffer[nombreCaractere+1]='\0';

			//attribution en fonction du type de données
			if(numeroColonne==0) {
				attribuerDate(buffer, numeroWinner,dataWinners);
			} else if( numeroColonne == 1) {
				attribuerNom(buffer, numeroWinner,dataWinners);
			} else {
				attribuerNature(buffer, numeroWinner,dataWinners);
			}
		}
}

// printWinners
//prend les donnes data et vient les ecrires dans fichier

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

	//test fonction number of winner
	// //Si l'ouverture du fichier a bien fonctionne
	// if(fichierValide(turingWinners, filename)) {
	// 	// readWinners(turingWinners);
	// 	printf("Fichier original\n");
	// 	afficheNumberOfWinners(numberOfWinners(turingWinners));
	// } 

	// if(fichierValide(out, outputFilename)) {
	// 	printf("Fichier out\n");
	// 	afficheNumberOfWinners(numberOfWinners(out));
	// }


	if(fichierValide(turingWinners,filename) && fichierValide(out, outputFilename)) {
		//Allocation dynamique en mémoire de datas
		int nb = numberOfWinners(turingWinners);
		dataWinners = (Winner *)malloc(nb*sizeof(Winner));

		//Lis le fichier + stocke en memoire les infos dans dataWinners
		readWinners(turingWinners);	
	}
	

	
	//Fermeture des fichiers
	fclose(turingWinners);
	fclose(out);

	//liberation de la memoire
	free(dataWinners);
=======

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    // TODO
>>>>>>> a8c77591435c12292cd2cec9312d343be997bcc0

	return EXIT_SUCCESS;
}
