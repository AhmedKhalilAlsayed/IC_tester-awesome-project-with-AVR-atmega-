#include "newTypes.h"

#include <mega32a.h>

#include "DIO_IC_PINS_interface.h"
#include "DIO_IC_PINS_config.h"

// shrtcts functions

/*
 * IC_PINS   -> total number of pins
 * IC_PIN_ID -> number of PIN from 1 to IC_PINS
 * #define PORT -> to select PORT REG
 * #define DDR -> to select DDR REG
 *
 * */

static u8 u8IC_PINS;
static u8 u8A_LEFT_PINS[] = LEFT_CHECK_PINS;
static u8 u8A_RIGHT_PINS[] = RIGHT_CHECK_PINS;

void SET_IC_NUM_OF_PINS(u8 PINS) {
	u8IC_PINS = PINS;
}

 static void SET_IC_PIN(u8 IC_PIN_ID, u8 REG) {

 u8 controllerPIN;

 // we will use left pins
 if (IC_PIN_ID <= (u8IC_PINS / 2)) {

 controllerPIN = u8A_LEFT_PINS[IC_PIN_ID - 1];

 } else {
 // we will use right pins

 controllerPIN = u8A_RIGHT_PINS[u8IC_PINS - IC_PIN_ID];

 }

 switch (controllerPIN / 8) {

 case 0: //PORTA
 if (REG == PORT)
 SET_BIT(PORTA, (controllerPIN % 8));
 else
 SET_BIT(DDRA, (controllerPIN % 8));
 break;

 case 1: //PORTB
 if (REG == PORT)
 SET_BIT(PORTB, (controllerPIN % 8));
 else
 SET_BIT(DDRB, (controllerPIN % 8));
 break;

 case 2: //PORTC
 if (REG == PORT)
 SET_BIT(PORTC, (controllerPIN % 8));
 else
 SET_BIT(DDRC, (controllerPIN % 8));
 break;

 case 3: //PORTD
 if (REG == PORT)
 SET_BIT(PORTD, (controllerPIN % 8));
 else
 SET_BIT(DDRD, (controllerPIN % 8));
 break;


 }

 }

 static void CLR_IC_PIN(u8 IC_PIN_ID, u8 REG) {

 u8 controllerPIN;

 // we will use left pins
 if (IC_PIN_ID <= (u8IC_PINS / 2)) {

 controllerPIN = u8A_LEFT_PINS[IC_PIN_ID - 1];

 } else {
 // we will use right pins

 controllerPIN = u8A_RIGHT_PINS[u8IC_PINS - IC_PIN_ID];

 }

 switch (controllerPIN / 8) {

 case 0: //PORTA
 if (REG == PORT)
 CLR_BIT(PORTA, (controllerPIN % 8));
 else
 CLR_BIT(DDRA, (controllerPIN % 8));
 break;

 case 1: //PORTB
 if (REG == PORT)
 CLR_BIT(PORTB, (controllerPIN % 8));
 else
 CLR_BIT(DDRB, (controllerPIN % 8));
 break;

 case 2: //PORTC
 if (REG == PORT)
 CLR_BIT(PORTC, (controllerPIN % 8));
 else
 CLR_BIT(DDRC, (controllerPIN % 8));
 break;

 case 3: //PORTD
 if (REG == PORT)
 CLR_BIT(PORTD, (controllerPIN % 8));
 else
 CLR_BIT(DDRD, (controllerPIN % 8));
 break;


 }
 }

 u8 GET_IC_PIN(u8 IC_PIN_ID) {

 u8 controllerPIN, bitValue;

 // we will use left pins
 if (IC_PIN_ID <= (u8IC_PINS / 2)) {

 controllerPIN = u8A_LEFT_PINS[IC_PIN_ID - 1];

 } else {
 // we will use right pins

 controllerPIN = u8A_RIGHT_PINS[u8IC_PINS - IC_PIN_ID];

 }

 switch (controllerPIN / 8) {

 case 0: //PORTA

 bitValue = GET_BIT(PINA, (controllerPIN % 8));

 break;

 case 1: //PORTB
 bitValue = GET_BIT(PINB, (controllerPIN % 8));
 break;

 case 2: //PORTC
 bitValue = GET_BIT(PINC, (controllerPIN % 8));
 break;

 case 3: //PORTD
 bitValue = GET_BIT(PIND, (controllerPIN % 8));
 break;


 }

 return bitValue;
 }


