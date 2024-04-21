#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "pilas_punteros.c"
#include "tipo_elemento.h"
#include "tipo_elemento.c"

void mostrarMenu(){
    printf(" > Menu <\n");
    printf("\n");
    printf("Seleccione una opcion: \n");
    printf("a) Buscar una clave y determinar si existe en la Pila (sin perder la pila). \n");
    printf("b) Colocar en una posicion ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo). \n");
    printf("c) Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave). \n");
    printf("d) Intercambiar los valores de 2 posiciones ordinales de la pila. \n");
    printf("e) Duplicar el contenido de una pila. \n");
    printf("f) Contar los elementos de la pila. \n");   
    printf("x) Salir\n");
}

int random_number(int min_num, int max_num){
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    result = (rand() % (hi_num - low_num)) + low_num;

    return result;
}

Pila crearListaAleatoria(int longitud){
    Pila pila = p_crear();
    
    srand(time(NULL));
    for(int i = 0; i < longitud; i++) {
        int number = random_number(0, 100);
        TipoElemento tipoElemento = te_crear(number);
        p_apilar(pila, tipoElemento);
    }

    return pila;
}

// Punto a)
bool p_ej2_existeclave(Pila p, int clave){
    Pila pAux = p_crear();
    bool existe = false;

    while(!p_es_vacia(p) && !existe){
        TipoElemento elementoActual = p_desapilar(p);
        p_apilar(pAux, elementoActual);

        if(elementoActual->clave == clave) existe = true;
    }

    while(!p_es_vacia(pAux)){
        p_apilar(p, p_desapilar(pAux));
    }

    return existe;
}

// Punto b)
Pila p_ej2_colocarelemento(Pila p, int posicionordinal){
    Pila pAux = p_crear();
    bool existe = false;
    int index = 0;

    while(!p_es_vacia(p)){
        p_apilar(pAux, p_desapilar(p));

        index ++;
    }

    while(!p_es_vacia(pAux)){
        p_apilar(p, p_desapilar(pAux));
        
        if(index == posicionordinal) {
            existe = true;
            p_apilar(pAux, te_crear(random_number(0, 100)));
        }

        index--;
    }

    return p;
}

// Punto c)
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila pAux = p_crear();
    bool eliminada = false;

    while (!eliminada && (!p_es_vacia(p))){
        TipoElemento elemento = p_desapilar(p);
        if (elemento->clave != clave){
            p_apilar(pAux, elemento);
        }
        else{
            eliminada = true;
        }
    }

    while (!p_es_vacia(pAux)){
        TipoElemento elemento = p_desapilar(pAux);
        p_apilar(p,elemento);
    }
    
    return p;
}

// Punto d) 
Pila p_ej2_intercambiarposiciones(Pila p, int posicion1, int posicion2){
    if (posicion1 < 1 || posicion2 < 1 || posicion1 == posicion2){
        printf("Posiciones Invalidas\n");
        return NULL;
    }
    if (posicion1 > posicion2) {
        int temp = posicion1;
        posicion1 = posicion2;
        posicion2 = temp;
    }

    Pila pAux = p_crear();

    int contador = 1;

    while (contador < posicion1 && !p_es_vacia(p)) {
        TipoElemento elemento = p_desapilar(p);
        p_apilar(pAux, elemento);
        contador++;
    }

    if (p_es_vacia(p)) {
        printf("Posiciones Invalidas\n");
        while (!p_es_vacia(pAux)) {
            TipoElemento elemento = p_desapilar(pAux);
            p_apilar(p, elemento);
        }
    }

    contador++;
    while (contador < posicion2 && !p_es_vacia(p)) {
        TipoElemento elemento = p_desapilar(p);
        p_apilar(pAux, elemento);
        contador++;
    }

    if (p_es_vacia(p)) {
        printf("Posiciones Invalidas\n");
        while (!p_es_vacia(pAux)) {
            TipoElemento elemento = p_desapilar(pAux);
            p_apilar(p, elemento);
        }
    }

    TipoElemento elemento1 = p_desapilar(p);

    TipoElemento elemento2 = p_desapilar(p);

    while (!p_es_vacia(pAux)) {
        TipoElemento elemento = p_desapilar(pAux);
        p_apilar(p, elemento);
    }

    p_apilar(p, elemento1);


    p_apilar(p, elemento2);

    return p;
}

