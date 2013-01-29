#include <stdio.h>
#define FILA 5
#define COLU 5

void main (void)
{
int filas, columnas;
int array [FILA] [COLU];

for (filas=0;filas<FILA;filas++)
	for (columnas=0;columnas<COLU;columnas++)
		scanf ("%d",*(array+filas)+columnas);



for (filas=0;filas<FILA;filas++)
	{
        printf ("\n");
	for (columnas=0;columnas<COLU;columnas++)
		printf ("%4d",*(*(array+filas)+columnas));
        }
}






