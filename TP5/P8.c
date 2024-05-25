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

int c_ej8_altura(ArbolBinario A){
    NodoArbol raizA = a_raiz(A);

    return calcularAltura(raizA,1);
}

int calcularAltura(NodoArbol nodo, int profundidad){
    printf("%c-%i\n", (char)nodo->datos->valor, profundidad);

    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    int validoIzquierda = profundidad;
    int validoDerecha = profundidad;

    if (!a_es_rama_nula(hijoIzquierdoNodo)){
        validoIzquierda = calcularAltura(hijoIzquierdoNodo,profundidad+1);
    }

    if (!a_es_rama_nula(hijoDerechoNodo)){
        validoDerecha = calcularAltura(hijoDerechoNodo, profundidad);
    }

    return (validoIzquierda>validoDerecha? validoIzquierda : validoDerecha);
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

    int altura = c_ej8_altura(arbol);

    printf("La altura es %i", altura);
    
    return 0;
}