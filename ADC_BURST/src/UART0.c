#include "myreg.h"

extern uint8_t bufferRX[TOPE];
extern uint8_t rx_out;
extern uint8_t rx_in;

void UART0_IRQHandler (void)
{
	uint8_t iir;

	iir = U0IIR;
		if ( iir & 0x04 ) //Data ready
		{
			rx_in++;
			bufferRX[rx_in] = (uint8_t)U0RBR;   	//guardo en buffer e incremento índice
			rx_in %= TOPE;		         			//garantizo el buffer circular
		}
}

