/*. Que retorne una lista con los valores de L2 que no están en L1. */
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"

Lista valores_no_en_L1(Lista lista1, Lista lista2) {
    Lista valores_no_comunes = l_crear();

    Iterador iter = iterador(lista2);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);

        if (l_buscar(lista1, elemento_actual->clave) == NULL) {
            l_agregar(valores_no_comunes, elemento_actual);
        }
    }

    return valores_no_comunes;
}

int main() {
    Lista lista1 = l_crear();
    Lista lista2 = l_crear();
    int inputNumber;
    char inputChar;
    bool seguirAgregando = true;
    bool seguirAgregando2 = true;

    printf("[INPUT] Agregar valores a lista1:\n");
    while(seguirAgregando){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(lista1, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }

    printf("[INPUT] Agregar valores a lista2:\n");
    while(seguirAgregando2){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(lista2, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando2 = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }
    
    Lista valores_no_en_L1_arreglo = valores_no_en_L1(lista1, lista2);
    printf("[OUTPUT] Valores de lista2 que no estan en lista1 (Lista): ");
    l_mostrar(valores_no_en_L1_arreglo);
    fflush(stdin);

    return 0;
}
