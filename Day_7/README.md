
# LABORATORIES PART 2
## ELECCIÓN DEL PROBLEMA
El problema ha sido elegido ya que consideramos que la difiucltad del mismo era adecuada, también fue elegido ya que se podían aplciar los conocimientos obtenidos en clase.
## ESTRUCTURA DE DATOS UTILIZADA
En este problema se ha utilizado programación dinámica ya que la cantidad de resultados aplicando recursividad normal es muy elevada, haciendo que el programa esté en una "eterna ejeución".
## COMO SE HA ABORDADO EL PROBLEMA
El problema ha sido abordado aplicando una lógica sencilla de programación dinámica, la idea planteada es que el código revisa la matriz de arriba a abajo desde la punta del árbol 'S'. Desde este punto cuando un cámino encuentra un '^' este se divide en dos (sin restricciones de que otro camino haya pasado ya por ahí, no como en la primera parte). Al final cuando llega a la última fila de la matriz se suma 1 al resultado. Esto se logra en él código mediante la llamada de mem = func() + func() y el hecho de que cuando se llega al final mem = 1;
## ALTERNATIVAS
A la hora de realizar el problema se planteó la idea de usar un grafo dirigído donde cada '^' era un nodo y buscarías mediante DFS con backtracking la cantidad de caminos posibles desde
el primer nodo hasta un nodo extra que uniría todos los nodos caminos que llegaran al final, pero dada la complejidad de la implementación y mirando de forma retrospectiva llegamos a la consclusión de que era mejor usar reursividad normal.
A la hora de usar recursividad normal llegamos a la conclusión de que para problemas grandes no iba a funcionar así que implementamos el problema mediante programación dinámica.
## QUE SE HA APRENDIDO
Aunque al final no se haya implementado mediante grafos, el intento de realizarlo mediante un grafo nos ha servido para aprender a crear una clase simple de un grafo, conteniendo esta las funciones de insertar nodos, eliminar nodos ,insertar aristas y buscar nodos; donde cada nodo del grafo contiene una lista de nodos veicnos.

