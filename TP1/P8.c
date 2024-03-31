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

char* buscarSubconjuntos(int numbers[], int target, int longitudNumbers, char* output, int outputIndex, char* actualSubOutput, int actualSubOutputIndex, int* longitudOutput){
    if(actualSubOutputIndex == 0){
        char vector[longitudNumbers];
        actualSubOutputIndex = vector;
    }

    printf("%i\n", numbers[numbersIndex]);

    if(actualSum + numbers[numbersIndex] == target){
        printf("La suma es valida\n");
        printf("Index: %i\n", numbersIndex);
        printf("Number: %i\n", numbers[numbersIndex]);

        output[*outputSize] = numbers[numbersIndex];
        (*outputSize)++;
        
        imprimirSubconjuntos(actualSubOutputIndex, (*actualSubOutputIndex));

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

char* subconjuntosQueSumanN(int numbers[], int target, int longitud){
    for (int i = 0; i < longitud; i++){
        printf("%i\n", numbers[i]);
    }
    
    char output[longitud];
    int outputSize = 0;
    return buscarSubconjuntos(numbers, target, longitud, output, 0, NULL, 0, &outputSize);
}

int main(){
    int input[] = {10, 3, 1, 7, 4, 2};
    int target = 7;
    printf("Size %i\n", sizeof(input)/sizeof(input[0]));
    subconjuntosQueSumanN(input, target);
    
    return 0;
}