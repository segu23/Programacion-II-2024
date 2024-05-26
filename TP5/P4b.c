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
#include "colas.h"
#include "colas_arreglos.c"

int auxiliares2(TipoElemento hermano){
    Cola C;
    NodoArbol N=hermano->valor;
    TipoElemento X;
    C=c_crear();
    Cola colaAux;
    colaAux=c_crear();
    int cantidad=0;
    X=te_crear_con_valor(0,N);
    c_encolar(C,X);
    while(!c_es_vacia(C)){
        X=c_desencolar(C);
        N=(NodoArbol)X->valor;

        if(a_es_rama_nula(n_hijoizquierdo(N))){
            c_encolar(colaAux,n_recuperar(N));

        }
        
        if(!a_es_rama_nula(n_hijoizquierdo(N))){
            X=te_crear_con_valor(0,n_hijoizquierdo(N));
            c_encolar(C,X);
        }

        if(!a_es_rama_nula(n_hijoderecho(N))){
            X=te_crear_con_valor(0,n_hijoderecho(N));
            c_encolar(C,X);
        }

    }
    while(!c_es_vacia(colaAux)){
        X=c_desencolar(colaAux);
        cantidad++;
    }
    return cantidad;
      
}
    
int a_ej4_q_hojas(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    int cantidad=0;
    TipoElemento elementoaux=te_crear_con_valor(0,raiz);
    cantidad=auxiliares2(elementoaux);

    return cantidad;
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

    int resultado=0;
    resultado = a_ej4_q_hojas(arbol);
    printf("La cantidad de nodos hojas es: %d ",resultado);
    return 0;
}