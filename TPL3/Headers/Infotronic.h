#include "Oscilador.h"
#include "RegsLPC1769.h"

#ifndef KIT_INFO2_H_
#define KIT_INFO2_H_

#define  ON		1
#define  OFF 	0

// TPL2-B-INIC.c
void Inicializar ( void );
void InitPLL ( void );
void InicSysTick ( void );
void InitExpansion(void);


// TPL2-B-FW-CONFIG.c
void SetPINSEL ( uint8_t , uint8_t , uint8_t );
void SetMODE ( uint8_t , uint8_t , uint8_t );

// TPL2-B-FW-GPIO.c
void SetDIR( uint8_t ,uint8_t ,uint8_t );
void SetPIN( uint8_t , uint8_t , uint8_t );
uint8_t GetPIN( uint8_t , uint8_t , uint8_t );

//Identificación de los puertos de expansion:
#define EXPANSION0		PORT2,7
    #define 	LED1        EXPANSION0 	// PLACA EXPANSION 1
    #define 	DIG1        EXPANSION0	// PLACA EXPANSION 2
    #define 	BCD_A       EXPANSION0	// PLACA EXPANSION 3
#define EXPANSION1		PORT1,29
    #define 	LED2        EXPANSION1	// PLACA EXPANSION 1
    #define 	DIG2        EXPANSION1	// PLACA EXPANSION 2
    #define		BCD_B       EXPANSION1	// PLACA EXPANSION 3
#define EXPANSION2		PORT4,28
    #define 	LED3        EXPANSION2	// PLACA EXPANSION 1
    #define 	DIG3        EXPANSION2	// PLACA EXPANSION 2
    #define 	BCD_C       EXPANSION2	// PLACA EXPANSION 3
#define EXPANSION3		PORT1,23
    #define 	LED4        EXPANSION3	// PLACA EXPANSION 1
    #define 	DIG4        EXPANSION3	// PLACA EXPANSION 2
    #define 	BCD_D       EXPANSION3	// PLACA EXPANSION 3
#define EXPANSION4		PORT1,20
    #define 	LED5        EXPANSION4	// PLACA EXPANSION 1
    #define 	DIG5        EXPANSION4	// PLACA EXPANSION 2
    #define 	seg_DP      EXPANSION4	// PLACA EXPANSION 3
#define EXPANSION5		PORT0,19
    #define 	LED6        EXPANSION5	// PLACA EXPANSION 1
    #define 	DIG6        EXPANSION5	// PLACA EXPANSION 2
    #define 	CLK         EXPANSION5	// PLACA EXPANSION 3
#define EXPANSION6		PORT3,26
    #define 	LED7        EXPANSION6	// PLACA EXPANSION 1
    #define 	seg_a       EXPANSION6	// PLACA EXPANSION 2
    #define 	RST         EXPANSION6	// PLACA EXPANSION 3
#define EXPANSION7		PORT1,25
    #define 	LED8        EXPANSION7	// PLACA EXPANSION 1
    #define 	FILA_0      EXPANSION7	// PLACA EXPANSION 3
#define EXPANSION8		PORT1,22
    #define 	DIP1_1      EXPANSION8	// PLACA EXPANSION 1
    #define 	FILA_1      EXPANSION8	// PLACA EXPANSION 3
#define EXPANSION9		PORT1,19
    #define 	DIP1_2      EXPANSION9	// PLACA EXPANSION 1
    #define 	seg_dp      EXPANSION9	// PLACA EXPANSION 2
    #define 	FILA_2      EXPANSION9	// PLACA EXPANSION 3

#define EXPANSION10		PORT0,20
   #define 		DIP1_3      EXPANSION10	// PLACA EXPANSION 1
   #define 		seg_g       EXPANSION10	// PLACA EXPANSION 2
   #define 		FILA_3      EXPANSION10	// PLACA EXPANSION 3
#define EXPANSION11		PORT3,25
   #define 		DIP1_4      EXPANSION11	// PLACA EXPANSION 1
   #define 		seg_f       EXPANSION11	// PLACA EXPANSION 2
   #define 		COL_0       EXPANSION11	// PLACA EXPANSION 3
#define EXPANSION12		PORT1,27
   #define 		DIP1_5      EXPANSION12	// PLACA EXPANSION 1
   #define 		seg_e       EXPANSION12	// PLACA EXPANSION 2
   #define 		COL_1       EXPANSION12	// PLACA EXPANSION 3
#define EXPANSION13		PORT1,24
   #define 		DIP1_6      EXPANSION13	// PLACA EXPANSION 1
   #define 		seg_d       EXPANSION13	// PLACA EXPANSION 2
#define EXPANSION14		PORT1,21
   #define 		DIP1_7      EXPANSION14	// PLACA EXPANSION 1
   #define 		seg_c       EXPANSION14	// PLACA EXPANSION 2
#define EXPANSION15		PORT1,18
   #define 		DIP1_8      EXPANSION15// PLACA EXPANSION 1
   #define 		seg_b       EXPANSION15// PLACA EXPANSION 2

#define EXPANSION16		PORT1,31
#define EXPANSION17		PORT0,24
#define EXPANSION18		PORT0,25
#define EXPANSION19		PORT0,17
#define EXPANSION20		PORT1,31
#define EXPANSION21		PORT0,22
#define EXPANSION22		PORT0,15

#define EXPANSION23		PORT0,16
   	#define 	DIP2_3      EXPANSION23// PLACA EXPANSION 1
#define EXPANSION24		EXPANSION23
	#define 	DIP2_1      EXPANSION23// PLACA EXPANSION 1
#define EXPANSION25		PORT2,12
    #define 	DIP2_2      EXPANSION25// PLACA EXPANSION 1

//#define EXPANSION26		PORT1,31
//#define EXPANSION27		PORT1,31


#endif /* KIT_INFO2_H_ */
