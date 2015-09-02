/*
 * lcd.c
 *
 *  Created on: 24/09/2013
 *      Author: gabriel
 *
 * Driver de display:
 * Tiene un problema de tiempos ya que no se ejecuta bién sin el debugger.
 * Adecuar las rutinas de la cátedra a mis inicializaciones
 *
 */
/*
 * lcd.c
 *
 *  Created on: 24/09/2013
 *      Author: gabriel
 *
 * Driver de display:
 * Tiene un problema de tiempos ya que no se ejecuta bién sin el debugger.
 * Adecuar las rutinas de la cátedra a mis inicializaciones
 *
 */
#include "lcd.h"

extern volatile unsigned char Buffer_LCD[];
extern volatile unsigned int inxInLCD;
extern volatile unsigned int inxOutLCD;
extern volatile unsigned int cantidadColaLCD;
extern volatile int DemoraLCD;

uint8_t entero_ascii[6];
extern uint8_t bufferLCD[];
extern uint8_t ptrLecturaLCD;
extern uint8_t ptrEscrituraLCD;


/**
 * void LCDWaitLong(uint8_t ciclos)
 * Demora larga por SW
 *
 * */
void LCDWaitLong(uint16_t ciclos)
{
	uint16_t i;
	uint16_t x;

	for(i=0;i<ciclos;i++)
	{
		for(x = 0;x < 0x4FF6;x++);
	}
}

/**
 * void LCDWaitShort(uint8_t ciclos)
 * Demora corta por SW
 *
 * */
void LCDWaitShort(uint8_t ciclos)
{
	uint8_t i;
	uint16_t x;

	for(i=0;i<ciclos;i++)
	{
		for(x=0;x<0x9F6;x++);
	}
}


/**
 * void LCDDelay(uint16_t demora)
 * Demora medida por el tick
 *
 * */

void LCDDelay(uint16_t demora){

	DemoraLCD = demora;
	while(DemoraLCD);

}


/**
 * void LatchLcd(void)
 * Genera pulso de latch para LCD
 *
 * */
void LatchLcd(void){
	uint16_t i;

	SetPIN(LCD_E,ON);
	//LCDDelay(2);
	LCDWaitLong(15);
	for(i = 0; i < 120; i++);
	SetPIN(LCD_E,OFF);
}

/**
 * void Conversor(uint16_t valor_int)
 * Convierte un entero sin signo en ascii
 *
 * */
void Conversor(uint16_t valor_int){
	entero_ascii[4] = valor_int % 10 +48;
	valor_int /= 10;

	entero_ascii[3] = valor_int % 10 +48;
	valor_int /= 10;

	entero_ascii[2] = valor_int % 10 +48;
	valor_int /= 10;

	entero_ascii[1] = valor_int % 10 +48;
	entero_ascii[0] = valor_int /10 +48;

}

/**
 * void DisplayInt_lcd(uint16_t valor , uint8_t r , uint8_t p )
 * Escribe un entero en el LCD en la línea indicada por r
 * A partir de la posicion indicada por p
 *
 * */
void DisplayInt_lcd(uint16_t valor , uint8_t r , uint8_t p ){
	uint8_t i ;
	uint8_t flag_cero = 0;

	if( r )
        p = p + 0xc0 ;
	else
		p = p + 0x80 ;

	WComando8(p);
	Conversor(valor);
	for( i = 0 ; i < 5; i++ ){
		if(flag_cero == 0){
			if(entero_ascii[ i ] != '0'){
				flag_cero = 1;
				WDato(entero_ascii[ i ]);
			}
		}else{
			WDato(entero_ascii[ i ]);
		}

	}
}


/**
 *
 * void ImprimeLCD(void)
 * Escribe bufferLCD en LCD
  * Formato: 1er byte es la posición y luego el mensaje hasta encontrar '0'
 *
 * */
