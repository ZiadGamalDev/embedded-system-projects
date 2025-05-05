#include "Alarm_Clock.h"

void time_init(Time* time)
{
	time->hour = time->minute = time->second = time->isPM = 0;
	strcpy(time->msgTime, "00:00:00 AM");
}

int time_read()
{
	int result = 0, digits = 2;
	while(digits)
	{
		char key = keypad_read();
		if (key >= '0' && key <= '9')
		{
			LCD_char(key);
			result = result * 10 + key - '0';
			digits--;
		}
		_delay_ms(30);
	}
	return result;
}

char time_adjust(Time* time) {
	LCD_gotoxy(1, 0);
	LCD_string("HH : MM : SS");
	LCD_gotoxy(1, 0);
	time->hour = time_read();
	time->isPM = time->hour > 11;
	LCD_gotoxy(1, 5);
	time->minute = time_read();
	LCD_gotoxy(1, 10);
	time->second = time_read();
	LCD_clear();
	return (time->hour > -1 && time->hour < 24 && time->minute > -1 && time->minute < 60 && time->second > -1 && time->second < 60);
}

void time_display(Time* time)
{	
	sprintf(time->msgTime, "%02d:%02d:%02d AM", time->hour, time->minute, time->second);
	if (time->isPM)time->msgTime[9] = 'P';
	LCD_string(time->msgTime);
}

//////////////////////////////////////////////////////////////////////////////

void alarm_init()
{
	time_init(&alarmTime);
}

void clock_init()
{
	time_init(&clockTime);
}

void alarm_adjust()
{
	while (1)
	{
		LCD_clear();
		LCD_string("Set Alarm Time:");
		if (time_adjust(&alarmTime))
		{
			LCD_string("Alarm Time Set!");
			_delay_ms(300);
			return;
		}
		LCD_string("Invalid Alarm Time!");
		_delay_ms(300);
	}
}

void clock_adjust()
{
	while (1)
	{
		LCD_clear();
		LCD_string("Set Clock Time:");
		if (time_adjust(&clockTime))
		{
			LCD_string("Clock Time Set!");
			_delay_ms(300);
			return;
		}
		LCD_string("Invalid Clock Time!");
		_delay_ms(300);
	}
}

void alarm_display()
{
	LCD_gotoxy(2, 0);
	LCD_string("Alarm: ");
	time_display(&alarmTime);
}

void clock_display()
{
	LCD_clear();
	LCD_string("Clock: ");
	time_display(&clockTime);
}

void clock_update()
{
	clockTime.second++;
	if (clockTime.second > 59)
	{
		clockTime.second = 0;
		clockTime.minute++;
		if (clockTime.minute > 59)
		{
			clockTime.minute = 0;
			clockTime.hour++;
			if (clockTime.hour > 23)
			{
				clockTime.hour = 0;
			}
			clockTime.isPM = clockTime.hour > 11;
		}
	}
}

void alarm_mode()
{
	alarm_adjust();
	LCD_gotoxy(2, 0);
	LCD_string("Alarm mode...");
	while(1)
	{
		char key = keypad_read();
		if (key == '*') return;
		_delay_ms(30);
	}
}

//////////////////////////////////////////////////////////////////////////////

void buttons_checking()
{
	char key = keypad_read();
	switch (key)
	{
		case '/':
		timer0_stop();
		clock_adjust();
		timer0_start();
		break;
		case '*':
		timer0_stop();
		alarm_mode();
		timer0_start();
		break;
		case '-':
		timer0_stop();
		led_of();
		buzzer_of();
		timer0_start();
	}
	_delay_ms(30);
}

int tick = 0;
void every_second()
{
	tick++;
	if (tick == NOMBER_OF_OVERFLOWS)
	{
		clock_update();
		clock_display();
		alarm_display();
		if (!strcmp(alarmTime.msgTime, clockTime.msgTime))
		{
			led_on();
			buzzer_on();
		}
		tick = 0;
	}
}