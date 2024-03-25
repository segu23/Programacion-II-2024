/*
Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de
números.
Ejemplos:
agregarSeparadorMiles (“123456”) => “123.456”
agregarSeparadorMiles (“12345678”) => “12.345.678” 
*/
#include <stdio.h>
#include <string.h>

int agregarSeparadorMiles(char* numero, int largoUsado, int contador){
    if (contador<3){
        contador++;
        largoUsado--;
        agregarSeparadorMiles(numero, largoUsado, contador);
    }
    else if(largoUsado>0){
        contador=0;
        numero[largoUsado+3]=numero[largoUsado+2];
        numero[largoUsado+2]=numero[largoUsado+1];
        numero[largoUsado+1]=numero[largoUsado];
        numero[largoUsado]= '.';
        printf("%s\n", numero);
        agregarSeparadorMiles(numero, largoUsado-1, contador);
    }
    else{
        return 0;
    }
}

int main(){
    char* numero = malloc(sizeof(char)*100);
    puts("A que numero queres agregar los puntos de los miles: ");
    gets(&numero);
    int largoString = strlen(&numero);
    agregarSeparadorMiles(&numero, largoString, 0);
    system("pause");
}