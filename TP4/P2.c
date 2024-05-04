#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "colas.h"
#include "tipo_elemento.h"

#include "colas_arreglos_circular.c"
#include "tipo_elemento.c"
/*Resolver los siguientes puntos:
a. Informar si un elemento dado se encuentra en la cola.
b. Agregar un nuevo elemento en una posición dada (colarse).
c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
d. Contar los elementos de la cola.
e. Realizar una función que realice una copia de una cola.
f. Invertir el contenido de una cola sin destruir la cola original. 
*/
void mostrarMenu(){
    printf(" > Menu <\n");
    printf("\n");
    printf("Seleccione una opcion: \n");
    printf("a) Informar si un elemento dado se encuentra en la cola. \n");
    printf("b) Agregar un nuevo elemento en una posición dada (colarse). \n");
    printf("c) Dado un elemento sacarlo de la cola todas las veces que aparezca. \n");
    printf("d) Contar los elementos de la cola. \n");
    printf("e) Realizar una función que realice una copia de una cola. \n");
    printf("f) Invertir el contenido de una cola sin destruir la cola original. \n");   
    printf("x) Salir\n");
}

Cola mover(Cola C1,Cola C2){
    while (!c_es_vacia(C2)){
        TipoElemento elemnto = c_desencolar(C2);
        c_encolar(C1, elemnto);
    }
    return C1;
}

// punto a
bool c_ej2_existeclave(Cola c, int clave){
    bool resultado = false;
    Cola aux = c_crear();
    mover(aux, c);
    while (!c_es_vacia(aux)){
        TipoElemento elem1 = c_desencolar(aux);
        int igual = elem1->clave;
        if(igual == clave){
            resultado = true;
            c_encolar(c, elem1);
        }
        else{
            c_encolar(c, elem1);
        }
    }

    if (resultado == true)
    {
        printf("[INFO] La clave ingresada, existe en la Cola.\n");
    }
    else{
        printf("[INFO] La clave ingresada, no existe en la Cola.\n");
    }
    free(aux);
    return resultado;
}

//punto b 
Cola resolverPuntoB(Cola C1, int posicion, int stage){
    Cola aux = c_crear();
    Cola c2 = c_crear();
    mover(aux, C1);
    while (!c_es_vacia(aux)){
        TipoElemento elem1 = c_desencolar(aux);
        TipoElemento elemento2 = te_crear(posicion);
        if (stage == posicion){
            c_encolar(c2, elemento2); //chequear encolar un entero (ver si tengo que poner un tipo elemento).
        }
        c_encolar(c2, elem1);
        c_encolar(C1, elem1);
        stage++;
        
    }
    return c2;
}

Cola c_ej2_colarelemento(Cola c, int posicionordinal){
    int stage = 1; 
    Cola resultado = resolverPuntoB(c, posicionordinal, stage);
    c_mostrar(resultado);
    return resultado;
}



//punto c
Cola c_ej2_sacarelemento(Cola c, int clave){
    Cola aux = c_crear();
    Cola c2 = c_crear();
    mover(aux, c);
    while (!c_es_vacia(aux)){
        TipoElemento elem1 = c_desencolar(aux);
        int igual = elem1->clave;
        if(igual == clave){
            c_encolar(c, elem1);
        }
        else{
            c_encolar(c2, elem1);
            c_encolar(c, elem1);
        }
    }
    free(aux);
    c_mostrar(c2);
    return c2;
}


//punto d 
int c_ej2_contarelementos(Cola c){
    int contador = 0;
    Cola aux = c_crear();
    mover(aux, c);
    while (!c_es_vacia(aux)){
        TipoElemento elem1 = c_desencolar(aux);
        c_encolar(c, elem1);
        contador++;
    }
    printf("[INFO] La cantidad de elementos dentro de la Cola es de: %d\n", contador);
    free(aux);
    return contador;
}


//punto e
Cola c_ej2_copiar(Cola c){
    Cola aux = c_crear();
    Cola aux2 = c_crear();
    if (c_es_vacia(c)) {
        return c; 
    }

    mover(aux, c);
    while (!c_es_vacia(aux)){
        TipoElemento elem1 = c_desencolar(aux);
        c_encolar(c, elem1);
        c_encolar(aux2, elem1);
    }
    free(aux);
    c_mostrar(aux2);
    return aux2;
}

//punto f 

void invertirRecursivamente(Cola c) {
    if (c_es_vacia(c)) {
        return; 
    }

    TipoElemento elemento = c_desencolar(c); 
    invertirRecursivamente(c); 
    c_encolar(c, elemento); 
}

Cola c_ej2_invertir(Cola c) {
    Cola aux = c_crear();
    Cola aux2 = c_crear();
    if (c_es_vacia(c)){
        return c;
    }
    
    mover(aux, c);
    while (!c_es_vacia(aux)){
        TipoElemento elemnto = c_desencolar(aux);
        c_encolar(c, elemnto);
        c_encolar(aux2, elemnto);
    }

    invertirRecursivamente(aux2); 
    c_mostrar(aux2);
    return aux2; 
}


int random_number(int min_num, int max_num){
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    result = (rand() % (hi_num - low_num)) + low_num;

    return result;
}

Cola crearListaAleatoria(int longitud){
    Cola colaAleatoria = c_crear();
    
    srand(time(NULL));
    for(int i = 0; i < longitud; i++) {
        int number = random_number(0, 10);
        TipoElemento tipoElemento = te_crear(number);
        c_encolar(colaAleatoria, tipoElemento);
    }

    return colaAleatoria;
}

int main(){
    Cola cola = crearListaAleatoria(5);
    char input;
    
    
    while(input != 'x') {
        mostrarMenu();
        printf("[INPUT] Seleccione una opcion: ");
        fflush(stdin);
        while(scanf("%c", &input) == 0){
            printf("[ERROR] Ingrese una opcion valida.\n");
            fflush(stdin);
        }

        switch(input){
            case 'a': {
                c_mostrar(cola);
                int clave;
                printf("[INPUT] Ingrese la clave a buscar: ");
                scanf("%d", &clave);
                c_ej2_existeclave(cola, clave);
                break;
            }
            case 'b': {
                c_mostrar(cola);
                int posicion;
                printf("[INPUT] Ingrese la posición en la que desea insertar el nuevo elemento: ");
                scanf("%d", &posicion);
                c_ej2_colarelemento(cola, posicion);
                break;
            }
            case 'c': {
                c_mostrar(cola);
                int clave;
                printf("[INPUT] Ingrese la clave del elemento que desea eliminar: ");
                scanf("%d", &clave);
                c_ej2_sacarelemento(cola, clave);
                break;
            }
            case 'd': {
                c_mostrar(cola);
                c_ej2_contarelementos(cola);
                break;
            }
            case 'e': {
                c_mostrar(cola);
                Cola nueva = c_crear();
                nueva = c_ej2_copiar(cola);
                printf("[INFO] Copia de la Cola creada.\n");

                break;
            }
            case 'f': {
                c_mostrar(cola);
                c_ej2_invertir(cola);
                printf("[INFO] Contenido de la Cola invertido.\n");
                break;
            }
            case 'x': {
                printf("[INFO] Saliendo del programa...\n");
                break;
            }
            default: {
                printf("[ERROR] Opción inválida. Por favor, seleccione una opción válida.\n");
                break;
            }
        }
        bool sigo= true;
        while (sigo==true)
        {
            printf("[INFO] Pulsa para continuar...\n");
            getchar();
            getchar();
            sigo = false;
        }
        
    }
    system("pause");
    return 0;
}
