/*
===============================================================================
 TPL2 - Systic Timer
===============================================================================
*/
#ifndef REGS_H_
#define REGS_H_

#define		__RW				volatile
typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;
typedef 	__RW uint32_t 		registro_t;  //!< defino un tipo 'registro'.


// REGISTROS ------------------------------------------------------------------------------------------------------------------------
#define		PINSEL		( ( registro_t  * ) 0x4002C000UL )		//!< Direccion de inicio de los registros PINSEL
#define		PINMODE		( ( registro_t  * ) 0x4002C040UL )		//!< Direccion de inicio de los registros de modo de los pines del GPIO
#define		GPIO		( ( registro_t  * ) 0x2009C000UL )		//!< Direccion de inicio de los registros de GPIOs

// 0xE000E010UL: Registro de control del SysTick:
#define 	SYSTICK		( (registro_t *) 0xE000E010UL )

#define		STCTRL		SYSTICK[ 0 ]
	#define	ENABLE			0
	#define	TICKINT			1
	#define	CLKSOURCE		2
	#define	COUNTFLAG		16
#define		STRELOAD	SYSTICK[ 1 ]
#define		STCURR		SYSTICK[ 2 ]
#define		STCALIB		SYSTICK[ 3 ]

//  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
// 0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
#define 	PCONP	(* ( ( registro_t  * ) 0x400FC0C4UL ))

// Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
// 0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
#define		PCLKSEL		( ( registro_t  * ) 0x400FC1A8UL )
//!< Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]

#endif
