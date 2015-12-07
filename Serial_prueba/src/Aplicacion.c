/*
 * Aplicacion.c
 *
 *  Created on: 14/10/2013
 *      Author: marcelo
 */

#include "Aplicacion.h"

volatile uint8_t bufferTeclado;

extern uint8_t estado;

extern uint8_t enviando;

void enviarTrama(uint8_t dato) {
	pushTX('#');
	pushTX(dato);
	pushTX('$');
}

uint8_t recibirTrama (void) {
      int a;
      uint8_t tecla;

      switch (estado) {
      case ESPERANDO:
              break;

      case INICIO:
              break;

      case RECIBIENDO:
    	  break;

      case VALIDANDO:
              break;
      default:
    	  	  estado = ESPERANDO;
      }

      return NOKEY;
}
