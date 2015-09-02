/*
 * Entradas.h
 *
 *  Created on: 30/03/2013
 *      Author: Marcelo
 */

#ifndef ENTRADAS_H_
#define ENTRADAS_H_

	//---Aquí defino nombres de fantasía para identificar a cada uno de los bits de 'BufferEntradas'
	//---que a su vez representan las entradas digitales del HW. Qué bit corresponde a qué entrada queda
	//---definido en la función debounce().
	#define		TECLA_UP		(   (BufferEntradas)      & 0x01 )
	#define		TECLA_DOWN		( ( BufferEntradas >> 1 ) & 0x01 )
	//--------------------------------------------------------------

	#define		ACEPTAReSTADO	10		//arbitrario
	#define		ENTRADAS		2		//KEY4_RC y KEY3_RC

	/** -------------------------------------------------------------------------------------
	 * Prototipos
	 */
	void Debounce(void);

#endif /* ENTRADAS_H_ */
