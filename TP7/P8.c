#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjuntos.h"
#include "tipo_elemento.h"

#define MAX 100

/*
Dados dos conjuntos de números naturales se pide determinar si son iguales sin
importar la posición de sus elementos. Determinar la complejidad algorítmica.
*/

bool ComparandoConjuntos(Conjunto C1, Conjunto C2) {
    int nC1 = cto_cantidad_elementos(C1);
    int nC2 = cto_cantidad_elementos(C2);
    if (nC1 == 0 && nC2 == 0) return true;
    int contador = 0;
    TipoElemento X;

    if (nC1 == nC2) {                       
        for (int i = 1 ; i <= nC1 ; i++) {
            X = cto_recuperar(C1, i);
            if (cto_pertenece(C2, X->clave)) contador++;
        }
    }
    else return false;

    if   (contador == nC1) return true;
    else                   return false;
}

int main() {
    Conjunto conjuntoA=cto_crear();
    bool seguiragregando=true;
    int indice=1;
    int clave=0;
    char claveChar;
    while(seguiragregando){
            
        printf("[INPUT] Ingrese el elemento %d del primer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoA,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("[INFO] Terminando ingreso del conjunto.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoB=cto_crear();
    while(seguiragregando){
            
        printf("[INPUT] Ingrese el elemento %d del segundo conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoB,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("[INFO] Terminando ingreso del conjunto.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }

    if (ComparandoConjuntos(conjuntoA, conjuntoB)) printf("\n> Los conjuntos son iguales.");
    else                           printf("\n> Los conjuntos no son iguales.");

    return 0;
}
