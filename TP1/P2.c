#include <stdlib.h>
#include <stdio.h>

int producto(int m,int n){
    if(n==0){
        
        return 0;
        
    }else{

        return m+producto(m,n-1);
    }

}

int main(){
    int m;
    int n;
    int resultado;
    int lectura;

    printf("ingrese el primer numero(multiplicando):");
    lectura=scanf("%d", &m);
    while(lectura!=1){
        printf("ERROR: No se ingreso un numero entero. Vuelva a ingresar el dato.\n");
        printf("ingrese el primer numero(multiplicando):");
        fflush(stdin);
        lectura=scanf("%d", &m);
    }
    printf("ingrese el segundo numero(multiplicador):");
    lectura=scanf("%d", &n);
    while(lectura!=1){
        printf("ERROR: No se ingreso un numero entero. Vuelva a ingresar el dato.\n");
        printf("ingrese el segundo numero(multiplicador):");
        fflush(stdin);
        lectura=scanf("%d", &n);
    }

    resultado=producto(m,n);

    printf("el producto de la multiplicacion es: %d",resultado);


    return 0;
}