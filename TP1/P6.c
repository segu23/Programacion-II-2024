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

void reunionMafia(int nivel) {
    
    if (nivel == 1) {
        printf("(-.-)");
        return;
    }
    printf("(-.");
    reunionMafia(nivel - 1);
    printf(".-)");
}

int main() {
    int nivelReunion;
    
    printf("Ingrese el nivel de la reunion: ");
    scanf("%d", &nivelReunion);

    if (nivelReunion <= 0)
    {
        printf("Ingrese nivel de reunion mayor a 0");
        return 0;
    }
    
    reunionMafia(nivelReunion);
    printf("\n");
    
    return 0;
}