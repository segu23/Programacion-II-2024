/*Generar un algoritmo que determine si una lista es sublista de otra. Se considera que es
una sublista si todos los valores de la segunda se encuentran dentro de la primera sin
importar el orden o posición de cada elemento. La comparación es solo por la clave. Se
pide además determinar la complejidad algorítmica de la solución.
Ejemplo: si “L1” contiene los elementos (7, 3, 4, 5, 9, 2) y “L2” contiene los elementos
(4, 7, 2) se dice que “L2” es sublista de “L1”.*/

#include <stdlib.h>
#include <stdbool.h>
#include "tipo_elemento.c"
#include "listas_arreglos.c"

bool esSublista(Lista L1, Lista L2){
    Iterador iterL2 = iterador(L2);
    
    while(hay_siguiente(iterL2)){
        bool contiene = false;
    
        TipoElemento elementoActualL2 = siguiente(iterL2);
        Iterador iterL1 = iterador(L1);
    
        while(hay_siguiente(iterL1) || !contiene){
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
    
    l_agregar(L1, te_crear(7));
    l_agregar(L1, te_crear(3));
    l_agregar(L1, te_crear(4));
    l_agregar(L1, te_crear(5));
    l_agregar(L1, te_crear(9));
    l_agregar(L1, te_crear(2));
    
    l_agregar(L2, te_crear(4));
    l_agregar(L2, te_crear(7));
    l_agregar(L2, te_crear(2));

    if(esSublista(L1, L2)){
        printf("L2 es sublista de L1");
    }else{
        printf("L2 no es sublista de L1");
    }
}