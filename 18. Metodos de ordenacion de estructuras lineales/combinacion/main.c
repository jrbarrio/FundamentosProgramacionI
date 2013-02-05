#include <stdio.h>

#define TAMANIO 20

void imprimir(int* elemento);
void ordenar(int* elemento, int principio, int final);
int quicksort(int* elemento, int principio, int final);
void burbuja(int* elemento, int principio, int final);

void main (void) {
  int elemento[] = {16, 20, 9, 7, 10, 6, 11, 2, 12, 8, 14, 1, 15, 5, 17, 3, 18, 13, 19, 4};
  imprimir(elemento);
  ordenar(elemento, 0, TAMANIO - 1);
}

void imprimir(int* elemento) {
  int i;
  for (i = 0; i < TAMANIO; i++) {
    printf("%3d", elemento[i]);
  }
  printf("\n");
}

void ordenar(int* elemento, int principio, int final) {
  int mitad;
  
  imprimir(elemento);
  
  if ((final - principio) < 5) {
    printf("%2d burbuja\n", (final - principio));
    
    burbuja(elemento, principio, final);
  } else {
    printf("%2d quicksort\n", (final - principio));
  
    mitad = quicksort(elemento, principio, final); 
    
    ordenar(elemento, principio, mitad - 1);
    ordenar(elemento, mitad + 1, final);
  }
}

int quicksort(int* elemento, int principio, int final) {
  int auxiliar, banderin, medio; 
    
  banderin = 1;
  medio = principio;
  
  while (principio < final) {
    if (banderin) {
      while (elemento[medio] <= elemento[final]
        && medio < final) {
        final = final - 1;
      }
      
      if (medio < final) {
        auxiliar = elemento[medio];
        elemento[medio] = elemento[final];
        elemento[final] = auxiliar;
        medio = final;
      }
      banderin = 0;
    } else {
      while (elemento[principio] <= elemento[medio]
        && principio < medio) {
        principio = principio + 1;
      }
      
      if (principio < medio) {
        auxiliar = elemento[medio];
        elemento[medio] = elemento[principio];
        elemento[principio] = auxiliar;
        medio = principio;
      }
      banderin = 1;
    }
  }  
  
  return medio;     
}

void burbuja(int* elemento, int principio, int final) {
  int contador, indice;
  int auxiliar;
  int sinCambio;
  
  for (contador = principio; contador < final; contador++) {
    sinCambio = 1;
    
    for (indice = principio; indice < final - contador; indice++) {
      if (elemento[indice] > elemento[indice + 1]) {
        auxiliar = elemento[indice];
        elemento[indice] = elemento[indice + 1];
        elemento[indice + 1] = auxiliar;
      
        sinCambio = 0;
      }
    }
    
    if (sinCambio) {
      break;
    }
  }
}