#include <stdio.h>
#define PI 3.1416

void main(void) {
  int opcion;
  float lado, radio, base, altura;
  
  printf("1 - Cuadrado\n");
  printf("2 - Circulo\n");
  printf("3 - Triangulo\n");
  printf("Seleccione un opcion: ");
  scanf("%d", &opcion);
  
  switch (opcion) {
    case 1:
      printf("Lado del cuadrado: ");
      scanf("%f", &lado);
      printf("El area del cuadrado es %.2f", (lado * lado));
      break;
    case 2:
      printf("Radio de la circunferencia: ");
      scanf("%f", &radio);
      printf("El area de la circunferencia es %.2f", (PI * radio * radio));
      break;
    case 3:
      printf("Base del triangulo: ");
      scanf("%f", &base);
      printf("Altura del triangulo: ");
      scanf("%f", &altura);
      printf("El area del triangulo es %.2f", ((base * altura) / 2));
      break;
    default:
      printf("Opcion no valida");
      break;
  }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                  