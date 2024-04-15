/*
D.Que retorne los promedios de ambas listas.
*/
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"

float promedio_lista1(Lista lista1){
    float promedio=0.0;
    float resultado=0.0;
    Iterador iter = iterador(lista1);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        float valor_actual;
        valor_actual=elemento_actual->clave;
        resultado+=valor_actual;
    }
    promedio=resultado/l_longitud(lista1);
    return promedio;
}

float promedio_lista2(Lista lista2){
    float promedio=0.0;
    float resultado=0.0;
    Iterador iter = iterador(lista2);
    while (hay_siguiente(iter)) {
        TipoElemento elemento_actual = siguiente(iter);
        float valor_actual;
        valor_actual=elemento_actual->clave;
        resultado+=valor_actual;
    }
    promedio=resultado/l_longitud(lista2);
    return promedio;
}

