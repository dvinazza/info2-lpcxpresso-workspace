/**
 \file		: KitInfo2FW_RTC.h
 \brief     : Header de rutinas de RTC
 \details   :
 \author    : GOS
 \date 	    : 2014.06.08
*/

#ifndef KITINFO2FW_RTC_H_
#define KITINFO2FW_RTC_H_

#include "RegsLPC1769.h"


#define RTC_INTERRUPCION_SEG		0
#define RTC_INTERRUPCION_MIN		1
#define RTC_INTERRUPCION_HORA		2
#define RTC_INTERRUPCION_DIAMES		3
#define RTC_INTERRUPCION_DIASEM		4
#define RTC_INTERRUPCION_DIAANIO	5
#define RTC_INTERRUPCION_MES		6
#define RTC_INTERRUPCION_ANIO		7

typedef struct {
	uint32_t seg;
	uint32_t min;
	uint32_t hora;
	uint32_t dia_mes;
	uint32_t dia_semana;
	uint32_t dia_anio;
	uint32_t mes;
	uint32_t anio;
} RTC_HoraFecha;

// Prototipos
void Inic_RTC(void);
void RTC_HabilitaInterrupcion(uint32_t);
void RTC_SetHoraFecha(RTC_HoraFecha*);
void RTC_GetHoraFecha(RTC_HoraFecha*);

#endif /* KITINFO2FW_RTC_H_ */
