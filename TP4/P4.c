#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tp_colas.h"
#include "tipo_elemento.h"
#include "listas.h"
#include "pilas.h"
#include "tipo_elemento.c"
#include "colas_arreglos.c"

Cola  c_ej4_colanorepetidos(Cola c){
    Cola cAux = c_crear();
    Cola respuesta = c_crear();
    Cola copiaOriginal = c_crear();

    while (!c_es_vacia(c)){
        TipoElemento aCopiar = c_desencolar(c);
        c_encolar(copiaOriginal, aCopiar);
        c_encolar(cAux, aCopiar);
    }
    
    while (!c_es_vacia(cAux)){
        TipoElemento aCopiar2 = c_desencolar(cAux);
        c_encolar(c, aCopiar2);
    }

    while (!c_es_vacia(copiaOriginal)){
        TipoElemento elemento = c_desencolar(copiaOriginal);
        while (!c_es_vacia(copiaOriginal)){
            TipoElemento elemento2 = c_desencolar(copiaOriginal);
            if (elemento->clave != elemento2->clave){
                c_encolar(cAux, elemento2);
            }

        }
        c_encolar(respuesta, elemento);
        while (!c_es_vacia(cAux)){
            TipoElemento elemento3 = c_desencolar(cAux);
            c_encolar(copiaOriginal, elemento3);
        }  
    }
    
    return respuesta;
}

int main(){
    Cola cola1 = c_crear();
    c_encolar(cola1, te_crear(1));
    c_encolar(cola1, te_crear(2));
    c_encolar(cola1, te_crear(2));
    c_encolar(cola1, te_crear(3));
    c_encolar(cola1, te_crear(2));

    Cola respuesta = c_crear();
    respuesta = c_ej4_colanorepetidos(cola1);

    printf("Cola original: \n");
    c_mostrar(cola1);
    printf("Cola sin repetidos: \n");
    c_mostrar(respuesta);

    return 0;
}