#include "myreg.h"

void init(void)
{
	Init_GPIO();
	Init_IntExt();
}

void Init_GPIO(void)
{
	SetDIR(PORT0, 22, 1);
	SetDIR(PORT2, 10, 0);
	SetDIR(PORT2, 13, 0);
}

void Init_IntExt(void)
{
	SetPINSEL(P2, 10, 1); //Interrupcion
	SetPINSEL(P2, 13, 1);

	EXTMODE = (0x0F);
	EXTPOLAR &= ~(0x00);

	ISER0 |= (0x01 << 18);
	ISER0 |= (0x01 << 21);
}

