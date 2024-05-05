#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "tp_colas.h"
#include "tipo_elemento.h"
#include "listas.h"
#include "pilas.h"

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
        bool encolar = true;
        TipoElemento elemento = c_desencolar(copiaOriginal);
        while (!c_es_vacia(copiaOriginal)){
            TipoElemento elemento2 = c_desencolar(copiaOriginal);
            if (elemento->clave != elemento2->clave){
                c_encolar(cAux, elemento2);
            }
            else{
                encolar=false;
            }
        }
        if (encolar){
            c_encolar(respuesta, elemento);
        }
        
        while (!c_es_vacia(cAux)){
            TipoElemento elemento3 = c_desencolar(cAux);
            c_encolar(copiaOriginal, elemento3);
        }  
    }
    
    return respuesta;
}

int main(){
    Cola cola = c_crear();

    bool bandera=true;
    int terminoElegido;
    char opcionSeguir;

    while(bandera){
        printf("[INPUT] Ingrese un elemento para agregar a la cola (ingrese 'n' para terminar el ingreso): ");
        if (scanf("%d", &terminoElegido)>0){
            c_encolar(cola, te_crear(terminoElegido));
            printf("[INFO] Agregado!\n");
        }
        else{
            if (scanf("%c", &opcionSeguir)>0 && opcionSeguir == 'n'){
                printf("[INFO] Finalizando carga de la cola.\n");
                bandera=false;
            }
            else{
                printf("[ERROR] Debe ingresar un numero.\n");
            }
            fflush(stdin);
        }
    }

    Cola respuesta = c_crear();
    respuesta = c_ej4_colanorepetidos(cola);

    printf("\n[OUTPUT] Cola original: \n");
    c_mostrar(cola);
    printf("\n[OUTPUT] Cola sin repetidos: \n");
    c_mostrar(respuesta);

    return 0;
}