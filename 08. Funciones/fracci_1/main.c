# include <stdio.h>

void mcd (int, int, int *);

/*************************************************/

void main (void)
{
int numerador,denominador,divisor;
printf ("INTRODUZCA EL NUMERADOR --->");
scanf ("%d",&numerador);
printf ("INTRODUZCA EL DENOMINADOR --->");
scanf ("%d",&denominador);
mcd (numerador,denominador,&divisor);               
printf ("LA FRACCION IRREDUCIBLE EQUIVALENTE ES:\n");
printf ("%20d",numerador/divisor);
printf ("\n                -----\n");
printf ("%20d",denominador/divisor);
}

/***************************************************/

void mcd (int numerador,int denominador,int *divisor)
{                         
do
        {
	for (;numerador>denominador;)
		numerador=numerador-denominador;
	for (;numerador<denominador;)
		denominador=denominador-numerador;
        }
while (numerador!=denominador);
*divisor=numerador;
}