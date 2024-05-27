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

void auxiliares2(TipoElemento hermano,Lista lista2,int clave){
    Cola C;
    NodoArbol N=hermano->valor;
    TipoElemento X;
    C=c_crear();
    X=te_crear_con_valor(0,N);
    c_encolar(C,X);
    while(!c_es_vacia(C)){
        X=c_desencolar(C);
        N=(NodoArbol)X->valor;
        
        if(n_recuperar(N)->clave!=clave){
            l_agregar(lista2,n_recuperar(N));
        }
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
    auxiliares2(hermano,lista2,clave);
    
    
    return lista2;
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
   
    int nodo; 
    printf("\n[INPUT] Selecciona un nodo para buscar a sus nodos hermanos: ");
    scanf("%i", &nodo);

    Lista her=a_ej4_hermanos(arbol,nodo);

    if (l_es_vacia(her)){
        printf("\n[ERROR] El nodo seleccionado no tiene hermanos.\n");
    }
    else{
        printf("\n[OUTPUT] Los nodos hermanos del nodo seleccionado estan en la siguiente lista.\n");
        l_mostrar(her);
    }

    return 0;
}