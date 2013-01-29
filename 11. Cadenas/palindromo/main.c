#include <stdio.h>
#include <string.h>
#define MAXTAM 100

void introduce(char []);
void mayusculas(char []);
void elimina(char []);
void comprueba(char []);

void main (void) {
  char cadena [MAXTAM];
  
  introduce(cadena);
  puts(cadena);
  mayusculas(cadena);
  puts(cadena);
  puts(cadena);
  comprueba(cadena);
}

void introduce(char cadena[]) {
  int indice = 0;
  char caracter;
  printf("INTRODUZCA LA CADENA\n");
  
  do {
  	caracter = getchar();
  	if (caracter != '\n') {
      cadena[indice++] = caracter;
    }
  } while (caracter != '\n' && indice < MAXTAM - 2);
  cadena[indice] = '\0';
}

void mayusculas(char cadena[]) {
  int indice, num_elem;
  
  num_elem = strlen(cadena);
  for (indice = 0; indice < num_elem; indice ++)  {
	 if (cadena[indice] >= 97 && cadena[indice] <= 122) {
    cadena[indice] = cadena[indice] - 32;
   }
	}
}

void comprueba(char cadena []) {
  int indice_1, indice_2, comprueba = 1;
  indice_2 = strlen(cadena) - 1;
  
  for (indice_1 = 0; indice_1 <= indice_2; indice_1++, indice_2--) {
    if (cadena[indice_1] != cadena[indice_2]) {
  		comprueba = 0;
  	}
  }
  
  if (comprueba) {
    printf("\n\nES UN PALINDROMO");
  } else {
    printf("\n\nNO ES UN PALINDROMO");
  }
}