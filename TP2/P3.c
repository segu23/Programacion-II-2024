#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "tipo_elemento.c"
#include "listas.h"
#include "listas_arreglos.c"

/*Dadas 2 listas (L1 y L2) determinar si L2 es múltiplo de L1. Se considera múltiplo si cada
elemento de L2 se divide en forma exacta por el valor L1 de la misma posición. Usar la
clave como campo de datos solamente.
Ejemplo: si L1 = (2, 5, 7, 3) y L2 = (8, 20, 28, 12) entonces L2 es múltiplo por L1 porque
cada posición de L2 se divide por el valor de L1 de la misma posición en forma exacta
(sin decimales). Si el resultado de la división retorna el mismo valor para cada posición
se dice que “L2” es múltiplo de “L1” por un “escalar”. Para este caso “4” es el escalar
de L1. El algoritmo debe contemplar esta situación. 
*/

bool esMultiploConEscalar(Lista l1,Lista l2,int *escalar){

    *escalar = -1; 
    bool estadoEscalar = false;
    Iterador ite = iterador(l1);
    Iterador ite2 = iterador(l2); 

    while (hay_siguiente(ite) && hay_siguiente(ite2)){
        TipoElemento elementoL1 = siguiente( ite);
        TipoElemento elementoL2 = siguiente( ite2);

        if ((elementoL1->clave == 0 )||(elementoL2->clave % elementoL1->clave!= 0)) {
            return false; // Retornamos falso si no es un múltiplo
        }
        
        // Calculamos el escalar si es posible
        if (!estadoEscalar) {
            *escalar = elementoL2->clave / elementoL1->clave;
            estadoEscalar = true;
        } 
        else if (*escalar != elementoL2->clave / elementoL1->clave) {
            *escalar=-1; // si hay multiplos diferentes no es un producto escalar
        }
    }

    return true;
}



int main() {
    Lista L1 = l_crear();
    Lista L2 = l_crear();


    bool seguirAgregando = true;
    int index = 1;
    int IngresoNumero;
    char inputChar;

    while(seguirAgregando){
        printf("[INPUT] Ingrese el #%i elemento de la primer lista o 'n' para terminar (mayor a 0): ", index);

        if(scanf("%d", &IngresoNumero) > 0 && IngresoNumero > 0){
            l_agregar(L1, te_crear(IngresoNumero));
            index++;
        }
        else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }
    
    printf("\n[INFO] Ingrese %d elementos para la Lista 2 \n", index-1);

    index=1;

    int longitud=l_longitud(L1);
    
    for (int i = 0; i < longitud; i++){
        printf("[INPUT] Ingrese el #%i elemento de la segunda lista: ", index);

        if(scanf("%d", &IngresoNumero) > 0 && IngresoNumero > 0){
            l_agregar(L2, te_crear(IngresoNumero));
            index++;
        }
        else{
            printf("[ERROR] Debe ingresar un valor valido.\n");
            fflush(stdin);
        }

        if(i == longitud-1) printf("\n[INFO] Terminando ingreso de la segunda lista.\n");
    }

    int escalar;

    if (esMultiploConEscalar(L1, L2, &escalar)) {
        if (escalar != -1) {
            printf("[OUTPUT] L2 es multiplo de L1 con escalar %d.\n", escalar);
        } 
        else {
            printf("[OUTPUT] L2 es multiplo de L1 pero no hay escalar.\n");
        }
    } 
    else{
        printf("[OUTPUT] L2 no es multiplo de L1.\n");
    }

    return 0;
}
