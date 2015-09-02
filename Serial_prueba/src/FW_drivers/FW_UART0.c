/*
 * FW_UART.c
 *
 *  Created on: 14/10/2013
 *      Author: marcelo
 */

#include "Aplicacion.h"

extern uint8_t buffer[TOPE];
extern uint8_t inx_out;
extern uint8_t inx_in;
extern uint8_t enviando;

void UART1_IRQHandler (void) {

	uint8_t iir, aux;

	do {
		iir = U1IIR; //IIR es reset por HW, una vez que lo lei se resetea.

		if ( iir & 0x02 ) { //envio
			if (inx_in != inx_out) {
				//Cuando saque el último...y los índices queden empatados...hay que cortar la RX
				enviando = 1;	 		//aviso que estoy enviando
				U1THR = popRX();
			}
			else {
				enviando = 0;  //aviso que terminé de transmitir.
			}
		}
	}
	while( ! ( iir & 0x01 ) );
	/*
	 * me fijo si cuando entre a la ISR habia otra
	 * int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
	 * espacio temporal lleguan dos interrupciones a la vez) */
}
