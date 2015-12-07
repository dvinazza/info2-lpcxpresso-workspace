
#include "Serie.h"

uint8_t bufferTX[TOPE];
uint8_t buffTX_out;
uint8_t buffTX_in;

uint8_t bufferRX[TOPE];
uint8_t buffRX_out;
uint8_t buffRX_in;

uint8_t enviando;		//variable auxiliar para disparar Tx

void inicializarSerie (void){
	buffRX_out = buffRX_in = 0;  	//por profiláxis....
	buffTX_out = buffTX_in = 0;  	//por profiláxis....
	enviando = 0;
}

void pushRX(uint8_t dato) {
	bufferRX[buffRX_in] = dato;
	buffRX_in++;
	buffRX_in = buffRX_in % TOPE;

	/*if ( enviando ==  0 ) { #no se fuerza para recepcion
		enviando = 1;
		U1THR = bufferRX[buffRX_out];
	}*/
}

int popTX() {
	int aux = -1;
	if ( buffTX_in != buffTX_out ) {
		aux = bufferTX[buffTX_out];
		buffTX_out++;
		buffTX_out = buffTX_out % TOPE;
	}
	return aux;
}
