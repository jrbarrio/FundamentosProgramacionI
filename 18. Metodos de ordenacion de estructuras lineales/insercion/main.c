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
  int contador, indice;
  int auxiliar;
  
  for (contador = 1; contador < TAMANIO; contador++) {
    auxiliar = elemento[contador];
    indice = contador - 1;
    
    while (auxiliar < elemento[indice] && indice >= 0) {
      elemento[indice + 1] = elemento[indice];
      indice--;
    }
    
    elemento[indice + 1] = auxiliar;
    
    imprimir(elemento);
  }
}
