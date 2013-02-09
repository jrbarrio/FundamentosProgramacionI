#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define TAMANIO_PAQUETE 13
#define TAMANIO_DESTINO 6
#define MAX_DESTINOS 6
#define MAX_ERRORES 3

typedef char * CADENA;
typedef FILE * FICHERO;
typedef struct nodo * PUNT_NODO;
typedef char CADENA_5[TAMANIO_DESTINO];
typedef char FICHA[TAMANIO_PAQUETE];

typedef struct nodo {
	FICHA info;
	PUNT_NODO enlace;
} NODO;

void inicializa_listas(CADENA nomf_entrada, PUNT_NODO *entrada,
        PUNT_NODO *salida_1, PUNT_NODO *ultimo_1,
        PUNT_NODO *salida_2, PUNT_NODO *ultimo_2,
        PUNT_NODO *error, PUNT_NODO *ultimo_e);

PUNT_NODO vuelca_fichero_a_lista(CADENA nomfich);

void vuelca_fichero_rutado_a_array(CADENA nomf_rutado, CADENA_5 vector_rutado[]);

void coge_elemento(PUNT_NODO *entrada, PUNT_NODO *elemento);

void calcula_salida(PUNT_NODO elemento, CADENA_5 vector_rutado[],
        char *puerta, char *prioridad, short *encontrado);

void inserta_nodo(PUNT_NODO *cabeza, PUNT_NODO *ultimo, PUNT_NODO elemento,
        char prioridad);

void inserta_en_cola(PUNT_NODO *cabeza, PUNT_NODO *ultimo,
        PUNT_NODO elemento);

PUNT_NODO inserta_en_cabeza(PUNT_NODO cabeza, PUNT_NODO elemento);

void visualiza_listas(PUNT_NODO entrada, PUNT_NODO salida_1,
        PUNT_NODO salida_2, PUNT_NODO error);

void visualiza_lista(PUNT_NODO cabeza);

void vuelca_lista_a_fichero_errores(PUNT_NODO error, CADENA nomf_errores);

void visualiza_fichero_errores(CADENA nomf_errores);

void pulsa_enter(void);

/*****************************************************************************/

void main(void) {
    CADENA nomf_entrada = "ENTRADA.DAT";
    CADENA nomf_rutado = "RUTADO.DAT";
    CADENA nomf_errores = "ERRORES.DAT";
    PUNT_NODO entrada, salida_1, ultimo_1, salida_2, ultimo_2, error, ultimo_e,
            elemento;
    CADENA_5 vector_rutado[MAX_DESTINOS];
    int num_errores = 0;
    char puerta, prioridad;
    short encontrado;
    
    inicializa_listas(nomf_entrada, &entrada, &salida_1, &ultimo_1, &salida_2,
            &ultimo_2, &error, &ultimo_e);
    vuelca_fichero_rutado_a_array(nomf_rutado, vector_rutado);
    
    while (num_errores <= MAX_ERRORES) {
        coge_elemento(&entrada, &elemento);
        calcula_salida(elemento, vector_rutado, &puerta, &prioridad,
                &encontrado);
        if (encontrado) {
            switch (puerta) {
                case '1':
                    inserta_nodo(&salida_1, &ultimo_1, elemento, prioridad);
                    break;
                case '2':
                    inserta_nodo(&salida_2, &ultimo_2, elemento, prioridad);
            }
        } else {
            inserta_nodo(&error, &ultimo_e, elemento, prioridad);
            num_errores++;
        }
    }
    
    visualiza_listas(entrada, salida_1, salida_2, error);
    vuelca_lista_a_fichero_errores(error, nomf_errores);
    visualiza_fichero_errores(nomf_errores);
}

void inicializa_listas(CADENA nomf_entrada, PUNT_NODO *entrada,
        PUNT_NODO *salida_1, PUNT_NODO *ultimo_1,
        PUNT_NODO *salida_2, PUNT_NODO *ultimo_2,
        PUNT_NODO *error, PUNT_NODO *ultimo_e) {
    *entrada = vuelca_fichero_a_lista(nomf_entrada);
    *salida_1 = *ultimo_1 = (PUNT_NODO) NULL;
    *salida_2 = *ultimo_2 = (PUNT_NODO) NULL;
    *error = *ultimo_e = (PUNT_NODO) NULL;
}

PUNT_NODO vuelca_fichero_a_lista(CADENA nomfich) {
    FICHERO punt_fich;
    PUNT_NODO cabeza, nuevo, ultimo;
    FICHA elemento;
    
    cabeza = (PUNT_NODO) NULL;
    if ((punt_fich = fopen(nomfich, "rb")) != (FICHERO) NULL) {
        while (fread(elemento, TAMANIO_PAQUETE, 1, punt_fich) != 0) {
            nuevo = (PUNT_NODO) malloc(sizeof (NODO));
            strcpy (nuevo->info, elemento);
            nuevo->enlace = (PUNT_NODO) NULL;
            inserta_en_cola(&cabeza, &ultimo, nuevo);    
        }
        fclose(punt_fich);
    }
    return (cabeza);
}

