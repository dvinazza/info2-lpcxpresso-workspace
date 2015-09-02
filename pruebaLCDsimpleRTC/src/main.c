/**
 \file		: main.c
 \brief     : Ejemplo de LCD y RTC
 \details   : Inicializa LCd y RTC, usa la mayoría de los comandos del LCD antes de ejecutar
 	 	 	  la aplicación para mostrar lo que se puede hacer.
 	 	 	  La aplicación lee el RTC cada vez que se incrementa su contador de segundos y muestra
 	 	 	  fecha y hora
 \author    : GOS
 \date 	    : 2014.06.08
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

volatile int DemoraLCD;					//!< Contador de demora rutinas de RTC
uint32_t f_tick_rtc  = 0;				//!< flag indicador de interrupción de RTc por incremento de seg
RTC_HoraFecha horafecha;				//!< Estructura de datos del RTC

/**
 * \fn int main (void)
 * \brief Ejemplo de LCD y RTC
 * \details
 * \author GOS
 * \date   2014.06.08
 * \param [in] void
 * \return int
 * */
int main(void)
{
	unsigned char i;
	char * renglon;

	InicializarKit ();

	//	Lo "pongo en hora" el 16/03/2012 a las 15:00:00
	/*----------------------------------------------------------------------------------------*/
		horafecha.anio = 2014;
		horafecha.mes = 5;
		horafecha.dia_mes = 6;
		horafecha.hora = 12;
		horafecha.min = 10;
		horafecha.seg = 50;
		horafecha.dia_anio = 128;
		RTC_SetHoraFecha(&horafecha);
	/*----------------------------------------------------------------------------------------*/


	// Prueba del display
	for(i = 0; i < 80; i++){
		WDato(0x41);
	}

	WComando8(LCD_CLEAR);
	WComando8(LCD_HOME1);
	WString("   Hola mundo...");
	WComando8(LCD_HOME2);
	WString("    Info II");

	WComando8(LCD_CLEAR);
	Display_lcd("Hola Mundo...",0,1);
	Display_lcd("Info II",1,1);

	renglon = itoa(2014,10);
	Display_lcd(renglon ,1 ,9);


	WComando8(CURSOR_ON);
	WComando8(BLINK_ON);

	WComando8(LCD_OFF);
	WComando8(LCD_ON);

	WComando8(LCD_CURSORON);

	WComando8(LCD_CURSORDEC);
	WComando8(LCD_CURSORINC);

	WComando8(LCD_CURSOROFF);

	WComando8(LCD_DEC);
	WComando8(LCD_INC);

	RTC_HabilitaInterrupcion(RTC_INTERRUPCION_SEG);
	WComando8(LCD_CLEAR);

	while(1) {
		Display_HoraFecha() ;
	}
	return 0 ;
}
