# include <stdio.h>

void main (void)
{
float gasto, descuento;
printf ("INTRODUZCA LA CANTIDAD GASTADA --->");
scanf ("%f",&gasto);
if (gasto>10000)
	{
	if (gasto>20000)
		{
		descuento=gasto*3/10;
		printf ("DESCUENTO ALTO");
		}
	else
		{
		descuento=gasto/5;
		printf ("DESCUENTO MEDIO");
		}
	}
else
	{
	if (gasto>6000)
		{
		descuento=gasto/10;
		printf ("DESCUENTO BAJO");
		}
	else
		printf ("DESCUENTO NULO");
	}

printf ("\nSU GASTO ES DE %.2f PTAS\n",gasto);
printf ("LE CORRESPONDE UN DESCUENTO DE %.2f PTAS\n",descuento);
printf ("LA CANTIDAD A PAGAR SON %.2f PTAS\n",gasto-descuento);
}










