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



void operaciones(Lista coleccion){

    if(l_longitud(coleccion)<3){
        printf("[ERROR] Debe cargar como minimo 3 conjuntos.");
        return;
    }

    Iterador iterador1=iterador(coleccion);
    bool bandera=true;
    Conjunto conjuntoA=cto_crear();

    while(hay_siguiente(iterador1)){

        if(bandera){
            TipoElemento elementoAux=siguiente(iterador1);
            conjuntoA=elementoAux->valor;
            bandera=false;
        }else{
            TipoElemento elementoaux=siguiente(iterador1);
            conjuntoA=cto_union(conjuntoA,elementoaux->valor);
        }

    }

    printf("\n[OUTPUT] Resultado de la UNION de los conjuntos:\n");

    cto_mostrar(conjuntoA);

    Conjunto conjuntoB=cto_crear();
    bandera=true;
    Iterador iterador2=iterador(coleccion);
    while(hay_siguiente(iterador2)){

        if(bandera){
            TipoElemento elementoAux=siguiente(iterador2);
            conjuntoB=elementoAux->valor;
            bandera=false;
        }else{
            TipoElemento elementoaux=siguiente(iterador2);
            conjuntoB=cto_interseccion(conjuntoB,elementoaux->valor);
        }

    }

    printf("[OUTPUT] Resultado de la INTERSECCION entre los conjuntos:\n");

    cto_mostrar(conjuntoB);

}

int main(){
    bool seguirconju=true;
    bool seguiragregando=true;
    int clave=0;
    char claveChar;
    int indice=1;
    int indicecon=1;
    Lista coleccion=l_crear();
    bool otroconju=true;

    while(seguirconju){
        Conjunto conju=cto_crear();
        while(seguiragregando){
            
            printf("[INPUT] Ingrese el elemento %d del conjunto %d ('n' para terminar de cargar el conjunto):",indice,indicecon);
            if(scanf("%d",&clave)>0){
                cto_agregar(conju,te_crear(clave));
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
        l_agregar(coleccion,te_crear_con_valor(0,conju));
        indicecon++;
        indice=1;
        otroconju=true;
        while(otroconju){
            printf("[INPUT] Desea agregar otro conjunto? (1 para SI, 2 para NO):");
            if(scanf("%d",&clave)>0 && (clave==1 || clave ==2)){
                if(clave==1){
                    seguirconju=true;
                    seguiragregando=true;
                    otroconju=false;
                }else if(clave==2){
                    seguirconju=false;
                    otroconju=false;
                }
            }else{
                printf("[ERROR] ingrese una opcion valida.\n");
            }
            fflush(stdin);
        }
        
    }

    operaciones(coleccion);

    return 0; 
}