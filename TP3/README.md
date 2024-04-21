# Trabajo Práctico Nro. 3: Pilas

## Ejercicio 4
### Complejidad algoritmica
En este ejercicio nos encontramos con una funcion llamada "p_ej4_cambiarbase(int decimal, int base)".<br>
La funcion se encarga a traves de diviciones sucesivar entre el decima y la base, siendo el decimal modificado en cada iteracion por el valor del resultado de la divicion, ir guardado en una pila los restos de las diviciones.<br>
Que a posterior serian expresados en sus respectivas bases por otra iteracion segun la basee seleccionada.<br>
La complejidad algoritmica de esta funcion recae en que se tendra que en el primer ciclo while se tendra que realizar iteraciones determinadas por al numero de digitos que tendra el numero expresado en la nueva base. Y en el segundo ciclo while se tendra que realizar iterciones para desapilar la pila proporcionales a la cantida de digitos del numero expresado en la nueva base.<br>
Comprendiendo que nuestra complejidad sera definida segun la cantidad de digitos que tendra el decimal luego de convertirse de base, pudiendo llamar a este como 'n' podemos plantear nuestra complejidad algoritmica con la siguiente formula: **O(log(n))**.<br>
Por otro lado, si tenemos en cuenta la implementación de listas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD es muy similar en las 2 implementaciones que poseemos, además que la complejidad interna de estas sigue siendo  **O(log(n))**. 

## Ejercicio 6
### Complejidad algorítmica
En este ejercicio contamos con una funcion con el siguiente encabezado Pila eleminarIterativamente(Pila p, Pila aux, Pila aux2, int clave).<br>
Esta función es la encargada de segun la implementacion que selccionemos('Iterativa o Recursiva'), nos dejara eliminar de la pila los valores que coincidan con la clave otorgadare.<br>
La complejidad algorítmica en la implementacion recursiva está condicionada por la longitud de la pila que llamaremos 'n'.<br>
Dado que para para esta funcion tendremos que realizar llamadas recursivas proporcionales a la longitud de la pila diremos que su complegidad esta dada por la siguiente formula **O(n)**.<br>
Por otro lado La complejidad algorítmica en la implementacion iterativa está tambien condicionada por la longitud de la pila que llamaremos 'n'.<br>
Teniendo en esta implementacion dos ciclos while donde se recorrera hasta que la pila este vacia, siendo la pila a recorrer en ambos casos la misma, podremos decir que la complejidad algoritmica de esta seria de: **O(n)**.<br>
Por otro lado, si tenemos en cuenta la implementación de listas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD es muy similar en las 2 implementaciones que poseemos, además que la complejidad interna de estas sigue siendo **O(n)**.