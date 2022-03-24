/*
Caso 2
InsertionSort

Fiorella Zelaya Coto
2021453615
*/

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <cstring>
#include <time.h>
#include <random>

using namespace std;

//globales
int cIteraciones = 0;
long long int cRegresiones = 0;


/*
Función que llena un array dependiendo del parámetro sign.
@param: array, tamaño del array y sign (0, desordenado; 1, ordenado ascendentemente; 2, ordenado descendentemente)
*/
void fill(int arr[], int size, int sign) {
    for (int i = 0; i < size; i++) {
        switch (sign) {
        case 0:
            arr[i] = rand() % size;
            break;
        case 1:
            arr[i] = i + 1;
            break;
        case 2:
            arr[i] = size - i;
        }
    }
}


/*
Insertion Sort.
Ordena un array insertando el elemento actual en su posición correcta.
@param: Recibe un array y el tamaño del array.
*/
void insertion_sort(int vector[], int size) { // loop invariant: array[0 - j-1] is always sorted
    int j;
    for (int i = 1; i < size; i++) {
        cIteraciones++;
        j = i;
        while (j != 0 && vector[j] < vector[j - 1]) {
            swap(vector[j], vector[j - 1]);
            j--;
            cRegresiones++;
        }

    }    
}

/*
Función para hacer las pruebas del insertionsort. 
Recibe el tamaño deseado del array y un sign que será 0 si el array está desordenado, 
1 si está ordenado ascendentemente y 2 descendentemente.
Al final imprime los stats.
*/
void pruebaInsertionSort(int size, int sign){
    int vector[size];
    fill(vector, size, sign);
    cout << "\nVector de " << size << " elementos: " << endl;
    cRegresiones = 0;
    cIteraciones = 0;
    double it1 = (double)clock() / CLOCKS_PER_SEC;
    insertion_sort(vector, size);
    double it2 = (double)clock() / CLOCKS_PER_SEC;
    cout << "Tiempo: " << (it2 - it1) << "\nRegresiones: " << cRegresiones << "\nIteraciones For: " << cIteraciones << "\nIteraciones totales: " << cIteraciones + cRegresiones << endl;
}


int main(){
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Ejercicio 2: Insertion sort" << endl;
    cout << "Caso promedio: Los elementos del array están en desorden. Tiene una complejidad en el tiempo de O(n^2)" << endl;

    pruebaInsertionSort(10, 0);
    pruebaInsertionSort(100, 0);
    pruebaInsertionSort(1000, 0);
    pruebaInsertionSort(10000, 0);
    pruebaInsertionSort(50000, 0);
    pruebaInsertionSort(80000, 0);
    pruebaInsertionSort(100000, 0);
    pruebaInsertionSort(200000, 0);


    cout << "\nPeor caso: Los elementos del array están en orden descendente y, por lo tanto en cada iteración el algoritmo debe\nrecorrer el array desde el índice i hasta 0. Tiene una complejidad en el tiempo de O(n ^ 2)" << endl;

    pruebaInsertionSort(10, 2);
    pruebaInsertionSort(100, 2);
    pruebaInsertionSort(1000,2);
    pruebaInsertionSort(10000,2);
    pruebaInsertionSort(50000,2);
    pruebaInsertionSort(80000,2);
    pruebaInsertionSort(100000,2);
    pruebaInsertionSort(200000,2);


    cout << "\nMejor caso: Los elementos del array están en orden ascendente o todos son iguales, por lo tanto el algoritmo simplemente\nrecorre el array sin realizar ningún swap. Tiene una complejidad en el tiempo de O(n)" << endl;

    pruebaInsertionSort(10, 1);
    pruebaInsertionSort(100, 1);
    pruebaInsertionSort(1000, 1);
    pruebaInsertionSort(10000, 1);
    pruebaInsertionSort(50000, 1);
    pruebaInsertionSort(80000, 1);
    pruebaInsertionSort(100000, 1);
    pruebaInsertionSort(200000, 1); 

    return 0;
}

