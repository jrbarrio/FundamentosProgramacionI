#include <stdio.h>

void main(void) {
  int numero;
  
  printf("Introduzca un numero entero ---> ");
  scanf("%d", &numero);
  
  if((numero < 0) || (numero > 10)) {
    printf("El numero %d esta fuera del rango", numero);
  } else {
    printf("El numero %d es valido", numero);
  }  
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                  