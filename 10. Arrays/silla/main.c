#include <stdio.h>
#define FILA 3
#define COLU 3

void introduce_array (int [] [COLU]);
int minimofil (int [] [COLU], int);
int minimocol (int [] [COLU], int);
int maximofil (int [] [COLU], int);
int maximocol (int [] [COLU], int);



/**************  funcion main   *************************/

void main (void)
{
int filas, columnas;
int array [FILA] [COLU];
introduce_array (array);
printf ("\n\n\n");


  
for (filas=0; filas<FILA; filas++)
	for (columnas=0; columnas<COLU; columnas++)
                {
		if (array [filas] [columnas]==maximocol (array, filas) &&
			array [filas] [columnas]==minimofil (array,columnas))
			printf ("\nFILA %d  COLUMNA %d  ES PUNTO DE SILLA",filas,columnas);
		if (array [filas] [columnas]==maximofil (array, columnas) &&
			array [filas] [columnas]==minimocol (array,filas))
			printf ("\nFILA %d  COLUMNA %d  ES PUNTO DE SILLA",filas,columnas);
                }
}


/*************  funcion introduce_array  ********************/

void introduce_array (int array [] [COLU])

{
int filas, columnas;

for (filas=0;filas<FILA;filas++)
	{
	for (columnas=0;columnas<COLU;columnas++)
		scanf ("%d",*(array+filas)+columnas);
        }


for (filas=0;filas<FILA;filas++)
	{
        printf ("\n");
	for (columnas=0;columnas<COLU;columnas++)
		printf ("%4d",*(*(array+filas)+columnas));
        }
}


/************  funcion minimofil  *************************/


int minimofil (int array [] [COLU], int columnas)
{
int filas=0;
int minimo=array [filas] [columnas];

for (; filas<FILA; filas++)
	{
	if (minimo>array [filas] [columnas])
		minimo=array [filas] [columnas];
	}
return (minimo);
}

/*************  funcion minimocol  ***************************/


int minimocol (int array [] [COLU], int filas)
{
int columnas=0;
int minimo=array [filas] [columnas];

for (; columnas<FILA; columnas++)
	{
	if (minimo>array [filas] [columnas])
		minimo=array [filas] [columnas];
	}
return (minimo);
}


/***************   funcion  maximofil  ****************************/

int maximofil (int array [] [COLU], int columnas)
{
int filas=0;
int maximo;

for (maximo=0; filas<FILA; filas++)
	{
	if (maximo<array [filas] [columnas])
		maximo=array [filas] [columnas];
	}
return (maximo);
}

/**************  funcion maximocol  ********************************/


int maximocol (int array [] [COLU], int filas)
{
int columnas=0;
int maximo;

for (maximo=0; columnas<COLU; columnas++)
	{        
	if (maximo<array [filas] [columnas])
		maximo=array [filas] [columnas];
	}
return (maximo);
}
