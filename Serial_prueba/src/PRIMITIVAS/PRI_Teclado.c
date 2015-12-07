/**
 	\file KitInfo2PR_Teclado.c
 	\brief Primitiva de teclado
 	\details Valida para BASE y Expansion 3 y Expansion 4
 	\author Ing. Marcelo Trujillo
 	\date 2012.04.25
*/
#include "Aplicacion.h"

// Buffer de teclado
extern uint8_t bufferTeclado;

uint8_t Teclado( void ) {
	uint8_t tecla = NOKEY;

	if (bufferTeclado != NOKEY ) {
		tecla = bufferTeclado;
		bufferTeclado = NOKEY;
	}
	return tecla;
}
