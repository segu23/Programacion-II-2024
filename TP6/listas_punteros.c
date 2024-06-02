#include "listas.h"
#include "tipo_elemento.h"
#include <stdlib.h>
#include <stdio.h>

static const int TAMANIO_MAXIMO_LISTAS = 100;

struct NodoListas {
    TipoElemento datos;
    struct NodoListas *siguiente;
};

struct ListaRep {
    struct NodoListas *inicio;
    int cantidad;
};

struct IteradorRep {
    struct NodoListas *posicionActual;
};

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    nueva_lista->inicio = NULL;
    nueva_lista->cantidad = 0;
    return nueva_lista;
}


bool l_es_vacia(Lista lista) {
    return (lista->cantidad == 0);
}


bool l_es_llena(Lista lista) {
    return (lista->cantidad == TAMANIO_MAXIMO_LISTAS);
}


int l_longitud(Lista lista) {
    return lista->cantidad;
}


bool l_agregar(Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) {
        return false;
    }
    // Ahora lo agrego
    struct NodoListas *nuevo_nodo = malloc(sizeof(struct NodoListas));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = nuevo_nodo;
    } else {
        // Debo buscar el puntero del ultimo
        struct NodoListas *temp2 = lista->inicio;
        while (temp2->siguiente != NULL) {
            temp2 = temp2->siguiente;
        }
        temp2->siguiente = nuevo_nodo;
    }
    lista->cantidad++;
    return true;
}


bool l_borrar(Lista lista, int clave) {
    if (l_es_vacia(lista)) {
        return false;
    }

    bool borre = false;

    // Ahora comienza a borrar
    struct NodoListas *actual = lista->inicio;

    while (actual != NULL && actual->datos->clave == clave) {
        lista->inicio = actual->siguiente;
        free(actual);
        lista->cantidad--;
        actual = lista->inicio;
        borre = true;
    }
    // Borra el resto de las claves que no estan al principio
    while (actual != NULL && actual->siguiente != NULL) {
        if (actual->siguiente->datos->clave == clave) {
            struct NodoListas *temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            free(temp);
            lista->cantidad--;
            borre = true;
        } else {
            actual = actual->siguiente;
        }
    }
    return borre;
}


TipoElemento l_buscar(Lista lista, int clave) {
    struct NodoListas *actual = lista->inicio;
    while (actual != NULL) {
        if (actual->datos->clave == clave) {
            return actual->datos;
        }
        actual = actual->siguiente;
    }
    return NULL;
}


bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    if (l_es_llena(lista)) {
        return false;
    }

    // Controlo si pos > cantidad de elementos mando a agregar
    if (pos > l_longitud(lista)) {
        l_agregar(lista, elemento);
        return false;
    }

    // Ahora si lo voy a insertar
    struct NodoListas *nuevo_nodo = malloc(sizeof(struct NodoListas));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    if (pos == 1) {
        nuevo_nodo->siguiente = lista->inicio;
        lista->inicio = nuevo_nodo;
    } else {
        struct NodoListas *temp2 = lista->inicio;
        for (int i = 0; i < pos - 2; i++) {
            temp2 = temp2->siguiente;
        }
        nuevo_nodo->siguiente = temp2->siguiente;
        temp2->siguiente = nuevo_nodo;
    }
    lista->cantidad++;
    return true;
}


bool l_eliminar(Lista lista, int pos) {
    if (l_es_vacia(lista)) {
        return false;
    }

    bool borre = false;

    struct NodoListas *actual = lista->inicio;
    if (1 <= pos && pos <= l_longitud(lista)) {
        if (pos == 1) {
            lista->inicio = actual->siguiente;
            free(actual);
            borre = true;
        } else {
            for (int i = 0; i < pos - 2; i++) {
                actual = actual->siguiente;
            }
            // actual apunta al nodo en posición (pos - 1)
            struct NodoListas *temp = actual->siguiente; // nodo en pos
            actual->siguiente = temp->siguiente; // nodo en pos + 1
            free(temp);
            borre = true;
        }
        lista->cantidad--;
    }
    return borre;
}


TipoElemento l_recuperar(Lista lista, int pos) {
    if (pos > l_longitud(lista)) {
        return NULL;
    }
    // Si existe lo retorno
    struct NodoListas *temp2 = lista->inicio;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = temp2->siguiente;
    }
    return temp2->datos;
}


void l_mostrar(Lista lista) {
    struct NodoListas *temp2 = lista->inicio;
    printf("Contenido de la lista: ");
    while (temp2 != NULL) {
        printf("%d ", temp2->datos->clave);
        temp2 = temp2->siguiente;
    }
    printf("\n");
}


//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

Iterador iterador(Lista lista) {
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->posicionActual = lista->inicio;
    return iter;
}


bool hay_siguiente(Iterador iterador) {
    return (iterador->posicionActual != NULL);
}


TipoElemento siguiente(Iterador iterador) {
    TipoElemento actual = iterador->posicionActual->datos;
    iterador->posicionActual = iterador->posicionActual->siguiente;
    return actual;
}
