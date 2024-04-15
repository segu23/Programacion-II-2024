/*
Dada una 2 listas (L1 y L2) cargadas con valores al azar (en la clave) realizar los siguientes 
ejercicios: 
a. Que retorne una lista con los valores de L1 que no están en L2. 
*/
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"



Lista valores_no_en_L2(Lista lista1, Lista lista2) {
    Lista valores_no_comunes = l_crear();

    Iterador iter = iterador(lista1);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);

        if (l_buscar(lista2, elemento_actual->clave) == NULL) {
            l_agregar(valores_no_comunes, elemento_actual);
        }
    }
    printf("[OUTPUT] Valores de lista1 que no estan en lista2 (Lista): ");
    return valores_no_comunes;
}
