/*Generar un algoritmo que determine si una lista es sublista de otra. Se considera que es
una sublista si todos los valores de la segunda se encuentran dentro de la primera sin
importar el orden o posición de cada elemento. La comparación es solo por la clave. Se
pide además determinar la complejidad algorítmica de la solución.
Ejemplo: si “L1” contiene los elementos (7, 3, 4, 5, 9, 2) y “L2” contiene los elementos
(4, 7, 2) se dice que “L2” es sublista de “L1”.*/

#include <stdlib.h>
#include <stdbool.h>
#include "tipo_elemento.c"
#include "listas_cursores.c"

/*
LA COMPLEJIDAD ALGORITMICA SE ENCUENTRA EN EL README.md DE ESTE DIRECTORIO
*/
bool esSublista(Lista L1, Lista L2){
    Iterador iterL2 = iterador(L2);

    if(L2->cantidad > L1->cantidad) return false;
    
    while(hay_siguiente(iterL2)){
        bool contiene = false;
    
        TipoElemento elementoActualL2 = siguiente(iterL2);
        Iterador iterL1 = iterador(L1);
    
        while(hay_siguiente(iterL1) && !contiene){
            TipoElemento elementoActualL1 = siguiente(iterL1);
    
            if(elementoActualL1->clave == elementoActualL2->clave){
                contiene = true;
            }
        }
    
        if(!contiene) return false;
    }
    
    return true;
}

int main(){
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    bool seguirAgregando = true;
    int index = 1;
    int inputNumber;
    char inputChar;

    while(seguirAgregando){
        printf("[INPUT] Ingrese el #%i elemento de la primer lista o 'n' para terminar: ", index);

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L1, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
        index++;
    }

    seguirAgregando = true;
    index = 1;

    while(seguirAgregando){
        printf("[INPUT] Ingrese el #%i elemento de la segunda lista o 'n' para terminar: ", index);

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L1, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la segunda lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }
            
            fflush(stdin);
        }
        index++;
    }

    if(esSublista(L1, L2)){
        printf("[OUTPUT] L2 es sublista de L1.");
    }else{
        printf("[OUTPUT] L2 no es sublista de L1.");
    }
}
