#include "seven_segment.h"

void seven_segment_init(void)
{
	SET_BIT(DDRA, 3);
	DDRB |= 0b00010111;
}

void seven_segment_display(int digit)
{
	digit %= 10;
	PORTB &= 0b11101000;
	PORTB |= (((digit & 0b00001000) << 1) | (digit & 0b00000111));
}