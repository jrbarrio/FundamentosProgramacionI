#include <string.h>
#include <stdio.h>
#define MAXTAM 100

void introduce(char []);
void inic(char []);
void fin(char []);
void inter(char []);
int contar(char []);

void main(void) {
  char cadena[MAXTAM];
  
  introduce(cadena);
  inic(cadena);
  fin(cadena);
  inter(cadena);
  puts(cadena);
  
  printf("\nLA CADENA TIENE %d PALABRAS", contar(cadena));
}

void introduce (char cadena[]) {
  int indice = 0;
  char caracter;
  printf("INTRODUZCA LA CADENA\n");
  
  do {
  	caracter = getchar();
  	if (caracter != '\n') {
  		cadena[indice++] = caracter;
  	}
	} while(caracter != '\n' && indice < MAXTAM - 2);
  cadena[indice] = '\0';
}       

void inic(char cadena[]) {
  int indice = 0;
  while (cadena[indice] == ' ') {
    indice++;
  }
  strcpy(&cadena[0], &cadena[indice]);
}

void fin(char cadena[]) {
  int indice ;
  indice = strlen(cadena);
  while(cadena[indice - 1] == ' ') {
    indice--;
  }
  cadena[indice] = '\0';
}            

void inter(char cadena[]) {
  int indice_1, indice_2;
  for (indice_1 = 0; cadena[indice_1] != '\0'; indice_1++) {
  	for (indice_2 = indice_1; cadena[indice_2] == ' '; indice_2++) {
      ;
    }
  	if (indice_2 != indice_1) {
  		strcpy(&cadena [indice_1], &cadena [indice_2 - 1]);
  	}
  }
}   

int contar(char cadena []) {
  int palabras = 0, indice;
  for (indice = 0; cadena[indice] != '\0'; indice++) {
  	if (cadena [indice] == ' ') {
      palabras ++;
    }
  }
  return (palabras+1);
}