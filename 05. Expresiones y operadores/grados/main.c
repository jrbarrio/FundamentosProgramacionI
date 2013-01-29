# include <stdio.h>

void main (void) {
  float numero1, numero2;
  
  printf("Grados Celsius=");
  scanf("%f",&numero1);
  numero2 = (1.8 * numero1) + 32;
  printf ("%.2f grados Celsius = %.2f grados Farenheit\n", numero1, numero2);
}