/*
static void SET_IC_PIN(u8 IC_PIN_ID, u8 REG) {
	if (IC_PIN_ID <= (u8IC_PINS / 2)) {
		if (IC_PIN_ID <= 8) {
			if (REG == PORT)
				SET_BIT(PORTA, (IC_PIN_ID - 1));
			else
				SET_BIT(DDRA, (IC_PIN_ID - 1));
		} else {
			if (REG == PORT)
				SET_BIT(PORTC, ((IC_PIN_ID - 8) - 1));
			else
				SET_BIT(DDRC, ((IC_PIN_ID - 8) - 1));
		}

	} else {
		if ((u8IC_PINS - IC_PIN_ID + 1) <= 8) {
			if (REG == PORT)
				SET_BIT(PORTB, ((u8IC_PINS - IC_PIN_ID + 1) - 1));
			else
				SET_BIT(DDRB, ((u8IC_PINS - IC_PIN_ID + 1) - 1));
		} else {
			if (REG == PORT)
				SET_BIT(PORTD, (((u8IC_PINS - IC_PIN_ID + 1) - 8) - 1));
			else
				SET_BIT(DDRD, (((u8IC_PINS - IC_PIN_ID + 1) - 8) - 1));
		}

	}
}

static void CLR_IC_PIN(u8 IC_PIN_ID, u8 REG) {
	if (IC_PIN_ID <= (u8IC_PINS / 2)) {
		if (IC_PIN_ID <= 8) {
			if (REG == PORT)
				CLR_BIT(PORTA, (IC_PIN_ID - 1));
			else
				CLR_BIT(DDRA, (IC_PIN_ID - 1));
		} else {
			if (REG == PORT)
				CLR_BIT(PORTC, ((IC_PIN_ID - 8) - 1));
			else
				CLR_BIT(DDRC, ((IC_PIN_ID - 8) - 1));
		}

	} else {
		if ((u8IC_PINS - IC_PIN_ID + 1) <= 8) {
			if (REG == PORT)
				CLR_BIT(PORTB, ((u8IC_PINS - IC_PIN_ID + 1) - 1));
			else
				CLR_BIT(DDRB, ((u8IC_PINS - IC_PIN_ID + 1) - 1));
		} else {
			if (REG == PORT)
				CLR_BIT(PORTD, (((u8IC_PINS - IC_PIN_ID + 1) - 8) - 1));
			else
				CLR_BIT(DDRD, (((u8IC_PINS - IC_PIN_ID + 1) - 8) - 1));
		}

	}
}

u8 GET_IC_PIN(u8 IC_PIN_ID) {
	u8 bitValue;
	if (IC_PIN_ID <= (u8IC_PINS / 2)) {
		if (IC_PIN_ID <= 8)
			bitValue = GET_BIT(PINA, (IC_PIN_ID - 1));
		else
			bitValue = GET_BIT(PINC, ((IC_PIN_ID - 8) - 1));
	} else {
		if ((u8IC_PINS - IC_PIN_ID + 1) <= 8)
			bitValue = GET_BIT(PINB, ((u8IC_PINS - IC_PIN_ID + 1) - 1));
		else
			bitValue = GET_BIT(PIND, (((u8IC_PINS - IC_PIN_ID + 1) - 8) - 1));
	}

	return bitValue;
}
*/


 void SET_IC_PIN_DIREC(u8 IC_PIN_ID, u8 VALUE) {
	if (VALUE)
		SET_IC_PIN(IC_PIN_ID, DDR);
	else {
		CLR_IC_PIN(IC_PIN_ID, DDR);
		/*pullup*/
		SET_IC_PIN(IC_PIN_ID, PORT);
	}
}

void SET_IC_PIN_VALUE(u8 IC_PIN_ID, u8 VALUE) {
	if (VALUE)
		SET_IC_PIN(IC_PIN_ID, PORT);
	else
		CLR_IC_PIN(IC_PIN_ID, PORT);
}
//end shrtcts functions
