#include "led.h"

void led_init()
{
	SET_BIT(DDRB, 7);
}

void led_on()
{
	SET_BIT(PORTB, 7);
}

void led_of()
{
	CLR_BIT(PORTB, 7);
}