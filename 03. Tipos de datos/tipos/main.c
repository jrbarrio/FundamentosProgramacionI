#include <stdio.h>

void main(void) {
  char caracter;
  short entero_corto;
  int entero;
  long entero_largo;
  float flotante;
  double doble;
  
  printf("Un char ocupa %d bytes.\n", sizeof(caracter));
  printf("Un short ocupa %d bytes.\n", sizeof(entero_corto));
  printf("Un int ocupa %d bytes.\n", sizeof(entero));
  printf("Un long ocupa %d bytes.\n", sizeof(entero_largo));
  printf("Un float ocupa %d bytes.\n", sizeof(flotante));
  printf("Un double ocupa %d bytes.\n", sizeof(doble));
}
