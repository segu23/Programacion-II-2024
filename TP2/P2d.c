/*
D.Que retorne los promedios de ambas listas.
*/
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"

float promedio_lista(Lista lista){
    float promedio=0.0;
    float resultado=0.0;
    Iterador iter = iterador(lista);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        float valor_actual;
        valor_actual=elemento_actual->clave;
        resultado+=valor_actual;
    }
    promedio=resultado/l_longitud(lista);
    return promedio;
}