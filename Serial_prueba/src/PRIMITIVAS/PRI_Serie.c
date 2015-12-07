#include "Serie.h"

extern uint8_t bufferTX[TOPE];
extern uint8_t buffTX_out;
extern uint8_t buffTX_in;

extern uint8_t bufferRX[TOPE];
extern uint8_t buffRX_out;
extern uint8_t buffRX_in;

extern uint8_t enviando;		//variable auxiliar para disparar Tx

void pushTX(uint8_t dato) {
	bufferTX[buffTX_in] = dato;
	buffTX_in++;
	buffTX_in = buffTX_in % TOPE;

	if ( enviando ==  0 ) {
		enviando = 1;
		U1THR = bufferTX[buffTX_out];
	}
}

int popRX() {
	int aux = -1;
	if ( buffRX_in != buffRX_out ) {
		aux = bufferRX[buffRX_out];
		buffRX_out++;
		buffRX_out = buffRX_out % TOPE;
	}
	return aux;
}
