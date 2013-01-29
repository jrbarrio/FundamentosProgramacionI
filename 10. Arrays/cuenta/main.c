#include <stdio.h>
#define MAXTAM 9

int suma (int []);
int resta (int []);
int multi (int []);

/*******************************************************/

void main (void)
{
int indice;
int cuenta [MAXTAM];
for (indice=0; indice<MAXTAM; indice++)
	scanf ("%d", &cuenta [indice]);
for (indice=0; indice<MAXTAM; indice++)
	printf ("%d", cuenta [indice]);


if (cuenta [0]==1)
	{
	if (cuenta [MAXTAM-1]==suma (cuenta ))
		printf ("\nLA CUENTA ES VALIDA");
	else
		{
		if (cuenta [MAXTAM-1]==resta (cuenta ) || cuenta [MAXTAM-1]== multi (cuenta ))
			printf ("\nEL CODIGO DE OPERACION ES INCORRECTO");
		else
			printf ("\nLA CUENTA NO ES VALIDA");
		}
	}


if (cuenta [0]==2)
	{
	if (cuenta [MAXTAM-1]==resta (cuenta ))
		printf ("\nLA CUENTA ES VALIDA");
	else
		{
		if (cuenta [MAXTAM-1]==suma (cuenta ) || cuenta [MAXTAM-1]== multi (cuenta ))
			printf ("\nEL CODIGO DE OPERACION ES INCORRECTO");
		else
			printf ("\nLA CUENTA NO ES VALIDA");
		}
	}

if (cuenta [0]==3)
	{
	if (cuenta [MAXTAM-1]==multi (cuenta ))
		printf ("\nLA CUENTA ES VALIDA");
	else
		{
		if (cuenta [MAXTAM-1]==resta (cuenta ) || cuenta [MAXTAM-1]== suma (cuenta ))
			printf ("\nEL CODIGO DE OPERACION ES INCORRECTO");
		else
			printf ("\nLA CUENTA NO ES VALIDA");
		}
	}

}

/***********************************************************************/

int suma (int cuenta [])
{
int indi, suma;
for (indi=0, suma=0; indi+1<MAXTAM; indi++)
	suma = suma + cuenta [indi];
printf ("\n%d      LA SUMA ES %d", cuenta [0], suma);
for (;suma>10;)
	suma=suma-10;
return (suma);
}

/**********************************************************************/

int resta (int cuenta [])
{
int indi, resta;
for (indi=1, resta =cuenta [0]; indi+1<MAXTAM; indi++)
	resta = resta - cuenta [indi];
printf ("\n%d      LA RESTA ES %d", cuenta [0], resta);
resta = -resta;
for (;resta>10;)
	resta=resta-10;
return (resta);
}

/***********************************************************************/

int multi (int cuenta [])
{
int multi, indi;
for (indi=0, multi =1 ; indi+1<MAXTAM; indi++)
	multi = multi *  cuenta [indi];
printf ("\n%d      LA MULTIPLICACION ES %d", cuenta [0], multi);
for (;multi>10;)
	multi=multi-10;
return (multi);
}
