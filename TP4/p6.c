#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_colas.h"
#include "tipo_elemento.h"
#include "tipo_elemento.c"
#include "colas_arreglos.c"
#include "listas_arreglos.c"
#include "pilas_arreglos.c"

const unsigned int max_rand =100;

// Dada una pila y una cola generada con valores al azar retornar en una lista todos los
// valores comunes a ambas y en qué posición ordinal se encontró cada uno en su
// estructura. No se deben destruir las estructuras originales. No se deben perderse las
// estructuras originales. Determinar la complejidad algorítmica de la solución empleada
void l_mostrar_IndicesyLista(Lista indice_pila,Lista indice_cola,Lista lista_comunes) {
    Iterador ite_pila=iterador(indice_pila);
    Iterador ite_cola=iterador(indice_cola);
    Iterador ite_comunes=iterador(lista_comunes);
    if(l_es_vacia(lista_comunes)){
        printf("No hay elementos comunes.");
        return;
    }
    while (hay_siguiente(ite_pila)&&hay_siguiente(ite_cola)&&hay_siguiente(ite_comunes))
    {
        TipoElemento elemento_pila=siguiente(ite_pila);
        TipoElemento elemento_cola=siguiente(ite_cola);
        TipoElemento elemento_comunes=siguiente(ite_comunes);

        printf("\n%d:%d:%d", elemento_pila->clave,elemento_cola->clave,elemento_comunes->clave);
    }
}

void movercola(Cola dest,Cola src){
    while (!c_es_vacia(dest))
    {
        c_encolar(src,c_desencolar(dest));
    }  
    while (!c_es_vacia(src))
    {
        c_encolar(dest,c_desencolar(src));
    }    
}

void cargarPila(Pila pila,int cantidad){
    int numero_azar;
    Pila pilaTmp=p_crear();
    bool hayRepetido=false;

    srand(time(NULL));
    numero_azar=rand()%max_rand;
    p_apilar(pila,te_crear(numero_azar));
    printf("[INFO]Posicion #1 Agregado a la PILA!\n");

    for (int i = 2; i < cantidad+1; i++)
    {
        numero_azar=rand()%max_rand;
        while (!p_es_vacia(pila))
        {
            TipoElemento elementoPila=p_desapilar(pila);
            p_apilar(pilaTmp,elementoPila);
            if(elementoPila->clave==numero_azar){
                hayRepetido=true;
                i--;
                break;
            }
            hayRepetido=false;
        }
        while (!p_es_vacia(pilaTmp))
        {
            p_apilar(pila,p_desapilar(pilaTmp));   
        }
        if(!hayRepetido){
            p_apilar(pila,te_crear(numero_azar));
            printf("[INFO]Posicion #%d Agregado a la PILA!\n",i);
        }
    }
    p_mostrar(pila);
}

void cargarCola(Cola cola,int cantidad){
    int numero_azar;
    Cola colaTmp=c_crear();
    bool hayRepetido=false;

    srand(time(NULL));

    numero_azar=rand()%max_rand;
    c_encolar(cola,te_crear(numero_azar));
    printf("[INFO]Posicion #1 Agregado a la COLA!\n");

    for (int i = 2; i < cantidad+1; i++)
    {
        numero_azar=rand()%max_rand;
        while (!c_es_vacia(cola))
        {
            TipoElemento elementoCola=c_desencolar(cola);
            c_encolar(colaTmp,elementoCola);
            if(elementoCola->clave==numero_azar){
                hayRepetido=true;
                i--;
                break;
            }  
            hayRepetido=false;
        }
        while (!c_es_vacia(colaTmp))
        {
            c_encolar(cola,c_desencolar(colaTmp));   
        }
        if (!hayRepetido)
        {
            c_encolar(cola,te_crear(numero_azar));
            printf("[INFO]Posicion #%d Agregado a la COLA!\n",i);
        }
    }
    c_mostrar(cola);
}

void c_ej6_comunesapilaycola(Pila p, Cola c,Lista listaPila,Lista listaCola,Lista listaComunes){
    Pila pilaAux=p_crear();
    Cola colaTmp=c_crear();

    int index_pila=1,index_cola=1;

    while (!p_es_vacia(p))
    {
        TipoElemento elementoPila=p_desapilar(p);
        p_apilar(pilaAux,elementoPila);
        while (!c_es_vacia(c)){
            TipoElemento elementoCola=c_desencolar(c);
            c_encolar(colaTmp,elementoCola);

            if (elementoCola->clave == elementoPila->clave) {
                l_agregar(listaComunes,te_crear(elementoCola->clave));
                l_agregar(listaPila,te_crear(index_pila));
                l_agregar(listaCola,te_crear(index_cola));
                break;     
            }
            index_cola++;
        }
        movercola(c,colaTmp); 
        
        index_pila++;
        index_cola=1;
    }

    while (!(p_es_vacia(pilaAux))){
        TipoElemento elementoAux1 = p_desapilar(pilaAux);
        p_apilar(p, elementoAux1);
    }
}

int main() {
    // Inicializar pila y cola
    Pila pila =p_crear();
    Cola cola =c_crear();
    int cantidadPila,cantidadCola;

    printf("Ingrese una cantidad (entre 0 y %d) numeros a generar para la PILA: ",max_rand/2);
    //si esta cerca del numero maximo randomizado puede salir todos los con coincidencia entre la pila y la cola
    scanf("%d",&cantidadPila);

    while ((cantidadPila<0)||(cantidadPila>(max_rand/2)))
    {
        printf("Ingrese una cantidad (entre 0 y %d) numeros a generar para la PILA: ",max_rand/2);
        scanf("%d",&cantidadPila);
    }
    

    cargarPila(pila,cantidadPila);

    printf("Ingrese una cantidad (entre 0 y %d) numeros a generar para la COLA: ",max_rand/2);
    //si esta cerca del numero maximo randomizado puede salir todos los con coincidencia entre la pila y la cola
    scanf("%d",&cantidadCola);
    while ((cantidadCola<0)&&(cantidadCola>(max_rand/2)))
    {
        printf("Ingrese una cantidad (entre 0 y %d) numeros a generar para la COLA: ",max_rand/2);
        scanf("%d",&cantidadPila);
    }

    cargarCola(cola,cantidadCola);

    Lista listaPila=l_crear();
    Lista listaCola=l_crear();
    Lista listaComunes=l_crear();
    c_ej6_comunesapilaycola(pila,cola,listaPila,listaCola,listaComunes);
    l_mostrar_IndicesyLista(listaPila,listaCola,listaComunes);
    
    return 0;
}
