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

    if(nodo->datos->clave == clave){
        l_agregar(resultado, te_crear_con_valor(nodo->datos->clave,(void*)nodo));
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
    NodoArbol raiz = a_establecer_raiz(arbol, te_crear(5));
    NodoArbol hijoIzquierdoRaiz =  a_conectar_hi(arbol, raiz, te_crear(2));
    NodoArbol hijoDerechoRaiz =  a_conectar_hd(arbol, raiz, te_crear(8));
    NodoArbol hijoIzquierdo1 =  a_conectar_hi(arbol, hijoIzquierdoRaiz, te_crear(7));
    NodoArbol hijoDerecho1 =  a_conectar_hd(arbol, hijoIzquierdoRaiz, te_crear(2));
    NodoArbol hijoIzquierdo2 =  a_conectar_hi(arbol, hijoDerechoRaiz, te_crear(1));
    NodoArbol hijoDerecho2 =  a_conectar_hd(arbol, hijoDerechoRaiz, te_crear(6));

    Lista lista = a_ej2_buscarclave(arbol, 2);

    l_mostrar(lista);

    return 0;
}