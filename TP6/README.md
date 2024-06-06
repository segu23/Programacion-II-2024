# Trabajo Práctico Nro. 5: Tablas Hash

## Ejercicio 5
### Conclusiones
En este punto notamos que si utilizamos la tabla hash con la implementacion de lista de colisiones, la tabla hash en todos los promedios de las repeticiones realizadas es mas eficiente que el arbol AVL.
Esto se debe a que el arbol AVL para buscar una clave debe recorrer los nodos comparando la clave buscada con la clave de ese nodo hasta encontrar la clave deseada, mientras que la tabla hash obtiene el indice de esta clave calculando su hash, con esto se direcciona al momento, en caso de que haya colision, debe buscar en la lista de colisiones la clave deseada pero este proceso es mas rapido que recorrer todo el arbol AVL ya que solo busca en las claves que colisionan.
En el caso de utilizar la tabla hash con la implementacion de zona de overflow, si no se encuentra la clave, la tabla hash incrementa muchisimo el tiempo de la busqueda haciendola menos eficiente que el arbol, esto sucede ya que al no encontrar la clave, primero busca en toda la tabla y luego va a buscar en la zona de overflow esta clave, mientras mas extensa la zona de overflow, mas demorara en encontrar la clave buscada.