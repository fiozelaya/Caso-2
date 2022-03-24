/*
Caso 2
Quicksort

Fiorella Zelaya Coto
2021453615
*/

#include <iostream>
#include <math.h>
#include <time.h>
#include <random>

using namespace std;

//contadores globales
long long int swapCount = 0;
int partitionCount = 0;
int pivot;

/*
Función para intercambiar dos elementos mediante la utilización de
punteros.
@param: puntero a y puntero b
*/
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
Función de partición del array utilizando el último elemento
como pivot.
@param: array, indice del primer elemento, indice del último elemento
@return: índice del pivot
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot 
    int random = low + rand() % (high - low);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swapCount++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swapCount++;
    return (i + 1);
}

/*
Función de partición del array utilizando un elemento aleatorio
como pivot.
@param: array, indice del primer elemento, indice del último elemento
@return: índice del pivot que retorna la función partitioning()
*/
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
    swapCount++;
 
    return partition(arr, low, high);
}

//quicksort algorithm
//void quickSort(int arr[], int low, int high)
//{
//    if (low < high)
//    {
//        //partition the array 
//        int pivot = partition(arr, low, high);
//
//        //sort the sub arrays independently 
//        quickSort(arr, low, pivot - 1);
//        quickSort(arr, pivot + 1, high);
//    }
//}


