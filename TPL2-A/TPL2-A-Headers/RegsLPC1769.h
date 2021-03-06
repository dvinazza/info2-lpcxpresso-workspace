/*
===============================================================================
RegsLPC1769.h
===============================================================================
*/
#ifndef REGS_H_
#define REGS_H_

#define		__RW				volatile
typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;
typedef 	__RW uint32_t 		registro_t;  //!< defino un tipo 'registro'.


// REGISTROS -------------------------------------------------------------------------------------------------------------
#define		PINSEL		( ( registro_t  * ) 0x4002C000UL )		//!< Direccion de inicio de los registros PINSEL
#define		PINMODE		( ( registro_t  * ) 0x4002C040UL )		//!< Direccion de inicio de los registros de modo de los pines del GPIO
#define		GPIO		( ( registro_t  * ) 0x2009C000UL )		//!< Direccion de inicio de los registros de GPIOs

//  NVIC -----------------------------------------------------------------------------------------------------------------
#define		NVIC_EINT3	21
// Nested Vectored Interrupt Controller (NVIC)
// 0xE000E100UL : Direccion de inicio de los registros de habilitación (set) de interrupciones en el NVIC:
#define		ISER		( ( registro_t  * ) 0xE000E100UL )
// 0xE000E180UL : Direccion de inicio de los registros de deshabilitacion (clear) de interrupciones en el NVIC:
#define		ICER		( ( registro_t  * ) 0xE000E180UL )

// Registros ISER:
#define		ISER0		ISER[0]
#define		ISER1		ISER[1]

// Registros ICER:
#define		ICER0		ICER[0]
#define		ICER1		ICER[1]

//  Power Control ----------------------------------------------------------------------------------------------------------
//  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
// 0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
#define 	PCONP	(* ( ( registro_t  * ) 0x400FC0C4UL ))

//  Peripheral Clock Selection ----------------------------------------------------------------------------------------------
// Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
// 0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
#define		PCLKSEL		( ( registro_t  * ) 0x400FC1A8UL )
// Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]

//  Interrupciones Externas  ------------------------------------------------------------------------------------------------
#define		EXTINT 		( * ( ( registro_t  * ) 0x400FC140UL ) )
	#define		EINT0		0
	#define		EINT1		1
	#define		EINT2		2
	#define		EINT3		3

#define		EXTMODE 	( * ( ( registro_t  * ) 0x400FC148UL ) )
	#define		EXTMODE0	0
	#define		EXTMODE1	1
	#define		EXTMODE2	2
	#define		EXTMODE3	3
#define		EXTPOLAR 	( * ( ( registro_t  * ) 0x400FC14CUL ) )
	#define		EXTPOLAR0	0
	#define		EXTPOLAR1	1
	#define		EXTPOLAR2	2
	#define		EXTPOLAR3	3

#endif /* REGS_H_ */
