/*
 * Aplicacion.c
 *
 *  Created on: 07/09/2013
 *      Author: marcelo
 */

#include "Aplicacion.h"
extern volatile uint8_t BufferEntradas;			//Buffer de Entradas Digitales


void cuentoPulsos (void){
    static uint8_t antKey4 = 0;
    static uint8_t antKey3 = 0;
    static uint32_t cont = 0;

    if (TECLA_UP && !antKey4) //Si el pulsador está oprimido
    {	//y se detecta flanco ascendente
    	antKey4 = 1;
	    cont++;
	    SetPIN(LED2,ON);
	    Display (cont%1000000); //%1000000 >>> de 0 a 999999 (1 display de 6 dígitos)
    }
    else if (!TECLA_UP && antKey4) //si el pulsador no esta presionado
    {	    //y se detecta flanco descendente
    	antKey4 = 0;
	    SetPIN(LED2,OFF);
    }

    if (TECLA_DOWN && !antKey3) //Si el pulsador está oprimido
       {	//y se detecta flanco ascendente
    	antKey3 = 1;
   	    if (!cont){
   	    	cont = 999999;
   	    }else{
   	    	cont--;
   	    }
   	    SetPIN(LED1,ON);
   	    Display (cont%1000000); //%1000000 >>> de 0 a 999999 (1 display de 6 dígitos)
       }
       else if (!TECLA_DOWN && antKey3) //si el pulsador no esta presionado
       {	    //y se detecta flanco descendente
    	   antKey3 = 0;
    	   SetPIN(LED1,OFF);
       }
}
