#include <stdlib.h>
#include <stdio.h>
#define MAX 100

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

    return numeros;
}

int* explosion (int n, int b){
    int *numeros = calloc(MAX,sizeof(int));
    int contador = 0;

    explotar(numeros, n, b, &contador);

    return numeros;
}

int main(){
    int numeroExplotar = -1;
    int bomba = -1;

    while (numeroExplotar<=0){
        printf("[INPUT] Ingrese el numero a explotar: ");
        if (scanf("%d", &numeroExplotar)==0){
            fflush(stdin);
            printf("[ERROR] El numero ingresado no es un valor permitido\n");
        }
    }
        
    while (bomba<=0){
        printf("[INPUT] Ingrese la bomba: ");
        if (scanf("%d", &bomba)==0){
            fflush(stdin);
            printf("[ERROR] El numero ingresado no es un valor permitido\n");
        }
    }

    int *resultado = explosion(numeroExplotar, bomba);

    for (int i = 0; i < MAX; i++){
        if (resultado[i]>0){
            printf("%i ", resultado[i]);
        }
    }

    system("pause");

    return 0;
}