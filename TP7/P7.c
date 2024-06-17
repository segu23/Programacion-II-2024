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
bool es_subconjunto_total(Conjunto X, Conjunto Y) {
    Conjunto resultado = cto_diferencia(X, Y);
    return cto_es_vacio(resultado);
}

bool es_subconjunto_parcial(Conjunto X, Conjunto Y) {
    int cantidad = cto_cantidad_elementos(X);
    Conjunto resultado = cto_diferencia(X, Y);
    int cantidad_f = cto_cantidad_elementos(resultado);
    
    return cantidad_f <= (cantidad / 2);

}

void determinar_subconjuntos(Conjunto A, Conjunto B, Conjunto C) {
    Conjunto conjuntos[3] = {A, B, C};
    char* nombres[3] = {"A", "B", "C"};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                if (es_subconjunto_total(conjuntos[i], conjuntos[j])) {
                    printf("%s es un subconjunto total de %s\n", nombres[i], nombres[j]);
                } else if (es_subconjunto_parcial(conjuntos[i], conjuntos[j])) {
                    printf("%s es un subconjunto parcial de %s\n", nombres[i], nombres[j]);
                }
            }
        }
    }
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
            TipoElemento elem1 = te_crear(clave);
            cto_agregar(conjuntoA,elem1);
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
            TipoElemento elem2 = te_crear(clave);
            cto_agregar(conjuntoB,elem2);
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

    Conjunto conjuntoC=cto_crear();
    while(seguiragregando){
            
        printf("[INPUT] Ingrese el elemento %d del tercer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            TipoElemento elem3 = te_crear(clave);
            cto_agregar(conjuntoC,elem3);
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
    
    determinar_subconjuntos(conjuntoA, conjuntoB, conjuntoC);
    

    return 0;
}