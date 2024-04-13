/*
D.Que retorne los promedios de ambas listas.
*/
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"

float promedio_lista1(Lista lista1){
    float promedio=0.0;
    float resultado=0.0;
    for (int i = 1; i <= l_longitud(lista1); i++) {
        TipoElemento elemento_actual = l_recuperar(lista1, i);
            int valor_actual;
            valor_actual= elemento_actual->clave;
            resultado+=valor_actual;
    }
    promedio = resultado/ l_longitud(lista1);
    return promedio;
}

float promedio_lista2(Lista lista2){
    float promedio=0.0;
    float resultado=0.0;
    for (int i = 1; i <= l_longitud(lista2); i++) {
        TipoElemento elemento_actual = l_recuperar(lista2, i);
            int valor_actual;
            valor_actual= elemento_actual->clave;
            resultado+=valor_actual;
    }
    promedio = resultado/ l_longitud(lista2);
    return promedio;
}

int main() {
    Lista lista1 = l_crear();
    Lista lista2 = l_crear();
    int valor;
    char opcion;

    printf("[INPUT]Agregar valores a lista1:\n");
        do {
            printf("[INPUT]Ingrese un valor: ");
            scanf("%d", &valor);
            l_agregar(lista1, te_crear(valor)); // tipo_elemento.h redondea a un entero y no se puede poner float
            printf("[INPUT]¿Desea agregar otro valor a lista1? (s/n): ");
            scanf(" %c", &opcion);
        } while (opcion == 's');
    
    printf("[INPUT]Agregar valores a lista2:\n");
        do {
            printf("[INPUT]Ingrese un valor: ");
            scanf("%d", &valor);
            l_agregar(lista2, te_crear(valor)); // tipo_elemento.h redondea a un entero y no se puede poner float
            printf("[INPUT]¿Desea agregar otro valor a lista2? (s/n): ");
            scanf(" %c", &opcion);
        } while (opcion == 's');

    float promedio1 = promedio_lista1(lista1);
    float promedio2 = promedio_lista2(lista2);
    printf("[OUTPUT] Promedio Lista 1: %3.f \n", promedio1);
    printf("[OUTPUT] Promedio Lista 2: %3.f \n",promedio2);
    fflush(stdin);

    return 0;
}
