#ifndef TP_ARBOLES_H
#define TP_ARBOLES_H

#include <stdbool.h>
#include ".\colas.h"
#include ".\listas.h"
#include ".\pilas.h"
#include ".\nodo.h"
#include ".\arbol-binario.h"
#include ".\arbol-avl.h"
#include ".\arbol-binario-busqueda.h"


/**
2.	Dado un árbol binario no vacío determinar:  
 */

//  a.	Retornar una lista con todos los nodos terminales u hojas.
Lista a_ej2_hojas(ArbolBinario A);

//  b.	Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz)
Lista a_ej2_interiores(ArbolBinario A);

//  c.	Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo).
Lista a_ej2_buscarclave(ArbolBinario A, int clave);


/**
3.	Para un nodo del árbol binario determinado:

 */

// a.	Indicar el nombre del nodo padre (clave).
int a_ej3_clavepadre(ArbolBinario A, int clavehijo);

// b.	Listar los hijos (solo las clave/s).
Lista a_ej3_hijos(ArbolBinario A, int clavepadre);

// c.	Listar el hermano (solo la clave).
int a_ej3_hermano(ArbolBinario A, int clave);

// d.	Calcular el nivel en el que se encuentra.
int a_ej3_nivel(ArbolBinario A, int clave);

// e.	Calcular la altura de su rama (Altura del Subárbol)
int a_ej3_alturarama(ArbolBinario A, int clave);

// f.	Listar todos los nodos que están en el mismo nivel (solo la clave).
Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel);


/**
4.	Para Árboles “N-arios”:
 */
// a.	Dado un árbol n-ario, devolver en forma de lista el resultado del recorrido en anchura del árbol  (solo las claves).
Lista a_ej4_anchura(ArbolBinario A);

// b.	Escribir una función que, dado un árbol n-ario, devuelva el número (cantidad) de hojas de dicho árbol.
int a_ej4_q_hojas(ArbolBinario A);

// c.	Escribir una función booleana que dados dos árboles generales determine si tienen la misma estructura, sin importar los datos del mismo (árbol similar).
bool a_ej4_similares(ArbolBinario A, ArbolBinario B);

// d.	Retornar el padre de un nodo del árbol (tipo_elemento).
TipoElemento a_ej4_padre(ArbolBinario A, int clave);

// e.	Retornar los hermanos de un nodo del árbol (lista de hermanos).
Lista a_ej4_hermanos(ArbolBinario A, int clave);



/**
7.	Determinar si dos árboles binarios son equivalentes.
 */
bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B);


/**
8.	Dado un árbol “n-ario” se pide:
 */
// a.	Determinar la altura del mismo.
int c_ej8_altura(ArbolBinario A);

// b.	Determinar el nivel de un nodo.
int c_ej8_nivel(ArbolBinario A, int clave);

// c.	Listar todos los nodos internos (solo las claves).
Lista c_ej8_internos(ArbolBinario A);

// d.	Determinar si todas las hojas están al mismo nivel.
bool c_ej8_hojasmismonivel(ArbolBinario A);


/**
9.	Generar un algoritmo, recursivo o no, que permita construir un árbol binario de búsqueda balanceado (AVL) 
	a partir de un árbol binario sin un orden determinado.  
	Comparar las alturas de ambos árboles. Determinar la complejidad algorítmica.
 */
// Primero llamamos para construir el AVL
ArbolAVL a_ej9_construiravl(ArbolBinario A);

// Luego con el resultado de la funcion anterior llamamos a una funcion para que nos retorne la diferencia de las alturas 
// comparadas como Altura(ArbolBinario) - Altura(ArbolAVL).
int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL);


/**
10.	Dada una serie de números generados al azar, cargar la misma serie en un árbol binario de búsqueda y en un árbol binario balanceado “AVL”.  
	Comparar la altura de ambos árboles.  
	Repetir el proceso “n” veces. 
	¿Qué puede concluir al respecto?
 */
// Generamos una lista con la serie de numeros (unicos no repetidos)
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo);

// Ahora se la paso a la funcion que crea los 2 arboles
ArbolBinarioBusqueda a_ej10_crearABB(Lista L);
ArbolAVL a_ej10_crearAVL(Lista L);

// Ahora llamos a la funcion que compara las alturas.  La comparacion es Altura(ABB) - Altura(AVL).
int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL);

// Este proceso se debera repetir N veces  (N se debera poder tomar por teclado).

// LLamada general del proceso.  retorna una lista con todas las diferencias de las comparaciones.
Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar);


#endif // TP_ARBOLES_H
