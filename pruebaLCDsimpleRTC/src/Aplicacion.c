/**
 \file		: Aplicacion.c
 \brief     : Fuente de la aplicacion principal
 \details   : Lee RTc y lo muestra por LCD
 \author    : GOS
 \date 	    : 2014.06.08
*/

#include "Aplicacion.h"

#define INT_DIGITOS 63

static char buf[INT_DIGITOS + 2];		//!< Buffer para INT_DIGITS dígitos, signo - y fin de string '\0'

extern RTC_HoraFecha horafecha;
extern uint32_t f_tick_rtc;


/**
 * \fn char * itoa(int i, unsigned int base)
 * \brief Convierte numeros a ascii para su impresion
 * \details	Convierte numeros a ascii hay que indicarle la base numerica y entrega ptr a buffer con resultado
 * \author GOS
 * \date   2014.06.08
 * \param [in] int i (numero a convertir), unsigned int base (base numerica)
 * \return char * (ptr a buffer con resultado de la conversion)
 * */
char * itoa(int i, unsigned int base)
{
	char *p = buf + INT_DIGITOS + 1; /* apunta a posición de unidades */
	int dig, signo=0;
	if (i<0) {signo=1;i = -i;}
	if(base<=0 || base>36) base=10; /*evita división por cero */

	do { dig=(i%base); if (dig <=9) *--p = '0' + dig; else *--p= '7'+ dig ; i /= base;}
	while (i != 0);

	if(signo) *--p = '-';
	return p;
}


/**
 * \fn 		void Display_HoraFecha(void)
 * \brief 	Lee RTC y lo muestra en LCD si se cumple condición de disparo
 * \details	Si se incrementó el contador de seg del RTC lo lee y lo muestra en el LCD
 * \author GOS
 * \date   2014.06.08
 * \param [in] void
 * \return void
 * */
void Display_HoraFecha(void)
{
	char LCD_renglon[LCD_ANCHO+1];
	char *renglon;// = LCD_renglon;

	if(f_tick_rtc){
		//Obtengo la hora y la muestro en el display
		RTC_GetHoraFecha(&horafecha);
		renglon = itoa(horafecha.dia_mes,10);
		Display_lcd(renglon, 0 , 4 );
		Display_lcd("/", 0 , 5 );
		renglon = itoa(horafecha.mes,10);
		Display_lcd(renglon, 0 , 6 );
		Display_lcd("/", 0 , 7 );
		renglon = itoa(horafecha.anio,10);
		Display_lcd(renglon, 0 , 8 );

		renglon = itoa(horafecha.hora,10);
		Display_lcd(renglon, 1 , 4 );
		Display_lcd(":", 1 , 6 );
		renglon = itoa(horafecha.min,10);
		Display_lcd(renglon, 1 , 7 );
		Display_lcd(":", 1 , 9 );
		renglon = itoa(horafecha.seg,10);
		Display_lcd(renglon, 1 , 10 );

		f_tick_rtc = 0;
	}
}
