#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7.
Ejemplos:
32291 -> 1x2=2.
3229 - 2 =
3227 -> 7x2=14.
322 - 14 =
308 -> 8x2=16
30 - 16 =
14 -> Múltiplo de 7
divisiblePor7 (32291) => verdadero
110 -> 0 x 2 = 0
11 – 0 =
11 -> No múltiplo de 7
divisiblePor7 (110) => falso
*/

bool divisiblePor7(int numero){
    if(numero < 70){
        return numero % 7 == 0;
    }

    int aux = (numero/10) - (numero%10 * 2);

    return divisiblePor7(aux);
}

int main(){
    int numero;
    
    printf("Ingresa el numero a comprobar si es divisible por 7: \n");
    scanf("%d", &numero);

    while(numero < 0){
        printf("El numero ingresado debe ser mayor o igual a 0.\n");
        scanf("%d", &numero);
    }

    bool divisible = divisiblePor7(numero);


    if(divisible){
        printf("El numero %i ES divisible por 7.\n", numero);
    }else{
        printf("El numero %i NO ES divisible por 7.\n", numero);
    }

    system("pause");
    
    return 0;
}