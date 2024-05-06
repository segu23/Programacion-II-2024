# Trabajo Práctico Nro. 4: Colas

## Ejercicio 3
### Complejidad algoritmica
En este ejercicio la funcion llamada c_ej3_iguales(Cola c1, Cola c2) se encarga de comparar las claves de cada
uno de los elementos de las colas y devuelve verdadero si las claves de los elementos, que se encuentran en la 
misma posicion de ambas colas, son iguales. Si las colas no son iguales devuelve falso.<br>
La funcion tiene dos bucles while. El primero desencola los elementos de la cola 1 y los va encolando en la cola auxiliar, luego desencola a los elementos de la cola 2 y los encola en la cola 1, en el transcurso de este proceso se realiza la comparacion. El segundo while se encarga de desencolar a los elementos de la cola 1 y encolarlos en la cola 2, tambien desencola a los elementos de la cola auxiliar y los encola en la cola 1, esto se hace para devolver sus valores originales a las colas 1 y 2, para que no se pierdan. Cada uno de estos bucles tiene una complejidad de **O(n)** siendo n la longitud de las colas, ya que los bucles van a dejar de iterar una vez que las recorran por completo. 

## Ejercicio 4
### Complejidad algoritmica
En este ejercicio nos encontramos con una función llamada c_ej4_colanorepetidos(Cola c). Esta función se encarga de quitar los repeditos de una cola.<br>
La funcion tiene dos bucles while al principio que se encargan de hacer una copia de la cola y dejar la cola original intacta cada uno de estos tiene una complejidad de **O(n)**.
Luego tiene un bucle while que dentro contiene dos bucles while mas, el primero desencola el primer elemento y el segundo desencola desde el elemento siguiente hasta el final de la cola, esto permite compararlos y seleccionar cuales encolar y cuales no a la cola respuesta. El ultimo while encola los elementos no repetidos para revisar los numeros que quedan y asi poder limpiar los repetidos restantes, al terminar los ciclos nos quedara la cola original intacta y una cola respuesta donde se encuentran los elementos que nunca se repitieron.
La complejidad algoritmica de este while medida en el peor de los casos es **O(n^2)**. el peor de los casos es aquel en el cual la cola no tiene repetidos.

## Ejercicio 5
### Complejidad algoritmica
En este ejercicio nos encontramos con una función llamada c_ej5_divisortotal(Cola c, bool *fuetotal). Esta función se encarga de encontrar un divisor total o parcial en una cola de números enteros.<br>
La función tiene dos bucles while al principio que desencolan y encolan todos los elementos de la cola c a la cola caux y viceversa en el que se consigue la longitud de la cola introducida y en el segundo while se vuelven a poner los elementos a la cola original. Cada uno de estos bucles tiene una complejidad de **O(n)**, donde n es la longitud de la cola.<br>
Luego, tiene un bucle for que recorre todos los elementos de la cola. Dentro de este bucle, hay otro bucle for que también recorre todos los elementos de la cola. Esto da lugar a una complejidad de **O(n^2)** para esta parte del código.
Por lo tanto, la complejidad total de la función c_ej5_divisortotal es **O(n^2)**.<br>
Por otro lado, si tenemos en cuenta la implementación de colas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD son muy similares en las 3 implementaciones que poseemos, además de que la complejidad interna de estas sigue siendo 
**O(n^2)**.

## Ejercico 6 
### Complejidad algoritmica
En este ejercicio, la función c_ej6_comunesapilaycola(Pila p, Cola c,Lista listaPila,Lista listaCola,Lista listaComunes) se encarga de encontrar elementos comunes entre una pila y una cola, manteniendo un registro de sus posiciones respectivas en cada una de las estructuras.<br>
El bucle principal contiene un bucle interno. El bucle externo se ejecutará tantas veces como elementos haya en la pila p, mientras que el bucle interno se ejecutará en el peor de los casos tantas veces como elementos haya en la cola c. Por lo tanto, la complejidad de estos bucles anidados es O(n*m), donde 'n' es el tamaño de la pila y 'm' es el tamaño de la cola.<br>
Luego, tiene un bucle for que recorre todos los elementos de la cola. Dentro de este bucle, hay otro bucle for que también recorre todos los elementos de la cola. Esto da lugar a una complejidad de **O(n^2)** para esta parte del código.
