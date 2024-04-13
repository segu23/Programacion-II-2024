/*
E. Que retorne el valor máximo de ambas listas y su posición ordinal. 
*/

#include <stdio.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "listas_arreglos.c"
#include "tipo_elemento.c"


int valor_max(Lista lista1,int primer_ingreso){
    int maximo = primer_ingreso;
    int pos1=1;

    for (int i = 1; i <= l_longitud(lista1); i++) {
        TipoElemento elemento_actual = l_recuperar(lista1, i);
        if (maximo<elemento_actual->clave){
            maximo=elemento_actual->clave;
            pos1=i;
        }    
    }
    printf("[OUTPUT]Posicion del Maximo de la Lista 1: %d \n", pos1);
    return maximo;

}

int valor_max2(Lista lista2, int primer_ingreso2){
    int maximo2 = primer_ingreso2;
    int pos2=1;

    for (int j = 1; j <= l_longitud(lista2); j++) {
        TipoElemento elemento_actual = l_recuperar(lista2, j);
        if (maximo2<elemento_actual->clave){
            maximo2=elemento_actual->clave;
            pos2=j;
        }    
    }
    printf("[OUTPUT]Posicion del Maximo de la Lista 2: %d \n", pos2);
    return maximo2;    
}

int main() {
    Lista lista1 = l_crear();
    Lista lista2 = l_crear();
    int valor;
    int valor2;
    char opcion;
    int primer_ingreso;
    int primer_ingreso2;
    int flag2=0;
    int flag=0;
    printf("[INPUT]Agregar valores a lista1:\n");
        do {
            printf("[INPUT]Ingrese un valor: ");
            scanf("%d", &valor);
            if(flag2==0){
                primer_ingreso=valor;
                flag2=1;
            }
            l_agregar(lista1, te_crear(valor));
            printf("[INPUT]¿Desea agregar otro valor a lista1? (s/n): ");
            scanf(" %c", &opcion);
        } while (opcion == 's');

    printf("[INPUT]Agregar valores a lista2:\n");
        do {
            printf("[INPUT]Ingrese un valor: ");
            scanf("%d", &valor2);
            if(flag==0){
                primer_ingreso2=valor2;
                flag=1;
            }
            l_agregar(lista2, te_crear(valor2)); 
            printf("[INPUT]¿Desea agregar otro valor a lista2? (s/n): ");
            scanf(" %c", &opcion);
        } while (opcion == 's');

        int valor_m1 = valor_max(lista1,primer_ingreso);
        int valor_m2 = valor_max2(lista2,primer_ingreso2);
        printf("[OUTPUT]Maximo Lista 1: %d\n",valor_m1);
        printf("[OUTPUT]Maximo Lista 2: %d \n",valor_m2);
       
        return 0;
}