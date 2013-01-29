# include <stdio.h>

/*********************************************************/

void comprueba (int numero );
int inferiores (int centro );

/*********************************************************/

void main (void)
{
int numero;
printf ("INTRODUCIR UN NUMERO N --->");
scanf ("%d",&numero);
do
	{
	comprueba (numero );
	numero -- ;
	}
while (numero != 0);
}

/**********************************************************/

void comprueba (int numero )
{
int centro = numero ;
int superiores = ++numero ;
do
	{
	numero++ ;
	superiores = superiores + numero ;
	}
while (superiores < inferiores (centro)) ;
if ( superiores ==inferiores (centro) )
	printf ("EL NUMERO %d ES UN CENTRO NUMERICO \n",centro);
}


/***********************************************************/

int inferiores (int centro )
{
int inferiores;
centro --;
for (inferiores = centro; centro != 0;)
	{
	centro --;
	inferiores = inferiores + centro;
	}
return (inferiores) ;
}