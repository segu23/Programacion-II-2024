#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "colas.h"
#include "tipo_elemento.h"
#include "tp_colas.h"

/*
Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en
cada ventanilla. Un día, dos de los tres empleados que atienden las ventanillas no
pueden asistir al trabajo, quedando uno solo para atender a las tres colas. Este
empleado decide que, a medida que lleguen los clientes, atenderá por cierta cantidad
de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas
equitativamente.
Se pide que implemente un algoritmo que modele esta situación y dé como resultado
el orden en que fueron atendidos los clientes.
Ejemplo: El algoritmo recibe un Q de tiempo que atenderá a cada cola y las tres colas
cargadas con clientes, donde cada cliente es la cantidad de tiempo que se necesita
para atenderlo.
Q = 10
Cola1 = (40, 20, 30)
Cola2 = (20, 10)
Cola3 = (10, 10, 10)
Resultado =
Cliente 1 Cola 3,
Cliente 1 Cola 2,
Cliente 2 Cola 3,
Cliente 2 Cola 2,
Cliente 3 Cola 3,
Cliente 1 Cola 1,
Cliente 2 Cola 1,
Cliente 3 Cola 1
*/

void devolverColas(Cola aux, Cola original)
{
    while (!c_es_vacia(aux))
    {
        TipoElemento X = c_desencolar(aux);
        c_encolar(original, X);
    }
}

void desencolarYRegistrarTiempo(Cola original, Cola aux, int *tiempo)
{
    if (!c_es_vacia(original))
    {
        TipoElemento X = c_recuperar(original);
        (*tiempo) = X->clave;
        c_encolar(aux, X);
    }
}

void atenderCola(Cola cola, Cola aux, int Q, int *Q1, int *tiempo, int *cliente, int nCola, Cola resultado)
{
    if (!c_es_vacia(cola))
    {
        (*Q1) = Q;
        while ((*Q1) > 0 && !c_es_vacia(cola))
        {
            if ((*Q1) >= (*tiempo))
            {
                (*Q1) = (*Q1) - (*tiempo);
                c_desencolar(cola);
                c_encolar(resultado, te_crear_con_valor((*cliente), (void *)nCola));
                (*cliente)++;
                TipoElemento X = c_recuperar(cola);
                if (X != NULL)
                {
                    (*tiempo) = X->clave;
                    c_encolar(aux, X);
                }
            }
            else
            {
                (*tiempo) = (*tiempo) - (*Q1);
                (*Q1) = 0;
            }
        }
    }
}
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion)
{
    Cola C1Aux = c_crear();
    Cola C2Aux = c_crear();
    Cola C3Aux = c_crear();
    Cola resultado = c_crear();

    int T1, T2, T3, Q1, Q2, Q3;

    desencolarYRegistrarTiempo(c1, C1Aux, &T1);
    desencolarYRegistrarTiempo(c2, C2Aux, &T2);
    desencolarYRegistrarTiempo(c3, C3Aux, &T3);

    int Cli1 = 1;
    int Cli2 = 1;
    int Cli3 = 1;

    while (!(c_es_vacia(c1) && c_es_vacia(c2) && c_es_vacia(c3)))
    {
        atenderCola(c1, C1Aux, tiempoatencion, &Q1, &T1, &Cli1, 1, resultado);
        atenderCola(c2, C2Aux, tiempoatencion, &Q2, &T2, &Cli2, 2, resultado);
        atenderCola(c3, C3Aux, tiempoatencion, &Q3, &T3, &Cli3, 3, resultado);
    }

    devolverColas(C1Aux, c1);
    devolverColas(C2Aux, c2);
    devolverColas(C3Aux, c3);

    return resultado;
}

void cargarCola(Cola cola, int nCola)
{
    bool seguirAgregando = true;
    int IngresoNumero;
    int index = 1;
    char inputChar;
    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el #%i elemento de la cola #%i o 'n' para terminar: ", index, nCola);

        if (scanf("%d", &IngresoNumero) > 0 && IngresoNumero > 0)
        {
            c_encolar(cola, te_crear(IngresoNumero));
            index++;
        }
        else
        {
            if (scanf("%c", &inputChar) > 0 && inputChar == 'n')
            {
                seguirAgregando = false;
                printf("[INFO] Ingreso de la cola terminado.\n");
            }
            else
            {
                printf("[ERROR] Debe ingresar un valor valido.\n");
                fflush(stdin);
            }
        }
    }
}

int main()
{

    int Q;
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();

    cargarCola(c1, 1);
    cargarCola(c2, 2);
    cargarCola(c3, 3);

    bool seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el tiempo Q para atender cada cola: ");

        if (scanf("%d", &Q) > 0 && Q >= 1)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("[ERROR] Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    Cola resultado = c_ej7_atenderclientes(c1, c2, c3, Q);

    printf("--------------------------------------------\n");
    printf("[INFO] Q = %d\n", Q);

    printf("[INFO] Colas ingresadas: \n");

    if (!c_es_vacia(c1))
    {
        c_mostrar(c1);
    }
    else
    {
        printf("[INFO] No habia nadie en la Cola 1.\n");
    }
    printf("\n");
    if (!c_es_vacia(c2))
    {
        c_mostrar(c2);
    }
    else
    {
        printf("[INFO] No habia nadie en la Cola 2.\n");
    }
    printf("\n");
    if (!c_es_vacia(c3))
    {
        c_mostrar(c3);
    }
    else
    {
        printf("[INFO] No habia nadie en la Cola 3.\n");
    }

    printf("[OUTPUT] Resultado:\n");
    while (!c_es_vacia(resultado))
    {
        TipoElemento atencion = c_desencolar(resultado);
        printf("[OUTPUT] Cliente %i de la Cola %i,\n", atencion->clave, (int)atencion->valor);
    }

    return 0;
}