#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define NUM_CAZUELAS 300

typedef char * CADENA;
typedef FILE * FICHERO;
typedef char CADENA_20[21];
typedef struct nodo_puntuaciones * PUNT_NODO_PUNTUACIONES;
typedef struct nodo_clasificacion * PUNT_NODO_CLASIFICACION;

typedef struct ficha_inscripcion {
    CADENA_20 nombre;
    CADENA_20 poblacion;
    int numero;
} FICHA_INSCRIPCION;

typedef struct ficha_puntuaciones {
    int numero;
    short sabor, punto, presentacion;
} FICHA_PUNTUACIONES;

typedef struct nodo_puntuaciones {
    FICHA_PUNTUACIONES info;
    PUNT_NODO_PUNTUACIONES enlace;
} NODO_PUNTUACIONES;

typedef struct ficha_clasificacion {
    CADENA_20 nombre;
    CADENA_20 poblacion;
    int numero;
    int puntuacion;
} FICHA_CLASIFICACION;

typedef struct nodo_clasificacion {
    FICHA_CLASIFICACION info;
    PUNT_NODO_CLASIFICACION enlace;
} NODO_CLASIFICACION;

/***************************************************************************/

void vuelca_lista_a_fichero_clasificacion(PUNT_NODO_CLASIFICACION cabeza,
        CADENA nomf_clasificacion);

void vuelca_fichero_inscripciones_a_vector(CADENA nomf_inscripciones, 
        FICHA_INSCRIPCION vector_inscripciones[], int *error);

void introduce_puntuaciones(PUNT_NODO_PUNTUACIONES *p_juez_1,
        PUNT_NODO_PUNTUACIONES *p_juez_2, PUNT_NODO_PUNTUACIONES *p_juez_3);

void pide_datos(PUNT_NODO_PUNTUACIONES *p_nuevo, char *juez);

void inserta_nodo(PUNT_NODO_PUNTUACIONES *cabeza,
        PUNT_NODO_PUNTUACIONES *ultimo,
        PUNT_NODO_PUNTUACIONES nuevo);

char pregunta(void);

PUNT_NODO_CLASIFICACION crea_clasificacion(PUNT_NODO_PUNTUACIONES juez_1,
        PUNT_NODO_PUNTUACIONES juez_2, PUNT_NODO_PUNTUACIONES juez_3,
        FICHA_INSCRIPCION vector_inscripciones[]);

void elimina_nodo(PUNT_NODO_PUNTUACIONES *p_cabeza,
        PUNT_NODO_PUNTUACIONES *p_viejo,
        PUNT_NODO_PUNTUACIONES viejo_1);

PUNT_NODO_PUNTUACIONES busca_nodo(PUNT_NODO_PUNTUACIONES cabeza,
        PUNT_NODO_PUNTUACIONES viejo_1);

PUNT_NODO_PUNTUACIONES elimina(PUNT_NODO_PUNTUACIONES cabeza,
        PUNT_NODO_PUNTUACIONES viejo_1);

PUNT_NODO_CLASIFICACION crea_nodo(PUNT_NODO_PUNTUACIONES viejo_1,
        PUNT_NODO_PUNTUACIONES viejo_2, PUNT_NODO_PUNTUACIONES viejo_3,
        FICHA_INSCRIPCION vector_inscripciones[]);

PUNT_NODO_CLASIFICACION busca_posicion(PUNT_NODO_CLASIFICACION cabeza,
        PUNT_NODO_CLASIFICACION nuevo);

PUNT_NODO_CLASIFICACION inserta_en_orden(PUNT_NODO_CLASIFICACION cabeza,
        PUNT_NODO_CLASIFICACION nuevo, PUNT_NODO_CLASIFICACION posicion);

/***************************************************************************/

void main (void) {
    char nomf_inscripciones[] = "INSCRIP";
    char nomf_clasificacion[] = "GANADOR";
    FICHA_INSCRIPCION vector_inscripciones[NUM_CAZUELAS];
    PUNT_NODO_PUNTUACIONES juez_1, juez_2, juez_3;
    PUNT_NODO_CLASIFICACION ganador;
    int error;
    
    vuelca_fichero_inscripciones_a_vector(nomf_inscripciones, 
            vector_inscripciones, &error);
    if (error) {
        printf("ERROR AL INTENTAR ABRIR EL FICHERO PARA LEER");
        getchar();
    } else {
        introduce_puntuaciones(&juez_1, &juez_2, &juez_3);
        ganador = crea_clasificacion(juez_1, juez_2, juez_3,
                vector_inscripciones);
        vuelca_lista_a_fichero_clasificacion(ganador, nomf_clasificacion);
    }
}

