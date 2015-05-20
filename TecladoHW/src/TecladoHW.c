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

uint8_t leerTeclado(void) {
	uint8_t fila, columna;

	for (fila = 0; fila < FILAS; fila++) {
		setPin(fila, ON);

		for (columna = 0; columna < COLUMNAS; columna++) {
			if (!getPin(columna)) {
				setPin(fila, OFF);
				return fila+columna;
			}
		}

		setPin(fila, OFF);
	}

	return NO_KEY;
}

int main(void) {

    while(1) {

    }
    return 0 ;
}
