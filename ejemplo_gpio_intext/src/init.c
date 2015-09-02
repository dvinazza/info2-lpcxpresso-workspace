#include "myreg.h"

void init(void)
{
	Init_GPIO();
	//Init_IntExt();
}

void Init_GPIO(void)
{
	SetPINSEL(puertoLED,pinLED,00);
	SetDIR(puertoLED,pinLED,1);
}

void Init_IntExt(void)
{
	SetPINSEL(P2,10,01);
	SetPINSEL(P2,13,01);

	EXTMODE |=(0x09);

	EXTPOLAR &=~(0x09);


	ISER0 |=(0x01<<18);
	ISER0 |=(0x01<<21);
}

