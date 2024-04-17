//C. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).

#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"

Lista valores_comunes(Lista lista1, Lista lista2) {
    Lista valores__comun = l_crear();

    Iterador iter = iterador(lista2);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);

        if (l_buscar(lista1, elemento_actual->clave) != NULL) {
            l_agregar(valores__comun, elemento_actual);
        }
    }

    return valores__comun;
}
