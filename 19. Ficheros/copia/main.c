#include <stdio.h>

typedef FILE* FICHERO;

void main (void) {
  char nomfich_1[] = "texto_1.dat"; 
  char nomfich_2[] = "texto_2.dat";
  
  FICHERO punt_fich_1, punt_fich_2;
  char caracter;
  
  if ((punt_fich_1 = fopen(nomfich_1, "r")) != NULL
      && (punt_fich_2 = fopen(nomfich_2, "w")) != NULL) {
    while ((caracter = getc(punt_fich_1)) != EOF) {
      printf("%c", caracter);
      putc(caracter, punt_fich_2);
    }
    
    fclose(punt_fich_1);
    fclose(punt_fich_2);
  }  
}

