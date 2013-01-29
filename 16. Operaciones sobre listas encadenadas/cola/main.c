#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct informacion {
	char nombre[20];
	int edad;
};

struct nodo {
	struct informacion info;
	struct nodo *enlace;
};

/*********************************************************************/

struct nodo *insercion(void);
struct nodo *pide_datos(void);
struct nodo *inserta(struct nodo *cabeza,struct nodo *nuevo);
 
/*********************************************************************/

void main(void) {
  struct nodo *cabeza, *recorre;
  
  cabeza = insercion();
  
  if (cabeza == (struct nodo*) NULL) {
  	printf("LISTA VACIA");
  } else {
  	recorre = cabeza;
  	printf("\n\nElementos introducidos:\n"); 
  	while (recorre != (struct nodo*) NULL) { 
  	 puts(recorre->info.nombre);
  	 recorre = recorre->enlace;
  	}
  }
}

/**********************************************************************/

struct nodo *insercion (void)
{
  struct nodo *cabeza, *nuevo;
  char respuesta, basura;
  
  cabeza = (struct nodo *) NULL;
  do {
  	nuevo = pide_datos();
  	cabeza = inserta(cabeza, nuevo);
    printf("¿MAS ELEMENTOS?(S/N)");
  	respuesta = getchar();
  	scanf("%c", &basura);
  }
  while (respuesta == 's' || respuesta == 'S');
  return(cabeza);
}

/**********************************************************************/

struct nodo *pide_datos (void) {
  struct nodo *nuevo;
  char basura;
  
  nuevo = (struct nodo*) malloc(sizeof(struct nodo));
  printf("\nNOMBRE --->");
  gets(nuevo ->info.nombre);
  printf("EDAD --->");
  scanf("%d", &nuevo->info.edad);
  nuevo->enlace = (struct nodo*) NULL;
  scanf("%c", &basura);
  
  return (nuevo);
}

/********************************************************************/

struct nodo *inserta (struct nodo *cabeza, struct nodo *nuevo) {
  struct nodo *recorre;
  
  if (cabeza == (struct nodo*) NULL) {
  	cabeza = nuevo;
  } else {
  	recorre = cabeza;
  	while (recorre->enlace != (struct nodo*) NULL) {
      recorre=recorre->enlace;
    }
  	recorre->enlace = nuevo;
  }
  
  return (cabeza);
}