void ImprimeLCD(void){

	static uint8_t estado = 0;

	switch(estado){
	case IDLE:
		if(ptrLecturaLCD != ptrEscrituraLCD){
			estado = 1;
		}
		break;
	// Case 1 a case 3 escritura de comando
	case NIBLE1_CMD:
		SetPIN(LCD_RS,OFF);
		// Parte Alta del comando
		SetPIN(LCD_D4,((bufferLCD[ptrLecturaLCD] & 0x10) >> 4));
		SetPIN(LCD_D5,((bufferLCD[ptrLecturaLCD] & 0x20) >> 5));
		SetPIN(LCD_D6,((bufferLCD[ptrLecturaLCD] & 0x40) >> 6));
		SetPIN(LCD_D7,((bufferLCD[ptrLecturaLCD] & 0x80) >> 7));
		SetPIN(LCD_E,ON);
		DemoraLCD = 2;
		estado = 2;
		break;

	case NIBLE2_CMD:
		if(!DemoraLCD){
			SetPIN(LCD_E,OFF);
			// Parte Baja del comando
			SetPIN(LCD_D4,(bufferLCD[ptrLecturaLCD] & 0x01));
			SetPIN(LCD_D5,((bufferLCD[ptrLecturaLCD] & 0x02) >> 1));
			SetPIN(LCD_D6,((bufferLCD[ptrLecturaLCD] & 0x04) >> 2));
			SetPIN(LCD_D7,((bufferLCD[ptrLecturaLCD] & 0x08) >> 3));
			SetPIN(LCD_E,ON);
			DemoraLCD = 2;
			estado = 3;
		}else{}
		break;
	case LATCH_CMD:
		// No está entrando a este estado
		if(!DemoraLCD){
			SetPIN(LCD_E,OFF);
			DemoraLCD = 4;
			ptrLecturaLCD++;
			if(ptrLecturaLCD == TOPE_BUFFER_LCD){
				ptrLecturaLCD = 0;
			}
			estado = 4;
		}else{}
		break;
	// Case 4 a case 6 escribe posición
	case NIBLE1_POS:
		SetPIN(LCD_RS,OFF);
		// Parte Alta del comando
		SetPIN(LCD_D4,((bufferLCD[ptrLecturaLCD] & 0x10) >> 4));
		SetPIN(LCD_D5,((bufferLCD[ptrLecturaLCD] & 0x20) >> 5));
		SetPIN(LCD_D6,((bufferLCD[ptrLecturaLCD] & 0x40) >> 6));
		SetPIN(LCD_D7,((bufferLCD[ptrLecturaLCD] & 0x80) >> 7));
		SetPIN(LCD_E,ON);
		DemoraLCD = 1;
		estado = 5;
		break;
	case NIBLE2_POS:
		if(!DemoraLCD){
			SetPIN(LCD_E,OFF);
			// Parte Baja del comando
			SetPIN(LCD_D4,(bufferLCD[ptrLecturaLCD] & 0x01));
			SetPIN(LCD_D5,((bufferLCD[ptrLecturaLCD] & 0x02) >> 1));
			SetPIN(LCD_D6,((bufferLCD[ptrLecturaLCD] & 0x04) >> 2));
			SetPIN(LCD_D7,((bufferLCD[ptrLecturaLCD] & 0x08) >> 3));
			SetPIN(LCD_E,ON);
			DemoraLCD = 1;
			estado = 6;
		}else{}
		break;
	case LATCH_POS:
		if(!DemoraLCD){
			SetPIN(LCD_E,OFF);
			DemoraLCD = 4;
			ptrLecturaLCD++;
			if(ptrLecturaLCD == TOPE_BUFFER_LCD){
				ptrLecturaLCD = 0;
			}
			estado = 7;
		}else{}
		break;
	// Escribe datos
	case NIBLE1_DATO:
		if(bufferLCD[ptrLecturaLCD] == 0x00){
			estado = 0;			// FIN
			ptrLecturaLCD++;
			if(ptrLecturaLCD == TOPE_BUFFER_LCD){
				ptrLecturaLCD = 0;
			}
			//bufferLCD[0] = 0x00;
		}else{
			SetPIN(LCD_RS,ON);
			// Parte Alta del comando
			SetPIN(LCD_D4,((bufferLCD[ptrLecturaLCD] & 0x10) >> 4));
			SetPIN(LCD_D5,((bufferLCD[ptrLecturaLCD] & 0x20) >> 5));
			SetPIN(LCD_D6,((bufferLCD[ptrLecturaLCD] & 0x40) >> 6));
			SetPIN(LCD_D7,((bufferLCD[ptrLecturaLCD] & 0x80) >> 7));
			SetPIN(LCD_E,ON);
			DemoraLCD = 1;
			estado = 8;
		}
		break;
	case NIBLE2_DATO:
		if(!DemoraLCD){
			SetPIN(LCD_E,OFF);
			// Parte Baja del comando
			SetPIN(LCD_D4,(bufferLCD[ptrLecturaLCD] & 0x01));
			SetPIN(LCD_D5,((bufferLCD[ptrLecturaLCD] & 0x02) >> 1));
			SetPIN(LCD_D6,((bufferLCD[ptrLecturaLCD] & 0x04) >> 2));
			SetPIN(LCD_D7,((bufferLCD[ptrLecturaLCD] & 0x08) >> 3));
			SetPIN(LCD_E,ON);
			DemoraLCD = 1;
			estado = 9;
		}else{}
		break;

	case LATCH_DATO:
		if(!DemoraLCD){
			SetPIN(LCD_E,OFF);
			DemoraLCD = 1;
			ptrLecturaLCD++;
			if(ptrLecturaLCD == TOPE_BUFFER_LCD){
				ptrLecturaLCD = 0;
			}
			estado = 7;
		}else{}
		break;

	default:
		break;
	}

}



