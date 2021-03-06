#include <stdio.h>
#define MAXTAM 10

void lee_array(int numeros[], int *num_elementos);
void visualiza_array(int numeros[], int num_elementos);

void main(void) {
  int numeros[MAXTAM];
  int num_elementos;
  
  lee_array(numeros, &num_elementos);
  visualiza_array(numeros, num_elementos);
}
       
void lee_array(int numeros[], int *num_elementos) {
  int indice = 0;
  do {
    scanf("%d", &numeros[indice]);
  } while ((numeros[indice++] > 0) && indice < MAXTAM);
  
  if (numeros[indice -1] == 0) {
    *num_elementos = indice -1;
  } else {
    *num_elementos = indice;
  }
}

void visualiza_array(int numeros[], int num_elementos) {
  int indice;
  for (indice = 0; indice < num_elementos; indice++) {
    printf("%8d", numeros[indice]);
  }
}                                                                                                                                                                                                                                                                                                                               