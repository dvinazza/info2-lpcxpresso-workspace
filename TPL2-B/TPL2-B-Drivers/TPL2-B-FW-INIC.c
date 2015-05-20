/*
===============================================================================
TPL2-B-FW-INIC
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
	InicSysTick ( );

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
	\fn  void InicSysTick ( void )
	\brief Inicialización de Interrupcion Systick.
	\author & date: Informática II
 	\param void
	\return:	void
*/
void InicSysTick ( void )
{
	STRELOAD = ( STCALIB / 4) - 1;	//TPL2 EJ3P5 Recarga cada 2.5 ms
	STCURR = 0;	// Cargando con cero limpio y provoco el disparo de una intrrupcion
	// Habilito el conteo
	// Habilito interrupcion
	// Utilizamos Pclk
	STCTRL |=  ( ( 1 << ENABLE ) | ( 1 << TICKINT ) | ( 1 << CLKSOURCE ) );
}
