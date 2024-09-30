/*
 * practica.cpp
 *
 *  Created on: 24 jul 2024
 *      Author: usuario
 */
#include "practica.h"
#include <iostream>
#include <fstream>

using namespace std;


namespace practica_presencial{




Test leerTestDesdeFichero(const std::string& nombreFichero, bool& ok ) {
	// 0. Creamos un "test" vacio
	Test test;

	test.numPreguntas = 0;

	// 1. Creamos el manejador del fichero (ENTRADA)
	ifstream f;

	// 2. Creamos una variable auxiliar donde vamos a ir guardando cada "item"
	Pregunta p;

	// 3. Abrimos el fichero
	f.open(nombreFichero.c_str());

	// 4. Comprobamos si lo hemos podido abrir
	ok = !f.fail();

	if(ok){
		// 5. Si todo ha ido bien, vamos leyendo su contenido
		// LECTURA ADELANTADA PARA DETECTAR FIN DEL FICHERO!!!!!
		getline(f, p.texto, '\n'); // leemos la pregunta
		while(!f.eof()){
			// leemos tantas posibles respuestas como me diga el fichero .hpp (3 respuestas)
			for(unsigned i = 0; i < NRESPUESTAS_TEST; i++){
				getline(f, p.respuestas[i], '\n'); // leemos la respuesta "i"
			}
			// Leemos el indice de la respuesta correcta
			f >> p.respuestaCorrecta;

			// Ignoramos el '\n' que esta detras del numero para que no entre en conflicto al intentar leer
			// la siguiente pregunta
			f.ignore(); 

			// Guardamos la pregunta ya rellena en nuestro "Test", copiando el registro auxiliar que hemos rellenado
			test.preguntas[test.numPreguntas] = p;
			test.numPreguntas++;

			getline(f, p.texto, '\n'); // leemos la siguiente pregunta (sobreescribiendo el registro auxiliar)
		}

		// 6. Cerramos el manejador
		f.close();
	}
	return test;
}


unsigned calcularPuntuacion(const Test& test, const Respuestas& respuestas) {
	int puntuacion = 0;
	
	// Recorremos todas las preguntas de nuestro test
	for(unsigned i = 0; i < test.numPreguntas; i++){
		// Para cada pregunta comprobamos si acerto con su respuesta
		if(test.preguntas[i].respuestaCorrecta == respuestas.respuestas[i]){
			puntuacion++;
		}
	}
	return puntuacion;
}

}
