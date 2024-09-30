#include <iostream>
// 1. Añadimos el modulo
#include "modulo.hpp" // OJO! Incluimos el .hpp no el .cpp

using namespace std;
// 2. Decimos que usaremos tambien el espacio de nombres definido en el modulo
// (para no tener que especificarlo cada vez que usemos algo de ese espacio de nombres)
using namespace Unitec;

int main(){
    // Para compilar tendremos dos opciones
    // 1. Nos dan un archivo "makefile" ya configurado y solo tendremos que hacer uso de el
    // make main
    
    // 2. Lo hacemos nosotros a mano
    // Generamos el compilado del fichero con el modulo
    // g++ -c -o .\modulo.o .\modulo.cpp -Wall -Werror -Wextra
    // Generamos el compilado del fichero con el main
    // g++ -c -o .\main.o .\main.cpp -Wall -Werror -Wextra
    // Enganchamos los compilados
    // g++ -o main .\modulo.o .\main.o -Wall -Werror -Wextra


    // Usamos funciones sencillas "suma"
    cout << "Suma: " << suma(2, 3) << endl;

    // Usamos estructuras/funciones mas complejas
    TPersona p;
    leerPersona(p);
    imprimirPersona(p);
}