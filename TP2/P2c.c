/*
C.Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
*/

#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"

Lista valores_comunes(Lista lista1, Lista lista2) {
    Lista valores__comun = l_crear();

    for (int i = 1; i <= l_longitud(lista2); i++) {
        TipoElemento elemento_actual = l_recuperar(lista2, i);

        if (l_buscar(lista1, elemento_actual->clave) != NULL) {
            l_agregar(valores__comun, elemento_actual);
        }
    }

    return valores__comun;
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

        printf("\n[INPUT]Agregar valores a lista2:\n");
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
    
    Lista valores_comu = valores_comunes(lista1, lista2);
    printf("[OUTPUT] Valores Comunes en Lista 1 y Lista 2: ");
    l_mostrar(valores_comu);
    fflush(stdin);

    return 0;
}
