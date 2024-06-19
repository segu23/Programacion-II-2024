#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"
#include "tipo_elemento.h"

int main(){
    Conjunto conjuntoA=cto_crear();
    bool seguiragregando=true;
    int indice=1;
    int clave=0;
    char claveChar;
    while(seguiragregando){
            
        printf("[INPUT] Ingrese el elemento %d del primer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoA,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("[INFO] Terminando ingreso del conjunto.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoB=cto_crear();
    while(seguiragregando){
            
        printf("[INPUT] Ingrese el elemento %d del segundo conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoB,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("[INFO] Terminando ingreso del conjunto.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }

    if(cto_es_vacio(conjuntoA) && cto_es_vacio(conjuntoB)){
        printf("\nAmbos conjuntos son vacios\n\n");
    }else if(cto_es_vacio(cto_diferencia(conjuntoA, conjuntoB))){
        printf("\nEl conjunto A es subconjunto del conjunto B\n\n");
    }else{
        printf("\nEl conjunto A no es subconjunto de B\n\n");
    }

    return 0;
}
