#include <stdlib.h>
#include "listas_punteros.c"
#include "tipo_elemento.c"
enum TipoRelacionLista {
    IGUAL,
    MAYOR,
    MENOR
};  


int ListaMayor(Lista L1, Lista L2){

    int clavesMayores=0;
    int clavesMenores=0;

    int longitud1= l_longitud( L1);
    int longitud2= l_longitud( L2);

    Iterador ite = iterador(L1);
    Iterador ite2 = iterador(L2);


    if (longitud1 != longitud2){
        printf("[ERROR] Las listas no tienen en mismo tamanio\n");
        exit(-1);
    }

    while (hay_siguiente(ite) && hay_siguiente(ite2)){
        TipoElemento elementoL1 = siguiente( ite);
        TipoElemento elementoL2 = siguiente( ite2);

        if(elementoL1 ->clave > elementoL2->clave){
            clavesMayores++;
        }
        else if(elementoL1 ->clave < elementoL2->clave){
            clavesMenores++;
        }


    }

    
    enum TipoRelacionLista TipoLista;
    
    if(clavesMayores > clavesMenores){
        TipoLista = MAYOR;
    }
    else if (clavesMayores < clavesMenores){
        TipoLista = MENOR;

    }
    else TipoLista = IGUAL;
    

}

int main(){
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    int inputNumber;
    char inputChar;
    bool seguirAgregando = true;

    printf("[INPUT] Agregar valores a lista1:\n");
    while(seguirAgregando){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L1, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    printf("[INPUT] Agregar valores a lista2:\n");
    while(seguirAgregando){
        printf("[INPUT] Ingrese un valor o 'n' para terminar: ");

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L2, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("[INFO] Terminando ingreso de la primer lista.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }
    
    enum TipoRelacionLista TipoLista = ListaMayor(L1, L2);
    switch(TipoLista) {
        case MAYOR:
            printf("L1 es mayor a L2\n");
            break;
        case MENOR:
            printf("L1 es menor a L2\n");
            break;
        case IGUAL:
            printf("L1 es igual a L2\n");
            break;
    }

    return 0;
}