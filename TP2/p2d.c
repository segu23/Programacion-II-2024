/*
D.Que retorne los promedios de ambas listas.
*/
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"


float promedio_lista1(Lista lista1){
    float promedio=0.0;
    float resultado=0.0;
    Iterador iter = iterador(lista1);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        float valor_actual;
        valor_actual=elemento_actual->clave;
        resultado+=valor_actual;
    }
    promedio=resultado/l_longitud(lista1);
    return promedio;
}

float promedio_lista2(Lista lista2){
    float promedio=0.0;
    float resultado=0.0;
    Iterador iter = iterador(lista2);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        float valor_actual;
        valor_actual=elemento_actual->clave;
        resultado+=valor_actual;
    }
    promedio=resultado/l_longitud(lista2);
    return promedio;
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

    float promedio1 = promedio_lista1(lista1);
    float promedio2 = promedio_lista2(lista2);
    printf("[OUTPUT] Promedio Lista 1: %.2f \n", promedio1);
    printf("[OUTPUT] Promedio Lista 2: %.2f \n",promedio2);
    fflush(stdin);

    return 0;
}
