/******    includes del programa   *****/

#include <stdio.h>
#include <stdlib.h>

/******    definicion de los tipos estructura  *****/

struct nodo	{
	int numero;
	struct nodo *enlace;
};

/*********************  prototipo de las funciones  *********************/

struct nodo* crea_lista(void);
struct nodo* pide_datos(void);
struct nodo* inserta(struct nodo*, struct nodo*);
void visualiza(struct nodo*);

/********  funcion principal  *******/

void main (void)
{
  struct nodo *cabeza, *recorre, *pares, *impares;
  
  pares = (struct nodo*) NULL;
  impares = (struct nodo*) NULL;
  
  cabeza = crea_lista();
  
  do {
  	recorre = cabeza;
  	if ((cabeza->numero) % 2 != 0) {
      cabeza = cabeza->enlace;
  		impares = inserta(impares, recorre);
  		recorre->enlace = (struct nodo*) NULL;
  	} else {
  		cabeza = cabeza->enlace;
  		pares = inserta(pares, recorre);
      recorre->enlace = (struct nodo*) NULL;
  	}
  } while (cabeza != (struct nodo*) NULL);
  
  printf("\n\n");
  
  printf("\nElementos impares:\n");
  visualiza(impares);
  printf("\nElementos pares:\n");
  visualiza(pares);
}

/******  funcion crea_lista  *****/

struct nodo *crea_lista(void) {
  struct nodo *cabeza, *nuevo;
  char respuesta, basura;
    
  cabeza = (struct nodo*) NULL;
  do {
  	nuevo = pide_datos();
  	cabeza = inserta(cabeza, nuevo);
  	printf ("¿MAS ELEMENTOS?(S/N)");
  	scanf("%c", &basura);
    respuesta = getchar();
  	scanf("%c", &basura);
  } while (respuesta == 's' || respuesta == 'S');
  return (cabeza);
}

/******  funcion pide_datos  *******/

struct nodo* pide_datos (void) {
  struct nodo* nuevo;
  nuevo = (struct nodo*) malloc(sizeof(struct nodo));
  printf("\nNUMERO --->");
  scanf("%d", &nuevo->numero);
  nuevo->enlace = (struct nodo*) NULL;
  return(nuevo);
}

/*****  funcion inserta  *****/

struct nodo* inserta(struct nodo* cabeza, struct nodo* nuevo) {
  struct nodo* recorre;
  if (cabeza == (struct nodo*) NULL) {
    cabeza=nuevo;
  } else {
  	recorre = cabeza;
  	while (recorre->enlace != (struct nodo*) NULL) {
      recorre = recorre->enlace;
    }
  	recorre->enlace = nuevo;
  }
  return(cabeza);     
}

/******  funcion visualiza  *****/

void visualiza(struct nodo* cabeza) {
  struct nodo *recorre;
  char respuesta;
  
  if (cabeza == (struct nodo*) NULL) {
    printf ("LISTA VACIA");
  } else {
  	recorre = cabeza;
  	while (recorre != (struct nodo*) NULL) {
  		printf ("   %d  ",recorre->numero);
  		recorre = recorre->enlace;
  	}
  }
  
  printf("\n\nPULSE UNA TECLA PARA CONTINUAR\n\n");
  respuesta = getchar();
}