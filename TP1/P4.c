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
#include <stdbool.h>

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
    
    bool mIngresado = false;
    bool nIngresado = false;

    while(!mIngresado){
        printf("[INPUT] Ingrese el Primer Numero (Dividendo): \n");
        
        if(scanf("%d",&m) != 1){
            fflush(stdin);
            printf("[ERROR] No se ha introducido un Numero Entero en el Dividendo.\n");
        }
        else{
            mIngresado = true;
        }
    }

    while(!nIngresado){
        printf("[INPUT] Ingrese el Segundo Numero (Divisor): \n");
        
        if(scanf("%d",&n) != 1){
            fflush(stdin);
            printf("[ERROR] No se ha introducido un Numero Entero en el Divisor.\n");
        }
        else if (n==0){
            fflush(stdin);
            printf("[ERROR] El Divisor no puede ser Cero.\n");
        }
        else{
            nIngresado = true;
        }
    }

    float resultado = division(m,n);
    if (m % n == 0){
        printf("[OUTPUT] Cociente: %.0f \n",resultado);    
    }
    else{
        printf("[OUTPUT] Cociente: %.5f \n",resultado);  // Hasta Un Maximo de 5 decimales
    }
    
    system("pause");

    return 0;
}