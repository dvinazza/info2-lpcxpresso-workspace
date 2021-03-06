#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "Infotronic.h"

#define SUMAR 1
#define RESTAR 2

extern uint8_t bufferTecla;
uint32_t bufferValor;

#define modoReset 0
#define modoAsc 1
#define modoDes 2

#define valorMinimo 0
#define valorMaximo 1000

#define puertoLED PORT1
#define pinLED 26

uint8_t estadoLed;
uint8_t estadoMaquina;

int main(void) {

	init();

    estadoMaquina = modoReset;
    estadoLed;

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

        			SetPIN(PORT1,26,estadoLed);
        			estadoMaquina = modoDes; }
        		break;

        	case modoDes:
        		if (valor > valorMinimo) { valor--; }
        		else {
        			estadoLed = !estadoLed;

        			SetPIN(PORT1,26,estadoLed);
        			estadoMaquina = modoAsc; }

        	default: //reset y emergencia
        		estadoMaquina = modoAsc;
        		valor = valorMinimo;
        		estadoLed = 0;
        		SetPIN(PORT1,26,estadoLed);
        }

        //un bucle para simular demora
        for (auxA=0; auxA < 10000; auxA++) {
        	for (auxB=0; auxB < 1000; auxB++) {

        	}
        }

    }
    return 0 ;
}
