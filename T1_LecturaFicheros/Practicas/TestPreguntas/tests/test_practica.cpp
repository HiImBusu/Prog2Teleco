/*
 * test_practica.cpp
 *
 *  Created on: 24 jul 2024
 *      Author: usuario
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../practica.h"
#include <fstream>

using namespace practica_presencial;

TEST_CASE("Leer test desde fichero", "[leerTestDesdeFichero]") {
    bool ok;
    Test test;

    SECTION("Fichero no existe") {
        test = leerTestDesdeFichero("data/fichero_inexistente.txt", ok);
        REQUIRE(ok == false);
        REQUIRE(test.numPreguntas == 0);
    }

    SECTION("Fichero vacío") {
        std::ofstream ofs("data/test_vacio.txt");
        ofs.close();
        test = leerTestDesdeFichero("data/test_vacio.txt", ok);
        REQUIRE(ok == true);
        REQUIRE(test.numPreguntas == 0);
    }

    SECTION("Fichero con un test válido") {
        std::ofstream ofs("data/test_valido.txt");
        ofs << "¿Cuál es la capital de Francia?\n";
        ofs << "Londres\n";
        ofs << "París\n";
        ofs << "Berlín\n";
        ofs << "1\n";  // Respuesta correcta: París

        ofs << "¿Cuál es 2+2?\n";
        ofs << "3\n";
        ofs << "4\n";
        ofs << "5\n";
        ofs << "1\n";  // Respuesta correcta: 4
        ofs.close();

        test = leerTestDesdeFichero("data/test_valido.txt", ok);
        REQUIRE(ok == true);
        REQUIRE(test.numPreguntas == 2);
        REQUIRE(test.preguntas[0].texto == "¿Cuál es la capital de Francia?");
        REQUIRE(test.preguntas[0].respuestas[0] == "Londres");
        REQUIRE(test.preguntas[0].respuestas[1] == "París");
        REQUIRE(test.preguntas[0].respuestas[2] == "Berlín");
        REQUIRE(test.preguntas[0].respuestaCorrecta == 1);

        REQUIRE(test.preguntas[1].texto == "¿Cuál es 2+2?");
        REQUIRE(test.preguntas[1].respuestas[0] == "3");
        REQUIRE(test.preguntas[1].respuestas[1] == "4");
        REQUIRE(test.preguntas[1].respuestas[2] == "5");
        REQUIRE(test.preguntas[1].respuestaCorrecta == 1);
    }
}

TEST_CASE("Calcular puntuación", "[calcularPuntuacion]") {
    Test test;
    Respuestas respuestas;

    test.numPreguntas = 2;
    test.preguntas[0] = {"¿Cuál es la capital de Francia?", {"Londres", "París", "Berlín"}, 1};
    test.preguntas[1] = {"¿Cuál es 2+2?", {"3", "4", "5"}, 1};

    respuestas.nombre = "Estudiante";
    respuestas.numPreguntas = 2;

    SECTION("Todas las respuestas correctas") {
        respuestas.respuestas[0] = 1;
        respuestas.respuestas[1] = 1;
        unsigned puntuacion = calcularPuntuacion(test, respuestas);
        REQUIRE(puntuacion == 2);
    }

    SECTION("Todas las respuestas incorrectas") {
        respuestas.respuestas[0] = 0;
        respuestas.respuestas[1] = 0;
        unsigned puntuacion = calcularPuntuacion(test, respuestas);
        REQUIRE(puntuacion == 0);
    }

    SECTION("Algunas respuestas correctas y otras incorrectas") {
        respuestas.respuestas[0] = 1;
        respuestas.respuestas[1] = 0;
        unsigned puntuacion = calcularPuntuacion(test, respuestas);
        REQUIRE(puntuacion == 1);
    }
}
