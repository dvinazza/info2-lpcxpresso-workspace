/*
===============================================================================
 TPL2 - Systic Timer
===============================================================================
*/
#include "Infotronic.h"

#define APAGADO 0
#define ROJO 1
#define AMARILLO 2
#define VERDE 3

#define TIEMPO_ROJO 30
#define TIEMPO_VERDE 20
#define TIEMPO_VERDE_AMARILLO 1
#define TIEMPO_ROJO_AMARILLO 2

uint8_t modoLED;
uint8_t modoLED_anterior;
uint8_t tiempo;

void SysTick_Handler(void) {

	static uint8_t fraccion = 1;

	if (fraccion) { fraccion--; return;}
	else {
		fraccion = 1;
		if (tiempo) { tiempo--; }
	}

}

int main(void) {

	Inicializar();

	modoLED=1;
	tiempo = TIEMPO_ROJO;

	while(1) {

		switch(modoLED) {
			case 0:
				break;

			case ROJO:
				if (! tiempo) {
					modoLED_anterior = modoLED;
					modoLED = AMARILLO;
					tiempo = TIEMPO_ROJO_AMARILLO; }
				break; //case ROJO

			case AMARILLO:
				if (! tiempo) {

					modoLED_anterior = modoLED;

					if ( modoLED_anterior == VERDE ) {
						modoLED = ROJO; tiempo = TIEMPO_ROJO; }
					else {
						modoLED = VERDE; tiempo = TIEMPO_VERDE; }
				}
				break; //case AMARILLO

			case VERDE:
				if (! tiempo) {
					modoLED_anterior = modoLED;
					modoLED = AMARILLO;
					tiempo = TIEMPO_VERDE_AMARILLO; }
				break; //case VERDE
			} //switch
		} //while

	return 0;
}
