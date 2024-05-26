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

void auxiliares2(TipoElemento hermano,Lista lista2){
    Cola C;
    NodoArbol N=hermano->valor;
    TipoElemento X;
    C=c_crear();
    X=te_crear_con_valor(0,N);
    c_encolar(C,X);
    while(!c_es_vacia(C)){
        X=c_desencolar(C);
        N=(NodoArbol)X->valor;
        
        l_agregar(lista2,n_recuperar(N));
        if(!a_es_rama_nula(n_hijoderecho(N))){
            X=te_crear_con_valor(0,n_hijoderecho(N));
            c_encolar(C,X);
        }

    }
      
}

void auxiliares1(NodoArbol nodo,NodoArbol nodoaux,int clave,Lista lista1){
    NodoArbol hijoIzquierdo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerecho = n_hijoderecho(nodo);


    if(nodo->datos->clave==clave){
        
        l_agregar(lista1,te_crear_con_valor(0,n_hijoizquierdo(nodoaux)));
        
    }else{
        if (!a_es_rama_nula(hijoIzquierdo)){
            if (!a_es_rama_nula(hijoDerecho)){
                auxiliares1(hijoDerecho,nodoaux,clave,lista1);
            }
            nodoaux=nodo;
            
            auxiliares1(hijoIzquierdo,nodoaux,clave,lista1);
        }
        if (!a_es_rama_nula(hijoDerecho)){
            auxiliares1(hijoDerecho,nodoaux,clave,lista1);
        }

    }
       
}

Lista a_ej4_hermanos(ArbolBinario A, int clave){
    
    NodoArbol raiz = a_raiz(A);
    Lista lista1=l_crear();
    auxiliares1(raiz, raiz, clave,lista1);
    TipoElemento hermano=te_crear_con_valor(0,NULL);
    hermano=l_recuperar(lista1,1);
    Lista lista2=l_crear();
    auxiliares2(hermano,lista2);
    
    return lista2;
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

    Lista her=a_ej4_hermanos(arbol,4);

    l_mostrar(her);

    return 0;
}