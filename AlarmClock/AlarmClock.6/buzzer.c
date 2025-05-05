#include "buzzer.h"

void buzzer_init()
{
	SET_BIT(DDRC, 6);
}

void buzzer_on()
{
	SET_BIT(PORTC, 6);
}

void buzzer_of()
{
	CLR_BIT(PORTC, 6);
}