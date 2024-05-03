/*
5.Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
	obtener todos los valores que son Divisores Totales o parciales.
	Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta.
	Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola (es decir a la mitad de los elementos).
    retorna el valor del divisor total o parcial en la función.   Si no hay ni divisor total ni parcial retornar "0".
    En la variable de referencia "&fuetotal" debe venir solo con true cual el divisor es total, caso contrario false.
*/
#include <stdio.h>
#include <stdlib.h>
#include "tipo_elemento.h"
#include "colas.h"

int c_ej5_divisortotal(Cola c, bool *fuetotal){
    int contador = 0;
    int divisor = 0;
    *fuetotal = false;
    Cola caux = c_crear();
    int longit = 0;

    while (!c_es_vacia(c)){
        TipoElemento elemento = c_desencolar(c);
        c_encolar(caux,elemento);
        longit++;
    }
    
    while (!c_es_vacia(caux)){
        TipoElemento elemento  = c_desencolar(caux);
        c_encolar(c,elemento);
    }
    

    for (int i = 0; i < longit; i++){                                        
        TipoElemento aux = c_desencolar(c);
        TipoElemento div = aux;
        c_encolar(c, aux);

        for (int t = 1; t <= longit; t++){                                   
            aux = c_desencolar(c);
            if (aux->clave % div->clave == 0){
                contador++;
            } 
            c_encolar(c, aux);
        }
        if(contador == longit){           
            divisor = div->clave;
            *fuetotal = true;
        }
        else if(longit==3){
            if ((float)(contador / 2) >= (float)(longit / 2)){
                divisor = div->clave;
            }
        }
        else if (contador >= (float)(longit / 2)){ 
            divisor = div->clave;
        }
        contador = 0;
    }
    return divisor;
}

int main(){
    Cola c = c_crear();
    int longitud, clave;
    bool repetido, fuetotal;
    TipoElemento elemento;
    printf("Ingresar Longitud de la cola (minimo 2): \n");
    scanf("%d", &longitud);
    fflush(stdin);

    if (longitud >= 2){
        for (int i = 1; i <= longitud; i++) {
            do{
                repetido = false;        
                printf("Ingrese el elemento %d de la cola (mayor o igual a 2): ", i);
                scanf("%d", &clave);
                fflush(stdin);
                if (clave >= 2){
                    elemento = te_crear(clave);
                    TipoElemento recuperado = c_recuperar(c);
                    if (recuperado != NULL && recuperado->clave == elemento->clave){
                        repetido = true;
                        printf("Clave repetida, ingresar de nuevo \n");
                    }
                }else{
                    printf("El numero debe ser mayor o igual a 2, Ingresar de nuevo.\n");
                    repetido = true;
                }
            }while(repetido);
            c_encolar(c, elemento);
        }   
        if (!c_es_vacia(c)){
            int divisor = c_ej5_divisortotal(c, &fuetotal);
            if (divisor != 0){
                if (fuetotal){
                    printf("Divisor total: %d\n", divisor);
                } 
                else {
                    printf("Divisor parcial: %d\n", divisor);
                }
            } else {
                printf("No hay divisor total ni parcial.\n");
            }
            printf("Cola Original:\n");
            c_mostrar(c);           
        } 
        else{
            printf("Cola vacia.\n");
        }       
    }
    else{
        printf("Longitud invalida, debe ser mayor o igual a 2.\n");
    }

    return 0;
}