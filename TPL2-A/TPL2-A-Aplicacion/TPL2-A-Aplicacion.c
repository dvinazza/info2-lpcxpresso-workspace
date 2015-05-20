/*
===============================================================================
 TPL2 - Interrupciones externas
===============================================================================
*/
#include "Infotronic.h"

uint8_t estadoLED;

//Es una funcion primitiva, conecta el main con los drivers
//La optimizamos utilizando una expresion ternaria.
void analizar() {
	estadoLED ? SetPIN( 0 , 22 , 0 ): SetPIN( 0 , 22 , 1 );
}

int main(void)
{
	Inicializar ( );
	
	while( 1 ) {
		analizar();
	}

	return 0 ;

}

