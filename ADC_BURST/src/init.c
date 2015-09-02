#include "myreg.h"

void init(void)
{
		Init_pines();
		Init_PLL();
		Init_ADC();
		Init_DAC();
		Init_UART0();
}

void Init_ADC(void)
{
	PCONP |= (1 << 12); // Asignamos el clock al ADC
	PCLKSEL0 &= ~(0x03 << 24);
	PCLKSEL0 |= (0x03 << 24); // El PERIPHERIAL clock del ADC es CCLK / 8 = 100 Mhz / 8 = 12,5 Mhz.
	AD0CR &= ~(0xFFFF); // Limpiamos los bits 15:0, el clock se divide por 1.
	AD0CR |= (1 << 2); //Sampleamos unicamente el canal 2, es decir EA2.
	AD0INTEN &= ~(0x01<<8); // Habilitamos solo interrupciones individuales.
	AD0INTEN |= (0x01<<2); // Habilitamos la interrupción individual del CH2
	IPR5 &= (0x1F << 19);
	IPR5 |= (0x1F << 19); // Interrupcion del adc en mínima prioridad
	ISER0 |= (0x01 << 22); //Habilitamos globalmente las interrupciones del ADC.
}

void Init_DAC(void)
{
	PCLKSEL0 &= ~(0x03 << 22);
	PCLKSEL0 |= (3 << 22); // El PERIPHERIAL clock del DAC es CCLK / 8 = 100 Mhz / 8 = 12,5 Mhz.
}


void Init_pines(void)
{
	// Led RGB
	SetPINSEL(P2,3,0);
	SetPINSEL(P2,2,0);
	SetPINSEL(P2,1,0);
	SetDIR(PORT2,1,SALIDA);
	SetDIR(PORT2,2,SALIDA);
	SetDIR(PORT2,3,SALIDA);
	//ADC
	SetPINSEL(P0,3,0);
	SetPINSEL(P0,2,0);
	SetPINSEL(P0,23,0);
	SetPINSEL(P0,24,0);
	SetPINSEL(P1,30,0);
	SetPINSEL(P1,31,0);
	SetPINSEL(P0,25,1); // Entrada analógica EA2 configurada como ADC0.2

	PINMODE1 &= ~(0x03 << 18);
	PINMODE1 |= (0x02 << 18); // Le quitamos las R de pull al pin.

	//DAC
	SetPINSEL(P0,26,2); // P0.26 es salida del DAC.
	PINMODE1 &= ~(0x03 << 18);
	PINMODE1 |= (0x02 << 18); //  Le quitamos las R de pull al pin.
}
void Init_PLL(void)                 // Clock de 100 MHz.
{
	  	SCS       = SCS_Value;

	 	if (SCS_Value & (1 << 5))       /* If Main Oscillator is enabled      */
	 		while ((SCS & (1<<6)) == 0);/* Wait for Oscillator to be ready    */

	 	CCLKCFG   = CCLKCFG_Value;      /* Setup Clock Divider                */

	 	PCLKSEL0  = PCLKSEL0_Value;     /* Peripheral Clock Selection         */
	 	PCLKSEL1  = PCLKSEL1_Value;

	 	CLKSRCSEL = CLKSRCSEL_Value;    /* Select Clock Source for PLL0       */

	 	PLL0CFG   = PLL0CFG_Value;      /* configure PLL0                     */
	 	PLL0FEED  = 0xAA;
	 	PLL0FEED  = 0x55;

	 	PLL0CON   = 0x01;               /* PLL0 Enable                        */
	 	PLL0FEED  = 0xAA;
	 	PLL0FEED  = 0x55;

	 	while (!(PLL0STAT & (1<<26)));  /* Wait for PLOCK0                    */

	 	PLL0CON   = 0x03;               /* PLL0 Enable & Connect              */
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
void Init_UART0 (void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 3 en 1 prende la UART:
	PCONP |= 0x01<<3;
	//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	PCLKSEL0 &= ~(0x03<<6);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U0LCR = 0x00000083;
	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios:
	U0DLM = 0;
	U0DLL = 0xA3;//0xA3 para 9600
	//5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	//TX1D : PIN ??	-> 		P0[2]	-> PINSEL0: 04:05
	SetPINSEL(TX0,1);
	//RX1D : PIN ??	-> 		P0[3]	-> PINSEL1: 06:07
	SetPINSEL(RX0,1);
	//6.- Registro U1LCR, pongo DLAB en 0:
	U0LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U0IER = 0x01;
	IPR1 &= (0x1F << 11);
	IPR1 |= (0x1E << 11);// Interrupcion del UART prioritaria frente a la del ADC.
	ISER0 |= (1<<5);
}
