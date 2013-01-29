#include <stdio.h>

void main(void) {
  char caracter;
  
  printf("Introduzca un caracter: ");
  caracter = getchar();
  printf("Has introducido: ");
  putchar(caracter);
}