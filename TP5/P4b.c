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

void recorrerNodo(NodoArbol nodo, Lista resultado, int clave){
    NodoArbol hijoIzquierdo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerecho = n_hijoderecho(nodo);

    if(a_es_rama_nula(hijoIzquierdo)){
        l_agregar(resultado, te_crear(nodo->datos->clave));
    }
    
    if (!a_es_rama_nula(hijoIzquierdo)){
        recorrerNodo(hijoIzquierdo,resultado,clave);
    }
    if (!a_es_rama_nula(hijoDerecho)){
        recorrerNodo(hijoDerecho,resultado,clave);
    }
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);
    Lista resultado = l_crear();
    recorrerNodo(raiz, resultado, clave);

    return resultado;
}

int main(){
    ArbolBinario arbol = a_crear();
    NodoArbol a = a_establecer_raiz(arbol, te_crear_con_valor(1,(void*)'a'));
    NodoArbol b =  a_conectar_hi(arbol, a, te_crear_con_valor(2,(void*)'b'));
    NodoArbol c =  a_conectar_hd(arbol, b, te_crear_con_valor(3,(void*)'c'));
    NodoArbol d =  a_conectar_hd(arbol, c, te_crear_con_valor(4,(void*)'d'));
    NodoArbol e =  a_conectar_hi(arbol, b, te_crear_con_valor(5,(void*)'e'));
    NodoArbol f =  a_conectar_hi(arbol, e, te_crear_con_valor(6,(void*)'f'));
    NodoArbol g =  a_conectar_hi(arbol, d, te_crear_con_valor(7,(void*)'g'));
    NodoArbol h =  a_conectar_hd(arbol, g, te_crear_con_valor(8,(void*)'h'));
    NodoArbol i =  a_conectar_hd(arbol, h, te_crear_con_valor(9,(void*)'i'));
    NodoArbol j =  a_conectar_hi(arbol, i, te_crear_con_valor(10,(void*)'j'));

    Lista lista = a_ej2_buscarclave(arbol, 2);

    l_mostrar(lista);



    return 0;
}