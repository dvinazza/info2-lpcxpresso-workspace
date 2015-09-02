/*
 * Aplicacion.c
 *
 *  Created on: 14/10/2013
 *      Author: marcelo
 */

#include "Aplicacion.h"
#include <string.h>

extern uint8_t buffer[TOPE];
extern uint8_t inx_out;
extern uint8_t inx_in;
extern uint8_t enviando;

uint8_t upper (uint8_t c)
{
	if ( c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';

	return c;
}

uint8_t lower (uint8_t c)
{
	if ( c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';

	return c;
}

void enviar_datos(uint8_t dato) {
	pushTX('#');
	pushTX(dato);
	pushTX('$');
}

void pushTX(uint8_t dato) {
	buffer[inx_in] = dato;
	inx_in++;
	inx_in = inx_in % TOPE;

	if ( enviando ==  0 ) {
		enviando = 1;
		U1THR = buffer[inx_out];
	}
}

uint8_t popTX() {
	int aux = -1;
	if ( inx_in != inx_out ) {
		aux = buffer[inx_out];
		inx_out++;
		inx_out = inx_out % TOPE;
	}
	return aux;
}
