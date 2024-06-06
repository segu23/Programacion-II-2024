#include "tabla_hash.h"
#include "tabla_hash_zona_overflow.c"
#include "listas.h"
#include "listas_arreglos.c"
#include "tipo_elemento.h"
#include "tipo_elemento.c"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX 100
static int cantidad;

struct Alumno {
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
    
    seguirAgregando = true;

    return alumno;
}

static int cantidadAlumnosArchivo = 0;

struct Alumno consultaAlumnoArchivo(FILE * archivo, int posicionFisicaArchivo){
    fseek(archivo, sizeof(struct Alumno) * posicionFisicaArchivo, SEEK_SET);
    
    struct Alumno alumno;
    fread(&alumno, sizeof(struct Alumno), 1, archivo);

    return alumno;
}

bool altaAlumno(struct Alumno alumno, FILE * archivo, int posicionFisicaArchivo, TablaHash tabla){
    fflush(archivo);
    if(th_recuperar(tabla, alumno.legajo) != NULL){
        printf("\033[0;31m[ERROR] El legajo ingresado ya pertenece a un alumno.\033[0;37m\n");
        return false;
    }
    fseek(archivo, sizeof(struct Alumno) * posicionFisicaArchivo, SEEK_SET);
    fwrite(&alumno, sizeof(struct Alumno), 1, archivo);
    th_insertar(tabla, te_crear_con_valor(alumno.legajo, (void*) posicionFisicaArchivo));
    printf("\033[0;32m[INFO] El alumno ha sido guardado en el archivo!\033[0;37m\n");
    fflush(archivo);
    return true;
}

void editAlumno(FILE * archivo, TablaHash tabla){
    int legajo;
    bool seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el legajo del alumno a editar: ");

        if (scanf("%i", &legajo) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    TipoElemento elementoAlumno = th_recuperar(tabla, legajo);
    struct Alumno alumno = consultaAlumnoArchivo(archivo, (int) elementoAlumno->valor);

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el apellido del alumno (%s): ", alumno.apellido);

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

    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el nombre del alumno (%s): ", alumno.nombres);

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
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el domicilio del alumno (%s): ", alumno.domicilio);

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
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el telefono del alumno (%s): ", alumno.telefono);

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
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el legajo del alumno (%i): ", alumno.legajo);

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

    th_eliminar(tabla, legajo);

    altaAlumno(alumno, archivo, (int) elementoAlumno->valor, tabla);
}

void mostrarAlumno(struct Alumno alumno){
    printf("\n\033[1;37m[INFO] Datos de Alumno: \033[0;36m\n");
    printf(" > \033[1;36mLegajo\033[0;36m: %i \n", alumno.legajo);
    printf(" > \033[1;36mNombre\033[0;36m: %s \n", alumno.nombres);
    printf(" > \033[1;36mApellido\033[0;36m: %s \n", alumno.apellido);
    printf(" > \033[1;36mDomicilio\033[0;36m: %s \n", alumno.domicilio);
    printf(" > \033[1;36mTelefono\033[0;36m: %s \033[0;37m\n\n", alumno.telefono);
}

void mostrarAlumnosDesdeArchivo(FILE * archivo){
    rewind(archivo);
    int indiceAlumnoActual = 0;
    struct Alumno alumno;
    while(fread(&alumno, sizeof(struct Alumno), 1, archivo)){
        //struct Alumno alumno = consultaAlumnoArchivo(archivo, indiceAlumnoActual);
        //th_insertar(tabla, te_crear_con_valor(alumno.legajo, (void*) indiceAlumnoActual));
        mostrarAlumno(alumno);
        indiceAlumnoActual++;
    }

    if(indiceAlumnoActual == 0){
        printf("\033[0;31m[INFO] No hay ningun alumno cargado!\033[0;37m\n");
    }
}

void eliminarAlumno(FILE * archivo, TablaHash tabla){
    int legajo;
    bool seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("[INPUT] Ingrese el legajo del alumno a eliminar: ");

        if (scanf("%i", &legajo) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
            fflush(stdin);
        }
    }

    TipoElemento elementoAlumno = th_recuperar(tabla, legajo);

    if (elementoAlumno == NULL) {
        printf("\033[0;31m[ERROR] Alumno no encontrado.\033[0;37m\n");
        return;
    }

    int posicion = (int) elementoAlumno->valor;
    struct Alumno alumno;

    // Mover todos los registros siguientes una posición hacia atrás
    fseek(archivo, sizeof(struct Alumno) * (posicion + 1), SEEK_SET);
    while (fread(&alumno, sizeof(struct Alumno), 1, archivo)) {
        fseek(archivo, sizeof(struct Alumno) * (posicion), SEEK_SET);
        fwrite(&alumno, sizeof(struct Alumno), 1, archivo);
        th_insertar(tabla, te_crear_con_valor(alumno.legajo, (void*) posicion));
        posicion = (int) th_recuperar(tabla, alumno.legajo)->valor;
        fseek(archivo, sizeof(struct Alumno) * (posicion + 1), SEEK_SET);
    }

    // Truncar el archivo para eliminar el último registro duplicado
    fseek(archivo, sizeof(struct Alumno) * (posicion), SEEK_SET);
    fflush(archivo);
    int resultado = ftruncate(fileno(archivo), sizeof(struct Alumno) * (cantidadAlumnosArchivo-1));
    fflush(archivo);
    if (resultado == 0) {
        printf("[INFO] Alumno eliminado!\n");
    } else {
        printf("\033[0;31m[ERROR] Error al truncar el archivo.\033[0;37m\n");
    }

    th_eliminar(tabla, legajo);
    cantidadAlumnosArchivo--;
}


void mostrarMenu(){
    printf(" [MENU]\n\n");
    printf(" 1 - Mostrar todos los alumnos.\n");
    printf(" 2 - Cargar nuevo alumno.\n");
    printf(" 3 - Ver alumno por legajo.\n");
    printf(" 4 - Editar alumno por legajo.\n");
    printf(" 5 - Eliminar alumno por legajo.\n\n");
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

    if(elementoAlumno == NULL){
        printf("\033[0;31m[ERROR] El alumno ingresado no existe.\033[0;37m\n");
        return;
    }

    struct Alumno alumno = consultaAlumnoArchivo(archivo, (int) elementoAlumno->valor);

    mostrarAlumno(alumno);
}

void procesarMenu(FILE * archivo, TablaHash tabla){
    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        mostrarMenu();

        if(scanf("%d", &clave) > 0 && clave >= 1 && clave <= 5){
            switch(clave){
                case 1: {
                    mostrarAlumnosDesdeArchivo(archivo);
                    break;
                }
                case 2: {
                    struct Alumno alumno = inputAlumno();
                    if(altaAlumno(alumno, archivo, cantidadAlumnosArchivo, tabla)) cantidadAlumnosArchivo++;;
                    break;
                }
                case 3: {
                    consultarAlumno(archivo, tabla);
                    break;
                }
                case 4: {
                    editAlumno(archivo, tabla);
                    break;
                }
                case 5: {
                    eliminarAlumno(archivo, tabla);
                    break;
                }
                default: {
                    printf("\033[0;31m[ERROR] Debe ingresar un valor valido.\033[0;37m\n");
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
    cantidad = 2000;
    valorModulo = encontrarPrimoMasCercano(cantidad);

    TablaHash tabla = th_crear(cantidad, &funcionHash);
    FILE * archivo = fopen("archivo.bin", "wb+");
    
    procesarMenu(archivo, tabla);

    fclose(archivo);
    
    return 0;
}