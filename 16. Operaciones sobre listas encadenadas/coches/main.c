#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 30

/*****   definicion de las estructuras  ****/

struct informacion {
	char marca [MAXTAM];
	char modelo [MAXTAM];
	float precio;
};

struct nodo {
	struct informacion info;
	struct nodo *enlace;
};

/****  prototipo de las funciones  ****/

int opciones(void);
void ainade(struct nodo**);
void listar(struct nodo**);
struct nodo *nuevo_elemento(void);
struct nodo *compara(struct nodo*, struct nodo*);
void inserta(struct nodo*, struct nodo*, struct nodo**);

/****  definicion de las funciones  ****/

void main(void) {
  int opcion;
  struct nodo *cabeza;

  cabeza = (struct nodo *) NULL;
  
  do {  
  	opcion = opciones();
  	switch (opcion) {
  		case 1:
  			ainade(&cabeza);
  			break;
  		case 2:
  			listar(&cabeza);
  			break;
  	}
  }
  while (opcion != 0);
  
  printf ("\n\n\nFIN DEL PROGRAMA");
}

/**  FUNCION AINADE  **/

void ainade(struct nodo **cabeza) {
  struct nodo *nuevo, *anterior;
  
  nuevo = nuevo_elemento();  
  anterior = compara(nuevo, *cabeza);
  inserta(nuevo, anterior, cabeza);
}

/** FUNCION NUEVO_ELEMENTO **/

struct nodo *nuevo_elemento(void) {
  char tmp;
  struct nodo *nuevo;
  
  nuevo = (struct nodo *) malloc(sizeof(struct nodo));
  
  printf("\nMARCA --->");
  scanf("%s", nuevo->info.marca);
  scanf("%c", &tmp);
  printf("\nMODELO --->");
  scanf("%s", nuevo->info.modelo);
  scanf("%c", &tmp);
  printf("\nPRECIO --->"); 
  scanf("%f", &(nuevo->info.precio));
  scanf("%c", &tmp);

  return(nuevo);
}

/**  FUNCION COMPARA **/

struct nodo *compara(struct nodo *nuevo, struct nodo *cabeza) {
  struct nodo *anterior, *recorre;
  
  if (cabeza == (struct nodo *) NULL) {
    anterior = cabeza;
  } else {
  	if (cabeza->info.precio < nuevo->info.precio) {
  		anterior = cabeza;
  	} else {
  		recorre = cabeza;
  		
      while (recorre != (struct nodo *)NULL 
          && (recorre->info.precio > nuevo->info.precio)) {
        anterior = recorre;
  			recorre = recorre->enlace;
      }
  		
      if (recorre != (struct nodo *)NULL) {
  			anterior = recorre;        
  		}
    }
  }
  
  return (anterior);
}

/**  FUNCION INSERTA  **/

void inserta(struct nodo *nuevo, struct nodo *anterior, struct nodo **cabeza) {
  if (anterior == *cabeza) {
  	nuevo->enlace = *cabeza;
  	*cabeza = nuevo;
	} else {
  	nuevo->enlace = anterior->enlace;
  	anterior->enlace = nuevo;
	}
}

/** FUNCION LISTAR  **/

void listar (struct nodo **cabeza) {
  struct nodo *recorre;
  char siguiente, tmp;
  
  if (*cabeza == (struct nodo *)NULL) {
  	printf ("\nLISTA VACIA");
  } else {
  	recorre = *cabeza;
  	while (recorre != (struct nodo *)NULL) {
  		printf ("\n\n\n");
  		printf ("MARCA --->");
  		puts (recorre->info.marca);
  		printf ("\nMODELO --->");
  		puts (recorre->info.modelo);
  		printf ("\nPRECIO ---> %.0f",recorre->info.precio);
  
      recorre = recorre->enlace;
  		printf ("\nPULSE UNA TECLA PARA CONTINUAR");
  		siguiente = getchar();
  		scanf("%c",&tmp);
  		}
  	}
  
  printf ("\nFIN DE LA LISTA.PULSE UNA TECLA.");
  siguiente = getchar();
}

/** FUNCION OPCIONES **/

int opciones (void) {
  int opcion;
  printf ("\nELIJA UNA OPCION:");
  printf ("\n1.-Añadir un nuevo coche.");
  printf ("\n2.-Listar toda la informacion.");
  printf ("\n0.-Salir.\n");
  
  scanf ("%d",&opcion);
  return (opcion);
}