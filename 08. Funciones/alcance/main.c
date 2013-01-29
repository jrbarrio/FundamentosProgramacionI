#include <stdio.h>

void mostrar();
void incrementar_valor();
void doblar_valor();

int valor;

void main(void) {
  int i;
  extern int valor;
  valor = 1;
  mostrar();
  
  for (i = 0; i < 10; i++) {
    incrementar_valor();
    doblar_valor();
  }
}

void mostrar() {
  extern int valor;
  printf("Mostrar valor: %d", valor);
}

static int numero = 0;

void incrementar_valor() {
  extern int numero;
  printf("\nEl numero es: %d", ++numero);
}

void doblar_valor() {
  extern int numero;
  numero *= 2;
  printf("\nEl numero es: %d", numero);
}
                                                                                                                                                                                                                                                                                                                                      