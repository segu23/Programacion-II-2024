# Trabajo Práctico Nro. 7: Conjuntos

## Ejercicio 7
### Complejidad algorítmica
En este ejercicio contamos con una funcion con el siguiente encabezado void determinar_subconjuntos(Conjunto A, Conjunto B, Conjunto C).<br>
Esta función es la encargada de realizar la comparacon entre 3 conjuntos y mostrar si son subconjuntos totales o parciales.<br>
Luego hay otras dos funcones que se encargan de verificar si la convinacion cumple para ser parcial o total.<br>
La complejidad algorítmica de las misma es constante sin tener en cuena las implementaciones.<br>
Teniendo en cuentas las implementaciones vistas en clase, cuando usemos conjuntos implementados con AVL vamos a tener una complejidad de **O(n log n)** ya que se utilizan funciones como "diferencia".<br>
Y si utilazamos la implementacion de listas la complejidad seria de **O(n2)** (n al cuadrado).