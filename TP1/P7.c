#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Implementación de recursividad - TP Nro. 1 - Punto 7

// Función recursiva de cola: grafíca la onda a base de valores bivaluados, High ('H') o Low ('L').
void aplicarOndaDigital(char onda[], int i, char output[])
{
    if (onda[i] != '\0')
    {
        if (onda[i] != ' ')
        {
            if (i != 0 && onda[i - 1] != 'H' && onda[i] == 'H')
            {
                strcat(output, "|-");
            }
            else if (i != 0 && onda[i - 1] != 'L' && onda[i] == 'L')
            {
                strcat(output, "|_");
            }
            else if (onda[i] == 'L')
            {
                strcat(output, "_");
            }
            else if (onda[i] == 'H')
            {
                strcat(output, "-");
            }
        }
        aplicarOndaDigital(onda, ++i, output);
    }
}

char *ondaDigital(char seniales[])
{
    char *output = calloc(MAX, sizeof(char));
    aplicarOndaDigital(seniales, 0, output);

    return output;
}

bool validarYCorregirString(char *numero)
{
    int longitud = strlen(numero);

    for (int i = 0; i < longitud; i++)
    {
        if (numero[i] == 'h')
            numero[i] = 'H';
        if (numero[i] == 'l')
            numero[i] = 'L';

        if (numero[i] != 'H' && numero[i] != 'L')
        {
            return false;
        }
    }

    return longitud > 0;
}

int main()
{
    char onda[MAX];

    bool valido = false;

    while (!valido)
    {
        printf("[INPUT] Ingrese los valores de la onda (H/L): ");

        fgets(onda, sizeof(onda), stdin);
        onda[strcspn(onda, "\n")] = '\0';

        valido = validarYCorregirString(onda);

        if (!valido)
        {
            printf("[ERROR] Debe ingresar H o L.\n");
        }
    }

    char *output = ondaDigital(onda);

    printf("[OUTPUT] La onda graficada es: %s\n", output);

    system("pause");

    return 0;
}
