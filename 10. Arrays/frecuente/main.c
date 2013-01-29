#include <conio.h>
#include <stdio.h>
#define MAXTAM 15


void frecuente (char[], int);

/*********************************************/

void main (void)
{
int num_elementos;
int indice=0;
char caracteres[MAXTAM];
do
	caracteres [indice]=getche ();
while (caracteres [indice++]!=' ' && indice<MAXTAM);
if (caracteres [indice-1]==' ')
	num_elementos=indice-1;
else
	num_elementos=indice;
frecuente (caracteres, num_elementos);
}


/*********************************************/


void frecuente (char caracteres [], int num_elementos)
{
static int contador [MAXTAM];
int indi, cuenta, maximo;
for (indi=0; indi<num_elementos; indi++)
	{
	for (cuenta=0; cuenta+indi<num_elementos; cuenta++)
		{
		if (caracteres [indi]==caracteres [indi+cuenta])
			contador [indi]++;
		}
	}

for (indi=0, maximo=0; indi<num_elementos; indi++)
	{
	if (contador [indi]>maximo)
		maximo=contador [indi];
	}

printf ("\nEL/LOS CARACTER/ES QUE MAS SE REPITE/N ES/SON:\n");
for (indi=0; indi<num_elementos; indi++)
	{
	if (contador [indi]==maximo)
		printf ("%c\n", caracteres [indi]);
	}
}








