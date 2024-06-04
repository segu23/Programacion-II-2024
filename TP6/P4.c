#include "tabla_hash.h"
#include "tabla_hash_zona_overflow.c"
#include "listas.h"
#include "listas_arreglos.c"
#include "tipo_elemento.h"
#include "tipo_elemento.c"
#include <stdio.h>

#define MAX 100
static int cantidad;

typedef struct Alumno {
    int legajo;
    char apellido[20];
    char nombres[20];
    char domicilio[20];
    char telefono[20];
};

bool esPrimo(int num) {
    if (num <= 1) return false;

    for (int i = 2; i <= sqrt(num); i++) 
        if (num % i == 0) 
            return false;

    return true;
}

// Función para encontrar el número primo más cercano a un número dado
int encontrarPrimoMasCercano(int num) {
    if      (num <= 1) return 2;
    else if (esPrimo(num)) return num;

    int menorPrimo = num - 1;
    int mayorPrimo = num + 1;

    while (true) {
        if      (esPrimo(menorPrimo)) return menorPrimo;
        else if (esPrimo(mayorPrimo)) return mayorPrimo;

        menorPrimo--;
        mayorPrimo++;
    }
}

static int valorModulo;

int funcionHash(int clave) {
    return clave % valorModulo;
}

struct Alumno inputAlumno(){
    struct Alumno alumno;
    bool seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el apellido del alumno: ");

        if (scanf("%s", alumno.apellido) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }

    printf("%s\n", alumno.apellido);
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el nombre del alumno: ");

        if (scanf("%s", alumno.nombres) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }
    
    printf("%s\n", alumno.nombres);
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el domicilio del alumno: ");

        if (scanf("%s", alumno.domicilio) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }
    
    printf("%s\n", alumno.domicilio);
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el telefono del alumno: ");

        if (scanf("%s", alumno.telefono) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }
    
    printf("%s\n", alumno.telefono);
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el legajo del alumno: ");

        if (scanf("%i", &alumno.legajo) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }
    
    printf("%i\n", alumno.legajo);
    
    seguirAgregando = true;

    return alumno;
}

static int cantidadAlumnosArchivo = 0;

void altaAlumno(struct Alumno alumno, FILE * archivo, int posicionFisicaArchivo, TablaHash tabla){
    fseek(archivo, sizeof(struct Alumno) * posicionFisicaArchivo, SEEK_SET);
    fwrite(&alumno, sizeof(struct Alumno), 1, archivo);
    th_insertar(tabla, te_crear_con_valor(alumno.legajo, posicionFisicaArchivo));
    cantidadAlumnosArchivo++;
    printf("\033[0;32m[INFO] El alumno ha sido guardado en el archivo!\033[0;37m\n");
}

struct Alumno consultaAlumnoArchivo(FILE * archivo, int posicionFisicaArchivo){
    fseek(archivo, sizeof(struct Alumno) * posicionFisicaArchivo, SEEK_SET);
    
    struct Alumno alumno;
    fread(&alumno, sizeof(struct Alumno), 1, archivo);

    return alumno;
}

void mostrarAlumno(struct Alumno alumno){
    printf("\n\033[1;37m[INFO] Datos de Alumno: \033[0;36m\n");
    printf(" > \033[1;36mLegajo\033[0;36m: %i \n", alumno.legajo);
    printf(" > \033[1;36mNombre\033[0;36m: %s \n", alumno.nombres);
    printf(" > \033[1;36mApellido\033[0;36m: %s \n", alumno.apellido);
    printf(" > \033[1;36mDomicilio\033[0;36m: %s \n", alumno.domicilio);
    printf(" > \033[1;36mTelefono\033[0;36m: %s \033[0;37m\n\n", alumno.telefono);
}

void cargarTablaDesdeArchivo(FILE * archivo, TablaHash tabla){
    rewind(archivo);
    int indiceAlumnoActual = 0;
    while(!feof(archivo)){
        struct Alumno alumno = consultaAlumnoArchivo(archivo, indiceAlumnoActual);
        th_insertar(tabla, te_crear_con_valor(alumno.legajo, (void*) indiceAlumnoActual));
        mostrarAlumno(alumno);
        indiceAlumnoActual++;
    }
}

void mostrarMenu(){
    printf(" [MENU]\n\n");
    printf(" 1 - Mostrar todos los alumnos.\n");
    printf(" 2 - Cargar nuevo alumno.\n");
    printf(" 3 - Ver alumno por legajo.\n\n");
}

void consultarAlumno(FILE * archivo, TablaHash tabla){
    bool seguirAgregando = true;
    int legajo;

    while(seguirAgregando){
        printf("[INPUT] Ingrese el legajo a consultar: ");

        if(scanf("%d", &legajo) > 0){
            seguirAgregando = false;
        }
        else{
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }

    TipoElemento elementoAlumno = th_recuperar(tabla, legajo);

    struct Alumno alumno = consultaAlumnoArchivo(archivo, (int) elementoAlumno->valor);

    mostrarAlumno(alumno);
}

void cargarAlumnos(FILE * archivo, TablaHash tabla){
    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        mostrarMenu();

        if(scanf("%d", &clave) > 0 && clave >= 1 && clave <= 3){
            switch(clave){
                case 1: {
                    cargarTablaDesdeArchivo(archivo, tabla);
                    break;
                }
                case 2: {
                    struct Alumno alumno = inputAlumno();
                    altaAlumno(alumno, archivo, cantidadAlumnosArchivo, tabla);
                    break;
                }
                case 3: {
                    consultarAlumno(archivo, tabla);
                    break;
                }
            }
        }
        else{
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }
}

int main(){
    cantidad = 100;
    valorModulo = encontrarPrimoMasCercano(cantidad);

    TablaHash tabla = th_crear(cantidad, &funcionHash);
    FILE * archivo = fopen("archivo.bin", "wb+");
    
    cargarAlumnos(archivo, tabla);

    fclose(archivo);
    
    return 0;
}