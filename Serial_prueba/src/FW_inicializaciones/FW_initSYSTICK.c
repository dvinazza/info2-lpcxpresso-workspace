#include "Aplicacion.h"

void InicSysTick ( void )
{
	STRELOAD = ( STCALIB / 4) - 1;	//TPL2 EJ3P5 Recarga cada 2.5 ms
	STCURR = 0;	// Cargando con cero limpio y provoco el disparo de una intrrupcion
	// Habilito el conteo
	// Habilito interrupcion
	// Utilizamos Pclk
	STCTRL |=  ( ( 1 << ENABLE ) | ( 1 << TICKINT ) | ( 1 << CLKSOURCE ) );
}
