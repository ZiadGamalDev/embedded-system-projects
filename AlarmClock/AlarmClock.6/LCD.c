#include "LCD.h"

void LCD_init(void)
{
	SET_BIT(DDRA, 2);
	SET_BIT(DDRA, 3);
	SET_BIT(DDRB, 0);
	SET_BIT(DDRB, 1);
	SET_BIT(DDRB, 2);
	SET_BIT(DDRB, 4);
	
	_delay_ms(15);
	LCD_command(0x02);
	LCD_command(0x28);
	LCD_command(0x0c);
	LCD_command(0x01);
	LCD_command(0x80);
}

void LCD_command(unsigned char cmd)
{
	CLR_BIT(PORTA, 3);
	
	PORTB &= 0b11101000;
	unsigned char high = (cmd & 0xf0) >> 4;					//1111 0000		=>	 	//0000 1111
	unsigned char temp = ((high & 0b00001000) << 1) | (high & 0b00000111);			//0001 0111
	PORTB |= temp;
	
	CLR_BIT(PORTA, 2);
	SET_BIT(PORTA, 2);
	_delay_ms(1);
	CLR_BIT(PORTA, 2);
	
	
	PORTB &= 0b11101000;
	unsigned char low = cmd & 0x0f;
	unsigned char temp2 = ((low & 0b00001000) << 1) | (low & 0b00000111);
	PORTB |= temp2;
	
	CLR_BIT(PORTA, 2);
	SET_BIT(PORTA, 2);
	_delay_ms(1);
	CLR_BIT(PORTA, 2);

	_delay_ms(5);
}

void LCD_char(unsigned char chr)
{
	SET_BIT(PORTA, 3);
	
	PORTB &= 0b11101000;
	unsigned char high = (chr & 0xf0) >> 4;					//1111 0000		=>	 	//0000 1111
	unsigned char temp = ((high & 0b00001000) << 1) | (high & 0b00000111);			//0001 0111
	PORTB |= temp;
	
	CLR_BIT(PORTA, 2);
	SET_BIT(PORTA, 2);
	_delay_ms(1);
	CLR_BIT(PORTA, 2);
	
	
	PORTB &= 0b11101000;
	unsigned char low = chr & 0x0f;
	unsigned char temp2 = ((low & 0b00001000) << 1) | (low & 0b00000111);
	PORTB |= temp2;
	
	CLR_BIT(PORTA, 2);
	SET_BIT(PORTA, 2);
	_delay_ms(1);
	CLR_BIT(PORTA, 2);

	_delay_ms(5);

}

void LCD_string(char* str)
{
	for (int i = 0; str[i]; i++)
	{
		LCD_char(str[i]);
	}
}

void LCD_clear()
{
	LCD_command(0x01);
	_delay_ms(10);
}

void LCD_gotoxy(unsigned char row, unsigned char col)
{
	unsigned char address = 0;
	switch(row)
	{
		case 0:
		address = col;
		break;
		case 1:
		address = col + 0x40;
		break;
		case 2:
		address = col + 0x14;
		break;
		case 3:
		address = col + 0x54;
		break;
	}
	LCD_command(address | 0x80);
}
