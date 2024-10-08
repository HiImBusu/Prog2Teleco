#include "lista.hpp"
#include <iostream>
#include <fstream>

using namespace std;

namespace Unitec{
    // Leer los datos de un alumno por pantalla
    void leer_alumno_consola(Alumno& al){
        cout << "Nombre: ";
        getline(cin, al.nombre);
        cout << "Dni: ";
        cin >> al.dni;
        cout << "Edad: ";
        cin >> al.edad;
        cout << "Nota final: ";
        cin >> al.nota;
        cin.ignore(); // Quitar el \n finall
    }
    // Imprimir los datos de un alumno por pantalla
    void imprimir_alumno_consola(const Alumno& al){
        // (nombre; dni; edad; nota)
        cout << "(" << al.nombre << "; " << al.dni << "; " << al.edad << "; " << al.nota << ")" << endl;
    }
    // Vaciar la lista de alumnos
    void vaciar(ListaAlumnos& lista){
        lista.n_alumnos = 0;
    }
    // Insertar (por el final) a un alumno en nuestra lista de alumnos
    void insertar(ListaAlumnos& lista, const Alumno& al){
        // [a1, a2, a3, ?, ?, ......]
        // a4
        // [a1, a2, a3, a4]
        if(lista.n_alumnos < MAX_ALUMNOS){
            lista.alumnos[lista.n_alumnos] = al;
            lista.n_alumnos++;
        }else{
            cout << "Error. Lista llena!";
        }
    }
    // Mostrar todos los alumnos de la lista
    void imprimir(const ListaAlumnos& lista){
        if(lista.n_alumnos == 0){
            cout << "Lista vacia!";
        }else{
            for(int i = 0; i < lista.n_alumnos; i++){
                imprimir_alumno_consola(lista.alumnos[i]);
            }
        }
    }
    // Buscar a un alumno en nuestra lista de alumnos
    bool buscar(const ListaAlumnos& lista, const std::string& dni){
        bool encontrado = false;
        int i = 0;
        while(i < lista.n_alumnos && !encontrado){
            if(dni == lista.alumnos[i].dni){
                encontrado = true;
            }
            i++;
        }
        return encontrado;
    }

    // Buscar la posicion donde se encuentra un alumno en la lista
    int buscar_posicion(const ListaAlumnos& lista, const std::string& dni){
        bool encontrado = false;
        int indice = -1;
        int i = 0;
        while(i < lista.n_alumnos && !encontrado){
            if(dni == lista.alumnos[i].dni){
                encontrado = true;
                indice = i;
            }
            i++;
        }
        return indice;
    }
    // Recorrer la lista de alumnos buscando los que cumplan cierto criterio. Por ejemplo, buscar cuantos tienen mas de x años
    int alumnos_mayores(const ListaAlumnos& lista, int edad_minima){
        int contador = 0;
        for(int i = 0; i < lista.n_alumnos; i++){
            if(lista.alumnos[i].edad >= edad_minima){
                contador++;
            }
        }
        return contador;
    }
    // Recorrer la lista, calcular la media de las notas
    float media_notas(const ListaAlumnos& lista){
        float suma = 0.0;
        for(int i = 0; i < lista.n_alumnos; i++){
            suma += lista.alumnos[i].nota;
        }   
        return suma/lista.n_alumnos;
    }
    // Insertar al alumno en la lista EN UNA POSICION DETERMINADA
    void insertar_posicion(ListaAlumnos& lista, const Alumno& al, int indice){
        // [a1, a2, a3, a4, a5]
        // a6
        // 1
        // // [a1, a6, a2, a3, a4, a5]

        // 1. Abrir hueco en la posicion "indice"
        // [a1, a2, a3, a4, a5]
        // [00, 01, 02, 03, 04, 05, 06, .....] indices
        // [a1, a2, a2, a3, a4, a5]
        for(int i = lista.n_alumnos - 1; i >= indice; i--){
            lista.alumnos[i + 1] = lista.alumnos[i];
        }
        // Equivalente a lo anterior
        // for(int i = lista.n_alumnos; i >= indice + 1; i--){
        //     lista.alumnos[i] = lista.alumnos[i - 1];
        // }
        lista.n_alumnos++;

        // 2. Una vez abierto el hueco, meto mi elemento en dicha posicion 
        lista.alumnos[indice] = al;
    }
    // Eliminar a un alumno de nuestra lista
    void eliminar(ListaAlumnos& lista, const std::string& dni){
        // [a1, a2, a3, a4, a5]
        // a2
        // [a1, a3, a3, a4, a5]
        // [a1, a3, a4, a4, a5]
        // [a1, a3, a4, a5, a5]
        // [a1, a3, a4, a5]
        // [a1, a3, a4, a5]
        // 1. Buscar al alumno
        int indice = buscar_posicion(lista, dni);

        if(indice == -1){
            cout << "Error. No puedo borrar un alumno que no existe!!!";
        }else{
            // cout << "Borrando el que esta en la posicion " << indice << endl;
            // 2. Cerrar hueco en la posicion "indice"
            for(int i = indice + 1; i <= lista.n_alumnos - 1; i++){
                // cout << "Muevo a " << lista.alumnos[i].nombre << " a la posicion " << i - 1 << endl;
                lista.alumnos[i - 1] = lista.alumnos[i];
                // imprimir(lista);
            }
            // 3. Disminuir el numero de alumnos de la lista
            lista.n_alumnos--;
        }

    }
    // Leer los datos de los alumnos de un fichero
    void leer_fichero(ListaAlumnos& lista, const std::string nombre_fichero){
        // Aragorn II Elessar; 12345; 87; 10
        ifstream f;

        f.open(nombre_fichero.c_str());

        Alumno al;
        if(f.fail()){
            cout << "Error" << endl;
        }else{
            getline(f, al.nombre, ';');
            while(!f.eof()){
                f >> al.dni;
                f >> al.edad;
                f >> al.nota;
                f.ignore();

                insertar(lista, al);
                getline(f, al.nombre, ';');
            }
        }

    }
    // Generar un fichero (con el mismo formato que el apartado anterior) con los datos de los alumnos almacenados en la lista
    void escribir_fichero(const ListaAlumnos& lista, const std::string nombre_fichero){
        if(lista.n_alumnos == 0 && nombre_fichero == "kk"){
            cout << "hola";
        }
    }
}