/*
 * Teclado.h
 *
 *  Created on: 9/9/2015
 *      Author: dvinazza
 */

#ifndef INC_TECLADO_H_
#define INC_TECLADO_H_

	#define     SW1_OFF     GetPIN(KEY0,ACTIVO_BAJO)
    #define     SW4_OFF     GetPIN(KEY1,ACTIVO_BAJO)
    #define     SW7_OFF     GetPIN(KEY2,ACTIVO_BAJO)
    #define     SW10_OFF    GetPIN(KEY3_RC,ACTIVO_BAJO)
    #define     SW13_OFF    GetPIN(KEY4_RC,ACTIVO_BAJO)

	#define 	CANT_REBOTES	10 //valor empírico
	#define		REPOSO			0
	#define		DETECCION		1
	#define		CHEQUEO			2
	#define		EMERGENCIA		CHEQUEO

	void DriverTeclado(void);
	uint8_t TecladoHW (void);
	void TecladoSW (uint8_t codAct);

#endif /* INC_TECLADO_H_ */
