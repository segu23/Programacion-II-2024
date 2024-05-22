#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"
#include "arbol-binario.c"
#include "nodo.c"

bool compararNodos(NodoArbol nodo1,NodoArbol nodo2){
    NodoArbol hijoIzquierdoNodo1 = n_hijoizquierdo(nodo1);
    NodoArbol hijoDerechoNodo1 = n_hijoderecho(nodo1);
    NodoArbol hijoIzquierdoNodo2 = n_hijoizquierdo(nodo2);
    NodoArbol hijoDerechoNodo2 = n_hijoderecho(nodo2);

    bool validoIzquierda = false;
    bool validoDerecha = false;

    if (nodo1->datos->clave == nodo2->datos->clave){
        //Es valido si las dos son ramas
        if (!a_es_rama_nula(hijoIzquierdoNodo1) && !a_es_rama_nula(hijoIzquierdoNodo2)){
            validoIzquierda = compararNodos(hijoIzquierdoNodo1, hijoIzquierdoNodo2);
        }
        //Es valido si las dos son hojas
        else{
            validoIzquierda = (a_es_rama_nula(hijoIzquierdoNodo1) && a_es_rama_nula(hijoIzquierdoNodo2));
        }
        //Hacemos lo mismo para la derecha
        if (!a_es_rama_nula(hijoDerechoNodo1) && !a_es_rama_nula(hijoDerechoNodo2)){
            validoDerecha = compararNodos(hijoDerechoNodo1, hijoDerechoNodo2);
        }
        else{
            validoDerecha = (a_es_rama_nula(hijoDerechoNodo1) && a_es_rama_nula(hijoDerechoNodo2));
        }

        return validoIzquierda && validoDerecha;
    }
    else{
        return false;
    }
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){
    NodoArbol raizA = a_raiz(A);
    NodoArbol raizB = a_raiz(B);
    
    return compararNodos(raizA,raizB);
}

int main(){
    ArbolBinario arbolA = a_crear();
    NodoArbol raizA = a_establecer_raiz(arbolA, te_crear(4));
    NodoArbol hijoIzquierdoRaizA =  a_conectar_hi(arbolA, raizA, te_crear(2));
    NodoArbol hijoDerechoRaizA =  a_conectar_hd(arbolA, raizA, te_crear(8));
    NodoArbol hijoIzquierdo1A =  a_conectar_hi(arbolA, hijoIzquierdoRaizA, te_crear(7));
    NodoArbol hijoDerecho1A =  a_conectar_hd(arbolA, hijoIzquierdoRaizA, te_crear(2));
    NodoArbol hijoIzquierdo2A =  a_conectar_hi(arbolA, hijoDerechoRaizA, te_crear(1));
    NodoArbol hijoDerecho2A =  a_conectar_hd(arbolA, hijoDerechoRaizA, te_crear(6));
 
    ArbolBinario arbolB = a_crear();
    NodoArbol raizB = a_establecer_raiz(arbolB, te_crear(4));
    NodoArbol hijoIzquierdoRaizB =  a_conectar_hi(arbolB, raizB, te_crear(2));
    NodoArbol hijoDerechoRaizB =  a_conectar_hd(arbolB, raizB, te_crear(8));
    NodoArbol hijoIzquierdo1B =  a_conectar_hi(arbolB, hijoIzquierdoRaizB, te_crear(7));
    NodoArbol hijoDerecho1B =  a_conectar_hd(arbolB, hijoIzquierdoRaizB, te_crear(2));
    NodoArbol hijoIzquierdo2B =  a_conectar_hi(arbolB, hijoDerechoRaizB, te_crear(1));
    NodoArbol hijoDerecho2B =  a_conectar_hd(arbolB, hijoDerechoRaizB, te_crear(6));

    if (a_ej7_equivalente(arbolA,arbolB)){
        printf("Tus arboles son equivalentes");
    }
    else{
        printf("Tus arboles no son equivalentes");
    }

    return 0;
}