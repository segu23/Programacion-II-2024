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

//d.	Calcular el nivel en el que se encuentra.
int a_ej3_nivel(ArbolAVL A, int clave){
    int nivel = 0;
    NodoArbol actual = A->raiz;

    while (actual != NULL) {
        if (actual->datos->clave == clave) {
            return nivel;
        } else if (clave < actual->datos->clave) {
            actual = actual->hi;
        } else {
            actual = actual->hd;
        }
        nivel++;
    }

    // Si el nodo no se encuentra en el árbol, devolver -1
    return -1;
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

    printf("Ingrese el nodo para saber el nivel en que se encuentra: ");
    scanf("%d",&clave);

    int claveNodo=a_ej3_nivel(arbolA,clave);

    if(claveNodo==-1){
        printf("El nodo no existe.");
    }
    else
    {
        printf("El hermano de %d es %d ",clave,claveNodo);
    }
}
