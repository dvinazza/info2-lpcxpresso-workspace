/**
 \file		: FW_Systick.c
 \brief     : Rutinas de Timer Tick
 \details   :
 \author    : GOS
 \date 	    : 2014.05.06
*/

#include "Aplicacion.h"


extern volatile int DemoraLCD;


/**
 * \fn 		void InicSysTick(void)
 * \brief 	Inicializacion del sistema
 * \details
 * \author 	GOS
 * \date   	2014.05.06
 * \param 	[in] void
 * \return 	int
 * */
void InicSysTick(void){ //si divido x 4, interrumpe cada 2,5ms
		STRELOAD  = ( STCALIB / 4 ) - 1 ;   //N=1 para 10ms
		STCURR = 0;

		ENABLE = 1;
		TICKINT = 1;
		CLKSOURCE = 1;
		return;
}

/**
 * \fn 		void SysTick_Handler(void)
 * \brief 	ISR del Systick
 * \details
 * \author 	GOS
 * \date   	2014.05.06
 * \param 	[in] void
 * \return 	void
 * */
void SysTick_Handler(void)
{


	if ( DemoraLCD ){

		DemoraLCD--;

	}


}
