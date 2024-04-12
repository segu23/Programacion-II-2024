#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tipo_elemento.c"
#include "listas_arreglos.c"
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

int main(){
    Lista listaPolinomio = l_crear();
    bool seguirIngresando = true;
    int gradoActual = 0;
    int terminoElegido;
    char opcionSeguir[1];
    
    while (seguirIngresando){
        fflush(stdin);
        if (gradoActual==0){
            printf("[INPUT] Ingrese el termino independiente: ");
        }
        else{
            printf("[INPUT] Ingrese coeficiente de x para x^%i: ", gradoActual);
        }

        bool valido = false;
        while (!valido){
            if (scanf("%i", &terminoElegido)>0){
                l_agregar(listaPolinomio, te_crear(terminoElegido));
                fflush(stdin);
                printf("Agregado!\n");
                valido = true;
                gradoActual++;

                fflush(stdin);
                printf("Desea agregar otro coeficiente? (y o n): ");
                scanf("%s", opcionSeguir);

                if (!strcmp(opcionSeguir,"y")){
                    seguirIngresando = true;
                }
                else{
                    seguirIngresando = false;
                }
            }
            if (!valido){
                fflush(stdin);
                printf("[ERROR] Debe ingresar un numero correcto.\n");
                valido = true;
            }
        }
    }

    Iterador iter = iterador(listaPolinomio);
    int suma = 0;
    int indice = 0;
    int x=3;

    char polinomioResultado[100] = "";
    char buffer[100];

    while (hay_siguiente(iter)){
        TipoElemento elementoActual = siguiente(iter);
        suma += elementoActual->clave*pow(x,indice);
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

    printf("El polinomio resultante es f(x) = %s\n", polinomioResultado);
    printf("Si reemplazamos %i por la X en el polinomio el resultado da %i\n",x, suma);
    return 0;
}