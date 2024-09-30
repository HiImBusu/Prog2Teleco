#include <iostream>
// Biblioteca para lectura/escritura de ficheros
#include <fstream>

using namespace std;

int main(){
    // 1. Creo el flujo de salida
    ifstream f;

    // 2. Abro el fichero
    string nf = "holaMundo.txt";
    f.open(nf.c_str());

    // 3. Leo lo que sea+
    string cadena;
    // f >> cadena;
    getline(f, cadena, '\n');
    cout << cadena << endl;

    // 4. Cierro el fichero
    f.close();
}