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
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "colas.h"
#include "colas_arreglos.c"

Lista a_ej4_anchura(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    NodoArbol raiz1 = a_raiz(A);
    Cola C;
    TipoElemento Xd;
    TipoElemento Xi;
    C=c_crear();
    Cola colaDe;
    colaDe=c_crear();
    Cola colaIz;
    colaIz=c_crear();
    Xd=te_crear_con_valor(0,n_hijoizquierdo(raiz));
    c_encolar(colaIz,Xd);

    Lista lista1=l_crear();
    l_agregar(lista1,n_recuperar(raiz));

    while(!c_es_vacia(colaDe)||!c_es_vacia(colaIz)){
        Xd=c_desencolar(colaIz);
        raiz=(NodoArbol)Xd->valor;
        l_agregar(lista1,n_recuperar(raiz));
        while(!a_es_rama_nula(n_hijoderecho(raiz))){
            l_agregar(lista1,n_recuperar(n_hijoderecho(raiz)));
            if(!a_es_rama_nula(n_hijoizquierdo(raiz))){
                Xi=te_crear_con_valor(0,n_hijoizquierdo(raiz));
                c_encolar(colaIz,Xi);
            }
            Xd=te_crear_con_valor(0,n_hijoderecho(raiz));
            raiz=(NodoArbol)Xd->valor;
        }
        if(!a_es_rama_nula(n_hijoizquierdo(raiz))){
            Xi=te_crear_con_valor(0,n_hijoizquierdo(raiz));
            c_encolar(colaIz,Xi);
        }
    }
    
    return lista1;

}

int main(){
    ArbolBinario arbol = a_crear();
    NodoArbol a = a_establecer_raiz(arbol, te_crear(1));
    NodoArbol b =  a_conectar_hi(arbol, a, te_crear(2));
    NodoArbol c =  a_conectar_hd(arbol, b, te_crear(3));
    NodoArbol d =  a_conectar_hd(arbol, c, te_crear(4));
    NodoArbol e =  a_conectar_hi(arbol, b, te_crear(5));
    NodoArbol f =  a_conectar_hi(arbol, e, te_crear(6));
    NodoArbol g =  a_conectar_hi(arbol, d, te_crear(7));
    NodoArbol h =  a_conectar_hd(arbol, g, te_crear(8));
    NodoArbol i =  a_conectar_hd(arbol, h, te_crear(9));
    NodoArbol j =  a_conectar_hi(arbol, i, te_crear(10));
    

    Lista lista=a_ej4_anchura(arbol);
    printf("El recorrido en anchura del arbol es:\n");
    l_mostrar(lista);

    return 0;

}