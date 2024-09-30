/*
 * practica.h
 *
 *  Created on: 24 jul 2024
 *      Author: usuario
 */

#ifndef PRACTICA_H
#define PRACTICA_H

#include <string>

namespace practica_presencial{

const unsigned NRESPUESTAS_TEST = 3;
const unsigned NMAX_TEST = 100;

struct Pregunta {
    std::string texto;
    std::string respuestas[NRESPUESTAS_TEST];
    unsigned respuestaCorrecta; // Índice de la respuesta correcta (0, 1, 2)
};

struct Test {
    Pregunta preguntas[NMAX_TEST];
    unsigned numPreguntas;
};

struct Respuestas {
    std::string nombre;
    unsigned numPreguntas;
    unsigned respuestas[NMAX_TEST]; // Índices de las respuestas dadas (0, 1, 2)
};

Test leerTestDesdeFichero(const std::string& nombreFichero, bool& ok );

unsigned calcularPuntuacion(const Test& test, const Respuestas& respuestas);
}

#endif // PRACTICA_H
