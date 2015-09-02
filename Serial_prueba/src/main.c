/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

#include <stdio.h>
#include "Aplicacion.h"

uint8_t buffer [TOPE];	//buffer de recepción
uint8_t inx_out;		//índice de transmisión
uint8_t inx_in;			//índice de recepción
uint8_t enviando;		//variable auxiliar para disparar Tx

int main(void)
{
	InicializarKit();	//inicialización del HW
	InicializacionSW();	//inicialización de variables
	
	while(1) {
		//U1THR = 0x55;
		//U1THR = 0x00;
		//U1THR = 0x01;
		enviar_datos('1');
	}

	return 0 ;
}

void InicializacionSW (void){
	inx_out = inx_in = 0;  	//por profiláxis....
	enviando = 0;
}
