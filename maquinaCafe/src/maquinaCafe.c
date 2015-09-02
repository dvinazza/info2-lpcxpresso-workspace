/*
===============================================================================
 Name        : maquinaCafe.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include "maquinaCafe.h"

typedef 	unsigned char 	uint8_t;

//ver defines en maquinaCafe.h
unsigned char estadoMaquina;

#define CANTIDAD_OPCIONES 3;
unsigned char costo[3] = { 1, 2, 3 };
unsigned char stock[3] = { 10, 8, 5 };

unsigned char aux;

char opcion; //-1 es no hay opcion

void recibirMonedas() {
}

void recibirEleccion() {
}

void servir() {
}

void reiniciarMaquina() {
}

int main(void) {

	estadoMaquina = -1; //inicio por caso de emergencia

    while(1) {
    	switch (estadoMaquina) {
    		case MAQUINA_EN_STAND_BY:
    			break;
    		case MAQUINA_ESPERANDO_MONEDAS:
    			break;
    		case MAQUINA_DEVOLVIENDO_MONEDAS:
    			break;
    		case MAQUINA_SIRVIENDO:
    			break;
    		default:
    			estadoMaquina = MAQUINA_EN_STAND_BY;
    		} //cierra switch
    }
    return 0 ;
}
