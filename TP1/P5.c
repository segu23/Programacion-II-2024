#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* separadorMiles(char* numero, int cantidadPuntos, int longitudUsada, int contador){
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
        return separadorMiles(numero, cantidadPuntos, longitudUsada, contador);
    }
    else{
        contador=1;
        numero[longitudUsada+cantidadPuntos]= '.';
        cantidadPuntos--;
        return separadorMiles(numero, cantidadPuntos, longitudUsada, contador);
    }
}

bool validarString(char * numero){
    int longitud = strlen(numero);
    for (int i = 0; i < longitud; i++){
        int numeroValidar = numero[i];
        if (numeroValidar < 48 || numeroValidar > 57){
            return false;
        }
    }
    return longitud>0;
}

char * agregarSeparadorMiles(char numero[]){
    int largoString = strlen(numero);
    int cantidadPuntos = (largoString - 1) / 3;
    int contador = 0;
    separadorMiles(numero, cantidadPuntos, largoString, contador);

    return numero;
}

int main() {
    char numero[100];
    bool valido = false;
    
    while (!valido){
        printf("[INPUT] Ingrese el numero al que desea agregar los puntos de miles: ");
        fgets(numero, sizeof(numero), stdin);
        numero[strcspn(numero, "\n")] = '\0';

        valido = validarString(numero);

        if (!valido){
            printf("[ERROR] No se ingresaron numeros validos.\n");
        }
    }

    agregarSeparadorMiles(numero);
    printf("[OUTPUT] Su numero con los puntos de los miles es %s\n", numero);
}