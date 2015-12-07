/*
 * Serie.h
 *
 *  Created on: 9/9/2015
 *      Author: dvinazza
 */

#ifndef INC_SERIE_H_
#define INC_SERIE_H_

	#include "RegsLPC1769.h"


	#define TOPE 16

	//primitivas
	void pushTX(uint8_t dato);
	int popRX();

	//drivers
	void inicializarSerie (void);

	int popTX();
	void pushRX(uint8_t dato);


#endif /* INC_SERIE_H_ */
