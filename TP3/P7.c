#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"

// Dada dos pilas realizar una función que permita determinar los elementos que tienen
// en común. Debe retornar una nueva pila con esos elementos (que están en ambas
// pilas) sin perder las pilas originales. Determinar la complejidad algorítmica de la
// solución.
// Ejemplo: si “P1” contiene (1, 4, 7, 9, 8) y “P2” contiene (4,1,6,9,3) el resultado será la
// pila “PR” = (1,4,9).


void moverPila(Pila dest,Pila src){
    while (!p_es_vacia(src))
    {
        p_apilar(dest,p_desapilar(src));
    }    
}

Pila elementosComunes(Pila pila1, Pila pila2) {
    Pila pilaComun = p_crear();//crea la pila
    Pila pAux=p_crear();
    Pila pTmp=p_crear();

    
    while (!p_es_vacia(pila1)) {//si la variable esta vacia sale
        TipoElemento elemento1 = p_desapilar(pila1);
        
        while (!p_es_vacia(pila2)) {
            TipoElemento elemento2 = p_desapilar(pila2);
            p_apilar(pTmp,elemento2);
            p_apilar(pAux,elemento1);
            p_apilar(pAux,elemento2);
            if (elemento1->clave== elemento2->clave) {
                p_apilar(pilaComun,te_crear(elemento1->clave));
                break;     
            }

        } 
        moverPila(pila2,pTmp);
    }

    while (!(p_es_vacia(pAux))){
        TipoElemento elementoAux1 = p_desapilar(pAux);
        p_apilar(pila1, elementoAux1);
        TipoElemento elementoAux2 = p_desapilar(pAux);
        p_apilar(pila2, elementoAux2);
    }
    return pilaComun;
}


void cargarPila(Pila pila){
    bool seguirIngresando = true;
    int terminoElegido;
    char opcionSeguir;

    while (seguirIngresando){
        printf("[INPUT] Ingrese un elemento para agregar a la pila('n'para terminar de ingresar): ");
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
    Pila pilaComun=p_crear();
    // bool vaciaPilaComun=p_es_vacia(pilaComun);

    cargarPila(pila1);
    cargarPila(pila2);
    
    printf("[INFO] La pila 1 es: \n");
    p_mostrar(pila1);
    printf("[INFO] La pila 2 es: \n");
    p_mostrar(pila2);

    pilaComun = elementosComunes(pila1, pila2);
    
    // Imprimir los elementos comunes
    printf("[OUTPUT] Elementos comunes entre las pilas: \n");
    
    p_mostrar(pilaComun);
    
    printf("\n");

    system("pause");
    
    return 0;
}
