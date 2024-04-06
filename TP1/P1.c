#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool es_palindromo(char cadena[], int inicio, int fin){
    if (inicio >= fin){
        return true;
    }
    
    if (cadena[inicio] != cadena [fin]){
        return false;
    }
    return es_palindromo(cadena, inicio+1, fin-1);

}

bool palindormo (char * cadena){
    
    int fin = strlen(cadena)-1;

    return es_palindromo(cadena, 0 , fin -1 );
}

int main(){
    char cadena[100];
    printf("[INPUT] Ingrese una cadena:");
    fgets(cadena, sizeof(cadena), stdin);

    bool es_palindromo_resultado = palindormo(cadena);

    if (es_palindromo_resultado){
        printf("[OUTPUT] La cadena es un palindromo\n");
    }
        
    else{
        printf("[OUTPUT] La cadena no es un palindromo\n");
    }

    system("pause");

    return 0;
}