
// 1. Incluimos el modulo que vamos a implementar
#include "modulo.hpp"

// OJO! Necesitaremos la biblioteca "iostream" para poder hacer lecturas/escrituras por pantalla
#include <iostream>

// 2. Como vamos a implementar las funciones que estan dentro del fichero "modulo.hpp" y dichas funciones estan encapsuladas DENTRO del modulo "Unitec", tendremos que volver a abrir el
// espacio de nombres para seguir añadiendo cosas
namespace Unitec{
    // Leemos los datos de la persona por consola y devolvemos un TPersona relleno
    void leerPersona(TPersona& p){
        // OJO! Las funciones de Lectura/Escritura tambien estan en el espacio de nombres estandar, por lo que o tendremos que especificarlo cada vez que utilizemos una operacion de lectura/escritura
        // o especificamos que a lo largo de todo el fichero queremos que consulte por defecto el espacio de nombres estantar
        // 1. std::cout << ".....";
        // 2. using namespace std;
        //    int main(){
        //      cout << "....."
        // }   
        std::cout << "Nombre: ";
        getline(std::cin, p.nombre, '\n');
        std::cout << "Edad: ";
        std::cin >> p.edad;
    }

    // Mostramos los datos de la persona por pantalla
    void imprimirPersona(const TPersona& p){
        std::cout << "(" << p.nombre << ", " << p.edad << ")" << std::endl;
    }

    // Funcion que suma dos numeros enteros
    int suma(int a, int b){
        return a + b;
    }
}