#include "TPL3.H"

//buffer con la data a mostrar
uint8_t bufferSegmentos[CANTIDAD_SEGMENTOS];

// pines de los segmentos a b c d e f g
uint8_t auxDisplaySegmentosPuertos[] = { 3, 1, 1, 1, 1, 3, 0};
uint8_t auxDisplaySegmentosPines[] = { 26, 18, 21, 24, 17, 25, 20};

//puertos/pines comunes de los digitos
//estan en la inicializacion --> TPL3-FW-INIC.c
extern uint8_t auxDisplayPuertos[];
extern uint8_t auxDisplayPines[];


void barridoDisplay (void) {

	static uint8_t digitoEncendido = 0;
	uint8_t auxDigito, aux;

	// apago el digito encendido antes de configurar el siguiente
	SetPIN(auxDisplayPuertos[digitoEncendido], auxDisplayPines[digitoEncendido], 0);

	digitoEncendido++;

	// enciendo los segmentos a, b, c, d, e, f y g del digito
	auxDigito = bufferSegmentos[digitoEncendido];
	for (aux = 0; aux < CANTIDAD_SEGMENTOS; aux++) {
		SetPIN(auxDisplayPuertos[aux], auxDisplayPines[aux], ( (auxDigito >> aux) & 0x01 ) );
	}

	// enciendo el digito
	SetPIN(auxDisplayPuertos[digitoEncendido], auxDisplayPines[digitoEncendido], 1);
}

void barridoTeclado ( void ) {
	lecturaTecladoSW();
}

void SysTick_Handler(void) {
	static uint8_t tiempoBase = 10;

	if (tiempoBase) { tiempoBase--; }
	else {
		tiempoBase = 10;
		barridoDisplay();
		barridoTeclado();
	}
}
