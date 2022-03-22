/*
Caso 2

Fiorella Zelaya Coto
2021453615
*/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
#include <cstring>
#include <time.h>
#include <chrono>
#include <random>

using namespace std;

//contadores globales
//quicksort
int compCount = 0;
int iterCount = 0;
int swapCount = 0;
int arithCount = 0;
int asignCount = 0;
int pivot;

//insertionsort
int cCambios = 0;
int cRegresiones = 0;

//free text
int prime = 10;


struct pos {
    int linea;
    int index;
};

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// partition the array using last element as pivot
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

int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
 
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
        iterCount++;

        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
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
        iterCount++;

        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
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


void pruebaQuicksort(int size, int sign){
    int vector[size];
    fill(vector, size, sign);
    cout << "\nVector de " << size << " elementos: " << endl;
    swapCount = 0;
    double qt1 = (double)clock() / CLOCKS_PER_SEC;
    quickSort(vector, 0, size - 1);
    double qt2 = (double)clock() / CLOCKS_PER_SEC;
    cout << "Tiempo: " << (qt2 - qt1) << "\nSwaps: " << swapCount << "\nComparaciones: " << compCount /*<< "Tasa de crecimiento: " << ((((qt2 - qt1))-tasa)/tasa)*100*/ << endl;
}

void pruebaQuicksort_r(int size, int sign, int pivote){
    int vector[size];
    fill(vector, size, sign);
    cout << "\nVector de " << size << " elementos: " << endl;
    swapCount = 0;
    double qt1 = (double)clock() / CLOCKS_PER_SEC;
    quickSort_r(vector, 0, size - 1, pivote);
    double qt2 = (double)clock() / CLOCKS_PER_SEC;
    cout << "Tiempo: " << (qt2 - qt1) << "\nSwaps: " << swapCount << "\nComparaciones: " << compCount /*<< "Tasa de crecimiento: " << ((((qt2 - qt1))-tasa)/tasa)*100*/ << endl;
}



void insertion_sort(int vector[], int size) { // loop invariant: array[0 - j-1] is always sorted
    int j;
    for (int i = 1; i < size; i++) {
        j = i;
        while (j != 0 && vector[j] < vector[j - 1]) {
            swap(vector[j], vector[j - 1]);
            j--;
            cRegresiones++;
        }

    }    
}


void pruebaInsertionSort(int size, int sign){
    int vector[size];
    fill(vector, size, sign);
    cout << "\nVector de " << size << " elementos: " << endl;
    cRegresiones = 0;
    double it1 = (double)clock() / CLOCKS_PER_SEC;
    insertion_sort(vector, size);
    double it2 = (double)clock() / CLOCKS_PER_SEC;
    cout << "Tiempo: " << (it2 - it1) << "\nRegresiones: " << cRegresiones /*<< "Tasa de crecimiento: " << ((((qt2 - qt1))-tasa)/tasa)*100*/ << endl;
}

void add(int n, int* posiciones, int index) {
    posiciones[index] = n;
}

long recalculateHash(char* str, int oldIndex, int newIndex, long oldHash, int patternLen) {
    long newHash = oldHash - str[oldIndex];
    newHash = newHash / prime;
    newHash += str[newIndex] * pow(prime, patternLen - 1);
    return newHash;
}

