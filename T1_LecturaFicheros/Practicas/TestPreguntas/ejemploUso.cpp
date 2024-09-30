/*
 * ejemploUso.cpp
 *
 *  Created on: 24 jul 2024
 *      Author: usuario
 */



#include "practica.h"
#include <iostream>

using namespace std;
using namespace practica_presencial;

Respuestas leerRespuestasDesdeTeclado(const Test& test) {
	Respuestas respuestas;
	std::cout << "Nombre del alumno: ";
	std::getline(std::cin, respuestas.nombre);

	for (unsigned i = 0; i < test.numPreguntas; i++) {
		std::cout << "Pregunta " << i + 1 << ": " << test.preguntas[i].texto << "\n";
		for (unsigned j = 0; j < NRESPUESTAS_TEST; j++) {
			std::cout << j << ": " << test.preguntas[i].respuestas[j] << "\n";
		}
		std::cout << "Respuesta: ";
		std::cin >> respuestas.respuestas[i];
	}

	return respuestas;
}

int main() {
	bool ok;

    Test test = leerTestDesdeFichero("test_data.txt", ok);

    if (!ok){
    	cout << "Fichero de test incorrecto" << endl;
    	return -1;
    }

    Respuestas respuestas = leerRespuestasDesdeTeclado( test );

    cout << "Puntuación obtenida  " << calcularPuntuacion(test, respuestas ) << endl;

    return 0;
}
