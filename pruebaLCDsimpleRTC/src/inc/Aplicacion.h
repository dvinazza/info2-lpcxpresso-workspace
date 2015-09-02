/**
 \file		: Aplicacion.h
 \brief     : Header de aplicacion
 \details   :
 \author    : GOS
 \date 	    : 2014.06.08
*/

#ifndef APLICACION_H_
#define APLICACION_H_

	#include "lcd.h"
	#include "Ejemplo_RTC.h"
	#include "KitInfo2FW_RTC.h"
	#include "FW_GPIO.h"
	#include "KitInfo2_BaseBoard.h"
	#include "RegsLPC1769.h"

	void InicSysTick(void);
	void InicPLL ( void );
	void cuentoPulsos (void);
	void InicializarKit ( void );

#endif /* APLICACION_H_ */
