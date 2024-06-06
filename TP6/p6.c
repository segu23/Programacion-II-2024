#include "tabla_hash.h"
#include "listas.h"
#include "listas_arreglos.c"
#include "tipo_elemento.h"
#include "tipo_elemento.c"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "tabla_hash_lista_colisiones.c"
#include "tabla_hash_zona_overflow.c"

/*
Se desea poder implementar una solución para encontrar de forma rápida los datos de
las personas que a una fecha determinada se presentaron a vacunar contra el COVID.
Es decir dada una fecha determinada debería obtener quienes se vacunaron. De cada
persona se guarda básicamente el DNI, Apellido y Nombre. Se debe además hacer una
pantalla de carga donde se pueda especificar la fecha y los datos de las personas que
se vacunaron en esa fecha. 
*/


const int MAX = 100;

typedef struct Persona{
    char nombre[20];
    char apellido[20];
    char DNI[8];
    int dia;
    int mes;
    int anio;
    int clave;
} Persona;

struct Date {
    int day;
    int month;
    int year;
};

// Función para verificar si un año es bisiesto
int is_leap_year(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}

// Función para calcular el número de días en un mes dado un año
int days_in_month(int month, int year) {
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_per_month[month - 1];
}

// Función para calcular los días desde el 1 de abril de 2020
int days_since_start(struct Date date) {
    struct Date start_date = {1, 4, 2020};
    int days = 0;

    // Añadir días completos de los años intermedios
    for (int year = start_date.year; year < date.year; year++) {
        days += is_leap_year(year) ? 366 : 365;
    }

    // Añadir días del año actual
    for (int month = 1; month < date.month; month++) {
        days += days_in_month(month, date.year);
    }
    days += date.day - 1;

    // Restar días de los meses y días del año de inicio
    for (int month = 1; month < start_date.month; month++) {
        days -= days_in_month(month, start_date.year);
    }
    days -= (start_date.day - 1);

    return days;
}

int calcular_clave(int dia, int mes, int anio) {
    struct Date date = {dia, mes, anio};
    int dias_transcurridos = days_since_start(date);
    int posicion_hash = dias_transcurridos % MAX;
    return posicion_hash;
}

void cargar_paciente_tabla(TablaHash tabla, struct Persona persona){
    TipoElemento te = te_crear_con_valor(persona.clave, &persona);
    if (th_insertar(tabla, te)) {
        printf("[INFO] Persona cargada exitosamente.\n");
    } else {
        printf("[ERROR] No se pudo cargar la persona.\n");
    }
}

void cargar_paciente(TablaHash tabla){
    struct Persona persona;
    bool continuar = true;

    while (continuar){
        printf("[INFO] Ingrese el dia de vacunacion: \n");
        if (scanf("%d", &persona.dia) == 1 && persona.dia > 0 && persona.dia <= 31){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el mes de vacunacion: \n");
        if (scanf("%d", &persona.mes) == 1 && persona.mes > 0 && persona.mes <= 12) {
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }

    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el anio de vacunacion: \n");
        if(scanf("%d", &persona.anio) > 0){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }

    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el nombre del paciente: \n");
        if(scanf("%s", persona.nombre) > 0 ){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el apellido del paciente: \n");
        if(scanf("%s", persona.apellido) > 0 ){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el DNI del paciente: \n");
        if(scanf("%s", persona.DNI) > 0 ){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }
    
    persona.clave = calcular_clave(persona.dia,persona.mes, persona.anio);
    cargar_paciente_tabla(tabla, persona);
}

void recuperar_paciente(TablaHash tabla){
    bool continuar = true;
    int dia, mes, anio, clave;
    while (continuar){
        printf("[INFO] Ingrese el dia de vacunacion: \n");
        if (scanf("%d", &dia) == 1 && dia > 0 && dia <= 31){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el mes de vacunacion: \n");
        if (scanf("%d", &mes) == 1 && mes > 0 && mes <= 12) {
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el anio de vacunacion: \n");
        if(scanf("%d", &anio) > 0){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresae un valor valido. \n");
            fflush(stdin);
        }

    }

    clave = calcular_clave(dia, mes, anio);
    Persona* persona = (Persona*) th_recuperar(tabla, clave);
    
    if (persona != NULL) {
        printf("[INFO] Datos de la persona vacunada:\n");
        printf("Nombre: %s\n", persona->nombre);
        printf("Apellido: %s\n", persona->apellido);
        printf("DNI: %s\n", persona->DNI);
    } else {
        printf("[ERROR] No se encontró ninguna persona vacunada en esa fecha.\n");
    }
        

    
}


int funcionHash(int clave){
    return clave % MAX-1;
}

void mostrarMenu() {
    printf(" [MENU]\n\n");
    printf(" 1 - Cargar nueva persona vacunada.\n");
    printf(" 2 - Recuperar persona vacunada por fecha.\n");
    printf(" 3 - Salir.\n");
}


int main(){
    TablaHash tablita = th_crear(MAX, &funcionHash);
    
    bool agregar = true;
    int clave;
    while (agregar){

        mostrarMenu();
        if(scanf("%d", &clave) > 0 && clave >= 1 && clave <= 3){
            switch (clave){

                case 1:{
                    cargar_paciente(tablita);
                    break;
                }
                case 2:{
                    recuperar_paciente(tablita);
                    break;
                }
                case 3:{
                    agregar = false;
                    break;
                }
                default:{
                    printf("[ERROR] Debe ingresar una opcion valida.\n");
                }
                
            }
        }
    }
    return 0;

}