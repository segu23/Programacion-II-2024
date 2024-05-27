#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"

void calcularNivelNodo(NodoArbol nodo, int profundidad, int clave, int *nivel)
{
    if (nodo->datos->clave == clave) (*nivel) = profundidad;

    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    if (!a_es_rama_nula(hijoIzquierdoNodo))
    {
        calcularNivelNodo(hijoIzquierdoNodo, profundidad + 1, clave, nivel);
    }

    if (!a_es_rama_nula(hijoDerechoNodo))
    {
        calcularNivelNodo(hijoDerechoNodo, profundidad, clave, nivel);
    }
}

int c_ej8_nivel(ArbolBinario A, int clave)
{
    NodoArbol raizA = a_raiz(A);
    int resultado = 0;

    calcularNivelNodo(raizA, 1, clave, &resultado);

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

int main()
{
    ArbolBinario arbol = a_crear();
    cargar_arbol_binario(arbol);

    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        printf("[INPUT] Ingrese la clave a buscar: ");

        if(scanf("%d", &clave) > 0 && clave >= 0 && clave < 10){
            seguirAgregando = false;
        }
        else{
            printf("[ERROR] Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    int nivel = c_ej8_nivel(arbol, clave);

    printf("[OUTPUT] La clave %i esta en el nivel %i", clave, nivel);

    return 0;
}