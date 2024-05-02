/*5.Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
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

int c_ej5_divisortotal(Cola c, bool *fuetotal, int tamanio){
    int contador = 0;
    int divisor = 0;
    *fuetotal = false;

    for (int i = 0; i < tamanio; i++){                                        
        TipoElemento aux = c_desencolar(c);
        TipoElemento div = aux;
        c_encolar(c, aux);

        for (int t = 1; t <= tamanio; t++){                                   
            aux = c_desencolar(c);
            if (aux->clave % div->clave == 0){
                contador++;
            } 
            c_encolar(c, aux);
        }
        if(contador == tamanio){           
            divisor = div->clave;
            *fuetotal = true;
            break;
        }
        else if (contador >= (float)(tamanio / 2)){ 
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
            int divisor = c_ej5_divisortotal(c, &fuetotal, longitud);
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