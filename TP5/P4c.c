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

bool compararArboles(NodoArbol nodo1,NodoArbol nodo2){
    NodoArbol hijoIzquierdoNodo1 = n_hijoizquierdo(nodo1);
    NodoArbol hijoDerechoNodo1 = n_hijoderecho(nodo1);

    NodoArbol hijoIzquierdoNodo2 = n_hijoizquierdo(nodo2);
    NodoArbol hijoDerechoNodo2 = n_hijoderecho(nodo2);

    bool validoIzquierda = false;
    bool validoDerecha = false;

    if (!a_es_rama_nula(hijoIzquierdoNodo1) && !a_es_rama_nula(hijoIzquierdoNodo2)){
        validoIzquierda = compararArboles(hijoIzquierdoNodo1, hijoIzquierdoNodo2);
    }else{
        validoIzquierda = (a_es_rama_nula(hijoIzquierdoNodo1) && a_es_rama_nula(hijoIzquierdoNodo2));
    }
        
    if (!a_es_rama_nula(hijoDerechoNodo1) && !a_es_rama_nula(hijoDerechoNodo2)){
        validoDerecha = compararArboles(hijoDerechoNodo1, hijoDerechoNodo2);
    }else{
        validoDerecha = (a_es_rama_nula(hijoDerechoNodo1) && a_es_rama_nula(hijoDerechoNodo2));
    }

    return validoIzquierda && validoDerecha;
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B){
    NodoArbol raizA = a_raiz(A);
    NodoArbol raizB = a_raiz(B);
    
    return compararArboles(raizA,raizB);
}

int main(){
    ArbolBinario arbolA = a_crear();
    NodoArbol a = a_establecer_raiz(arbolA, te_crear_con_valor(1,(void*)'a'));
    NodoArbol b =  a_conectar_hi(arbolA, a, te_crear_con_valor(2,(void*)'b'));
    NodoArbol c =  a_conectar_hd(arbolA, b, te_crear_con_valor(3,(void*)'c'));
    NodoArbol d =  a_conectar_hd(arbolA, c, te_crear_con_valor(4,(void*)'d'));
    NodoArbol e =  a_conectar_hi(arbolA, b, te_crear_con_valor(5,(void*)'e'));
    NodoArbol f =  a_conectar_hi(arbolA, e, te_crear_con_valor(6,(void*)'f'));
    NodoArbol g =  a_conectar_hi(arbolA, d, te_crear_con_valor(7,(void*)'g'));
    NodoArbol h =  a_conectar_hd(arbolA, g, te_crear_con_valor(8,(void*)'h'));
    NodoArbol i =  a_conectar_hd(arbolA, h, te_crear_con_valor(9,(void*)'i'));
    NodoArbol j =  a_conectar_hi(arbolA, i, te_crear_con_valor(10,(void*)'j'));

    ArbolBinario arbolB=a_crear();
    NodoArbol a1 = a_establecer_raiz(arbolB, te_crear_con_valor(1,(void*)'a'));
    NodoArbol b1 =  a_conectar_hi(arbolB, a1, te_crear_con_valor(2,(void*)'b'));
    NodoArbol c1 =  a_conectar_hd(arbolB, b1, te_crear_con_valor(3,(void*)'c'));
    NodoArbol d1 =  a_conectar_hd(arbolB, c1, te_crear_con_valor(4,(void*)'d'));
    NodoArbol e1 =  a_conectar_hi(arbolB, b1, te_crear_con_valor(5,(void*)'e'));
    NodoArbol f1 =  a_conectar_hi(arbolB, e1, te_crear_con_valor(6,(void*)'f'));
    NodoArbol g1 =  a_conectar_hi(arbolB, d1, te_crear_con_valor(7,(void*)'g'));
    NodoArbol h1 =  a_conectar_hd(arbolB, g1, te_crear_con_valor(8,(void*)'h'));
    NodoArbol i1 =  a_conectar_hd(arbolB, h1, te_crear_con_valor(9,(void*)'i'));
    NodoArbol j1 =  a_conectar_hi(arbolB, i1, te_crear_con_valor(10,(void*)'j'));

    if (a_ej4_similares(arbolA,arbolB)){
        printf("Los arboles son similares");
    }
    else{
        printf("Los arboles NO son similares");
    }

    return 0;


}