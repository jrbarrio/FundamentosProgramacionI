#include <stdio.h>

void main (void)
{ 
int caracter;

for (caracter=32;caracter<=225;caracter++)
	printf ("%7d%3c",caracter,caracter);
}