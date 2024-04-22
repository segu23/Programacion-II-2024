# Trabajo Práctico Nro. 3: Pilas

## Ejercicio 3
### Complejidad algoritmica
En este ejercicio contamos con una funcion llamada "bool p_ej3_iguales(Pila p1, Pila p2)".<br>
La funcion se encarga de desapilar 2 pilas en una unica pila auxiliar, comparando en cada iteracion el valor de las claves de los elementos, mientras estas sean iguales seguira iterando, si en algun momento se terminan ambas pilas y las claves nunca fueron diferentes, retornara true. Si en algun momento las claves son diferentes retornara false, 
si una de las pilas queda con elementos dentro luego de terminar de iterar, retornara false.
La complejidad algoritmica de esta funcion recaera en un unico while que recorre ambas pilas al mismo tiempo. Esto generara que la complejidad algoritmica este determinada
por la cantidad de elementos de la pila mas corta.
Podemos plantear la complejidad de este punto con la formula **O(n)**.

## Ejercicio 4
### Complejidad algoritmica
En este ejercicio nos encontramos con una funcion llamada "p_ej4_cambiarbase(int decimal, int base)".<br>
La funcion se encarga a traves de diviciones sucesivar entre el decimal y la base, siendo el decimal modificado en cada iteracion por el valor del resultado de la divicion, ir guardado en una pila los restos de las diviciones.<br>
Que a posterior serian expresados en sus respectivas bases por otra iteracion segun la base seleccionada.<br>
La complejidad algoritmica de esta funcion recae en que durante el primer ciclo while se tendra que realizar iteraciones determinadas por al numero de digitos que tendra el numero expresado en la nueva base. Y en el segundo ciclo while se tendra que realizar iterciones para desapilar la pila proporcionales a la cantida de digitos del numero expresado en la nueva base.<br>
Comprendiendo que nuestra complejidad sera definida segun la cantidad de digitos que tendra el decimal luego de convertirse de base, pudiendo llamar a este como 'n' podemos plantear nuestra complejidad algoritmica con la siguiente formula: **O(log(n))**.<br>
Por otro lado, si tenemos en cuenta la implementación de pilas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD es muy similar en las 2 implementaciones que poseemos, además que la complejidad interna de estas sigue siendo  **O(log(n))**.

## Ejercicio 5
### Complejidad algoritmica
En este ejercicio contamos con una funcion con el siguiente encabezado "Pila  p_ej5_invertir(Pila p)".<br>
La funcion se encarga de desapilar la pila original en 2 pilas auxiliares con el primer while. Luego se desapila una de las pilas auxiliares y se apila su contenido en la pila original, con el segundo while, para no perder la pila original. El contenido de la otra
pila auxiliar sera el contenido de la pila original pero invertido.<br>
La complejidad algoritmica en la implementacion esta condicionada por la longitud de la pila, ya que en ambos while la cantidad de iteraciones que realizaran, estara definida por la longitud de la pila original a la que llamaremos 'n'. Se puede plantear la complejidad de esta implementacion es: **O(n)**.<br>
Por otro lado, si tenemos en cuenta la implementación de pilas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD es muy similar en las 2 implementaciones que poseemos, además que la complejidad interna de estas sigue siendo **O(n)**.


## Ejercicio 6
### Complejidad algorítmica
En este ejercicio contamos con una funcion con el siguiente encabezado Pila eleminarIterativamente(Pila p, Pila aux, Pila aux2, int clave).<br>
Esta función es la encargada de segun la implementacion que selccionemos('Iterativa o Recursiva'), nos dejara eliminar de la pila los valores que coincidan con la clave otorgada.<br>
La complejidad algorítmica en la implementacion recursiva está condicionada por la longitud de la pila que llamaremos 'n'.<br>
Dado que, para esta funcion tendremos que realizar llamadas recursivas proporcionales a la longitud de la pila, diremos que su complegidad esta dada por la siguiente formula **O(n)**.<br>
Por otro lado La complejidad algorítmica en la implementacion iterativa está tambien condicionada por la longitud de la pila que llamaremos 'n'.<br>
Teniendo en esta implementacion dos ciclos while donde se recorrera hasta que la pila este vacia, siendo la pila a recorrer en ambos casos la misma, podremos decir que la complejidad algoritmica de esta seria de: **O(n)**.<br>
Por otro lado, si tenemos en cuenta la implementación de pilas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD es muy similar en las 2 implementaciones que poseemos, además que la complejidad interna de estas sigue siendo **O(n)**.

## Ejercicio 7
### Complejidad algoritmica
En este ejercico tenemos una funcion llamada "elementosComunes"(Pila pila1, Pila pila2).<br>
La función elementosComunes tiene dos bucles while anidados. El bucle exterior itera sobre los elementos de pila1 y el bucle interior itera sobre los elementos de pila2. En el peor caso, ambos bucles pueden recorrer cada elemento de sus respectivas pilas, lo que resultaría en una complejidad de **O(n^2)**, donde n es el número total de elementos en ambas pilas.<br>
La función cargarPila no afecta la complejidad del algoritmo principal, ya que solo se encarga de agregar elementos a una pila, lo cual es una operación de complejidad constante.<br>
Ya que el algoritmo principal depende en gran medida de la función elementosComunes, la complejidad algoritmica del programa se ve dominada por la complejidad de esta función, que es **O(n^2)**.<br>
Y la función moverPila itera sobre los elementos de src y los apila en dest. Esto implica un ciclo while que ejecuta p_desapilar y p_apilar una vez por cada elemento en src. Si n es el número total de elementos en src, la complejidad de esta función es **O(n)**.<br>

## Ejercicio 8
### Complejidad algorítmica
En este ejercicio desarrollamos una función con el siguiente encabezado Pila p_ej8_sacarrepetidos(Pila p).<br>
Dentro de esta función se hacen varias cosas, primero tenemos dos whiles no anidados, los cuales serian O(n) y O(n) respectivamente.<br>
Debajo de estos whiles nos encontramos con un while que dentro de si mismo ejecuta dos whiles más, por lo que tendriamos **O(n) * O(2n)**, quedandonos **O(2n^2**). Por lo que si tomamos la operación más compleja que realiza la función determinamos que esa es la complejidad de la misma.<br>
En este caso la complejidad no varía si tenemos en cuenta la implementación que usemos de Pilas ya que todas las funciones utilizadas son O(1).
