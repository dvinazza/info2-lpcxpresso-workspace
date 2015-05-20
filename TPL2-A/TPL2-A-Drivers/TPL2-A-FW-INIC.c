/*
===============================================================================
 TPL2-A-FW-INIC
===============================================================================
*/
#include "Infotronic.h"

/********************************************************************************
	\fn  void Inicializar ( void )
	\brief Inicializacion de Hardware.
	\author & date: Informática II
 	\param void
	\return:	void
*/
void Inicializar ( void )
{
	InitPLL ( ) ;
	InitGPIOs ( ) ;
	InitEINTx ( ) ;

}

/********************************************************************************
	\fn  void InitGPIOs ( void )
	\brief Inicialización de GPIO.
	\author & date: Informática II
 	\param void
	\return:	void
*/
void InitGPIOs ( void )
{
	SetPINSEL( 0 , 22 , 0 ); 	// puerto = 0 , pin =  22 ; seleccion = GPIO
	SetDIR( 0 , 22 , 1 ); 		// puerto = 0 , pin =  22 ; Direccion = SALIDA
}

/********************************************************************************
	\fn  void InitEINTx( void )
	\brief Inicialización de Interrupciones externas.
	\author & date: Informática II
 	\param void
	\return:	void
*/

void InitEINTx( void )
{
	// Interrupcion EINT3 -----------------------------------------------------------
	SetPINSEL( 2 , 13 , 1 ); 			// Pin9:P2[13] 	GPIO / EINT3 / Reserved / I2STX_SDA
	EXTMODE |= ( 1 << EXTMODE3 );		// externa por flanco
	//6. EXTPOLAR &= ~( 1 << EXTPOLAR3 );	// descendente
	EXTPOLAR |=  (1 << EXTPOLAR3);	// ascendente
	ISER0 |= ( 1 << NVIC_EINT3 ) ;		// Habilito Interrupcion externa 3
	// --------------------------------------------------------------------------------
}
