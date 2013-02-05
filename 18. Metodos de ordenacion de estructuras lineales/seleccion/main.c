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
  int contador, conta, indice;
  int auxiliar;
  
  for (contador = 0; contador < TAMANIO - 1; contador++) {
    auxiliar = elemento[contador];
    indice = contador;
    
    for (conta = contador + 1; conta < TAMANIO; conta++) {
      if (elemento[conta] < auxiliar) {
        auxiliar = elemento[conta];
        indice = conta;
      }
    }
      
    auxiliar = elemento[indice];
    elemento[indice] = elemento[contador];
    elemento[contador] = auxiliar;
    
    imprimir(elemento);
  }
}
