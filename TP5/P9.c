#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "arbol-avl.h"
#include "colas.h"
#include "listas.h"

void cargarArbolAVL(NodoArbol nodo, ArbolAVL resultado)
{
    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    avl_insertar(resultado, nodo->datos);

    if (!a_es_rama_nula(hijoIzquierdoNodo))
    {
        cargarArbolAVL(hijoIzquierdoNodo, resultado);
    }

    if (!a_es_rama_nula(hijoDerechoNodo))
    {
        cargarArbolAVL(hijoDerechoNodo, resultado);
    }
}

ArbolAVL a_ej9_construiravl(ArbolBinario A)
{
    ArbolAVL arbolAVL = avl_crear();
    NodoArbol raiz = a_raiz(A);

    cargarArbolAVL(raiz, arbolAVL);

    return arbolAVL;
}

int calcularAlturaArbolBinario(NodoArbol nodo, int profundidad)
{
    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    int validoIzquierda = profundidad;
    int validoDerecha = profundidad;

    if (!a_es_rama_nula(hijoIzquierdoNodo))
    {
        validoIzquierda = calcularAlturaArbolBinario(hijoIzquierdoNodo, profundidad + 1);
    }

    if (!a_es_rama_nula(hijoDerechoNodo))
    {
        validoDerecha = calcularAlturaArbolBinario(hijoDerechoNodo, profundidad);
    }

    return (validoIzquierda > validoDerecha ? validoIzquierda : validoDerecha);
}

int calcularAlturaArbolAVL(NodoArbol nodo, int profundidad)
{
    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    int validoIzquierda = profundidad;
    int validoDerecha = profundidad;

    if (!a_es_rama_nula(hijoIzquierdoNodo))
    {
        validoIzquierda = calcularAlturaArbolAVL(hijoIzquierdoNodo, profundidad + 1);
    }

    if (!a_es_rama_nula(hijoDerechoNodo))
    {
        validoDerecha = calcularAlturaArbolAVL(hijoDerechoNodo, profundidad + 1);
    }

    return (validoIzquierda > validoDerecha ? validoIzquierda : validoDerecha);
}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL)
{
    int alturaBinario = calcularAlturaArbolBinario(a_raiz(A), 1);
    int alturaAVL = calcularAlturaArbolAVL(avl_raiz(AVL), 1);
    
    if(alturaBinario > alturaAVL) return alturaBinario - alturaAVL;

    return alturaAVL - alturaBinario;
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

int main()
{
    ArbolBinario arbol = a_crear();
    cargar_arbol_binario(arbol);

    ArbolAVL arbolAVL = a_ej9_construiravl(arbol);

    printf("[OUTPUT] Altura arbol binario: %i\n", calcularAlturaArbolBinario(a_raiz(arbol), 1));
    printf("[OUTPUT] Altura arbol AVL: %i\n", calcularAlturaArbolAVL(avl_raiz(arbolAVL), 1));

    int diferenciaAlturas = a_ej9_diferenciaalturas(arbol, arbolAVL);

    printf("[OUTPUT] La diferencia de alturas es de: %i\n", diferenciaAlturas);

    return 0;
}