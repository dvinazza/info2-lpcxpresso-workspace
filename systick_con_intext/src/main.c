
#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "myreg.h"

extern uint8_t estadoLED;

int main(void)
	{
	init();
	while(1)
	{
		if (estadoLED) { SetPIN(PORT2, 1, 1); }
		else { SetPIN(PORT2,1, 0); }
	}
	return 0 ;
	}
