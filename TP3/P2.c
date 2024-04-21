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
    Pila pilaAleatoria = crearListaAleatoria(6);

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


    return 0;
}