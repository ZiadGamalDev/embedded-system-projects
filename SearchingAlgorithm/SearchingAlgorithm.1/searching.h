#ifndef SEARCHING_H_
#define SEARCHING_H_

#include "LCD.h"
#include "keypad.h"
#include "seven_segment.h"

#define size 17

int numbers[size], positions[size], target, pos;

void searching_init(void);
void input_numbers(void);
void input_target(void);
void search(void);
void display_positions_7segment(void);
void leds_init();
void leds_on(int);
void leds_of();
void display_positions();
void display_positions_leds();

#endif /* SEARCHING_H_ */