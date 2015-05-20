/*
 * gpio.h
 *
 *  Created on: 20/5/2015
 *      Author: dvinazza
 */

#ifndef GPIO_H_
#define GPIO_H_

void SetPINSEL (uint8_t puerto, uint8_t pin, uint8_t modo);
void SetDIR(registro* puerto,uint8_t pin,uint8_t direccion);
void SetPIN(registro* puerto,uint8_t pin,uint8_t estado);
uint8_t GetPIN(registro* puerto,uint8_t pin);

#endif /* GPIO_H_ */
