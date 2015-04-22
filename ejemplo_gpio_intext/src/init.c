#include "myreg.h"

void init(void)
{
	Init_GPIO();
	Init_IntExt();
}

void Init_GPIO(void)
{

}

void Init_IntExt(void)
{
	SetPINSEL(KEY0, PINSEL_FUNC1);
	SetPINSEL(KEY3, PINSEL_FUNC1);

	EXTMODE=(0X0F);
	EXTPOLAR=(0X00);

	ISER0 |= (0x01 << 18);
	ISER0 |= (0x01 << 21);
}

