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
    cto_mostrar(dif1);
    Conjunto dif2=cto_diferencia(conjuntoB,conjuntoA);
    cto_mostrar(dif2);

    Conjunto resultado=cto_union(dif1,dif2);
    cto_mostrar(resultado);


}

int main(){
    Conjunto conju=cto_crear();
    cto_agregar(conju,te_crear(1));
    cto_agregar(conju,te_crear(2));
    cto_agregar(conju,te_crear(3));
    //cto_mostrar(conju);

    Conjunto conju2=cto_crear();
    cto_agregar(conju2,te_crear(3));
    cto_agregar(conju2,te_crear(4));
    cto_agregar(conju2,te_crear(5));

    diferenciaSime(conju,conju2);

    return 0;

}