#include "arbol-avl.h"
#include "nodo.h"
#include "tipo_elemento.h"
#include "tp_arboles.h"
#include <stdio.h>

void imprimirArbol(NodoArbol raiz, int espacio) {
    // Definir la cantidad de espacio entre los niveles
    int COUNT = 4;

    if (raiz == NULL) {
        return;
    }

    // Aumentar la distancia entre los niveles
    espacio += COUNT;

    // Procesar primero el subárbol derecho
    imprimirArbol(raiz->hd, espacio);

    // Imprimir el nodo actual después de los espacios COUNT
    printf("\n");
    for (int i = COUNT; i < espacio; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->datos->clave);

    // Procesar el subárbol izquierdo
    imprimirArbol(raiz->hi,espacio);
}

void mostrarArbol(ArbolAVL arbol) {
    NodoArbol raiz=arbol->raiz;
    imprimirArbol(raiz, 1);
}


// a.	Indicar el nombre del nodo padre (clave).
int a_ej3_clavepadre(ArbolAVL A, int clavehijo){
    
    if (A == NULL || A->raiz->datos->clave == clavehijo) {
        // No hay padre si el árbol es nulo o si la clave del hijo es la raíz
        return -1;  // Usamos -1 para indicar que no hay padre
    }

    NodoArbol actual = A->raiz;
    NodoArbol padre = NULL;

    while (actual != NULL && actual->datos->clave != clavehijo) {
        padre = actual;
        if (clavehijo < actual->datos->clave) {
            actual = actual->hi;
        } else {
            actual = actual->hd;
        }
    }

    if (actual == NULL) {
        // No se encontró el nodo con clavehijo
        return -1;  // Usamos -1 para indicar que el nodo no se encontró
    }
    if (padre != NULL){
        return padre->datos->clave;
    }
    else{
        return -1;
    }
}
int main(){
    int claveHijo=0,raiz=0,elemento=0,index=1;
    ArbolAVL arbolA = avl_crear();

    printf("Ingrese el nodo raiz: ");
    scanf("%d",&raiz);
    avl_insertar(arbolA,te_crear(raiz));

    printf("Ingrese los elementos: \n");
    while (true)
    {
        printf("Nodo %d (-1 para dejar de ingresar):",index);
        scanf("%d",&elemento);

        if (elemento==-1)
        {
            break;
        }
        index++;
        avl_insertar(arbolA,te_crear(elemento));

    }
    mostrarArbol(arbolA);
    
    printf("Ingrese el nodo hijo para buscar el padre: ");
    scanf("%d",&claveHijo);

    int padre=a_ej3_clavepadre(arbolA,claveHijo);

    if(padre == -1){

        printf("La raiz no tiene padre o el nodo no se encuentra");
    }
    else{
        printf("El padre es: %d",padre);
    }
}
