/*
E. Que retorne el valor máximo de ambas listas y su posición ordinal. 
*/

#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"


int valor_max(Lista lista1, int primer_ingreso){
    int maximo= primer_ingreso;
    int pos1=1;

    Iterador iter = iterador(lista1);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        if (maximo<elemento_actual->clave){
            maximo=elemento_actual->clave;
            pos1=iter->posicionActual;
        }
        
    }
    printf("[OUTPUT]Posicion del Maximo de la Lista 1: %d \n",pos1);
    return maximo;
}

int valor_max2(Lista lista2, int primer_ingreso2){
    int maximo2= primer_ingreso2;
    int pos2=1;

    Iterador iter = iterador(lista2);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        if (maximo2<elemento_actual->clave){
            maximo2=elemento_actual->clave;
            pos2=iter->posicionActual;
        }   
    }
    printf("[OUTPUT]Posicion del Maximo de la Lista 2: %d \n",pos2);
    return maximo2;
}


int main() {
    Lista lista1 = l_crear();
    Lista lista2 = l_crear();
    int primer_ingreso;
    int primer_ingreso2;
    int flag2=0;
    int flag=0;
    int inputNumber;
    char inputChar;
    bool seguirAgregando = true;
    bool seguirAgregando2 = true;

    printf("[INPUT] Agregar valores a lista1:\n");
    while(seguirAgregando){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(lista1, te_crear(inputNumber));
            if(flag==0){
                primer_ingreso=inputNumber;
                flag=1;
            }
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
            if(flag2==0){
                primer_ingreso2=inputNumber;
                flag2=1;
            }
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

        int valor_m1 = valor_max(lista1,primer_ingreso);
        int valor_m2 = valor_max2(lista2,primer_ingreso2);
        printf("[OUTPUT]Maximo Lista 1: %d\n",valor_m1);
        printf("[OUTPUT]Maximo Lista 2: %d \n",valor_m2);
       
        return 0;
}