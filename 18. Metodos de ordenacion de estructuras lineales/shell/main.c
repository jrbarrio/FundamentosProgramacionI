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
  int indice, auxiliar, salto, ordenado;
  
  salto = TAMANIO - 1;
  while (salto != 1) {
    salto = salto / 2;
    do {
      ordenado = 1;
      for (indice = 0; indice < TAMANIO - salto; indice++) {
        if (elemento[indice] > elemento[indice + salto]) {
          auxiliar = elemento[indice];
          elemento[indice] = elemento[indice + salto];
          elemento[indice + salto] = auxiliar;
          ordenado = 0;
        }
      }
      
      imprimir(elemento);
    } while (!ordenado);    
  }
}