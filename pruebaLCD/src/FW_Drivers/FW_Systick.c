
#include "Aplicacion.h"
#include "lcd.h"

extern volatile int DemoraLCD;

void BarridoDisplay( void );

void SysTick_Handler(void)
{

// Aquí escribo todo aquello que deseo que ocurra cada 2,5ms.

	BarridoDisplay();
	Debounce ();

	if ( DemoraLCD ){

		DemoraLCD--;

	}

	ImprimeLCD();
}
