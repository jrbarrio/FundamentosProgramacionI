#include <stdio.h>

#define MAXTAM 20

void lee_cadena(char cadena[], int *num_elem);
void cuenta_caracteres(char cadena[], int contador[], int num_elem);
int mayor_frecuencia(int contador[], int num_elem);
void visualiza_moda(char cadena[], int contador[], int num_elem, int frecuencia);

void main(void) {
    char cadena[MAXTAM];
    static int contador[MAXTAM];
    int num_elem;
    int frecuencia;
    
    lee_cadena(cadena, &num_elem);
    cuenta_caracteres(cadena, contador, num_elem);
    frecuencia = mayor_frecuencia(contador, num_elem);
    visualiza_moda(cadena, contador, num_elem, frecuencia);
}

void lee_cadena(char cadena[], int *num_elem) {
    int indice = 0;
    char caracter;
    
    puts("INTRODUCE UNA CADENA (-ENTER- PARA ACABAR)\n\n");
    while (indice < MAXTAM && (caracter = getchar()) != '\r') {
        cadena[indice++] = caracter;
    }
    *num_elem = indice++;
}

void cuenta_caracteres(char cadena[], int contador[], int num_elem) {
    int indice_1, indice_2;
    
    for (indice_1 = 0; indice_1 < num_elem; indice_1++) {
        for (indice_2 = indice_1; indice_2 < num_elem; indice_2++) {
            if (cadena[indice_2] == cadena[indice_1]) {
                contador[indice_1]++;
            }
        }
    }
}

int mayor_frecuencia(int contador[], int num_elem) {
    int indice, indice_max;
    
    for (indice = 0, indice_max = 0; indice < num_elem; indice++) {
        if (contador[indice] > contador[indice_max]) {
            indice_max = indice;
        }
    }
    
    return (contador[indice_max]);
}

void visualiza_moda(char cadena[], int contador[], int num_elem, int frecuencia) {
    int indice;
    
    printf("\n\nLOS SIGUIENTES CARACTERES APARECEN %d VECES\n", frecuencia);
    for (indice = 0; indice < num_elem; indice++) {
        if (contador[indice] == frecuencia) {
            printf("%c\n", cadena[indice]);
        }
    }
}