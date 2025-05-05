#include "timer0.h"

void timer0_init()
{
	TCNT0 = 0;                // timer initial value
	TIMSK |= (1 << TOIE0);    // enable overflow interrupt
	TCCR0 = (1 << FOC0) | (1 << CS02) | (1 << CS00);
	sei();
}

void (*globalCallback)(void) = NULL_PTR;
void timer0_setCallback(void (*callback)(void))
{
	globalCallback = callback;
}

ISR(TIMER0_OVF_vect)
{
	if (globalCallback)
	{
		globalCallback();
	}
}

void timer0_start()
{
	// Set the prescaler to start the timer
	TCCR0 |= (1 << CS02) | (1 << CS00);
}

void timer0_stop()
{
	// Clear the prescaler to stop the timer
	TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
}
