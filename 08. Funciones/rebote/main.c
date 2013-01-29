# include <stdio.h>

void calcula (float *altura, float factor,int orden);

/*********************************************************/

void main (void)
{
int orden=1 ;
float altura,factor,nueva;
printf ("INTRODUCE LA ALTURA INICIAL --->");
scanf ("%f",&altura);
printf ("INTRODUCE EL FACTOR DE REBOTE --->");
scanf ("%f",&factor);
printf ("INTRODUCE LA NUEVA ALTURA --->");
scanf ("%f",&nueva);
do
	{
	calcula (&altura,factor,orden);
	orden ++ ;
	}
while (altura>nueva);
printf ("LA PRIMERA ALTURA INFERIOR A LA DADA ES --->%f\n",altura);
printf ("EL NUMERO DE ORDEN DEL REBOTE ES --->%d\n",orden);
}


/*****************************************************************/


void calcula (float *altura, float factor,int orden)
{
for (; orden>0; orden --)
	*altura= *altura * factor;
}
