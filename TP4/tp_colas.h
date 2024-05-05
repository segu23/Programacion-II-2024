#ifndef TP_COLAS_H
#define TP_COLAS_H

#include <stdbool.h>
#include "colas.h"
#include "listas.h"
#include "pilas.h"

/**
    2.	Resolver los siguientes puntos:
 */

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave);

//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal);

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave);

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c);

//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c);

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.
Cola c_ej2_invertir(Cola c);

/**
3.	Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave),
	sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar.
 */
// retorna true si son exactamente iguales, caso contrario retorna false.
bool c_ej3_iguales(Cola c1, Cola c2);

/**
4.	Dada una cola de números enteros, no ordenada,
	construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera,
	sin destruir el contenido de la cola original y dejándola en su estado inicial.
 */
// Retorna la cola con las claves que no tienen repeticiones, caso contrario si todas se repiten retorna cola vacia.
Cola  c_ej4_colanorepetidos(Cola c);

/**
5.	Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
	obtener todos los valores que son Divisores Totales o parciales.
	Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta.
	Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola (es decir a la mitad de los elementos).
 */
// retorna el valor del divisor total o parcial en la función.   Si no hay ni divisor total ni parcial retornar "0".
// En la variable de referencia "&fuetotal" debe venir solo con true cual el divisor es total, caso contrario false.
int  c_ej5_divisortotal(Cola c, bool *fuetotal);


/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
	y en qué posición ordinal se encontró cada uno en su estructura.  Si existe mas de una vez la primer posicion encontrada.
	No se deben destruir las estructuras originales.
 */
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia.
void c_ej6_comunesapilaycola(Pila p, Cola c);


/**
7.	Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en cada ventanilla.
	Un día, dos de los tres empleados que atienden las ventanillas no pueden asistir al trabajo,
	quedando uno solo para atender a las tres colas. Este empleado decide que, a medida que lleguen los clientes,
	atenderá por cierta cantidad de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas equitativamente.
	Se pide que implemente un algoritmo que modele esta situación y dé como resultado el orden en que fueron atendidos los clientes.
 */
// retornar la cola con los resultados de la atenciones de los clientes.  Ver el ejemplo en el PDF del TP.
// retornar en la clave el nro de cola que lo atendio y en el void* de cada elemento los textos "Cliente 1 Cola 3", Cliente 1 Cola 2, etc.
// Segun el ejemplo el primer item de la cola seria clave: 3, void* "Cliente 1 Cola 3".
// Si las colas estan vacias, retornar cola vacia.
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion);

#endif // TP_COLAS_H
