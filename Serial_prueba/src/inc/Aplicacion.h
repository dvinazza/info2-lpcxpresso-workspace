/*
 * Aplicacion.h
 *
 *  Created on: 14/06/2013
 *      Author: Marcelo
 */

#ifndef APLICACION_H_
#define APLICACION_H_

	#include "FW_GPIO.h"
	#include "KitInfo2_BaseBoard.h"

	#define TOPE 16

	void InicializarKit ( void );
	void InicializacionSW (void);
	uint8_t upper (uint8_t c);
	uint8_t lower (uint8_t c);
	void InitUART1 (void);

	void pushTX(uint8_t dato);
	uint8_t popTX();


#endif /* APLICACION_H_ */
