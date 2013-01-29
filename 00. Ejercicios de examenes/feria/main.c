#include <stdio.h>
#include <string.h>
#define MAXTAM 100

/***************   definicion de las estructuras *****************/

struct stand
	{
	char nombre [30];
	int numero;
	int dias;
	int metros_stand;
	int precio;
	};


struct pabellon
	{
	int tarifa;
	int metros_pabellon;
	int metros_alquilados;
	};


/***********   prototipo de las funciones   ********************/

void opciones (int *);
void modifica_tarifa (struct pabellon []);
void visualiza (struct stand [], int , struct pabellon []);
void add_stand (struct stand [], int *, struct pabellon []);
void elimina (struct stand [], int *, struct pabellon []);



/**************    funcion main  *****************/

void main (void)
{
static struct stand stands [MAXTAM];
struct pabellon pabellones [5];
int indice, opcion, elementos=0;

for (indice=0; indice<5; indice++)
	{
	printf ("TARIFA DEL PABELLON (EN PTAS/M2) --->");
	scanf ("%d", &pabellones [indice].tarifa);
	printf ("METROS CUADRADOS DEL PABELLON --->");
	scanf ("%d", &pabellones [indice].metros_pabellon);
	printf ("METROS ALQUILADOS --->");
	scanf ("%d", &pabellones [indice].metros_alquilados);
	} 

do
	{
	opciones (&opcion);
	switch (opcion)
		{
		case 1:
			add_stand (stands, &elementos, pabellones);
			break;       	
		case 2:
			elimina (stands, &elementos, pabellones);
                        break;
		case 3:
			modifica_tarifa (pabellones);
                        break;
		case 4:
			visualiza (stands, elementos, pabellones);
                        break;
		}
	}
while (opcion!=5);

printf ("FIN DEL PROGRAMA");
}



/************   funcion elimina   ****************/

void elimina (struct stand stands [], int *elementos, struct pabellon pabellones [])
{
int posicion, indice;
int principio=0;
int final=*elementos;
int mitad=(principio+final)/2;

char empresa [30];
printf ("\n\nINTRODUZCA EL NUMBRE DE LA EMPRESA --->");
fflush (stdin);
gets (empresa);

while (strcmp (stands [mitad].nombre, empresa)!=0 && principio<final)
	{
	if (strcmp (stands [mitad].nombre, empresa)>0)
		final=mitad-1;
	else
		principio=mitad+1;
        	mitad=(principio+final)/2;
	}

if ( strcmp (stands [mitad].nombre, empresa)==0)
        {
	posicion=mitad;
        pabellones [ stands [posicion].numero ].metros_alquilados -= stands [posicion].metros_stand;
	for (indice=posicion; posicion+1<=*elementos; indice++)
		{
		strcpy ( stands [indice].nombre, stands [indice+1].nombre);
		stands [indice].numero= stands [indice+1].numero;
		stands [indice].dias= stands [indice+1].dias;
		stands [indice].metros_stand= stands [indice+1].metros_stand;
		stands [indice].precio= stands [indice+1].precio;
		}

	*elementos-=1;

	}
else
	printf ("\n\nNO HAY NINGUNA EMPRESA CON ESTE NOMBRE.");

}

/*************   funcion add_stand   ******************/

