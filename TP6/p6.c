#include "tabla_hash.h"
#include "listas.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/*
Se desea poder implementar una solución para encontrar de forma rápida los datos de
las personas que a una fecha determinada se presentaron a vacunar contra el COVID.
Es decir dada una fecha determinada debería obtener quienes se vacunaron. De cada
persona se guarda básicamente el DNI, Apellido y Nombre. Se debe además hacer una
pantalla de carga donde se pueda especificar la fecha y los datos de las personas que
se vacunaron en esa fecha. 
*/


static const int MAX = 100;
static const int NRO_PRIMO = 107;

typedef struct Persona{
    char nombre[20];
    char apellido[20];
    char DNI[9];
    int dia;
    int mes;
    int anio;
}Persona;

struct Date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}


int days_in_month(int month, int year) {
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_per_month[month - 1];
}

int days_since_start(struct Date date) {
    struct Date start_date = {1, 4, 2020};
    int days = 0;

    for (int year = start_date.year; year < date.year; year++) {
        days += is_leap_year(year) ? 366 : 365;
    }

    for (int month = 1; month < date.month; month++) {
        days += days_in_month(month, date.year);
    }
    days += date.day - 1;

    for (int month = 1; month < start_date.month; month++) {
        days -= days_in_month(month, start_date.year);
    }
    days -= (start_date.day - 1);

    return days;
}
void pausar(){
    printf("Presione Enter para continuar...\n");
    getchar();
    getchar();
}
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpiar_consola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int calcular_clave(int dia, int mes, int anio) {
    struct Date date = {dia, mes, anio};
    int dias_transcurridos = days_since_start(date);
    int posicion_hash = dias_transcurridos; // % MAX?
    return posicion_hash;
}

void cargar_paciente_tabla(TablaHash tabla, struct Persona persona) {
    int clave = calcular_clave(persona.dia, persona.mes, persona.anio);

    struct Persona* nueva_persona = (struct Persona*)malloc(sizeof(struct Persona));
    if (nueva_persona == NULL) {
        printf("[ERROR] No se pudo asignar memoria para la nueva persona.\n");
        return;
    }
    *nueva_persona = persona;

    TipoElemento te = te_crear_con_valor(clave, nueva_persona);
    TipoElemento old = th_recuperar(tabla, clave);

    if (old == NULL) {
        Lista lista = l_crear();
        l_agregar(lista, te);
        if (th_insertar(tabla, te_crear_con_valor(clave, (void*) lista))) {
            printf("[INFO] Persona cargada exitosamente.\n");
        } else {
            printf("[ERROR] No se pudo cargar la persona.\n");
        }
    } else {
        Lista lista = (Lista) old->valor;
        l_agregar(lista, te);
    }
}


void cargar_paciente(TablaHash tabla){
    struct Persona persona;
    bool continuar = true;

    while (continuar){
        printf("[INFO] Ingrese el anio de vacunacion: \n");
        if(scanf("%d", &persona.anio) > 0 && persona.anio >= 2020){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            limpiar_buffer(); 
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el mes de vacunacion: \n");
        if (scanf("%d", &persona.mes) == 1 && ((persona.anio == 2020 && persona.mes >= 4) || (persona.anio > 2020 && persona.mes > 0 && persona.mes <= 12))) {
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            limpiar_buffer(); 
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el dia de vacunacion: \n");
        if (scanf("%d", &persona.dia) == 1 && persona.dia > 0 && persona.dia <= 31){
            continuar = false;

        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            limpiar_buffer(); 
        }

    }

    limpiar_buffer(); 

    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el nombre del paciente: \n");
        if(fgets(persona.nombre, sizeof(persona.nombre), stdin) != NULL){
            persona.nombre[strcspn(persona.nombre, "\n")] = '\0';
            if(strlen(persona.nombre) > 0) {
                continuar = false;
            }
            else {
                printf("[ERROR] Debe ingresar un valor válido. \n");
            }
        }  
        else{
            printf("[ERROR] Debe ingresar un valor válido. \n");
            limpiar_buffer(); 
        }
    }

    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el apellido del paciente: \n");
        if(fgets(persona.apellido, sizeof(persona.apellido), stdin) != NULL){
            persona.apellido[strcspn(persona.apellido, "\n")] = '\0';
            if(strlen(persona.apellido) > 0) {
                continuar = false;
            }
            else{
                printf("[ERROR] Debe ingresar un valor válido. \n");
            }
        }
        else{
            printf("[ERROR] Debe ingresar un valor válido. \n");
            limpiar_buffer(); 
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el DNI del paciente (Sin puntos): \n");
        if(fgets(persona.DNI, sizeof(persona.DNI), stdin) != NULL){
            persona.DNI[strcspn(persona.DNI, "\n")] = '\0';
            if(strlen(persona.DNI) > 0) {
                continuar = false;
            }
            else{
                printf("[ERROR] Debe ingresar un valor válido. \n");
            }
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido. \n");
            limpiar_buffer(); 
        }

    }
    //persona.clave = calcular_clave(persona.dia,persona.mes, persona.anio);
    cargar_paciente_tabla(tabla, persona);

}

void recuperar_paciente(TablaHash tabla){
    bool continuar = true;
    int dia, mes, anio, clave;
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el anio de vacunacion: \n");
        if(scanf("%d", &anio) == 1 && anio >= 2020){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }
    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el mes de vacunacion: \n");
        if (scanf("%d", &mes) == 1 && ((anio == 2020 && mes >= 4) || (anio > 2020 && mes > 0 && mes <= 12))) {
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }
    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el dia de vacunacion: \n");
        if (scanf("%d", &dia) == 1 && dia > 0 && dia <= 31){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }
    }

    clave = calcular_clave(dia, mes, anio);
    TipoElemento elemento = th_recuperar(tabla, clave);
    limpiar_consola();
    if (elemento != NULL) {
        Lista lista = (Lista) elemento->valor;
        Iterador iter = iterador(lista);
        while(hay_siguiente(iter)){
            TipoElemento sig = siguiente(iter);
            struct Persona* persona = (struct Persona*) sig->valor;
            printf("[INFO] Datos de la persona vacunada:\n");
            printf("Nombre: %s\n", persona->nombre);
            printf("Apellido: %s\n", persona->apellido);
            printf("DNI: %s\n", persona->DNI);
            printf("\n");
        }
    } else {
        printf("[ERROR] No se encontró ninguna persona vacunada en esa fecha.\n");
    }
        

    
}



int funcionHash(int clave){
    return (clave % NRO_PRIMO);
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
                    pausar();
                    break;
                }
                case 2:{
                    recuperar_paciente(tablita);
                    pausar();
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