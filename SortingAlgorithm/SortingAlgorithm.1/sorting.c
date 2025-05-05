#include "sorting.h"

void sort_init()
{
	for (int i = 0; i < Size; i++)
	{
		numbers[i] = 0;
	}
	pos = 0;
}

void input_numbers()
{
	LCD_string("Enter numbers: ");
	LCD_gotoxy(1, 0);
	while (1)
	{
		char key = keypad_get_value();
		if (key >= '0' && key <= '9')
		{
			LCD_char(key);
			numbers[pos] = numbers[pos] * 10 + key - '0';
		}
		else if (key == '=')
		{
			LCD_string(", ");
			pos++;
		}
		else if (key == 'C')
		{
			pos++;
			return;
		}
		_delay_ms(200);
	}
}

void sort()
{
	for (int i = 0; i < pos; i++)
	{
		for (int j = i + 1; j < pos; j++)
		{
			if (numbers[i] > numbers[j])
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

void display_numbers()
{
	LCD_clear();
	for (int i = 0; i < pos; i++)
	{
		char str[4];
		sprintf(str, "%d", numbers[i]);
		LCD_string(str);
		LCD_string(", ");
	}	
	for (int i = 0; i < pos; i++)
	{
		disply_number(numbers[i]);
		_delay_ms(300);
	}
}