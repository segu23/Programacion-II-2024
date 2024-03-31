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

void imprimirSubconjuntos(int *subconjunto, int longitud){
    printf("Longitud: %i\n", longitud);
    printf("{");
    for (int i = 0; i < longitud; i++){
        printf("%i", subconjunto[i]);
        if (i < longitud - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

int* buscarSubconjuntos(int numbers[], int target, int longitudNumbers, int** output, int numbersIndex, int* outputSize, int actualSum, int outputIndex){
    if(outputIndex == 0){
        int vector[longitudNumbers];
        output[*outputSize] = vector;
    }
    printf("%i\n", numbers[numbersIndex]);

    if(actualSum + numbers[numbersIndex] == target){
        printf("La suma es valida\n");
        printf("Index: %i\n", numbersIndex);
        printf("Number: %i\n", numbers[numbersIndex]);

        output[*outputSize][outputIndex] = numbers[numbersIndex];
        (*outputSize)++;
        
        imprimirSubconjuntos(output[(*outputSize)-1], (*outputSize));

        return output;
    }else if(numbersIndex == longitudNumbers){
        printf("La suma era invalida y es el fin del array\n");
        return output;
    }else if(numbersIndex < longitudNumbers-1){
        printf("La suma era invalida y no es el fin del array\n");
        numbersIndex++;
        
        return buscarSubconjuntos(numbers, target, longitudNumbers, output, numbersIndex, outputSize, actualSum, outputIndex);
    }
}

int* subconjuntosQueSumanN(int numbers[], int target){
    printf("Size %i\n", sizeof(numbers)/sizeof(numbers[0]));
    for (int i = 0; i < 10; i++){
        printf("%i\n", numbers[i]);
    }
    
    //int output[longitud];
    int outputSize = 0;
    //return buscarSubconjuntos(numbers, target, longitud, output, 0, &outputSize, 0, 0);
}

int main(){
    int input[] = {10, 3, 1, 7, 4, 2};
    int target = 7;
    printf("Size %i\n", sizeof(input)/sizeof(input[0]));
    subconjuntosQueSumanN(input, target);
    
    return 0;
}