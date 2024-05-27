#include "arbol-binario.h"
#include "nodo.h"
#include "tipo_elemento.h"
#include "listas.h"
#include "tp_arboles.h"

void buscarNodosNivel(NodoArbol nodo, int profundidad, int nivel, Lista resultado){
    if(profundidad == nivel) l_agregar(resultado, te_crear(nodo->datos->clave));

    if(profundidad > nivel) return;

    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    if (!a_es_rama_nula(hijoIzquierdoNodo))
    {
        buscarNodosNivel(hijoIzquierdoNodo, profundidad + 1, nivel, resultado);
    }

    if (!a_es_rama_nula(hijoDerechoNodo))
    {
        buscarNodosNivel(hijoDerechoNodo, profundidad + 1, nivel, resultado);
    }
}

// Función principal para listar nodos en un nivel dado
Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel) {
    Lista resultado=l_crear();
    NodoArbol raiz = a_raiz(A);

    buscarNodosNivel(raiz, 1, nivel, resultado);

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
    int nivel;

    while(seguirAgregando){
        printf("[INPUT] Ingrese el nivel a buscar: ");

        if(scanf("%d", &nivel) > 0 && nivel >= 0){
            seguirAgregando = false;
        }
        else{
            printf("[ERROR] Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    Lista claveNivel=a_ej3_clavesmismonivel(arbolA,nivel);

    if(l_es_vacia(claveNivel)){
        printf("[OUTPUT] No hay elementos en ese nivel.");
    }
    else{
        l_mostrar(claveNivel);
    }
}