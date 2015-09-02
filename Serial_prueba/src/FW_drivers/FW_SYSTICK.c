#include "Aplicacion.h"

void systick_handler(void) {
	static uint8_t tiempo = 255;

	if (tiempo) { tiempo--; }
	else {
		tiempo = 255;
	} //cierra if
}
