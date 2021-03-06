/*
Caso 2
Free Text Search

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
int prime = 10;

//Struct de una posición
struct pos {
    int linea;
    int index;
};

/*
Función que recalcula el valor hash del elemento usando rolling hash
@param string del patrón a calcular, el viejo index, el nuevo index, el viejo valor hash y la longitud del patrón
*/
long recalculateHash(char* str, int oldIndex, int newIndex, long oldHash, int patternLen) {
    long newHash = oldHash - str[oldIndex];
    newHash = newHash / prime;
    newHash += str[newIndex] * pow(prime, patternLen - 1);
    return newHash;
}

/*
Función que calcula el valor hash del patrón
@param: string del patron, ultimo indice del string
*/
long createHash(char* str, int end) {
    long hash = 0;
    for (int i = 0; i <= end; i++) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

/*
Función que verifica si ambos strings coindicen
@param: string del patron, indice de inicio, indice de fin, string del string a comparar, indice de inicio, indice de fin
@return: true si coindicen, false si no coinciden
*/
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

/*
Función que crea un nuevo objeto Pos para guardar la linea y el indice de una palabra encontrada
@param: linea en que se encuentra la palabra, indice de la palabra encontrada en la linea
*/
pos createPos(int linea, int index) {
    pos nuevo;
    nuevo.linea = linea;
    nuevo.index = index;

    return nuevo;
}

/*
Función del algoritmo Rabin-Karp. Busca una palabra en un string.
@param: char del texto en el que se busca, char del patrón a buscar, vector de posiciones, longitud m del texto,
        longitud n del patron, número de línea del txt.
@return: las apariciones de la palabra en el char text
*/
int patternSearch(char* text, char* pattern, vector<pos>& posiciones, int m, int n, int linea, int &cRecalculos) {
    // int m = sizeof(pattern) / sizeof(pattern[0]);
    // int n = sizeof(text) / sizeof(text[0]);;
    int apariciones = 0;
    long patternHash = createHash(pattern, m - 1);
    long textHash = createHash(text, m - 1);
    for (int i = 1; i <= n - m + 1; i++) {
        if (patternHash == textHash && checkEqual(text, i - 1, i + m - 2, pattern, 0, m - 1)) {
            apariciones++;
            //posiciones.push_back(createPos(linea, i - 1));
        }
        if (i < n - m + 1) {
            textHash = recalculateHash(text, i - 1, i + m - 1, textHash, m);
            cRecalculos++;
        }
    }
    return apariciones;
}

/*
Función para realizar la prueba del algoritmo de búsqueda de free text.
Abre el archivo "prueba.txt" para buscar cierta palabra en ese archivo.
@param: string de la palabra que deseamos buscar.
*/
void pruebaTextSearch(string palabra){
    ifstream archivo;
    archivo.open("prueba.txt", ios::in); //abrir archivo con el texto

    if (archivo.fail()) { //si hay errores al abrir el archivo, se muestra un mensaje y el programa termina
        cout << "No se pudo abrir el archivo. " << endl;
        exit(1);
    }

    //se construye el array de char de la palabra a buscar
    string linea = "";
    char clinea[1000], cpalabra[1000];
    strcpy_s(cpalabra, palabra.c_str());

    int apariciones = 0, cRecalculos = 0, lengthline, lengthpalabra, numline = 1;
    vector<pos> posiciones1;

    //ciclo que busca todas las apariciones de la palabra en el texto linea por linea
    double t1 = (double)clock() / CLOCKS_PER_SEC;
    while (!archivo.eof()) {
        getline(archivo, linea);
        strcpy_s(clinea, linea.c_str());
        lengthline = linea.length(); lengthpalabra = palabra.length();
        apariciones += patternSearch(clinea, cpalabra, posiciones1, lengthpalabra, lengthline, numline, cRecalculos);
        numline++;
    }
    double t2 = (double)clock() / CLOCKS_PER_SEC;

    cout << "\nApariciones de " << palabra << " en el texto: " << apariciones << endl;
    //cout << "Recalculos del valor hash: " << cRecalculos << endl;
    cout << "Tiempo: " << t2-t1 << endl;
    archivo.close();
}

int main(){
    cout << "-----------------------------------------------------------------------------" << endl;

    ifstream archivo;

    cout << "\nEjercicio 3: Free text search " << endl;
    vector<pos> posiciones1;
    string linea = "";
    string palabra = "";
    char clinea[1000];
    char cpalabra[1000];
    int apariciones = 0, lengthline, lengthpalabra, numline = 1;

    
    pruebaTextSearch("a");
    pruebaTextSearch("galaxia");
    pruebaTextSearch("cosmos");
    pruebaTextSearch("aeiou1234");
    pruebaTextSearch("La palabra cosmopolita");
    pruebaTextSearch("Actualmente  hemos  descubierto  una  manera");
    pruebaTextSearch("Narrado con habilidad, logra que las ideas científicas sean comprensibles");
    pruebaTextSearch("La época actual es una encrucijada histórica para nuestra civilización y quizás para nuestra");

    return 0;
}

/*

Resultados

Ejercicio 3: Free text search

Apariciones de a en el texto: 944284
Tiempo: 0.496

Apariciones de galaxia en el texto: 2332
Tiempo: 1.008

Apariciones de cosmos en el texto: 11
Tiempo: 0.936

Apariciones de aeiou1234 en el texto: 0
Tiempo: 1.264

Apariciones de La palabra cosmopolita en el texto: 11
Tiempo: 1.336

Apariciones de Actualmente  hemos  descubierto  una  manera en el texto: 11
Tiempo: 1.488

Apariciones de Narrado con habilidad, logra que las ideas cient├¡ficas sean comprensibles en el texto: 11
Tiempo: 1.849

Apariciones de La ├®poca actual es una encrucijada hist├│rica para nuestra civilizaci├│n y quiz├ís para nuestra en el texto: 11
Tiempo: 2.304

*/