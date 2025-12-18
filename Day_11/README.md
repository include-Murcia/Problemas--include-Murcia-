# REACTOR PART 2
## ELECCIÓN DEL PROBLEMA
El problema ha sido elegido ya que se obervó de forma clara la utulización de las estructuras utilizadas en clase, así mismo fue escogido dada su dificultad, considerándolo un problema de nivel moderado.

## ESTRUCTURA DE DATOS UTILIZADA
En este problema se ha hecho uso de una gran parte de las estructuras de datos dadas en clase, en este caso se han utlizado grafos, tablas hash y programción dinámica para poder obtener el resultado del problema de forma sencilla y eficiente.

## COMO SE HA ABORDADO EL PROBLEMA
A la hora de abordar este problema supimos desde el principio que estrucuras de datos deberiamos de utlizar. En este caso, cada combinación de tres letras representará un nodo del grafo cuyo identificador estará guardado en una tabla hash para su fácil y eficiente utilización.

Una vez recogidos los datos recogidos de `input.txt` y creados la tabla hash y el grafo se plantea un algoritmo capaz de contar la cantidad de caminos que hay de el nodo inicial `svr` al nodo final `out` pero con una condición, solo son válidos los caminos que pasan por dos nodos específicos más dando igual el orden. Para ello creamos dos variables booleanas 'ffr' y 'dac' las cuales controlarán si el camino recorrido ha pasado por esos dos nodos. Así con estas variables y con una matriz de tres dimensiones de memorización aplicamos un algoritmo básico de conteo de caminos donde se recorren los nodos de las listas de vecinos del nodo actual, hasta llegar al nodo final. Así pues cuando un camino llegue al nodo final se comprobará si este ha pasado por los nodos obligados, si es así devolverá 1, sino 0.

Por último se suman todos los caminos posibles en una variable que luego se devovlerá.

## ALTERNATIVAS
A la hora de plantear el problema primero planteamos traducir directamente las combinaciones de tres letras en un número y considerarlo este el nodo del grafo, sin embargo para facilitar las operaciones decidimos que usar una tabla hash era lo mejor ya que temporalmente no iba a ser tan significativo pero nos facilitaba mucho la realización del problema.

## QUE SE HA APRENDIDO
A la hora de la realización del problema aprendimos otra forma de ver la utilización de la programación dinámica ya que, en un principio utilizabamos un vector de memoria de una sla dimensión, sin embargo el aumentar la dimensión y la utilización de variables booleanas como comprobaciones nos ayudó a la realización del problema de una forma que fuera simple de entender.
