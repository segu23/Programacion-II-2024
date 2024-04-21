#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "pilas_punteros.c"
#include "tipo_elemento.h"
#include "tipo_elemento.c"

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
        TipoElemento elementoActual = p_desapilar(clave);
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

Pila p_ej2_duplicarcontenido(Pila p){  // Para pilas mayores de 5 elementos no funciona por el TAMANIO_MAXIMO = 10;
    Pila pila_duplicada = p_crear();
    Pila pAux = p_crear();
    
    while (!p_es_vacia(p)) {
        TipoElemento elemento = p_desapilar(p);
        p_apilar(pAux, elemento);
    }
    
    while (!p_es_vacia(pAux)) {
        TipoElemento elemento = p_desapilar(pAux);
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

    // Punto a)
    /*while(true){
        int target;
        p_mostrar(pilaAleatoria);
        printf("[INPUT] Ingrese el numero a buscar: ");
        scanf("%i", &target);
        bool existe = p_ej2_existeclave(pilaAleatoria, target);

        if(existe){
            printf("[OUTPUT] Existe.\n");
        }else{
            printf("[OUTPUT] No existe.\n");
        }
    }

    // Punto b)
    while(true){
        p_mostrar(pilaAleatoria);

        int posicion;
        printf("[INPUT] Ingrese la posicion: ");
        scanf("%i", &posicion);
        
        p_ej2_colocarelemento(pilaAleatoria, posicion);
    }*/
    // punt d
    // p_mostrar(pilaAleatoria);

    // int posicion1;
    // int posicion2;
    // printf("[INPUT] Ingrese la Posicion1: ");
    // scanf("%i", &posicion1);

    // printf("[INPUT] Ingrese la Posicion2: ");
    // scanf("%i", &posicion2);
        
    // Pila resultado =p_ej2_intercambiarposiciones(pilaAleatoria,posicion1,posicion2);
    // p_mostrar(resultado);

    // return 0;

    // punto e
    // p_mostrar(pilaAleatoria);
    // Pila resultado = p_ej2_duplicarcontenido(pilaAleatoria);
    // p_mostrar(resultado);
    // return 0;
}