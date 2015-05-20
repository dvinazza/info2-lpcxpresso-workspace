/*
===============================================================================
Infotronic.h
===============================================================================
*/
#ifndef KIT_INFO2_H_
#define KIT_INFO2_H_

	#include "Oscilador.h"
	#include "RegsLPC1769.h"

	// TPL2-A-FW-INIC.c
	void Inicializar ( void );
	void InitPLL ( void );
	void InitGPIOs ( void );
	void InitEINTx( void );

	// TPL2-A-FW-CONFIG.c
	void SetPINSEL ( uint8_t , uint8_t , uint8_t );
	void SetMODE ( uint8_t , uint8_t , uint8_t );

	// TPL2-A-FW-GPIO.c
	void SetDIR( uint8_t ,uint8_t ,uint8_t );
	void SetPIN( uint8_t , uint8_t , uint8_t );
	uint8_t GetPIN( uint8_t , uint8_t , uint8_t );

#endif /* KIT_INFO2_H_ */
