#include <stdio.h>

#define FILA 5
#define COLU 5

void main (void)
{
int array [FILA] [COLU];
int col, fil;

for (fil=0; fil<FILA; fil++)
	for (col=0; col<COLU; col++)
		scanf ("%d", &array [fil] [col]);

for (fil=0; fil<FILA; fil++)
	{
	printf ("\n");
	for (col=0; col<COLU; col++)
		printf (" %d", array [fil] [col]);
	}
}
