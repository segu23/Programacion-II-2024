#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "tipo_elemento.c"
#include "pilas_punteros.c"

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.

    retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
    Si la pila estavacia retorna pila vacia.
    Ejemplo: si “P” contiene (1, 2,1, 3, 4, 5, 2, 1, 3, 5, 5), la pila resultado del proceso será
    “PR” = (1:3, 2:2, 3:2, 4:1, 5:3). */
Pila p_ej8_sacarrepetidos(Pila p){
    Pila aux = p_crear();
    Pila aux2 = p_crear();
    Pila pRespuesta = p_crear();

    int amount = 0;

    while(!p_es_vacia(p)){
        TipoElemento tipoElemento = p_desapilar(p);
        p_apilar(aux, tipoElemento);
        p_apilar(aux2, tipoElemento);
        amount++;
    }

    while(!p_es_vacia(aux2)){
        p_apilar(p, p_desapilar(aux2));
    }

    int index = 0;
    while(!p_es_vacia(aux) && index < amount){
        int apariciones = 1;
        TipoElemento tipoElemento = p_desapilar(aux);
        int clave = tipoElemento->clave;
        index++;
        while(!p_es_vacia(aux)){
            TipoElemento tipoElemento2 = p_desapilar(aux);
            if(tipoElemento2->clave == clave){
                apariciones++;
            }else{
                p_apilar(aux2, tipoElemento2);
            }
        }
        p_apilar(pRespuesta, te_crear_con_valor(clave, (void*) apariciones));
        while(!p_es_vacia(aux2)){
            p_apilar(aux, p_desapilar(aux2));
        }
    }

    return pRespuesta;
}

int main(){
    Pila pila = p_crear();

    bool seguirAgregando = true;
    int index = 1;
    int IngresoNumero;
    char inputChar;

    while(seguirAgregando){
        printf("[INPUT] Ingrese el #%i elemento de la pila o 'n' para terminar: ", index);

        if(scanf("%d", &IngresoNumero) > 0 && IngresoNumero > 0){
            p_apilar(pila, te_crear(IngresoNumero));
            index++;
        }
        else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Ingreso de la pila terminado.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }

    printf("[INFO] Pila ingresada: \n");
    p_mostrar(pila);
    Pila pilaSinRepetidos = p_ej8_sacarrepetidos(pila);
    printf("[INFO] Pila original despues de procesarla: \n");
    p_mostrar(pila);
    printf("[OUTPUT] PilaResultado: clave:apariciones = (");

    while(!p_es_vacia(pilaSinRepetidos)){
        TipoElemento elemento = p_desapilar(pilaSinRepetidos);
        printf("%i:%i, ", elemento->clave, (int) elemento->valor);
    }
    
    printf(")");

    return 0;
}