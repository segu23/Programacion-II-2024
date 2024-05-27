#include "arbol-binario.h"
#include "listas.h"
#include "nodo.h"
#include "tipo_elemento.h"
#include "tp_arboles.h"
#include <stdbool.h>

void agregarHijos(NodoArbol nodo, Lista resultado, int clavePadre, bool hijo){
    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    if(nodo->datos->clave == clavePadre) hijo = true;

    if(hijo){
        if(!a_es_rama_nula(hijoIzquierdoNodo)){
            l_agregar(resultado, te_crear(hijoIzquierdoNodo->datos->clave));
        }
        if(!a_es_rama_nula(hijoDerechoNodo)){
            l_agregar(resultado, te_crear(hijoDerechoNodo->datos->clave));
        }
    }

    if(!a_es_rama_nula(hijoIzquierdoNodo)){
        agregarHijos(hijoIzquierdoNodo, resultado, clavePadre, hijo);
    }
    if(!a_es_rama_nula(hijoDerechoNodo)){
        agregarHijos(hijoDerechoNodo, resultado, clavePadre, hijo);
    }
}

Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    Lista resultado = l_crear();
    NodoArbol raiz = a_raiz(A);

    agregarHijos(raiz, resultado, clavepadre, false);

    return resultado;
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
    ArbolBinario arbolA = a_crear();
    cargar_arbol_binario(arbolA);

    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        printf("[INPUT] Ingrese la clave a buscar: ");

        if(scanf("%d", &clave) > 0 && clave >= 0){
            seguirAgregando = false;
        }
        else{
            printf("[ERROR] Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    Lista hijos = a_ej3_hijos(arbolA, clave);

    if (!l_es_vacia(hijos)){
        printf("[OUTPUT] Los hijos de la clave buscada estan en la siguiente lista.\n");
        l_mostrar(hijos);
    }
    else{
        printf("[OUTPUT] La clave no se encontro o no tiene hijos.");
    }

    return 0;
}