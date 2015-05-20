/*
===============================================================================
Infotronic.h
===============================================================================
*/
#ifndef KIT_INFO2_H_
#define KIT_INFO2_H_

#include "Oscilador.h"
#include "RegsLPC1769.h"
// TPL2-C-FW-INIC.c
void Inicializar ( void );
void InitPLL ( void );
void InitGPIOs ( void );
void Inicializar_Timer(void);

// TPL2-C-FW-CONFIG.c
void SetPINSEL ( uint8_t , uint8_t , uint8_t );
void SetMODE ( uint8_t , uint8_t , uint8_t );

// TPL2-A-FW-GPIO.c
void SetDIR( uint8_t ,uint8_t ,uint8_t );
void SetPIN( uint8_t , uint8_t , uint8_t );
uint8_t GetPIN( uint8_t , uint8_t , uint8_t );

#endif
