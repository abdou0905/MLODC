#include <stdio.h>
#include "echangeContenu.h"

int main(void)
{
	int a=4,b=14;
	int* pa = &a; // pointeur de A
   int* pb = &b; // pointeur de B

	printf ("a = %d\tb = %d\n", a, b);

	echangeContenu(pa,pb);

	printf ("a et b echanges \n");
	printf ("a = %d\tb = %d\n", a, b);

	return 0;
}

