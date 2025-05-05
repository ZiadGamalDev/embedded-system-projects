#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include "Registers.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#define LCD_Command_Dir		DDRA
#define LCD_Command_Port	PORTA
#define LCD_Data_Dir		DDRB
#define LCD_Data_Port		PORTB
#define SET_CURSOR_LOCATION	0x80
#define RS 3
#define EN 2

void LCD_init(void);
void LCD_command(unsigned char cmd);
void LCD_char(unsigned char chr);
void LCD_string(char* str);
void LCD_clear(void);
void LCD_gotoxy(unsigned char row, unsigned char col);

#endif /* LCD_H_ */