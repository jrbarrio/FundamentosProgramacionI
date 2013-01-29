#include <stdio.h>
#include <math.h>

void main (void)
{
float numero, ro, ri, ril, siguiente, epsilon;
int encontrado;
printf ("INTRODUCE EL NUMERO --->");
scanf ("%f",&numero);
printf ("INTRODUCE LA PRECISION EPSILON --->");
scanf ("%f",&epsilon);
printf ("INTRODUCE LA APROXIMACION DE LA RAIZ CUADRADA DEL NUMERO --->");
scanf ("%f",ro);
ri=ro;
encontrado=0;
do
	{
	ril=(numero/ri+ri)/2;
	if (((ri>ril)?(ri-ril):(ril-ri))<=epsilon)
		encontrado=1;
	else
		ri=ril;
	}
while (!encontrado);
printf ("EL VALOR DE LA RAIZ ES %f",ri);
}