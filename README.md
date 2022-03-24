# Caso-2
Caso 2 - Análisis de Algoritmos

-----------------------------------------------------------------------------------------------------------------------------------------
Ejercicio 1: Quicksort

Para demostrar la tasa de crecimiento del quicksort se realizaron 4 pruebas en total con 8 entradas
diferentes (10, 100, 1000, 10 000, 50 000, 80 000, 100 000, 200 000).

La primera prueba fue con un pivote fijo, siendo este siempre el último elemento. El primer vector
utilizado contenía números desordenados y el segundo vector números ordenados de forma descendente.
1. En el primer vector se puede observar con claridad que el tiempo aumenta de forma lineal, puesto
que mientras mayor es la entrada, el tiempo que tarda el algoritmo en dar respuesta aumenta en forma
proporcional. Su tasa de crecimiento se comporta entonces como O(n log n). (Ver Imagen)
2. En el segundo vector se pudo observar que el algoritmo se comporta de forma cuadrática. Al ser el
pivote el último elemento y los elementos del vector ordenados descendentemente, provoca que el quicksort
haga el partitioning de forma en que un lado queda con un vector vacío y el otro con todos los demás elementos.
Esto se demuestra en el gráfico y se nota que el comportamiento es cuadrático, es decir, mientras
más grande es la entrada, el tiempo en dar respuesta crece de forma exponencial, la tasa de crecimiento
aumenta cada vez más. O(n^2) (Ver Imagen)

Además, se puede notar que los swaps y las particiones del primer vector son mucho menores
que los del segundo vector, puesto que las particiones del segundo vector son n - 1 por ser el peor caso
del quicksort. 

De todo lo anterior se concluye que el primer vector tuvo un comportamiento de O(n log n) y el segundo
de O(n^2).

La segunda prueba se realizó con un pivote aleatorio y los mismos vectores.
1. El primer vector que contenía elementos desordenados se comportó de forma lineal, es decir
O(n log n). Su tasa de crecimiento aumenta en forma proporcional a la entrada. (Ver Imagen)
2.El segundo vector ordenado en forma descendente se comportó de forma lineal, puesto que al escoger 
un pivote random, las probabilidades de escoger un mínimo o un máximo se reducen muchísimo. De esta
forma, se evita obtener un comportamiento cuadrático. Su tasa de crecimiento aumenta en forma
proporcional al tamaño de la entrada. (Ver Imagen)

También, podemos notar que los swaps y las particiones de los vectores son un poco semejantes.

De lo anterior, se concluye que ambos vectores tienen un comportamiento de O(n log n).



-----------------------------------------------------------------------------------------------------------------------------------------

Ejercicio 2: Insertion Sort

Para demostrar la tasa de crecimiento del insertionsort se realizaron 3 pruebas en total con 8 entradas
diferentes (10, 100, 1000, 10 000, 50 000, 80 000, 100 000, 200 000).

1. La primera prueba se realizó con un vector desordenado. Se pudo observar que mientras más grande
es la entrada, el crecimiento del algoritmo es exponencial. Es un algoritmo de comportamiento cuadrático 
O(n^2), es decir, la tasa de crecimiento aumenta conforme aumenta la entrada. Y, efectivamente, 
podemos notar que las "regresiones", las iteraciones del algoritmo y la duración del algoritmo en 
dar respuesta aumenta cada vez más y más, según crece el valor de entrada. (Ver Imagen)

2. La segunda prueba se llevo a cabo con un vector ordenado de forma descendente. Esto supone
el peor caso para el Insertion Sort debido a que el algoritmo tiene que recorrer todos los elementos anteriores
al actual para poder insertarlo en su posición correcta. De este modo, se obtiene un algoritmo cuadrático 
O(n^2), en el que el crecimiento es exponencial. En este caso podemos observar que las "regresiones" 
e iteraciones son mucho mayores que en el caso promedio, así como también lo es el tiempo en el 
que da una respuesta. (Ver Imagen)

3. La tercera prueba se realizó con un vector odenado de forma ascendente. Este es el mejor caso
del Insertion Sort, puesto que el algoritmo solo tiene que iterar n veces sin tener que ordenar ningún elemento.
De esta forma, obtenemos un algoritmo lineal. La tasa de crecimiento es proporcional a la entrada. Se puede
observar que no hace ninguna "regresión" y la cantidad de iteraciones son únicamente las del for, es decir, 
el tamaño de la entrada. Por esta razón es O(n). (Ver Imagen)


-----------------------------------------------------------------------------------------------------------------------------------------

Ejercicio 3: Free text search

Para este ejercicio se utilizo el algoritmo de búsqueda de texto Rabin Karp, que tiene una complejidad
de O(m+n) en el mejor caso siendo m la longitud del texto y n la longitud del patrón a buscar.
Es un algoritmo lineal.

Para comprobarlo se realizaron 3 pruebas. 

1. El patrón "aeiou1234" no se encuentra en el texto. Esta búsqueda dura aproximadamente lo mismo
que buscar una palabra. 

2. El patrón "La palabra cosmopolita" se encontró en el texto 11 veces, y duró más que el patrón anterior. 
Esto se debe a que el patrón es más largo.

3. El patrón "La época actual es una encrucijada histórica para nuestra civilización y quizás para nuestra"
se encontró 11 veces en el texto, pero tardó más para llegar a este resultado debido a la longitud del patrón.

Se probaron también otras palabras como "a", "galaxia", "cosmos" y se pudo comprobar que la longitud
del patrón afecta el crecimiento del algoritmo. Con el string "a" se encontraron muchas más apariciones
y el algoritmo duró aproximadamente la mitad de lo que tarda buscando la palabra "galaxia" o "cosmos". 

Entonces, se puede concluir que la tasa de este algoritmo es lineal, puesto que el tiempo de respuesta
dependerá de su entrada (longitud del texto y patrón de búsqueda), y será proporcional a esta. 

-----------------------------------------------------------------------------------------------------------------------------------------