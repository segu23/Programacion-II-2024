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

//e.	Calcular la altura de su rama (Altura del Subárbol)
int calcularAltura(NodoArbol a){
    if(a==NULL){
        return -1;
    }
    else
    {
        int alturaIzquierda=calcularAltura(a->hi);
        int alturaDerecha=calcularAltura(a->hd);
        return 1+(alturaIzquierda>alturaDerecha ? alturaIzquierda:alturaDerecha);
    } 
}

int a_ej3_alturarama(ArbolAVL A, int clave){
    NodoArbol nodo = A->raiz;
    if (nodo != NULL) {
        return calcularAltura(nodo);
    } else {
        return -1; // Nodo no encontrado
    }
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

    printf("Ingrese la clave para buscar la altura de su rama: ");
    scanf("%d",&clave);

    int claveRama=a_ej3_alturarama(arbolA,clave);

    if(claveRama==-1){
        printf("La rama es nula.");
    }
    else
    {
        printf("La altura de la rama de %d es %d ",clave,claveRama);
    }
}