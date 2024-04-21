#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "tipo_elemento.c"
#include "pilas.h"
#define MAX 100

#include "pilas_arreglos.c"

/**
6.	Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado ítem sin perder la pila original.
	Deberá retornar una nueva pila sin el ítem en consideración.
	Resolver iterativamente y recursivamente.
	Determinar la       complejidad algorítmica de ambas soluciones.
 */
// retornar la nueva pila sin la clave que se debe sacar (eliminar). Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones

//Resuelto recursivamente
Pila ordenar_Pila(Pila nueva){
    Pila aux = p_crear();
    bool tf =p_es_vacia(nueva);
    while (tf == false){
        TipoElemento elmt = p_desapilar(nueva);
        p_apilar(aux, elmt);
        tf=p_es_vacia(nueva);

        free(elmt);
    }
    
    return aux;
}

Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila nueva = p_crear();
    if(p_es_vacia(p)){
        return p_crear(); 
    }
    else{
        TipoElemento elemento1 = p_desapilar(p);
        Pila nueva = p_ej6_eliminarclave(p, clave);
        int valor = elemento1->clave;
        if (valor != clave){    
            p_apilar(nueva, elemento1);
        }
        
        //Pila resultados = ordenar_Pila(nueva);
        //return resultados;

        return ordenar_Pila(nueva);

    }



}

void cargarPila(Pila pila){
    bool seguirIngresando = true;
    int terminoElegido;
    char opcionSeguir;

    while (seguirIngresando){
        printf("[INPUT] Ingrese un elemento para agregar a la pila: ");
        if (scanf("%i", &terminoElegido)>0){
            p_apilar(pila, te_crear(terminoElegido));
            printf("[INFO] Agregado!\n");
        }
        else{
            if (scanf("%c", &opcionSeguir)>0 && opcionSeguir == 'n'){
                printf("[INFO] Finalizando carga de la pila.\n");
                seguirIngresando = false;
            }
            else{
                printf("[ERROR] Debe ingresar un numero.\n");
            }
            fflush(stdin);
        }
    }
}

//Resuelto iterativamnte 
int main(){
    Pila pila1 = p_crear();
    cargarPila(pila1);
    int clave;
    printf("Ingrese clave:");
    scanf("%d",&clave);

    Pila n = p_ej6_eliminarclave(pila1, clave);

    
    printf("Nueva pila sin ocurrencias de %d:\n", clave);
    p_mostrar(n);
    return 0;
}