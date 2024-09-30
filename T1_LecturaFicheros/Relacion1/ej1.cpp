#include <iostream>
// Biblioteca para lectura/escritura de ficheros
#include <fstream>

using namespace std;

int main(){
    // 1. Creo el flujo de salida
    ofstream f;

    // 2. Abro el fichero
    string nf = "holaMundo.txt";
    f.open(nf.c_str());

    // 3. Escribo lo que sea
    f << "Hola mundo";

    // 4. Cierro el fichero
    f.close();
}