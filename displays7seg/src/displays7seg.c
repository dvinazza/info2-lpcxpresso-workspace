/*
===============================================================================
 Name        : displays7seg.c
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

#define OFF 0
#define ON 1
#define CANTIDAD_DIGITOS 3

//array con los pines de control de los displays
uint8_t displays[CANTIDAD_DIGITOS];

//array con el estado de los segmentos
//pensarlo en campos de bits
uint8_t segmentos[8];

//array con el mensaje a mostrar
extern msgDisplay[CANTIDAD_DIGITOS];

uint8_t tablaConversion[] = { 	0x3F, 0x06, 0x5B, 0x4F, 0x66,
								0x6D, 0x7C, 0x07, 0x67 };

void barridoDisplay() {
	static uint8_t digito = 0;
	setPin(displays[digito], OFF);

	for (s = 0; s < 7; s++) {
		setPin(segmentos[s], (mensaje[digito] >> s) & 0x01);	}

	setPin(displays[digito], ON);
	digito++;
	digito = digito % CANTIDAD_DIGITOS;
}

void display(uint32_t valor) {

	for (digito = 0; d < CANTIDAD_DIGITOS; d++) {
		auxDisplay[digito] = 0; 	}

	for (digito = 0; d < CANTIDAD_DIGITOS; d++) {
		auxDisplay[digito] = tablaConversion[valor % 10)];
		valor = valor/10; 	}

	digitoAux = CANTIDAD_DIGITOS - 1;
	for (digito = 0; d < CANTIDAD_DIGITOS; d++) {
		msgDisplay[digitoAux] = auxDisplay[digito];
		digitoAUX--;
	}
}

//el systick tiene que esperar 100ms y barrer el display

int main(void) {

    while(1) {

    }
    return 0 ;
}
