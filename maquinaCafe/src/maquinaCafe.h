
#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

#include "RegsLPC1769.h"

#define MAQUINA_EN_STAND_BY 0
#define MAQUINA_ESPERANDO_MONEDAS 1
#define MAQUINA_SIRVIENDO 2
#define MAQUINA_DEVOLVIENDO_MONEDAS 3

#define TIEMPO_MONEDAS 100
#define TIEMPO_MONEDAS_EXTENSION 100
#define MAX_MONEDAS 3
