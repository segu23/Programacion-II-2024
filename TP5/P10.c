#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbol-binario-busqueda.c"
#include "arbol-avl.c"
#include "listas_arreglos.c"
#include "nodo.c"
#include "tipo_elemento.c"

/**
10.	Dada una serie de números generados al azar, cargar la misma serie en un árbol binario de búsqueda y en un árbol binario balanceado “AVL”.  
	Comparar la altura de ambos árboles.  
	Repetir el proceso “n” veces. 
	¿Qué puede concluir al respecto?
 */

// Generamos una lista con la serie de numeros (unicos no repetidos)
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo) {
    Lista valores = l_crear();
    int rango = valormaximo - valorminimo + 1;

    if (rango < cantidadclavesagenerar) {
        printf("No es posible generar %d claves únicas en el rango dado.\n", cantidadclavesagenerar);
        return valores;
    }

    for (int i = 0; i < cantidadclavesagenerar; i++) {
        int clave;
        do {
            clave = rand() % rango + valorminimo;
        } while (l_buscar(valores, clave));

        l_agregar(valores, te_crear(clave));
    }
    return valores;
}

// Ahora se la paso a la funcion que crea los 2 arboles
// Crear ABB
ArbolBinarioBusqueda a_ej10_crearABB(Lista L) {
    ArbolBinarioBusqueda arbolBB = abb_crear();
    Iterador itera = iterador(L);
    while (hay_siguiente(itera)) {
        TipoElemento elemento_actual = siguiente(itera);
        abb_insertar(arbolBB, elemento_actual);
    }
    return arbolBB;
}

// Crear AVL
ArbolAVL a_ej10_crearAVL(Lista L) {
    ArbolAVL arbolAVL = avl_crear();
    Iterador itera = iterador(L);
    while (hay_siguiente(itera)) {
        TipoElemento elemento_actual = siguiente(itera);
        avl_insertar(arbolAVL, elemento_actual);
    }
    return arbolAVL;
}

// Calcula la altura de un árbol
int calcularAlturaArbol(NodoArbol nodo){
    if(nodo==NULL){
        return 0;
    }
    else
    {
        int alturaIzquierda=calcularAlturaArbol(nodo->hi);
        int alturaDerecha=calcularAlturaArbol(nodo->hd);
        return 1+(alturaIzquierda>alturaDerecha ? alturaIzquierda:alturaDerecha);
    } 
}

// Ahora llamos a la funcion que compara las alturas.  La comparacion es Altura(ABB) - Altura(AVL).
int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL) {
    printf("La altura de ABB es de: %d \nLa altura de AVL es de: %d \n", calcularAlturaArbol(ABB->raiz), calcularAlturaArbol(AVL->raiz));
    return calcularAlturaArbol(ABB->raiz) - calcularAlturaArbol(AVL->raiz);
}

// LLamada general del proceso.  retorna una lista con todas las diferencias de las comparaciones.
Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar) {
    Lista diferencias = l_crear();
    for(int i=0; i<N_repeticiones; i++) {
        Lista L = a_ej10_generarlistaclaves(cantidaclavesagenerar, valorminimo, valormaximo);
        ArbolBinarioBusqueda ABB = a_ej10_crearABB(L);
        ArbolAVL AVL = a_ej10_crearAVL(L);
        int dif_alturas = a_ej10_difalturas(ABB, AVL);
        l_agregar(diferencias, te_crear(dif_alturas));
    }
    return diferencias;
}

int main() {
    srand(time(NULL));
    int n;

    printf("Ingrese el numero de repeticiones: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Lista serie_numeros = a_ej10_generarlistaclaves(10, 1, 100); // Generar 10 números aleatorios // Entre los Primeros 100 Numeros
        ArbolBinarioBusqueda abb = a_ej10_crearABB(serie_numeros);
        ArbolAVL avl = a_ej10_crearAVL(serie_numeros);

        int dif_alturas = a_ej10_difalturas(abb, avl);
        printf("Diferencia de alturas entre el Arbol de Busqueda Binaria y Arbol AVL en la repeticion %d: %d\n", i + 1, dif_alturas);
    }
    printf("En Conclusion el auto balanceo del arbol AVL es mas grande que en el del arbol ABB \nen la mayoria de las ocasiones lo llega a reducir hasta casi la mitad teniendo en cuenta su rama mas larga");
    return 0;
}


