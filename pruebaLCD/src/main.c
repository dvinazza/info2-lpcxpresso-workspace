/**
 * ===============================================================================
 *  Name        : main.c
 *  Author      : $(author)
 *  Version     :
 *  Copyright   : $(copyright)
 *  Description : main definition
 * ===============================================================================
 *
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
//__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;


#include "Aplicacion.h"
#include "lcd.h"

volatile uint8_t msgDisplay[DIGITOS];			//Buffer de display
volatile uint8_t BufferEntradas;				//Buffer de Entradas Digitales

volatile unsigned int inxInLCD;
volatile unsigned int inxOutLCD;
volatile unsigned int cantidadColaLCD;
volatile int DemoraLCD;
uint8_t bufferLCD[100];
uint8_t ptrLecturaLCD = 0;
uint8_t ptrEscrituraLCD = 0;

int main(void)
{
	unsigned char i;

	InicializarKit ();

	// Prueba del display
	for(i = 0; i < 80; i++){
		WDato(0x41);
	}

	/* WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString("A...");
	WComando8(LCD_HOME2);
	WString("    Info II");
	WComando8(LCD_CLEAR);
	Display_lcd("Hola Mundo...",0,1);
	Display_lcd("Info II",1,1);*/

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME2);
	//DisplayInt_lcd(2013 ,1 ,9);

	Push_BufferLCD(LCD_CLEAR,"Hola clase", RENGLON_1, 3);
	//Push_BufferLCD(LCD_HOME2,"Info II 2013", RENGLON_2, 3);

	while(1) {
		//cuentoPulsos() ;
	}
	return 0 ;
}
