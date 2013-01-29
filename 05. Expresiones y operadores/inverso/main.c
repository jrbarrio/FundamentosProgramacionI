#include <stdio.h>

void main (void) {
  int num1,num2,num3;
  int numero;
  
  printf ("Introduzca un numero de 3 cifras:");
  scanf ("%d",&numero);
  
  num3=numero/100;
  num2=numero/10 - num3*10;
  num1=numero - 100*num3 - 10*num2;
  
  printf("Sus digitos en orden inverso forman el numero %d%d%d", num1, num2, num3);
}
