#include <stdio.h>

#define TAMANIO 20

void imprimir(int* elemento);
void ordenar(int* elemento);

void main (void) {
  int elemento[] = {16, 20, 9, 7, 10, 6, 11, 2, 12, 8, 14, 1, 15, 5, 17, 3, 18, 13, 19, 4};

  imprimir(elemento);
  ordenar(elemento);
}

void imprimir(int* elemento) {
  int i;
  for (i = 0; i < TAMANIO; i++) {
    printf("%3d", elemento[i]);
  }
  printf("\n");
}

void ordenar(int* elemento) {
  int auxiliar, banderin, izquierdo, derecho, medio;
  
  banderin = 1;
  izquierdo = 0;
  derecho = TAMANIO - 1;
  medio = izquierdo;
  
  while (izquierdo < derecho) {
    if (banderin) {
      while (elemento[medio] <= elemento[derecho]
        && medio < derecho) {
        derecho = derecho - 1;
      }
      
      if (medio < derecho) {
        auxiliar = elemento[medio];
        elemento[medio] = elemento[derecho];
        elemento[derecho] = auxiliar;
        medio = derecho;
      }
      banderin = 0;
    } else {
      while (elemento[izquierdo] <= elemento[medio]
        && izquierdo < medio) {
        izquierdo = izquierdo + 1;
      }
      
      if (izquierdo < medio) {
        auxiliar = elemento[medio];
        elemento[medio] = elemento[izquierdo];
        elemento[izquierdo] = auxiliar;
        medio = izquierdo;
      }
      banderin = 1;
    }
    
    imprimir(elemento); 
  }
}