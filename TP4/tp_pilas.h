#ifndef TP_PILAS_H
#define TP_PILAS_H

#include <stdbool.h>
#include ".\pilas.h"

/**
    2.	Dada una pila cargada con valores al azar realizar los siguientes ejercicios:
 */

//  a.	Buscar una clave y determinar si existe en la Pila (sin perder la pila).
// Si la encuentra retorna true, caso contrario false
bool p_ej2_existeclave(Pila p, int clave);

//  b.	Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).
// Retorna la nueva pila con el nuevo elemento, caso contrario la pila original recibida.
Pila p_ej2_colocarelemento(Pila p, int posicionordinal);

//  c.	Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave).
// retorna la nueva pila sin la clave, si la encuentra, sino retorna la misma pila que recibio.
Pila p_ej2_eliminarclave(Pila p, int clave);

//  d.	Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.
// retorna la nueva pila con las posiciones cambiadas, siempre que sea posible haerlo, caso contrario retorna la pila recibida.
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2);

//  e.	Duplicar el contenido de una pila.
// retorna la nueva pila. Si esta vacia retorna otra vacia.
Pila p_ej2_duplicar(Pila p);

//  f.	Contar los elementos de la pila.
// retorna la cantidad de elementos de la pila. Si esta vacia retorna 0 (cero).
int p_ej2_cantidadelementos(Pila p);

/**
 3.	Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas.
	Utilizar para la resolución del problema una única pila auxiliar.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna true si son exactamente iguales, caso contrario retorna false
bool p_ej3_iguales(Pila p1, Pila p2);

/**
 4.	Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como parámetro,
	a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase);

/**
 5.	Invertir el contenido de una pila sin destruir la pila original.
	Se debe retornar la nueva pila invertida y la original no se debe perder.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
Pila  p_ej5_invertir(Pila p);

/**
6.	Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado ítem sin perder la pila original.
	Deberá retornar una nueva pila sin el ítem en consideración.
	Resolver iterativamente y recursivamente.
	Determinar la complejidad algorítmica de ambas soluciones.
 */
// retornar la nueva pila sin la clave que se debe sacar (eliminar). Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones
Pila p_ej6_eliminarclave(Pila p, int clave);

/**
7.	Dada dos pilas realizar una función que permita determinar los elementos que tienen en común.
	Debe retornar una nueva pila con esos elementos (que están en ambas pilas) sin perder las pilas originales.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves en comun de ambas Pilas recibidas por parametro.  Si no hay claves en comun retornar una pila vacia.
Pila p_ej7_elementoscomunes(Pila p1, Pila p2);

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
// Si la pila estavacia retorna pila vacia.
Pila p_ej8_sacarrepetidos(Pila p);

#endif // TP_PILAS_H
