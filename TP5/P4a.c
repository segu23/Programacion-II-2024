#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "colas.h"

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

int ingresoEntero(int* n){
    char s[10];
    int resultado =0;
    *n=0;
    printf("[INPUT] Ingrese una clave numerica o '.' para nulo: ");
    scanf("%s", s);
    if (s[0]=='.'){
        resultado = 1;
    }else{
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i]>='0')&&(s[i]<='9')){
                *n = *n * 10 + (s[i] - 48);}
            else{resultado=2;}
        }
    }
    return resultado;
}

void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    int b;
    if(!a_es_lleno(A)){
        if(sa == -1) {
                printf("[INPUT] Ingrese el hijo izquierdo de %i.\n", N->datos->clave);
            }
            else if(sa == 1) {
                printf("[INPUT] Ingrese el hijo derecho de %i.\n", N->datos->clave);
            }
            else {
                printf("[INPUT] Ingrese la raiz.\n");
            }
        b= ingresoEntero(&n);
        if (b==0){
            X= te_crear(n);

            if(sa == -1) {
                N1 = a_conectar_hi(A, N, X);
            }
            else if(sa == 1) {
                N1 = a_conectar_hd(A, N, X);
            }
            else {
                N1 = a_establecer_raiz(A, X);
            }

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }else if(b==2){
            printf("[ERROR] Entrada invalida (valor fuera de rango).\n");
            Cargar_SubArbol(A, N,sa);
        }
    }
}

void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
}

int main(){
    ArbolBinario arbol = a_crear();
    printf("[INFO] Cargando arbol...\n");
    cargar_arbol_binario(arbol);
    
    Lista lista = a_ej4_anchura(arbol);
    printf("\n[OUTPUT] El recorrido en anchura del arbol esta en la siguiente lista.\n");
    l_mostrar(lista);

    return 0;
}