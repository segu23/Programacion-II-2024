#include "arbol-avl.h"
#include "arbol-avl.c"
#include "listas.h"
#include "tp_arboles.h"

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

Lista a_ej3_hijos(ArbolAVL A, int clavepadre){
    if (A == NULL) {
        return NULL;
    }

    Lista hijos = l_crear();  // Asumimos que un nodo puede tener como máximo 2 hijos en un árbol binario


    NodoArbol actual = A->raiz;
    while (actual != NULL && actual->datos->clave != clavepadre) {
        if (clavepadre < actual->datos->clave) {
            actual = actual->hi;
        } else {
            actual = actual->hd;
        }
    }
    if (actual != NULL) {
        bool tieneHijos=false;
        if (actual->hi != NULL) {
            l_agregar(hijos, te_crear(actual->hi->datos->clave));
            tieneHijos=true;
        }
        if (actual->hd != NULL) {
            l_agregar(hijos, te_crear(actual->hd->datos->clave));
            tieneHijos=true;
        }
        if (tieneHijos==false)
        {
            printf("No tiene hijos.");
        }   
    }
    return hijos;
}

int main(){
    int clavePadre=0,raiz=0,index=1,elemento;
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

    printf("Ingrese un numero de los nodos pra saber cules son los hijos: ");
    scanf("%d",&clavePadre);

    Lista hijos=l_crear();
    hijos=a_ej3_hijos(arbolA,clavePadre);

    if (!l_es_vacia(hijos)){
        l_mostrar(hijos);
    }
}