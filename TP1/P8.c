#include <stdio.h>

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
    printf("{");
    for (int i = 0; i < longitud; i++){
        printf("%i", subconjunto[i]);
        if (i < longitud - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

int main(){
    int input[] = {10, 3, 1, 7, 4, 2};
    int target = 7;
    
    return 0;
}