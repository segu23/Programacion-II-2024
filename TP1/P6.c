// Se conoce que la mafia china es muy organizada y protege mucho a sus miembros,
// cuando deciden asistir a una reunión se dispone de una cantidad de chinos que
// asisten, y ellos se ubican de forma que al mirarlos frontalmente generan cierto respeto
// y temor. A continuación, se tiene una serie de posibles reuniones y su nivel y la
// apariencia que se tiene del grupo que va a la reunión vistos frontalmente:
//  Nivel reunión Vista frontal de la delegación
//  1 (-.-)
//  2 (-.(-.-).-)
//  3 (-.(-.(-.-).-).-)
//  4 (-.(-.(-.(-.-).-).-).-)
// Considerando esta descripción, diseñar los procesos recursivos que permitan mostrar
// la apariencia del grupo de chinos que asisten a una reunión de nivel n.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void crearReunionMafia(int nivel, char output[])
{
    if (nivel == 1)
    {
        strcat(output, "(-.-)");
        return;
    }
    strcat(output, "(-.");
    crearReunionMafia(nivel - 1, output);
    strcat(output, ".-)");
}

char *reunionMafia(int nivel)
{
    char *output = calloc(MAX, sizeof(char));

    crearReunionMafia(nivel, output);

    return output;
}

int main()
{
    int nivelReunion;
    int input;
    while (input <= 0)
    {
        printf("[INPUT] Ingrese el nivel de la reunion: ");
        if (scanf("%i", &input) > 0 && input > 0)
        {
            nivelReunion = input;
        }
        else
        {
            fflush(stdin);
            printf("[ERROR] Ha ingresado un valor incorrecto.\n");
        }
    }

    char *reunion = reunionMafia(nivelReunion);

    printf("[OUTPUT] La reunion del nivel %i es: %s\n", nivelReunion, reunion);

    return 0;
}