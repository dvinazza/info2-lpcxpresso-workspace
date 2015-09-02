/*
 * Display_7_seg.c
 *
 *  Created on: 04/06/2014
 *      Author: Hernan
 */

#include "TPL3.H"

extern uint8_t bufferValor; //buffer en el main

extern uint8_t bufferSegmentos[CANTIDAD_SEGMENTOS];

uint8_t auxDisplay[CANTIDAD_DIGITOS];

unsigned char Tabla_Digitos_BCD_7seg[] = { 0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7C, 0x07, 0x7f, 0x67};

void actualizarDisplay() {
	int digito;

	for (digito = 0; digito < CANTIDAD_DIGITOS; digito++) {
		auxDisplay[digito] = 0; 	}

	for (digito = 0; digito < CANTIDAD_DIGITOS; digito++) {
		auxDisplay[digito] = Tabla_Digitos_BCD_7seg[bufferValor % 10];
		bufferValor = bufferValor/10; 	}

	//invierto el orden de los digitos
	for (digito = 0; digito < CANTIDAD_DIGITOS; digito++) {
		bufferSegmentos[digito] = auxDisplay[digito];
	}
}
