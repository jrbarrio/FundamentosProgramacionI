#include <stdio.h>
#include <math.h>

double logaritmo(float numero, int base);

void main(void) {
  float numero;
  int base;
  
  printf("Introduzca el numero: ");
  scanf("%f", &numero);
  printf("Introduzca la base: ");
  scanf("%d", &base);
  
  printf("El logaritmo es %f", logaritmo(numero, base));
}                                                      

double logaritmo(float numero, int base){
  double logaritmo;
  logaritmo  = log(numero)/log(base);
  return logaritmo;
}                                                                                                                                                                                                                                                                                                                                                                                                            