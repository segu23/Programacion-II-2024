/*
Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de
números.
Ejemplos:
agregarSeparadorMiles (“123456”) => “123.456”
agregarSeparadorMiles (“12345678”) => “12.345.678” 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* agregarSeparadorMiles(char* numero, int cantidadPuntos, int longitudUsada, int contador){
    if (longitudUsada==0){
        return numero;
    }

    if (contador<=3){
        numero[longitudUsada+cantidadPuntos] = numero[longitudUsada];

        if (cantidadPuntos==1){
            numero[longitudUsada] = '.';
        }

        contador++;
        longitudUsada--;
        return agregarSeparadorMiles(numero, cantidadPuntos, longitudUsada, contador);
    }
    else{
        contador=1;
        numero[longitudUsada+cantidadPuntos]= '.';
        cantidadPuntos--;
        return agregarSeparadorMiles(numero, cantidadPuntos, longitudUsada, contador);
    }
}

bool validarString(char * numero, int longitud){
    for (int i = 0; i < longitud; i++){
        int caca = numero[i];
        if (caca < 48 || caca > 57){
            return false;
        }
    }
    return true;
}

int main() {
    char numero[100];
    printf("Ingrese el numero al que desea agregar los puntos de miles: ");
    fgets(numero, sizeof(numero), stdin);
    numero[strcspn(numero, "\n")] = '\0';
    int largoString = strlen(numero);

    if (validarString(numero, largoString)){
        int cantidadPuntos = (largoString - 1) / 3;
        agregarSeparadorMiles(numero, cantidadPuntos, largoString, 0);
        printf("El numero con puntos de miles es: %s\n", numero);
        return 0;    
    }
    else{
        printf("%s", "No se ingresaron numeros validos");
    }
}