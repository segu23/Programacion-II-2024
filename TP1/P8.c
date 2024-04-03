#include <stdio.h>
#include <stdlib.h>

/*
Definir una función recursiva que dado un conjunto devuelva una lista con los
subconjuntos del mismo tales que la suma de los elementos de cada subconjunto
sumen una cantidad dada. Por ejemplo: Dado el conjunto A = {10, 3, 1, 7, 4, 2}. La
lista de los conjuntos que sumen 7 sería: R = [{3, 4}, {1, 4, 2}, {7}]
Ejemplos:
subconjuntosQueSumanN ({10, 3, 1, 7, 4, 2}, 7) => {{3, 4}, {1, 4, 2}, {7}}
subconjuntosQueSumanN ({10, 3, 1, 7, 4, 2}, 10) => {{10}, {3,7}, {3, 1, 4, 2}, {1, 7, 2}}
*/

#define MAX 100

void imprimirSubconjuntos(int subconjunto[], int longitud){
    printf("{");
    for (int i = 0; i < longitud; i++){
        printf("%i", subconjunto[i]);
        if (i < longitud - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

void copiarArray(int original[], int copia[], int longitud, int i) { 
    if (i < longitud) { 
        copia[i] = original[i]; 
        copiarArray(original, copia, longitud, ++i); 
    } 
} 

void buscarSubconjuntos(
    int conjuntoOriginal[], 
    int longitud, 
    int temp[], 
    int longitudSubconjunto, 
    int sumaDeseada, 
    int sumaActual, 
    int *cantidadSubconjuntos,
    int longitudSubconjuntos[],
    int output[MAX][MAX]
    ){    
    if (sumaActual == sumaDeseada && longitudSubconjunto > 0){
        copiarArray(temp, output[(*cantidadSubconjuntos)], longitudSubconjunto, 0);
        longitudSubconjuntos[(*cantidadSubconjuntos)] = longitudSubconjunto;
        (*cantidadSubconjuntos)++;
        
        return;
    }

    if (longitud == 0){
        return;
    }

    temp[longitudSubconjunto] = conjuntoOriginal[0];

    buscarSubconjuntos(conjuntoOriginal + 1, longitud - 1, temp, longitudSubconjunto + 1, sumaDeseada, sumaActual + temp[longitudSubconjunto], cantidadSubconjuntos,longitudSubconjuntos, output);
    buscarSubconjuntos(conjuntoOriginal + 1, longitud - 1, temp, longitudSubconjunto, sumaDeseada, sumaActual, cantidadSubconjuntos,longitudSubconjuntos, output);
}

void subconjuntosQueSumanN(int *conjuntoOriginal, int longitud, int sumaDeseada, int output[MAX][MAX], int *cantidadSubconjuntos, int longitudSubconjuntos[]){
    if (longitud == 0){
        return;
    }

    int temp[MAX] = {0};
    buscarSubconjuntos(conjuntoOriginal, longitud, temp, 0, sumaDeseada, 0, cantidadSubconjuntos, longitudSubconjuntos, output);
}

int main(){
    int conjuntoOriginal[MAX] = {0};
    int sumaDeseada;

    int input = 1;
    int inputIndex = 0;
    
    while(input > 0){
        printf("[INPUT] Ingrese el %iº número del conjunto o 0 para finalizar el ingreso: ", (inputIndex+1));
        if(scanf("%i", &input) > 0){
            conjuntoOriginal[inputIndex] = input;
            inputIndex++;
        }else{
            fflush(stdin);
            printf("[ERROR] Ha ingresado un valor incorrecto.\n");
        }
    }

    fflush(stdin);
    input = -1;

    while(input <= 0){
        printf("[INPUT] Ingrese la suma objetivo: ");
        if(scanf("%i", &input) > 0){
            sumaDeseada = input;
        }else{
            fflush(stdin);
            printf("[ERROR] Ha ingresado un valor incorrecto.\n");
        }
    }

    int cantidadSubconjuntos = 0;
    int longitudSubconjuntos[MAX] = {0};

    int output[MAX][MAX] = {0};

    subconjuntosQueSumanN(conjuntoOriginal, inputIndex, sumaDeseada, output, &cantidadSubconjuntos, longitudSubconjuntos);
    
    printf("[OUTPUT] Se han encontrado %i subconjuntos válidos:\n", cantidadSubconjuntos);

    for (int i = 0; i < cantidadSubconjuntos; i++){
        imprimirSubconjuntos(output[i], longitudSubconjuntos[i]);
    }
    
    
    return 0;
}