/**
 *
 * void Push_BufferLCD(char cmd, char *msg , char r , char p ){
 * Escribe una cadena en el LCD en la línea indicada por r
 * A partir de la posicion indicada por p
 * Escribe datos en bufferLCD
 * Formato: 1er byte es el comando, el segundo la posición y luego el mensaje hasta encontrar '0'
 *
 * */
void Push_BufferLCD(char cmd, char *msg , char r , char p ){
	unsigned char j;

	bufferLCD[ptrEscrituraLCD] = cmd;
	ptrEscrituraLCD++;
	if(ptrEscrituraLCD == TOPE_BUFFER_LCD){
		ptrEscrituraLCD = 0;
	}

	if( r ){
        p = p | 0xc0 ;
	}else{
		p = p | 0x80 ;
	}

	bufferLCD[ptrEscrituraLCD] = p;
	ptrEscrituraLCD++;
	if(ptrEscrituraLCD == TOPE_BUFFER_LCD){
		ptrEscrituraLCD = 0;
	}

	for( j = 0 ; msg[j] != 0x00 ; j++ ){
		bufferLCD[ptrEscrituraLCD] = msg[j];
		ptrEscrituraLCD++;
		if(ptrEscrituraLCD == TOPE_BUFFER_LCD){
			ptrEscrituraLCD = 0;
		}
	}

	ptrEscrituraLCD++;
		if(ptrEscrituraLCD == TOPE_BUFFER_LCD){
			ptrEscrituraLCD = 0;
		}

	bufferLCD[ptrEscrituraLCD] = 0;
}


/**
 * void Display_lcd( char *msg , char r , char p )
 * Escribe una cadena en el LCD en la línea indicada por r
 * A partir de la posicion indicada por p
 *
 * */
void Display_lcd( char *msg , char r , char p ){
	unsigned char i ;

	if( r )
        p = p + 0xc0 ;
	else
		p = p + 0x80 ;

	WComando8(p);
	for( i = 0 ; msg[ i ] != '\0' ; i++ )
		WDato(msg[ i ]);

}



/**
 * void Inic_PinesLCD(void)
 * Configura pines para manejo de LCD interfaz de 4 bits
 *
 * */
void Inic_PinesLCD(void){
	SetPINSEL(LCD_RS,PINSEL_GPIO);
	SetDIR(LCD_RS,SALIDA);
	SetMODE_OD(LCD_RS,OPEN_DRAIN);
	SetPIN(LCD_RS,OFF);

	SetPINSEL(LCD_E,PINSEL_GPIO);
	SetDIR(LCD_E,SALIDA);
	SetMODE_OD(LCD_E,OPEN_DRAIN);
	SetPIN(LCD_E,OFF);

	SetPINSEL(LCD_D4,PINSEL_GPIO);
	SetDIR(LCD_D4,SALIDA);
	SetMODE_OD(LCD_D4,OPEN_DRAIN);
	SetPIN(LCD_D4,OFF);

	SetPINSEL(LCD_D5,PINSEL_GPIO);
	SetDIR(LCD_D5,SALIDA);
	SetMODE_OD(LCD_D5,OPEN_DRAIN);
	SetPIN(LCD_D5,OFF);

	SetPINSEL(LCD_D6,PINSEL_GPIO);
	SetDIR(LCD_D6,SALIDA);
	SetMODE_OD(LCD_D6,OPEN_DRAIN);
	SetPIN(LCD_D6,OFF);

	SetPINSEL(LCD_D7,PINSEL_GPIO);
	SetDIR(LCD_D7,SALIDA);
	SetMODE_OD(LCD_D7,OPEN_DRAIN);
	SetPIN(LCD_D7,OFF);
}

