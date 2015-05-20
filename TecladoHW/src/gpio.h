/*
 * gpio.h
 *
 *  Created on: 20/5/2015
 *      Author: dvinazza
 */

#ifndef GPIO_H_
#define GPIO_H_

//no se por que no me lo toma
typedef 	unsigned char 		uint8_t;

void setPINSEL (uint8_t puerto, uint8_t pin, uint8_t modo);
void setDIR(registro* puerto,uint8_t pin,uint8_t direccion);
void setPIN(registro* puerto,uint8_t pin,uint8_t estado);
uint8_t getPIN(registro* puerto,uint8_t pin);

#endif /* GPIO_H_ */
