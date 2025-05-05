#include "searching.h"

int main(void)
{
    // Initiation:
	keypad_init();	
	leds_init();
	LCD_init();
	
	input_numbers();
	input_target();
	search();
	display_positions();
	
    while (1) 
    {
    }
}

