#include <iostream>
#include "lista.hpp"

using namespace std;
using namespace Unitec;

int main(){
    ListaAlumnos lista;
    cout << "1. Creamos la lista vacia" << endl;
    vaciar(lista);
    imprimir(lista);

    cout << "2. Meter alumnos en la lista" << endl;
    Alumno a1 = {"Marco", "123", 29, 10.0};
    Alumno a2 = {"Ana", "321", 20, 5.2};
    Alumno a3 = {"Paco", "456", 26, 6.5};
    Alumno a4 = {"Luisa", "654", 18, 4.0};
    insertar(lista, a1);
    insertar(lista, a2);
    insertar_posicion(lista, a3, 0);
    insertar(lista, a4);
    imprimir(lista);

    cout << "3. Buscando a 321" << endl;
    if(buscar(lista, "321")){
        cout << "Encontrado" << endl;
    }else{
        cout << "No encontrado" << endl;
    }

    cout << "4. Eliminar a 321" << endl;
    eliminar(lista, "321");
    imprimir(lista);

    cout << "5. Leer del fichero" << endl;
    ListaAlumnos seniorAnillos;
    vaciar(seniorAnillos);
    leer_fichero(seniorAnillos, "datos.txt");
    imprimir(seniorAnillos);
    
}