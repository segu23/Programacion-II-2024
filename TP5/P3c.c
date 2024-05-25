#include "arbol-avl.h"
#include "arbol-binario-busqueda.h"
#include "arbol-binario.h"
#include "nodo.h"
#include "tipo_elemento.h"
#include "listas.h"
#include "tp_arboles.h"

void imprimirArbol(NodoArbol raiz, int espacio) {
    // Definir la cantidad de espacio entre los niveles
    int COUNT = 10;

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

// c.	Listar el hermano (solo la clave).
int a_ej3_hermano(ArbolAVL A, int clave){
    if (A == NULL || A->raiz->datos->clave == clave) {
        // No hay hermano si el árbol es nulo o si la clave es la raíz
        return -2;
    }

    NodoArbol actual = A->raiz;
    NodoArbol padre = NULL;
    bool esIzquierdo=false;
    // Buscar el nodo con la clave dada y su padre
    while (actual != NULL && actual->datos->clave != clave) {
        padre = actual;
        if (clave < actual->datos->clave) {
            actual = actual->hi;
            esIzquierdo=true;
        } else {
            actual = actual->hd;
            esIzquierdo=false;
        }
    }
    if(padre->hd==NULL || padre->hi==NULL){
        return -1;
    }

    if(esIzquierdo){
        return padre->hd->datos->clave;
    }
    return padre->hi->datos->clave;
}


int main(){
    int elemento,index=1,raiz,clave=0;
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

    printf("Ingrese la clave para buscar el hermano: ");
    scanf("%d",&clave);

    int claveHermano=a_ej3_hermano(arbolA,clave);

    if(claveHermano==-1){
        printf("NO tiene hermano o la rama es nula.");
    }
    else if (claveHermano==-2)
    {
        printf("La rama es nula.");
    }
    
    else
    {
        printf("El hermano de %d es %d ",clave,claveHermano);
    }
}