void add_stand (struct stand stands [], int *elementos, struct pabellon pabellones [])
{
char caracter;
struct stand nuevo;
int posicion, indice;
int principio=0;
int final=*elementos;
int mitad=(principio+final)/2;

printf ("\nNUEVO STAND.\n\n\n");
printf ("NOMBRE --->");
fflush (stdin);
gets (nuevo.nombre);
printf("PABELLON NUMERO --->");
scanf ("%d", &nuevo.numero);
printf ("DIAS --->");
scanf ("%d", &nuevo.dias);
printf ("METROS DEL STAND --->");
scanf ("%d", &nuevo.metros_stand);

nuevo.precio= nuevo.metros_stand * pabellones [nuevo.numero-1].tarifa;

if ( pabellones [nuevo.numero-1].metros_pabellon>( pabellones [nuevo.numero-1].metros_alquilados + nuevo.metros_stand))
	{
	pabellones [nuevo.numero].metros_alquilados += nuevo.metros_stand;
	while (strcmp (stands [mitad].nombre, nuevo.nombre)!=0 && principio<final)
		{
		if (strcmp (stands [mitad].nombre, nuevo.nombre)>0)
			final=mitad-1;
		else
			principio=mitad+1;
                mitad=(principio+final)/2;
		}
	if ( strcmp (stands [mitad].nombre, nuevo.nombre)==0)
		posicion=mitad;
	else
		posicion=principio;


	for (indice=*elementos; indice>=posicion; indice--)
		{
		strcpy (stands [indice+1].nombre, stands [indice].nombre);
		stands [indice+1].numero=stands [indice].numero;
		stands [indice+1].dias=stands [indice].dias;
		stands [indice+1].metros_stand=stands [indice].metros_stand;
		stands [indice+1].precio=stands [indice].precio;
                }


	strcpy (stands [posicion].nombre,nuevo.nombre);
	stands [posicion].numero=nuevo.dias;
	stands [posicion].dias=nuevo.dias;
	stands [posicion].metros_stand=nuevo.metros_stand;
	stands [posicion].precio=nuevo.precio;

	*elementos+=1;
        }
else
	{
	printf ("\n\nNO HAY METROS DISPONIBLES EN ESTE PABELLON.");
	printf ("\n\nPULSE UNA TECLA PARA CONTINUAR");
	caracter=getchar ();
        }
}
	


/*************  funcion visualiza   *****************/

void visualiza (struct stand stands [], int elementos, struct pabellon pabellones [])
{
char caracter;
int indice;
if (elementos==0)
	printf ("\n\nNO HAY NINGUN STAND ALQUILADO.\n");
else
        {
	for (indice=0; indice<elementos; indice++)
		{
		printf ("\n\n\nSTAND NUMERO %d.\n\n\n",indice+1);
		printf ("EMPRESA - %s.\n", stands [indice].nombre);
		printf ("PABELLON NUMERO - %d.\n", stands [indice].numero);
		printf ("DIAS DE ALQUILER - %d.\n", stands [indice].dias);
		printf ("METROS DEL STAND - %d.\n", stands [indice].metros_stand);
                printf ("PRECIO - %d pts.\n\n\n", stands [indice].precio);
		printf ("\nPULSE UNA TECLA PARA CONTINUAR.");
		caracter=getchar ();
                }
	}

for (indice=0; indice<5; indice++)
	{
	printf ("\nPABELLON NUMERO %d.\n\n\n", indice+1);
	printf ("TARIFA - %d pts.\n", pabellones [indice].tarifa);
	printf ("METROS CUADRADOS DEL PABELLON - %d.\n", pabellones [indice].metros_pabellon);
	printf ("METROS ALQUILADOS DEL PABELLON - %d.\n\n\n", pabellones [indice].metros_alquilados);
	printf ("\nPULSE UNA TECLA PARA CONTINUAR.");
	caracter=getchar ();
        }
}
	

/*************   funcion opciones  *****************/

void opciones (int *opcion)
{
do
	{
	printf ("1.-Añadir un stand.\n");
	printf ("2.-Eliminar un stand.\n");
	printf ("3.-Modificar la tarifa de un pabellon.\n");
	printf ("4.-Visualizar la informacion de los stands y pabellones.\n");
	printf ("5.-Salir del programa.\n");
	printf ("\n\nELIJA UNA OPCION --->");
	scanf ("%d", opcion);
	}
while (*opcion<1 || *opcion>5);
}


/******************  funcion modifica_tarifa  *****************/

void modifica_tarifa (struct pabellon pabellones [])
{
int indice;
printf ("\nNUMERO DEL PABELLON");
scanf ("%d", &indice);
printf ("\nNUEVA TARIFA --->");
scanf ("%d", &pabellones [indice].tarifa);
}















































































































































































