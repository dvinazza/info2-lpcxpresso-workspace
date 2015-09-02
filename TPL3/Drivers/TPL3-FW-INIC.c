#include "TPL3.H"
#include "RegsLPC1769.h"

//puertos/pines comunes de los digitos
uint8_t auxDisplayPuertos[] = {2, 1, 4, 1, 1, 0};
uint8_t auxDisplayPines[] = {7, 29, 28, 23, 20};

void Inicializar ( void )
{
	InitPLL ( ) ;
	InicSysTick ( );
	InitExpansion();
}

void InicSysTick ( void )
{
	STRELOAD = ( STCALIB / 4) - 1;	// Recarga cada 2.5 ms
	STCURR = 0;	// Cargando con cero limpio y provoco el disparo de una intrrupcion
	// Habilito el conteo
	// Habilito interrupcion
	// Utilizamos Pclk
	STCTRL |=  ( ( 1 << ENABLE ) | ( 1 << TICKINT ) | ( 1 << CLKSOURCE ) );
}

void InitExpansion(void)
{

	//inicia los segmentos
	int puertos[] = {2, 1, 4, 1, 1, 0, 3, 1, 0, 3, 1, 1, 1, 1, -1};
	int pines[] = {7, 29, 28, 23, 20, 19, 26, 19, 20, 25, 17, 24, 21, 18};

	uint8_t aux=0;
	while ( puertos[aux] != -1) {
		SetPINSEL(puertos[aux], pines[aux], FUNCION_GPIO);
		SetDIR(puertos[aux], pines[aux],SALIDA);
		aux++;
	}

	//apago todos los displays
	for (aux = 0; aux < CANTIDAD_DIGITOS; aux++) {
		SetPIN(auxDisplayPuertos[aux], auxDisplayPines[aux], 0); }


	//inicia los switches
}
