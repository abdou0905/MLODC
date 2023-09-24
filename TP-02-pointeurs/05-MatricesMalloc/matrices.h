#pragma once

//Signatures des fonctions matrices

typedef struct  {
//definir la matrice
   int **elements;
   int nbLigne;
   int nbColonne;
} Matrice;

Matrice* creer(int val, int nbLigne, int nbColonne);

void initialiserLigne(int numLigne, int valeur, Matrice* A);

Matrice* multiplier(Matrice* A, Matrice* B);

void afficherMatrice(Matrice* A);

void libererMatrice(Matrice* A);