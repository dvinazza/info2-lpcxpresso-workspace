/**
 \file		: FW_InitKit_principal.c
 \brief     : Rutinas de inicializacion
 \details   :
 \author    : GOS
 \date 	    : 2014.05.06
*/

#include "Aplicacion.h"

void InicializarKit ( void );





/**
 * \fn void InicializarKit ( void )
 * \brief Inicializacion del sistema
 * \details
 * \author GOS
 * \date   2014.05.06
 * \param [in] void
 * \return int
 * */
void InicializarKit ( void )
{
	InicPLL();
	Inicializar_Teclado();
	Inicializar_Relay();
	Inicializar_RGB();

// ESCRIBIR CODIGO DE OTRAS INICIALIZACIONES A PARTIR DE AQUI   <<<-----------------------
	InicSysTick();
	Inic_LCD();
	Inic_RTC();

}

