#include "myreg.h"

uint8_t modoLED = 1; //1 titila

void EINT0_IRQHandler(void)
{
	EXTINT = 0x0F;
	modoLED = 1;
}


void EINT3_IRQHandler(void)
{
	EXTINT = 0x0F;
	modoLED = 2;
}