/*

Resultados

Ejercicio 2: Insertion sort
Caso promedio: Los elementos del array est├ín en desorden. Tiene una complejidad en el tiempo de O(n^2)

Vector de 10 elementos:
Tiempo: 0
Regresiones: 18
Iteraciones For: 9
Iteraciones totales: 27

Vector de 100 elementos:
Tiempo: 0
Regresiones: 2605
Iteraciones For: 99
Iteraciones totales: 2704

Vector de 1000 elementos:
Tiempo: 0.005
Regresiones: 244828
Iteraciones For: 999
Iteraciones totales: 245827

Vector de 10000 elementos:
Tiempo: 0.487
Regresiones: 25177091
Iteraciones For: 9999
Iteraciones totales: 25187090

Vector de 50000 elementos:
Tiempo: 13.845
Regresiones: 626762122
Iteraciones For: 49999
Iteraciones totales: 626812121

Vector de 80000 elementos:
Tiempo: 36.855
Regresiones: 1599583278
Iteraciones For: 79999
Iteraciones totales: 1599663277

Vector de 100000 elementos:
Tiempo: 57.153
Regresiones: 2492835399
Iteraciones For: 99999
Iteraciones totales: 2492935398

Vector de 200000 elementos:
Tiempo: 237.053
Regresiones: 10024351609
Iteraciones For: 199999
Iteraciones totales: 10024551608

Peor caso: Los elementos del array est├ín en orden descendente y, por lo tanto en cada iteraci├│n el algoritmo debe
recorrer el array desde el ├¡ndice i hasta 0. Tiene una complejidad en el tiempo de O(n ^ 2)

Vector de 10 elementos:
Tiempo: 0
Regresiones: 45
Iteraciones For: 9
Iteraciones totales: 54

Vector de 100 elementos:
Tiempo: 0
Regresiones: 4950
Iteraciones For: 99
Iteraciones totales: 5049

Vector de 1000 elementos:
Tiempo: 0.01
Regresiones: 499500
Iteraciones For: 999
Iteraciones totales: 500499

Vector de 10000 elementos:
Tiempo: 0.919
Regresiones: 49995000
Iteraciones For: 9999
Iteraciones totales: 50004999

Vector de 50000 elementos:
Tiempo: 27.569
Regresiones: 1249975000
Iteraciones For: 49999
Iteraciones totales: 1250024999

Vector de 80000 elementos:
Tiempo: 72.295
Regresiones: 3199960000
Iteraciones For: 79999
Iteraciones totales: 3200039999

Vector de 100000 elementos:
Tiempo: 112.565
Regresiones: 4999950000
Iteraciones For: 99999
Iteraciones totales: 5000049999

Vector de 200000 elementos:
Tiempo: 442.803
Regresiones: 19999900000
Iteraciones For: 199999
Iteraciones totales: 20000099999

Mejor caso: Los elementos del array est├ín en orden ascendente o todos son iguales, por lo tanto el algoritmo simplemente
recorre el array sin realizar ning├║n swap. Tiene una complejidad en el tiempo de O(n)

Vector de 10 elementos:
Tiempo: 0
Regresiones: 0
Iteraciones For: 9
Iteraciones totales: 9

Vector de 100 elementos:
Tiempo: 0
Regresiones: 0
Iteraciones For: 99
Iteraciones totales: 99

Vector de 1000 elementos:
Tiempo: 0
Regresiones: 0
Iteraciones For: 999
Iteraciones totales: 999

Vector de 10000 elementos:
Tiempo: 0
Regresiones: 0
Iteraciones For: 9999
Iteraciones totales: 9999

Vector de 50000 elementos:
Tiempo: 0
Regresiones: 0
Iteraciones For: 49999
Iteraciones totales: 49999

Vector de 80000 elementos:
Tiempo: 0
Regresiones: 0
Iteraciones For: 79999
Iteraciones totales: 79999

Vector de 100000 elementos:
Tiempo: 0
Regresiones: 0
Iteraciones For: 99999
Iteraciones totales: 99999

Vector de 200000 elementos:
Tiempo: 0.002
Regresiones: 0
Iteraciones For: 199999
Iteraciones totales: 199999

*/