long createHash(char* str, int end) {
    long hash = 0;
    for (int i = 0; i <= end; i++) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

bool checkEqual(char str1[], int start1, int end1, char str2[], int start2, int end2) {
    if (end1 - start1 != end2 - start2) {
        return false;
    }
    while (start1 <= end1 && start2 <= end2) {
        if (str1[start1] != str2[start2]) {
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}


pos createPos(vector<pos> lista, int linea, int index) {
    pos nuevo;
    nuevo.linea = linea;
    nuevo.index = index;

    return nuevo;
}


int patternSearch(char* text, char* pattern, vector<pos>& posiciones, int m, int n, int linea) {
    // int m = sizeof(pattern) / sizeof(pattern[0]);
    // int n = sizeof(text) / sizeof(text[0]);;
    int apariciones = 0;
    long patternHash = createHash(pattern, m - 1);
    long textHash = createHash(text, m - 1);
    for (int i = 1; i <= n - m + 1; i++) {
        if (patternHash == textHash && checkEqual(text, i - 1, i + m - 2, pattern, 0, m - 1)) {
            apariciones++;
            posiciones.push_back(createPos(posiciones, linea, i - 1));
        }
        if (i < n - m + 1) {
            textHash = recalculateHash(text, i - 1, i + m - 1, textHash, m);
        }
    }
    return apariciones;
}





int main() {

    const int size = 100;

    /*int vector1[size] = { 41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36, 91, 4, 2, 53, 92, 82, 21, 16, 18, 95, 47, 26, 71, 38, 69, 12, 67, 99, 35, 94, 3, 11, 22, 33, 73, 64, 41, 11, 53, 68, 47, 44, 62, 57, 37, 59, 23, 41, 29, 78, 16, 35, 90, 42, 88, 6, 40, 42, 64, 48, 46, 5, 90, 29, 70, 50, 6, 1, 93, 48, 29, 23, 84, 54, 56, 40, 66, 76, 31, 8, 44, 39, 26, 23, 37, 38, 18, 82, 29, 41 };
    int vector2[size] = { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, };
   */ vector<int> vector20 = { 40, 20, 58, 18, 10, 60, 5 , 234, 678, 102, 987, 98, 34 , 473, 8349, 193, 13, 4395, 304, 12, 45, 23, 89 };
    vector<int> vector21 = { 10000, 8000, 6000, 4000, 2000, 1000, 800, 600, 400, 200, 100, 80, 60, 40, 20,10, 8, 6, 4, 2, 1 };

    int vector1[size];
    int vector2[size];
    int vector3[size];

    double tasa = 0;

    fill(vector1, size, 0);
    fill(vector2, size, 2);
    fill(vector3, size, 1);

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
    cout << "Caso promedio: Los elementos del array están en desorden. Tiene una complejidad en el tiempo de O(n log n)" << endl;


    pruebaQuicksort_r(10, 0,1);
    pruebaQuicksort_r(100, 0,1);
    pruebaQuicksort_r(1000, 0,1);
    pruebaQuicksort_r(10000, 0,1);
    pruebaQuicksort_r(50000, 0,1);
    pruebaQuicksort_r(80000, 0,1);
    pruebaQuicksort_r(100000, 0,1);
    pruebaQuicksort_r(200000, 0,1);

    cout << "Peor caso: Los elementos del array están en ordenados ascendentemente, el pivote es un mínimo o máximo. Tiene una complejidad en el tiempo de O(n^2)" << endl;


    pruebaQuicksort_r(10, 2,1);
    pruebaQuicksort_r(100, 2,1);
    pruebaQuicksort_r(1000, 2,1);
    pruebaQuicksort_r(10000, 2,1);
    pruebaQuicksort_r(50000, 2,1);
    pruebaQuicksort_r(80000, 2,1);
    pruebaQuicksort_r(100000, 2,1);
    pruebaQuicksort_r(200000, 2,1);



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


    //-------------------------------------------------------------------------------------------------------

    ifstream archivo;
    archivo.open("prueba.txt", ios::in); //abrir archivo con el texto

    if (archivo.fail()) { //si hay errores al abrir el archivo, se muestra un mensaje y el programa termina
        cout << "No se pudo abrir el archivo. " << endl;
        exit(1);
    }



    // cout << "\nEjercicio 3: Free text search \nPalabra a buscar: " << endl;
    // vector<pos> posiciones1;
    // string linea = "";
    // string palabra = "";
    // char clinea[1000];
    // char cpalabra[1000];
    // cin >> palabra;
    // strcpy_s(cpalabra, palabra.c_str());
    // int apariciones = 0, lengthline, lengthpalabra, numline = 1;

    // int t1 = clock();
    // // Obtener línea de archivo, y almacenar contenido en "linea"
    // while (!archivo.eof()) {
    //     getline(archivo, linea);
    //     strcpy_s(clinea, linea.c_str());
    //     lengthline = linea.length(); lengthpalabra = palabra.length();
    //     apariciones += patternSearch(clinea, cpalabra, posiciones1, lengthpalabra, lengthline, numline);
    //     numline++;
    // }

    // cout << "\nApariciones de la palabra: " << apariciones << endl;
    // int t2 = clock();

    // // cout << "Posiciones en las que aparece la palabra: " << endl;
    // // for (int i = 0; i < posiciones1.size(); i++) {
    // //     cout << "Linea: " << posiciones1[i].linea << "    Index: " << posiciones1[i].index << endl;;
    // // }

    // cout << (t2 - t1) / 1000 << endl;

    return 0;
}