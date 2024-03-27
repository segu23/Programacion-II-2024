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
    float cociente=0;
    if(m<n){
        cociente= (float) m/n;
    }
    else{
    
        while (m>=n){
            m-=n;
            cociente++;
        }

        if (m!=0){
            float decimal = (float)m / n;
            cociente+=decimal;
        }
    }
    return cociente;
}

int main(){
    int m;
    int n;
    printf("Ingrese el Primer Numero (Dividendo): \n");
    scanf("%d",&m);

    printf("Ingrese el Segundo Numero (Divisor): \n");
    scanf("%d",&n);

    float resultado=division(m,n);
    if (m % n ==0){
        printf("Cociente: %.0f \n",resultado);    
    }
    else{
        printf("Cociente: %.5f \n",resultado);
    }
    system("pause");

    return 0;
}