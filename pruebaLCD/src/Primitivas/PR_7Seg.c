/**
 	\file KitInfo2PR_7Seg.c
 	\brief Primitiva de Display de 7 segmentos
 	\details Valida para Expansion 2 y Expansion 3
 	\author Ing. Marcelo Trujillo
 	\date 2012.04.25
*/

#include "Aplicacion.h"

extern volatile uint8_t msgDisplay[DIGITOS];			//!< Buffer de display
/**
Tabla de conversion bcd a 7 segmentos
	Codigo bcd		a	b	c	d	e	f	g   dp
	0				1	1	1	1	1	1	0   0
	1				0	1	1	0	0	0	0
 	2				1	1	0	1	1	0	1
 	3				1	1	1	1	0	0	1
 	4				0	1	1	0	0	1	1
	5				1	0	1	1	0	1	1
	6				0	0	1	1	1	1	1
	7				1	1	1	0	0	0	0
 	8				1	1	1	1	1	1	1
	9				1	1	1	0	0	1	1
*/
uint8_t Tabla_Digitos_BCD_7seg[] = { 0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7C, 0x07, 0x7f, 0x67};

	/**
		\fn  void Display(int Val)
		\brief Presentacion de valores en el display de 6 dígitos
	 	\param [in] val valor a mostrar
		\return void
	*/

	void Display (uint32_t Val){
	    uint8_t i;
	    for (i=0; i<DIGITOS ; i++){
	    	msgDisplay[i] = Tabla_Digitos_BCD_7seg[Val%10];
	    	Val /= 10;
	    }
	}

