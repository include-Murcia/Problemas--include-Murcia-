# CAFETERIA PART 1
## ELECCIÓN DEL PROBLEMA
El problema ha sido elegido ya que vimos claramente el uso de de un árbol para su resulción. Así mismo lo elegimos ya que consideramos que su dificultad era relativamente elevada, dada la implementación de dicho árbol

## ESTRUCTURA DE DATOS UTILIZADA
En este problema se hace uso de un árbol binario de búsqueda adaptado para funcionar mediante intervalos y resolver el problema.

## COMO SE HA ABORDADO EL PROBLEMA
A la hora de abordar el problema en un principio pensamos en utilizar un árbol binario de búsqueda donde se hacía la inserción y la búsqueda con respecto al mínimo de los intervalos, sin embargo esto no funcionaba ya que habían situaciones donde el rango donde un elemento inicialmente fresco se encontraba en otra rama donde el dicho elemento estaba, esto provocaba descuentos teniendo que adaptar de mejor manera el árbol.

Para adaptar el árbol modificamos la inserción y la búsqueda:
### INSERCIÓN
A la hora de insertar en el árbol se realiza un recorrido normal de inserción hasta que se llega a la posición donde se desea insertar, una vez ahí se comprueba cuál es el máximo entre la rama de la derecha, la izquierda y el nodo actual, actualizando el máximo del nodo actual en el proceso.

###BÚSQUEDA
La búsqueda es similar a la de un árbol binario normal, sin embargo primero comprobaremos si el elemento está dentro del intervalo actual, si es así directamente devolvemos que el elemento está fresco, sino miramos cual es el elemento máximo de la izquierda. Una vez realizado esto comrpobamos si el nodo de la izquierda existe y si el elemento está en el sub_árbol adecuado, si esto se cumple irá a la derecha, sino a la lizquierda. 
## ALTERNATIVAS
En un principio planteamos este problema mediante un vector de parejas, donde recorremos el vector cada vez hasta conseguir el resultado, sin embargo esto resultaba ser muy ineficiente pues en el peor de los casos teníamos que recorrer el vector todas las veces. Por esta razón decidimos hacer uso de un árbol, ya que, aunque haya que preparalo, la búsqueda de después es mucho más rápida
## QUE SE HA APRENDIDO
Por culpa de los problemas mencionados con anterioridad hemos tenido que aprender a crear un árbol de intervalos, así como a recoger inputs de problemas más complejos
