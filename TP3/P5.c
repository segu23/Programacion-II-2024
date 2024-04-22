#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"

Pila  p_ej5_invertir(Pila p){
    Pila paux1=p_crear();
    Pila paux2=p_crear();
    bool vaciaP=p_es_vacia(p);

    while(vaciaP!=true){
        TipoElemento elemento1=p_desapilar(p);
        p_apilar(paux1,elemento1);
        p_apilar(paux2,elemento1);
        vaciaP=p_es_vacia(p);

    }

    vaciaP=p_es_vacia(paux2);

    while(vaciaP!=true){
        TipoElemento elemento2 = p_desapilar(paux2);
        p_apilar(p,elemento2);
        vaciaP=p_es_vacia(paux2);

    }

    return paux1;

}

void cargar_Pila(Pila pila){
    bool bandera=true;
    int terminoElegido;
    char opcionSeguir;

    while(bandera){
        printf("[INPUT] Ingrese un elemento para agregar a la pila (ingrese 'n' para terminar el ingreso): ");
        if (scanf("%d", &terminoElegido)>0){
            p_apilar(pila, te_crear(terminoElegido));
            printf("[INFO] Agregado!\n");
        }
        else{
            if (scanf("%c", &opcionSeguir)>0 && opcionSeguir == 'n'){
                printf("[INFO] Finalizando carga de la pila.\n");
                bandera=false;
            }
            else{
                printf("[ERROR] Debe ingresar un numero.\n");
            }
            fflush(stdin);
        }
    }
}

int main(){
    Pila pila1=p_crear();
    cargar_Pila(pila1);

    printf("[OUTPUT] El contenido de la pila ORIGINAL es\n");
    p_mostrar(pila1);

    Pila pilaAux=p_ej5_invertir(pila1);

    printf("[OUTPUT] El contenido de la pila invertida es\n");
    p_mostrar(pilaAux);

    printf("[OUTPUT] El contenido pila ORIGINAL sigue siendo\n");
    p_mostrar(pila1);

    system("pause");
    return 0;
}