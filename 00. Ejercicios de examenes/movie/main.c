#include <stdio.h>
#include <malloc.h>

#define MAX_CARACTERES 15
#define FILAS 10
#define COLUMNAS 12
#define UMBRAL 50

typedef char * CADENA;
typedef FILE * FICHERO;
typedef struct nodo_cm * PUNT_NODO_CM;

typedef struct ficha_imagen {
    int nivel_de_gris;
} FICHA_IMAGEN;

typedef struct ficha_cm {
    float xc, yc;
} FICHA_CM;

typedef struct nodo_cm {
    FICHA_CM info;
    PUNT_NODO_CM enlace;
} NODO_CM;

typedef struct recttangulo {
    int x_min, y_min, x_max, y_max;
} RECTANGULO;

/****************************************************************************/

PUNT_NODO_CM crea_lista(CADENA nomf_mov);

PUNT_NODO_CM crea_nodo(CADENA nomf_imagen);

void inserta_en_cola(PUNT_NODO_CM *cabeza, PUNT_NODO_CM *ultimo,
        PUNT_NODO_CM nuevo);

void vuelca_fichero_imagen_a_array(CADENA nomf_imagen, 
        FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

void binariza_imagen(FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

FICHA_CM calcula_centro_de_masas(FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

void vuelca_lista_a_fichero(PUNT_NODO_CM cabeza, CADENA nomf_cm);

void averigua_superposicion(CADENA nomf_mov_cuad, CADENA nomf_mov_circ);

RECTANGULO calcula_rectangulo_minimo(CADENA nomf_imagen);

RECTANGULO calcula_rectangulo(FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

int calcula_y_min(FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

int calcula_x_min(FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

int calcula_y_max(FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

int calcula_x_max(FICHA_IMAGEN matriz_imagen[][COLUMNAS]);

int coinciden(RECTANGULO *p_rectang_1, RECTANGULO *p_rectang_2);
        
/****************************************************************************/

void main (void) {
    char nomf_mov_cuad[] = "CUADRADO.MOV";
    char nomf_mov_circ[] = "CIRCULO.MOV";
    char nomf_cm_cuad[] = "CUADRADO.CM";
    char nomf_cm_circ[] = "CIRCULO.CM";
    PUNT_NODO_CM cabeza_cuadrado, cabeza_circulo; 
    
    cabeza_cuadrado = crea_lista(nomf_mov_cuad);
    cabeza_circulo = crea_lista(nomf_mov_circ);
    vuelca_lista_a_fichero(cabeza_cuadrado, nomf_cm_cuad);
    vuelca_lista_a_fichero(cabeza_circulo, nomf_cm_circ);
    averigua_superposicion(nomf_mov_cuad, nomf_mov_circ);
}

PUNT_NODO_CM crea_lista(CADENA nomf_mov) {
    FICHERO punt_fich;
    PUNT_NODO_CM cabeza, nuevo, ultimo;
    char nomf_imagen[MAX_CARACTERES];
    
    cabeza = (PUNT_NODO_CM) NULL;
    if ((punt_fich = fopen(nomf_mov, "r")) != (FICHERO) NULL) {
        while (fscanf(punt_fich, "%s", nomf_imagen) != -1) {
            nuevo = crea_nodo(nomf_imagen);
            inserta_en_cola(&cabeza, &ultimo, nuevo);
        }
        fclose(punt_fich);
    }
    return (cabeza);
}

PUNT_NODO_CM crea_nodo(CADENA nomf_imagen) {
    FICHA_IMAGEN matriz_imagen[FILAS][COLUMNAS];
    PUNT_NODO_CM nuevo;
    
    vuelca_fichero_imagen_a_array(nomf_imagen, matriz_imagen);
    binariza_imagen(matriz_imagen);
    nuevo = (PUNT_NODO_CM) malloc(sizeof (NODO_CM));
    nuevo->info = calcula_centro_de_masas(matriz_imagen);
    nuevo->enlace = (PUNT_NODO_CM) NULL;
    return (nuevo);
}

void inserta_en_cola(PUNT_NODO_CM *cabeza, PUNT_NODO_CM *ultimo,
        PUNT_NODO_CM nuevo) {
    if (*cabeza == (PUNT_NODO_CM) NULL) {
        *cabeza = nuevo;
    } else {
        (*ultimo)->enlace = nuevo;
    }
    *ultimo = nuevo;
}

void vuelca_fichero_imagen_a_array(CADENA nomf_imagen, 
        FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    FICHERO punt_fich;
    FICHA_IMAGEN elemento;
    int fila = 0, columna = 0;
    
    if ((punt_fich = fopen(nomf_imagen, "rb")) != (FICHERO) NULL) {
        while (fread(&elemento, sizeof (elemento), 1, punt_fich) != -1) {
            matriz_imagen[fila][columna++] = elemento;
            if (columna == COLUMNAS) {
                columna = 0;
                fila++;
            }
        }
        fclose(punt_fich);
    }
}

void binariza_imagen(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    int fila, columna;
    
    for (fila = 0; fila < FILAS; fila++) {
        for (columna = 0; columna < COLUMNAS; columna++) {
            if (matriz_imagen[fila][columna].nivel_de_gris <= UMBRAL) {
                matriz_imagen[fila][columna].nivel_de_gris = 1;
            } else {
                matriz_imagen[fila][columna].nivel_de_gris = 0;
            }
        }
    }
}

FICHA_CM calcula_centro_de_masas(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    FICHA_CM centro_de_masas;
    int fila, columna;
    int numero_de_pixels_negros = 0;
    float numerador_xc = 0, numerador_yc = 0;
    
    for (fila = 0; fila < FILAS; fila++) {
        for (columna = 0; columna < COLUMNAS; columna++) {
            if (matriz_imagen[fila][columna].nivel_de_gris == 1) {
                numero_de_pixels_negros++;
                numerador_xc += columna + 1;
                numerador_yc += fila + 1;
            }
        }
    }
    
    centro_de_masas.xc = numerador_xc / numero_de_pixels_negros;
    centro_de_masas.yc = numerador_yc / numero_de_pixels_negros;
    return (centro_de_masas);
}

void vuelca_lista_a_fichero(PUNT_NODO_CM cabeza, CADENA nomf_cm) {
    PUNT_NODO_CM viejo;
    FICHERO punt_fich;
    
    if ((punt_fich = fopen(nomf_cm, "wb")) != (FICHERO) NULL) {
        while (cabeza != (PUNT_NODO_CM) NULL) {
            fwrite(&cabeza->info, sizeof (FICHA_CM), 1, punt_fich);
            viejo = cabeza;
            cabeza = cabeza->enlace;
            free (viejo);
        }
        fclose(punt_fich);
    }
}

void averigua_superposicion(CADENA nomf_mov_cuad, CADENA nomf_mov_circ) {
    FICHERO punt_fich_cuad, punt_fich_circ, punt_fich_sup;
    char nomf_img_cuad[MAX_CARACTERES];
    char nomf_img_circ[MAX_CARACTERES];
    int instante = 0;
    RECTANGULO rectang_min_cuad, rectang_min_circ;
    
    if ((punt_fich_cuad = fopen(nomf_mov_cuad, "r")) != (FICHERO) NULL
            && (punt_fich_circ = fopen(nomf_mov_circ, "r")) != (FICHERO) NULL
            && (punt_fich_sup = fopen("SUPERPOS.TXT", "w")) != (FICHERO) NULL) {
        instante++;
        rectang_min_cuad = calcula_rectangulo_minimo(nomf_img_cuad);
        rectang_min_circ = calcula_rectangulo_minimo(nomf_img_circ);
        if (coinciden(&rectang_min_cuad, &rectang_min_circ)
                || coinciden(&rectang_min_circ, &rectang_min_cuad)) {
            fprintf(punt_fich_sup, "%d\n", instante);
        }
        fclose(punt_fich_cuad);
        fclose(punt_fich_circ);
        fclose(punt_fich_sup);
    }
}

RECTANGULO calcula_rectangulo_minimo(CADENA nomf_imagen) {
    FICHA_IMAGEN matriz_imagen[FILAS][COLUMNAS];
    RECTANGULO rectangulo_minimo;
    
    vuelca_fichero_imagen_a_array(nomf_imagen, matriz_imagen);
    binariza_imagen(matriz_imagen);
    rectangulo_minimo = calcula_rectangulo(matriz_imagen);
    return (rectangulo_minimo);
}

/* FORMA ALTERNATIVA: 
RECTANGULO calcula_rectangulo(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    RECTANGULO rectangulo = {COLUMNAS - 1, FILAS - 1, 0, 0};
    int fila, columna;
    
    for (fila = 0; fila < filas; fila++) {
        for (columna = 0; columna < COLUMNAS; columna++) {
            if (matriz_imagen[fila][columna].nivel_de_gris == 1) {
                if (rectangulo.x_min > columna) {
                    rectangulo.x_min = columna;
                }
                if (rectangulo.y_min > fila) {
                    rectangulo.y_min = fila;
                }
                if (rectangulo.x_max < columna) {
                    rectangulo.x_max = columna;
                }
                if (rectangulo.y_max < fila) {
                    rectangulo.y_max = fila;
                }
            }
        }
    }
    
    rectangulo.x_min++;
    rectangulo.x_max++;
    rectangulo.y_min++;
    rectangulo.y_max++;
    
    return (rectangulo);
}
*/

RECTANGULO calcula_rectangulo(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    RECTANGULO rectangulo;
    
    rectangulo.y_min = calcula_y_min(matriz_imagen);
    rectangulo.x_min = calcula_x_min(matriz_imagen);
    rectangulo.y_max = calcula_y_max(matriz_imagen);
    rectangulo.x_max = calcula_x_max(matriz_imagen);
}

int calcula_y_min(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    int y_min;
    int encontrado = 0;
    int fila = 0, columna;
    do {
        columna = 0;
        do {
            if (matriz_imagen[fila][columna].nivel_de_gris == 1) {
                encontrado = 1;
                y_min = fila + 1;
            }
        } while (++columna < COLUMNAS && !encontrado);        
    } while (++fila < FILAS && !encontrado);
    
    return (y_min);
}

int calcula_x_min(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    int x_min;
    int encontrado = 0;
    int fila, columna = 0;
    do {
        fila = 0;
        do {
            if (matriz_imagen[fila][columna].nivel_de_gris == 1) {
                encontrado = 1;
                x_min = columna + 1;
            }
        } while (++fila < FILAS && !encontrado);        
    } while (++columna < COLUMNAS && !encontrado);
    
    return (x_min);
}

int calcula_y_max(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    int y_max;
    int encontrado = 0;
    int fila = FILAS - 1, columna;
    do {
        columna = 0;
        do {
            if (matriz_imagen[fila][columna].nivel_de_gris == 1) {
                encontrado = 1;
                y_max = fila + 1;
            }
        } while (++columna < COLUMNAS && !encontrado);        
    } while (--fila < FILAS && !encontrado);
    
    return (y_max);
}

int calcula_x_max(FICHA_IMAGEN matriz_imagen[][COLUMNAS]) {
    int x_max;
    int encontrado = 0;
    int fila, columna = COLUMNAS - 1;
    do {
        fila = 0;
        do {
            if (matriz_imagen[fila][columna].nivel_de_gris == 1) {
                encontrado = 1;
                x_max = columna + 1;
            }
        } while (++fila < FILAS && !encontrado);        
    } while (--columna < COLUMNAS && !encontrado);
    
    return (x_max);
}

int coinciden(RECTANGULO *p_rectang_1, RECTANGULO *p_rectang_2) {
    int coinciden = 0;
    if ((*p_rectang_1).x_max >= (*p_rectang_2).x_min
            && (*p_rectang_1).x_min <= (*p_rectang_2).x_max
            && (*p_rectang_1).y_min <= (*p_rectang_2).y_max
            && (*p_rectang_1).y_max >= (*p_rectang_2).y_min) {
        coinciden = 1;
    }
    return (coinciden);
}