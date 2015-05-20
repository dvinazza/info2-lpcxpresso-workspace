/*
===============================================================================
TPL2-C-FW-INIC
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
	Inicializar_Timer( ) ;

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
	\fn  void Inicializar_Timer(void)
	\brief Inicialización de Interrupcion y funcionamiento del T/C 0.
	\author & date: Informática II
 	\param void
	\return:	void
*/
void Inicializar_Timer(void)
{
	PCONP |= 1 << 1 ;//Resetea el timer y el counter 0
	PCLKSEL0 |= 0 << 2 ; //Deja el valor que esta en los bits 0,1,2

	//Establece el tiempo de interrupcion para el timer 0
	T0MR0 = 0x7fffff; //Match 0
	T0MR1 = 0xffffff ; //Match 1

	//Punto 6
	//T0MR0 = 0xffffff; //Match 0
	//T0MR1 = 0x7fffff ; //Match 1

	//Match 1 y 2 -> Configura la interrupcion y determina si se reinicia el TC
	//Estaba así en el source:
	//T0MCR  = ( ( 1 << MR0I ) | ( 0 << MR0R ) | ( 0 << MR0S ) ) ;

	T0MCR |= ( ( 1 << MR0I ) | ( 0 << MR0R ) | ( 0 << MR0S ) ) ;
	T0MCR |= ( ( 1 << MR1I ) | ( 1 << MR1R ) | ( 0 << MR1S ) ) ;

	T0TCR &= ( ~( 1 << CE ) ) ; //Se asegura que el bit de encendido este en 0
	T0TCR |= (    1 << CR ) ; //Activa el bit de reset

	T0TCR &= ( ~( 1 << CR ) ) ; //Se asegura que el bit de reset quede en 0
	T0TCR |= (    1 << CE ) ; //Activa el bit de encendido

	// Defines : ISER0 = ISER[0]; NVIC_TIMER0 = 1
	ISER0 |= ( 1 << NVIC_TIMER0 ) ; //Enciende la interrupcion por timer
}
