#include "sorting.h"

int main(void)
{
	keypad_init();	
	LCD_init();
	sort_init();
 	seven_segment_init();
	input_numbers();
	sort();
	display_numbers();

    while (1) 
    {
    }
}

