#include <stdio.h>
#define SECRETO 25

void main(void) {
  int numero;
  
  printf("Introduzca un numero ---> ");
  scanf("%d", &numero);
  
  if (numero > SECRETO) {
    printf("El numero %d es mayor que el numero secreto", numero);
  }
  if (numero < SECRETO) {
    printf("El numero %d es menor que el numero secreto", numero);
  }
  if (numero == SECRETO) {
    printf("El numero %d es igual que el numero secreto", numero);
  }  
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                  