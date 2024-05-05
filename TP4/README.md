# Trabajo Práctico Nro. 4: Colas

## Ejercicio 5
### Complejidad algoritmica
En este ejercicio nos encontramos con una función llamada c_ej5_divisortotal(Cola c, bool *fuetotal). Esta función se encarga de encontrar un divisor total o parcial en una cola de números enteros.<br>
La función tiene dos bucles while al principio que desencolan y encolan todos los elementos de la cola c a la cola caux y viceversa en el que se consigue la longitud de la cola introducida y en el segundo while se vuelven a poner los elementos a la cola original. Cada uno de estos bucles tiene una complejidad de **O(n)**, donde n es la longitud de la cola.<br>
Luego, tiene un bucle for que recorre todos los elementos de la cola. Dentro de este bucle, hay otro bucle for que también recorre todos los elementos de la cola. Esto da lugar a una complejidad de **O(n^2)** para esta parte del código.
Por lo tanto, la complejidad total de la función c_ej5_divisortotal es **O(n^2)**.<br>
Por otro lado, si tenemos en cuenta la implementación de colas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD son muy similares en las 3 implementaciones que poseemos, además de que la complejidad interna de estas sigue siendo 
**O(n^2)**.