void vuelca_fichero_rutado_a_array(CADENA nomf_rutado, 
        CADENA_5 vector_rutado[]) {
    FICHERO punt_fich;
    int indice = 0;
    char destino[TAMANIO_DESTINO];
    
    if ((punt_fich = fopen(nomf_rutado, "rb")) != (FICHERO) NULL) {
        while (fread(destino, TAMANIO_DESTINO, 1, punt_fich) != 0) {
            stpcpy(vector_rutado[indice], destino);
            indice++;
        }
    }
}

void coge_elemento(PUNT_NODO *entrada, PUNT_NODO *elemento) {
    *elemento = *entrada;
    *entrada = (*entrada)->enlace;
    (*elemento)->enlace = (PUNT_NODO) NULL;
}

void calcula_salida(PUNT_NODO elemento, CADENA_5 vector_rutado[],
        char *puerta, char *prioridad, short *encontrado) {
    char direccion[5];
    char dir_destino[5];
    short caracter, indice;
    
    for (caracter = 0; caracter < 4; caracter++) {
        direccion[4] = '\0';
        encontrado = 0;
        indice = 0;
        
        while (!*encontrado && indice < MAX_DESTINOS) {
            for (caracter = 0; caracter < 4; caracter++) {
                dir_destino[caracter] = vector_rutado[indice][caracter];
            }
            dir_destino[4] = '\0';
            if (strcmp(direccion, dir_destino) == 0) {
                *encontrado = 1;
            }
            indice++;
        }
        if (*encontrado) {
            *puerta = vector_rutado[indice - 1][4];
        }
        prioridad = elemento->info[8];
    }
}

void inserta_nodo(PUNT_NODO *cabeza, PUNT_NODO *ultimo, PUNT_NODO elemento,
        char prioridad) {
    switch (prioridad) {
        case '0':
          inserta_en_cola(cabeza, ultimo, elemento);
          break;
        case '1':
            *cabeza = inserta_en_cabeza(*cabeza, elemento);
    }
}

void inserta_en_cola(PUNT_NODO *cabeza, PUNT_NODO *ultimo,
        PUNT_NODO nuevo) {
    if (*cabeza == (PUNT_NODO) NULL) {
        *cabeza = nuevo;
    } else {
        (*ultimo)->enlace = nuevo;
    }
    *ultimo = nuevo;
}

PUNT_NODO inserta_en_cabeza(PUNT_NODO cabeza, PUNT_NODO elemento) {
    elemento->enlace = cabeza;
    cabeza = elemento;
    return (cabeza);
}

void visualiza_listas(PUNT_NODO entrada, PUNT_NODO salida_1,
        PUNT_NODO salida_2, PUNT_NODO error) {
    printf("LISTA DE ENTRADA\n\n");
    visualiza_lista(entrada);
    printf("LISTA DE SALIDA_!\n\n");
    visualiza_lista(salida_1);
    printf("LISTA DE SALIDA_2\n\n");
    visualiza_lista(salida_2);
    printf("LISTA DE ERROR\n\n");
    visualiza_lista(error);
}

void visualiza_lista(PUNT_NODO cabeza) {
    PUNT_NODO recorre;
    
    recorre = cabeza;
    while (recorre != (PUNT_NODO) NULL) {
        puts (recorre->info);
        recorre = recorre->enlace;
    }
    pulsa_enter();
}

void vuelca_lista_a_fichero_errores(PUNT_NODO error, CADENA nomf_errores) {
    FICHERO punt_fich;
    PUNT_NODO viejo;
    
    if ((punt_fich = fopen(nomf_errores, "wb")) != (FICHERO) NULL) {
        while (error != (PUNT_NODO) NULL) {
            fwrite(&error->info, TAMANIO_PAQUETE, 1, punt_fich);
            viejo = error;
            error = error->enlace;
            free(viejo);
        }
    }
}

void visualiza_fichero_errores(CADENA nomf_errores) {
    FICHERO punt_fich;
    char paquete[TAMANIO_PAQUETE];
    
    if ((punt_fich = fopen(nomf_errores, "rb")) != (FICHERO) NULL) {
        printf("FICHERO DE ERRORES\n\n");
        while (fread(paquete, TAMANIO_PAQUETE, 1, punt_fich) != 0) {
            puts(paquete);
        }
        fclose(punt_fich);
    }
}

void pulsa_enter(void) {
    printf("Pulsa la tecla ENTER para continuar");
    while (getchar() != '\r');
}