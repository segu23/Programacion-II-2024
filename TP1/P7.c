// 7. Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se
// pide obtener recursivamente la onda que representa utilizando “_” y “|”.
// Ejemplos:
// ondaDigital (“LHLHL”) => “_ |¯ |_|¯ |_”
// ondaDigital (“HHHHLLLLHHHHHLLHH”) => “¯ ¯ ¯ ¯ | _ _ _ _ |¯ ¯ ¯ ¯ ¯ | _ _ | ¯ ¯ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * ondaDigital(char seniales[]) {
    char guionAlto[] = "^";
    int len = strlen(seniales);
    char *resultado = (char *)malloc((len * 3 + 1) * sizeof(char));
    resultado[0] = '\0';

    for (int i = 0; i < len; i++) {
        if (seniales[i] == 'H') {
            strcat(resultado, guionAlto);
        } else if (seniales[i] == 'L') {
            strcat(resultado, "_");
        }

        if (seniales[i + 1] != seniales[i] && seniales[i + 1] != '\0') {
            strcat(resultado, "|");
        }
    }

    return resultado;
}

int validarSeniales(char seniales[]) {
    int len = strlen(seniales);
    for (int i = 0; i < len; i++) {
        if (seniales[i] != 'H' && seniales[i] != 'L') {
            return 0; 
        }
    }
    return 1;
}

int main() {
    char seniales[100]; 

    printf("Ingrese la cadena de seniales (L para Low, H para High): ");
    scanf("%s", seniales);

    if (!validarSeniales(seniales)) {
        printf("La cadena de seniales contiene caracteres no válidos.\n");
        return 1; 
    }
    
    char *resultado = ondaDigital(seniales);

    printf("Resultado final: %s\n", resultado);

    free(resultado);

    return 0;
}