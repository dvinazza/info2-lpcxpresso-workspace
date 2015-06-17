/*
===============================================================================
 Name        : TecladoHW.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include "myreg.h"
#include "gpio.h"

#define FILAS 4
#define COLUMNAS 3
#define ON 1
#define OFF 0
#define NO_KEY 16
#define UMBRAL_TECLA 15

uint8_t tecla;

uint8_t leerTecladoHW(void) {
	uint8_t fila, columna;

	for (fila = 0; fila < FILAS; fila++) {
		setPin(fila, ON);

		for (columna = 0; columna < COLUMNAS; columna++) {
			if (!getPin(columna)) {
				setPin(fila, OFF);
				return (fila*COLUMNAS) + columna; }
		}

		setPin(fila, OFF); }

	return NO_KEY;
}

void leerTecladoSW (void) {
	static uint8_t estadosEstables = 0;
	static uint8_t teclaAnterior = NO_KEY;
	static uint8_t teclaActual;

	teclaActual = leerTecladoHW();

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
				tecla = teclaActual;
				return; }
		}
		else { //Si cambio la tecla
			estadosEstables = 0;
			teclaAnterior = teclaActual; }
	}
}

uint8_t leerTeclado() {
	uint8_t lectura;
	if (tecla != NO_KEY) {
		lectura = tecla;
		tecla = NO_KEY;
		return lectura;
	}
	return NO_KEY;
}

void menu(void) {
	switch (leerTeclado()) {
	case NO_KEY:
		break;
	case 1:
		break;
	default:
		break;
	}
}

int main(void) {

    while(1) {
    	menu();
    }
    return 0 ;
}
