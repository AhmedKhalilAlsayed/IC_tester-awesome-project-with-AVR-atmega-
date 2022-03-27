/*
 * DIO_IC_PINS_interface.h
 *
 *  Created on: Dec 25, 2021
 *      Author: Mega Store
 */

#ifndef DIO_IC_PINS_INTERFACE_H_
#define DIO_IC_PINS_INTERFACE_H_


#define PORT 1
#define DDR  0

#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW  0

void SET_IC_NUM_OF_PINS(u8 PINS);

u8 GET_IC_PIN(u8 IC_PIN_ID);

void SET_IC_PIN_DIREC(u8 IC_PIN_ID, u8 VALUE);

void SET_IC_PIN_VALUE(u8 IC_PIN_ID, u8 VALUE);


#endif /* DIO_IC_PINS_INTERFACE_H_ */