/*
Función quicksort iterativa utilizando el ultimo elemento del array
como pivot.
@param: array, indice del primer elemento, indice del ultimo elemento
*/
void quickSort(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {

        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        partitionCount++;
        int p = partition(arr, l, h);
        

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

/*
Función quicksort iterativa utilizando un pivot random
@param: array, indice del primer elemento, indice del ultimo elemento
*/
void quickSort_r(int arr[], int l, int h, int pivote)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {

        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        partitionCount++;
        int p = partition_r(arr, l, h);
        

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

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
Función para hacer pruebas del funcionamiento del quicksort utilizando el
último elemento como pivot.
@param: tamaño del array, sign (0, 1 o 2)
*/
void pruebaQuicksort(int size, int sign){
    int vector[size];
    fill(vector, size, sign);
    cout << "\nVector de " << size << " elementos: " << endl;
    swapCount = 0;
    partitionCount = 0;
    double qt1 = (double)clock() / CLOCKS_PER_SEC;
    quickSort(vector, 0, size - 1);
    double qt2 = (double)clock() / CLOCKS_PER_SEC;
    cout << "Tiempo: " << (qt2 - qt1) << "\nSwaps: " << swapCount << "\nParticiones: " << partitionCount /*<< "Tasa de crecimiento: " << ((((qt2 - qt1))-tasa)/tasa)*100*/ << endl;
}

/*
Función para hacer pruebas del funcionamiento del quicksort utilizando un
pivot aleatorio
@param: tamaño del array, sign (0, 1 o 2)
*/
void pruebaQuicksort_r(int size, int sign, int pivote){
    int vector[size];
    fill(vector, size, sign);
    cout << "\nVector de " << size << " elementos: " << endl;
    swapCount = 0;
    partitionCount = 0;
    double qt1 = (double)clock() / CLOCKS_PER_SEC;
    quickSort_r(vector, 0, size - 1, pivote);
    double qt2 = (double)clock() / CLOCKS_PER_SEC;
    cout << "Tiempo: " << (qt2 - qt1) << "\nSwaps: " << swapCount << "\nParticiones: " << partitionCount /*<< "Tasa de crecimiento: " << ((((qt2 - qt1))-tasa)/tasa)*100*/ << endl;
}

int main() {
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Ejercicio 1: Quicksort" << endl;
    cout << "Pivote fijo: último elemento" << endl;
    cout << "Caso promedio: Los elementos del array están en desorden. Tiene una complejidad en el tiempo de O(n log n)" << endl;


    pruebaQuicksort(10, 0);
    pruebaQuicksort(100, 0);
    pruebaQuicksort(1000, 0);
    pruebaQuicksort(10000, 0);
    pruebaQuicksort(50000, 0);
    pruebaQuicksort(80000, 0);
    pruebaQuicksort(100000, 0);
    pruebaQuicksort(200000, 0);

    cout << "Peor caso: Los elementos del array están en ordenados ascendentemente, el pivote es un mínimo o máximo. Tiene una complejidad en el tiempo de O(n^2)" << endl;


    pruebaQuicksort(10, 2);
    pruebaQuicksort(100, 2);
    pruebaQuicksort(1000, 2);
    pruebaQuicksort(10000, 2);
    pruebaQuicksort(50000, 2);
    pruebaQuicksort(80000, 2);
    pruebaQuicksort(100000, 2);
    pruebaQuicksort(200000, 2);

    cout << "\nPivote aleatorio" << endl;
    cout << "\nCaso promedio: Los elementos del array están en desorden. Tiene una complejidad en el tiempo de O(n log n)" << endl;


    pruebaQuicksort_r(10, 0,1);
    pruebaQuicksort_r(100, 0,1);
    pruebaQuicksort_r(1000, 0,1);
    pruebaQuicksort_r(10000, 0,1);
    pruebaQuicksort_r(50000, 0,1);
    pruebaQuicksort_r(80000, 0,1);
    pruebaQuicksort_r(100000, 0,1);
    pruebaQuicksort_r(200000, 0,1);

    cout << "\nLos elementos del array est├ín en ordenados ascendentemente. Tiene una complejidad en el tiempo de O(n log n)" << endl;


    pruebaQuicksort_r(10, 2,1);
    pruebaQuicksort_r(100, 2,1);
    pruebaQuicksort_r(1000, 2,1);
    pruebaQuicksort_r(10000, 2,1);
    pruebaQuicksort_r(50000, 2,1);
    pruebaQuicksort_r(80000, 2,1);
    pruebaQuicksort_r(100000, 2,1);
    pruebaQuicksort_r(200000, 2,1);

    return 0;

}

/*

Resultados:

Caso promedio: Los elementos del array est├ín en desorden. Tiene una complejidad en el tiempo de O(n log n)

Vector de 10 elementos:
Tiempo: 0
Swaps: 15
Particiones: 6

Vector de 100 elementos:
Tiempo: 0
Swaps: 372
Particiones: 64

Vector de 1000 elementos:
Tiempo: 0
Swaps: 6091
Particiones: 692

Vector de 10000 elementos:
Tiempo: 0.005
Swaps: 102496
Particiones: 6793

Vector de 50000 elementos:
Tiempo: 0.02
Swaps: 534334
Particiones: 34515

Vector de 80000 elementos:
Tiempo: 0.034
Swaps: 950672
Particiones: 57647

Vector de 100000 elementos:
Tiempo: 0.042
Swaps: 1142491
Particiones: 74475

Vector de 200000 elementos:
Tiempo: 0.086
Swaps: 2675282
Particiones: 167935
Peor caso: Los elementos del array est├ín en ordenados ascendentemente, el pivote es un m├¡nimo o m├íximo. Tiene una complejidad en el tiempo de O(n^2)

Vector de 10 elementos:
Tiempo: 0
Swaps: 29
Particiones: 9

Vector de 100 elementos:
Tiempo: 0
Swaps: 2549
Particiones: 99

Vector de 1000 elementos:
Tiempo: 0.004
Swaps: 250499
Particiones: 999

Vector de 10000 elementos:
Tiempo: 0.579
Swaps: 25004999
Particiones: 9999

Vector de 50000 elementos:
Tiempo: 15.821
Swaps: 625024999
Particiones: 49999

Vector de 80000 elementos:
Tiempo: 43.439
Swaps: 1600039999
Particiones: 79999

Vector de 100000 elementos:
Tiempo: 65.817
Swaps: 2500049999
Particiones: 99999

Vector de 200000 elementos:
Tiempo: 261.84
Swaps: 10000099999
Particiones: 199999

Pivote aleatorio

Caso promedio: Los elementos del array est├ín en desorden. Tiene una complejidad en el tiempo de O(n log n)

Vector de 10 elementos:
Tiempo: 0
Swaps: 21
Particiones: 6

Vector de 100 elementos:
Tiempo: 0
Swaps: 469
Particiones: 67

Vector de 1000 elementos:
Tiempo: 0.001
Swaps: 6808
Particiones: 686

Vector de 10000 elementos:
Tiempo: 0.004
Swaps: 94135
Particiones: 6787

Vector de 50000 elementos:
Tiempo: 0.023
Swaps: 584977
Particiones: 34512

Vector de 80000 elementos:
Tiempo: 0.037
Swaps: 1058575
Particiones: 57645

Vector de 100000 elementos:
Tiempo: 0.047
Swaps: 1239973
Particiones: 74395

Vector de 200000 elementos:
Tiempo: 0.105
Swaps: 3193494
Particiones: 167971

Los elementos del array est├ín en ordenados ascendentemente. Tiene una complejidad en el tiempo de O(n log n)

Vector de 10 elementos:
Tiempo: 0
Swaps: 23
Particiones: 6

Vector de 100 elementos:
Tiempo: 0
Swaps: 560
Particiones: 64

Vector de 1000 elementos:
Tiempo: 0
Swaps: 7053
Particiones: 632

Vector de 10000 elementos:
Tiempo: 0.003
Swaps: 90092
Particiones: 6402

Vector de 50000 elementos:
Tiempo: 0.02
Swaps: 611290
Particiones: 32143

Vector de 80000 elementos:
Tiempo: 0.03
Swaps: 994363
Particiones: 51298

Vector de 100000 elementos:
Tiempo: 0.043
Swaps: 1358116
Particiones: 64158

Vector de 200000 elementos:
Tiempo: 0.104
Swaps: 3411267
Particiones: 128216


*/