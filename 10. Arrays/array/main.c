#include <stdio.h>
#define MAXTAM 10

void main(void) {
  int numeros[MAXTAM];
  int num_elementos;
  int indice = 0;
  
  do {
    scanf("%d", numeros + indice);
  } while ((*(numeros + indice++) > 0) && (indice < MAXTAM));
  
  if (*(numeros + indice - 1) == 0) {
    num_elementos = indice - 1;
  } else {
    num_elementos = indice;
  }
  
  printf("Numero de elementos: %d", num_elementos);
}
                                                                                                                                                                                                                                                                                                                                      