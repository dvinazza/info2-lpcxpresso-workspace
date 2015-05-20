#include "myreg.h"

void init(void)
{
	Init_gpios();
	Init_systick();
	Init_IntExt();
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

void Init_gpios(void)
{
		// Led RGB
		SetPINSEL(P2,3,PINSEL_GPIO);
		SetPINSEL(P2,2,PINSEL_GPIO);
		SetPINSEL(P2,1,PINSEL_GPIO);

		/* Reles
		SetPINSEL(P0,21,PINSEL_GPIO);
		SetPINSEL(P0,23,PINSEL_GPIO);
		SetPINSEL(P0,27,PINSEL_GPIO);
		SetPINSEL(P2,0,PINSEL_GPIO); */

		// Buzzer
		SetPINSEL(P0,28,PINSEL_GPIO);

		// Modos
		SetDIR(PORT2,1,SALIDA);
		SetDIR(PORT2,2,SALIDA);
		SetDIR(PORT2,3,SALIDA);
}

void Init_systick(void)
{
	//STRELOAD = 405000; // Aprox. 1 seg cuando no se configura el PLL.
	STRELOAD = STCALIB -1; // Aprox. 1 seg cuando no se configura el PLL.
	STCTRL |= 0x07;	// Clock sistema, interrupción habilitada, systick habilitado.
}

void Init_PLL(void) // Clock de 100 MHz.
{
	  	SCS       = SCS_Value;

	 	if (SCS_Value & (1 << 5))               /* If Main Oscillator is enabled      */
	 		while ((SCS & (1<<6)) == 0);/* Wait for Oscillator to be ready    */

	 	CCLKCFG   = CCLKCFG_Value;      /* Setup Clock Divider                */

	 	PCLKSEL0  = PCLKSEL0_Value;     /* Peripheral Clock Selection         */
	 	PCLKSEL1  = PCLKSEL1_Value;

	 	CLKSRCSEL = CLKSRCSEL_Value;    /* Select Clock Source for PLL0       */

	 	PLL0CFG   = PLL0CFG_Value;      /* configure PLL0                     */
	 	PLL0FEED  = 0xAA;
	 	PLL0FEED  = 0x55;

	 	PLL0CON   = 0x01;             /* PLL0 Enable                        */
	 	PLL0FEED  = 0xAA;
	 	PLL0FEED  = 0x55;

	 	while (!(PLL0STAT & (1<<26)));/* Wait for PLOCK0                    */

	 	PLL0CON   = 0x03;             /* PLL0 Enable & Connect              */
	 	PLL0FEED  = 0xAA;
	 	PLL0FEED  = 0x55;

	 	while (!(PLL0STAT & ((1<<25) | (1<<24))));/* Wait for PLLC0_STAT & PLLE0_STAT */

	 	PLL1CFG   = PLL1CFG_Value;
	 	PLL1FEED  = 0xAA;
	 	PLL1FEED  = 0x55;

	 	PLL1CON   = 0x01;             /* PLL1 Enable                        */
	 	PLL1FEED  = 0xAA;
	 	PLL1FEED  = 0x55;

	 	while (!(PLL1STAT & (1<<10)));/* Wait for PLOCK1                    */

	 	PLL1CON   = 0x03;             /* PLL1 Enable & Connect              */
	 	PLL1FEED  = 0xAA;
	 	PLL1FEED  = 0x55;

	 	while (!(PLL1STAT & ((1<< 9) | (1<< 8))));/* Wait for PLLC1_STAT & PLLE1_STAT */

	 	PCONP     = PCONP_Value;        /* Power Control for Peripherals      */

	 	CLKOUTCFG = CLKOUTCFG_Value;    /* Clock Output Configuration         */

	 	FLASHCFG  = (FLASHCFG & ~0x0000F000) | FLASHCFG_Value;
}
