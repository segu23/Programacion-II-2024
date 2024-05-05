#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "colas.h"
#include "tipo_elemento.h"

bool c_ej3_iguales(Cola c1, Cola c2){
    TipoElemento elementoaux=te_crear(0);
    TipoElemento elementoaux2=te_crear(0);
    Cola caux=c_crear();
    bool resultado=true;

    while(!c_es_vacia(c2) && !c_es_vacia(c1)){
        elementoaux=c_desencolar(c1);
        elementoaux2=c_desencolar(c2);
        if(elementoaux->clave!=elementoaux2->clave){
            resultado=false;
        }
        c_encolar(caux,elementoaux);
        c_encolar(c1,elementoaux2);
    }

    while(!c_es_vacia(caux)){
        elementoaux=c_desencolar(c1);
        c_encolar(c2,elementoaux);
        elementoaux2=c_desencolar(caux);
        c_encolar(c1,elementoaux2);
    }

    return resultado;
}

void cargarCola(Cola cola, int nCola){
    bool seguirAgregando = true;
    int IngresoNumero;
    int index = 1;
    char inputChar;
    while (seguirAgregando){
        printf("[INPUT] Ingrese el #%i elemento de la cola #%i o 'n' para terminar: ", index, nCola);

        if (scanf("%d", &IngresoNumero) > 0 && IngresoNumero > 0){
            c_encolar(cola, te_crear(IngresoNumero));
            index++;
        }
        else{
            if (scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Ingreso de la cola terminado.\n");
            }
            else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
                fflush(stdin);
            }
        }
    }
}


int main(){
    bool resultado;
    Cola cola1=c_crear();

    printf("[INFO] Carga de la cola 1.\n");
    cargarCola(cola1,1);
    c_mostrar(cola1);

    Cola cola2=c_crear();

    printf("[INFO] Carga de la cola 2.\n");
    cargarCola(cola2,2);
    c_mostrar(cola2);

    resultado=c_ej3_iguales(cola1,cola2);

    if(resultado==true){
        printf("[OUTPUT] Las COLAS son IGUALES.\n");
    }else{
        printf("[OUTPUT] Las COLAS son DISTINTAS.\n");
    }

    return 0;
}