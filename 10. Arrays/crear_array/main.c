#include <stdio.h>
#define MAXTAM 10

int *crea_array(void);
void visualiza_array(int numeros[]);

void main(void) {
  int *puntero;
  puntero = crea_array();
  visualiza_array(puntero);
}
       
int *crea_array(void) {
  static int array[MAXTAM];
  int indice = 0;
  do {
    scanf("%d", &array[indice++]);
  } while (indice < MAXTAM);
  return array;
}

void visualiza_array(int numeros[]) {
  int indice;
  for (indice = 0; indice < MAXTAM; indice++) {
    printf("%6d", *(numeros + indice));
  }                
}                                                                                                                                                                                                                                                                                                                               