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
	#include "FW_initSYSTICK.h"

	#include "Teclado.h"
	#include "Serie.h"

	#include <string.h>

	void InicializarKit ( void );
	void InicializacionSW (void);
	uint8_t upper (uint8_t c);
	uint8_t lower (uint8_t c);
	void InitUART1 (void);

	void enviarTrama(uint8_t dato);
	uint8_t recibirTrama(void);

	#define ESPERANDO 0
	#define INICIO 1
	#define RECIBIENDO 2
	#define VALIDANDO 3

	#define NOKEY 0
	#define ERROR 255

#endif /* APLICACION_H_ */
