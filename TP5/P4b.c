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

    int resultado=0;
    resultado = a_ej4_q_hojas(arbol);
    printf("[OUTPUT] La cantidad de nodos hojas es: %d ",resultado);
    return 0;
}