# Trabajo Práctico Nro. 5: Árboles

## Ejercicio 2
### Complejidad algoritmica
En este ejercicio las funciones llamadas Lista a_ej2_hojas(ArbolBinario A), Lista a_ej2_interiores(ArbolBinario A) y Lista a_ej2_buscarclave(ArbolBinario A, int clave), tienen la misma complejidad algoritmica, ya que todos son resueltos de manera recursiva recorriendo cada uno de los nodos del arbol.
Podemos expresar la complejidad algoritmica de estas funciones con la notacion **O(n)**.

## Ejercicio 9
### Complejidad algoritmica
En este ejercicio la funcion llamada ArbolAVL a_ej9_construiravl(ArbolBinario A) lo que hace es llamar a una funcion recursiva que irá recorriendo todos los nodos y agregandolo a un arbol avl de resultado. Dado que cada nodo se recorre una sola vez, decimos que la complejidad de esta funcion es de O(n).
Esto mismo sucede en la funcion int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL), la cual recorre todos los nodos de ambos arboles recibidos por parametro, lo cual nos da que la complejidad en este caso es de O(2n).