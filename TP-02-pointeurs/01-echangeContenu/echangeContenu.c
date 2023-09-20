#include "echangeContenu.h"
#include <stdio.h>


void echangeContenu (int* pa, int* pb) {
  
   int c = *pa; // contenu de la valeur a
   int *pc  = &c;
   
   *pa = *pb; // a l'adresse de a, mettre valeur B 
   *pb = *pc; 
}