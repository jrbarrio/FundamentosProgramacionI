#include <stdio.h>
#define MAXTAM 10

void main (void)
{
int arrayX [MAXTAM];
int arrayY [MAXTAM];
int menor, mayor ;
int indice =0;

printf ("INTRODUZCA LOS ELEMENTOS DEL ARRAY X\n");
do
	scanf ("%d",&arrayX [indice++]);
while (indice<MAXTAM);

indice = 0;
printf ("INTRODUZCA LOS ELEMENTOS DEL ARRAY Y\n");
do
	scanf ("%d",&arrayY [indice ++]);
while (indice<MAXTAM);

indice =0;
do
	{
	printf ("%8d  %8d\n",arrayX [indice],arrayY [indice]);
	indice ++ ;
	}
while (indice<MAXTAM);

indice =0;
menor=0;
mayor = 0;
do
	{
	if (arrayX [indice]<arrayY [indice])
		menor ++ ;
	if (arrayX [indice]>arrayY [indice])
		mayor ++ ;
	indice ++ ;
	}
while (indice<MAXTAM);

printf ("Nº DE ELEMENTOS DE X MENORES QUE LOS DE Y = %d\n",menor);
printf ("Nº DE ELEMENTOS DE X MAYORES QUE LOS DE Y = %d\n",mayor);
}




