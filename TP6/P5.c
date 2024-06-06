#include "listas.h"
#include "listas_arreglos.c"
#include "nodo.c"
#include "nodo.h"
#include "arbol-avl.c"
#include "arbol-avl.h"
#include "tabla_hash.h"
#include "tipo_elemento.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "tipo_elemento.c"
#include "tabla_hash_lista_colisiones.c"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

long long obtener_tiempo_en_nanosegundos() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    return (start.QuadPart * 1000000000) / frequency.QuadPart;
}

#else
#include <sys/time.h>
#include <unistd.h>

#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC 1
#endif

long long obtener_tiempo_en_nanosegundos() {
    struct timespec tiempo;
    clock_gettime(CLOCK_MONOTONIC, &tiempo);
    return (long long) tiempo.tv_sec * 1000000000LL + (long long) tiempo.tv_nsec;
}

#endif

bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) 
        if (num % i == 0) 
            return false;
    return true;
}

int encontrarPrimoMasCercano(int num) {
    if (num <= 1) return 2;
    else if (esPrimo(num)) return num;

    int menorPrimo = num - 1;
    int mayorPrimo = num + 1;

    while (true) {
        if (esPrimo(menorPrimo)) return menorPrimo;
        else if (esPrimo(mayorPrimo)) return mayorPrimo;

        menorPrimo--;
        mayorPrimo++;
    }
}

static int valorModulo;

int funcionHash(int clave) {
    return clave % valorModulo;
}

int main() {
    int cantidadClaves;
    bool cantidadClavesCorrecta = false;

    while (!cantidadClavesCorrecta) {
        printf("[INPUT] Cuantas claves desea generar (1-2000): ");
        if (scanf("%i", &cantidadClaves) > 0 && cantidadClaves >= 1 && cantidadClaves <= 2000) {
            cantidadClavesCorrecta = true;
        } else {
            printf("[ERROR] Debe ingresar un numero de claves que se encuentre entre 1 y 2000.\n");
            fflush(stdin);
        }
    }

    bool cantidadRepeticionesCorrecta = false;
    int repeticiones;

    while (!cantidadRepeticionesCorrecta) {
        printf("[INPUT] Cuantas repeticiones desea hacer: ");
        if (scanf("%i", &repeticiones) > 0) {
            cantidadRepeticionesCorrecta = true;
        } else {
            printf("[ERROR] Debe ingresar un numero para las repeticiones.\n");
            fflush(stdin);
        }
    }

    bool minimoCorrecto = false;
    int minimo;

    while (!minimoCorrecto) {
        printf("[INPUT] Ingrese el minimo del intervalo para generar las claves: ");
        if (scanf("%i", &minimo) > 0) {
            minimoCorrecto = true;
        } else {
            printf("[ERROR] Debe ingresar un numero minimo para el intervalo.\n");
            fflush(stdin);
        }
    }

    bool maximoCorrecto = false;
    int maximo;

    while (!maximoCorrecto) {
        printf("[INPUT] Ingrese el maximo del intervalo para generar las claves: ");
        if (scanf("%i", &maximo) > 0 && maximo > minimo) {
            maximoCorrecto = true;
        } else {
            printf("[ERROR] Debe ingresar un numero maximo para el intervalo, mayor que el numero minimo ya ingresado.\n");
            fflush(stdin);
        }
    }

    valorModulo = encontrarPrimoMasCercano(cantidadClaves);
    ArbolAVL arbol = avl_crear();
    TablaHash tabla = th_crear(cantidadClaves, &funcionHash);

    long long totalTiempoArbol = 0;
    long long totalTiempoTabla = 0;

    srand(time(NULL));

    for (int i = 0; i < cantidadClaves; i++) {
        int numeroGenerado = ((double)rand() / RAND_MAX) * (maximo - minimo) + minimo;
        avl_insertar(arbol, te_crear(numeroGenerado));
        th_insertar(tabla, te_crear(numeroGenerado));
    }

    for (int i = 0; i < repeticiones; i++) {
        int claveBuscada = ((double)rand() / RAND_MAX) * (maximo - minimo) + minimo;

        long long tiempoInicio1 = obtener_tiempo_en_nanosegundos();

        TipoElemento elementoBuscadoArbol = avl_buscar(arbol, claveBuscada);

        long long tiempoFin1 = obtener_tiempo_en_nanosegundos();

        long long diferenciaTiempo1 = tiempoFin1 - tiempoInicio1;

        totalTiempoArbol += diferenciaTiempo1;
    }

    for (int i = 0; i < repeticiones; i++) {
        int claveBuscada2 = ((double)rand() / RAND_MAX) * (maximo - minimo) + minimo;

        long long tiempoInicio2 = obtener_tiempo_en_nanosegundos();

        TipoElemento elementoBuscadoTabla = th_recuperar(tabla, claveBuscada2);

        long long tiempoFin2 = obtener_tiempo_en_nanosegundos();

        long long diferenciaTiempo2 = tiempoFin2 - tiempoInicio2;

        totalTiempoTabla += diferenciaTiempo2;
    }

    float promedioTiempoArbol = totalTiempoArbol / (float) repeticiones;
    float promedioTiempoTabla = totalTiempoTabla / (float) repeticiones;

    printf("\n[OUTPUT] El promedio de tiempo de ejecucion del arbol es %.1f nanosegundos y el promedio de tiempo de ejecucion de la tabla es %.1f nanosegundos.\n", promedioTiempoArbol, promedioTiempoTabla);

    return 0;
}