# Trabajo Práctico Nro. 3: Pilas

## Ejercicio 4
### Complejidad algoritmica
En este ejercicio nos encontramos con una funcion llamada "p_ej4_cambiarbase(int decimal, int base)".<br>
La funcion se encarga a traves de diviciones sucesivar entre el decimal y la base, siendo el decimal modificado en cada iteracion por el valor del resultado de la divicion, ir guardado en una pila los restos de las diviciones.<br>
Que a posterior serian expresados en sus respectivas bases por otra iteracion segun la base seleccionada.<br>
La complejidad algoritmica de esta funcion recae en que durante el primer ciclo while se tendra que realizar iteraciones determinadas por al numero de digitos que tendra el numero expresado en la nueva base. Y en el segundo ciclo while se tendra que realizar iterciones para desapilar la pila proporcionales a la cantida de digitos del numero expresado en la nueva base.<br>
Comprendiendo que nuestra complejidad sera definida segun la cantidad de digitos que tendra el decimal luego de convertirse de base, pudiendo llamar a este como 'n' podemos plantear nuestra complejidad algoritmica con la siguiente formula: **O(log(n))**.<br>
Por otro lado, si tenemos en cuenta la implementación de pilas utilizada en la ejecución, la complejidad no varía, ya que los métodos utilizados provenientes de este TAD es muy similar en las 2 implementaciones que poseemos, además que la complejidad interna de estas sigue siendo  **O(log(n))**. 

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