/**
 * void WComando8(uint8_t comando)
 * Escribe un comando al LCD luego de inicialización
 * No usa BF
 *
 * */
void WComando8(uint8_t comando){
	SetPIN(LCD_RS,OFF);
	// Parte Alta del comando
	SetPIN(LCD_D4,((comando & 0x10) >> 4));
	SetPIN(LCD_D5,((comando & 0x20) >> 5));
	SetPIN(LCD_D6,((comando & 0x40) >> 6));
	SetPIN(LCD_D7,((comando & 0x80) >> 7));
	LatchLcd();
	LCDDelay(2);
	//LCDWaitLong(15);
	// Parte Baja del comando
	SetPIN(LCD_D4,(comando & 0x01));
	SetPIN(LCD_D5,((comando & 0x02) >> 1));
	SetPIN(LCD_D6,((comando & 0x04) >> 2));
	SetPIN(LCD_D7,((comando & 0x08) >> 3));
	LatchLcd();
	LCDDelay(4);
	//LCDWaitLong(30);
}

/**
 * void WComando4(uint8_t comando)
 * Escribe un comando al LCD en el proceso de inicialización
 * No usa BF
 *
 * */
void WComando4(uint8_t comando){
	SetPIN(LCD_RS,OFF);
	SetPIN(LCD_D4,((comando & 0x10) >> 4));
	SetPIN(LCD_D5,((comando & 0x20) >> 5));
	SetPIN(LCD_D6,((comando & 0x40) >> 6));
	SetPIN(LCD_D7,((comando & 0x80) >> 7));
	LatchLcd();
	LCDDelay(2);
	//LCDWaitLong(15);
}

/**
 * void WDato (uint8_t dato)
 * Escribe un dato al LCD en interfaz de 4 bits
 * No usa BF
 *
 * */
void WDato (uint8_t dato)
{
	SetPIN(LCD_RS,ON);
	// Parte Alta del comando
	SetPIN(LCD_D4,((dato & 0x10) >> 4));
	SetPIN(LCD_D5,((dato & 0x20) >> 5));
	SetPIN(LCD_D6,((dato & 0x40) >> 6));
	SetPIN(LCD_D7,((dato & 0x80) >> 7));
	LatchLcd();
	LCDDelay(2);
	//LCDWaitLong(15);
	// Parte Baja del comando
	SetPIN(LCD_D4,(dato & 0x01));
	SetPIN(LCD_D5,((dato & 0x02) >> 1));
	SetPIN(LCD_D6,((dato & 0x04) >> 2));
	SetPIN(LCD_D7,((dato & 0x08) >> 3));
	LatchLcd();
	LCDDelay(2);
	//LCDWaitLong(15);
}

/**
 * void WString (uint8_t *ptr)
 * Escribe cadena de caracteres al LCD
 * No posiciona
 *
 * */
void WString (uint8_t *ptr)
{
	while(*ptr != 0x00)
	{
		WDato(*ptr++);
	}
}



/**
 * void Inic_LCD(void)
 * Inicializa LCD en modo de 4 bits de datos
 * No usa BF
 *
 * */
void Inic_LCD(void)
{
	Inic_PinesLCD();		// Configura pines de interfaz con LCD
	LCDDelay(400);			// Demora inicial
	//LCDWaitLong(400);

	LCDWaitLong(15);		// Funsion Set para 4 bits
	WComando4(0x30);
	LCDWaitLong(15);
	WComando4(0x30);
	LCDWaitShort(6);
	WComando4(0x30);
	LCDWaitShort(6);
	WComando4(0x20);		// 4 bits
	LCDWaitShort(3);
	WComando4(0x20);		// 4 bits
	LCDWaitShort(3);
	WComando4(0x80);		// Clear del LCD
	LCDWaitShort(12);
	WComando4(0x00);		// Display y cursos off
	LCDWaitShort(3);
	WComando4(0xC0);		// Display de dos lineas caractetes de 5x11
	LCDWaitShort(15);
	WComando8(LCD_CLEAR);	// Limpia LCd y va a Home

}
