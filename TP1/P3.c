/* 
Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.
Ejemplos:
terminoSeridFibonacci (1) => 1
terminoSeridFibonacci (5) => 8
*/
#include<stdio.h>
#include<stdlib.h>

int fibonacci(int numero){
    
    if ((numero==0)||(numero==1)){
        return 1;
    }
    
    else{
        return(fibonacci(numero-1)+fibonacci(numero-2));
    }
}

int main(){

    int numero;

    printf("[INPUT] Ingrese un numero para el termino de la serie de fibonacci entre 0 y 40: ");
    scanf("%d",&numero);

    while ((numero<=0)||(numero>41))
    {
        printf("[INPUT] Ingrese un numero entre 0 y 40: ");
        scanf("%d",&numero);
    }
    
    
    printf("[OUTPUT] El resultado para el termino %d es %d\n",numero,fibonacci(numero)); 
    
    system("pause");
   
}
