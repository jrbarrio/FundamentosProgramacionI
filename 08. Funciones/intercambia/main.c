#include <stdio.h>

void pide_datos(int *dato_1, int *dato_2);
void visualiza(int dato_1, int dato_2);
void intercambia_datos(int *dato_1, int *dato_2);
void intercambia(int *dato_1, int *dato_2);

void main(void) {
  int dato_1, dato_2;
  
  pide_datos(&dato_1, &dato_2);
  visualiza(dato_1, dato_2);
  intercambia(&dato_1, &dato_2);
  visualiza(dato_1, dato_2);
}

void pide_datos(int *dato_1, int *dato_2) {
  printf("Introduce dato 1: ");
  scanf("%d", dato_1);
  printf("Introduce dato 2: ");
  scanf("%d", dato_2);
}
void visualiza(int dato_1, int dato_2) {
  printf("\ndato 1: %d\ndato 2: %d\n", dato_1, dato_2);
}

void intercambia_datos(int *dato_1, int *dato_2) {
  intercambia(dato_1, dato_2);
  visualiza(*dato_1, *dato_2);
}

void intercambia(int *dato_1, int *dato_2) {
  int temporal;
  temporal = *dato_1;
  *dato_1 = *dato_2;
  *dato_2 = temporal;  
}                                                                                                                                                                                                                                                                                                                                             