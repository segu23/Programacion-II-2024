# Trabajo Práctico Nro. 5: Tablas Hash

## Ejercicio 5
### Conclusiones
En este punto notamos que si utilizamos la tabla hash con la implementacion de lista de colisiones, la tabla hash en todas las repeticiones es mas eficiente que el arbol AVL.
Esto se debe a que el arbol AVL para buscar una clave debe recorrer los nodos comparando la clave buscada con la clave de ese nodo hasta encontrar la clave deseada, mientras que la tabla hash obtiene el indice de esta clave calculando su hash, esto permite que la tabla hash llegue mas rapido a encontrar la clave.
En el caso de utilizar la tabla hash con la implementacion de zona de overflow, si no se encuentra la clave, la tabla hash incrementa muchisimo el tiempo de la busqueda haciendola muchisimo menos eficiente que el arbol, esto sucede ya que al no encontrar la clave, primero busca en toda la tabla y luego va a buscar en toda la zona de overflow esta clave.