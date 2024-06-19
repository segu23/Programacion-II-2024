#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjuntos.h"
#include "tipo_elemento.h"

#define MAX 100

/*
Desarrollar un algoritmo que dado tres conjuntos puedan demostrar la propiedad de la
transitividad: “si A es subconjunto de B y B a su vez es subconjunto de C, entonces A
es subconjunto de C”.
*/

bool BuscandoSubconjuntos(Conjunto C1, Conjunto C2) {     
    int nC1 = cto_cantidad_elementos(C1);
    int nC2 = cto_cantidad_elementos(C2);
    if (nC1 == 0 && nC2 == 0) return true;

    int contador = 0;
    TipoElemento X;

    for (int i = 1 ; i <= nC1 ; i++) {
        X = cto_recuperar(C1, i);
        if (cto_pertenece(C2, X->clave)) contador++;
    }

    if    (contador == nC1) return true;
    else                    return false;
}

int main() {
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
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoC=cto_crear();
    while(seguiragregando){
            
        printf("[INPUT] Ingrese el elemento %d del tercer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoC,te_crear(clave));
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

    printf("\n/ Verificando propiedad de la transitividad . . .\n");

    bool AB = BuscandoSubconjuntos(conjuntoA, conjuntoB);
    bool BC = BuscandoSubconjuntos(conjuntoB, conjuntoC);
    bool AC = BuscandoSubconjuntos(conjuntoA, conjuntoC);

    if (AB) printf("\n> A es subconjunto de B");
    else    printf("\n> A no es subconjunto de B");

    if (BC) printf("\n> B es subconjunto de C");
    else    printf("\n> B no es subconjunto de C");

    if (AC) printf("\n> A es subconjunto de C");
    else    printf("\n> A no es subconjunto de B");    

    if (AB && BC && AC) printf("\n\n/ Conclusion: se verifica la propiedad de la transitividad . . .\n\n");
    else                printf("\n\n/ Conclusion: no se verifica la propiedad de la transistividad . . .\n\n");

    return 0;
}
