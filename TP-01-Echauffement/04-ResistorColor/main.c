#include <stdio.h>

enum Colors {
   BLACK,
   BRONW,
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   BLUE,
   VIOLET,
   GREY,
   WHITE
};

//pointeur sur les 
const char *colorNames[]= {
   "Black",
   "Brown",
   "Red",
   "Orange",
   "Yellow",
   "Green",
   "Blue",
   "Violet",
   "Grey",
   "White"
};

int main() {
   enum Colors oneColor;
   
   oneColor = RED;
   // 1] afficher le code de la couleur rouge
   printf ("\nla code couleur est : %d", oneColor);

   // 2] afficher tous les codes des couleurs
   printf("\nTous les codes Couleurs:\n");
   
   for(enum Colors color=BLACK; color<=WHITE; color++) {
      printf("%s = %d\n",colorNames[color], color); //colorNames[color] donne le nom de la couleur, color donne le code de la couleur
   }

}