# Trabajo Práctico Nro. 2: Listas

## Ejercicio 6
### Complejidad algorítmica
En este ejercicio contamos con una funcion con el siguiente encabezado bool esSublista(Lista L1, Lista L2).<br>
Esta función es la encargada de realizar la comprobación entre dos listas y determinar si L2 es una sublista de L1.<br>
La complejidad algorítmica de la misma está condicionada por la longitud de L1 a quien llamaremos 'm' y la logitud de L2 y la llamaremos 'n'.<br>
Dado que para determinar la complejidad algorítmica hay que pensar en el peor caso y en esta ocación contamos con dos while anidados, 
dichos while's recorren de principio a fin L2 y por cada elemento recorre de principio a fin L1.<br>
Entendiendo esto decimos que la complejidad está dada por la siguiente fórmula: **O(n*m)**.
