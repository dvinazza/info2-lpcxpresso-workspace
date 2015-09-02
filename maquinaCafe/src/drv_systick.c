#include "maquinaCafe.h"

uint8_t tiempoMonedas;
uint8_t tiempoDevolucion;
uint8_t tiempoError;

extern unsigned char monedas;
extern unsigned char estadoMaquina;

void systick_handler(void) {
	static uint8_t tiempo = 255;

	tecladoSW();
	barridoDisplay();

	if (tiempo) { tiempo--; }
	else {
		tiempo = 255;

		switch (estadoMaquina) {
		case MAQUINA_EN_STAND_BY:
			break;
		case MAQUINA_ESPERANDO_MONEDAS:
			if (tiempoMonedas) { tiempoMonedas--; }
			else {
				tiempoMonedas = 100;
				estadoMaquina = MAQUINA_DEVOLVIENDO_MONEDAS; }
			break;
		case MAQUINA_DEVOLVIENDO_MONEDAS:
			if (tiempoDevolucion) { tiempoDevolucion--; }
			else {
				tiempoDevolucion = 100;
				estadoMaquina = MAQUINA_EN_STAND_BY; }
			break;
		case MAQUINA_SIRVIENDO:
			break;
		default:
			estadoMaquina = MAQUINA_EN_STAND_BY;
		} //cierra switch
	} //cierra if
}
