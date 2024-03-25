#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindromo(char cadena[], int inicio, int fin){
    if (inicio >= fin){
        return true;
    }
    
    if (cadena[inicio] != cadena [fin]){
        return false;
    }
    return palindromo(cadena, inicio+1, fin-1);

}

int main(){
    char cadena[100];
    printf("Ingrese una cadena:");
    fgets(cadena, sizeof(cadena), stdin);
    int fin = strlen(cadena); 

    bool es_palindromo = palindromo(cadena, 0 , fin -2 );
    
    if (es_palindromo){
        printf("La cadena es un palindromo\n");
    }
        
    else{
        printf("La cadena no es un palindromo\n");

    }
    
    system("pause");
}