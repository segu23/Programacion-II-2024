#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"



void auxiliares1(NodoArbol nodo,NodoArbol nodoaux,int clave,Lista lista1){
    NodoArbol hijoIzquierdo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerecho = n_hijoderecho(nodo);


    if(nodo->datos->clave==clave){
        l_agregar(lista1,n_recuperar(nodoaux));
        
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

TipoElemento a_ej4_padre(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);
    Lista lista1=l_crear();
    auxiliares1(raiz, raiz, clave,lista1);
    TipoElemento resultado=l_recuperar(lista1,1);
    
    
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
    ArbolBinario arbol = a_crear();
    printf("[INFO] Cargando arbol...\n");
    cargar_arbol_binario(arbol);

    TipoElemento padreNodo=te_crear(0);

    bool seguirAgregando = true;
    int nodoHijo;

    while(seguirAgregando){
        printf("\n[INPUT] Selecciona un nodo para buscar a sus nodos hermanos: ");

        if(scanf("%i", &nodoHijo) > 0 && nodoHijo >= 0){
            seguirAgregando = false;
        }
        else{
            printf("[ERROR] Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    padreNodo=a_ej4_padre(arbol, nodoHijo);
    
    if (padreNodo != NULL){
        printf("[OUTPUT] El padre del nodo seleccionado es: %i\n", padreNodo->clave);
    }
    else{
        printf("[ERROR] No se pudo encontrar el padre del nodo que seleccionaste.\n");
    }
    
    return 0;
}