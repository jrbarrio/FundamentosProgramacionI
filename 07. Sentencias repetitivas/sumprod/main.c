#include <stdio.h>

void main (void)
{
unsigned numero, contador_1, contador_2;
double suma, producto;

printf ("INTRODUCE UN Nº ENTERO POSITIVO --->");
scanf ("%u",&numero);
for (contador_1=1,suma=0;contador_1<=numero;contador_1++)
	{
	producto=1;
	for (contador_2=1;contador_2<=contador_1;contador_2++)
		producto=producto*contador_1;
	suma=suma+producto;
	}
printf ("\nRESULTADO=%.0lf",suma);
}