#include <stdio.h>
#include <stdbool.h>
//Isogramme est une chaine de caractere qui n'a pas deux fois la meme lettre
//les espaces ou autres caracteres sont autorisé à apparaitre plusieurs fois
//rappels: char = 1 caractère, char[] = chaine de caractere

bool estIsogramme(char mot[] ) {
   bool result = false;
   char x = mot[0];
   for (int i=1; i<sizeof mot; i++) {
      
   }
   return result; 
}

int main() {
   char a = 'a';
   char b = 'b';
   if (a == b ) {
      printf("succes");
   } else {
      printf("difference");
   }

   return 0;
}