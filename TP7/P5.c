#include "stdlib.h"
#include "stdio.h"
#include "listas.h"
#include "conjuntos.h"
#include "conjuntos_listas.c"
#include "listas_arreglos.c"
#include "tipo_elemento.h"
#include "tipo_elemento.c"
//#include "conjuntos_avl.c"
#include "nodo.c"
#include "nodo.h"
#include "arbol-avl.c"
#include "arbol-avl.h"
#include "stdbool.h"

void diferenciaSime(Conjunto conjuntoA,Conjunto conjuntoB){
    Conjunto dif1=cto_diferencia(conjuntoA,conjuntoB);
    Conjunto dif2=cto_diferencia(conjuntoB,conjuntoA);

    Conjunto resultado=cto_union(dif1,dif2);
    printf("\n[OUTPUT] El resultado de la diferencia simetrica entre los dos conjuntos es:\n");
    cto_mostrar(resultado);
}

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
    
    diferenciaSime(conjuntoA,conjuntoB);

    return 0;
}