#include "searching.h"

// 1 3 5 0 2 1 -1 0 0 0 0 0 0
// 0

void searching_init()
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] = 0;
		positions[i] = -1;
	}
	target = pos = 0;
}

void input_numbers()
{
	LCD_string("Enter numbers: ");
	LCD_gotoxy(1, 0);
	int mx = 0;
	while (1)
	{
		char key = keypad_read();
		if (key >= '0' && key <= '9')
		{
			LCD_char(key);
			numbers[pos] = numbers[pos] * 10 + (key - '0');
			mx++;
		}
		else if (key == '+')
		{
			pos++;
			LCD_string(", ");
		}
		else if (key == '&' || mx == 16)
		{
			numbers[pos + 1] = -1;
			_delay_ms(200);
			return;
		}
		_delay_ms(200);
	}
}

void input_target()
{
	LCD_clear();
	LCD_string("Enter target: ");
	while (1)
	{
		char key = keypad_read();
		if (key >= '0' && key <= '9')
		{
			LCD_char(key);
			target = target * 10 + key - '0';
		}
		if (key == '&')
		{
			return;
		}
		_delay_ms(200);
	}
}

void search()
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == -1)
		{
			return;
		}
		if (target == numbers[i])
		{
			positions[j] = i;
			j++;
		}
	}
}

void leds_init()
{
	DDRA = 0b01110000;
	DDRB |= (1 << 7);
}

void leds_on(int i)
{
	switch(i)
	{
		case 0: SET_BIT(PORTA, 4); return;
		case 1: SET_BIT(PORTA, 5); return;
		case 2: SET_BIT(PORTA, 6); return;
		case 3: SET_BIT(PORTB, 7); return;
	}
}

void leds_of()
{
	CLR_BIT(PORTA, 4);
	CLR_BIT(PORTA, 5);
	CLR_BIT(PORTA, 6);
	CLR_BIT(PORTB, 7);
}

// positions => 0 2 5 15
// 0 => 0000
// 2 => 0010
// 5 => 0101
// 16 => 1111
	// test
	// 	positions[0] = 0;
	// 	positions[1] = 2;
	// 	positions[2] = 5;
	// 	positions[3] = 15;
	// 	positions[4] = -1;

void display_positions()
{
	seven_segment_init();
	LCD_clear();
	LCD_string("Positions...");
	
	for (int i = 0; i < size; i++)
	{
		int num = positions[i];
		if (num == -1)return;
		
		seven_segment_display(num);		//display 7-segment
		
		for (int j = 0; j < 4; j++)		//display leds
		{
			if (num % 2 != 0)
			{
				leds_on(j);
			}
			num /= 2;
		}
		
		_delay_ms(1000);
		leds_of();
	}
}