#include "listas.h"
#include "tipo_elemento.h"
#include <stdlib.h>
#include <stdio.h>

static const int TAMANIO_MAXIMO = 100;
static const int NULO = -1;

struct Nodo {
    TipoElemento datos;
    int siguiente;
};

struct ListaRep {
    struct Nodo *cursor;
    int inicio;
    int libre;
    int cantidad;
};

struct IteradorRep {
    Lista lista;
    int posicionActual;
};


//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
// Rutinas del TAD de Lista
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

Lista l_crear() {
    int i = 0;
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));

    // TODO hacer flexible y que la lista crezca sola
    nueva_lista->cursor = calloc(TAMANIO_MAXIMO, sizeof(struct Nodo));
    nueva_lista->cantidad = 0;
    nueva_lista->inicio = NULO;

    // Encadeno todos los libres
    for (i=0; i<=(TAMANIO_MAXIMO-2); i++) {
        nueva_lista->cursor[i].siguiente = i+1;
    }

    // Instancio inicio, libre y demas
    nueva_lista->libre = 0;
    nueva_lista->cursor[TAMANIO_MAXIMO-1].siguiente = NULO;
    nueva_lista->inicio = NULO;

    // retorno la lista creada
    return nueva_lista;
}


bool l_es_vacia(Lista lista) {
    return lista->cantidad == 0;
}


bool l_es_llena(Lista lista) {
    return (lista->cantidad == TAMANIO_MAXIMO);
}


int l_longitud(Lista lista) {
    return lista->cantidad;
}


bool l_agregar(Lista lista, TipoElemento elemento) {
    int p;
    int q;
    int anteq;

    // controlo lista llena
    if (l_es_llena(lista)) {
        return false;
    }

    // Tomo el primer libre
    p = lista->libre;
    lista->libre = lista->cursor[p].siguiente;

    // Asigno el dato
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;

    // Controlo que no sea el primero de la lista
    if (l_es_vacia(lista)) {
        lista->inicio = p;
    } else {
        // lo ubico al final
        q = lista->inicio;
        while (q != NULO) {
            anteq = q;  //guardo el anterior porque no tengo puntero al anterior
            q = lista->cursor[q].siguiente;
        }
        lista->cursor[anteq].siguiente = p;
    }
    lista->cantidad++;
    return true;
}


bool l_borrar(Lista lista, int clave) {
    if (l_es_vacia(lista)) {
        return false;
    }

    bool borre = false;
    int q;
    int p = lista->inicio;

    // borro las claves que coinciden con el inicio
    while ((p != NULO) && (lista->cursor[p].datos->clave == clave)) {
        q = p;
        lista->inicio = lista->cursor[p].siguiente;
        // recupero el nodo en el libre para no perderlo
        lista->cursor[q].siguiente = lista->libre;
        lista->libre = q;
        // Descuento 1 y arranco de nuevo desde el inicio
        lista->cantidad--;
        p = lista->inicio;
        borre = true;
    }

    // Borro las claves en el resto de la lista
    int qant;
    p = lista->inicio;
    while (p != NULO) {
        // pregunto por uno adelantado
        if (lista->cursor[p].datos->clave == clave) {
            q = p;
            lista->cursor[qant].siguiente = lista->cursor[p].siguiente;
            // Preservo en el libre
            lista->cursor[q].siguiente = lista->libre;
            lista->libre = q;
            lista->cantidad--;
            p = qant;  //vuelvo a tomar el qant para revisar que no existan otras claves iguales
            borre = true;
        } else {
            qant = p;  // guardo el anterior
            p = lista->cursor[p].siguiente;
        }
    }
    return borre;
}


TipoElemento l_buscar(Lista lista, int clave) {
    int p = lista->inicio;
    while (p != NULO) {
        if (lista->cursor[p].datos->clave == clave) {
            return lista->cursor[p].datos;
        }
        p = lista->cursor[p].siguiente;
    }
    return NULL;
}


bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    // Controla si la posicion ordinal es mayor a la cantidad
    // llama automaticamente al agregar
    if (pos > l_longitud(lista)) {
        l_agregar(lista, elemento);
        return false;
    }

    // Sino asigna espacio tomando del libre
    int p = lista->libre;
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;

    // valida si es la primer posicion
    if (pos == 1) {
        lista->cursor[p].siguiente = lista->inicio;
        lista->inicio = p;
    } else {
        int temp2 = lista->inicio;
        for (int i = 0; i < pos - 2; i++) {
            temp2 = lista->cursor[temp2].siguiente;
        }
        lista->cursor[p].siguiente = lista->cursor[temp2].siguiente;
        lista->cursor[temp2].siguiente = p;
    }
    // Cuenta uno mas
    lista->cantidad++;
    return true;
}


bool l_eliminar(Lista lista, int pos) {
    int p;
    bool borre = false;
    int actual = lista->inicio;

    if (1 <= pos && pos <= l_longitud(lista)) {
        if (pos == 1) {
            p = actual;
            lista->inicio = lista->cursor[actual].siguiente;
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p;
	    borre = true;
        } else {
            for (int i = 0; i < pos - 2; i++) {
                actual = lista->cursor[actual].siguiente;
            }
            // actual apunta al nodo en posición (pos - 1)
            p = lista->cursor[actual].siguiente; // nodo en pos
            lista->cursor[actual].siguiente = lista->cursor[p].siguiente; // nodo en pos + 1
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p;
            borre = true;
        }
        lista->cantidad--;
    }
    return borre;
}


TipoElemento l_recuperar(Lista lista, int pos) {
    int temp2 = lista->inicio;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = lista->cursor[temp2].siguiente;
    }
    return lista->cursor[temp2].datos;
}


void l_mostrar(Lista lista) {
    int temp2 = lista->inicio;
    printf("Contenido de la lista: ");
    while (temp2 != NULO) {
        printf("%d ", lista->cursor[temp2].datos->clave);
        temp2 = lista->cursor[temp2].siguiente;
    }
    printf("\n");
}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
// Rutinas del ITERADOR
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

Iterador iterador(Lista lista) {
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicionActual = lista->inicio;
    return iter;
}


bool hay_siguiente(Iterador iterador) {
    return (iterador->posicionActual != NULO);
}


TipoElemento siguiente(Iterador iterador) {
    TipoElemento actual = iterador->lista->cursor[iterador->posicionActual].datos;
    iterador->posicionActual = iterador->lista->cursor[iterador->posicionActual].siguiente;
    return actual;
}

