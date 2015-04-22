#include "myreg.h"

void EINT0_IRQHandler(void) {
	EXTINT = 0x0F;
	SetPIN(P0, 28, 0);
}

void EINT3_IRQHandler(void) {
	EXTINT = 0x0F;
	SetPIN(P0, 28, 1);
}
