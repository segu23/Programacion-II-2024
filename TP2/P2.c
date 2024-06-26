/*
Dada una 2 listas (L1 y L2) cargadas con valores al azar (en la clave) realizar los siguientes 
ejercicios:
a. Que retorne una lista con los valores de L1 que no están en L2.
b. Que retorne una lista con los valores de L2 que no están en L1.
c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
d. Que retorne los promedios de ambas listas.
e. Que retorne el valor máximo de ambas listas y su posición ordinal. 
*/

#include <stdlib.h>
#include <stdio.h>
#include "P2ab.c"
#include "P2c.c"
#include "P2d.c"
#include "P2e.c"
#include <stdbool.h>
#include "listas.h"
#include "tipo_elemento.h"

void mostrarMenu(){
    printf(" > Menu <\n");
    printf("\n");
    printf("Seleccione una opcion: \n");
    printf("a) Que retorne una lista con los valores de L1 que no estan en L2\n");
    printf("b) Que retorne una lista con los valores de L2 que no estan en L1\n");
    printf("c) Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2)\n");
    printf("d) Que retorne los promedios de ambas listas\n");
    printf("e) Que retorne el valor maximo de ambas listas y su posicion ordinal\n");
    printf("x) Salir\n");
}

int main() {

    Lista lista1 = l_crear();
    Lista lista2 = l_crear();
    int inputNumber;
    char inputChar;
    bool seguirAgregando = true;
    bool seguirAgregando2 = true;

    printf("[INPUT] Agregar valores a lista 1:\n");

    while(seguirAgregando){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(lista1, te_crear(inputNumber));
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

    printf("[INPUT] Agregar valores a lista 2:\n");

    while(seguirAgregando2){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(lista2, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando2 = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }

    char input;

    while(input != 'x'){
        mostrarMenu();
        fflush(stdin);
        while(scanf("%c", &input) == 0){
            printf("[ERROR] Ingrese una opcion valida.\n");
            fflush(stdin);
        }
        switch(input){
            case 'a':{
                printf("[INFO] Mostrando opcion A.\n");
                l_mostrar(lista1);
                l_mostrar(lista2);
                l_mostrar(valores_no_en_lista(lista1, lista2));
                break;
            }
            case 'b':{
                printf("[INFO] Mostrando opcion B.\n");
                l_mostrar(lista1);
                l_mostrar(lista2);
                l_mostrar(valores_no_en_lista(lista2, lista1));
                break;
            }
            case 'c':{
                printf("[INFO] Mostrando opcion C.\n");
                l_mostrar(lista1);
                l_mostrar(lista2);
                l_mostrar(valores_comunes(lista1,lista2));
                break;
            }
            case 'd':{
                printf("[INFO] Mostrando opcion D.\n");
                l_mostrar(lista1);
                l_mostrar(lista2);
                printf("[OUTPUT]Promedio de Lista 1 = %3.f \n",promedio_lista(lista1));
                printf("[OUTPUT]Promedio de Lista 2 = %3.f \n",promedio_lista(lista2));
                break;
            }
            case 'e':{
                int posMax1 = -1;
                int posMax2 = -1;

                int valor_m1 = valor_max(lista1, &posMax1);
                int valor_m2 = valor_max(lista2, &posMax2);
                
                l_mostrar(lista1);
                l_mostrar(lista2);

                if(posMax1 == -1){
                    printf("[OUTPUT] La lista 1 esta vacia");
                }else{
                    printf("[OUTPUT] Maximo Lista 1: %d en la posicion %i\n",valor_m1, posMax1);
                }
                
                if(posMax1 == -1){
                    printf("[OUTPUT] La lista 1 esta vacia");
                }else{
                    printf("[OUTPUT] Maximo Lista 2: %d en la posicion %i\n",valor_m2, posMax2);  
                }
                break;
            }
            case 'x':{
                printf("[INFO] Saliendo...\n");
                break;
            }
            default:{
                printf("[ERROR] Opcion invalida.\n");
                break;
            }
        }
        system("pause");
    }
    return 0;
}
