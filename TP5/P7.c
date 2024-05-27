#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"

bool compararNodos(NodoArbol nodo1,NodoArbol nodo2){
    NodoArbol hijoIzquierdoNodo1 = n_hijoizquierdo(nodo1);
    NodoArbol hijoDerechoNodo1 = n_hijoderecho(nodo1);
    NodoArbol hijoIzquierdoNodo2 = n_hijoizquierdo(nodo2);
    NodoArbol hijoDerechoNodo2 = n_hijoderecho(nodo2);

    bool validoIzquierda = false;
    bool validoDerecha = false;

    if (nodo1->datos->clave == nodo2->datos->clave){
        //Es valido si las dos son ramas
        if (!a_es_rama_nula(hijoIzquierdoNodo1) && !a_es_rama_nula(hijoIzquierdoNodo2)){
            validoIzquierda = compararNodos(hijoIzquierdoNodo1, hijoIzquierdoNodo2);
        }
        //Es valido si las dos son hojas
        else{
            validoIzquierda = (a_es_rama_nula(hijoIzquierdoNodo1) && a_es_rama_nula(hijoIzquierdoNodo2));
        }
        //Hacemos lo mismo para la derecha
        if (!a_es_rama_nula(hijoDerechoNodo1) && !a_es_rama_nula(hijoDerechoNodo2)){
            validoDerecha = compararNodos(hijoDerechoNodo1, hijoDerechoNodo2);
        }
        else{
            validoDerecha = (a_es_rama_nula(hijoDerechoNodo1) && a_es_rama_nula(hijoDerechoNodo2));
        }

        return validoIzquierda && validoDerecha;
    }
    else{
        return false;
    }
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){
    NodoArbol raizA = a_raiz(A);
    NodoArbol raizB = a_raiz(B);
    
    return compararNodos(raizA,raizB);
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
    printf("[INFO] Cargando primer arbol...\n");
    cargar_arbol_binario(arbolA);
 
    ArbolBinario arbolB = a_crear();
    printf("[INFO] Cargando segundo arbol...\n");
    cargar_arbol_binario(arbolB);

    if (a_ej7_equivalente(arbolA,arbolB)){
        printf("\n[OUTPUT] Tus arboles son equivalentes.\n");
    }
    else{
        printf("\n[OUTPUT] Tus arboles no son equivalentes.\n");
    }

    return 0;
}