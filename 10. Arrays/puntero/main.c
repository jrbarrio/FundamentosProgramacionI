#include <stdio.h>
#define MAXTAM 10

void main(void) {
  int numeros[MAXTAM];
  int num_elementos;
  int indice = 0;
  int *punt_num;
  punt_num = numeros;
  
  do {
    indice++;
    scanf("%d", punt_num);
  } while ((*(punt_num++) > 0) && (indice < MAXTAM));
  
  if (*(punt_num - 1) == 0) {
    num_elementos = indice - 1;
  } else {
    num_elementos = indice;
  }
  
  printf("Numero de elementos: %d", num_elementos);
}
                                                                                                                                                                                                                                                                                                                                      