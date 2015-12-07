/**
 	\file KitInfo2FW_Teclado.c
 	\brief Driver Driver de teclado
 	\details Expansion 4
 	\author Ing. Marcelo Trujillo
 	\date 2012.04.25
*/

#include "Aplicacion.h"
#include "Teclado.h"

// Buffer de teclado
extern volatile uint8_t bufferTeclado;

void DriverTeclado(void) { //la funcion que llama el systick
	uint8_t CodigoActual;
	CodigoActual = TecladoHW( );
	TecladoSW( CodigoActual );
}

uint8_t TecladoHW (void) {
	uint8_t Codigo = NOKEY;

	if (SW1_OFF) return 1;
	if (SW4_OFF) return 2;
	if (SW7_OFF) return 3;
	if (SW10_OFF) return 4;
	if (SW13_OFF) return 5;
    return Codigo;
}

void TecladoSW (uint8_t codAct) { //ANTIREBOTE
   static uint8_t codAnt = NOKEY;
   static uint8_t estado = REPOSO;
   uint8_t cont = 0; //no es necesario inicializarla

   if (codAct == NOKEY)
   { //mientras NO se oprima tecla SIEMPRE
      codAnt = NOKEY;	//entraré acá
      estado = REPOSO;
      return;
   }

   if (estado == DETECCION)
   {
      if (codAnt != codAct)
    	  codAnt = codAct;
      else {
    	  estado = CHEQUEO;
    	  cont = CANT_REBOTES;
      }
      return;
   }

   if (estado == CHEQUEO)
   {
      if (codAnt != codAct)
    	  estado = DETECCION;
      else if (cont)
    	  cont--;
      else {
    	  bufferTeclado = codAct;
    	  estado = REPOSO;
    	  codAnt = NOKEY;
      }
      return;
   }

   if (estado > EMERGENCIA) //por si perdí el control de la var de estado.
      estado = REPOSO;

   else{	//detecté una tecla por primera vez
      estado = DETECCION;
      codAnt = codAct;
   }
}
