# include <stdio.h>

/********************************************************/

float potencia (float numero, int grado);
int factorial (int grado);

/******************************************************/


void main (void)
{
float numero;
float coseno = 0;
int grado = 0 ;
float termino;
int signo = 1 ;
printf ("INTRODUZCA LA X --->");
scanf ("%f",&numero);
do
	{
	termino= potencia (numero,grado)/factorial (grado) ;
	coseno = coseno + signo*termino ;
	signo = -signo ;
	grado = grado + 2 ;
	}
while (termino > 0.0005 );
printf ("EL COSENO DE X ES --->%f",coseno);
}


/******************************************************/

float potencia (float numero, int grado)
{
float potencia ;
if (grado>0)
	{
	for (potencia = numero ; grado > 1;grado --)
		potencia = potencia*numero;
	}
else
	potencia =1;
return (potencia);
}

/******************************************************/


int factorial (int grado)
{
int factorial ;
if (grado >0)
	for (factorial =grado;grado>1 ; )
		{
		grado --;
		factorial = factorial*grado;
		}
else
	factorial=1;
return (factorial);
}