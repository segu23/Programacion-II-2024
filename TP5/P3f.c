#include "arbol-avl.h"
#include "nodo.h"
#include "tipo_elemento.h"
#include "listas.h"
#include "tp_arboles.h"
#include "arbol-avl.c"
#include "nodo.c"
#include "tipo_elemento.c"
#include "listas_punteros.c"

ArbolAVL cargarArbol(ArbolAVL arbol){
    



}


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

// f.	Listar todos los nodos que están en el mismo nivel (solo la clave).
// Función para calcular la altura de un nodo
void listarNodosEnNivel(ArbolAVL arbol, int nivelActual, int nivelObjetivo, Lista lista) {
    ArbolAVL arbolIzquierdo=avl_crear();
    ArbolAVL arbolDerecho=avl_crear();
    NodoArbol nodo=arbol->raiz;

    arbolIzquierdo->raiz=nodo->hi;
    arbolDerecho->raiz=nodo->hd;
   
    if (nivelActual == nivelObjetivo) {
        l_agregar(lista, te_crear(nodo->datos->clave));
        return;
    } 
    if (arbolDerecho->raiz==NULL && arbolIzquierdo->raiz==NULL){
        return;
    }
    else {
        listarNodosEnNivel(arbolDerecho, nivelActual + 1, nivelObjetivo, lista);
        listarNodosEnNivel(arbolIzquierdo, nivelActual + 1, nivelObjetivo, lista);
        
    }
}

// Función principal para listar nodos en un nivel dado
Lista a_ej3_clavesmismonivel(ArbolAVL A, int nivel) {
    Lista lista=l_crear();
    if(A!=NULL){
        listarNodosEnNivel(A, 0, nivel, lista);
    }
    return lista;
}

int main(){
    int elemento,index=1,raiz,nivel=0;

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

    printf("Ingrese el nivel para buscar los elementos(la raiz es el nivel 0): ");
    scanf("%d",&nivel);

    Lista claveNivel=l_crear();
    claveNivel=a_ej3_clavesmismonivel(arbolA,nivel);

    if(l_es_vacia(claveNivel)){
        printf("No hay elemntos en ese nivel. ");
    }
    else{
        l_mostrar(claveNivel);
    }
}