// Punto e)
Pila p_ej2_duplicarcontenido(Pila p){  // Para pilas mayores de 5 elementos no funciona por el TAMANIO_MAXIMO = 10;
    Pila pila_duplicada = p_crear();
    Pila pAux = p_crear();
    
    while (!p_es_vacia(p)) {
        TipoElemento elemento = p_desapilar(p);
        p_apilar(pAux, elemento);
    }
    
    while (!p_es_vacia(pAux)) {
        TipoElemento elemento = p_desapilar(pAux);
        p_apilar(p, elemento);
        p_apilar(pila_duplicada, elemento);
        p_apilar(pila_duplicada, elemento);
    }

    return pila_duplicada;
}

// Punto f)
int p_ej2_cantidadelementos(Pila p){
    if (p_es_vacia(p)){
        return 0;
    }

    Pila pAux = p_crear();
    int contador = 0;

    while (!p_es_vacia(p)){
        TipoElemento elemento = p_desapilar(p);
        p_apilar(pAux, elemento);
        contador++;
    }

    while (!p_es_vacia(p)){
        TipoElemento elemento = p_desapilar(pAux);
        p_apilar(p, elemento);
    }
    
    return contador;
}

int main(){
    Pila pilaAleatoria = crearListaAleatoria(5);
    p_mostrar(pilaAleatoria);
    char input;

    while(input != 'x'){
        mostrarMenu();
        printf("Seleccione una opcion: ");
        fflush(stdin);
        while(scanf("%c", &input) == 0){
            printf("[ERROR] Ingrese una opcion valida.\n");
            fflush(stdin);
        }
        switch(input){
            case 'A':
            case 'a':{
                int target;
                printf("[INPUT] Ingrese el numero a buscar: ");
                scanf("%i", &target);

                if(p_ej2_existeclave(pilaAleatoria, target)){
                    printf("[OUTPUT] La clave existe.\n");
                }else{
                    printf("[OUTPUT] La clave no existe.\n");
                }
                break;
            }
            case 'B':
            case 'b':{
                bool seguirAgregando = true;
                int IngresoNumero;
                char inputChar;

                while(seguirAgregando){
                    printf("[INPUT] Ingrese la posicion del elemento a insertar o 'n' para terminar: ");

                    if(scanf("%d", &IngresoNumero) > 0 && IngresoNumero > 0){
                        p_ej2_colocarelemento(pilaAleatoria, IngresoNumero);
                        printf("[INFO] Elemento agregado!\n");
                        p_mostrar(pilaAleatoria);
                    }
                    else{
                        if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                            seguirAgregando = false;
                            printf("[INFO] Ingreso de la pila terminado.\n");
                        }
                        else{
                            printf("[ERROR] Debe ingresar un valor valido.\n");
                        }

                        fflush(stdin);
                    }
                }

                break;
            }
            case 'C':
            case 'c':{
                while(!p_es_vacia(pilaAleatoria)){
                    int clave;
                    printf("[INPUT] Ingrese el elemento: ");
                    if(scanf("%i", &clave)){
                        Pila resultado = p_ej2_eliminarclave(pilaAleatoria,clave);
                        p_mostrar(resultado);
                    }
                    else{
                        fflush(stdin);
                    }
                }
                break;
            }
            case 'D':
            case 'd':{
                while (true){
                    int posicion1;
                    int posicion2;
                    printf("[INPUT] Ingrese la Posicion 1: ");
                    scanf("%i", &posicion1);

                    printf("[INPUT] Ingrese la Posicion 2: ");
                    scanf("%i", &posicion2);
            
                    Pila resultado = p_ej2_intercambiarposiciones(pilaAleatoria,posicion1,posicion2);
                    p_mostrar(resultado);
                }
                break;
            }
            case 'E':
            case 'e':{
                Pila resultado = p_ej2_duplicarcontenido(pilaAleatoria);
                p_mostrar(resultado);

                break;
            }
            case 'F':
            case 'f':{
                int resultado = p_ej2_cantidadelementos(pilaAleatoria);
                printf("[OUTPUT] La pila tiene %i elementos.\n", resultado);

                break;
            }
            case 'X':
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