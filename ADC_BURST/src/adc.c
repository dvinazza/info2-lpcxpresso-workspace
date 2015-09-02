#include "myreg.h"
void ADC_IRQHandler (void)
{
	unsigned int aux [7]; // Defino un vector auxiliar para guardar los valores de los registros AD0DRx.

	aux[0] = AD0DR0[0];
	aux[1] = AD0DR0[1];
	aux[2] = AD0DR0[2];
	aux[3] = AD0DR0[3];
	aux[4] = AD0DR0[4];
	aux[5] = AD0DR0[5];
	aux[6] = AD0DR0[6];
	aux[7] = AD0DR0[7];

	if((aux[0]>>30)== 0x02)
	{

	}
	if((aux[1]>>30)== 0x02)
	{

	}
	if((aux[2]>>30)== 0x02) 	   // Solamente entro al if si DONE = 1 y OVERRUN = 0.
	{                      		   // Cualquier otra combinación, descarto la conversión y espero la siguiente.
		aux[2] = AD0DR0[2]&0xFFC0; // Guardo en aux solamente los 10 bits mas significativos de la conversión del canal 2.
		DACR = aux[2];             // Paso los valores a la salida del DAC para verlos en el osc.
	}
	if((aux[3]>>30)== 0x02)
	{

	}
	if((aux[4]>>30)== 0x02)
	{

	}
	if((aux[5]>>30)== 0x02)
	{

	}
	if((aux[6]>>30)== 0x02)
	{

	}
	if((aux[7]>>30)== 0x02)
	{

	}
}

void start_adc(void)
{
	AD0CR |= (1 << 21); // Energizamos el ADC.
	AD0CR |= (1 << 16); // Seteamos conversiones BURST. Conversiones repetitivas a 192.3 Khz.
}


