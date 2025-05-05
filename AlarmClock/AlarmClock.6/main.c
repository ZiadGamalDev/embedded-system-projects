#include "Alarm_Clock.h"

int main(void)
{
	// Initiation:
	keypad_init();
	LCD_init();
	alarm_init();
	clock_init();
	timer0_init();
	led_init();
	
 	// Calling:
	clock_adjust();
	timer0_setCallback(every_second);
	
    while (1)
    {
	    buttons_checking();
    }
}

