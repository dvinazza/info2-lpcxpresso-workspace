/*
===============================================================================
 TPL2 - Systic Timer
===============================================================================
*/
#ifndef KIT_INFO2_H_
#define KIT_INFO2_H_

#include "Oscilador.h"
#include "RegsLPC1769.h"

// TPL2-B-INIC.c
void Inicializar ( void );
void InitPLL ( void );
void InitGPIOs ( void );
void InicSysTick ( void );

// TPL2-B-FW-CONFIG.c
void SetPINSEL ( uint8_t , uint8_t , uint8_t );
void SetMODE ( uint8_t , uint8_t , uint8_t );

// TPL2-B-FW-GPIO.c
void SetDIR( uint8_t ,uint8_t ,uint8_t );
void SetPIN( uint8_t , uint8_t , uint8_t );
uint8_t GetPIN( uint8_t , uint8_t , uint8_t );

#endif /* KIT_INFO2_H_ */
