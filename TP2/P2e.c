//E. Que retorne el valor máximo de ambas listas y su posición ordinal.

#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include <stdbool.h>

int valor_max(Lista lista, int * pos){
    int maximo;
    bool primer_ingreso = false;
    Iterador iter = iterador(lista);
    int indice = 1;
    
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        if (maximo<elemento_actual->clave || !primer_ingreso){
            maximo=elemento_actual->clave;
            (*pos) = indice;
            primer_ingreso=true;
        }
        indice++;
    }

    return maximo;
}