void vuelca_fichero_inscripciones_a_vector(CADENA nomf_inscripciones, 
        FICHA_INSCRIPCION vector_inscripciones[], int *error) {
    FICHERO punt_fich;
    FICHA_INSCRIPCION elemento;
    int indice = 0;
    
    if ((punt_fich = fopen(nomf_inscripciones, "rb")) != (FICHERO) NULL) {
        while (fread(&elemento, sizeof (elemento), 1, punt_fich) != 0) {
            vector_inscripciones[indice++] = elemento;
        }
        fclose(punt_fich);
        *error = 0;
    } else {
        *error = 1;
    }
}

void vuelca_lista_a_fichero_clasificacion(PUNT_NODO_CLASIFICACION cabeza,
        CADENA nomf_clasificacion) {
    PUNT_NODO_CLASIFICACION viejo;
    FICHERO punt_fich;
    
    if ((punt_fich = fopen(nomf_clasificacion, "wb")) != (FICHERO) NULL) {
        while (cabeza != (PUNT_NODO_CLASIFICACION) NULL) {
            fwrite(&cabeza->info, sizeof (FICHA_CLASIFICACION), 1, punt_fich);
            viejo = cabeza;
            cabeza = cabeza->enlace;
            free (viejo);
        }
        fclose(punt_fich);
    }
}

void introduce_puntuaciones(PUNT_NODO_PUNTUACIONES *p_juez_1,
        PUNT_NODO_PUNTUACIONES *p_juez_2, PUNT_NODO_PUNTUACIONES *p_juez_3) {
    PUNT_NODO_PUNTUACIONES nuevo, ultimo_1, ultimo_2, ultimo_3;
    char juez;
    char respuesta;
    
    *p_juez_1 = *p_juez_2 = *p_juez_3 = (PUNT_NODO_PUNTUACIONES) NULL;
    do {
        pide_datos(&nuevo, &juez);
        switch (juez) {
            case 'X':
                inserta_nodo(p_juez_1, &ultimo_1, nuevo);
                break;
            case 'Y':
                inserta_nodo(p_juez_2, &ultimo_2, nuevo);
                break;
            case 'Z':
                inserta_nodo(p_juez_3, &ultimo_3, nuevo);
                break;
        }
        respuesta = pregunta();
    } while (respuesta != 'N');
}

void pide_datos(PUNT_NODO_PUNTUACIONES *p_nuevo, char *juez) {
    printf("\n\nIDENTIFICADOR DE JUEZ --->");
    *juez = getchar();
    *p_nuevo = (PUNT_NODO_PUNTUACIONES) malloc(sizeof (NODO_PUNTUACIONES));
    printf("\nNUMERO --->");
    scanf("%d", &(*p_nuevo)->info.numero);
    printf("\nSABOR --->");
    scanf("%d", &(*p_nuevo)->info.sabor);
    printf("\nPUNTO --->");
    scanf("%d", &(*p_nuevo)->info.punto);
    printf("\nPRESENTACION --->");
    scanf("%d", &(*p_nuevo)->info.presentacion);
    (*p_nuevo)->enlace = (PUNT_NODO_PUNTUACIONES) NULL;
}

void inserta_nodo(PUNT_NODO_PUNTUACIONES *p_cabeza,
        PUNT_NODO_PUNTUACIONES *p_ultimo,
        PUNT_NODO_PUNTUACIONES nuevo) {
    if (*p_cabeza == (PUNT_NODO_PUNTUACIONES) NULL) {
        *p_cabeza = nuevo;
    } else {
        (*p_ultimo)->enlace = nuevo;
    }
    
    *p_ultimo = nuevo;
}

char pregunta(void) {
    char respuesta;
    
    printf("\n¿DESEA INTRODUCIR MAS DATOS?(S/N): ");
    respuesta = getchar();
    
    return (respuesta);
}

PUNT_NODO_CLASIFICACION crea_clasificacion(PUNT_NODO_PUNTUACIONES juez_1,
        PUNT_NODO_PUNTUACIONES juez_2, PUNT_NODO_PUNTUACIONES juez_3,
        FICHA_INSCRIPCION vector_inscripciones[]) {
    PUNT_NODO_CLASIFICACION nuevo, posicion;
    PUNT_NODO_CLASIFICACION ganador = (PUNT_NODO_CLASIFICACION) NULL;
    PUNT_NODO_PUNTUACIONES viejo_1, viejo_2, viejo_3;
    
    while (juez_1 != (PUNT_NODO_PUNTUACIONES) NULL) {
        viejo_1 = juez_1;
        juez_1 = juez_1->enlace;
        elimina_nodo(&juez_2, &viejo_2, viejo_1);
        elimina_nodo(&juez_3, &viejo_3, viejo_1);
        nuevo = crea_nodo(viejo_1, viejo_2, viejo_3, vector_inscripciones);
        posicion = busca_posicion(ganador, nuevo);
        ganador = inserta_en_orden(ganador, nuevo, posicion);
    }
    return (ganador);
}

