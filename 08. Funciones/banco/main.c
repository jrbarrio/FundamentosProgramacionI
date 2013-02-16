#include <stdio.h>

#define MAXIMO 9

int lee_operacion(void);
void lee_vector(int vector[]);
int comprueba_validez(int vector[], int operacion);
int digito_suma(int vector[]);
int digito_resta(int vector[]);
int digito_producto(int vector[]);
void visualiza_vector(int vector[]);

void main(void) {
    int operacion;
    int vector[MAXIMO];
    
    operacion = lee_operacion();
    lee_vector(vector);
    visualiza_vector(vector);
    
    if (operacion >= 1 && operacion <= 3) {
        if (comprueba_validez(vector, operacion)) {
            printf("EL NUMERO DE LA CUENTA ES VALIDO");
        } else {
            printf("EL NUMERO DE LA CUENTA NO ES VALIDO");
        }
    } else {
        printf("EL CODIGO DE OPERACION ES INCORRECTO");
    }
}

int lee_operacion(void) {
    int operacion;
    
    printf("1. SUMA\n");
    printf("2. RESTA\n");
    printf("3. PRODUCTO\n");
    printf("\n\nElige operacion ---> ");
    scanf("%d", &operacion);
    return (operacion);
}

void lee_vector(int vector[]) {
    int indice;
    
    printf("INTRODUCE UNO A UNO LOS 9 DIGITOS DEL NUMERO DE CUENTA\n");
    for (indice = 0; indice < MAXIMO; indice++) {
        scanf("%d", &vector[indice]);
    }
}

int comprueba_validez(int vector[], int operacion) {
    int digito, validez = 0;
    
    switch (operacion) {
        case 1:
            digito = digito_suma(vector);
            break;
        case 2:
            digito = digito_resta(vector);
            break;
        case 3:
            digito = digito_producto(vector);
            break;
    }
    
    if (digito == vector[8]) {
        validez = 1;
    }
    
    return (validez);
}

int digito_suma(int vector[]) {
    int indice, suma;
    
    for (indice = 0, suma = 0; indice < MAXIMO - 1; indice++) {
        suma += vector[indice];
    }
    
    return (suma % 10);
}

int digito_resta(int vector[]) {
    int indice, resta;
    
    for (indice = 1, resta = vector[0]; indice < MAXIMO - 1; indice++) {
        resta -= vector[indice];
    }
    
    return (resta % 10);
}

int digito_producto(int vector[]) {
    int indice;
    long producto;
    
    for (indice = 0, producto = 1; indice < MAXIMO; indice++) {
        producto *= vector[indice];
    }
    
    return ((int) (producto % 10));
}

void visualiza_vector(int vector[]) {
    int indice;
    
    for (indice = 0; indice < MAXIMO; indice++) {
        printf("%d", vector[indice]);
    }
    printf("\n\n");
}