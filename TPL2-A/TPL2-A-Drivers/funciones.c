
#include "Infotronic.h"

extern uint8_t estadoLED;

void EINT3_IRQHandler( void )
{
	EXTINT |= ( 1 << EINT3 );	// borro el flag EINT3 de interrupcion externa 3 del registro EXTINT

	/* En el punto 7 lo acortamos con una expr ternaria en una funcion primitiva
	if( GetPIN( 0 , 22 , 1 ) )	// puerto = 0 , pin =  22 ; actividad = ALTO
			SetPIN( 0 , 22 , 0 );	// puerto = 0 , pin =  22 ; estado = 0
		else
			SetPIN( 0 , 22 , 1 );	// puerto = 0 , pin =  22 ; estado = 1
	*/

	estadoLED =! estadoLED;


}
