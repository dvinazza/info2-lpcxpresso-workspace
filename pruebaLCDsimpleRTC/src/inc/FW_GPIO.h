/**
 \file		: FW_GPIO.h
 \brief     : Header de rutinas de GPIO
 \details   :
 \author    : GOS
 \date 	    : 2014.06.08
*/

#ifndef FW_GPIO_H_
#define FW_GPIO_H_

	#include "RegsLPC1769.h"

    void 		SetPINSEL 	( uint8_t  ,uint8_t  ,uint8_t );
    void 		SetPINMODE	( uint8_t  ,uint8_t  ,uint8_t );
    void 		SetMODE_OD  ( uint8_t  ,uint8_t  ,uint8_t );
    void 		SetDIR		( uint8_t  ,uint8_t  ,uint8_t );
    void 		SetPIN		( uint8_t  ,uint8_t  ,uint8_t );
    uint8_t 	GetPIN		( uint8_t  ,uint8_t  ,uint8_t );

	//!< ----------- Estados de PINSEL:
	#define		PINSEL_GPIO			0
	#define		PINSEL_FUNC1		1
	#define		PINSEL_FUNC2		2
	#define		PINSEL_FUNC3		3

    // Modo OD
	#define		NORMAL			0
	#define		OPEN_DRAIN		1

    #define		ACTIVO_BAJO		0
    #define		ACTIVO_ALTO		1

	// dirección en FIODIR
	#define 	ENTRADA			0
	#define 	SALIDA			1

	// identificadores de los puertos
	#define 	PORT0			0
	#define 	PORT1			1
	#define 	PORT2			2
	#define 	PORT3			3
	#define 	PORT4			4

	//Prototipos de función:
    void Inicializar_Teclado( void );
    void Inicializar_Relay( void );
    void Inicializar_RGB( void );
    //void Inicializar_EXP1( void );

#endif /* FW_GPIO_H_ */
