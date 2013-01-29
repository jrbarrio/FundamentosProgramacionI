#include <stdio.h>
#define MAXTAM 50
#include <math.h>

/**********************************************************/

float media (int [],int elementos);
void moda (int [], int elementos);
void desviacion (int [],int num1, int elementos);

/************************************************************/

void main (void)
{
int array [MAXTAM];
int elementos;
float num1;
int indice;

do
	{
	printf ("NUMERO DE ELEMENTOS (MAXIMO %d) --->",MAXTAM);
	scanf ("%d",&elementos);
        }
while (elementos>MAXTAM);

printf ("\nINTRODUZCA LOS ELEMENTOS.\n");

for (indice=0; indice<elementos; indice++)
	scanf ("%d",&array [indice]);

num1= media (array,elementos);

moda (array, elementos);

desviacion (array, num1, elementos);

}

/*************************************************************/

float media (int array [MAXTAM],int elementos)
{
float media=0;
int ind;
for (ind=0; ind<elementos; ind++)
	media=array [ind] + media;
media=media/elementos;
printf ("\nLA MEDIA ES %.3f",media);
return (media);
}

/***************************************************************/

void moda (int array [], int elementos)
{
static int contador [MAXTAM];
int indi, cuenta, maximo;
for (indi=0; indi<elementos; indi++)
	{
	for (cuenta=0; cuenta<elementos; cuenta++)
		{
		if (array [indi]==array [indi+cuenta])
			contador [indi]++;
		}
	}
for (indi=0, maximo=0;indi<elementos; indi++)
	{
	if (contador [indi]>maximo)
		maximo=contador [indi];
	}
printf ("\n\nEL/LOS NUMERO/S QUE MAS SE REPITE/N ES/SON:\n");
for (indi=0; indi<elementos; indi++)
	{
	if (contador [indi]== maximo)
		printf (" %d ", array [indi]);
	}
}


/******************************************************************/

void desviacion (int array [],int num1, int elementos)
{
float potencia, suma, desviacion;
int indi;
for (indi=0, suma=0; indi<elementos; indi++)
		  {
	potencia= num1 - array [indi];
	potencia=potencia*potencia;
	suma=suma+potencia;
	}
desviacion= sqrt (suma)/elementos;
printf ("\n\nLA DESVIACION TIPICA ES : %.3f",desviacion);
}