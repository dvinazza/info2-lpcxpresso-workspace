/*
===============================================================================
 TPL2 - Systic Timer
===============================================================================
*/
#include "Infotronic.h"

uint32_t cuenta;
uint8_t estadoLED;

void SysTick_Handler(void)
{
	if (cuenta) {
		cuenta--; }
	else {
		cuenta = 400;
		estadoLED =! estadoLED;
	}
}

void analizar() {
	estadoLED ? SetPIN( 0 , 22 , 0 ): SetPIN( 0 , 22 , 1 );
}

int main(void)
{
	Inicializar ( );
	
	while( 1 ) {
		analizar();
	}

	return 0 ;
}

