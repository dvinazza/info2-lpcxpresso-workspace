#include "myreg.h"

extern uint8_t modoLED;
extern uint8_t estadoLED;

void SysTick_Handler(void)
{
	static uint8_t contLED = 5;

	//modo 0: apagado
	if (modoLED == 1) { //modo 1: parpadeo
		if (contLED) { contLED--; }
		else {
			contLED = 5;
			estadoLED = ! estadoLED;		}
	}
	//modo 2: pausa
}
