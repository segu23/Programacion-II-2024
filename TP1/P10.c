#include <stdlib.h>
#include <stdio.h>

int* explotar(int numeros[], int numero, int bomba, int* contador){
    
    if (numero<=bomba){
        numeros[(*contador)] = numero;
        (*contador)++;
        return numeros;
    }

    int N1 = numero/bomba;
    int N2 = numero - (N1);

    explotar(numeros, N1, bomba, contador);
    explotar(numeros, N2, bomba, contador);
}

int main(){
    int numeros[100];
    int contador = 0;
    explotar(numeros, 20, 5, &contador);

    for (int i = 0; i < contador; i++){
        printf("%i", numeros[i]);
    }

    return 0;
}