void elimina_nodo(PUNT_NODO_PUNTUACIONES *p_cabeza,
        PUNT_NODO_PUNTUACIONES *p_viejo,
        PUNT_NODO_PUNTUACIONES viejo_1) {
    *p_viejo = busca_nodo(*p_cabeza, viejo_1);
    *p_cabeza = elimina(*p_cabeza, p_viejo);
}

PUNT_NODO_PUNTUACIONES busca_nodo(PUNT_NODO_PUNTUACIONES cabeza,
        PUNT_NODO_PUNTUACIONES viejo_1) {
    PUNT_NODO_PUNTUACIONES recorre;
    
    recorre = cabeza;
    while (recorre != (PUNT_NODO_PUNTUACIONES) NULL
            && recorre->info.numero != viejo_1->info.numero) {
        recorre = recorre->enlace;
    }
    return (recorre);
}

PUNT_NODO_PUNTUACIONES elimina(PUNT_NODO_PUNTUACIONES cabeza,
        PUNT_NODO_PUNTUACIONES viejo) {
    PUNT_NODO_PUNTUACIONES anterior;
    if (viejo == cabeza) {
        cabeza = cabeza->enlace;
    } else {
        anterior = cabeza;
        while (anterior->enlace != viejo) {
            anterior = anterior->enlace;
        }
        anterior->enlace = viejo->enlace;
    }
    viejo->enlace = (PUNT_NODO_PUNTUACIONES) NULL;
    return (cabeza);
}

PUNT_NODO_CLASIFICACION crea_nodo(PUNT_NODO_PUNTUACIONES viejo_1,
        PUNT_NODO_PUNTUACIONES viejo_2, PUNT_NODO_PUNTUACIONES viejo_3,
        FICHA_INSCRIPCION vector_inscripciones[]) {
    PUNT_NODO_CLASIFICACION nuevo;
    
    nuevo = (PUNT_NODO_CLASIFICACION) malloc(sizeof (NODO_CLASIFICACION));
    strcpy(nuevo->info.nombre, vector_inscripciones[viejo_1->info.numero - 1].nombre);
    strcpy(nuevo->info.nombre, vector_inscripciones[viejo_1->info.numero - 1].poblacion);
    nuevo->info.numero = viejo_1->info.numero;
    nuevo->info.puntuacion = viejo_1->info.sabor + viejo_1->info.punto + viejo_1->info.presentacion
            + viejo_2->info.sabor + viejo_2->info.punto + viejo_2->info.presentacion
            + viejo_3->info.sabor + viejo_3->info.punto + viejo_3->info.presentacion;
    nuevo->enlace = (PUNT_NODO_CLASIFICACION) NULL;
    free (viejo_1);
    free (viejo_2);
    free (viejo_3);
    return (nuevo);
}

PUNT_NODO_CLASIFICACION busca_posicion(PUNT_NODO_CLASIFICACION cabeza,
        PUNT_NODO_CLASIFICACION nuevo) {
    PUNT_NODO_CLASIFICACION recorre;
    int encontrado = 0;
    
    recorre = cabeza;
    while (recorre != (PUNT_NODO_CLASIFICACION) NULL && !encontrado) {
        if (recorre->info.puntuacion < nuevo->info.puntuacion) {
            encontrado = 1;
        } else {
            if (recorre->info.puntuacion == nuevo->info.puntuacion
                    && recorre->info.numero > nuevo->info.numero) {
                encontrado = 1;
            } else {
                recorre = recorre->enlace;
            }
        }
    }
    return (recorre);
}

PUNT_NODO_CLASIFICACION inserta_en_orden(PUNT_NODO_CLASIFICACION cabeza,
        PUNT_NODO_CLASIFICACION nuevo, PUNT_NODO_CLASIFICACION posicion) {
    PUNT_NODO_CLASIFICACION anterior;
    
    if (posicion == cabeza) {
        nuevo->enlace = cabeza;
        cabeza = nuevo;
    } else {
        anterior = cabeza;
        while(anterior->enlace != posicion) {
            anterior = anterior->enlace;
        }
        nuevo->enlace = posicion;
        anterior->enlace = nuevo;
    }
    return (cabeza);
}