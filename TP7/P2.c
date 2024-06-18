#include "stdlib.h"
#include "stdio.h"
#include "listas.h"
#include "conjuntos.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-avl.h"
#include "stdbool.h"


// Desarrollar un algoritmo que dado dos conjuntos de elementos tipo numérico (clave)
// verifique las operaciones de Unión, Intersección, Diferencia y Pertenencia.

void operaciones(Conjunto A,Conjunto B){
    Conjunto Union=cto_crear();
    Conjunto Interseccion=cto_crear();
    Conjunto Diferencia=cto_crear();
    Conjunto PertenenciaA=cto_crear();
    Conjunto PertenenciaB=cto_crear();
    int clave=0;

    Union=cto_union(A,B);
    Interseccion=cto_interseccion(A,B);
    Diferencia=cto_diferencia(A,B);

    printf("\nIngrese la clave para mostrar pertenencia en los conjuntos ");
    scanf("%d",&clave);

    if(cto_pertenece(A,clave)){
        printf("\nEl elemento %d pertenece al conjunto A \n",clave);
    }else{
        printf("La clave no esta en el conjunto A\n");
    }
    if(cto_pertenece(B,clave)){
        printf("\nEl elemento %d pertenece al conjunto B \n",clave);
    }else{
        printf("La clave no esta en el conjunto B\n\n");
    }

    printf("\nLos elementos que tienen Union son: \n");
    cto_mostrar(Union);
    printf("\n\nLos elementos que tienen Interseccion son: \n");
    cto_mostrar(Interseccion);
    printf("\n\nLos elementos que tienen Dieferencia son: \n");
    cto_mostrar(Diferencia);
}




int main(){
    bool seguiragregando=true;
    int clave=0;
    char claveChar;
    int indice=1;

   Conjunto A=cto_crear();
   while(seguiragregando){ 
       printf("[INPUT] Ingrese el elemento %d del conjunto A ('n' para terminar de cargar el conjunto):",indice);
       if(scanf("%d",&clave)>0){
           cto_agregar(A,te_crear(clave));
           indice++;
        }else{
           if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
               seguiragregando = false;
               printf("[INFO] Terminando ingreso del conjunto A.\n");
            }
           else{
               printf("[ERROR] Debe ingresar un valor valido.\n");
            }

           fflush(stdin);
        }
    }

    seguiragregando=true;
    Conjunto B=cto_crear();
    while(seguiragregando){ 
        printf("[INPUT] Ingrese el elemento %d del conjunto B ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(B,te_crear(clave));
            indice++;
        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("[INFO] Terminando ingreso del conjunto B.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }
    cto_mostrar(A);
    cto_mostrar(B);
    operaciones(A,B);
}
