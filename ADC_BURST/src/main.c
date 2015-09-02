/*
===============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Copyright (C) 
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include "myreg.h"
#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

// TODO: insert other include files here

// TODO: insert other definitions and declarations here
uint8_t clk_div = 0;
uint8_t bufferRX[TOPE];
uint8_t rx_out = 0;
uint8_t rx_in = 0;


int main(void)
	{
		init();
		start_adc();
		while(1)
				{
			Mensajes();// Reviso si hay mensajes de comunicacion serie.
				}

	return 0 ;
	}
void Mensajes(void)
{
	char comando;
	if(rx_in != rx_out)
	{
	AD0CR &= ~(1 << 16); // Apago el burst.
	AD0CR &= ~(1 << 21); // Apago el conversor.
		rx_out++;
		comando = (char) bufferRX[rx_in];
		rx_out %= TOPE;
		if(comando == '+')
			Aumentar_sampling();
		if(comando == '-')
			Bajar_sampling();
	AD0CR |= (1 << 21);
	AD0CR |= (1 << 16);
}
}

void Aumentar_sampling(void)
{
	if (clk_div > 0)
	{
		clk_div--; // Lo decremento para ir aumentando la velocidad del clock del ADC y por ende la de sampling.
		AD0CR &= ~(0xFF << 8); // Limpio los bits
		AD0CR |= (clk_div << 8); // Cargo el nuevo valor del divisor de clock en el registro del ADC.
	}
}

void Bajar_sampling(void)
{
	if (clk_div < 0xFF)
	{
		clk_div++;
		AD0CR &= ~(0xFF << 8);
		AD0CR |= (clk_div << 8);
	}
}
