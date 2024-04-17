/*
Dadas dos listas L1 y L2, se pide compararlas siempre en el sentido L1L2. Por lo tanto
puede suceder que: L1 > L2, L1 = L2 o L1 < L2. La forma de obtener la comparación es por
la clave, posición a posición, donde si L1 tiene más cantidad de claves mayores que L2 se
considera L1 > L2, por el contrario se considera L1 < L2, o de lo contrario L1 será igual a L2.
Determinar la complejidad algorítmica de la solución empleada.
*/

//LA COMPLEJIDAD ALGORITMICA SE ENCUENTRA EN EL README.md DE ESTE DIRECTORIO

#include <stdlib.h>
#include <stdio.h>
#include "tipo_elemento.h"
#include "listas.h"

enum TipoRelacionLista {
    IGUAL,
    MAYOR,
    MENOR
};  

enum TipoRelacionLista ListaMayor(Lista L1, Lista L2){

    int clavesMayores=0;
    int clavesMenores=0;

    int longitud1= l_longitud( L1);
    int longitud2= l_longitud( L2);

    Iterador ite = iterador(L1);
    Iterador ite2 = iterador(L2);

    if (longitud1 != longitud2){
        printf("[ERROR] Las listas no tienen en mismo tamanio\n");
        system("pause");
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

    enum TipoRelacionLista TipoLista;
    
    if(clavesMayores > clavesMenores){
        TipoLista = MAYOR;
    }
    else if (clavesMayores < clavesMenores){
        TipoLista = MENOR;

    }
    else TipoLista = IGUAL;
    
    return TipoLista;
}

int main(){
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    int inputNumber;
    char inputChar;
    bool seguirAgregando = true;

    printf("[INPUT] Agregar valores a lista 1:\n");

    while(seguirAgregando){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L1, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    printf("[INPUT] Agregar valores a lista 2:\n");

    while(seguirAgregando){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L2, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }
    
    enum TipoRelacionLista TipoLista = ListaMayor(L1, L2);
    switch(TipoLista) {
        case MAYOR:
            printf("L1 es mayor a L2\n");
            break;
        case MENOR:
            printf("L1 es menor a L2\n");
            break;
        case IGUAL:
            printf("L1 es igual a L2\n");
            break;
    }
    
    system("pause");
    return 0;
}