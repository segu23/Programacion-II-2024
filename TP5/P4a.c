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
    Cola C;
    //NodoArbol N=hermano->valor;
    TipoElemento X;
    C=c_crear();
    Cola colaAux;
    colaAux=c_crear();
    int cantidad=0;
    X=te_crear_con_valor(0,raiz);
    c_encolar(C,X);

    Lista lista1=l_crear();
    //l_agregar(lista1,n_recuperar(raiz));
    
    while(!c_es_vacia(C)){
        X=c_desencolar(C);
        raiz=(NodoArbol)X->valor;
        
        
        c_encolar(colaAux,X);

        /*if(a_es_rama_nula(n_hijoizquierdo(N))){
            c_encolar(colaAux,n_recuperar(N));

        }*/
        if(!a_es_rama_nula(n_hijoderecho(raiz))){
            while(!a_es_rama_nula(n_hijoderecho(raiz))){
                X=te_crear_con_valor(0,n_hijoderecho(raiz));
                //l_agregar(lista1,n_recuperar(n_hijoderecho(raiz)));
                c_encolar(C,X);
                X=c_desencolar(C);
                raiz=(NodoArbol)X->valor;

            }
            
        }

        
        
        if(!a_es_rama_nula(n_hijoizquierdo(raiz))){
            X=te_crear_con_valor(0,n_hijoizquierdo(raiz));
            //l_agregar(lista1,n_recuperar(n_hijoizquierdo(raiz)));
            c_encolar(C,X);
        }
        

        

    }
    /*
    while(!c_es_vacia(colaAux)){
        X=c_desencolar(colaAux);
        raiz=(NodoArbol)X->valor;
        l_agregar(lista1,n_recuperar(raiz));

    }*/

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
    l_mostrar(lista);

    return 0;

}