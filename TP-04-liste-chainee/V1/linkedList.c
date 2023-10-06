#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	if(l == NULL) {
		return true;
	} else {
		return false;
	}
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = (Liste)malloc(sizeof(Cellule));
	l->val=v;
	l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste liste=creer(v);
	liste->suiv=l;
	return liste;
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste liste=l;
	while(liste != NULL){
		afficheElement(liste->val);
		liste=liste->suiv;
	}
}

// version recursive
void afficheListe_r(Liste l) {
	Liste liste = l;
	if(!estVide(liste)) {
		afficheElement(liste->val);
		afficheListe_r(liste->suiv);
	} else {
		printf("\n");
	}
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	while(l != NULL){
		Liste liste = l->suiv;
		free(liste);
		l=liste;
	}
}

// version récursive
void detruire_r(Liste l) {
	Liste liste = l;
	if(l != NULL) {
		detruire_r(liste->suiv);
	} else {
		free(liste);
		l=liste;
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste elem = creer(v);
	Liste p = l;
	if(estVide(p)){
		return elem;
	} 
	
	while(!estVide(p->suiv)){
		p = p->suiv;
	}
	p->suiv = elem;
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	Liste elem = creer(v);
	if(l->suiv !=NULL) {
		ajoutFin_r(v,l->suiv);
	}	else {
		l->suiv = elem;
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste p=l;
	while(!estVide(p) && !equalsElement(p->val,v)){
		p=p->suiv;
	}
	return p;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	Liste res;
	if(!estVide(l)){
		if(!equalsElement(l->val,v)){
			// est pas egal
			cherche_r(v,l->suiv);
		} else {
			res=l->suiv;
		}
	} else {
		res=l;
	}
	return res;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste precedent,p;

	if(estVide(l)){
		return l;
	}

	if(equalsElement(l->val,v)){
		p=l->suiv;
		l->suiv=NULL;
		detruire_r(l);
		return p;
	}

	precedent = l;
	p=l->suiv;
	while(!estVide(p) && !equalsElement(p->val,v)){
		precedent=p;
		p=p->suiv;
	}

	if(!estVide(p)){
		precedent->suiv=p->suiv;
		p->suiv=NULL;
		detruire_r(p);
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(estVide(l)){
		return l;
	}

	if(equalsElement(l->val,v)){
		Liste p=l->suiv;
		l->suiv=NULL;
		detruire_r(l);
		return p;
	}
	
	l->suiv=retirePremier_r(v,l->suiv);
	return l;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



