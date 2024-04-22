/*
Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la
clave), sin destruirlas. Utilizar para la resolución del problema una única pila auxiliar.
Determinar la complejidad algorítmica de la solución.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"

bool p_ej3_iguales(Pila p1, Pila p2){
    Pila pAux = p_crear();
    bool vaciaP1 = p_es_vacia(p1);
    bool vaciaP2 = p_es_vacia(p2);
    bool respuesta = true;

    while (respuesta && ((!vaciaP1) || (!vaciaP2))){
        TipoElemento elemento1 = p_desapilar(p1);
        TipoElemento elemento2 = p_desapilar(p2);
        if (elemento1->clave == elemento2->clave){
            p_apilar(pAux, elemento1);
            p_apilar(pAux, elemento2);
            vaciaP1 = p_es_vacia(p1);
            vaciaP2 = p_es_vacia(p2);
        }
        else{
            respuesta= false;
        }
    }

    while (!(p_es_vacia(pAux))){
        TipoElemento elementoAux1 = p_desapilar(pAux);
        p_apilar(p2, elementoAux1);
        TipoElemento elementoAux2 = p_desapilar(pAux);
        p_apilar(p1, elementoAux2);
    }

    return respuesta;
}

void cargarPila(Pila pila){
    bool seguirIngresando = true;
    int terminoElegido;
    char opcionSeguir;

    while (seguirIngresando){
        printf("[INPUT] Ingrese un elemento para agregar a la pila o 'n' para terminar: ");
        if (scanf("%i", &terminoElegido)>0){
            p_apilar(pila, te_crear(terminoElegido));
            printf("[INFO] Agregado!\n");
        }
        else{
            if (scanf("%c", &opcionSeguir)>0 && opcionSeguir == 'n'){
                printf("[INFO] Finalizando carga de la pila.\n");
                seguirIngresando = false;
            }
            else{
                printf("[ERROR] Debe ingresar un numero.\n");
            }
            fflush(stdin);
        }
    }
}

int main(){
    Pila pila1 = p_crear();
    Pila pila2 = p_crear();

    cargarPila(pila1);
    cargarPila(pila2);
    
    printf("[INFO] Pila 1: \n");
    p_mostrar(pila1);
    printf("[INFO] Pila 2: \n");
    p_mostrar(pila2);
    
    bool respuesta = p_ej3_iguales(pila1, pila2);

    if (respuesta){
        printf("[OUTPUT] Las pilas son iguales.\n");
    }
    else{
        printf("[OUTPUT] Las pilas no son iguales.\n");
    }

    system("pause");

    return 0;
}