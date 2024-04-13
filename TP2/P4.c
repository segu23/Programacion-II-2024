#include <stdlib.h>
#include "./TP2/listas_punteros.c"
#include "./TP2/tipo_elemento.c"

/*
Dadas dos listas L1 y L2, se pide compararlas siempre en el sentido L1L2. Por lo tanto
puede suceder que: L1 > L2, L1 = L2 o L1 < L2. La forma de obtener la comparación es por
la clave, posición a posición, donde si L1 tiene más cantidad de claves mayores que L2 se
considera L1 > L2, por el contrario se considera L1 < L2, o de lo contrario L1 será igual a L2.
Determinar la complejidad algorítmica de la solución empleada.
*/

void ListaMayor(Lista L1, Lista L2){

    int clavesMayores=0;
    int clavesMenores=0;

    int longitud1= l_longitud( L1);
    int longitud2= l_longitud( L2);

    Iterador ite = iterador(L1);
    Iterador ite2 = iterador(L2);


    if (longitud1 != longitud2){
        exit(-1);
    }

    while (hay_siguiente(ite) && hay_siguiente(ite2)){
        TipoElemento elementoL1 = siguiente( ite);
        TipoElemento elementoL2 = siguiente( ite2);

        if(elementoL1 ->clave > elementoL2->clave){
            clavesMayores++;
        }
        else if(elementoL1 ->clave < elementoL2->clave){
            clavesMenores++;
        }


    }

    if(clavesMayores > clavesMenores){
        printf("L1 es mayor a L2\n");
    }
    else if (clavesMayores < clavesMenores){
        printf("L1 es menor a L2\n");

    }
    else printf("L1 es igual a L2\n");
    

}