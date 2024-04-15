/*. Que retorne una lista con los valores de L2 que no están en L1. */
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"

Lista valores_no_en_L1(Lista lista1, Lista lista2) {
    Lista valores_no_comunes = l_crear();

    Iterador iter = iterador(lista2);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);

        if (l_buscar(lista1, elemento_actual->clave) == NULL) {
            l_agregar(valores_no_comunes, elemento_actual);
        }
    }

    return valores_no_comunes;
}

