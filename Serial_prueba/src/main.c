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

uint8_t estado; 		//'global' del estado de la maquina

int main(void)
{
	InicializarKit();	//inicialización del HW
	inicializarSerie();

	estado = ESPERANDO;
	
	uint8_t aux=15;

	while(1) {
		enviarTrama(aux);
		//if ( (aux = Teclado()) != NOKEY ) { enviarTrama(aux); }
		//aux = recibirTrama();
		//display(aux);
	}

	return 0 ;
}
