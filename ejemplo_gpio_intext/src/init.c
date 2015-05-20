#include "myreg.h"

void init(void)
{
	Init_GPIO();
	Init_IntExt();
}

void Init_GPIO(void)
{
	SetPINSEL(P0,28,00);
	SetDIR(PORT0,28,1);

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

