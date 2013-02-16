#include <stdio.h>

#define MAXIMO 10

void lee_vectores(int vector_x[], int vector_y[]);
void lee_vector(int vector[]);
void compara_vectores(int vector_x[], int vector_y[], int vector_z[]);
void visualiza_vectores(int vector_x[], int vector_y[], int vector_z[]);
void visualiza_vector(int vector[]);
void cuenta_elementos(int vector[]);

void main() {
    int vector_x[MAXIMO], vector_y[MAXIMO], vector_z[MAXIMO];
    
    lee_vectores(vector_x, vector_y);
    compara_vectores(vector_x, vector_y, vector_z);
    visualiza_vectores(vector_x, vector_y, vector_z);
}

void lee_vectores(int vector_x[], int vector_y[]) {
    printf("INTRODUCE LOS %d ELEMENTOS DEL ARRAY X\n", MAXIMO);
    lee_vector(vector_x);
    printf("INTRODUCE LOS %d ELEMENTOS DEL ARRAY Y\n", MAXIMO);
    lee_vector(vector_y);
}

void lee_vector(int vector[]) {
    int indice;
    
    for (indice = 0; indice < MAXIMO; indice++) {
        scanf("%d", &vector[indice]);
    }
}

void compara_vectores(int vector_x[], int vector_y[], int vector_z[]) {
    int indice;
    
    for (indice = 0; indice < MAXIMO; indice++) {
        if (vector_x[indice] > vector_y[indice]) {
            vector_z[indice] = 1;
        } else {
            if (vector_x[indice] == vector_y[indice]) {
                vector_z[indice] = 0;
            } else {
                vector_z[indice] = -1;
            }
        }
    }
}

void visualiza_vectores(int vector_x[], int vector_y[], int vector_z[]) {
    printf("ELEMENTOS DEL ARRAY X");
    visualiza_vector(vector_x);
    printf("ELEMENTOS DEL ARRAY Y");
    visualiza_vector(vector_y);
    cuenta_elementos(vector_z);
}

void visualiza_vector(int vector[]) {
    int indice = 0;
    
    for (indice = 0; indice < MAXIMO; indice++) {
        printf("%5d", vector[indice]);
    }
    printf("\n\n");
}

void cuenta_elementos(int vector[]) {
    int indice, mayores, menores;
    
    printf("ELEMENTOS DEL ARRAY Z");
    for (indice = 0, mayores = 0, menores = 0; indice < MAXIMO; indice++) {
        printf("%5d", vector[indice]);
        if (vector[indice] == 1) {
            mayores++;
        } else {
            if (vector[indice] == -1) {
                menores++;
            }
        }
    }
    
    printf("\n\n%d ELEMENTOS DE X QUE SON MAYORES QUE LOS CORRESPONDIENTES DE Y", mayores);
    printf("\n\n%d ELEMENTOS DE X QUE SON MENORES QUE LOS CORRESPONDIENTES DE Y", menores);
}