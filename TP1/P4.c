/*
Dados los números enteros m y n, construir una función recursiva que devuelva el 
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener 
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta 5 cifras 
decimales (si es necesario).  
Ejemplos: 
division (10,2) => 5 
division (22,3) => 7,33333 
*/

#include <stdio.h>
#include <stdlib.h>

float division(int m, int n){
    if(m<n){
        return (float) m/n;
    }
    else {
        return 1 + division(m-n,n);
    }
}

int main(){
    int m;
    int n;
    printf("Ingrese el Primer Numero (Dividendo): \n");
    if(scanf("%d",&m)!=1){
        printf("Error no se ha introducido un Numero Entero en el Dividendo");
    }
    printf("Ingrese el Segundo Numero (Divisor): \n");
    if(scanf("%d",&n)!=1){
        printf("Error no se ha introducido un Numero Entero en el Divisor");
    }
    if (n==0){
        printf("Error el Divisor no puede ser Cero");
    }

    float resultado=division(m,n);
    if (m % n ==0){
        printf("Cociente: %.0f \n",resultado);    
    }
    else{
        printf("Cociente: %.5g \n",resultado);  // Hasta Un Maximo de 5 decimales
    }
    system("pause");

    return 0;
}