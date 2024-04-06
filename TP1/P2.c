#include <stdlib.h>
#include <stdio.h>

int producto(int m,int n){
    if(n==0){  
        return 0;   
    }
    else{
        return m+producto(m,n-1);
    }
}

int main(){
    int m;
    int n;
    int resultado;
    int lectura;

    printf("[INPUT] Ingrese el primer numero(multiplicando): ");
    lectura=scanf("%d", &m);

    while(lectura!=1){
        printf("[ERROR] No se ingreso un numero entero. Vuelva a ingresar el dato.\n");
        printf("[INPUT] Ingrese el primer numero(multiplicando): ");
        fflush(stdin);
        lectura=scanf("%d", &m);
    }

    printf("[INPUT] Ingrese el segundo numero(multiplicador): ");
    lectura=scanf("%d", &n);

    while(lectura!=1){
        printf("[ERROR] No se ingreso un numero entero. Vuelva a ingresar el dato.\n");
        printf("[INPUT] Ingrese el segundo numero(multiplicador): ");
        fflush(stdin);
        lectura=scanf("%d", &n);
    }

    resultado=producto(m,n);

    printf("[OUTPUT] El producto de la multiplicacion es: %d\n",resultado);
    system("pause");

    return 0;
}