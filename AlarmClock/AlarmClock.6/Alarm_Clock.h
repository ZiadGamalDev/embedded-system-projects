#ifndef ALARM_CLOCK_H_
#define ALARM_CLOCK_H_

#include "keypad.h"
#include "LCD.h"
#include "timer0.h"
#include "led.h"
#include "buzzer.h"
#include "util/delay.h"
#include <string.h>
#include <stdio.h>

typedef struct {
	int hour, minute, second;
	char isPM, msgTime[12];
} Time;
Time alarmTime, clockTime;

void time_init(Time*);
int time_read();
char time_adjust(Time*);
void time_display(Time*);

void alarm_init();
void clock_init();

void alarm_adjust();
void clock_adjust();

void alarm_display();
void clock_display();

void clock_update();
void alarm_mode();

void buttons_checking();
void every_second();

#endif /* ALARM_CLOCK_H_ */