#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"

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

    int claveBuscada;
    printf("[INPUT] Ingrese la clave a buscar: ");
    scanf("%i", &claveBuscada);
    Lista lista = a_ej2_buscarclave(arbol, claveBuscada);

    if (l_es_vacia(lista)){
        printf("\n[OUTPUT] No hay ocurrencias con esa clave en el arbol.\n");
    }
    else{
        printf("\n[OUTPUT] En la siguiente lista se encuentran los punteros a los nodos de la ocurrencia buscada.\n");
        l_mostrar(lista);
    }

    return 0;
}