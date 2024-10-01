#ifndef __LISTA__H
#define __LISTA__H

/**
 * Queremos implementar una lista INCOMPLETA como lo que teniamos en Programacion 1.
 * Definiremos una lista incompleta para manejar la informacion de los alumnos de la clase
 * Informacion del alumno a guardar:
 * - Nombre completo
 * - DNI
 * - Edad
 * - Nota final (valor real)
 * Para ello tendremos que:
 * - Definir los tipos necesarios para poder guardar la informacion de la lista incompleta de alumnos
 * - Definir metodos para poder:
 *      - Leer los datos de un alumno por pantalla
 *      - Imprimir los datos de un alumno por pantalla
 *      - Insertar (por el final) a un alumno en nuestra lista de alumnos
*       - Mostrar todos los alumnos de la lista
 *      - Buscar a un alumno en nuestra lista de alumnos
 *      - Buscar la posicion donde se encuentra un alumno en la lista
 *      - Recorrer la lista de alumnos buscando los que cumplan cierto criterio. Por ejemplo, buscar cuantos tienen mas de x años
 *      - Insertar al alumno en la lista EN UNA POSICION DETERMINADA
 *      - Eliminar a un alumno de nuestra lista
 *      - Leer los datos de los alumnos de un fichero
 *      - Generar un fichero (con el mismo formato que el apartado anterior) con los datos de los alumnos almacenados en la lista
 */

#include <array>

namespace Unitec{
    // Definicion de tipos
    typedef struct{
        std::string nombre;
        std::string dni;
        int edad;
        float nota;
    }Alumno;
    const int MAX_ALUMNOS = 100;
    typedef std::array<Alumno, MAX_ALUMNOS> ArrayAlumnos;
    typedef struct{
        ArrayAlumnos alumnos;
        int n_alumnos;
    }ListaAlumnos;

    // Definicion de metodos
    // Leer los datos de un alumno por pantalla
    void leer_alumno_consola(Alumno& al);
    // Imprimir los datos de un alumno por pantalla
    void imprimir_alumno_consola(const Alumno& al);
    // Vaciar la lista de alumnos
    void vaciar(ListaAlumnos& lista);
    // Insertar (por el final) a un alumno en nuestra lista de alumnos
    void insertar(ListaAlumnos& lista, const Alumno& al);
    // Mostrar todos los alumnos de la lista
    void imprimir(const ListaAlumnos& lista);
    // Buscar a un alumno en nuestra lista de alumnos
    bool buscar(const ListaAlumnos& lista, const std::string& dni);
    // Buscar la posicion donde se encuentra un alumno en la lista
    int buscar_posicion(const ListaAlumnos& lista, const std::string& dni);
    // Recorrer la lista de alumnos buscando los que cumplan cierto criterio. Por ejemplo, buscar cuantos tienen mas de x años
    int alumnos_mayores(const ListaAlumnos& lista, int edad_minima);
    // Recorrer la lista, calcular la media de las notas
    int media_notas(const ListaAlumnos& lista);
    // Insertar al alumno en la lista EN UNA POSICION DETERMINADA
    void insertar_posicion(ListaAlumnos& lista, const Alumno& al, int indice);
    // Eliminar a un alumno de nuestra lista
    void eliminar(ListaAlumnos& lista, const std::string& dni);
    // Leer los datos de los alumnos de un fichero
    void leer_fichero(ListaAlumnos& lista, const std::string nombre_fichero);
    // Generar un fichero (con el mismo formato que el apartado anterior) con los datos de los alumnos almacenados en la lista
    void escribir_fichero(const ListaAlumnos& lista, const std::string nombre_fichero);
}

#endif