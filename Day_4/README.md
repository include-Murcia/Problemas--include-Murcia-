
# PRINTING DEPARMENT PART 2
## ELECCIÓN DEL PROBLEMA
El problema ha sido elegido ya que consideramos que la difiucltad del mismo era adecuada, y porque consideramos adecuado aplicar los conocimientos estudiados en clase para la resolución del mismo
## ESTRUCTURA DE DATOS UTILIZADA
En este problema se ha utilizado un grafo no dirigido ya que, aunque su creadión en un inicio es costosa temporalmente, luego hacer las operaciones restantes con él es más eficiente que trabajar con matrices.
## COMO SE HA ABORDADO EL PROBLEMA
Para abordar este problema se han hecho varias consideraciones:
1. Cada '@' se tratará como un nodo cuyos vecinos serán los '@' adyacentes a él en las 8 direcciones.
2. Cada vez que recoges un nodo no lo eliminas instantaneamente sino que lo eliminas una vez has hecho todo el recorrido

Con estas consieraciones una vez montado el grafo se hacen iteraciones dentro de el, guardando en un vector los nodos que tendremos que eliminar posteriormente. Cuando se llegue a un punto donde no se elimina nigún nodo, significará que no se pueden recoger más y el problema habrá terminado.
## ALTERNATIVAS
En un principio se planteó hacerlo mediante matrices como en la primera parte, sin embargo esto era temporalmente muy ineficiente ya que por cada "ronda de recogidas" se tenía que recorrer una matriz que cada vez contiene información menos importante (ya que al final los '.' no significan nada). Es por eso que al final se ha decidio el uso de grafos para realizar esta tarea de forma más eficiente ya que, en vez de consultar una matriz entera, solo consultas los datos que te importan (los '@').

## QUE SE HA APRENDIDO
A la hora de la realización del problema hemos aprendido a utilizar y crear correctamente un grafo así como a entenderlo mejor de forma teórica y práctica.
Así mismo también hemos aprendido que a veces la forma más elegante no tiene porqué ser la más eficiente, ya que en la realización de la parte 1 intentamos ya hacer uso de grafos pero resultó ser más eficiente iterar sobre la propia matriz en búsqueda de vecinos ya que el coste de la creación del grafo era igual al coste de encontrar el resultado mediante el conteo en la propia matriz.
