# Trabajo Práctico Nro. 7: Conjuntos

## Ejercicio 6
### Complejidad algorítmica
La complejidad algoritmica depende del TAD utilizado.
Si se utiliza Conjuntos de listas la complejidad sera de O(n^2), ya que se utiliza la operacion de cto_diferencia() la cual recorre la lista de forma lineal.
En cambio al utilizar el TAD de conjuntos con arboles AVL la complejidad pasara a ser O(n log n) ya que el recorrido de un arbol AVL es mas eficiente y no hace falta recorrer todo el arbol.

## Ejercicio 7
### Complejidad algorítmica
En este ejercicio contamos con una funcion con el siguiente encabezado void determinar_subconjuntos(Conjunto A, Conjunto B, Conjunto C).<br>
Esta función es la encargada de realizar la comparacon entre 3 conjuntos y mostrar si son subconjuntos totales o parciales.<br>
Luego hay otras dos funcones que se encargan de verificar si la convinacion cumple para ser parcial o total.<br>
La complejidad algorítmica de las misma es constante sin tener en cuena las implementaciones.<br>
Teniendo en cuentas las implementaciones vistas en clase, cuando usemos conjuntos implementados con AVL vamos a tener una complejidad de **O(n log n)** ya que se utilizan funciones como "diferencia".<br>
Y si utilazamos la implementacion de listas la complejidad seria de **O(n2)** (n al cuadrado).

## Ejercicio 8
### Complejidad algorítmica
la complejidad algoritmica de la solucion es O(n**2), siendo n la cantidad de elementos del uno de los conjuntos si los dos conjuntos son iguales. La complejidad es de orden cuadratico usando cualquiera de las dos implementaciones.