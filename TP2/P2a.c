/*
Dada una 2 listas (L1 y L2) cargadas con valores al azar (en la clave) realizar los siguientes 
ejercicios: 
a. Que retorne una lista con los valores de L1 que no están en L2. 
*/
#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"

Lista valores_no_en_L2(Lista lista1, Lista lista2) {
    Lista valores_no_comunes = l_crear();

    for (int i = 1; i <= l_longitud(lista1); i++) {
        TipoElemento elemento_actual = l_recuperar(lista1, i);

        if (l_buscar(lista2, elemento_actual->clave) == NULL) {
            l_agregar(valores_no_comunes, elemento_actual);
        }
    }

    return valores_no_comunes;
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
            l_agregar(lista1, te_crear(valor));
            printf("[INPUT]¿Desea agregar otro valor a lista1? (s/n): ");
            scanf(" %c", &opcion);
        } while (opcion == 's');

        printf("\n[INPUT]agregar valores a lista2:\n");
        do {
            printf("[INPUT]Ingrese un valor: ");
            scanf("%d", &valor);
            l_agregar(lista2, te_crear(valor));
            printf("[INPUT]¿Desea agregar otro valor a lista2? (s/n): ");
            scanf(" %c", &opcion); 
        } while (opcion == 's');

        printf("\n[OUTPUT]Valores en lista1: ");
        l_mostrar(lista1);
        printf("[OUTPUT]Valores en lista2: ");
        l_mostrar(lista2);
    
    Lista valores_no_en_L2_arreglo = valores_no_en_L2(lista1, lista2);
    printf("[OUTPUT] Valores de lista1 que no estan en lista2 (Lista): ");
    l_mostrar(valores_no_en_L2_arreglo);
    fflush(stdin);

    return 0;
}
