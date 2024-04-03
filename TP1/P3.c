/* 
Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.
Ejemplos:
terminoSeridFibonacci (1) => 1
terminoSeridFibonacci (5) => 8
*/
#include<stdio.h>


int fibonacci(int numero){
    
    if (numero==0)
    {
        return 0;
    }
    
    else if ((numero==1)||(numero==2)){
        return 1;
    }
    
    else
    {
        return(fibonacci(numero-1)+fibonacci(numero-2));
    }
}


int fibonacci_negativo(int numero){

    if(numero==-1)
    {
        return 0;
    }
    else if (numero==-2)
    {
        return 1;
    }
    else
    {
       return(fibonacci_negativo(numero+2)-fibonacci_negativo(numero+1));
    }
}

int main(){

    int numero;

    printf("Ingrese un numero para el termino de la serie de fibonacci: ");
    scanf("%d",&numero);


    if(numero<0){
        printf("El resultado pra el termino %d es %d\n",numero,fibonacci_negativo(numero)); 
    }
    else
    {
        printf("El resultado pra el termino %d es %d\n",numero,fibonacci(numero));
    }
    
    system("pause");
   
}

