#include "tp_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "colas.h"
#include "listas.h"

void calcularNivelHojas(NodoArbol nodo, int profundidad, Lista resultado){
    NodoArbol hijoIzquierdoNodo = n_hijoizquierdo(nodo);
    NodoArbol hijoDerechoNodo = n_hijoderecho(nodo);

    if (a_es_rama_nula(hijoIzquierdoNodo)){
        l_agregar(resultado, te_crear_con_valor(profundidad, (void*) nodo));
    }else{
        calcularNivelHojas(hijoIzquierdoNodo, profundidad+1, resultado);
    }/**/

    if (!a_es_rama_nula(hijoDerechoNodo)){
        calcularNivelHojas(hijoDerechoNodo, profundidad, resultado);
    }
}

bool c_ej8_hojasmismonivel(ArbolBinario A){
    NodoArbol raizA = a_raiz(A);
    Lista resultado = l_crear();

    calcularNivelHojas(raizA, 1, resultado);

    Iterador iter = iterador(resultado);

    int nivel = 0;

    while(hay_siguiente(iter)){
        TipoElemento tipoElemento = siguiente(iter);

        if(nivel == 0) {
            nivel = tipoElemento->clave;
        }else {
            if(nivel != tipoElemento->clave) return false;
        }
    }

    return true;
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
    cargar_arbol_binario(arbol);

    bool hojasMismoNivel = c_ej8_hojasmismonivel(arbol);

    if(hojasMismoNivel){
        printf("[OUTPUT] Mismo nivel.");
    }else{
        printf("[OUTPUT] Diferente nivel.");
    }

    return 0;
}