#include "maquinaCafe.h"

extern unsigned char flagMonedas;
extern unsigned char flagDevolucion;
extern unsigned char flagError;

extern uint8_t tiempoMonedas;
extern uint8_t tiempoDevolucion;
extern uint8_t tiempoError;

unsigned char monedas;

extern unsigned char estadoMaquina;

void devolverMonedas() {
	monedas = 0;
	flagDevolucion = 1;
	estadoMaquina = MAQUINA_EN_STAND_BY;
}

void entroMoneda() {

	if (monedas == 0) {
		estadoMaquina = MAQUINA_ESPERANDO_MONEDAS;
		tiempoMonedas = TIEMPO_MONEDAS; }
	else {
		tiempoMonedas += TIEMPO_MONEDAS_EXTENSION; 	}

	monedas++;

	if (monedas > MAX_MONEDAS) {
		flagMonedas = 0;
		devolverMonedas();
	}
}
