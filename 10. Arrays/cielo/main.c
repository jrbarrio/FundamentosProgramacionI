#include <stdio.h>
#define FILA 20
#define COLU 20


void introduce_array (int [] [COLU],int *, int *);
float estrella (int [] [COLU], int, int);


/*************  funcion main  ************************/


void main (void)
{
int cielo [FILA] [COLU];
char plano [FILA] [COLU];
int filas, columnas;
int indice1, indice2;

introduce_array (cielo, &filas, &columnas);

for (indice1=0; indice1<filas; indice1++)
	for (indice2=0; indice2<columnas; indice2++)
		{
		if (indice1==0 || indice1==filas-1 || indice2==0 || indice2==columnas-1)
			plano [indice1] [indice2]=' ';
		if (indice1!=0 && indice1!=filas-1 && indice2!=0 && indice2!=columnas-1)
			{
			if (estrella (cielo , indice1, indice2)/9>6.0)
				plano [indice1] [indice2]='*';
			else
				plano [indice1] [indice2]='.';
			}
		}
for (indice1=0; indice1<filas; indice1++)
	{
	printf ("\n");
	for (indice2=0; indice2<columnas; indice2++)
		printf ("  %c",plano [indice1] [indice2]);
	}

}

/**************  funcion  introduce_array  **********************/

void introduce_array (int cielo [] [COLU],int *filas, int *columnas)
{
int indice1, indice2;
do
	{
	printf ("INTRODUZCA EL NUMERO DE COLUMNAS --->");
	scanf ("%d",columnas);
	}
while (*columnas>COLU);
do
	{
	printf ("INTRODUZCA EL NUMERO DE FILAS --->");
	scanf ("%d",filas);
	}
while (*filas>FILA);

printf ("\nINTRODUZCA LOS ELEMENTOS DEL ARRAY\n");

for (indice1=0; indice1<*filas; indice1++)
	for (indice2=0; indice2<*columnas; indice2++)
		{
		scanf ("%d",&cielo [indice1] [indice2]);
		if (cielo [indice1] [indice2]<0 || cielo [indice1] [indice2]>20)
			{
			printf ("VALOR NO VALIDO. INTRODUZCA OTRO");
			indice2--;
			}
		}
}

/*****************   funcion estrella   ****************************************/


float estrella (int cielo [] [COLU],int indice1,int indice2)
{
float suma;
 suma= cielo [indice1+1] [indice2] + cielo [indice1-1] [indice2] + cielo [indice1] [indice2] +
	cielo [indice1+1] [indice2+1] + cielo [indice1-1] [indice2+1] + cielo [indice1] [indice2+1] +
	cielo [indice1+1] [indice2-1] + cielo [indice1-1] [indice2-1] + cielo [indice1] [indice2-1];
return (suma);
}









