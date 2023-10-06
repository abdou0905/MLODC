//Adele PATAROT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";
typedef struct {
	int index;
	int distance;
} Difference ;

// =============
// = Fonctions =
// =============

bool isNucleotide(char c) {
   return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
   return indexOf(n1)-indexOf(n2);
}

//Fonction double pour pouvoir faire les divisions
double* statistics(char chaine[]){
	//initialisation du tableau de resultat
	double resultat[4]={0,0,0,0};
	double* pointeur=resultat;
	
	//On compte les occurences de chaque lettre
	for(int i=0; i<strlen(chaine); i++){
		if(isNucleotide(chaine[i])){
			if(chaine[i]=='A'){
				resultat[0]++;
			} else if (chaine[i]=='T'){
				resultat[1]++;
			} else if (chaine[i]=='C'){
				resultat[2]++;
			} else if (chaine[i]=='G'){
				resultat[3]++;
			}
		}
	}

	//En effectue le calcul du pourcentage
	for(int i=0; i<4; i++){
		resultat[i]=(resultat[i]/strlen(chaine))*100;
	}

	return pointeur;
}

Difference* newDifference(){
	Difference* new = (Difference*)malloc(sizeof(Difference));
	return new;
}

Difference* initiDifference(int index, int distance, Difference* new){
	new->distance=distance;
	new->index=index;
	return new;
}

void computeDifferenceBetween(const char seq1[], const char seq2[], Difference* diff[]){
	//Taille des deux chaines de caractères
	int lenght=strlen(seq1);
	// printf("taille=%d", lenght);
	int nbDiff=0;
	//Recherche de différence
	for(int i=0; i<=lenght; i++){
		//Couple de recherche pour une difference, reinitialisé à chaque itération
		int index=0;
		int distance=0;
		if(isNucleotide(seq1[i]) && isNucleotide(seq2[i])){ // Verifi caractères = nucléotides
			if (seq1[i]!=seq2[i]) { // Si différence
				// printf("jai trouve 1 diff\n");
				index=i;
				distance=distanceBetweenNucleotides(seq1[i], seq2[i]);
				//Ajout de cette nouvelle différence dans notre tableau de difference
				diff[nbDiff]=initiDifference(index,distance,newDifference());
				// printf("Diff num %d: distance=%d et index =%d\n", nbDiff,diff[nbDiff]->distance, diff[nbDiff]->index);
				nbDiff++;
			}
		}
	}
}

void printDifferences(Difference** differences){
	int i=0;
	while(differences[i]!=NULL){
		printf("Difference numero %d: <%d,%d>\n",i+1,differences[i]->index,differences[i]->distance);
		i++;
	}
}

// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";
	// const char seq1[]="ATGC";
	// const char seq2[]="ATCG";
	
	printf("Dans la sequence: %s\n",sequenceDeNucleotides);
	printf("%f pourcent de A\n", statistics(sequenceDeNucleotides)[0]); //A
	printf("%f pourcent de T\n", statistics(sequenceDeNucleotides)[1]); //T
	printf("%f pourcent de C\n", statistics(sequenceDeNucleotides)[2]); //C
	printf("%f pourcent de G\n", statistics(sequenceDeNucleotides)[3]); //G

	printf("\n\n");
	//Initialiser dynamiquement avec un malloc le tableau de différences
	int taillemax=strlen(code_proteine_spike_moderna); // Nombre maxi de differences
	Difference** differences= (Difference**)malloc(taillemax*sizeof(Difference*));
	computeDifferenceBetween(code_proteine_spike_pfizer, code_proteine_spike_moderna, differences);
	printf("Pour les sequences code_proteine_spike_pfizer &  code_proteine_spike_moderna\n");
	printDifferences(differences);	
	free(differences);

	return EXIT_SUCCESS;
}

