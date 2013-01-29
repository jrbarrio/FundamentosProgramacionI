# include <stdio.h>
# define SECRETO 38

void main (void)
{
int intento, numero;
intento=10;
do
	{
	printf ("LE QUEDAN %d OPORTUNIDADES.",intento);
	printf ("INTRODUZCA UN NUMERO ENTRE 0  Y 99 --->");
	scanf ("%d",&numero);
	intento= --intento;
	}
while (numero!=SECRETO && intento!=0);
if (numero==SECRETO)
	{
	printf ("\n ¡¡ENHORABUENA!! HA ACERTADO EL NUMERO SECRETO.");
	printf ("\n LA NOTA OBTENIDA HA SIDO %d.",1+intento);
	}
else
	printf ("\n FIN DEL JUEGO. VUELVA A INTENTARLO.");
}
