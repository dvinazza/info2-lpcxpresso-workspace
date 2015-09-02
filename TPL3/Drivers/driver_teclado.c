/*
 *  Created on: 24/6/2015
 *      Author: dvinazza
 */

#include "TPL3.H"

// puertos y pines de los pulsadores
uint8_t auxBotonesPuertos[] = { 3, 1, 1, 1 }; //
uint8_t auxBotonesPines[] = { 26, 18, 21, 24};

uint8_t bufferTecla; //ejercicio 2, punto 2

uint8_t lecturaTecladoHW(void) {
	// Lectura de los pulsadores
	uint8_t aux;
	for (aux = 0; aux < CANTIDAD_TECLAS; aux++) {
		if ( GetPIN(auxBotonesPuertos[aux], auxBotonesPines[aux], 0) ) {
			return aux; }
	}

	return NO_KEY;
}

void lecturaTecladoSW(void) {
	// Eliminación del rebote de los pulsadores

	static uint8_t estadosEstables = 0;
	static uint8_t teclaAnterior = NO_KEY;
	static uint8_t teclaActual;

	teclaActual = lecturaTecladoHW();

	if (teclaActual == NO_KEY) {
		estadosEstables = 0;
		teclaAnterior = NO_KEY;
		return; }

	if (!estadosEstables) { //La primera vez
		teclaAnterior = teclaActual;
		estadosEstables = 1;
		return; }

	else { //Las siguientes
		if (teclaAnterior == teclaActual) { //Si sigue presionada
			estadosEstables++;

			if (estadosEstables == UMBRAL_TECLA) {
				bufferTecla = teclaActual;
				return; }
		}
		else { //Si cambio la tecla
			estadosEstables = 0;
			teclaAnterior = teclaActual; }
	}

}
