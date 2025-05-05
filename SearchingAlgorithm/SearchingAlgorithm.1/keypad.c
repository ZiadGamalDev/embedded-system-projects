#include "keypad.h"

void keypad_init()
{
	DDRC |= 0b00111100;
	PORTD |= 0b11101000;
}

char keypad_read(void)
{
	CLR_BIT(PORTC, 2);
	if (!GET_BIT(PIND, 3)) return '+';
	if (!GET_BIT(PIND, 5)) return '=';
	if (!GET_BIT(PIND, 6)) return '0';
	if (!GET_BIT(PIND, 7)) return '&';
	
	SET_BIT(PORTC, 2);
	CLR_BIT(PORTC, 3);
	if (!GET_BIT(PIND, 3)) return '-';
	if (!GET_BIT(PIND, 5)) return '3';
	if (!GET_BIT(PIND, 6)) return '2';
	if (!GET_BIT(PIND, 7)) return '1';

	SET_BIT(PORTC, 3);
	CLR_BIT(PORTC, 4);
	if (!GET_BIT(PIND, 3)) return '*';
	if (!GET_BIT(PIND, 5)) return '6';
	if (!GET_BIT(PIND, 6)) return '5';
	if (!GET_BIT(PIND, 7)) return '4';
	
	SET_BIT(PORTC, 4);
	CLR_BIT(PORTC, 5);
	if (!GET_BIT(PIND, 3)) return '/';
	if (!GET_BIT(PIND, 5)) return '9';
	if (!GET_BIT(PIND, 6)) return '8';
	if (!GET_BIT(PIND, 7)) return '7';
	
	return '\0';
}