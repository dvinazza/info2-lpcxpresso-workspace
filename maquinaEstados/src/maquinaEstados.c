/*
===============================================================================
 Name        : maquinaEstados.c
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

#include "Infotronic.h"

#define modoReset 0
#define modoAsc 1
#define modoDes 2

#define valorMinimo 0
#define valorMaximo 1000

#define puertoLED PORT1
#define pinLED 26

uint8_t estadoLed;
uint8_t estadoMaquina;

void SetPINSEL( uint8_t puerto , uint8_t pin ,uint8_t funcion ) {
	puerto = puerto * 2 + pin / 16;
	pin = ( pin % 16 ) * 2;
	PINSEL[ puerto ] &= ( ~ ( 3 << pin ) );
	PINSEL[ puerto ] |= ( funcion << pin );
}


void SetDIR( uint8_t puerto , uint8_t pin , uint8_t dir ) {
	puerto = puerto * 8;
	GPIO[ puerto ] = GPIO[ puerto ] & ( ~ ( 1 << pin ) );
	GPIO[ puerto ] = GPIO[ puerto ] | ( dir << pin );
}

void SetPIN( uint8_t puerto , uint8_t pin , uint8_t estado ) {
	puerto = puerto * 8 + 5;
	GPIO[ puerto ] = GPIO[ puerto ] & ( ~ ( 1 << pin ) );
	GPIO[ puerto ] = GPIO[ puerto ] | ( estado << pin );
}

uint8_t GetPIN( uint8_t puerto , uint8_t pin , uint8_t actividad ) {
	puerto = puerto * 8 + 5;
	return ( ( ( GPIO[ puerto ] >> pin ) & 1 ) == actividad ) ? 1 : 0;
}

void init(void) {
	InitPLL();

	SetPINSEL(puertoLED, pinLED, 00); //gpio
	SetDIR(puertoLED, pinLED, 1); //escritura
}

int main(void) {

	init();

    estadoMaquina = modoReset;

    uint8_t valor;

    //demora bloqueante
    uint32_t auxA;
    uint32_t auxB;

    while(1) {

        switch(estadoMaquina) {
        	case modoAsc:
        		if (valor < valorMaximo) { valor++; }
        		else {
        			estadoLed = !estadoLed;
        			SetPIN(puertoLED,pinLED,estadoLed);
        			estadoMaquina = modoDes; }
        		break;

        	case modoDes:
        		if (valor > valorMinimo) { valor--; }
        		else {
        			estadoLed = !estadoLed;
        			SetPIN(puertoLED,pinLED,estadoLed);
        			estadoMaquina = modoAsc; }
        		break;

        	default: //reset y emergencia
        		estadoMaquina = modoAsc;
        		valor = valorMinimo;
        		estadoLed = 0;
        		SetPIN(puertoLED,pinLED,estadoLed);
        }

        //un bucle para simular demora
        for (auxA=0; auxA < 10000; auxA++) {
        	for (auxB=0; auxB < 1000; auxB++) {

        	}
        }

    }
    return 0 ;
}
