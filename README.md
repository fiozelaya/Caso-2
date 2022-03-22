# Caso-2
Caso 2 - Análisis de Algoritmos

Ejercicio 1: Quicksort

Para demostrar el tiempo algorítmico del quicksort se realizaron 4 pruebas en total con 8 entradas
diferentes (10, 100, 1000, 10000, 50000, 80000, 100000, 200000).

La primera prueba fue con un pivote fijo, siendo este siempre el último elemento. El primer vector
utilizado contenía números desordenados y el segundo vector números ordenados de forma descendente.
1. En el primer vector se pudo observar con claridad que el tiempo aumenta de forma logarítmica, puesto
que mientras mayor es la entrada, el tiempo que tarda el algoritmo en dar respuesta aumenta pero no
de forma exponencial. (Ver Imagen)
2. En el segundo vector se pudo observar que el algoritmo se comporta de forma cuadrática. Al ser el
pivote el último elemento y los elementos del vector ordenados descendentemente, provoca que el quicksort
haga el partitioning de forma en que un lado queda con un vector vacío y el otro con todos los demás elementos.
Esto se demuestra en el gráfico, al notar que el comportamiento es claramente cuadrático, es decir, mientras
más grande es la entrada, el tiempo en dar respuesta crece de forma exponencial. (Ver Imagen)

La segunda prueba se realizó con un pivote aleatorio y los mismos vectores.
1. El primer vector que contenía elementos desordenados se comportó también de forma logarítmica e
incluso más eficiente que con un pivote fijo.
2.El segundo vector ordenado en forma descendente se comportó de forma logarítmica, puesto que al escoger 
un pivote random, las probabilidades de escoger un mínimo o un máximo se reducen muchísimo. De esta
forma, se evita obtener un comportamiento cuadrático.


Ejercicio 2: Insertion Sort

Para demostrar el tiempo algorítmico del insertionsort se realizaron 3 pruebas en total con 8 entradas
diferentes (10, 100, 1000, 10000, 50000, 80000, 100000, 200000).

1. La primera prueba se realizó con un vector desordenado. Se pudo observar que mientras más grande
es la entrada, el crecimiento del algoritmo es exponencial. Esto nos da un algoritmo cuadrático.

2. La segunda prueba se llevo a cabo con un vector ordenado de forma descendente. Esto supone
el peor caso para el Insertion Sort debido a que el algoritmo tiene que recorrer todos los elementos anteriores
al de la iteración actual para poder insertarlo en su posición correcta. De este modo, se obtiene un algoritmo
cuadrático, en el que el crecimiento es exponencial.

3. La tercera prueba se realizó con un vector odenado de forma ascendente. Este es el mejor caso
del Insertion Sort, puesto que el algoritmo solo tiene que iterar n veces sin tener que ordenar ningún elemento.
De esta forma, obtenemos un algoritmo lineal.

Ejercicio 3: Free text search