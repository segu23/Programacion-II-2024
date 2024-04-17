/*
Generar un algoritmo que guarde en una lista enlazada los coeficientes de un polinomio.
Realizar una función que dada la lista de coeficientes y un cierto valor de “X” nos devuelva
el valor del polinomio para ese punto.
Luego realizar un proceso que dado un rango de valores de “X” y un valor de intervalo
“I”, retorne una lista con los valores de “Y” o “F(x)”.
Ejemplo: si el polinomio es F(x) = 2x + 1. Se pide retornar los valores de F(x) entre los
“X” -1 y 1 de a “0,5”. Es decir se deberían retornar los valores de F(-1), F(-0,5), F(0),
F(0,5) y F(1). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tipo_elemento.h"
#include "listas.h"

void insertar_string(char *destino, const char *origen) {
    int longitud_destino = strlen(destino);
    int longitud_origen = strlen(origen);

    for (int i = longitud_destino; i >= 0; i--) {
        destino[i + longitud_origen] = destino[i];
    }

    for (int i = 0; i < longitud_origen; i++) {
        destino[i] = origen[i];
    }
}

char* formarPolinomio(Lista polinomio){
    Iterador iter = iterador(polinomio);
    int indice = 0;

    char* polinomioResultado = calloc(100,sizeof(char));
    char buffer[100];

    while (hay_siguiente(iter)){
        TipoElemento elementoActual = siguiente(iter);
        char termino[50]="";
                
        if ((elementoActual->clave)!=0){
            
            if ((elementoActual->clave) > 0){
                if (hay_siguiente(iter)){
                    strcat(termino," + "); 
                }
            }
            else{
                strcat(termino," - ");  
            }

            strcat(termino,itoa(abs(elementoActual->clave),buffer,10));
            if (indice>1){
                strcat(termino,"x^");
                strcat(termino,itoa(indice,buffer,10));
            }
            else if(indice!=0){
                strcat(termino,"x");
            }
        }
        
        insertar_string(polinomioResultado, termino);
        indice++;
    }

    return polinomioResultado;
}

float calcularPolinomio(Lista polinomio, float x){    
    Iterador iter = iterador(polinomio);

    float suma = 0;
    int indice = 0;

    while (hay_siguiente(iter)){
        TipoElemento elementoActual = siguiente(iter);
        suma += elementoActual->clave*pow(x,indice);
        indice++;
    }

    return suma;
}

struct ResultadoFuncion {
    float x;
    float resultado;
};

Lista calculcarXIntervalo(Lista polinomio, int x1, int x2, float espaciado){
    Lista intervalos = l_crear();
    float actual = x1;
    int indice = 0;

    while ((actual<=x2 && espaciado>0) || (actual>=x2 && espaciado<0)){
        struct ResultadoFuncion* resultadoFuncion = malloc(sizeof(struct ResultadoFuncion));
        (*resultadoFuncion).resultado = calcularPolinomio(polinomio, actual);
        (*resultadoFuncion).x = actual;
        l_agregar(intervalos, te_crear_con_valor(indice, (void*) resultadoFuncion));
        actual += espaciado;
        indice++;
    }

    return intervalos;
}

int cargarX(int numeroDeX){
    int x; 
    bool seguirIngresando = true;
    while (seguirIngresando){
        printf("[INPUT] Determine el #%i numero del intervalo: ", numeroDeX);
        if (scanf("%i", &x)>0){
            printf("[INFO] Agregado!\n");
            seguirIngresando=false;
        }
        else{
            printf("[ERROR] Ingrese un valor numerico valido.\n");
        }
    }
    
    return x;
}

float cargarEspaciado(int numero1, int numero2){
    float espaciado;
    bool seguirIngresando = true;

    while (seguirIngresando){
        printf("[INPUT] Ingrese su numero de espaciado: ");
        if (scanf("%f", &espaciado)>0 && ((espaciado<0 && numero1>=numero2) || (espaciado>0 && numero1<numero2))){
            printf("[INFO] Agregado!\n");
            seguirIngresando=false;
        }
        else{
            if ((numero1>numero2) && (espaciado>0)){
                printf("[ERROR] El espaciado tiene que ser un numero negativo\n");
            }
            else if((numero1<numero2) && (espaciado<0)){
                printf("[ERROR] El espaciado tiene que ser un numero positivo\n");
            }
            else{
                printf("[ERROR] Ingrese un valor numerico valido.\n");
            }
        }
    }
    
    return espaciado;
}

int main(){
    Lista listaPolinomio = l_crear();
    bool seguirIngresando = true;
    int gradoActual = 0;
    int terminoElegido;
    char opcionSeguir;
    
    while (seguirIngresando){
        if (gradoActual==0){
            printf("[INPUT] Ingrese el termino independiente: ");
        }
        else{
            printf("[INPUT] Ingrese coeficiente de x para x^%i o 'n' para terminar: ", gradoActual);
        }

        if (scanf("%i", &terminoElegido)>0){
            l_agregar(listaPolinomio, te_crear(terminoElegido));
            printf("[INFO] Agregado!\n");
            gradoActual++;
        }
        else{
            if (scanf("%c", &opcionSeguir)>0 && opcionSeguir == 'n'){
                printf("[INFO] Finalizando carga del polinomio.\n");
                seguirIngresando = false;
            }
            else{
                printf("[ERROR] Debe ingresar un numero correcto.\n");
            }
            fflush(stdin);
        }
    }

    int x1 = cargarX(1);
    int x2 = cargarX(2);
    float espaciado = cargarEspaciado(x1,x2);


    char *polinomioResultado = formarPolinomio(listaPolinomio);
    Lista polinomioXIntervalos = calculcarXIntervalo(listaPolinomio, x1, x2, espaciado);
    Iterador iter = iterador(polinomioXIntervalos);

    printf("[OUTPUT] El polinomio resultante es f(x) = %s\n", polinomioResultado);

    while (hay_siguiente(iter)){
        TipoElemento elementoActual = siguiente(iter);
        printf("f(%.1f) = %.1f\n", ((struct ResultadoFuncion*)elementoActual->valor)->x ,((struct ResultadoFuncion*) elementoActual->valor)->resultado);
    }

    return 0;
}